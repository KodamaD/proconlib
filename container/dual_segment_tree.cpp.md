---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bit/bit_rzeros.cpp
    title: bit/bit_rzeros.cpp
  - icon: ':heavy_check_mark:'
    path: bit/ceil_log2.cpp
    title: bit/ceil_log2.cpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':heavy_check_mark:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  - icon: ':heavy_check_mark:'
    path: utility/revrep.cpp
    title: utility/revrep.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dual_segment_tree.test.cpp
    title: test/dual_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n#include <cstddef>\n\
    \nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    using isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 3 \"utility/rep.cpp\"\
    \n#include <algorithm>\n\nclass rep {\n    struct Iter {\n        usize itr;\n\
    \        constexpr Iter(const usize pos) noexcept: itr(pos) { }\n        constexpr\
    \ void operator ++ () noexcept { ++itr; }\n        constexpr bool operator !=\
    \ (const Iter& other) const noexcept { return itr != other.itr; }\n        constexpr\
    \ usize operator * () const noexcept { return itr; }\n    };\n    const Iter first,\
    \ last;\npublic:\n    explicit constexpr rep(const usize first, const usize last)\
    \ noexcept: first(first), last(std::max(first, last)) { }\n    constexpr Iter\
    \ begin() const noexcept { return first; }\n    constexpr Iter end() const noexcept\
    \ { return last; }\n};\n#line 4 \"utility/revrep.cpp\"\n\nclass revrep {\n   \
    \ struct Iter {\n        usize itr;\n        constexpr Iter(const usize pos) noexcept:\
    \ itr(pos) { }\n        constexpr void operator ++ () noexcept { --itr; }\n  \
    \      constexpr bool operator != (const Iter& other) const noexcept { return\
    \ itr != other.itr; }\n        constexpr usize operator * () const noexcept {\
    \ return itr; }\n    };\n    const Iter first, last;\npublic:\n    explicit constexpr\
    \ revrep(const usize first, const usize last) noexcept: first(last - 1), last(std::min(first,\
    \ last) - 1) { }\n    constexpr Iter begin() const noexcept { return first; }\n\
    \    constexpr Iter end() const noexcept { return last; }\n};\n#line 3 \"bit/ceil_log2.cpp\"\
    \n\nconstexpr u64 ceil_log2(const u64 x) {\n    u64 e = 0;\n    while (((u64)\
    \ 1 << e) < x) ++e;\n    return e;\n}\n#line 3 \"bit/bit_rzeros.cpp\"\n\nconstexpr\
    \ u64 bit_rzeros(const u64 x) {\n    return x == 0 ? 64 : __builtin_ctzll(x);\n\
    }\n#line 7 \"container/dual_segment_tree.cpp\"\n#include <vector>\n#include <cassert>\n\
    \ntemplate <class Effector>\nclass DualSegmentTree {\n    using E = Effector;\n\
    \    usize internal_size, logn;\n    std::vector<E> lazy;\n\n    void apply(const\
    \ usize k, const E& e) { lazy[k] = lazy[k] * e; }\n    void flush(const usize\
    \ k) {\n        apply(2 * k, lazy[k]);\n        apply(2 * k + 1, lazy[k]);\n \
    \       lazy[k] = E::one();\n    }\n    void push(const usize k) {\n        for\
    \ (const usize d: revrep(bit_rzeros(k) + 1, logn + 1)) {\n            flush(k\
    \ >> d);\n        }\n    }\n\npublic:\n    explicit DualSegmentTree(const usize\
    \ size = 0, const E& value = E::one()):\n        DualSegmentTree(std::vector<E>(size,\
    \ value)) { }\n    explicit DualSegmentTree(const std::vector<E>& vec): internal_size(vec.size())\
    \ {\n        logn = ceil_log2(internal_size);\n        lazy = std::vector<E>(2\
    \ * internal_size, E::one());\n        for (const usize i: rep(0, internal_size))\
    \ lazy[i] = vec[i];\n    }\n    \n    usize size() const { return internal_size;\
    \ }\n\n    void operate(usize l, usize r, const E& e) {\n        assert(l <= r\
    \ and r <= internal_size);\n        l += internal_size; r += internal_size;\n\
    \        push(l); push(r);\n        while (l < r) {\n            if (l & 1) apply(l++,\
    \ e);\n            if (r & 1) apply(--r, e);\n            l >>= 1;\n         \
    \   r >>= 1;\n        }\n    }\n    void assign(usize i, const E& e) {\n     \
    \   assert(i < internal_size);\n        i += internal_size;\n        for (const\
    \ usize d: revrep(1, logn + 1)) flush(i >> d);\n        lazy[i] = e;\n    }\n\n\
    \    E get(usize i) const {\n        assert(i < internal_size);\n        i +=\
    \ internal_size;\n        E ret = E::one();\n        while (i > 0) {\n       \
    \     ret = ret * lazy[i];\n            i >>= 1;\n        }\n        return ret;\n\
    \    }\n};\n"
  code: "#pragma once\n#include \"../utility/int_alias.cpp\"\n#include \"../utility/rep.cpp\"\
    \n#include \"../utility/revrep.cpp\"\n#include \"../bit/ceil_log2.cpp\"\n#include\
    \ \"../bit/bit_rzeros.cpp\"\n#include <vector>\n#include <cassert>\n\ntemplate\
    \ <class Effector>\nclass DualSegmentTree {\n    using E = Effector;\n    usize\
    \ internal_size, logn;\n    std::vector<E> lazy;\n\n    void apply(const usize\
    \ k, const E& e) { lazy[k] = lazy[k] * e; }\n    void flush(const usize k) {\n\
    \        apply(2 * k, lazy[k]);\n        apply(2 * k + 1, lazy[k]);\n        lazy[k]\
    \ = E::one();\n    }\n    void push(const usize k) {\n        for (const usize\
    \ d: revrep(bit_rzeros(k) + 1, logn + 1)) {\n            flush(k >> d);\n    \
    \    }\n    }\n\npublic:\n    explicit DualSegmentTree(const usize size = 0, const\
    \ E& value = E::one()):\n        DualSegmentTree(std::vector<E>(size, value))\
    \ { }\n    explicit DualSegmentTree(const std::vector<E>& vec): internal_size(vec.size())\
    \ {\n        logn = ceil_log2(internal_size);\n        lazy = std::vector<E>(2\
    \ * internal_size, E::one());\n        for (const usize i: rep(0, internal_size))\
    \ lazy[i] = vec[i];\n    }\n    \n    usize size() const { return internal_size;\
    \ }\n\n    void operate(usize l, usize r, const E& e) {\n        assert(l <= r\
    \ and r <= internal_size);\n        l += internal_size; r += internal_size;\n\
    \        push(l); push(r);\n        while (l < r) {\n            if (l & 1) apply(l++,\
    \ e);\n            if (r & 1) apply(--r, e);\n            l >>= 1;\n         \
    \   r >>= 1;\n        }\n    }\n    void assign(usize i, const E& e) {\n     \
    \   assert(i < internal_size);\n        i += internal_size;\n        for (const\
    \ usize d: revrep(1, logn + 1)) flush(i >> d);\n        lazy[i] = e;\n    }\n\n\
    \    E get(usize i) const {\n        assert(i < internal_size);\n        i +=\
    \ internal_size;\n        E ret = E::one();\n        while (i > 0) {\n       \
    \     ret = ret * lazy[i];\n            i >>= 1;\n        }\n        return ret;\n\
    \    }\n};"
  dependsOn:
  - utility/int_alias.cpp
  - utility/rep.cpp
  - utility/revrep.cpp
  - bit/ceil_log2.cpp
  - bit/bit_rzeros.cpp
  isVerificationFile: false
  path: container/dual_segment_tree.cpp
  requiredBy: []
  timestamp: '2021-04-06 09:35:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dual_segment_tree.test.cpp
documentation_of: container/dual_segment_tree.cpp
layout: document
redirect_from:
- /library/container/dual_segment_tree.cpp
- /library/container/dual_segment_tree.cpp.html
title: container/dual_segment_tree.cpp
---
