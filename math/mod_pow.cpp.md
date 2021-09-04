---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/rem_euclid.cpp
    title: math/rem_euclid.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/primitive_root.cpp
    title: math/primitive_root.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/mod_pow.cpp\"\n#include <cassert>\n#line 2 \"math/rem_euclid.cpp\"\
    \n\ntemplate <class T> constexpr T rem_euclid(T value, const T& mod) { return\
    \ (value %= mod) >= 0 ? value : value + mod; }\n#line 4 \"math/mod_pow.cpp\"\n\
    \ntemplate <class T> constexpr T mod_pow(T x, u64 exp, const T& mod) {\n    assert(mod\
    \ > 0);\n    T ret = T(1) % mod;\n    x = rem_euclid(x, mod);\n    for (; exp\
    \ > 0; exp >>= 1) {\n        if (exp & 1) ret = ret * x % mod;\n        x = x\
    \ * x % mod;\n    }\n    return ret;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include \"../math/rem_euclid.cpp\"\n\n\
    template <class T> constexpr T mod_pow(T x, u64 exp, const T& mod) {\n    assert(mod\
    \ > 0);\n    T ret = T(1) % mod;\n    x = rem_euclid(x, mod);\n    for (; exp\
    \ > 0; exp >>= 1) {\n        if (exp & 1) ret = ret * x % mod;\n        x = x\
    \ * x % mod;\n    }\n    return ret;\n}\n"
  dependsOn:
  - math/rem_euclid.cpp
  isVerificationFile: false
  path: math/mod_pow.cpp
  requiredBy:
  - math/primitive_root.cpp
  timestamp: '2021-09-04 17:30:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/mod_pow.cpp
layout: document
redirect_from:
- /library/math/mod_pow.cpp
- /library/math/mod_pow.cpp.html
title: math/mod_pow.cpp
---
