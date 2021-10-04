---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: container/integer_hash_map.cpp
    title: container/integer_hash_map.cpp
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
  bundledCode: "#line 1 \"test/integer_hash_map.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\
    \n#line 2 \"utility/int_alias.cpp\"\n#include <cstddef>\n#include <cstdint>\n\n\
    using i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing isize = std::ptrdiff_t;\nusing usize = std::size_t;\n\
    #line 2 \"container/integer_hash_map.cpp\"\n#include <cstring>\n#include <memory>\n\
    #include <type_traits>\n#include <utility>\n#line 2 \"random/xorshift.cpp\"\n\
    #include <chrono>\n#include <random>\n#line 5 \"random/xorshift.cpp\"\n\nu64 xorshift()\
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
    };\n#line 9 \"container/integer_hash_map.cpp\"\n\ntemplate <class Key, class Value,\
    \ std::enable_if_t<std::is_integral_v<Key>>* = nullptr> class IntegerHashMap {\n\
    \    using TraitsK = std::allocator_traits<std::allocator<Key>>;\n    using TraitsV\
    \ = std::allocator_traits<std::allocator<Value>>;\n    using TraitsU = std::allocator_traits<std::allocator<char>>;\n\
    \n    usize full, del, logn, mask;\n    char* state;\n    Key* keys;\n    Value*\
    \ values;\n    std::allocator<char> alloc_u;\n    std::allocator<Key> alloc_k;\n\
    \    std::allocator<Value> alloc_v;\n\n    u64 hash(u64 key) const {\n       \
    \ if (__builtin_expect(logn == 0, 0)) return 0;\n        static const u64 rand\
    \ = xorshift();\n        key ^= rand;\n        key ^= key >> (64 - logn);\n  \
    \      return (key * 11400714819323198485ull) >> (64 - logn);\n    }\n    usize\
    \ find_key(const Key& key, usize i) const {\n        while (state[i] != 0) {\n\
    \            if (state[i] > 1 && keys[i] == key) return i;\n            i += 1;\n\
    \            i &= mask;\n        }\n        return i;\n    }\n    usize find_nonfull(usize\
    \ i) const {\n        while (state[i] > 1) {\n            i += 1;\n          \
    \  i &= mask;\n        }\n        return i;\n    }\n\n    void resize() {\n  \
    \      char* old_state = state;\n        Key* old_keys = keys;\n        Value*\
    \ old_values = values;\n        const usize old_len = (!initialized() ? 0 : mask\
    \ + 1);\n        del = 0;\n        logn = 0;\n        while (3 * full > ((usize)1\
    \ << logn)) logn += 1;\n        mask = (1 << logn) - 1;\n        state = TraitsU::allocate(alloc_u,\
    \ mask + 1);\n        keys = TraitsK::allocate(alloc_k, mask + 1);\n        values\
    \ = TraitsV::allocate(alloc_v, mask + 1);\n        std::memset(state, 0, mask\
    \ + 1);\n        for (const usize i : rep(0, old_len)) {\n            if (old_state[i]\
    \ > 1) {\n                const usize k = find_nonfull(hash(static_cast<u64>(old_keys[i])));\n\
    \                state[k] = old_state[i];\n                keys[k] = old_keys[i];\n\
    \                TraitsV::construct(alloc_v, values + k, std::move(old_values[i]));\n\
    \            }\n        }\n        if (old_len) {\n            TraitsU::deallocate(alloc_u,\
    \ old_state, old_len);\n            TraitsK::deallocate(alloc_k, old_keys, old_len);\n\
    \            TraitsV::deallocate(alloc_v, old_values, old_len);\n        }\n \
    \   }\n\n    bool initialized() const { return state != nullptr; }\n    void reset_variables()\
    \ {\n        full = 0, del = 0, logn = 0, mask = 0;\n        state = nullptr,\
    \ keys = nullptr, values = nullptr;\n    }\n\n  public:\n    IntegerHashMap()\
    \ : alloc_u(), alloc_k(), alloc_v() { reset_variables(); }\n    ~IntegerHashMap()\
    \ { clear(); }\n    IntegerHashMap(const IntegerHashMap& other) noexcept : alloc_u(),\
    \ alloc_k(), alloc_v() {\n        reset_variables();\n        for (const usize\
    \ i : rep(0, other.mask + 1))\n            if (other.state[i] > 1) insert(other.keys[i],\
    \ other.values[i]);\n    }\n    IntegerHashMap(IntegerHashMap&& other) noexcept\
    \ : alloc_u(), alloc_k(), alloc_v() {\n        full = std::exchange(other.full,\
    \ 0);\n        del = std::exchange(other.del, 0);\n        logn = std::exchange(other.logn,\
    \ 0);\n        mask = std::exchange(other.mask, 0);\n        state = std::exchange(other.state,\
    \ nullptr);\n        keys = std::exchange(other.keys, nullptr);\n        values\
    \ = std::exchange(other.values, nullptr);\n    }\n\n    IntegerHashMap& operator=(const\
    \ IntegerHashMap& other) noexcept {\n        if (this != &other) {\n         \
    \   clear();\n            for (const usize i : rep(0, other.mask + 1))\n     \
    \           if (other.state[i] > 1) insert(other.keys[i], other.values[i]);\n\
    \        }\n        return *this;\n    }\n    IntegerHashMap& operator=(IntegerHashMap&&\
    \ other) noexcept {\n        if (this != &other) {\n            clear();\n   \
    \         full = std::exchange(other.full, 0);\n            del = std::exchange(other.del,\
    \ 0);\n            logn = std::exchange(other.logn, 0);\n            mask = std::exchange(other.mask,\
    \ 0);\n            state = std::exchange(other.state, nullptr);\n            keys\
    \ = std::exchange(other.keys, nullptr);\n            values = std::exchange(other.values,\
    \ nullptr);\n        }\n        return *this;\n    }\n\n    template <class...\
    \ Args> std::pair<Value*, bool> insert(const Key& key, Args&&... args) {\n   \
    \     if (!initialized()) resize();\n        const usize pos = hash(static_cast<u64>(key));\n\
    \        usize i = find_key(key, pos);\n        if (state[i] == 0) {\n       \
    \     i = find_nonfull(pos);\n            full += 1;\n            del -= (state[i]\
    \ == 1);\n            if (2 * (full + del) > mask + 1) {\n                resize();\n\
    \                i = find_nonfull(hash(static_cast<u64>(key)));\n            }\n\
    \            state[i] = 2;\n            keys[i] = key;\n            TraitsV::construct(alloc_v,\
    \ values + i, std::forward<Args>(args)...);\n            return std::make_pair(values\
    \ + i, true);\n        }\n        return std::make_pair(values + i, false);\n\
    \    }\n\n    bool erase(const Key& key) {\n        if (empty()) return false;\n\
    \        const usize i = find_key(key, hash(static_cast<u64>(key)));\n       \
    \ if (state[i] != 0) {\n            full -= 1;\n            del += 1;\n      \
    \      state[i] = 1;\n            TraitsV::destroy(alloc_v, values + i);\n   \
    \         if (8 * full <= mask) resize();\n            return true;\n        }\n\
    \        return false;\n    }\n\n    Value* find(const Key& key) const {\n   \
    \     if (empty()) return nullptr;\n        const usize i = find_key(key, hash(static_cast<u64>(key)));\n\
    \        return state[i] == 0 ? nullptr : (values + i);\n    }\n\n    void clear()\
    \ {\n        if (initialized()) {\n            for (const usize i : rep(0, mask\
    \ + 1))\n                if (state[i] > 1) TraitsV::destroy(alloc_v, values +\
    \ i);\n            TraitsK::deallocate(alloc_k, keys, mask + 1);\n           \
    \ TraitsV::deallocate(alloc_v, values, mask + 1);\n            TraitsU::deallocate(alloc_u,\
    \ state, mask + 1);\n            reset_variables();\n        }\n    }\n\n    Value&\
    \ operator[](const Key& key) { return *insert(key, Value()).first; }\n    usize\
    \ size() const { return full; }\n    bool empty() const { return size() == 0;\
    \ }\n\n    class Iter {\n        using Ref = std::pair<const Key&, Value&>;\n\
    \        friend class IntegerHashMap;\n\n        usize idx;\n        IntegerHashMap*\
    \ map;\n\n        explicit Iter(const usize i, IntegerHashMap* m) : idx(i), map(m)\
    \ { step(); }\n        void step() {\n            while (idx <= map->mask and\
    \ map->state[idx] < 2) idx += 1;\n        }\n\n      public:\n        bool operator!=(const\
    \ Iter& other) const { return idx != other.idx; }\n        Ref operator*() { return\
    \ Ref(map->keys[idx], map->values[idx]); }\n        void operator++() {\n    \
    \        idx += 1;\n            step();\n        }\n    };\n\n    Iter begin()\
    \ { return Iter(0, this); }\n    Iter end() { return Iter(mask + 1, this); }\n\
    };\n#line 4 \"test/integer_hash_map.test.cpp\"\n#include <iostream>\n\nint main()\
    \ {\n    usize Q;\n    std::cin >> Q;\n    IntegerHashMap<u64, u64> map;\n   \
    \ while (Q--) {\n        char c;\n        u64 k;\n        std::cin >> c >> k;\n\
    \        if (c == '0') {\n            u64 v;\n            std::cin >> v;\n   \
    \         map[k] = v;\n        } else {\n            std::cout << map[k] << '\\\
    n';\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n#include\
    \ \"../utility/int_alias.cpp\"\n#include \"../container/integer_hash_map.cpp\"\
    \n#include <iostream>\n\nint main() {\n    usize Q;\n    std::cin >> Q;\n    IntegerHashMap<u64,\
    \ u64> map;\n    while (Q--) {\n        char c;\n        u64 k;\n        std::cin\
    \ >> c >> k;\n        if (c == '0') {\n            u64 v;\n            std::cin\
    \ >> v;\n            map[k] = v;\n        } else {\n            std::cout << map[k]\
    \ << '\\n';\n        }\n    }\n    return 0;\n}"
  dependsOn:
  - utility/int_alias.cpp
  - container/integer_hash_map.cpp
  - random/xorshift.cpp
  - utility/rep.cpp
  isVerificationFile: true
  path: test/integer_hash_map.test.cpp
  requiredBy: []
  timestamp: '2021-10-04 09:51:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/integer_hash_map.test.cpp
layout: document
redirect_from:
- /verify/test/integer_hash_map.test.cpp
- /verify/test/integer_hash_map.test.cpp.html
title: test/integer_hash_map.test.cpp
---
