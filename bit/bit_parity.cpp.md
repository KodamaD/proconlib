---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
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

    #line 3 "bit/bit_parity.cpp"


    __attribute__((target("avx2"))) constexpr u64 bit_parity(const u64 x) { return
    __builtin_parityll(x); }

    '
  code: '#pragma once

    #include "../utility/int_alias.cpp"


    __attribute__((target("avx2"))) constexpr u64 bit_parity(const u64 x) { return
    __builtin_parityll(x); }

    '
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: bit/bit_parity.cpp
  requiredBy: []
  timestamp: '2021-09-27 22:23:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: bit/bit_parity.cpp
layout: document
redirect_from:
- /library/bit/bit_parity.cpp
- /library/bit/bit_parity.cpp.html
title: bit/bit_parity.cpp
---
