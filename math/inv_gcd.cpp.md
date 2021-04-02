---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/dynamic_modint.cpp
    title: math/dynamic_modint.cpp
  - icon: ':warning:'
    path: math/mod_inv.cpp
    title: math/mod_inv.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/inv_gcd.cpp\"\n#include <utility>\n#include <type_traits>\n\
    \ntemplate <class T>\nconstexpr std::pair<T, T> inv_gcd(const T& a, const T& b)\
    \ {\n    using U = std::make_signed_t<T>;\n    U t = rem_euclid(a, b);\n    if\
    \ (t == 0) return { b, 0 };\n    U s = b, m0 = 0, m1 = 1;\n    while (t != 0)\
    \ {\n        const U u = s / t;\n        s -= t * u;\n        m0 -= m1 * u;\n\
    \        U tmp = s;\n        s = t;\n        t = tmp;\n        tmp = m0;\n   \
    \     m0 = m1;\n        m1 = tmp;\n    }\n    if (m0 < 0) m0 += b / s;\n    return\
    \ { (T) s, (T) m0 };\n}\n"
  code: "#pragma once\n#include <utility>\n#include <type_traits>\n\ntemplate <class\
    \ T>\nconstexpr std::pair<T, T> inv_gcd(const T& a, const T& b) {\n    using U\
    \ = std::make_signed_t<T>;\n    U t = rem_euclid(a, b);\n    if (t == 0) return\
    \ { b, 0 };\n    U s = b, m0 = 0, m1 = 1;\n    while (t != 0) {\n        const\
    \ U u = s / t;\n        s -= t * u;\n        m0 -= m1 * u;\n        U tmp = s;\n\
    \        s = t;\n        t = tmp;\n        tmp = m0;\n        m0 = m1;\n     \
    \   m1 = tmp;\n    }\n    if (m0 < 0) m0 += b / s;\n    return { (T) s, (T) m0\
    \ };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/inv_gcd.cpp
  requiredBy:
  - math/mod_inv.cpp
  - math/dynamic_modint.cpp
  timestamp: '2021-03-24 22:27:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/inv_gcd.cpp
layout: document
redirect_from:
- /library/math/inv_gcd.cpp
- /library/math/inv_gcd.cpp.html
title: math/inv_gcd.cpp
---
