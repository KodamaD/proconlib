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
  bundledCode: "#line 2 \"math/ceil_div.cpp\"\n#include <cassert>\n\ntemplate <class\
    \ T> constexpr T ceil_div(const T& x, const T& y) {\n    assert(y != 0);\n   \
    \ return x / y + (((x ^ y) >= 0) && (x % y));\n}\n"
  code: "#pragma once\n#include <cassert>\n\ntemplate <class T> constexpr T ceil_div(const\
    \ T& x, const T& y) {\n    assert(y != 0);\n    return x / y + (((x ^ y) >= 0)\
    \ && (x % y));\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/ceil_div.cpp
  requiredBy: []
  timestamp: '2021-09-04 18:33:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/ceil_div.cpp
layout: document
redirect_from:
- /library/math/ceil_div.cpp
- /library/math/ceil_div.cpp.html
title: math/ceil_div.cpp
---
