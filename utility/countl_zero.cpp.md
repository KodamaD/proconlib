---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: container/sparse_table.cpp
    title: container/sparse_table.cpp
  - icon: ':heavy_check_mark:'
    path: utility/bit_width.cpp
    title: utility/bit_width.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/sparse_table.test.cpp
    title: test/sparse_table.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 2 "utility/int_alias.cpp"

    #include <cstdint>


    using i32 = std::int32_t;

    using u32 = std::uint32_t;

    using i64 = std::int64_t;

    using u64 = std::uint64_t;

    using i128 = __int128_t;

    using u128 = __uint128_t;

    #line 3 "utility/countl_zero.cpp"


    __attribute__((target("avx2"))) constexpr int countl_zero(const u64 x) { return
    x == 0 ? 64 : __builtin_clzll(x); }

    '
  code: '#pragma once

    #include "int_alias.cpp"


    __attribute__((target("avx2"))) constexpr int countl_zero(const u64 x) { return
    x == 0 ? 64 : __builtin_clzll(x); }

    '
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: utility/countl_zero.cpp
  requiredBy:
  - utility/bit_width.cpp
  - container/sparse_table.cpp
  timestamp: '2021-12-17 09:20:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/sparse_table.test.cpp
documentation_of: utility/countl_zero.cpp
layout: document
redirect_from:
- /library/utility/countl_zero.cpp
- /library/utility/countl_zero.cpp.html
title: utility/countl_zero.cpp
---
