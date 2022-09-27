---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: traits/max_add_action.cpp
    title: traits/max_add_action.cpp
  - icon: ':heavy_check_mark:'
    path: traits/max_monoid.cpp
    title: traits/max_monoid.cpp
  - icon: ':warning:'
    path: traits/min_add_action.cpp
    title: traits/min_add_action.cpp
  - icon: ':warning:'
    path: traits/min_monoid.cpp
    title: traits/min_monoid.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/larsch.test.cpp
    title: test/larsch.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/sparse_table.test.cpp
    title: test/sparse_table.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"traits/optional_monoid.cpp\"\n#include <optional>\n#include\
    \ <utility>\n\ntemplate <class S> struct OptionalMonoid {\n    using Type = std::optional<typename\
    \ S::Type>;\n    static constexpr Type identity() { return std::nullopt; }\n \
    \   static constexpr Type operation(const Type& l, const Type& r) {\n        if\
    \ (!l) return r;\n        if (!r) return l;\n        return Type(std::in_place,\
    \ S::operation(*l, *r));\n    }\n};\n"
  code: "#pragma once\n#include <optional>\n#include <utility>\n\ntemplate <class\
    \ S> struct OptionalMonoid {\n    using Type = std::optional<typename S::Type>;\n\
    \    static constexpr Type identity() { return std::nullopt; }\n    static constexpr\
    \ Type operation(const Type& l, const Type& r) {\n        if (!l) return r;\n\
    \        if (!r) return l;\n        return Type(std::in_place, S::operation(*l,\
    \ *r));\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: traits/optional_monoid.cpp
  requiredBy:
  - traits/min_add_action.cpp
  - traits/max_monoid.cpp
  - traits/min_monoid.cpp
  - traits/max_add_action.cpp
  timestamp: '2021-09-27 22:23:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/sparse_table.test.cpp
  - test/larsch.test.cpp
documentation_of: traits/optional_monoid.cpp
layout: document
redirect_from:
- /library/traits/optional_monoid.cpp
- /library/traits/optional_monoid.cpp.html
title: traits/optional_monoid.cpp
---
