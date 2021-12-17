---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: traits/max_monoid.cpp
    title: traits/max_monoid.cpp
  - icon: ':question:'
    path: traits/optional_monoid.cpp
    title: traits/optional_monoid.cpp
  - icon: ':heavy_check_mark:'
    path: traits/plus_monoid.cpp
    title: traits/plus_monoid.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
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
    \ MaxMonoid = OptionalMonoid<MaxSemiGroup<T>>;\n#line 2 \"traits/plus_monoid.cpp\"\
    \n\ntemplate <class T> struct PlusMonoid {\n    using Type = T;\n    static constexpr\
    \ T identity() { return T(0); }\n    static constexpr T operation(const T& l,\
    \ const T& r) { return l + r; }\n};\n#line 4 \"traits/max_add_action.cpp\"\n\n\
    template <class T> struct MaxAddAction {\n    using Monoid = MaxMonoid<T>;\n \
    \   using Effector = PlusMonoid<T>;\n    static constexpr std::optional<T> operation(const\
    \ std::optional<T>& l, const T& r) {\n        if (!l) return std::nullopt;\n \
    \       return std::optional<T>(std::in_place, *l + r);\n    }\n};\n"
  code: "#pragma once\n#include \"max_monoid.cpp\"\n#include \"plus_monoid.cpp\"\n\
    \ntemplate <class T> struct MaxAddAction {\n    using Monoid = MaxMonoid<T>;\n\
    \    using Effector = PlusMonoid<T>;\n    static constexpr std::optional<T> operation(const\
    \ std::optional<T>& l, const T& r) {\n        if (!l) return std::nullopt;\n \
    \       return std::optional<T>(std::in_place, *l + r);\n    }\n};"
  dependsOn:
  - traits/max_monoid.cpp
  - traits/optional_monoid.cpp
  - traits/plus_monoid.cpp
  isVerificationFile: false
  path: traits/max_add_action.cpp
  requiredBy: []
  timestamp: '2021-11-10 20:31:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: traits/max_add_action.cpp
layout: document
redirect_from:
- /library/traits/max_add_action.cpp
- /library/traits/max_add_action.cpp.html
title: traits/max_add_action.cpp
---
