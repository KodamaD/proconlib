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
    \ : value + mod;\n}\n#line 3 \"math/mod_pow.cpp\"\n#include <cassert>\n\ntemplate\
    \ <class T>\nconstexpr T mod_pow(T x, u64 exp, const T& mod) {\n    assert(mod\
    \ > 0);\n    T ret = T(1) % mod;\n    x = rem_euclid(x, mod);\n    for (; exp\
    \ > 0; exp >>= 1) {\n        if (exp & 1) ret = ret * x % mod;\n        x = x\
    \ * x % mod;\n    }\n    return ret;\n}\n"
  code: "#pragma once\n#include \"../math/rem_euclid.cpp\"\n#include <cassert>\n\n\
    template <class T>\nconstexpr T mod_pow(T x, u64 exp, const T& mod) {\n    assert(mod\
    \ > 0);\n    T ret = T(1) % mod;\n    x = rem_euclid(x, mod);\n    for (; exp\
    \ > 0; exp >>= 1) {\n        if (exp & 1) ret = ret * x % mod;\n        x = x\
    \ * x % mod;\n    }\n    return ret;\n}\n"
  dependsOn:
  - math/rem_euclid.cpp
  isVerificationFile: false
  path: math/mod_pow.cpp
  requiredBy: []
  timestamp: '2021-05-02 18:39:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/mod_pow.cpp
layout: document
redirect_from:
- /library/math/mod_pow.cpp
- /library/math/mod_pow.cpp.html
title: math/mod_pow.cpp
---
