---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: traits/optional_monoid.cpp
    title: traits/optional_monoid.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: traits/max_add_action.cpp
    title: traits/max_add_action.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/larsch.test.cpp
    title: test/larsch.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"traits/max_monoid.cpp\"\n#include <algorithm>\n#line 2 \"\
    traits/optional_monoid.cpp\"\n#include <optional>\n#include <utility>\n\ntemplate\
    \ <class S> struct OptionalMonoid {\n    using Type = std::optional<typename S::Type>;\n\
    \    static constexpr Type identity() { return std::nullopt; }\n    static constexpr\
    \ Type operation(const Type& l, const Type& r) {\n        if (!l) return r;\n\
    \        if (!r) return l;\n        return Type(std::in_place, S::operation(*l,\
    \ *r));\n    }\n};\n#line 4 \"traits/max_monoid.cpp\"\n\ntemplate <class T> struct\
    \ MaxSemiGroup {\n    using Type = T;\n    static constexpr T operation(const\
    \ T& l, const T& r) { return std::max(l, r); }\n};\n\ntemplate <class T> using\
    \ MaxMonoid = OptionalMonoid<MaxSemiGroup<T>>;\n"
  code: "#pragma once\n#include <algorithm>\n#include \"optional_monoid.cpp\"\n\n\
    template <class T> struct MaxSemiGroup {\n    using Type = T;\n    static constexpr\
    \ T operation(const T& l, const T& r) { return std::max(l, r); }\n};\n\ntemplate\
    \ <class T> using MaxMonoid = OptionalMonoid<MaxSemiGroup<T>>;"
  dependsOn:
  - traits/optional_monoid.cpp
  isVerificationFile: false
  path: traits/max_monoid.cpp
  requiredBy:
  - traits/max_add_action.cpp
  timestamp: '2021-11-10 20:31:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/larsch.test.cpp
documentation_of: traits/max_monoid.cpp
layout: document
redirect_from:
- /library/traits/max_monoid.cpp
- /library/traits/max_monoid.cpp.html
title: traits/max_monoid.cpp
---