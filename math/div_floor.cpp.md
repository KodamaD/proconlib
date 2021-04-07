---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/rem_euclid.cpp
    title: math/rem_euclid.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/rem_euclid.cpp\"\n\ntemplate <class T>\nconstexpr T\
    \ rem_euclid(T value, const T& mod) {\n    return (value %= mod) >= 0 ? value\
    \ : value + mod;\n}\n#line 3 \"math/div_floor.cpp\"\n\ntemplate <class T>\nconstexpr\
    \ T div_floor(const T& x, const T& y) {\n    return (x - rem_euclid(x, y)) / y;\n\
    }\n"
  code: "#pragma once\n#include \"rem_euclid.cpp\"\n\ntemplate <class T>\nconstexpr\
    \ T div_floor(const T& x, const T& y) {\n    return (x - rem_euclid(x, y)) / y;\n\
    }\n"
  dependsOn:
  - math/rem_euclid.cpp
  isVerificationFile: false
  path: math/div_floor.cpp
  requiredBy: []
  timestamp: '2021-03-28 15:26:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/div_floor.cpp
layout: document
redirect_from:
- /library/math/div_floor.cpp
- /library/math/div_floor.cpp.html
title: math/div_floor.cpp
---
