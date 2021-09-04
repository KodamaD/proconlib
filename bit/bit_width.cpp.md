---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: bit/bit_lzeros.cpp
    title: bit/bit_lzeros.cpp
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

    #include <cstddef>

    #include <cstdint>


    using i32 = std::int32_t;

    using u32 = std::uint32_t;

    using i64 = std::int64_t;

    using u64 = std::uint64_t;

    using i128 = __int128_t;

    using u128 = __uint128_t;

    using isize = std::ptrdiff_t;

    using usize = std::size_t;

    #line 3 "bit/bit_lzeros.cpp"


    constexpr u64 bit_lzeros(const u64 x) { return x == 0 ? 64 : __builtin_clzll(x);
    }

    #line 4 "bit/bit_width.cpp"


    constexpr u64 bit_width(const u64 x) { return 64 - bit_lzeros(x); }

    '
  code: '#pragma once

    #include "../utility/int_alias.cpp"

    #include "bit_lzeros.cpp"


    constexpr u64 bit_width(const u64 x) { return 64 - bit_lzeros(x); }

    '
  dependsOn:
  - utility/int_alias.cpp
  - bit/bit_lzeros.cpp
  isVerificationFile: false
  path: bit/bit_width.cpp
  requiredBy:
  - container/sparse_table.cpp
  timestamp: '2021-09-04 17:30:23+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/sparse_table.test.cpp
documentation_of: bit/bit_width.cpp
layout: document
redirect_from:
- /library/bit/bit_width.cpp
- /library/bit/bit_width.cpp.html
title: bit/bit_width.cpp
---
