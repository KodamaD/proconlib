---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/inv_gcd.cpp
    title: math/inv_gcd.cpp
  - icon: ':heavy_check_mark:'
    path: math/rem_euclid.cpp
    title: math/rem_euclid.cpp
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
  bundledCode: "#line 2 \"math/mod_inv.cpp\"\n#include <cassert>\n#line 2 \"math/inv_gcd.cpp\"\
    \n#include <type_traits>\n#include <utility>\n#line 2 \"math/rem_euclid.cpp\"\n\
    \ntemplate <class T> constexpr T rem_euclid(T value, const T& mod) { return (value\
    \ %= mod) >= 0 ? value : value + mod; }\n#line 5 \"math/inv_gcd.cpp\"\n\ntemplate\
    \ <class T> constexpr std::pair<T, T> inv_gcd(const T& a, const T& b) {\n    using\
    \ U = std::make_signed_t<T>;\n    U t = rem_euclid(a, b);\n    if (t == 0) return\
    \ {b, 0};\n    U s = b, m0 = 0, m1 = 1;\n    while (t != 0) {\n        const U\
    \ u = s / t;\n        s -= t * u;\n        m0 -= m1 * u;\n        U tmp = s;\n\
    \        s = t;\n        t = tmp;\n        tmp = m0;\n        m0 = m1;\n     \
    \   m1 = tmp;\n    }\n    if (m0 < 0) m0 += b / s;\n    return {(T)s, (T)m0};\n\
    }\n#line 4 \"math/mod_inv.cpp\"\n\ntemplate <class T> constexpr T mod_inv(const\
    \ T& a, const T& mod) {\n    const auto [g, x] = inv_gcd(a, mod);\n    assert(g\
    \ == 1);\n    return x;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include \"inv_gcd.cpp\"\n\ntemplate <class\
    \ T> constexpr T mod_inv(const T& a, const T& mod) {\n    const auto [g, x] =\
    \ inv_gcd(a, mod);\n    assert(g == 1);\n    return x;\n}\n"
  dependsOn:
  - math/inv_gcd.cpp
  - math/rem_euclid.cpp
  isVerificationFile: false
  path: math/mod_inv.cpp
  requiredBy:
  - math/dynamic_modint.cpp
  timestamp: '2021-09-04 17:30:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/mod_inv.cpp
layout: document
redirect_from:
- /library/math/mod_inv.cpp
- /library/math/mod_inv.cpp.html
title: math/mod_inv.cpp
---
