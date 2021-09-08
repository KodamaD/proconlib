---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/heavy_light_decomposition.cpp
    title: graph/heavy_light_decomposition.cpp
  - icon: ':warning:'
    path: math/divisors_from_factors.cpp
    title: math/divisors_from_factors.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/heavy_light_decomposition.test.cpp
    title: test/heavy_light_decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/rollback_union_find.test.cpp
    title: test/rollback_union_find.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/rec_lambda.cpp\"\n#include <type_traits>\n#include\
    \ <utility>\n\ntemplate <class F> struct RecursiveLambda : private F {\n    explicit\
    \ constexpr RecursiveLambda(F&& f) : F(std::forward<F>(f)) {}\n    template <class...\
    \ Args> constexpr decltype(auto) operator()(Args&&... args) const {\n        return\
    \ F::operator()(*this, std::forward<Args>(args)...);\n    }\n};\n\ntemplate <class\
    \ F> constexpr decltype(auto) rec_lambda(F&& f) {\n    using G = std::decay_t<F>;\n\
    \    return RecursiveLambda<G>(std::forward<G>(f));\n}\n"
  code: "#pragma once\n#include <type_traits>\n#include <utility>\n\ntemplate <class\
    \ F> struct RecursiveLambda : private F {\n    explicit constexpr RecursiveLambda(F&&\
    \ f) : F(std::forward<F>(f)) {}\n    template <class... Args> constexpr decltype(auto)\
    \ operator()(Args&&... args) const {\n        return F::operator()(*this, std::forward<Args>(args)...);\n\
    \    }\n};\n\ntemplate <class F> constexpr decltype(auto) rec_lambda(F&& f) {\n\
    \    using G = std::decay_t<F>;\n    return RecursiveLambda<G>(std::forward<G>(f));\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: utility/rec_lambda.cpp
  requiredBy:
  - graph/heavy_light_decomposition.cpp
  - math/divisors_from_factors.cpp
  timestamp: '2021-09-04 17:30:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/rollback_union_find.test.cpp
  - test/heavy_light_decomposition.test.cpp
documentation_of: utility/rec_lambda.cpp
layout: document
redirect_from:
- /library/utility/rec_lambda.cpp
- /library/utility/rec_lambda.cpp.html
title: utility/rec_lambda.cpp
---
