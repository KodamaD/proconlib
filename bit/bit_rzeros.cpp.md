---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: container/dual_segment_tree.cpp
    title: container/dual_segment_tree.cpp
  - icon: ':heavy_check_mark:'
    path: container/lazy_segment_tree.cpp
    title: container/lazy_segment_tree.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dual_segment_tree.test.cpp
    title: test/dual_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazy_segment_tree.test.cpp
    title: test/lazy_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n#include <cstddef>\n\
    \nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    using isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 3 \"bit/bit_rzeros.cpp\"\
    \n\nconstexpr u64 bit_rzeros(const u64 x) {\n    return x == 0 ? 64 : __builtin_ctzll(x);\n\
    }\n"
  code: "#pragma once\n#include \"../utility/int_alias.cpp\"\n\nconstexpr u64 bit_rzeros(const\
    \ u64 x) {\n    return x == 0 ? 64 : __builtin_ctzll(x);\n}\n"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: bit/bit_rzeros.cpp
  requiredBy:
  - container/lazy_segment_tree.cpp
  - container/dual_segment_tree.cpp
  timestamp: '2021-03-26 16:52:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dual_segment_tree.test.cpp
  - test/lazy_segment_tree.test.cpp
documentation_of: bit/bit_rzeros.cpp
layout: document
redirect_from:
- /library/bit/bit_rzeros.cpp
- /library/bit/bit_rzeros.cpp.html
title: bit/bit_rzeros.cpp
---
