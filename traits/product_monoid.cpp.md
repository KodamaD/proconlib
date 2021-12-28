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
  bundledCode: "#line 2 \"traits/product_monoid.cpp\"\n\ntemplate <class T> struct\
    \ ProductMonoid {\n    using Type = T;\n    static constexpr T identity() { return\
    \ T(1); }\n    static constexpr T operation(const T& l, const T& r) { return l\
    \ * r; }\n};\n"
  code: "#pragma once\n\ntemplate <class T> struct ProductMonoid {\n    using Type\
    \ = T;\n    static constexpr T identity() { return T(1); }\n    static constexpr\
    \ T operation(const T& l, const T& r) { return l * r; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: traits/product_monoid.cpp
  requiredBy: []
  timestamp: '2021-12-28 21:38:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: traits/product_monoid.cpp
layout: document
redirect_from:
- /library/traits/product_monoid.cpp
- /library/traits/product_monoid.cpp.html
title: traits/product_monoid.cpp
---
