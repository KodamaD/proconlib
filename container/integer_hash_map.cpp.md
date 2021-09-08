---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias_extended.cpp
    title: utility/int_alias_extended.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"container/integer_hash_map.cpp\"\n#include <cstring>\n#include\
    \ <memory>\n#include <type_traits>\n#include <utility>\n#line 2 \"utility/int_alias.cpp\"\
    \n#include <cstddef>\n#include <cstdint>\n\nusing i32 = std::int32_t;\nusing u32\
    \ = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing\
    \ isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 4 \"utility/int_alias_extended.cpp\"\
    \n\nusing i8 = std::int8_t;\nusing u8 = std::uint8_t;\nusing i16 = std::int16_t;\n\
    using u16 = std::uint16_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    #line 8 \"container/integer_hash_map.cpp\"\n\ntemplate <class Key, class Value,\
    \ std::enable_if_t<std::is_integral_v<Key>>* = nullptr> class IntegerHashMap {\n\
    \    using TraitsK = std::allocator_traits<std::allocator<Key>>;\n    using TraitsV\
    \ = std::allocator_traits<std::allocator<Value>>;\n    using TraitsU = std::allocator_traits<std::allocator<u8>>;\n\
    \n    class Iter {\n        using Ref = std::pair<const Key&, Value&>;\n     \
    \   friend class IntegerHashMap;\n\n        usize idx;\n        IntegerHashMap*\
    \ map;\n\n        explicit Iter(const usize i, IntegerHashMap* m) : idx(i), map(m)\
    \ { step(); }\n        void step() {\n            while (idx <= map->mask and\
    \ map->state[idx] >= 128) idx += 1;\n        }\n\n      public:\n        bool\
    \ operator!=(const Iter& other) const { return idx != other.idx; }\n        Ref\
    \ operator*() { return Ref(map->keys[idx], map->values[idx]); }\n        void\
    \ operator++() {\n            idx += 1;\n            step();\n        }\n    };\n\
    \n    usize full, del, logn, mask;\n    u8* state;\n    Key* keys;\n    Value*\
    \ values;\n    std::allocator<u8> alloc_u;\n    std::allocator<Key> alloc_k;\n\
    \    std::allocator<Value> alloc_v;\n\n    u64 hash0(u64 key) const {\n      \
    \  if (logn == 0) return 0;\n        key ^= key >> (64 - logn);\n        return\
    \ (key * 11400714819323198485ull) >> (64 - logn);\n    }\n    u8 hash1(u64 key)\
    \ const {\n        key ^= key >> 57;\n        return (key * 5871781006564002453ull)\
    \ >> 57;\n    }\n\n    usize find_key(const Key& key, usize i, const u8 id) const\
    \ {\n        while (state[i] != 128) {\n            if (state[i] == id and keys[i]\
    \ == key) return i;\n            i += 1;\n            i &= mask;\n        }\n\
    \        return i;\n    }\n    usize find_nonfull(usize i) const {\n        while\
    \ (state[i] < 128) {\n            i += 1;\n            i &= mask;\n        }\n\
    \        return i;\n    }\n\n    void resize() {\n        u8* old_state = state;\n\
    \        Key* old_keys = keys;\n        Value* old_values = values;\n        const\
    \ usize old_len = (!initialized() ? 0 : mask + 1);\n        del = 0;\n       \
    \ logn = 0;\n        while (3 * full > ((usize)1 << logn)) logn += 1;\n      \
    \  mask = (1 << logn) - 1;\n        state = TraitsU::allocate(alloc_u, mask +\
    \ 1);\n        keys = TraitsK::allocate(alloc_k, mask + 1);\n        values =\
    \ TraitsV::allocate(alloc_v, mask + 1);\n        std::memset(state, 128, mask\
    \ + 1);\n        for (usize i = 0; i < old_len; i += 1) {\n            if (old_state[i]\
    \ < 128) {\n                const usize k = find_nonfull(hash0(static_cast<u64>(old_keys[i])));\n\
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
    \ alloc_k(), alloc_v() {\n        reset_variables();\n        for (usize i = 0;\
    \ i <= other.mask; i += 1)\n            if (other.state[i] < 128) insert(other.keys[i],\
    \ other.values[i]);\n    }\n    IntegerHashMap(IntegerHashMap&& other) noexcept\
    \ : alloc_u(), alloc_k(), alloc_v() {\n        full = std::exchange(other.full,\
    \ 0);\n        del = std::exchange(other.del, 0);\n        logn = std::exchange(other.logn,\
    \ 0);\n        mask = std::exchange(other.mask, 0);\n        state = std::exchange(other.state,\
    \ nullptr);\n        keys = std::exchange(other.keys, nullptr);\n        values\
    \ = std::exchange(other.values, nullptr);\n    }\n\n    IntegerHashMap& operator=(const\
    \ IntegerHashMap& other) noexcept {\n        if (this != &other) {\n         \
    \   clear();\n            for (usize i = 0; i <= other.mask; i += 1)\n       \
    \         if (other.state[i] < 128) insert(other.keys[i], other.values[i]);\n\
    \        }\n        return *this;\n    }\n    IntegerHashMap& operator=(IntegerHashMap&&\
    \ other) noexcept {\n        if (this != &other) {\n            clear();\n   \
    \         full = std::exchange(other.full, 0);\n            del = std::exchange(other.del,\
    \ 0);\n            logn = std::exchange(other.logn, 0);\n            mask = std::exchange(other.mask,\
    \ 0);\n            state = std::exchange(other.state, nullptr);\n            keys\
    \ = std::exchange(other.keys, nullptr);\n            values = std::exchange(other.values,\
    \ nullptr);\n        }\n        return *this;\n    }\n\n    template <class...\
    \ Args> std::pair<Value*, bool> insert(const Key& key, Args&&... args) {\n   \
    \     if (!initialized()) resize();\n        const usize pos = hash0(static_cast<u64>(key));\n\
    \        const u8 id = hash1(static_cast<u64>(key));\n        usize i = find_key(key,\
    \ pos, id);\n        if (state[i] == 128) {\n            i = find_nonfull(pos);\n\
    \            full += 1;\n            del -= (state[i] == 129);\n            if\
    \ (2 * (full + del) > mask + 1) {\n                resize();\n               \
    \ i = find_nonfull(hash0(static_cast<u64>(key)));\n            }\n           \
    \ state[i] = id;\n            keys[i] = key;\n            TraitsV::construct(alloc_v,\
    \ values + i, std::forward<Args>(args)...);\n            return std::make_pair(values\
    \ + i, true);\n        }\n        return std::make_pair(values + i, false);\n\
    \    }\n\n    bool erase(const Key& key) {\n        if (empty()) return false;\n\
    \        const usize pos = hash0(static_cast<u64>(key));\n        const u8 id\
    \ = hash1(static_cast<u64>(key));\n        const usize i = find_key(key, pos,\
    \ id);\n        if (state[i] != 128) {\n            full -= 1;\n            del\
    \ += 1;\n            state[i] = 129;\n            TraitsV::destroy(alloc_v, values\
    \ + i);\n            if (8 * full <= mask) resize();\n            return true;\n\
    \        }\n        return false;\n    }\n\n    Value* find(const Key& key) {\n\
    \        if (empty()) return nullptr;\n        const usize pos = hash0(static_cast<u64>(key));\n\
    \        const u8 id = hash1(static_cast<u64>(key));\n        const usize i =\
    \ find_key(key, pos, id);\n        return state[i] == 128 ? nullptr : (values\
    \ + i);\n    }\n\n    void clear() {\n        if (initialized()) {\n         \
    \   for (usize i = 0; i <= mask; i += 1)\n                if (state[i] < 128)\
    \ TraitsV::destroy(alloc_v, values + i);\n            TraitsK::deallocate(alloc_k,\
    \ keys, mask + 1);\n            TraitsV::deallocate(alloc_v, values, mask + 1);\n\
    \            TraitsU::deallocate(alloc_u, state, mask + 1);\n            reset_variables();\n\
    \        }\n    }\n\n    Value& operator[](const Key& key) { return *insert(key,\
    \ Value()).first; }\n    usize size() { return full; }\n    bool empty() { return\
    \ size() == 0; }\n\n    Iter begin() { return Iter(0, this); }\n    Iter end()\
    \ { return Iter(mask + 1, this); }\n};\n"
  code: "#pragma once\n#include <cstring>\n#include <memory>\n#include <type_traits>\n\
    #include <utility>\n#include \"../utility/int_alias.cpp\"\n#include \"../utility/int_alias_extended.cpp\"\
    \n\ntemplate <class Key, class Value, std::enable_if_t<std::is_integral_v<Key>>*\
    \ = nullptr> class IntegerHashMap {\n    using TraitsK = std::allocator_traits<std::allocator<Key>>;\n\
    \    using TraitsV = std::allocator_traits<std::allocator<Value>>;\n    using\
    \ TraitsU = std::allocator_traits<std::allocator<u8>>;\n\n    class Iter {\n \
    \       using Ref = std::pair<const Key&, Value&>;\n        friend class IntegerHashMap;\n\
    \n        usize idx;\n        IntegerHashMap* map;\n\n        explicit Iter(const\
    \ usize i, IntegerHashMap* m) : idx(i), map(m) { step(); }\n        void step()\
    \ {\n            while (idx <= map->mask and map->state[idx] >= 128) idx += 1;\n\
    \        }\n\n      public:\n        bool operator!=(const Iter& other) const\
    \ { return idx != other.idx; }\n        Ref operator*() { return Ref(map->keys[idx],\
    \ map->values[idx]); }\n        void operator++() {\n            idx += 1;\n \
    \           step();\n        }\n    };\n\n    usize full, del, logn, mask;\n \
    \   u8* state;\n    Key* keys;\n    Value* values;\n    std::allocator<u8> alloc_u;\n\
    \    std::allocator<Key> alloc_k;\n    std::allocator<Value> alloc_v;\n\n    u64\
    \ hash0(u64 key) const {\n        if (logn == 0) return 0;\n        key ^= key\
    \ >> (64 - logn);\n        return (key * 11400714819323198485ull) >> (64 - logn);\n\
    \    }\n    u8 hash1(u64 key) const {\n        key ^= key >> 57;\n        return\
    \ (key * 5871781006564002453ull) >> 57;\n    }\n\n    usize find_key(const Key&\
    \ key, usize i, const u8 id) const {\n        while (state[i] != 128) {\n    \
    \        if (state[i] == id and keys[i] == key) return i;\n            i += 1;\n\
    \            i &= mask;\n        }\n        return i;\n    }\n    usize find_nonfull(usize\
    \ i) const {\n        while (state[i] < 128) {\n            i += 1;\n        \
    \    i &= mask;\n        }\n        return i;\n    }\n\n    void resize() {\n\
    \        u8* old_state = state;\n        Key* old_keys = keys;\n        Value*\
    \ old_values = values;\n        const usize old_len = (!initialized() ? 0 : mask\
    \ + 1);\n        del = 0;\n        logn = 0;\n        while (3 * full > ((usize)1\
    \ << logn)) logn += 1;\n        mask = (1 << logn) - 1;\n        state = TraitsU::allocate(alloc_u,\
    \ mask + 1);\n        keys = TraitsK::allocate(alloc_k, mask + 1);\n        values\
    \ = TraitsV::allocate(alloc_v, mask + 1);\n        std::memset(state, 128, mask\
    \ + 1);\n        for (usize i = 0; i < old_len; i += 1) {\n            if (old_state[i]\
    \ < 128) {\n                const usize k = find_nonfull(hash0(static_cast<u64>(old_keys[i])));\n\
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
    \ alloc_k(), alloc_v() {\n        reset_variables();\n        for (usize i = 0;\
    \ i <= other.mask; i += 1)\n            if (other.state[i] < 128) insert(other.keys[i],\
    \ other.values[i]);\n    }\n    IntegerHashMap(IntegerHashMap&& other) noexcept\
    \ : alloc_u(), alloc_k(), alloc_v() {\n        full = std::exchange(other.full,\
    \ 0);\n        del = std::exchange(other.del, 0);\n        logn = std::exchange(other.logn,\
    \ 0);\n        mask = std::exchange(other.mask, 0);\n        state = std::exchange(other.state,\
    \ nullptr);\n        keys = std::exchange(other.keys, nullptr);\n        values\
    \ = std::exchange(other.values, nullptr);\n    }\n\n    IntegerHashMap& operator=(const\
    \ IntegerHashMap& other) noexcept {\n        if (this != &other) {\n         \
    \   clear();\n            for (usize i = 0; i <= other.mask; i += 1)\n       \
    \         if (other.state[i] < 128) insert(other.keys[i], other.values[i]);\n\
    \        }\n        return *this;\n    }\n    IntegerHashMap& operator=(IntegerHashMap&&\
    \ other) noexcept {\n        if (this != &other) {\n            clear();\n   \
    \         full = std::exchange(other.full, 0);\n            del = std::exchange(other.del,\
    \ 0);\n            logn = std::exchange(other.logn, 0);\n            mask = std::exchange(other.mask,\
    \ 0);\n            state = std::exchange(other.state, nullptr);\n            keys\
    \ = std::exchange(other.keys, nullptr);\n            values = std::exchange(other.values,\
    \ nullptr);\n        }\n        return *this;\n    }\n\n    template <class...\
    \ Args> std::pair<Value*, bool> insert(const Key& key, Args&&... args) {\n   \
    \     if (!initialized()) resize();\n        const usize pos = hash0(static_cast<u64>(key));\n\
    \        const u8 id = hash1(static_cast<u64>(key));\n        usize i = find_key(key,\
    \ pos, id);\n        if (state[i] == 128) {\n            i = find_nonfull(pos);\n\
    \            full += 1;\n            del -= (state[i] == 129);\n            if\
    \ (2 * (full + del) > mask + 1) {\n                resize();\n               \
    \ i = find_nonfull(hash0(static_cast<u64>(key)));\n            }\n           \
    \ state[i] = id;\n            keys[i] = key;\n            TraitsV::construct(alloc_v,\
    \ values + i, std::forward<Args>(args)...);\n            return std::make_pair(values\
    \ + i, true);\n        }\n        return std::make_pair(values + i, false);\n\
    \    }\n\n    bool erase(const Key& key) {\n        if (empty()) return false;\n\
    \        const usize pos = hash0(static_cast<u64>(key));\n        const u8 id\
    \ = hash1(static_cast<u64>(key));\n        const usize i = find_key(key, pos,\
    \ id);\n        if (state[i] != 128) {\n            full -= 1;\n            del\
    \ += 1;\n            state[i] = 129;\n            TraitsV::destroy(alloc_v, values\
    \ + i);\n            if (8 * full <= mask) resize();\n            return true;\n\
    \        }\n        return false;\n    }\n\n    Value* find(const Key& key) {\n\
    \        if (empty()) return nullptr;\n        const usize pos = hash0(static_cast<u64>(key));\n\
    \        const u8 id = hash1(static_cast<u64>(key));\n        const usize i =\
    \ find_key(key, pos, id);\n        return state[i] == 128 ? nullptr : (values\
    \ + i);\n    }\n\n    void clear() {\n        if (initialized()) {\n         \
    \   for (usize i = 0; i <= mask; i += 1)\n                if (state[i] < 128)\
    \ TraitsV::destroy(alloc_v, values + i);\n            TraitsK::deallocate(alloc_k,\
    \ keys, mask + 1);\n            TraitsV::deallocate(alloc_v, values, mask + 1);\n\
    \            TraitsU::deallocate(alloc_u, state, mask + 1);\n            reset_variables();\n\
    \        }\n    }\n\n    Value& operator[](const Key& key) { return *insert(key,\
    \ Value()).first; }\n    usize size() { return full; }\n    bool empty() { return\
    \ size() == 0; }\n\n    Iter begin() { return Iter(0, this); }\n    Iter end()\
    \ { return Iter(mask + 1, this); }\n};\n"
  dependsOn:
  - utility/int_alias.cpp
  - utility/int_alias_extended.cpp
  isVerificationFile: false
  path: container/integer_hash_map.cpp
  requiredBy: []
  timestamp: '2021-09-08 18:46:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: container/integer_hash_map.cpp
layout: document
redirect_from:
- /library/container/integer_hash_map.cpp
- /library/container/integer_hash_map.cpp.html
title: container/integer_hash_map.cpp
---
