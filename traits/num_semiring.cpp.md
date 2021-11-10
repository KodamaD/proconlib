---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/semiring_matrix.test.cpp
    title: test/semiring_matrix.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"traits/num_semiring.cpp\"\n\ntemplate <class T> struct NumSemiRing\
    \ {\n    using Type = T;\n    static constexpr T zero() { return T(0); }\n   \
    \ static constexpr T one() { return T(1); }\n    static constexpr T sum(const\
    \ T& x, const T& y) { return x + y; }\n    static constexpr T product(const T&\
    \ x, const T& y) { return x * y; }\n};\n"
  code: "#pragma once\n\ntemplate <class T> struct NumSemiRing {\n    using Type =\
    \ T;\n    static constexpr T zero() { return T(0); }\n    static constexpr T one()\
    \ { return T(1); }\n    static constexpr T sum(const T& x, const T& y) { return\
    \ x + y; }\n    static constexpr T product(const T& x, const T& y) { return x\
    \ * y; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: traits/num_semiring.cpp
  requiredBy: []
  timestamp: '2021-09-27 22:23:01+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/semiring_matrix.test.cpp
documentation_of: traits/num_semiring.cpp
layout: document
redirect_from:
- /library/traits/num_semiring.cpp
- /library/traits/num_semiring.cpp.html
title: traits/num_semiring.cpp
---
