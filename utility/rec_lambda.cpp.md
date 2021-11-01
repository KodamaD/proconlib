---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/dinic.cpp
    title: graph/dinic.cpp
  - icon: ':heavy_check_mark:'
    path: graph/strongly_connected_components.cpp
    title: graph/strongly_connected_components.cpp
  - icon: ':heavy_check_mark:'
    path: graph/tree_manager.cpp
    title: graph/tree_manager.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/bipartite_matching.test.cpp
    title: test/bipartite_matching.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/heavy_light_decomposition.test.cpp
    title: test/heavy_light_decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/rollback_union_find.test.cpp
    title: test/rollback_union_find.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/strongly_connected_components.test.cpp
    title: test/strongly_connected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/rec_lambda.cpp\"\n#include <type_traits>\n#include\
    \ <utility>\n\ntemplate <class F> struct RecursiveLambda : private F {\n    explicit\
    \ constexpr RecursiveLambda(F&& f) : F(std::move(f)) {}\n    template <class...\
    \ Args> constexpr decltype(auto) operator()(Args&&... args) const {\n        return\
    \ F::operator()(*this, std::forward<Args>(args)...);\n    }\n};\n\ntemplate <class\
    \ F> constexpr decltype(auto) rec_lambda(F&& f) { return RecursiveLambda<F>(std::move(f));\
    \ }\n"
  code: "#pragma once\n#include <type_traits>\n#include <utility>\n\ntemplate <class\
    \ F> struct RecursiveLambda : private F {\n    explicit constexpr RecursiveLambda(F&&\
    \ f) : F(std::move(f)) {}\n    template <class... Args> constexpr decltype(auto)\
    \ operator()(Args&&... args) const {\n        return F::operator()(*this, std::forward<Args>(args)...);\n\
    \    }\n};\n\ntemplate <class F> constexpr decltype(auto) rec_lambda(F&& f) {\
    \ return RecursiveLambda<F>(std::move(f)); }\n"
  dependsOn: []
  isVerificationFile: false
  path: utility/rec_lambda.cpp
  requiredBy:
  - graph/dinic.cpp
  - graph/tree_manager.cpp
  - graph/strongly_connected_components.cpp
  timestamp: '2021-11-01 21:39:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/rollback_union_find.test.cpp
  - test/strongly_connected_components.test.cpp
  - test/bipartite_matching.test.cpp
  - test/heavy_light_decomposition.test.cpp
documentation_of: utility/rec_lambda.cpp
layout: document
redirect_from:
- /library/utility/rec_lambda.cpp
- /library/utility/rec_lambda.cpp.html
title: utility/rec_lambda.cpp
---
