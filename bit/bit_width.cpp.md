---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bit/bit_lzeros.cpp
    title: bit/bit_lzeros.cpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: container/sparse_table.cpp
    title: container/sparse_table.cpp
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

    #include <cstddef>

    #include <cstdint>


    using i32 = std::int32_t;

    using u32 = std::uint32_t;

    using i64 = std::int64_t;

    using u64 = std::uint64_t;

    using isize = std::ptrdiff_t;

    using usize = std::size_t;

    #line 3 "bit/bit_lzeros.cpp"


    __attribute__((target("avx2"))) constexpr u64 bit_lzeros(const u64 x) { return
    x == 0 ? 64 : __builtin_clzll(x); }

    #line 4 "bit/bit_width.cpp"


    __attribute__((target("avx2"))) constexpr u64 bit_width(const u64 x) { return
    64 - bit_lzeros(x); }

    '
  code: '#pragma once

    #include "../utility/int_alias.cpp"

    #include "bit_lzeros.cpp"


    __attribute__((target("avx2"))) constexpr u64 bit_width(const u64 x) { return
    64 - bit_lzeros(x); }

    '
  dependsOn:
  - utility/int_alias.cpp
  - bit/bit_lzeros.cpp
  isVerificationFile: false
  path: bit/bit_width.cpp
  requiredBy:
  - container/sparse_table.cpp
  timestamp: '2021-09-08 18:46:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/sparse_table.test.cpp
documentation_of: bit/bit_width.cpp
layout: document
redirect_from:
- /library/bit/bit_width.cpp
- /library/bit/bit_width.cpp.html
title: bit/bit_width.cpp
---