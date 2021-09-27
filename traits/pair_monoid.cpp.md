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
  requiredBy: []
  timestamp: '2021-09-27 22:23:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/lazy_segment_tree.test.cpp
documentation_of: traits/pair_monoid.cpp
layout: document
redirect_from:
- /library/traits/pair_monoid.cpp
- /library/traits/pair_monoid.cpp.html
title: traits/pair_monoid.cpp
---
