---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: traits/sum_affine_action.cpp
    title: traits/sum_affine_action.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/heavy_light_decomposition.test.cpp
    title: test/heavy_light_decomposition.test.cpp
  - icon: ':x:'
    path: test/lazy_segment_tree.test.cpp
    title: test/lazy_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/queue_aggregation.test.cpp
    title: test/queue_aggregation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment_tree.test.cpp
    title: test/segment_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"traits/affine_composite_monoid.cpp\"\n\ntemplate <class\
    \ T> struct Affine {\n    T a, b;\n    constexpr Affine(const T& a = 1, const\
    \ T& b = 0) : a(a), b(b) {}\n    constexpr T eval(const T& x) const { return a\
    \ * x + b; }\n    constexpr Affine operator+(const Affine& other) const { return\
    \ affine(a + other.a, b + other.b); }\n    constexpr Affine composite(const Affine&\
    \ other) const { return Affine(a * other.a, b * other.a + other.b); }\n};\n\n\
    template <class T> struct AffineCompositeMonoid {\n    using Type = Affine<T>;\n\
    \    static constexpr Type identity() { return Type(); }\n    static constexpr\
    \ Type operation(const Type& l, const Type& r) noexcept { return l.composite(r);\
    \ }\n};\n"
  code: "#pragma once\n\ntemplate <class T> struct Affine {\n    T a, b;\n    constexpr\
    \ Affine(const T& a = 1, const T& b = 0) : a(a), b(b) {}\n    constexpr T eval(const\
    \ T& x) const { return a * x + b; }\n    constexpr Affine operator+(const Affine&\
    \ other) const { return affine(a + other.a, b + other.b); }\n    constexpr Affine\
    \ composite(const Affine& other) const { return Affine(a * other.a, b * other.a\
    \ + other.b); }\n};\n\ntemplate <class T> struct AffineCompositeMonoid {\n   \
    \ using Type = Affine<T>;\n    static constexpr Type identity() { return Type();\
    \ }\n    static constexpr Type operation(const Type& l, const Type& r) noexcept\
    \ { return l.composite(r); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: traits/affine_composite_monoid.cpp
  requiredBy:
  - traits/sum_affine_action.cpp
  timestamp: '2021-09-27 22:23:01+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/queue_aggregation.test.cpp
  - test/lazy_segment_tree.test.cpp
  - test/heavy_light_decomposition.test.cpp
  - test/segment_tree.test.cpp
documentation_of: traits/affine_composite_monoid.cpp
layout: document
redirect_from:
- /library/traits/affine_composite_monoid.cpp
- /library/traits/affine_composite_monoid.cpp.html
title: traits/affine_composite_monoid.cpp
---
