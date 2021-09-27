---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/sparse_table.test.cpp
    title: test/sparse_table.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"traits/min_monoid.cpp\"\n#include <functional>\n#include\
    \ <limits>\n\ntemplate <class T> struct MinMonoid {\n    using Type = T;\n   \
    \ static constexpr T identity() { return std::numeric_limits<T>::max(); }\n  \
    \  static constexpr T operation(const T& l, const T& r) { return std::min(l, r);\
    \ }\n};\n"
  code: "#pragma once\n#include <functional>\n#include <limits>\n\ntemplate <class\
    \ T> struct MinMonoid {\n    using Type = T;\n    static constexpr T identity()\
    \ { return std::numeric_limits<T>::max(); }\n    static constexpr T operation(const\
    \ T& l, const T& r) { return std::min(l, r); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: traits/min_monoid.cpp
  requiredBy: []
  timestamp: '2021-09-27 22:23:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/sparse_table.test.cpp
documentation_of: traits/min_monoid.cpp
layout: document
redirect_from:
- /library/traits/min_monoid.cpp
- /library/traits/min_monoid.cpp.html
title: traits/min_monoid.cpp
---
