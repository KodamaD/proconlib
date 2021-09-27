---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dual_segment_tree.test.cpp
    title: test/dual_segment_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"traits/assign_monoid.cpp\"\n#include <optional>\n\ntemplate\
    \ <class T> struct AssignMonoid {\n    using Type = std::optional<T>;\n    static\
    \ constexpr Type identity() { return std::nullopt; }\n    static constexpr Type\
    \ operation(const Type& l, const Type& r) { return r ? r : l; }\n};\n"
  code: "#pragma once\n#include <optional>\n\ntemplate <class T> struct AssignMonoid\
    \ {\n    using Type = std::optional<T>;\n    static constexpr Type identity()\
    \ { return std::nullopt; }\n    static constexpr Type operation(const Type& l,\
    \ const Type& r) { return r ? r : l; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: traits/assign_monoid.cpp
  requiredBy: []
  timestamp: '2021-09-27 22:23:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dual_segment_tree.test.cpp
documentation_of: traits/assign_monoid.cpp
layout: document
redirect_from:
- /library/traits/assign_monoid.cpp
- /library/traits/assign_monoid.cpp.html
title: traits/assign_monoid.cpp
---
