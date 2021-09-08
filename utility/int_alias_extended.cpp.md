---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: container/integer_hash_map.cpp
    title: container/integer_hash_map.cpp
  - icon: ':heavy_check_mark:'
    path: container/polynomial_hash.cpp
    title: container/polynomial_hash.cpp
  - icon: ':warning:'
    path: math/dynamic_modint.cpp
    title: math/dynamic_modint.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/integer_hash_map.test.cpp
    title: test/integer_hash_map.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial_hash.test.cpp
    title: test/polynomial_hash.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 2 "utility/int_alias_extended.cpp"

    #include <cstddef>

    #include <cstdint>


    using i8 = std::int8_t;

    using u8 = std::uint8_t;

    using i16 = std::int16_t;

    using u16 = std::uint16_t;

    using i128 = __int128_t;

    using u128 = __uint128_t;

    '
  code: '#pragma once

    #include <cstddef>

    #include <cstdint>


    using i8 = std::int8_t;

    using u8 = std::uint8_t;

    using i16 = std::int16_t;

    using u16 = std::uint16_t;

    using i128 = __int128_t;

    using u128 = __uint128_t;

    '
  dependsOn: []
  isVerificationFile: false
  path: utility/int_alias_extended.cpp
  requiredBy:
  - container/integer_hash_map.cpp
  - container/polynomial_hash.cpp
  - math/dynamic_modint.cpp
  timestamp: '2021-09-08 18:46:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/integer_hash_map.test.cpp
  - test/polynomial_hash.test.cpp
documentation_of: utility/int_alias_extended.cpp
layout: document
redirect_from:
- /library/utility/int_alias_extended.cpp
- /library/utility/int_alias_extended.cpp.html
title: utility/int_alias_extended.cpp
---
