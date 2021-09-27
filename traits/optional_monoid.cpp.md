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
  requiredBy: []
  timestamp: '2021-09-27 22:23:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: traits/optional_monoid.cpp
layout: document
redirect_from:
- /library/traits/optional_monoid.cpp
- /library/traits/optional_monoid.cpp.html
title: traits/optional_monoid.cpp
---
