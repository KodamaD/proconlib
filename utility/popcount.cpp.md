---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: internal/enable_avx2.cpp
    title: internal/enable_avx2.cpp
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"internal/enable_avx2.cpp\"\n\n#ifdef ENABLE_AVX2\n#define\
    \ TARGET_AVX2 __attribute__((target(\"avx2\")))\n#else\n#define TARGET_AVX2\n\
    #endif\n#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n\nusing i32 = std::int32_t;\n\
    using u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n#line 4 \"utility/popcount.cpp\"\
    \n\nTARGET_AVX2 constexpr int popcount(u64 x) {\n#ifdef __GNUC__\n    return __builtin_popcountll(x);\n\
    #else\n    x -= x >> 1 & 0x5555555555555555;\n    x = (x & 0x3333333333333333)\
    \ + (x >> 2 & 0x3333333333333333);\n    x = (x + (x >> 4)) & 0x0F0F0F0F0F0F0F0F;\n\
    \    return x * 0x0101010101010101 >> 56 & 0x7f;\n#endif\n}\n"
  code: "#pragma once\n#include \"../internal/enable_avx2.cpp\"\n#include \"int_alias.cpp\"\
    \n\nTARGET_AVX2 constexpr int popcount(u64 x) {\n#ifdef __GNUC__\n    return __builtin_popcountll(x);\n\
    #else\n    x -= x >> 1 & 0x5555555555555555;\n    x = (x & 0x3333333333333333)\
    \ + (x >> 2 & 0x3333333333333333);\n    x = (x + (x >> 4)) & 0x0F0F0F0F0F0F0F0F;\n\
    \    return x * 0x0101010101010101 >> 56 & 0x7f;\n#endif\n}"
  dependsOn:
  - internal/enable_avx2.cpp
  - utility/int_alias.cpp
  isVerificationFile: false
  path: utility/popcount.cpp
  requiredBy: []
  timestamp: '2022-01-07 21:48:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/popcount.cpp
layout: document
redirect_from:
- /library/utility/popcount.cpp
- /library/utility/popcount.cpp.html
title: utility/popcount.cpp
---
