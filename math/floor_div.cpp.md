---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/floor_div.cpp\"\n#include <cassert>\n\ntemplate <class\
    \ T> constexpr T floor_div(const T& x, const T& y) {\n    assert(y != 0);\n  \
    \  return x / y - (((x ^ y) < 0) && (x % y));\n}\n"
  code: "#pragma once\n#include <cassert>\n\ntemplate <class T> constexpr T floor_div(const\
    \ T& x, const T& y) {\n    assert(y != 0);\n    return x / y - (((x ^ y) < 0)\
    \ && (x % y));\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/floor_div.cpp
  requiredBy: []
  timestamp: '2021-09-04 18:33:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/floor_div.cpp
layout: document
redirect_from:
- /library/math/floor_div.cpp
- /library/math/floor_div.cpp.html
title: math/floor_div.cpp
---
