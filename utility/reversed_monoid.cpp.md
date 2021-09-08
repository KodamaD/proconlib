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
  bundledCode: "#line 2 \"utility/reversed_monoid.cpp\"\n\ntemplate <class Monoid>\
    \ struct ReversedMonoid {\n    using M = Monoid;\n    using Self = ReversedMonoid;\n\
    \    M raw;\n    constexpr ReversedMonoid(const M& m): raw(m) {}\n    static constexpr\
    \ Self zero() { return Self(M::zero()); }\n    constexpr Self operator+(const\
    \ Self& other) const { return other.raw + raw; }\n};\n"
  code: "#pragma once\n\ntemplate <class Monoid> struct ReversedMonoid {\n    using\
    \ M = Monoid;\n    using Self = ReversedMonoid;\n    M raw;\n    constexpr ReversedMonoid(const\
    \ M& m): raw(m) {}\n    static constexpr Self zero() { return Self(M::zero());\
    \ }\n    constexpr Self operator+(const Self& other) const { return other.raw\
    \ + raw; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: utility/reversed_monoid.cpp
  requiredBy:
  - container/queue_aggregation.cpp
  timestamp: '2021-09-04 18:33:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/queue_aggregation.test.cpp
documentation_of: utility/reversed_monoid.cpp
layout: document
redirect_from:
- /library/utility/reversed_monoid.cpp
- /library/utility/reversed_monoid.cpp.html
title: utility/reversed_monoid.cpp
---
