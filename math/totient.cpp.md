---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: math/static_modint.cpp
    title: math/static_modint.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/heavy_light_decomposition.test.cpp
    title: test/heavy_light_decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazy_segment_tree.test.cpp
    title: test/lazy_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/modint_util.test.cpp
    title: test/modint_util.test.cpp
  - icon: ':x:'
    path: test/segment_tree.test.cpp
    title: test/segment_tree.test.cpp
  - icon: ':x:'
    path: test/semiring_matrix.test.cpp
    title: test/semiring_matrix.test.cpp
  - icon: ':x:'
    path: test/totient.test.cpp
    title: test/totient.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/totient.cpp\"\n\ntemplate <class T> constexpr T totient(T\
    \ x) {\n    T ret = x;\n    for (T i = 2; i * i <= x; ++i) {\n        if (x %\
    \ i == 0) {\n            ret /= i;\n            ret *= i - 1;\n            while\
    \ (x % i == 0) x /= i;\n        }\n    }\n    if (x > 1) {\n        ret /= x;\n\
    \        ret *= x - 1;\n    }\n    return ret;\n}\n"
  code: "#pragma once\n\ntemplate <class T> constexpr T totient(T x) {\n    T ret\
    \ = x;\n    for (T i = 2; i * i <= x; ++i) {\n        if (x % i == 0) {\n    \
    \        ret /= i;\n            ret *= i - 1;\n            while (x % i == 0)\
    \ x /= i;\n        }\n    }\n    if (x > 1) {\n        ret /= x;\n        ret\
    \ *= x - 1;\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/totient.cpp
  requiredBy:
  - math/static_modint.cpp
  timestamp: '2021-09-04 17:30:23+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/totient.test.cpp
  - test/segment_tree.test.cpp
  - test/semiring_matrix.test.cpp
  - test/modint_util.test.cpp
  - test/heavy_light_decomposition.test.cpp
  - test/lazy_segment_tree.test.cpp
documentation_of: math/totient.cpp
layout: document
redirect_from:
- /library/math/totient.cpp
- /library/math/totient.cpp.html
title: math/totient.cpp
---
