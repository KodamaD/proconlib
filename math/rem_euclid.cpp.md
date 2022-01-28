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
    path: internal/modulo_transform.cpp
    title: internal/modulo_transform.cpp
  - icon: ':warning:'
    path: math/congruence_equations.cpp
    title: math/congruence_equations.cpp
  - icon: ':warning:'
    path: math/dynamic_modint.cpp
    title: math/dynamic_modint.cpp
  - icon: ':heavy_check_mark:'
    path: math/inv_gcd.cpp
    title: math/inv_gcd.cpp
  - icon: ':heavy_check_mark:'
    path: math/mod_inv.cpp
    title: math/mod_inv.cpp
  - icon: ':heavy_check_mark:'
    path: math/mod_pow.cpp
    title: math/mod_pow.cpp
  - icon: ':heavy_check_mark:'
    path: math/primitive_root.cpp
    title: math/primitive_root.cpp
  - icon: ':heavy_check_mark:'
    path: math/static_modint.cpp
    title: math/static_modint.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/and_convolution.test.cpp
    title: test/and_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/berlekamp_massey.test.cpp
    title: test/berlekamp_massey.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution_arbitrary_mod.test.cpp
    title: test/convolution_arbitrary_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution_mod.test.cpp
    title: test/convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fp_util.test.cpp
    title: test/fp_util.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/heavy_light_decomposition.test.cpp
    title: test/heavy_light_decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazy_segment_tree.test.cpp
    title: test/lazy_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/queue_aggregation.test.cpp
    title: test/queue_aggregation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment_tree.test.cpp
    title: test/segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/semiring_matrix.test.cpp
    title: test/semiring_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/subset_convolution.test.cpp
    title: test/subset_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/rem_euclid.cpp\"\n#include <cassert>\n\ntemplate <class\
    \ T> constexpr T rem_euclid(T value, const T& mod) {\n    assert(mod > 0);\n \
    \   return (value %= mod) >= 0 ? value : value + mod;\n}\n"
  code: "#pragma once\n#include <cassert>\n\ntemplate <class T> constexpr T rem_euclid(T\
    \ value, const T& mod) {\n    assert(mod > 0);\n    return (value %= mod) >= 0\
    \ ? value : value + mod;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/rem_euclid.cpp
  requiredBy:
  - algorithm/convolution_mod.cpp
  - algorithm/convolution_arbitrary_mod.cpp
  - algorithm/convolution_int.cpp
  - math/mod_inv.cpp
  - math/dynamic_modint.cpp
  - math/primitive_root.cpp
  - math/static_modint.cpp
  - math/mod_pow.cpp
  - math/inv_gcd.cpp
  - math/congruence_equations.cpp
  - internal/modulo_transform.cpp
  timestamp: '2021-11-01 18:27:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution_mod.test.cpp
  - test/fp_util.test.cpp
  - test/heavy_light_decomposition.test.cpp
  - test/segment_tree.test.cpp
  - test/and_convolution.test.cpp
  - test/convolution_arbitrary_mod.test.cpp
  - test/subset_convolution.test.cpp
  - test/semiring_matrix.test.cpp
  - test/queue_aggregation.test.cpp
  - test/lazy_segment_tree.test.cpp
  - test/berlekamp_massey.test.cpp
documentation_of: math/rem_euclid.cpp
layout: document
redirect_from:
- /library/math/rem_euclid.cpp
- /library/math/rem_euclid.cpp.html
title: math/rem_euclid.cpp
---
