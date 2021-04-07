---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algorithm/monotone_minima.cpp
    title: algorithm/monotone_minima.cpp
  - icon: ':warning:'
    path: algorithm/smawk.cpp
    title: algorithm/smawk.cpp
  - icon: ':heavy_check_mark:'
    path: bit/bit_lzeros.cpp
    title: bit/bit_lzeros.cpp
  - icon: ':heavy_check_mark:'
    path: bit/bit_rzeros.cpp
    title: bit/bit_rzeros.cpp
  - icon: ':heavy_check_mark:'
    path: bit/bit_width.cpp
    title: bit/bit_width.cpp
  - icon: ':question:'
    path: bit/ceil_log2.cpp
    title: bit/ceil_log2.cpp
  - icon: ':warning:'
    path: bit/popcount.cpp
    title: bit/popcount.cpp
  - icon: ':heavy_check_mark:'
    path: container/dual_segment_tree.cpp
    title: container/dual_segment_tree.cpp
  - icon: ':heavy_check_mark:'
    path: container/fenwick_tree.cpp
    title: container/fenwick_tree.cpp
  - icon: ':heavy_check_mark:'
    path: container/lazy_segment_tree.cpp
    title: container/lazy_segment_tree.cpp
  - icon: ':heavy_check_mark:'
    path: container/segment_tree.cpp
    title: container/segment_tree.cpp
  - icon: ':heavy_check_mark:'
    path: container/sparse_table.cpp
    title: container/sparse_table.cpp
  - icon: ':heavy_check_mark:'
    path: graph/union_find.cpp
    title: graph/union_find.cpp
  - icon: ':warning:'
    path: math/divisors_from_factors.cpp
    title: math/divisors_from_factors.cpp
  - icon: ':warning:'
    path: math/dynamic_modint.cpp
    title: math/dynamic_modint.cpp
  - icon: ':heavy_check_mark:'
    path: math/factorize.cpp
    title: math/factorize.cpp
  - icon: ':x:'
    path: math/modint_util.cpp
    title: math/modint_util.cpp
  - icon: ':x:'
    path: math/prime_sieve.cpp
    title: math/prime_sieve.cpp
  - icon: ':question:'
    path: math/static_modint.cpp
    title: math/static_modint.cpp
  - icon: ':warning:'
    path: utility/auto_memoize.cpp
    title: utility/auto_memoize.cpp
  - icon: ':x:'
    path: utility/auto_realloc.cpp
    title: utility/auto_realloc.cpp
  - icon: ':question:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  - icon: ':heavy_check_mark:'
    path: utility/revrep.cpp
    title: utility/revrep.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dual_segment_tree.test.cpp
    title: test/dual_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/factorize.test.cpp
    title: test/factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fenwick_tree.test.cpp
    title: test/fenwick_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazy_segment_tree.test.cpp
    title: test/lazy_segment_tree.test.cpp
  - icon: ':x:'
    path: test/modint_util.test.cpp
    title: test/modint_util.test.cpp
  - icon: ':x:'
    path: test/prime_sieve.test.cpp
    title: test/prime_sieve.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment_tree.test.cpp
    title: test/segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/sparse_table.test.cpp
    title: test/sparse_table.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/union_find.test.cpp
    title: test/union_find.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
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
  - utility/revrep.cpp
  - utility/rep.cpp
  - utility/auto_realloc.cpp
  - utility/auto_memoize.cpp
  - container/segment_tree.cpp
  - container/sparse_table.cpp
  - container/fenwick_tree.cpp
  - container/dual_segment_tree.cpp
  - container/lazy_segment_tree.cpp
  - math/factorize.cpp
  - math/static_modint.cpp
  - math/dynamic_modint.cpp
  - math/divisors_from_factors.cpp
  - math/modint_util.cpp
  - math/prime_sieve.cpp
  - graph/union_find.cpp
  - algorithm/monotone_minima.cpp
  - algorithm/smawk.cpp
  - bit/bit_lzeros.cpp
  - bit/bit_width.cpp
  - bit/ceil_log2.cpp
  - bit/bit_rzeros.cpp
  - bit/popcount.cpp
  timestamp: '2021-03-24 22:26:55+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/fenwick_tree.test.cpp
  - test/factorize.test.cpp
  - test/sparse_table.test.cpp
  - test/modint_util.test.cpp
  - test/lazy_segment_tree.test.cpp
  - test/union_find.test.cpp
  - test/segment_tree.test.cpp
  - test/dual_segment_tree.test.cpp
  - test/prime_sieve.test.cpp
documentation_of: utility/int_alias.cpp
layout: document
redirect_from:
- /library/utility/int_alias.cpp
- /library/utility/int_alias.cpp.html
title: utility/int_alias.cpp
---
