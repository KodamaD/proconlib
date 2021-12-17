---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: traits/max_add_action.cpp
    title: traits/max_add_action.cpp
  - icon: ':warning:'
    path: traits/min_add_action.cpp
    title: traits/min_add_action.cpp
  - icon: ':x:'
    path: traits/sum_affine_action.cpp
    title: traits/sum_affine_action.cpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/lazy_segment_tree.test.cpp
    title: test/lazy_segment_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"traits/plus_monoid.cpp\"\n\ntemplate <class T> struct PlusMonoid\
    \ {\n    using Type = T;\n    static constexpr T identity() { return T(0); }\n\
    \    static constexpr T operation(const T& l, const T& r) { return l + r; }\n\
    };\n"
  code: "#pragma once\n\ntemplate <class T> struct PlusMonoid {\n    using Type =\
    \ T;\n    static constexpr T identity() { return T(0); }\n    static constexpr\
    \ T operation(const T& l, const T& r) { return l + r; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: traits/plus_monoid.cpp
  requiredBy:
  - traits/max_add_action.cpp
  - traits/sum_affine_action.cpp
  - traits/min_add_action.cpp
  timestamp: '2021-09-27 22:23:01+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/lazy_segment_tree.test.cpp
documentation_of: traits/plus_monoid.cpp
layout: document
redirect_from:
- /library/traits/plus_monoid.cpp
- /library/traits/plus_monoid.cpp.html
title: traits/plus_monoid.cpp
---
