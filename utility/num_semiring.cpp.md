---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/semiring_matrix.test.cpp
    title: test/semiring_matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/num_semiring.cpp\"\n\ntemplate <class T> struct\
    \ NumSemiRing {\n    T val;\n    constexpr NumSemiRing() = default;\n    constexpr\
    \ NumSemiRing(const T& val) : val(val) {}\n    static constexpr NumSemiRing zero()\
    \ { return T(0); }\n    static constexpr NumSemiRing one() { return T(1); }\n\
    \    constexpr NumSemiRing operator+(const NumSemiRing& other) const { return\
    \ val + other.val; }\n    constexpr NumSemiRing operator*(const NumSemiRing& other)\
    \ const { return val * other.val; }\n};\n"
  code: "#pragma once\n\ntemplate <class T> struct NumSemiRing {\n    T val;\n   \
    \ constexpr NumSemiRing() = default;\n    constexpr NumSemiRing(const T& val)\
    \ : val(val) {}\n    static constexpr NumSemiRing zero() { return T(0); }\n  \
    \  static constexpr NumSemiRing one() { return T(1); }\n    constexpr NumSemiRing\
    \ operator+(const NumSemiRing& other) const { return val + other.val; }\n    constexpr\
    \ NumSemiRing operator*(const NumSemiRing& other) const { return val * other.val;\
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: utility/num_semiring.cpp
  requiredBy: []
  timestamp: '2021-09-04 17:30:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/semiring_matrix.test.cpp
documentation_of: utility/num_semiring.cpp
layout: document
redirect_from:
- /library/utility/num_semiring.cpp
- /library/utility/num_semiring.cpp.html
title: utility/num_semiring.cpp
---
