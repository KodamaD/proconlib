---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/sparse_table.test.cpp
    title: test/sparse_table.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: '#line 2 "utility/infty.cpp"

    #include <limits>


    template <class T, T Div = 2> constexpr T INFTY = std::numeric_limits<T>::max()
    / Div;

    '
  code: '#pragma once

    #include <limits>


    template <class T, T Div = 2> constexpr T INFTY = std::numeric_limits<T>::max()
    / Div;

    '
  dependsOn: []
  isVerificationFile: false
  path: utility/infty.cpp
  requiredBy: []
  timestamp: '2021-09-04 17:30:23+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/sparse_table.test.cpp
documentation_of: utility/infty.cpp
layout: document
redirect_from:
- /library/utility/infty.cpp
- /library/utility/infty.cpp.html
title: utility/infty.cpp
---
