---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/binary_optimization.cpp
    title: graph/binary_optimization.cpp
  - icon: ':heavy_check_mark:'
    path: graph/dinic.cpp
    title: graph/dinic.cpp
  - icon: ':heavy_check_mark:'
    path: graph/strongly_connected_components.cpp
    title: graph/strongly_connected_components.cpp
  - icon: ':x:'
    path: graph/tree_manager.cpp
    title: graph/tree_manager.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/bipartite_matching.test.cpp
    title: test/bipartite_matching.test.cpp
  - icon: ':x:'
    path: test/heavy_light_decomposition.test.cpp
    title: test/heavy_light_decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/rollback_union_find.test.cpp
    title: test/rollback_union_find.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/strongly_connected_components.test.cpp
    title: test/strongly_connected_components.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/rec_lambda.cpp\"\n#include <type_traits>\n#include\
    \ <utility>\n\ntemplate <class F> struct RecursiveLambda : private F {\n    explicit\
    \ constexpr RecursiveLambda(F&& f) : F(std::forward<F>(f)) {}\n    template <class...\
    \ Args> constexpr decltype(auto) operator()(Args&&... args) const {\n        return\
    \ F::operator()(*this, std::forward<Args>(args)...);\n    }\n};\n\ntemplate <class\
    \ F> constexpr decltype(auto) rec_lambda(F&& f) { return RecursiveLambda<F>(std::forward<F>(f));\
    \ }\n"
  code: "#pragma once\n#include <type_traits>\n#include <utility>\n\ntemplate <class\
    \ F> struct RecursiveLambda : private F {\n    explicit constexpr RecursiveLambda(F&&\
    \ f) : F(std::forward<F>(f)) {}\n    template <class... Args> constexpr decltype(auto)\
    \ operator()(Args&&... args) const {\n        return F::operator()(*this, std::forward<Args>(args)...);\n\
    \    }\n};\n\ntemplate <class F> constexpr decltype(auto) rec_lambda(F&& f) {\
    \ return RecursiveLambda<F>(std::forward<F>(f)); }\n"
  dependsOn: []
  isVerificationFile: false
  path: utility/rec_lambda.cpp
  requiredBy:
  - graph/strongly_connected_components.cpp
  - graph/tree_manager.cpp
  - graph/dinic.cpp
  - graph/binary_optimization.cpp
  timestamp: '2021-11-03 19:13:26+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/strongly_connected_components.test.cpp
  - test/heavy_light_decomposition.test.cpp
  - test/rollback_union_find.test.cpp
  - test/bipartite_matching.test.cpp
documentation_of: utility/rec_lambda.cpp
layout: document
redirect_from:
- /library/utility/rec_lambda.cpp
- /library/utility/rec_lambda.cpp.html
title: utility/rec_lambda.cpp
---
