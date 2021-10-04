#pragma once
#include <cstring>
#include <memory>
#include <type_traits>
#include <utility>
#include "../random/xorshift.cpp"
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"

template <class Key, class Value, std::enable_if_t<std::is_integral_v<Key>>* = nullptr> class IntegerHashMap {
    using TraitsK = std::allocator_traits<std::allocator<Key>>;
    using TraitsV = std::allocator_traits<std::allocator<Value>>;
    using TraitsU = std::allocator_traits<std::allocator<char>>;

    usize full, del, logn, mask;
    char* state;
    Key* keys;
    Value* values;
    std::allocator<char> alloc_u;
    std::allocator<Key> alloc_k;
    std::allocator<Value> alloc_v;

    u64 hash(u64 key) const {
        if (__builtin_expect(logn == 0, 0)) return 0;
        static const u64 rand = xorshift();
        key ^= rand;
        key ^= key >> (64 - logn);
        return (key * 11400714819323198485ull) >> (64 - logn);
    }
    usize find_key(const Key& key, usize i) const {
        while (state[i] != 0) {
            if (state[i] > 1 && keys[i] == key) return i;
            i += 1;
            i &= mask;
        }
        return i;
    }
    usize find_nonfull(usize i) const {
        while (state[i] > 1) {
            i += 1;
            i &= mask;
        }
        return i;
    }

    void resize() {
        char* old_state = state;
        Key* old_keys = keys;
        Value* old_values = values;
        const usize old_len = (!initialized() ? 0 : mask + 1);
        del = 0;
        logn = 0;
        while (3 * full > ((usize)1 << logn)) logn += 1;
        mask = (1 << logn) - 1;
        state = TraitsU::allocate(alloc_u, mask + 1);
        keys = TraitsK::allocate(alloc_k, mask + 1);
        values = TraitsV::allocate(alloc_v, mask + 1);
        std::memset(state, 0, mask + 1);
        for (const usize i : rep(0, old_len)) {
            if (old_state[i] > 1) {
                const usize k = find_nonfull(hash(static_cast<u64>(old_keys[i])));
                state[k] = old_state[i];
                keys[k] = old_keys[i];
                TraitsV::construct(alloc_v, values + k, std::move(old_values[i]));
            }
        }
        if (old_len) {
            TraitsU::deallocate(alloc_u, old_state, old_len);
            TraitsK::deallocate(alloc_k, old_keys, old_len);
            TraitsV::deallocate(alloc_v, old_values, old_len);
        }
    }

    bool initialized() const { return state != nullptr; }
    void reset_variables() {
        full = 0, del = 0, logn = 0, mask = 0;
        state = nullptr, keys = nullptr, values = nullptr;
    }

  public:
    IntegerHashMap() : alloc_u(), alloc_k(), alloc_v() { reset_variables(); }
    ~IntegerHashMap() { clear(); }
    IntegerHashMap(const IntegerHashMap& other) noexcept : alloc_u(), alloc_k(), alloc_v() {
        reset_variables();
        for (const usize i : rep(0, other.mask + 1))
            if (other.state[i] > 1) insert(other.keys[i], other.values[i]);
    }
    IntegerHashMap(IntegerHashMap&& other) noexcept : alloc_u(), alloc_k(), alloc_v() {
        full = std::exchange(other.full, 0);
        del = std::exchange(other.del, 0);
        logn = std::exchange(other.logn, 0);
        mask = std::exchange(other.mask, 0);
        state = std::exchange(other.state, nullptr);
        keys = std::exchange(other.keys, nullptr);
        values = std::exchange(other.values, nullptr);
    }

    IntegerHashMap& operator=(const IntegerHashMap& other) noexcept {
        if (this != &other) {
            clear();
            for (const usize i : rep(0, other.mask + 1))
                if (other.state[i] > 1) insert(other.keys[i], other.values[i]);
        }
        return *this;
    }
    IntegerHashMap& operator=(IntegerHashMap&& other) noexcept {
        if (this != &other) {
            clear();
            full = std::exchange(other.full, 0);
            del = std::exchange(other.del, 0);
            logn = std::exchange(other.logn, 0);
            mask = std::exchange(other.mask, 0);
            state = std::exchange(other.state, nullptr);
            keys = std::exchange(other.keys, nullptr);
            values = std::exchange(other.values, nullptr);
        }
        return *this;
    }

    template <class... Args> std::pair<Value*, bool> insert(const Key& key, Args&&... args) {
        if (!initialized()) resize();
        const usize pos = hash(static_cast<u64>(key));
        usize i = find_key(key, pos);
        if (state[i] == 0) {
            i = find_nonfull(pos);
            full += 1;
            del -= (state[i] == 1);
            if (2 * (full + del) > mask + 1) {
                resize();
                i = find_nonfull(hash(static_cast<u64>(key)));
            }
            state[i] = 2;
            keys[i] = key;
            TraitsV::construct(alloc_v, values + i, std::forward<Args>(args)...);
            return std::make_pair(values + i, true);
        }
        return std::make_pair(values + i, false);
    }

    bool erase(const Key& key) {
        if (empty()) return false;
        const usize i = find_key(key, hash(static_cast<u64>(key)));
        if (state[i] != 0) {
            full -= 1;
            del += 1;
            state[i] = 1;
            TraitsV::destroy(alloc_v, values + i);
            if (8 * full <= mask) resize();
            return true;
        }
        return false;
    }

    Value* find(const Key& key) const {
        if (empty()) return nullptr;
        const usize i = find_key(key, hash(static_cast<u64>(key)));
        return state[i] == 0 ? nullptr : (values + i);
    }

    void clear() {
        if (initialized()) {
            for (const usize i : rep(0, mask + 1))
                if (state[i] > 1) TraitsV::destroy(alloc_v, values + i);
            TraitsK::deallocate(alloc_k, keys, mask + 1);
            TraitsV::deallocate(alloc_v, values, mask + 1);
            TraitsU::deallocate(alloc_u, state, mask + 1);
            reset_variables();
        }
    }

    Value& operator[](const Key& key) { return *insert(key, Value()).first; }
    usize size() const { return full; }
    bool empty() const { return size() == 0; }

    class Iter {
        using Ref = std::pair<const Key&, Value&>;
        friend class IntegerHashMap;

        usize idx;
        IntegerHashMap* map;

        explicit Iter(const usize i, IntegerHashMap* m) : idx(i), map(m) { step(); }
        void step() {
            while (idx <= map->mask and map->state[idx] < 2) idx += 1;
        }

      public:
        bool operator!=(const Iter& other) const { return idx != other.idx; }
        Ref operator*() { return Ref(map->keys[idx], map->values[idx]); }
        void operator++() {
            idx += 1;
            step();
        }
    };

    Iter begin() { return Iter(0, this); }
    Iter end() { return Iter(mask + 1, this); }
};
