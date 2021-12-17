---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
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
  bundledCode: "#line 2 \"traits/pair_monoid.cpp\"\n#include <utility>\n\ntemplate\
    \ <class M, class N> struct PairMonoid {\n    using Type = std::pair<typename\
    \ M::Type, typename N::Type>;\n    static constexpr Type identity() { return {M::identity(),\
    \ N::identity()}; }\n    static constexpr Type operation(const Type& l, const\
    \ Type& r) {\n        return {M::operation(l.first, r.first), N::operation(l.second,\
    \ r.second)};\n    }\n};\n"
  code: "#pragma once\n#include <utility>\n\ntemplate <class M, class N> struct PairMonoid\
    \ {\n    using Type = std::pair<typename M::Type, typename N::Type>;\n    static\
    \ constexpr Type identity() { return {M::identity(), N::identity()}; }\n    static\
    \ constexpr Type operation(const Type& l, const Type& r) {\n        return {M::operation(l.first,\
    \ r.first), N::operation(l.second, r.second)};\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: traits/pair_monoid.cpp
  requiredBy:
  - traits/sum_affine_action.cpp
  timestamp: '2021-09-27 22:23:01+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/lazy_segment_tree.test.cpp
documentation_of: traits/pair_monoid.cpp
layout: document
redirect_from:
- /library/traits/pair_monoid.cpp
- /library/traits/pair_monoid.cpp.html
title: traits/pair_monoid.cpp
---
