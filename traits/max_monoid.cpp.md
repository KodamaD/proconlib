---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/larsch.test.cpp
    title: test/larsch.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"traits/max_monoid.cpp\"\n#include <functional>\n#include\
    \ <limits>\n\ntemplate <class T> struct MaxMonoid {\n    using Type = T;\n   \
    \ static constexpr T identity() { return std::numeric_limits<T>::min(); }\n  \
    \  static constexpr T operation(const T& l, const T& r) { return std::max(l, r);\
    \ }\n};\n"
  code: "#pragma once\n#include <functional>\n#include <limits>\n\ntemplate <class\
    \ T> struct MaxMonoid {\n    using Type = T;\n    static constexpr T identity()\
    \ { return std::numeric_limits<T>::min(); }\n    static constexpr T operation(const\
    \ T& l, const T& r) { return std::max(l, r); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: traits/max_monoid.cpp
  requiredBy: []
  timestamp: '2021-09-27 22:23:01+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/larsch.test.cpp
documentation_of: traits/max_monoid.cpp
layout: document
redirect_from:
- /library/traits/max_monoid.cpp
- /library/traits/max_monoid.cpp.html
title: traits/max_monoid.cpp
---
