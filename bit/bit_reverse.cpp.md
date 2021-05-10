---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/convolution.cpp
    title: math/convolution.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution.test.cpp
    title: test/convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n#include <cstddef>\n\
    \nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    using isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 3 \"bit/bit_reverse.cpp\"\
    \n\nconstexpr u64 bit_reverse(u64 x) {\n    x = ((x >> 1) & 0x5555555555555555)\
    \ | ((x & 0x5555555555555555) << 1);\n    x = ((x >> 2) & 0x3333333333333333)\
    \ | ((x & 0x3333333333333333) << 2);\n    x = ((x >> 4) & 0x0F0F0F0F0F0F0F0F)\
    \ | ((x & 0x0F0F0F0F0F0F0F0F) << 4);\n    x = ((x >> 8) & 0x00FF00FF00FF00FF)\
    \ | ((x & 0x00FF00FF00FF00FF) << 8);\n    x = ((x >> 16) & 0x0000FFFF0000FFFF)\
    \ | ((x & 0x0000FFFF0000FFFF) << 16);\n    x = (x >> 32) | (x << 32);\n    return\
    \ x;\n}\n"
  code: "#pragma once\n#include \"../utility/int_alias.cpp\"\n\nconstexpr u64 bit_reverse(u64\
    \ x) {\n    x = ((x >> 1) & 0x5555555555555555) | ((x & 0x5555555555555555) <<\
    \ 1);\n    x = ((x >> 2) & 0x3333333333333333) | ((x & 0x3333333333333333) <<\
    \ 2);\n    x = ((x >> 4) & 0x0F0F0F0F0F0F0F0F) | ((x & 0x0F0F0F0F0F0F0F0F) <<\
    \ 4);\n    x = ((x >> 8) & 0x00FF00FF00FF00FF) | ((x & 0x00FF00FF00FF00FF) <<\
    \ 8);\n    x = ((x >> 16) & 0x0000FFFF0000FFFF) | ((x & 0x0000FFFF0000FFFF) <<\
    \ 16);\n    x = (x >> 32) | (x << 32);\n    return x;\n}"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: bit/bit_reverse.cpp
  requiredBy:
  - math/convolution.cpp
  timestamp: '2021-05-10 19:01:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution.test.cpp
documentation_of: bit/bit_reverse.cpp
layout: document
redirect_from:
- /library/bit/bit_reverse.cpp
- /library/bit/bit_reverse.cpp.html
title: bit/bit_reverse.cpp
---
