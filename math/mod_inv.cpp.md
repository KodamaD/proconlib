---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/inv_gcd.cpp
    title: math/inv_gcd.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/dynamic_modint.cpp
    title: math/dynamic_modint.cpp
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
    \ { (T) s, (T) m0 };\n}\n#line 3 \"math/mod_inv.cpp\"\n#include <cassert>\n\n\
    template <class T>\nconstexpr T mod_inv(const T& a, const T& mod) {\n    const\
    \ auto [g, x] = inv_gcd(a, mod);\n    assert(g == 1);\n    return x;\n}\n"
  code: "#pragma once\n#include \"inv_gcd.cpp\"\n#include <cassert>\n\ntemplate <class\
    \ T>\nconstexpr T mod_inv(const T& a, const T& mod) {\n    const auto [g, x] =\
    \ inv_gcd(a, mod);\n    assert(g == 1);\n    return x;\n}\n"
  dependsOn:
  - math/inv_gcd.cpp
  isVerificationFile: false
  path: math/mod_inv.cpp
  requiredBy:
  - math/dynamic_modint.cpp
  timestamp: '2021-03-25 16:47:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/mod_inv.cpp
layout: document
redirect_from:
- /library/math/mod_inv.cpp
- /library/math/mod_inv.cpp.html
title: math/mod_inv.cpp
---
