---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: utility/countl_zero.cpp
    title: utility/countl_zero.cpp
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: container/sparse_table.cpp
    title: container/sparse_table.cpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/sparse_table.test.cpp
    title: test/sparse_table.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
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

    #line 3 "utility/bit_width.cpp"


    __attribute__((target("avx2"))) constexpr int bit_width(const u64 x) { return
    64 - countl_zero(x); }

    '
  code: '#pragma once

    #include "countl_zero.cpp"


    __attribute__((target("avx2"))) constexpr int bit_width(const u64 x) { return
    64 - countl_zero(x); }

    '
  dependsOn:
  - utility/countl_zero.cpp
  - utility/int_alias.cpp
  isVerificationFile: false
  path: utility/bit_width.cpp
  requiredBy:
  - container/sparse_table.cpp
  timestamp: '2021-12-17 09:20:39+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/sparse_table.test.cpp
documentation_of: utility/bit_width.cpp
layout: document
redirect_from:
- /library/utility/bit_width.cpp
- /library/utility/bit_width.cpp.html
title: utility/bit_width.cpp
---
