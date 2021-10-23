---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bit/ceil_log2.cpp
    title: bit/ceil_log2.cpp
  - icon: ':heavy_check_mark:'
    path: container/integer_hash_table.cpp
    title: container/integer_hash_table.cpp
  - icon: ':heavy_check_mark:'
    path: random/xorshift.cpp
    title: random/xorshift.cpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':heavy_check_mark:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/associative_array
    links:
    - https://judge.yosupo.jp/problem/associative_array
  bundledCode: "#line 1 \"test/integer_hash_table.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\
    \n#line 2 \"utility/int_alias.cpp\"\n#include <cstddef>\n#include <cstdint>\n\n\
    using i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing isize = std::ptrdiff_t;\nusing usize = std::size_t;\n\
    #line 2 \"container/integer_hash_table.cpp\"\n#include <tuple>\n#include <type_traits>\n\
    #include <utility>\n#line 3 \"bit/ceil_log2.cpp\"\n\n__attribute__((target(\"\
    avx2\"))) constexpr u64 ceil_log2(const u64 x) {\n    u64 e = 0;\n    while (((u64)1\
    \ << e) < x) ++e;\n    return e;\n}\n#line 2 \"random/xorshift.cpp\"\n#include\
    \ <chrono>\n#include <random>\n#line 5 \"random/xorshift.cpp\"\n\nu64 xorshift()\
    \ {\n    static u64 state = std::chrono::system_clock::now().time_since_epoch().count();\n\
    \    state ^= state << 7;\n    state ^= state >> 9;\n    return state;\n}\n#line\
    \ 2 \"utility/rep.cpp\"\n#include <algorithm>\n#line 4 \"utility/rep.cpp\"\n\n\
    class rep {\n    struct Iter {\n        usize itr;\n        constexpr Iter(const\
    \ usize pos) noexcept : itr(pos) {}\n        constexpr void operator++() noexcept\
    \ { ++itr; }\n        constexpr bool operator!=(const Iter& other) const noexcept\
    \ { return itr != other.itr; }\n        constexpr usize operator*() const noexcept\
    \ { return itr; }\n    };\n    const Iter first, last;\n\n  public:\n    explicit\
    \ constexpr rep(const usize first, const usize last) noexcept : first(first),\
    \ last(std::max(first, last)) {}\n    constexpr Iter begin() const noexcept {\
    \ return first; }\n    constexpr Iter end() const noexcept { return last; }\n\
    };\n#line 9 \"container/integer_hash_table.cpp\"\n\ntemplate <class K, class V,\
    \ std::enable_if_t<std::is_integral_v<K>>* = nullptr> class IntegerHashTable {\n\
    \    using Self = IntegerHashTable;\n\n    enum class Ctrl : char { Empty, Full,\
    \ Deleted };\n\n    union Slot {\n        std::pair<const K, V> pair;\n      \
    \  std::pair<K, V> mut_pair;\n        Slot() {}\n        ~Slot() {}\n    };\n\n\
    \    struct Data {\n        Ctrl ctrl;\n        Slot slot;\n        Data() : ctrl(Ctrl::Empty),\
    \ slot() {}\n        ~Data() {\n            if (ctrl == Ctrl::Full) slot.mut_pair.~pair();\n\
    \        }\n    };\n\n    struct Manager {\n        static inline constexpr u64\
    \ PHI = 11400714819323198485ull;\n        static inline const u64 RND = xorshift();\n\
    \n        usize logn, size, full, deleted;\n        Manager() : logn(0), size(0),\
    \ full(0), deleted(0) {}\n\n        void fix() {\n            logn = ceil_log2(3\
    \ * full);\n            size = (full == 0 ? 0 : (1 << logn));\n            deleted\
    \ = 0;\n        }\n\n        bool balanced() const { return 2 * (full + deleted)\
    \ <= size and 8 * full >= size; }\n        usize mask() const { return size -\
    \ 1; }\n\n        usize index(const K& k) const {\n            u64 x = static_cast<u64>(k)\
    \ ^ RND;\n            x ^= x >> (64 - logn);\n            return (x * PHI) >>\
    \ (64 - logn);\n        }\n    };\n\n    Data* data;\n    Manager info;\n\n  \
    \  usize find_key(const K& k, usize i) const {\n        while (data[i].ctrl !=\
    \ Ctrl::Empty) {\n            if (data[i].ctrl == Ctrl::Full and data[i].slot.pair.first\
    \ == k) break;\n            i = (i + 1) & info.mask();\n        }\n        return\
    \ i;\n    }\n    usize find_place(usize i) const {\n        while (data[i].ctrl\
    \ == Ctrl::Full) i = (i + 1) & info.mask();\n        return i;\n    }\n\n    template\
    \ <class... Args> void construct(const usize i, Args&&... args) {\n        new\
    \ (&data[i].slot.mut_pair) std::pair<K, V>(std::forward<Args>(args)...);\n   \
    \ }\n    void resize() {\n        Data* old_data = std::exchange(data, nullptr);\n\
    \        const usize old_len = info.size;\n        info.fix();\n        if (info.size)\
    \ {\n            data = new Data[info.size];\n            for (const usize i :\
    \ rep(0, old_len)) {\n                if (old_data[i].ctrl == Ctrl::Full) {\n\
    \                    const usize k = find_place(info.index(old_data[i].slot.pair.first));\n\
    \                    data[k].ctrl = Ctrl::Full;\n                    construct(k,\
    \ std::move(old_data[i].slot.mut_pair));\n                }\n            }\n \
    \       }\n        if (old_data) delete[] old_data;\n    }\n\n  public:\n    IntegerHashTable()\
    \ noexcept : data(nullptr), info() {}\n    IntegerHashTable(const Self& other)\
    \ noexcept : Self() { *this = other; }\n    IntegerHashTable(Self&& other) noexcept\
    \ : Self() { *this = std::move(other); }\n    ~IntegerHashTable() { clear(); }\n\
    \n    class Iter {\n        friend class IntegerHashTable;\n        usize idx;\n\
    \        Self* self;\n\n        explicit Iter(const usize i, Self* s) : idx(i\
    \ - 1), self(s) { next(); }\n\n        void next() {\n            while (++idx\
    \ < self->info.size)\n                if (self->data[idx].ctrl == Ctrl::Full)\
    \ return;\n        }\n\n      public:\n        bool operator!=(const Iter& other)\
    \ const { return idx != other.idx or self != other.self; }\n        std::pair<const\
    \ K, V>& operator*() const { return self->data[idx].slot.pair; }\n        void\
    \ operator++() { next(); }\n    };\n\n    class ConstIter {\n        friend class\
    \ IntegerHashTable;\n        usize idx;\n        const Self* self;\n\n       \
    \ explicit ConstIter(const usize i, const Self* s) : idx(i - 1), self(s) { next();\
    \ }\n\n        void next() {\n            while (++idx < self->info.size)\n  \
    \              if (self->data[idx].ctrl == Ctrl::Full) return;\n        }\n\n\
    \      public:\n        bool operator!=(const ConstIter& other) const { return\
    \ idx != other.idx or self != other.self; }\n        const std::pair<const K,\
    \ V>& operator*() const { return self->data[idx].slot.pair; }\n        void operator++()\
    \ { next(); }\n    };\n\n    Self& operator=(const Self& other) noexcept {\n \
    \       if (this != &other) {\n            clear();\n            info = other.info;\n\
    \            info.fix();\n            if (info.size) {\n                data =\
    \ new Data[info.size];\n                for (const usize i : rep(0, other.info.size))\
    \ {\n                    if (other.data[i].ctrl == Ctrl::Full) {\n           \
    \             const usize k = find_place(info.index(other.data[i].slot.pair.first));\n\
    \                        data[k].ctrl = Ctrl::Full;\n                        construct(k,\
    \ other.data[i].slot.mut_pair);\n                    }\n                }\n  \
    \          }\n        }\n        return *this;\n    }\n    Self& operator=(Self&&\
    \ other) noexcept {\n        if (this != &other) {\n            clear();\n   \
    \         data = std::exchange(other.data, nullptr);\n            info = std::exchange(other.info,\
    \ Manager());\n        }\n        return *this;\n    }\n\n    template <class...\
    \ Args> std::pair<V*, bool> insert(const K& key, Args&&... args) {\n        usize\
    \ idx = -1;\n        if (empty()) {\n            info.full += 1;\n           \
    \ resize();\n            idx = info.index(key);\n        } else {\n          \
    \  const usize pos = info.index(key);\n            usize i = find_key(key, pos);\n\
    \            if (data[i].ctrl == Ctrl::Full) return std::make_pair(&data[i].slot.pair.second,\
    \ false);\n            i = find_place(pos);\n            info.full += 1;\n   \
    \         info.deleted -= (data[i].ctrl == Ctrl::Deleted);\n            if (!info.balanced())\
    \ {\n                resize();\n                i = find_place(info.index(key));\n\
    \            }\n            idx = i;\n        }\n        data[idx].ctrl = Ctrl::Full;\n\
    \        construct(idx, std::piecewise_construct, std::forward_as_tuple(key),\n\
    \                  std::forward_as_tuple(std::forward<Args>(args)...));\n    \
    \    return std::make_pair(&data[idx].slot.pair.second, true);\n    }\n\n    bool\
    \ erase(const K& key) {\n        if (empty()) return false;\n        const usize\
    \ i = find_key(key, info.index(key));\n        if (data[i].ctrl == Ctrl::Full)\
    \ {\n            info.full -= 1;\n            info.deleted += 1;\n           \
    \ data[i].ctrl = Ctrl::Deleted;\n            data[i].slot.mut_pair.~pair();\n\
    \            if (!info.balanced()) resize();\n            return true;\n     \
    \   }\n        return false;\n    }\n\n    V* find(const K& key) const {\n   \
    \     if (empty()) return nullptr;\n        const usize i = find_key(key, info.index(key));\n\
    \        return data[i].ctrl == Ctrl::Full ? &data[i].slot.pair.second : nullptr;\n\
    \    }\n\n    void clear() {\n        if (data) {\n            delete[] data;\n\
    \            data = nullptr;\n        }\n        info = Manager();\n    }\n\n\
    \    usize size() const { return info.full; }\n    bool empty() const { return\
    \ size() == 0; }\n    V& operator[](const K& key) { return *insert(key).first;\
    \ }\n\n    Iter begin() { return Iter(0, this); }\n    Iter end() { return Iter(info.size,\
    \ this); }\n    ConstIter begin() const { return ConstIter(0, this); }\n    ConstIter\
    \ end() const { return ConstIter(info.size, this); }\n};\n#line 4 \"test/integer_hash_table.test.cpp\"\
    \n#include <iostream>\n\nint main() {\n    usize Q;\n    std::cin >> Q;\n    IntegerHashTable<u64,\
    \ u64> map;\n    while (Q--) {\n        char c;\n        u64 k;\n        std::cin\
    \ >> c >> k;\n        if (c == '0') {\n            u64 v;\n            std::cin\
    \ >> v;\n            map[k] = v;\n        } else {\n            std::cout << map[k]\
    \ << '\\n';\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n#include\
    \ \"../utility/int_alias.cpp\"\n#include \"../container/integer_hash_table.cpp\"\
    \n#include <iostream>\n\nint main() {\n    usize Q;\n    std::cin >> Q;\n    IntegerHashTable<u64,\
    \ u64> map;\n    while (Q--) {\n        char c;\n        u64 k;\n        std::cin\
    \ >> c >> k;\n        if (c == '0') {\n            u64 v;\n            std::cin\
    \ >> v;\n            map[k] = v;\n        } else {\n            std::cout << map[k]\
    \ << '\\n';\n        }\n    }\n    return 0;\n}"
  dependsOn:
  - utility/int_alias.cpp
  - container/integer_hash_table.cpp
  - bit/ceil_log2.cpp
  - random/xorshift.cpp
  - utility/rep.cpp
  isVerificationFile: true
  path: test/integer_hash_table.test.cpp
  requiredBy: []
  timestamp: '2021-10-23 19:56:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/integer_hash_table.test.cpp
layout: document
redirect_from:
- /verify/test/integer_hash_table.test.cpp
- /verify/test/integer_hash_table.test.cpp.html
title: test/integer_hash_table.test.cpp
---
