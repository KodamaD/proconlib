---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: internal/enable_avx2.cpp
    title: internal/enable_avx2.cpp
  - icon: ':x:'
    path: random/xorshift.cpp
    title: random/xorshift.cpp
  - icon: ':question:'
    path: utility/bit_width.cpp
    title: utility/bit_width.cpp
  - icon: ':question:'
    path: utility/ceil_log2.cpp
    title: utility/ceil_log2.cpp
  - icon: ':question:'
    path: utility/countl_zero.cpp
    title: utility/countl_zero.cpp
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':question:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/integer_hash_table.test.cpp
    title: test/integer_hash_table.test.cpp
  - icon: ':x:'
    path: test/integer_hash_table_verbose.test.cpp
    title: test/integer_hash_table_verbose.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"container/integer_hash_table.cpp\"\n#include <tuple>\n#include\
    \ <type_traits>\n#include <utility>\n#line 2 \"random/xorshift.cpp\"\n#include\
    \ <chrono>\n#include <random>\n#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n\
    \nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    #line 5 \"random/xorshift.cpp\"\n\nu64 xorshift() {\n    static u64 state = std::chrono::system_clock::now().time_since_epoch().count();\n\
    \    state ^= state << 7;\n    state ^= state >> 9;\n    return state;\n}\n#line\
    \ 2 \"internal/enable_avx2.cpp\"\n\n#ifdef ENABLE_AVX2\n#define TARGET_AVX2 __attribute__((target(\"\
    avx2\")))\n#else\n#define TARGET_AVX2\n#endif\n#line 4 \"utility/countl_zero.cpp\"\
    \n\nTARGET_AVX2 constexpr int countl_zero(u64 x) {\n#ifdef __GNUC__\n    return\
    \ x == 0 ? 64 : __builtin_clzll(x);\n#else\n    x |= x >> 1;\n    x |= x >> 2;\n\
    \    x |= x >> 4;\n    x |= x >> 8;\n    x |= x >> 16;\n    x |= x >> 32;\n  \
    \  return 64 - countr_zero(~x);\n#endif\n}\n#line 4 \"utility/bit_width.cpp\"\n\
    \nTARGET_AVX2 constexpr int bit_width(const u64 x) { return 64 - countl_zero(x);\
    \ }\n#line 5 \"utility/ceil_log2.cpp\"\n\nTARGET_AVX2 constexpr int ceil_log2(const\
    \ u64 x) {\n#ifdef __GNUC__\n    return x == 0 ? 0 : bit_width(x - 1);\n#else\n\
    \    int e = 0;\n    while (((u64)1 << e) < x) ++e;\n    return e;\n#endif\n}\n\
    #line 2 \"utility/rep.cpp\"\n#include <algorithm>\n\nclass Range {\n    struct\
    \ Iter {\n        int itr;\n        constexpr Iter(const int pos) noexcept : itr(pos)\
    \ {}\n        constexpr void operator++() noexcept { ++itr; }\n        constexpr\
    \ bool operator!=(const Iter& other) const noexcept { return itr != other.itr;\
    \ }\n        constexpr int operator*() const noexcept { return itr; }\n    };\n\
    \    const Iter first, last;\n\n  public:\n    explicit constexpr Range(const\
    \ int first, const int last) noexcept : first(first), last(std::max(first, last))\
    \ {}\n    constexpr Iter begin() const noexcept { return first; }\n    constexpr\
    \ Iter end() const noexcept { return last; }\n};\n\nconstexpr Range rep(const\
    \ int l, const int r) noexcept { return Range(l, r); }\nconstexpr Range rep(const\
    \ int n) noexcept { return Range(0, n); }\n#line 9 \"container/integer_hash_table.cpp\"\
    \n\ntemplate <class K, class V, std::enable_if_t<std::is_integral_v<K>>* = nullptr>\
    \ class IntegerHashTable {\n  public:\n    class Iter {\n        friend class\
    \ IntegerHashTable;\n        int idx;\n        Self* self;\n\n        explicit\
    \ Iter(const int i, Self* s) : idx(i - 1), self(s) { next(); }\n\n        void\
    \ next() {\n            while (++idx < self->info.size)\n                if (self->data[idx].ctrl\
    \ == Ctrl::Full) return;\n        }\n\n      public:\n        bool operator!=(const\
    \ Iter& other) const { return idx != other.idx or self != other.self; }\n    \
    \    std::pair<const K, V>& operator*() const { return self->data[idx].slot.pair;\
    \ }\n        void operator++() { next(); }\n    };\n\n    class ConstIter {\n\
    \        friend class IntegerHashTable;\n        int idx;\n        const Self*\
    \ self;\n\n        explicit ConstIter(const int i, const Self* s) : idx(i - 1),\
    \ self(s) { next(); }\n\n        void next() {\n            while (++idx < self->info.size)\n\
    \                if (self->data[idx].ctrl == Ctrl::Full) return;\n        }\n\n\
    \      public:\n        bool operator!=(const ConstIter& other) const { return\
    \ idx != other.idx or self != other.self; }\n        const std::pair<const K,\
    \ V>& operator*() const { return self->data[idx].slot.pair; }\n        void operator++()\
    \ { next(); }\n    };\n\n  private:\n    using Self = IntegerHashTable;\n\n  \
    \  enum class Ctrl : char { Empty, Full, Deleted };\n\n    union Slot {\n    \
    \    std::pair<const K, V> pair;\n        std::pair<K, V> mut_pair;\n        Slot()\
    \ {}\n        ~Slot() {}\n    };\n\n    struct Data {\n        Ctrl ctrl;\n  \
    \      Slot slot;\n        Data() : ctrl(Ctrl::Empty), slot() {}\n        ~Data()\
    \ {\n            if (ctrl == Ctrl::Full) slot.mut_pair.~pair();\n        }\n \
    \   };\n\n    struct Manager {\n        static inline constexpr u64 PHI = 11400714819323198485ull;\n\
    \        static inline const u64 RND = xorshift();\n\n        int logn, size,\
    \ full, deleted;\n        Manager() : logn(0), size(0), full(0), deleted(0) {}\n\
    \n        void fix() {\n            logn = ceil_log2(3 * full);\n            size\
    \ = (full == 0 ? 0 : (1 << logn));\n            deleted = 0;\n        }\n\n  \
    \      bool balanced() const { return 2 * (full + deleted) <= size and 8 * full\
    \ >= size; }\n        int mask() const { return size - 1; }\n\n        int index(const\
    \ K& k) const {\n            u64 x = static_cast<u64>(k) ^ RND;\n            x\
    \ ^= x >> (64 - logn);\n            return (x * PHI) >> (64 - logn);\n       \
    \ }\n    };\n\n    Data* data;\n    Manager info;\n\n    int find_key(const K&\
    \ k, int i) const {\n        while (data[i].ctrl != Ctrl::Empty) {\n         \
    \   if (data[i].ctrl == Ctrl::Full and data[i].slot.pair.first == k) break;\n\
    \            i = (i + 1) & info.mask();\n        }\n        return i;\n    }\n\
    \    int find_place(int i) const {\n        while (data[i].ctrl == Ctrl::Full)\
    \ i = (i + 1) & info.mask();\n        return i;\n    }\n\n    template <class...\
    \ Args> void construct(const int i, Args&&... args) {\n        new (&data[i].slot.mut_pair)\
    \ std::pair<K, V>(std::forward<Args>(args)...);\n    }\n    void resize() {\n\
    \        Data* old_data = std::exchange(data, nullptr);\n        const int old_len\
    \ = info.size;\n        info.fix();\n        if (info.size) {\n            data\
    \ = new Data[info.size];\n            for (const int i : rep(old_len)) {\n   \
    \             if (old_data[i].ctrl == Ctrl::Full) {\n                    const\
    \ int k = find_place(info.index(old_data[i].slot.pair.first));\n             \
    \       data[k].ctrl = Ctrl::Full;\n                    construct(k, std::move(old_data[i].slot.mut_pair));\n\
    \                }\n            }\n        }\n        if (old_data) delete[] old_data;\n\
    \    }\n\n  public:\n    IntegerHashTable() noexcept : data(nullptr), info() {}\n\
    \    IntegerHashTable(const Self& other) noexcept : Self() { *this = other; }\n\
    \    IntegerHashTable(Self&& other) noexcept : Self() { *this = std::move(other);\
    \ }\n    ~IntegerHashTable() { clear(); }\n\n    Self& operator=(const Self& other)\
    \ noexcept {\n        if (this != &other) {\n            clear();\n          \
    \  info = other.info;\n            info.fix();\n            if (info.size) {\n\
    \                data = new Data[info.size];\n                for (const int i\
    \ : rep(other.info.size)) {\n                    if (other.data[i].ctrl == Ctrl::Full)\
    \ {\n                        const int k = find_place(info.index(other.data[i].slot.pair.first));\n\
    \                        data[k].ctrl = Ctrl::Full;\n                        construct(k,\
    \ other.data[i].slot.mut_pair);\n                    }\n                }\n  \
    \          }\n        }\n        return *this;\n    }\n    Self& operator=(Self&&\
    \ other) noexcept {\n        if (this != &other) {\n            clear();\n   \
    \         data = std::exchange(other.data, nullptr);\n            info = std::exchange(other.info,\
    \ Manager());\n        }\n        return *this;\n    }\n\n    template <class...\
    \ Args> std::pair<V*, bool> insert(const K& key, Args&&... args) {\n        int\
    \ idx = -1;\n        if (empty()) {\n            info.full += 1;\n           \
    \ resize();\n            idx = info.index(key);\n        } else {\n          \
    \  const int pos = info.index(key);\n            int i = find_key(key, pos);\n\
    \            if (data[i].ctrl == Ctrl::Full) return std::make_pair(&data[i].slot.pair.second,\
    \ false);\n            i = find_place(pos);\n            info.full += 1;\n   \
    \         info.deleted -= (data[i].ctrl == Ctrl::Deleted);\n            if (!info.balanced())\
    \ {\n                resize();\n                i = find_place(info.index(key));\n\
    \            }\n            idx = i;\n        }\n        data[idx].ctrl = Ctrl::Full;\n\
    \        construct(idx, std::piecewise_construct, std::forward_as_tuple(key),\n\
    \                  std::forward_as_tuple(std::forward<Args>(args)...));\n    \
    \    return std::make_pair(&data[idx].slot.pair.second, true);\n    }\n\n    bool\
    \ erase(const K& key) {\n        if (empty()) return false;\n        const int\
    \ i = find_key(key, info.index(key));\n        if (data[i].ctrl == Ctrl::Full)\
    \ {\n            info.full -= 1;\n            info.deleted += 1;\n           \
    \ data[i].ctrl = Ctrl::Deleted;\n            data[i].slot.mut_pair.~pair();\n\
    \            if (!info.balanced()) resize();\n            return true;\n     \
    \   }\n        return false;\n    }\n\n    V* find(const K& key) const {\n   \
    \     if (empty()) return nullptr;\n        const int i = find_key(key, info.index(key));\n\
    \        return data[i].ctrl == Ctrl::Full ? &data[i].slot.pair.second : nullptr;\n\
    \    }\n\n    void clear() {\n        if (data) {\n            delete[] data;\n\
    \            data = nullptr;\n        }\n        info = Manager();\n    }\n\n\
    \    int size() const { return info.full; }\n    bool empty() const { return size()\
    \ == 0; }\n    V& operator[](const K& key) { return *insert(key).first; }\n\n\
    \    Iter begin() { return Iter(0, this); }\n    Iter end() { return Iter(info.size,\
    \ this); }\n    ConstIter begin() const { return ConstIter(0, this); }\n    ConstIter\
    \ end() const { return ConstIter(info.size, this); }\n};\n"
  code: "#pragma once\n#include <tuple>\n#include <type_traits>\n#include <utility>\n\
    #include \"../random/xorshift.cpp\"\n#include \"../utility/ceil_log2.cpp\"\n#include\
    \ \"../utility/int_alias.cpp\"\n#include \"../utility/rep.cpp\"\n\ntemplate <class\
    \ K, class V, std::enable_if_t<std::is_integral_v<K>>* = nullptr> class IntegerHashTable\
    \ {\n  public:\n    class Iter {\n        friend class IntegerHashTable;\n   \
    \     int idx;\n        Self* self;\n\n        explicit Iter(const int i, Self*\
    \ s) : idx(i - 1), self(s) { next(); }\n\n        void next() {\n            while\
    \ (++idx < self->info.size)\n                if (self->data[idx].ctrl == Ctrl::Full)\
    \ return;\n        }\n\n      public:\n        bool operator!=(const Iter& other)\
    \ const { return idx != other.idx or self != other.self; }\n        std::pair<const\
    \ K, V>& operator*() const { return self->data[idx].slot.pair; }\n        void\
    \ operator++() { next(); }\n    };\n\n    class ConstIter {\n        friend class\
    \ IntegerHashTable;\n        int idx;\n        const Self* self;\n\n        explicit\
    \ ConstIter(const int i, const Self* s) : idx(i - 1), self(s) { next(); }\n\n\
    \        void next() {\n            while (++idx < self->info.size)\n        \
    \        if (self->data[idx].ctrl == Ctrl::Full) return;\n        }\n\n      public:\n\
    \        bool operator!=(const ConstIter& other) const { return idx != other.idx\
    \ or self != other.self; }\n        const std::pair<const K, V>& operator*() const\
    \ { return self->data[idx].slot.pair; }\n        void operator++() { next(); }\n\
    \    };\n\n  private:\n    using Self = IntegerHashTable;\n\n    enum class Ctrl\
    \ : char { Empty, Full, Deleted };\n\n    union Slot {\n        std::pair<const\
    \ K, V> pair;\n        std::pair<K, V> mut_pair;\n        Slot() {}\n        ~Slot()\
    \ {}\n    };\n\n    struct Data {\n        Ctrl ctrl;\n        Slot slot;\n  \
    \      Data() : ctrl(Ctrl::Empty), slot() {}\n        ~Data() {\n            if\
    \ (ctrl == Ctrl::Full) slot.mut_pair.~pair();\n        }\n    };\n\n    struct\
    \ Manager {\n        static inline constexpr u64 PHI = 11400714819323198485ull;\n\
    \        static inline const u64 RND = xorshift();\n\n        int logn, size,\
    \ full, deleted;\n        Manager() : logn(0), size(0), full(0), deleted(0) {}\n\
    \n        void fix() {\n            logn = ceil_log2(3 * full);\n            size\
    \ = (full == 0 ? 0 : (1 << logn));\n            deleted = 0;\n        }\n\n  \
    \      bool balanced() const { return 2 * (full + deleted) <= size and 8 * full\
    \ >= size; }\n        int mask() const { return size - 1; }\n\n        int index(const\
    \ K& k) const {\n            u64 x = static_cast<u64>(k) ^ RND;\n            x\
    \ ^= x >> (64 - logn);\n            return (x * PHI) >> (64 - logn);\n       \
    \ }\n    };\n\n    Data* data;\n    Manager info;\n\n    int find_key(const K&\
    \ k, int i) const {\n        while (data[i].ctrl != Ctrl::Empty) {\n         \
    \   if (data[i].ctrl == Ctrl::Full and data[i].slot.pair.first == k) break;\n\
    \            i = (i + 1) & info.mask();\n        }\n        return i;\n    }\n\
    \    int find_place(int i) const {\n        while (data[i].ctrl == Ctrl::Full)\
    \ i = (i + 1) & info.mask();\n        return i;\n    }\n\n    template <class...\
    \ Args> void construct(const int i, Args&&... args) {\n        new (&data[i].slot.mut_pair)\
    \ std::pair<K, V>(std::forward<Args>(args)...);\n    }\n    void resize() {\n\
    \        Data* old_data = std::exchange(data, nullptr);\n        const int old_len\
    \ = info.size;\n        info.fix();\n        if (info.size) {\n            data\
    \ = new Data[info.size];\n            for (const int i : rep(old_len)) {\n   \
    \             if (old_data[i].ctrl == Ctrl::Full) {\n                    const\
    \ int k = find_place(info.index(old_data[i].slot.pair.first));\n             \
    \       data[k].ctrl = Ctrl::Full;\n                    construct(k, std::move(old_data[i].slot.mut_pair));\n\
    \                }\n            }\n        }\n        if (old_data) delete[] old_data;\n\
    \    }\n\n  public:\n    IntegerHashTable() noexcept : data(nullptr), info() {}\n\
    \    IntegerHashTable(const Self& other) noexcept : Self() { *this = other; }\n\
    \    IntegerHashTable(Self&& other) noexcept : Self() { *this = std::move(other);\
    \ }\n    ~IntegerHashTable() { clear(); }\n\n    Self& operator=(const Self& other)\
    \ noexcept {\n        if (this != &other) {\n            clear();\n          \
    \  info = other.info;\n            info.fix();\n            if (info.size) {\n\
    \                data = new Data[info.size];\n                for (const int i\
    \ : rep(other.info.size)) {\n                    if (other.data[i].ctrl == Ctrl::Full)\
    \ {\n                        const int k = find_place(info.index(other.data[i].slot.pair.first));\n\
    \                        data[k].ctrl = Ctrl::Full;\n                        construct(k,\
    \ other.data[i].slot.mut_pair);\n                    }\n                }\n  \
    \          }\n        }\n        return *this;\n    }\n    Self& operator=(Self&&\
    \ other) noexcept {\n        if (this != &other) {\n            clear();\n   \
    \         data = std::exchange(other.data, nullptr);\n            info = std::exchange(other.info,\
    \ Manager());\n        }\n        return *this;\n    }\n\n    template <class...\
    \ Args> std::pair<V*, bool> insert(const K& key, Args&&... args) {\n        int\
    \ idx = -1;\n        if (empty()) {\n            info.full += 1;\n           \
    \ resize();\n            idx = info.index(key);\n        } else {\n          \
    \  const int pos = info.index(key);\n            int i = find_key(key, pos);\n\
    \            if (data[i].ctrl == Ctrl::Full) return std::make_pair(&data[i].slot.pair.second,\
    \ false);\n            i = find_place(pos);\n            info.full += 1;\n   \
    \         info.deleted -= (data[i].ctrl == Ctrl::Deleted);\n            if (!info.balanced())\
    \ {\n                resize();\n                i = find_place(info.index(key));\n\
    \            }\n            idx = i;\n        }\n        data[idx].ctrl = Ctrl::Full;\n\
    \        construct(idx, std::piecewise_construct, std::forward_as_tuple(key),\n\
    \                  std::forward_as_tuple(std::forward<Args>(args)...));\n    \
    \    return std::make_pair(&data[idx].slot.pair.second, true);\n    }\n\n    bool\
    \ erase(const K& key) {\n        if (empty()) return false;\n        const int\
    \ i = find_key(key, info.index(key));\n        if (data[i].ctrl == Ctrl::Full)\
    \ {\n            info.full -= 1;\n            info.deleted += 1;\n           \
    \ data[i].ctrl = Ctrl::Deleted;\n            data[i].slot.mut_pair.~pair();\n\
    \            if (!info.balanced()) resize();\n            return true;\n     \
    \   }\n        return false;\n    }\n\n    V* find(const K& key) const {\n   \
    \     if (empty()) return nullptr;\n        const int i = find_key(key, info.index(key));\n\
    \        return data[i].ctrl == Ctrl::Full ? &data[i].slot.pair.second : nullptr;\n\
    \    }\n\n    void clear() {\n        if (data) {\n            delete[] data;\n\
    \            data = nullptr;\n        }\n        info = Manager();\n    }\n\n\
    \    int size() const { return info.full; }\n    bool empty() const { return size()\
    \ == 0; }\n    V& operator[](const K& key) { return *insert(key).first; }\n\n\
    \    Iter begin() { return Iter(0, this); }\n    Iter end() { return Iter(info.size,\
    \ this); }\n    ConstIter begin() const { return ConstIter(0, this); }\n    ConstIter\
    \ end() const { return ConstIter(info.size, this); }\n};"
  dependsOn:
  - random/xorshift.cpp
  - utility/int_alias.cpp
  - utility/ceil_log2.cpp
  - internal/enable_avx2.cpp
  - utility/bit_width.cpp
  - utility/countl_zero.cpp
  - utility/rep.cpp
  isVerificationFile: false
  path: container/integer_hash_table.cpp
  requiredBy: []
  timestamp: '2022-01-07 21:48:21+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/integer_hash_table_verbose.test.cpp
  - test/integer_hash_table.test.cpp
documentation_of: container/integer_hash_table.cpp
layout: document
redirect_from:
- /library/container/integer_hash_table.cpp
- /library/container/integer_hash_table.cpp.html
title: container/integer_hash_table.cpp
---
