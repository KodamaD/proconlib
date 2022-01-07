---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: internal/enable_avx2.cpp
    title: internal/enable_avx2.cpp
  - icon: ':heavy_check_mark:'
    path: utility/countl_zero.cpp
    title: utility/countl_zero.cpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
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
    path: math/prime_sieve.cpp
    title: math/prime_sieve.cpp
  - icon: ':heavy_check_mark:'
    path: utility/auto_realloc.cpp
    title: utility/auto_realloc.cpp
  - icon: ':heavy_check_mark:'
    path: utility/ceil_log2.cpp
    title: utility/ceil_log2.cpp
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
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"internal/enable_avx2.cpp\"\n\n#ifdef ENABLE_AVX2\n#define\
    \ TARGET_AVX2 __attribute__((target(\"avx2\")))\n#else\n#define TARGET_AVX2\n\
    #endif\n#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n\nusing i32 = std::int32_t;\n\
    using u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n#line 4 \"utility/countl_zero.cpp\"\
    \n\nTARGET_AVX2 constexpr int countl_zero(u64 x) {\n#ifdef __GNUC__\n    return\
    \ x == 0 ? 64 : __builtin_clzll(x);\n#else\n    x |= x >> 1;\n    x |= x >> 2;\n\
    \    x |= x >> 4;\n    x |= x >> 8;\n    x |= x >> 16;\n    x |= x >> 32;\n  \
    \  return 64 - countr_zero(~x);\n#endif\n}\n#line 4 \"utility/bit_width.cpp\"\n\
    \nTARGET_AVX2 constexpr int bit_width(const u64 x) { return 64 - countl_zero(x);\
    \ }\n"
  code: '#pragma once

    #include "../internal/enable_avx2.cpp"

    #include "countl_zero.cpp"


    TARGET_AVX2 constexpr int bit_width(const u64 x) { return 64 - countl_zero(x);
    }

    '
  dependsOn:
  - internal/enable_avx2.cpp
  - utility/countl_zero.cpp
  - utility/int_alias.cpp
  isVerificationFile: false
  path: utility/bit_width.cpp
  requiredBy:
  - math/prime_sieve.cpp
  - algorithm/convolution_mod.cpp
  - algorithm/convolution_arbitrary_mod.cpp
  - algorithm/convolution_int.cpp
  - utility/auto_realloc.cpp
  - utility/ceil_log2.cpp
  - container/fenwick_tree.cpp
  - container/lazy_segment_tree.cpp
  - container/dual_segment_tree.cpp
  - container/segment_tree_beats.cpp
  - container/integer_hash_table.cpp
  - container/segment_tree.cpp
  - container/sparse_table.cpp
  timestamp: '2022-01-07 21:48:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution_arbitrary_mod.test.cpp
  - test/larsch.test.cpp
  - test/integer_hash_table_verbose.test.cpp
  - test/lazy_segment_tree.test.cpp
  - test/sparse_table.test.cpp
  - test/heavy_light_decomposition.test.cpp
  - test/segment_tree.test.cpp
  - test/segment_tree_beats.test.cpp
  - test/dual_segment_tree.test.cpp
  - test/prime_sieve.test.cpp
  - test/fenwick_tree.test.cpp
  - test/integer_hash_table.test.cpp
  - test/convolution_mod.test.cpp
documentation_of: utility/bit_width.cpp
layout: document
redirect_from:
- /library/utility/bit_width.cpp
- /library/utility/bit_width.cpp.html
title: utility/bit_width.cpp
---
