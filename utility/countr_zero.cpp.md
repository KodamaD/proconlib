---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: internal/enable_avx2.cpp
    title: internal/enable_avx2.cpp
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
    path: container/lazy_segment_tree.cpp
    title: container/lazy_segment_tree.cpp
  - icon: ':heavy_check_mark:'
    path: container/segment_tree_beats.cpp
    title: container/segment_tree_beats.cpp
  - icon: ':heavy_check_mark:'
    path: internal/modulo_transform.cpp
    title: internal/modulo_transform.cpp
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
    path: test/lazy_segment_tree.test.cpp
    title: test/lazy_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment_tree_beats.test.cpp
    title: test/segment_tree_beats.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/countr_zero.cpp\"\n#include <array>\n#line 2 \"\
    internal/enable_avx2.cpp\"\n\n#ifdef ENABLE_AVX2\n#define TARGET_AVX2 __attribute__((target(\"\
    avx2\")))\n#else\n#define TARGET_AVX2\n#endif\n#line 2 \"utility/int_alias.cpp\"\
    \n#include <cstdint>\n\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\n\
    using i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\n#line 5 \"utility/countr_zero.cpp\"\n\nconstexpr int\
    \ countr_zero(u64 x) {\n    if (x == 0) return 64;\n#ifdef __GNUC__\n    return\
    \ __builtin_ctzll(x);\n#else\n    constexpr std::array<int, 64> table = {0,  1,\
    \  2,  7,  3,  13, 8,  27, 4,  33, 14, 36, 9,  49, 28, 19,\n                 \
    \                            5,  25, 34, 17, 15, 53, 37, 55, 10, 46, 50, 39, 29,\
    \ 42, 20, 57,\n                                             63, 6,  12, 26, 32,\
    \ 35, 48, 18, 24, 16, 52, 54, 45, 38, 41, 56,\n                              \
    \               62, 11, 31, 47, 23, 51, 44, 40, 61, 30, 22, 43, 60, 21, 59, 58};\n\
    \    return table[(x & (~x + 1)) * 0x218A7A392DD9ABF >> 58 & 0x3F];\n#endif\n\
    }\n"
  code: "#pragma once\n#include <array>\n#include \"../internal/enable_avx2.cpp\"\n\
    #include \"int_alias.cpp\"\n\nconstexpr int countr_zero(u64 x) {\n    if (x ==\
    \ 0) return 64;\n#ifdef __GNUC__\n    return __builtin_ctzll(x);\n#else\n    constexpr\
    \ std::array<int, 64> table = {0,  1,  2,  7,  3,  13, 8,  27, 4,  33, 14, 36,\
    \ 9,  49, 28, 19,\n                                             5,  25, 34, 17,\
    \ 15, 53, 37, 55, 10, 46, 50, 39, 29, 42, 20, 57,\n                          \
    \                   63, 6,  12, 26, 32, 35, 48, 18, 24, 16, 52, 54, 45, 38, 41,\
    \ 56,\n                                             62, 11, 31, 47, 23, 51, 44,\
    \ 40, 61, 30, 22, 43, 60, 21, 59, 58};\n    return table[(x & (~x + 1)) * 0x218A7A392DD9ABF\
    \ >> 58 & 0x3F];\n#endif\n}"
  dependsOn:
  - internal/enable_avx2.cpp
  - utility/int_alias.cpp
  isVerificationFile: false
  path: utility/countr_zero.cpp
  requiredBy:
  - algorithm/convolution_int.cpp
  - algorithm/convolution_arbitrary_mod.cpp
  - algorithm/convolution_mod.cpp
  - container/lazy_segment_tree.cpp
  - container/segment_tree_beats.cpp
  - container/dual_segment_tree.cpp
  - internal/modulo_transform.cpp
  timestamp: '2022-01-07 21:48:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dual_segment_tree.test.cpp
  - test/segment_tree_beats.test.cpp
  - test/convolution_arbitrary_mod.test.cpp
  - test/convolution_mod.test.cpp
  - test/lazy_segment_tree.test.cpp
documentation_of: utility/countr_zero.cpp
layout: document
redirect_from:
- /library/utility/countr_zero.cpp
- /library/utility/countr_zero.cpp.html
title: utility/countr_zero.cpp
---
