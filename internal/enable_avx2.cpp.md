---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algorithm/convolution_arbitrary_mod.cpp
    title: algorithm/convolution_arbitrary_mod.cpp
  - icon: ':warning:'
    path: algorithm/convolution_int.cpp
    title: algorithm/convolution_int.cpp
  - icon: ':heavy_check_mark:'
    path: algorithm/convolution_mod.cpp
    title: algorithm/convolution_mod.cpp
  - icon: ':heavy_check_mark:'
    path: algorithm/ranked_subset_mobius_transform.cpp
    title: algorithm/ranked_subset_mobius_transform.cpp
  - icon: ':heavy_check_mark:'
    path: algorithm/ranked_subset_zeta_transform.cpp
    title: algorithm/ranked_subset_zeta_transform.cpp
  - icon: ':heavy_check_mark:'
    path: algorithm/subset_convolution.cpp
    title: algorithm/subset_convolution.cpp
  - icon: ':heavy_check_mark:'
    path: container/dual_segment_tree.cpp
    title: container/dual_segment_tree.cpp
  - icon: ':heavy_check_mark:'
    path: container/fenwick_tree.cpp
    title: container/fenwick_tree.cpp
  - icon: ':heavy_check_mark:'
    path: container/integer_hash_table.cpp
    title: container/integer_hash_table.cpp
  - icon: ':heavy_check_mark:'
    path: container/lazy_segment_tree.cpp
    title: container/lazy_segment_tree.cpp
  - icon: ':heavy_check_mark:'
    path: container/segment_tree.cpp
    title: container/segment_tree.cpp
  - icon: ':heavy_check_mark:'
    path: container/segment_tree_beats.cpp
    title: container/segment_tree_beats.cpp
  - icon: ':heavy_check_mark:'
    path: container/sparse_table.cpp
    title: container/sparse_table.cpp
  - icon: ':heavy_check_mark:'
    path: internal/modulo_transform.cpp
    title: internal/modulo_transform.cpp
  - icon: ':heavy_check_mark:'
    path: math/prime_sieve.cpp
    title: math/prime_sieve.cpp
  - icon: ':heavy_check_mark:'
    path: utility/auto_realloc.cpp
    title: utility/auto_realloc.cpp
  - icon: ':heavy_check_mark:'
    path: utility/bit_width.cpp
    title: utility/bit_width.cpp
  - icon: ':heavy_check_mark:'
    path: utility/ceil_log2.cpp
    title: utility/ceil_log2.cpp
  - icon: ':heavy_check_mark:'
    path: utility/countl_zero.cpp
    title: utility/countl_zero.cpp
  - icon: ':heavy_check_mark:'
    path: utility/countr_zero.cpp
    title: utility/countr_zero.cpp
  - icon: ':heavy_check_mark:'
    path: utility/fast_io.cpp
    title: utility/fast_io.cpp
  - icon: ':heavy_check_mark:'
    path: utility/popcount.cpp
    title: utility/popcount.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution_arbitrary_mod.test.cpp
    title: test/convolution_arbitrary_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution_mod.test.cpp
    title: test/convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/dual_segment_tree.test.cpp
    title: test/dual_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fast_io.test.cpp
    title: test/fast_io.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fenwick_tree.test.cpp
    title: test/fenwick_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/heavy_light_decomposition.test.cpp
    title: test/heavy_light_decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/integer_hash_table.test.cpp
    title: test/integer_hash_table.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/integer_hash_table_verbose.test.cpp
    title: test/integer_hash_table_verbose.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/larsch.test.cpp
    title: test/larsch.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazy_segment_tree.test.cpp
    title: test/lazy_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/prime_sieve.test.cpp
    title: test/prime_sieve.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment_tree.test.cpp
    title: test/segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment_tree_beats.test.cpp
    title: test/segment_tree_beats.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/sparse_table.test.cpp
    title: test/sparse_table.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/subset_convolution.test.cpp
    title: test/subset_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 2 "internal/enable_avx2.cpp"


    #ifdef ENABLE_AVX2

    #define TARGET_AVX2 __attribute__((target("avx2")))

    #else

    #define TARGET_AVX2

    #endif

    '
  code: '#pragma once


    #ifdef ENABLE_AVX2

    #define TARGET_AVX2 __attribute__((target("avx2")))

    #else

    #define TARGET_AVX2

    #endif'
  dependsOn: []
  isVerificationFile: false
  path: internal/enable_avx2.cpp
  requiredBy:
  - internal/modulo_transform.cpp
  - algorithm/convolution_arbitrary_mod.cpp
  - algorithm/ranked_subset_mobius_transform.cpp
  - algorithm/subset_convolution.cpp
  - algorithm/convolution_int.cpp
  - algorithm/convolution_mod.cpp
  - algorithm/ranked_subset_zeta_transform.cpp
  - container/dual_segment_tree.cpp
  - container/segment_tree_beats.cpp
  - container/fenwick_tree.cpp
  - container/lazy_segment_tree.cpp
  - container/sparse_table.cpp
  - container/integer_hash_table.cpp
  - container/segment_tree.cpp
  - math/prime_sieve.cpp
  - utility/auto_realloc.cpp
  - utility/bit_width.cpp
  - utility/ceil_log2.cpp
  - utility/fast_io.cpp
  - utility/countr_zero.cpp
  - utility/countl_zero.cpp
  - utility/popcount.cpp
  timestamp: '2022-01-07 21:48:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/larsch.test.cpp
  - test/convolution_mod.test.cpp
  - test/segment_tree.test.cpp
  - test/segment_tree_beats.test.cpp
  - test/integer_hash_table_verbose.test.cpp
  - test/sparse_table.test.cpp
  - test/integer_hash_table.test.cpp
  - test/heavy_light_decomposition.test.cpp
  - test/dual_segment_tree.test.cpp
  - test/lazy_segment_tree.test.cpp
  - test/fenwick_tree.test.cpp
  - test/subset_convolution.test.cpp
  - test/fast_io.test.cpp
  - test/convolution_arbitrary_mod.test.cpp
  - test/prime_sieve.test.cpp
documentation_of: internal/enable_avx2.cpp
layout: document
redirect_from:
- /library/internal/enable_avx2.cpp
- /library/internal/enable_avx2.cpp.html
title: internal/enable_avx2.cpp
---
