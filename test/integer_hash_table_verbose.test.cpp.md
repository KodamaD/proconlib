---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: container/integer_hash_table.cpp
    title: container/integer_hash_table.cpp
  - icon: ':question:'
    path: random/xorshift.cpp
    title: random/xorshift.cpp
  - icon: ':heavy_check_mark:'
    path: utility/ceil_log2.cpp
    title: utility/ceil_log2.cpp
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':question:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/integer_hash_table_verbose.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\n#include\
    \ <cassert>\n#include <vector>\n#include <utility>\n#include <memory>\n#line 2\
    \ \"container/integer_hash_table.cpp\"\n#include <tuple>\n#include <type_traits>\n\
    #line 2 \"random/xorshift.cpp\"\n#include <chrono>\n#include <random>\n#line 2\
    \ \"utility/int_alias.cpp\"\n#include <cstdint>\n\nusing i32 = std::int32_t;\n\
    using u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n#line 5 \"random/xorshift.cpp\"\
    \n\nu64 xorshift() {\n    static u64 state = std::chrono::system_clock::now().time_since_epoch().count();\n\
    \    state ^= state << 7;\n    state ^= state >> 9;\n    return state;\n}\n#line\
    \ 3 \"utility/ceil_log2.cpp\"\n\nconstexpr int ceil_log2(const u64 x) {\n    int\
    \ e = 0;\n    while (((u64)1 << e) < x) ++e;\n    return e;\n}\n#line 2 \"utility/rep.cpp\"\
    \n#include <algorithm>\n\nclass Range {\n    struct Iter {\n        int itr;\n\
    \        constexpr Iter(const int pos) noexcept : itr(pos) {}\n        constexpr\
    \ void operator++() noexcept { ++itr; }\n        constexpr bool operator!=(const\
    \ Iter& other) const noexcept { return itr != other.itr; }\n        constexpr\
    \ int operator*() const noexcept { return itr; }\n    };\n    const Iter first,\
    \ last;\n\n  public:\n    explicit constexpr Range(const int first, const int\
    \ last) noexcept : first(first), last(std::max(first, last)) {}\n    constexpr\
    \ Iter begin() const noexcept { return first; }\n    constexpr Iter end() const\
    \ noexcept { return last; }\n};\n\nconstexpr Range rep(const int l, const int\
    \ r) noexcept { return Range(l, r); }\nconstexpr Range rep(const int n) noexcept\
    \ { return Range(0, n); }\n#line 9 \"container/integer_hash_table.cpp\"\n\ntemplate\
    \ <class K, class V, std::enable_if_t<std::is_integral_v<K>>* = nullptr> class\
    \ IntegerHashTable {\n    using Self = IntegerHashTable;\n\n    enum class Ctrl\
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
    \ }\n    ~IntegerHashTable() { clear(); }\n\n    class Iter {\n        friend\
    \ class IntegerHashTable;\n        int idx;\n        Self* self;\n\n        explicit\
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
    \ { next(); }\n    };\n\n    Self& operator=(const Self& other) noexcept {\n \
    \       if (this != &other) {\n            clear();\n            info = other.info;\n\
    \            info.fix();\n            if (info.size) {\n                data =\
    \ new Data[info.size];\n                for (const int i : rep(other.info.size))\
    \ {\n                    if (other.data[i].ctrl == Ctrl::Full) {\n           \
    \             const int k = find_place(info.index(other.data[i].slot.pair.first));\n\
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
    \ end() const { return ConstIter(info.size, this); }\n};\n#line 7 \"test/integer_hash_table_verbose.test.cpp\"\
    \n\nstruct Object {\n    static inline int CON = 0;\n    static inline int DES\
    \ = 0;\n    Object() { CON += 1; }\n    ~Object() { DES += 1; }\n};\n\nvoid test()\
    \ {\n    {\n        IntegerHashTable<int, int> map;\n\n        assert(map.insert(0,\
    \ 3).second);\n        assert(map.insert(1, 2).second);\n        assert(!map.insert(0,\
    \ 2).second);\n\n        assert(map[0] == 3);\n        assert(map[1] == 2);\n\n\
    \        map[0] = 10;\n        assert(map[0] == 10);\n\n        for (int i = 2;\
    \ i < 100; ++i) {\n            map.insert(i, 2 * i);\n        }\n        assert(map.find(10));\n\
    \        assert(map.erase(10));\n        assert(!map.find(10));\n        assert(map.size()\
    \ == 99);\n\n        const auto enumerate = [&](const IntegerHashTable<int, int>&\
    \ m) {\n            std::vector<std::pair<int, int>> ret;\n            ret.reserve(m.size());\n\
    \            for (const auto& [a, b] : m) {\n                ret.emplace_back(a,\
    \ b);\n            }\n            assert(ret.size() == m.size());\n          \
    \  std::sort(ret.begin(), ret.end());\n            return ret;\n        };\n\n\
    \        const auto copy1 = map;\n        assert(copy1.size() == 99);\n      \
    \  assert(copy1.find(0));\n        assert(!copy1.find(10));\n        assert(enumerate(map)\
    \ == enumerate(copy1));\n\n        IntegerHashTable<int, int> copy2(map);\n  \
    \      assert(copy2.size() == 99);\n        assert(enumerate(map) == enumerate(copy2));\n\
    \n        auto move1 = std::move(map);\n        assert(map.size() == 0);\n   \
    \     assert(map.empty());\n        assert(enumerate(move1) == enumerate(copy1));\n\
    \n        IntegerHashTable<int, int> move2(std::move(move1));\n        assert(move1.size()\
    \ == 0);\n        assert(move1.empty());\n        assert(enumerate(move2) == enumerate(copy1));\n\
    \n        for (auto& [a, b] : move2) {\n            b = -1;\n        }\n     \
    \   assert(move2[0] == -1);\n        assert(move2[1] == -1);\n        assert(move2[2]\
    \ == -1);\n    }\n    {\n        {\n            IntegerHashTable<int, std::unique_ptr<Object>>\
    \ map;\n            assert(map.insert(0, std::make_unique<Object>()).second);\n\
    \            assert(!map.insert(0, std::make_unique<Object>()).second);\n    \
    \        assert(Object::CON == 2);\n            assert(Object::DES == 1);\n\n\
    \            map.clear();\n            assert(Object::CON == 2);\n           \
    \ assert(Object::DES == 2);\n        }\n\n        IntegerHashTable<int, std::unique_ptr<Object>>\
    \ map;\n        for (int i = 0; i < 100; ++i) {\n            map.insert(2 * i,\
    \ std::make_unique<Object>());\n        }\n        assert(Object::CON == 102);\n\
    \        assert(Object::DES == 2);\n\n        auto next = std::move(map);\n  \
    \      assert(Object::CON == 102);\n        assert(Object::DES == 2);\n      \
    \  assert(next.size() == 100);\n        for (const auto& [a, b] : next) {\n  \
    \          assert(a % 2 == 0);\n        }\n\n        {\n            const IntegerHashTable<int,\
    \ std::unique_ptr<Object>> inside(std::move(next));\n            assert(inside.size()\
    \ == 100);\n            assert(Object::CON == 102);\n            assert(Object::DES\
    \ == 2);\n        }\n        assert(Object::CON == 102);\n        assert(Object::DES\
    \ == 102);\n    }\n}\n\n#include <iostream>\n\nint main() {\n    test();\n   \
    \ std::cout << \"Hello World\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n#include <cassert>\n#include <vector>\n#include <utility>\n#include <memory>\n\
    #include \"../container/integer_hash_table.cpp\"\n\nstruct Object {\n    static\
    \ inline int CON = 0;\n    static inline int DES = 0;\n    Object() { CON += 1;\
    \ }\n    ~Object() { DES += 1; }\n};\n\nvoid test() {\n    {\n        IntegerHashTable<int,\
    \ int> map;\n\n        assert(map.insert(0, 3).second);\n        assert(map.insert(1,\
    \ 2).second);\n        assert(!map.insert(0, 2).second);\n\n        assert(map[0]\
    \ == 3);\n        assert(map[1] == 2);\n\n        map[0] = 10;\n        assert(map[0]\
    \ == 10);\n\n        for (int i = 2; i < 100; ++i) {\n            map.insert(i,\
    \ 2 * i);\n        }\n        assert(map.find(10));\n        assert(map.erase(10));\n\
    \        assert(!map.find(10));\n        assert(map.size() == 99);\n\n       \
    \ const auto enumerate = [&](const IntegerHashTable<int, int>& m) {\n        \
    \    std::vector<std::pair<int, int>> ret;\n            ret.reserve(m.size());\n\
    \            for (const auto& [a, b] : m) {\n                ret.emplace_back(a,\
    \ b);\n            }\n            assert(ret.size() == m.size());\n          \
    \  std::sort(ret.begin(), ret.end());\n            return ret;\n        };\n\n\
    \        const auto copy1 = map;\n        assert(copy1.size() == 99);\n      \
    \  assert(copy1.find(0));\n        assert(!copy1.find(10));\n        assert(enumerate(map)\
    \ == enumerate(copy1));\n\n        IntegerHashTable<int, int> copy2(map);\n  \
    \      assert(copy2.size() == 99);\n        assert(enumerate(map) == enumerate(copy2));\n\
    \n        auto move1 = std::move(map);\n        assert(map.size() == 0);\n   \
    \     assert(map.empty());\n        assert(enumerate(move1) == enumerate(copy1));\n\
    \n        IntegerHashTable<int, int> move2(std::move(move1));\n        assert(move1.size()\
    \ == 0);\n        assert(move1.empty());\n        assert(enumerate(move2) == enumerate(copy1));\n\
    \n        for (auto& [a, b] : move2) {\n            b = -1;\n        }\n     \
    \   assert(move2[0] == -1);\n        assert(move2[1] == -1);\n        assert(move2[2]\
    \ == -1);\n    }\n    {\n        {\n            IntegerHashTable<int, std::unique_ptr<Object>>\
    \ map;\n            assert(map.insert(0, std::make_unique<Object>()).second);\n\
    \            assert(!map.insert(0, std::make_unique<Object>()).second);\n    \
    \        assert(Object::CON == 2);\n            assert(Object::DES == 1);\n\n\
    \            map.clear();\n            assert(Object::CON == 2);\n           \
    \ assert(Object::DES == 2);\n        }\n\n        IntegerHashTable<int, std::unique_ptr<Object>>\
    \ map;\n        for (int i = 0; i < 100; ++i) {\n            map.insert(2 * i,\
    \ std::make_unique<Object>());\n        }\n        assert(Object::CON == 102);\n\
    \        assert(Object::DES == 2);\n\n        auto next = std::move(map);\n  \
    \      assert(Object::CON == 102);\n        assert(Object::DES == 2);\n      \
    \  assert(next.size() == 100);\n        for (const auto& [a, b] : next) {\n  \
    \          assert(a % 2 == 0);\n        }\n\n        {\n            const IntegerHashTable<int,\
    \ std::unique_ptr<Object>> inside(std::move(next));\n            assert(inside.size()\
    \ == 100);\n            assert(Object::CON == 102);\n            assert(Object::DES\
    \ == 2);\n        }\n        assert(Object::CON == 102);\n        assert(Object::DES\
    \ == 102);\n    }\n}\n\n#include <iostream>\n\nint main() {\n    test();\n   \
    \ std::cout << \"Hello World\\n\";\n}"
  dependsOn:
  - container/integer_hash_table.cpp
  - random/xorshift.cpp
  - utility/int_alias.cpp
  - utility/ceil_log2.cpp
  - utility/rep.cpp
  isVerificationFile: true
  path: test/integer_hash_table_verbose.test.cpp
  requiredBy: []
  timestamp: '2021-12-28 21:38:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/integer_hash_table_verbose.test.cpp
layout: document
redirect_from:
- /verify/test/integer_hash_table_verbose.test.cpp
- /verify/test/integer_hash_table_verbose.test.cpp.html
title: test/integer_hash_table_verbose.test.cpp
---
