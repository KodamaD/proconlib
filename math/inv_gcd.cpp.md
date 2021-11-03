---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/rem_euclid.cpp
    title: math/rem_euclid.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algorithm/convolution_arbitrary_mod.cpp
    title: algorithm/convolution_arbitrary_mod.cpp
  - icon: ':warning:'
    path: algorithm/convolution_int.cpp
    title: algorithm/convolution_int.cpp
  - icon: ':warning:'
    path: math/congruence_equations.cpp
    title: math/congruence_equations.cpp
  - icon: ':warning:'
    path: math/dynamic_modint.cpp
    title: math/dynamic_modint.cpp
  - icon: ':heavy_check_mark:'
    path: math/mod_inv.cpp
    title: math/mod_inv.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution_arbitrary_mod.test.cpp
    title: test/convolution_arbitrary_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/inv_gcd.cpp\"\n#include <type_traits>\n#include <utility>\n\
    #line 2 \"math/rem_euclid.cpp\"\n#include <cassert>\n\ntemplate <class T> constexpr\
    \ T rem_euclid(T value, const T& mod) {\n    assert(mod > 0);\n    return (value\
    \ %= mod) >= 0 ? value : value + mod;\n}\n#line 5 \"math/inv_gcd.cpp\"\n\ntemplate\
    \ <class T> constexpr std::pair<T, T> inv_gcd(const T& a, const T& b) {\n    using\
    \ U = std::make_signed_t<T>;\n    U t = rem_euclid(a, b);\n    if (t == 0) return\
    \ {b, 0};\n    U s = b, m0 = 0, m1 = 1;\n    while (t != 0) {\n        const U\
    \ u = s / t;\n        s -= t * u;\n        m0 -= m1 * u;\n        U tmp = s;\n\
    \        s = t;\n        t = tmp;\n        tmp = m0;\n        m0 = m1;\n     \
    \   m1 = tmp;\n    }\n    if (m0 < 0) m0 += b / s;\n    return {(T)s, (T)m0};\n\
    }\n"
  code: "#pragma once\n#include <type_traits>\n#include <utility>\n#include \"../math/rem_euclid.cpp\"\
    \n\ntemplate <class T> constexpr std::pair<T, T> inv_gcd(const T& a, const T&\
    \ b) {\n    using U = std::make_signed_t<T>;\n    U t = rem_euclid(a, b);\n  \
    \  if (t == 0) return {b, 0};\n    U s = b, m0 = 0, m1 = 1;\n    while (t != 0)\
    \ {\n        const U u = s / t;\n        s -= t * u;\n        m0 -= m1 * u;\n\
    \        U tmp = s;\n        s = t;\n        t = tmp;\n        tmp = m0;\n   \
    \     m0 = m1;\n        m1 = tmp;\n    }\n    if (m0 < 0) m0 += b / s;\n    return\
    \ {(T)s, (T)m0};\n}\n"
  dependsOn:
  - math/rem_euclid.cpp
  isVerificationFile: false
  path: math/inv_gcd.cpp
  requiredBy:
  - math/dynamic_modint.cpp
  - math/mod_inv.cpp
  - math/congruence_equations.cpp
  - algorithm/convolution_int.cpp
  - algorithm/convolution_arbitrary_mod.cpp
  timestamp: '2021-11-01 18:27:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution_arbitrary_mod.test.cpp
documentation_of: math/inv_gcd.cpp
layout: document
redirect_from:
- /library/math/inv_gcd.cpp
- /library/math/inv_gcd.cpp.html
title: math/inv_gcd.cpp
---
