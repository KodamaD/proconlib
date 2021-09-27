---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/lazy_segment_tree.test.cpp
    title: test/lazy_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/queue_aggregation.test.cpp
    title: test/queue_aggregation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment_tree.test.cpp
    title: test/segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  requiredBy: []
  timestamp: '2021-09-27 22:23:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/queue_aggregation.test.cpp
  - test/lazy_segment_tree.test.cpp
  - test/segment_tree.test.cpp
documentation_of: traits/affine_composite_monoid.cpp
layout: document
redirect_from:
- /library/traits/affine_composite_monoid.cpp
- /library/traits/affine_composite_monoid.cpp.html
title: traits/affine_composite_monoid.cpp
---
