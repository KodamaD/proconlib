---
data:
  _extendedDependsOn:
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
  bundledCode: '#line 2 "utility/int_alias.cpp"

    #include <cstdint>


    using i32 = std::int32_t;

    using u32 = std::uint32_t;

    using i64 = std::int64_t;

    using u64 = std::uint64_t;

    using i128 = __int128_t;

    using u128 = __uint128_t;

    #line 3 "utility/bit_parity.cpp"


    __attribute__((target("avx2"))) constexpr int bit_parity(const u64 x) { return
    __builtin_parityll(x); }

    '
  code: '#pragma once

    #include "int_alias.cpp"


    __attribute__((target("avx2"))) constexpr int bit_parity(const u64 x) { return
    __builtin_parityll(x); }

    '
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: utility/bit_parity.cpp
  requiredBy: []
  timestamp: '2021-12-17 09:20:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/bit_parity.cpp
layout: document
redirect_from:
- /library/utility/bit_parity.cpp
- /library/utility/bit_parity.cpp.html
title: utility/bit_parity.cpp
---
