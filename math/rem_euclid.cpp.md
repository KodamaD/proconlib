---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/dynamic_modint.cpp
    title: math/dynamic_modint.cpp
  - icon: ':warning:'
    path: math/inv_gcd.cpp
    title: math/inv_gcd.cpp
  - icon: ':warning:'
    path: math/mod_inv.cpp
    title: math/mod_inv.cpp
  - icon: ':warning:'
    path: math/mod_pow.cpp
    title: math/mod_pow.cpp
  - icon: ':warning:'
    path: math/primitive_root.cpp
    title: math/primitive_root.cpp
  - icon: ':heavy_check_mark:'
    path: math/static_modint.cpp
    title: math/static_modint.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/heavy_light_decomposition.test.cpp
    title: test/heavy_light_decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazy_segment_tree.test.cpp
    title: test/lazy_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/modint_util.test.cpp
    title: test/modint_util.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/queue_aggregation.test.cpp
    title: test/queue_aggregation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment_tree.test.cpp
    title: test/segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/semiring_matrix.test.cpp
    title: test/semiring_matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 2 "math/rem_euclid.cpp"


    template <class T> constexpr T rem_euclid(T value, const T& mod) { return (value
    %= mod) >= 0 ? value : value + mod; }

    '
  code: '#pragma once


    template <class T> constexpr T rem_euclid(T value, const T& mod) { return (value
    %= mod) >= 0 ? value : value + mod; }

    '
  dependsOn: []
  isVerificationFile: false
  path: math/rem_euclid.cpp
  requiredBy:
  - math/dynamic_modint.cpp
  - math/static_modint.cpp
  - math/primitive_root.cpp
  - math/inv_gcd.cpp
  - math/mod_pow.cpp
  - math/mod_inv.cpp
  timestamp: '2021-09-04 17:30:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/segment_tree.test.cpp
  - test/semiring_matrix.test.cpp
  - test/queue_aggregation.test.cpp
  - test/modint_util.test.cpp
  - test/heavy_light_decomposition.test.cpp
  - test/lazy_segment_tree.test.cpp
documentation_of: math/rem_euclid.cpp
layout: document
redirect_from:
- /library/math/rem_euclid.cpp
- /library/math/rem_euclid.cpp.html
title: math/rem_euclid.cpp
---
