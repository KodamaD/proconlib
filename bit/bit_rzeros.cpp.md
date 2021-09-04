---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: container/dual_segment_tree.cpp
    title: container/dual_segment_tree.cpp
  - icon: ':heavy_check_mark:'
    path: container/lazy_segment_tree.cpp
    title: container/lazy_segment_tree.cpp
  - icon: ':x:'
    path: container/segment_tree_beats.cpp
    title: container/segment_tree_beats.cpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/dual_segment_tree.test.cpp
    title: test/dual_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazy_segment_tree.test.cpp
    title: test/lazy_segment_tree.test.cpp
  - icon: ':x:'
    path: test/segment_tree_beats.test.cpp
    title: test/segment_tree_beats.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: '#line 2 "utility/int_alias.cpp"

    #include <cstddef>

    #include <cstdint>


    using i32 = std::int32_t;

    using u32 = std::uint32_t;

    using i64 = std::int64_t;

    using u64 = std::uint64_t;

    using i128 = __int128_t;

    using u128 = __uint128_t;

    using isize = std::ptrdiff_t;

    using usize = std::size_t;

    #line 3 "bit/bit_rzeros.cpp"


    constexpr u64 bit_rzeros(const u64 x) { return x == 0 ? 64 : __builtin_ctzll(x);
    }

    '
  code: '#pragma once

    #include "../utility/int_alias.cpp"


    constexpr u64 bit_rzeros(const u64 x) { return x == 0 ? 64 : __builtin_ctzll(x);
    }

    '
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: bit/bit_rzeros.cpp
  requiredBy:
  - container/segment_tree_beats.cpp
  - container/dual_segment_tree.cpp
  - container/lazy_segment_tree.cpp
  timestamp: '2021-09-04 17:30:23+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/segment_tree_beats.test.cpp
  - test/dual_segment_tree.test.cpp
  - test/lazy_segment_tree.test.cpp
documentation_of: bit/bit_rzeros.cpp
layout: document
redirect_from:
- /library/bit/bit_rzeros.cpp
- /library/bit/bit_rzeros.cpp.html
title: bit/bit_rzeros.cpp
---
