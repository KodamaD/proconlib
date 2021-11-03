---
data:
  _extendedDependsOn: []
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
    path: container/polynomial_hash.cpp
    title: container/polynomial_hash.cpp
  - icon: ':heavy_check_mark:'
    path: math/barret_reduction.cpp
    title: math/barret_reduction.cpp
  - icon: ':warning:'
    path: math/dynamic_modint.cpp
    title: math/dynamic_modint.cpp
  - icon: ':heavy_check_mark:'
    path: math/mod_pow.cpp
    title: math/mod_pow.cpp
  - icon: ':heavy_check_mark:'
    path: math/modulo_transform.cpp
    title: math/modulo_transform.cpp
  - icon: ':heavy_check_mark:'
    path: math/primitive_root.cpp
    title: math/primitive_root.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution_arbitrary_mod.test.cpp
    title: test/convolution_arbitrary_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution_mod.test.cpp
    title: test/convolution_mod.test.cpp
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
  - math/mod_pow.cpp
  - math/dynamic_modint.cpp
  - math/modulo_transform.cpp
  - math/barret_reduction.cpp
  - math/primitive_root.cpp
  - algorithm/convolution_int.cpp
  - algorithm/convolution_mod.cpp
  - algorithm/convolution_arbitrary_mod.cpp
  - container/polynomial_hash.cpp
  timestamp: '2021-09-08 18:46:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution_mod.test.cpp
  - test/convolution_arbitrary_mod.test.cpp
  - test/polynomial_hash.test.cpp
documentation_of: utility/int_alias_extended.cpp
layout: document
redirect_from:
- /library/utility/int_alias_extended.cpp
- /library/utility/int_alias_extended.cpp.html
title: utility/int_alias_extended.cpp
---
