---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: traits/optional_monoid.cpp
    title: traits/optional_monoid.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: traits/min_add_action.cpp
    title: traits/min_add_action.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"traits/min_monoid.cpp\"\n#include <algorithm>\n#line 2 \"\
    traits/optional_monoid.cpp\"\n#include <optional>\n#include <utility>\n\ntemplate\
    \ <class S> struct OptionalMonoid {\n    using Type = std::optional<typename S::Type>;\n\
    \    static constexpr Type identity() { return std::nullopt; }\n    static constexpr\
    \ Type operation(const Type& l, const Type& r) {\n        if (!l) return r;\n\
    \        if (!r) return l;\n        return Type(std::in_place, S::operation(*l,\
    \ *r));\n    }\n};\n#line 4 \"traits/min_monoid.cpp\"\n\ntemplate <class T> struct\
    \ MinSemiGroup {\n    using Type = T;\n    static constexpr T operation(const\
    \ T& l, const T& r) { return std::min(l, r); }\n};\n\ntemplate <class T> using\
    \ MinMonoid = OptionalMonoid<MinSemiGroup<T>>;\n"
  code: "#pragma once\n#include <algorithm>\n#include \"optional_monoid.cpp\"\n\n\
    template <class T> struct MinSemiGroup {\n    using Type = T;\n    static constexpr\
    \ T operation(const T& l, const T& r) { return std::min(l, r); }\n};\n\ntemplate\
    \ <class T> using MinMonoid = OptionalMonoid<MinSemiGroup<T>>;"
  dependsOn:
  - traits/optional_monoid.cpp
  isVerificationFile: false
  path: traits/min_monoid.cpp
  requiredBy:
  - traits/min_add_action.cpp
  timestamp: '2021-11-10 20:31:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: traits/min_monoid.cpp
layout: document
redirect_from:
- /library/traits/min_monoid.cpp
- /library/traits/min_monoid.cpp.html
title: traits/min_monoid.cpp
---
