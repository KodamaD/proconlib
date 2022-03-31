---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: traits/num_ring.cpp
    title: traits/num_ring.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/and_convolution.test.cpp
    title: test/and_convolution.test.cpp
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
  bundledCode: "#line 2 \"traits/product_monoid.cpp\"\n\ntemplate <class T> struct\
    \ ProductMonoid {\n    using Type = T;\n    static constexpr T identity() { return\
    \ T(1); }\n    static constexpr T operation(const T& l, const T& r) { return l\
    \ * r; }\n};\n"
  code: "#pragma once\n\ntemplate <class T> struct ProductMonoid {\n    using Type\
    \ = T;\n    static constexpr T identity() { return T(1); }\n    static constexpr\
    \ T operation(const T& l, const T& r) { return l * r; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: traits/product_monoid.cpp
  requiredBy:
  - traits/num_ring.cpp
  timestamp: '2021-12-28 21:38:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/subset_convolution.test.cpp
  - test/and_convolution.test.cpp
  - test/semiring_matrix.test.cpp
documentation_of: traits/product_monoid.cpp
layout: document
redirect_from:
- /library/traits/product_monoid.cpp
- /library/traits/product_monoid.cpp.html
title: traits/product_monoid.cpp
---
