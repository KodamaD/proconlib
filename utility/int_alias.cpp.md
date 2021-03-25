---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: bit/ceil_log2.cpp
    title: bit/ceil_log2.cpp
  - icon: ':warning:'
    path: math/dynamic_modint.cpp
    title: math/dynamic_modint.cpp
  - icon: ':heavy_check_mark:'
    path: math/modint_util.cpp
    title: math/modint_util.cpp
  - icon: ':warning:'
    path: math/prime_util.cpp
    title: math/prime_util.cpp
  - icon: ':heavy_check_mark:'
    path: math/static_modint.cpp
    title: math/static_modint.cpp
  - icon: ':heavy_check_mark:'
    path: utility/auto_realloc.cpp
    title: utility/auto_realloc.cpp
  - icon: ':heavy_check_mark:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  - icon: ':warning:'
    path: utility/rev_rep.cpp
    title: utility/rev_rep.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/modint_util.test.cpp
    title: test/modint_util.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 2 "utility/int_alias.cpp"

    #include <cstdint>

    #include <cstddef>


    using i32 = std::int32_t;

    using u32 = std::uint32_t;

    using i64 = std::int64_t;

    using u64 = std::uint64_t;

    using i128 = __int128_t;

    using u128 = __uint128_t;

    using isize = std::ptrdiff_t;

    using usize = std::size_t;

    '
  code: '#pragma once

    #include <cstdint>

    #include <cstddef>


    using i32 = std::int32_t;

    using u32 = std::uint32_t;

    using i64 = std::int64_t;

    using u64 = std::uint64_t;

    using i128 = __int128_t;

    using u128 = __uint128_t;

    using isize = std::ptrdiff_t;

    using usize = std::size_t;

    '
  dependsOn: []
  isVerificationFile: false
  path: utility/int_alias.cpp
  requiredBy:
  - utility/auto_realloc.cpp
  - utility/rep.cpp
  - utility/rev_rep.cpp
  - math/modint_util.cpp
  - math/static_modint.cpp
  - math/dynamic_modint.cpp
  - math/prime_util.cpp
  - bit/ceil_log2.cpp
  timestamp: '2021-03-24 22:26:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/modint_util.test.cpp
documentation_of: utility/int_alias.cpp
layout: document
redirect_from:
- /library/utility/int_alias.cpp
- /library/utility/int_alias.cpp.html
title: utility/int_alias.cpp
---
