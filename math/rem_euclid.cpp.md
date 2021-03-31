---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/div_floor.cpp
    title: math/div_floor.cpp
  - icon: ':warning:'
    path: math/dynamic_modint.cpp
    title: math/dynamic_modint.cpp
  - icon: ':heavy_check_mark:'
    path: math/static_modint.cpp
    title: math/static_modint.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/lazy_segment_tree.test.cpp
    title: test/lazy_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/modint_util.test.cpp
    title: test/modint_util.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment_tree.test.cpp
    title: test/segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/rem_euclid.cpp\"\n\ntemplate <class T>\nconstexpr T\
    \ rem_euclid(T value, const T& mod) {\n    return (value %= mod) >= 0 ? value\
    \ : value + mod;\n}\n"
  code: "#pragma once\n\ntemplate <class T>\nconstexpr T rem_euclid(T value, const\
    \ T& mod) {\n    return (value %= mod) >= 0 ? value : value + mod;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/rem_euclid.cpp
  requiredBy:
  - math/static_modint.cpp
  - math/dynamic_modint.cpp
  - math/div_floor.cpp
  timestamp: '2021-03-28 15:26:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/lazy_segment_tree.test.cpp
  - test/segment_tree.test.cpp
  - test/modint_util.test.cpp
documentation_of: math/rem_euclid.cpp
layout: document
redirect_from:
- /library/math/rem_euclid.cpp
- /library/math/rem_euclid.cpp.html
title: math/rem_euclid.cpp
---
