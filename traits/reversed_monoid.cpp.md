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
  bundledCode: "#line 2 \"traits/reversed_monoid.cpp\"\n\ntemplate <class M> struct\
    \ ReversedMonoid {\n    using Type = typename M::Type;\n    static constexpr Type\
    \ identity() { return M::identity(); }\n    static constexpr Type operation(const\
    \ Type& l, const Type& r) { return M::operation(r, l); }\n};\n"
  code: "#pragma once\n\ntemplate <class M> struct ReversedMonoid {\n    using Type\
    \ = typename M::Type;\n    static constexpr Type identity() { return M::identity();\
    \ }\n    static constexpr Type operation(const Type& l, const Type& r) { return\
    \ M::operation(r, l); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: traits/reversed_monoid.cpp
  requiredBy: []
  timestamp: '2021-09-27 22:23:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: traits/reversed_monoid.cpp
layout: document
redirect_from:
- /library/traits/reversed_monoid.cpp
- /library/traits/reversed_monoid.cpp.html
title: traits/reversed_monoid.cpp
---
