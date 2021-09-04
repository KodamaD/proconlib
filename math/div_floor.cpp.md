---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/rem_euclid.cpp
    title: math/rem_euclid.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: '#line 2 "math/rem_euclid.cpp"


    template <class T> constexpr T rem_euclid(T value, const T& mod) { return (value
    %= mod) >= 0 ? value : value + mod; }

    #line 3 "math/div_floor.cpp"


    template <class T> constexpr T div_floor(const T& x, const T& y) { return (x -
    rem_euclid(x, y)) / y; }

    '
  code: '#pragma once

    #include "rem_euclid.cpp"


    template <class T> constexpr T div_floor(const T& x, const T& y) { return (x -
    rem_euclid(x, y)) / y; }

    '
  dependsOn:
  - math/rem_euclid.cpp
  isVerificationFile: false
  path: math/div_floor.cpp
  requiredBy: []
  timestamp: '2021-09-04 17:30:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/div_floor.cpp
layout: document
redirect_from:
- /library/math/div_floor.cpp
- /library/math/div_floor.cpp.html
title: math/div_floor.cpp
---
