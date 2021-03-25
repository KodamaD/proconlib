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
  bundledCode: '#line 2 "utility/infty.cpp"

    #include <limits>


    template <class T, T Div = 2>

    constexpr T INFTY = std::numeric_limits<T>::max() / Div;

    '
  code: '#pragma once

    #include <limits>


    template <class T, T Div = 2>

    constexpr T INFTY = std::numeric_limits<T>::max() / Div;

    '
  dependsOn: []
  isVerificationFile: false
  path: utility/infty.cpp
  requiredBy: []
  timestamp: '2021-03-24 22:26:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/infty.cpp
layout: document
redirect_from:
- /library/utility/infty.cpp
- /library/utility/infty.cpp.html
title: utility/infty.cpp
---
