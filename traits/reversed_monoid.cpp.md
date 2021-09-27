---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: container/queue_aggregation.cpp
    title: container/queue_aggregation.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/queue_aggregation.test.cpp
    title: test/queue_aggregation.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  requiredBy:
  - container/queue_aggregation.cpp
  timestamp: '2021-09-27 22:23:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/queue_aggregation.test.cpp
documentation_of: traits/reversed_monoid.cpp
layout: document
redirect_from:
- /library/traits/reversed_monoid.cpp
- /library/traits/reversed_monoid.cpp.html
title: traits/reversed_monoid.cpp
---
