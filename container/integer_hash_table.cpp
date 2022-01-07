#pragma once
#include <tuple>
#include <type_traits>
#include <utility>
#include "../random/xorshift.cpp"
#include "../utility/ceil_log2.cpp"
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"

template <class K, class V, std::enable_if_t<std::is_integral_v<K>>* = nullptr> class IntegerHashTable {
    using Self = IntegerHashTable;

  public:
    class Iter {
        friend class IntegerHashTable;
        int idx;
        Self* self;

        explicit Iter(const int i, Self* s) : idx(i - 1), self(s) { next(); }

        void next() {
            while (++idx < self->info.size)
                if (self->data[idx].ctrl == Ctrl::Full) return;
        }

      public:
        bool operator!=(const Iter& other) const { return idx != other.idx or self != other.self; }
        std::pair<const K, V>& operator*() const { return self->data[idx].slot.pair; }
        void operator++() { next(); }
    };

    class ConstIter {
        friend class IntegerHashTable;
        int idx;
        const Self* self;

        explicit ConstIter(const int i, const Self* s) : idx(i - 1), self(s) { next(); }

        void next() {
            while (++idx < self->info.size)
                if (self->data[idx].ctrl == Ctrl::Full) return;
        }

      public:
        bool operator!=(const ConstIter& other) const { return idx != other.idx or self != other.self; }
        const std::pair<const K, V>& operator*() const { return self->data[idx].slot.pair; }
        void operator++() { next(); }
    };

  private:
    enum class Ctrl : char { Empty, Full, Deleted };

    union Slot {
        std::pair<const K, V> pair;
        std::pair<K, V> mut_pair;
        Slot() {}
        ~Slot() {}
    };

    struct Data {
        Ctrl ctrl;
        Slot slot;
        Data() : ctrl(Ctrl::Empty), slot() {}
        ~Data() {
            if (ctrl == Ctrl::Full) slot.mut_pair.~pair();
        }
    };

    struct Manager {
        static inline constexpr u64 PHI = 11400714819323198485ull;
        static inline const u64 RND = xorshift();

        int logn, size, full, deleted;
        Manager() : logn(0), size(0), full(0), deleted(0) {}

        void fix() {
            logn = ceil_log2(3 * full);
            size = (full == 0 ? 0 : (1 << logn));
            deleted = 0;
        }

        bool balanced() const { return 2 * (full + deleted) <= size and 8 * full >= size; }
        int mask() const { return size - 1; }

        int index(const K& k) const {
            u64 x = static_cast<u64>(k) ^ RND;
            x ^= x >> (64 - logn);
            return (x * PHI) >> (64 - logn);
        }
    };

    Data* data;
    Manager info;

    int find_key(const K& k, int i) const {
        while (data[i].ctrl != Ctrl::Empty) {
            if (data[i].ctrl == Ctrl::Full and data[i].slot.pair.first == k) break;
            i = (i + 1) & info.mask();
        }
        return i;
    }
    int find_place(int i) const {
        while (data[i].ctrl == Ctrl::Full) i = (i + 1) & info.mask();
        return i;
    }

    template <class... Args> void construct(const int i, Args&&... args) {
        new (&data[i].slot.mut_pair) std::pair<K, V>(std::forward<Args>(args)...);
    }
    void resize() {
        Data* old_data = std::exchange(data, nullptr);
        const int old_len = info.size;
        info.fix();
        if (info.size) {
            data = new Data[info.size];
            for (const int i : rep(old_len)) {
                if (old_data[i].ctrl == Ctrl::Full) {
                    const int k = find_place(info.index(old_data[i].slot.pair.first));
                    data[k].ctrl = Ctrl::Full;
                    construct(k, std::move(old_data[i].slot.mut_pair));
                }
            }
        }
        if (old_data) delete[] old_data;
    }

  public:
    IntegerHashTable() noexcept : data(nullptr), info() {}
    IntegerHashTable(const Self& other) noexcept : Self() { *this = other; }
    IntegerHashTable(Self&& other) noexcept : Self() { *this = std::move(other); }
    ~IntegerHashTable() { clear(); }

    Self& operator=(const Self& other) noexcept {
        if (this != &other) {
            clear();
            info = other.info;
            info.fix();
            if (info.size) {
                data = new Data[info.size];
                for (const int i : rep(other.info.size)) {
                    if (other.data[i].ctrl == Ctrl::Full) {
                        const int k = find_place(info.index(other.data[i].slot.pair.first));
                        data[k].ctrl = Ctrl::Full;
                        construct(k, other.data[i].slot.mut_pair);
                    }
                }
            }
        }
        return *this;
    }
    Self& operator=(Self&& other) noexcept {
        if (this != &other) {
            clear();
            data = std::exchange(other.data, nullptr);
            info = std::exchange(other.info, Manager());
        }
        return *this;
    }

    template <class... Args> std::pair<V*, bool> insert(const K& key, Args&&... args) {
        int idx = -1;
        if (empty()) {
            info.full += 1;
            resize();
            idx = info.index(key);
        } else {
            const int pos = info.index(key);
            int i = find_key(key, pos);
            if (data[i].ctrl == Ctrl::Full) return std::make_pair(&data[i].slot.pair.second, false);
            i = find_place(pos);
            info.full += 1;
            info.deleted -= (data[i].ctrl == Ctrl::Deleted);
            if (!info.balanced()) {
                resize();
                i = find_place(info.index(key));
            }
            idx = i;
        }
        data[idx].ctrl = Ctrl::Full;
        construct(idx, std::piecewise_construct, std::forward_as_tuple(key),
                  std::forward_as_tuple(std::forward<Args>(args)...));
        return std::make_pair(&data[idx].slot.pair.second, true);
    }

    bool erase(const K& key) {
        if (empty()) return false;
        const int i = find_key(key, info.index(key));
        if (data[i].ctrl == Ctrl::Full) {
            info.full -= 1;
            info.deleted += 1;
            data[i].ctrl = Ctrl::Deleted;
            data[i].slot.mut_pair.~pair();
            if (!info.balanced()) resize();
            return true;
        }
        return false;
    }

    V* find(const K& key) const {
        if (empty()) return nullptr;
        const int i = find_key(key, info.index(key));
        return data[i].ctrl == Ctrl::Full ? &data[i].slot.pair.second : nullptr;
    }

    void clear() {
        if (data) {
            delete[] data;
            data = nullptr;
        }
        info = Manager();
    }

    int size() const { return info.full; }
    bool empty() const { return size() == 0; }
    V& operator[](const K& key) { return *insert(key).first; }

    Iter begin() { return Iter(0, this); }
    Iter end() { return Iter(info.size, this); }
    ConstIter begin() const { return ConstIter(0, this); }
    ConstIter end() const { return ConstIter(info.size, this); }
};