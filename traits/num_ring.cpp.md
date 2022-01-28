---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: traits/product_monoid.cpp
    title: traits/product_monoid.cpp
  - icon: ':heavy_check_mark:'
    path: traits/sum_group.cpp
    title: traits/sum_group.cpp
  _extendedRequiredBy: []
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
  bundledCode: "#line 2 \"traits/sum_group.cpp\"\n\ntemplate <class T> struct SumGroup\
    \ {\n    using Type = T;\n    static constexpr T identity() { return T(0); }\n\
    \    static constexpr T operation(const T& l, const T& r) { return l + r; }\n\
    \    static constexpr T inverse(const T& x) { return -x; }\n};\n#line 2 \"traits/product_monoid.cpp\"\
    \n\ntemplate <class T> struct ProductMonoid {\n    using Type = T;\n    static\
    \ constexpr T identity() { return T(1); }\n    static constexpr T operation(const\
    \ T& l, const T& r) { return l * r; }\n};\n#line 4 \"traits/num_ring.cpp\"\n\n\
    template <class T> struct NumRing {\n    using Type = T;\n    using Sum = SumGroup<T>;\n\
    \    using Product = ProductMonoid<T>;\n};\n"
  code: "#pragma once\n#include \"sum_group.cpp\"\n#include \"product_monoid.cpp\"\
    \n\ntemplate <class T> struct NumRing {\n    using Type = T;\n    using Sum =\
    \ SumGroup<T>;\n    using Product = ProductMonoid<T>;\n};"
  dependsOn:
  - traits/sum_group.cpp
  - traits/product_monoid.cpp
  isVerificationFile: false
  path: traits/num_ring.cpp
  requiredBy: []
  timestamp: '2022-01-28 13:07:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/and_convolution.test.cpp
  - test/subset_convolution.test.cpp
  - test/semiring_matrix.test.cpp
documentation_of: traits/num_ring.cpp
layout: document
redirect_from:
- /library/traits/num_ring.cpp
- /library/traits/num_ring.cpp.html
title: traits/num_ring.cpp
---
