---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: traits/max_add_action.cpp
    title: traits/max_add_action.cpp
  - icon: ':warning:'
    path: traits/min_add_action.cpp
    title: traits/min_add_action.cpp
  - icon: ':heavy_check_mark:'
    path: traits/num_ring.cpp
    title: traits/num_ring.cpp
  - icon: ':heavy_check_mark:'
    path: traits/sum_affine_action.cpp
    title: traits/sum_affine_action.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/and_convolution.test.cpp
    title: test/and_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fenwick_tree.test.cpp
    title: test/fenwick_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazy_segment_tree.test.cpp
    title: test/lazy_segment_tree.test.cpp
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
  bundledCode: "#line 2 \"traits/sum_group.cpp\"\n\ntemplate <class T> struct SumGroup\
    \ {\n    using Type = T;\n    static constexpr T identity() { return T(0); }\n\
    \    static constexpr T operation(const T& l, const T& r) { return l + r; }\n\
    \    static constexpr T inverse(const T& x) { return -x; }\n};\n"
  code: "#pragma once\n\ntemplate <class T> struct SumGroup {\n    using Type = T;\n\
    \    static constexpr T identity() { return T(0); }\n    static constexpr T operation(const\
    \ T& l, const T& r) { return l + r; }\n    static constexpr T inverse(const T&\
    \ x) { return -x; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: traits/sum_group.cpp
  requiredBy:
  - traits/min_add_action.cpp
  - traits/max_add_action.cpp
  - traits/sum_affine_action.cpp
  - traits/num_ring.cpp
  timestamp: '2021-12-28 21:38:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/semiring_matrix.test.cpp
  - test/subset_convolution.test.cpp
  - test/fenwick_tree.test.cpp
  - test/and_convolution.test.cpp
  - test/lazy_segment_tree.test.cpp
documentation_of: traits/sum_group.cpp
layout: document
redirect_from:
- /library/traits/sum_group.cpp
- /library/traits/sum_group.cpp.html
title: traits/sum_group.cpp
---
