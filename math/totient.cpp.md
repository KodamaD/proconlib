---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algorithm/convolution_arbitrary_mod.cpp
    title: algorithm/convolution_arbitrary_mod.cpp
  - icon: ':warning:'
    path: algorithm/convolution_int.cpp
    title: algorithm/convolution_int.cpp
  - icon: ':heavy_check_mark:'
    path: algorithm/convolution_mod.cpp
    title: algorithm/convolution_mod.cpp
  - icon: ':heavy_check_mark:'
    path: math/static_modint.cpp
    title: math/static_modint.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/and_convolution.test.cpp
    title: test/and_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/berlekamp_massey.test.cpp
    title: test/berlekamp_massey.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution_arbitrary_mod.test.cpp
    title: test/convolution_arbitrary_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution_mod.test.cpp
    title: test/convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fp_util.test.cpp
    title: test/fp_util.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/heavy_light_decomposition.test.cpp
    title: test/heavy_light_decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazy_segment_tree.test.cpp
    title: test/lazy_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/queue_aggregation.test.cpp
    title: test/queue_aggregation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment_tree.test.cpp
    title: test/segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/semiring_matrix.test.cpp
    title: test/semiring_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/subset_convolution.test.cpp
    title: test/subset_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/totient.test.cpp
    title: test/totient.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  - algorithm/convolution_int.cpp
  - algorithm/convolution_arbitrary_mod.cpp
  - algorithm/convolution_mod.cpp
  - math/static_modint.cpp
  timestamp: '2022-01-07 21:48:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/semiring_matrix.test.cpp
  - test/segment_tree.test.cpp
  - test/queue_aggregation.test.cpp
  - test/totient.test.cpp
  - test/subset_convolution.test.cpp
  - test/convolution_arbitrary_mod.test.cpp
  - test/convolution_mod.test.cpp
  - test/and_convolution.test.cpp
  - test/berlekamp_massey.test.cpp
  - test/lazy_segment_tree.test.cpp
  - test/heavy_light_decomposition.test.cpp
  - test/fp_util.test.cpp
documentation_of: math/totient.cpp
layout: document
redirect_from:
- /library/math/totient.cpp
- /library/math/totient.cpp.html
title: math/totient.cpp
---
