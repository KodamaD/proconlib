---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/lazy_segment_tree.test.cpp
    title: test/lazy_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  requiredBy: []
  timestamp: '2021-09-27 22:23:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/lazy_segment_tree.test.cpp
documentation_of: traits/plus_monoid.cpp
layout: document
redirect_from:
- /library/traits/plus_monoid.cpp
- /library/traits/plus_monoid.cpp.html
title: traits/plus_monoid.cpp
---
