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
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/rec_lambda.cpp\"\n#include <utility>\n#include <type_traits>\n\
    \ntemplate <class F>\nstruct RecLambda: private F {\n    template <class G>\n\
    \    explicit constexpr RecLambda(G&& g): F(std::forward<G>(g)) { }\n    template\
    \ <class... Args>\n    constexpr decltype(auto) operator () (Args&&... args) const\
    \ {\n        return F::operator()(*this, std::forward<Args>(args)...);\n    }\n\
    };\n\ntemplate <class G>\nexplicit RecLambda(G&&) -> RecLambda<std::decay_t<G>>;\n"
  code: "#pragma once\n#include <utility>\n#include <type_traits>\n\ntemplate <class\
    \ F>\nstruct RecLambda: private F {\n    template <class G>\n    explicit constexpr\
    \ RecLambda(G&& g): F(std::forward<G>(g)) { }\n    template <class... Args>\n\
    \    constexpr decltype(auto) operator () (Args&&... args) const {\n        return\
    \ F::operator()(*this, std::forward<Args>(args)...);\n    }\n};\n\ntemplate <class\
    \ G>\nexplicit RecLambda(G&&) -> RecLambda<std::decay_t<G>>;\n"
  dependsOn: []
  isVerificationFile: false
  path: utility/rec_lambda.cpp
  requiredBy:
  - math/divisors_from_factors.cpp
  - graph/heavy_light_decomposition.cpp
  timestamp: '2021-04-13 21:27:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/heavy_light_decomposition.test.cpp
documentation_of: utility/rec_lambda.cpp
layout: document
redirect_from:
- /library/utility/rec_lambda.cpp
- /library/utility/rec_lambda.cpp.html
title: utility/rec_lambda.cpp
---
