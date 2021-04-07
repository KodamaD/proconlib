---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/divisors_from_factors.cpp
    title: math/divisors_from_factors.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/rec_lambda.cpp\"\n#include <utility>\n#include <type_traits>\n\
    \ntemplate <class F>\nstruct RecLambda: private F {\n    template <class G>\n\
    \    explicit constexpr RecLambda(G&& g): F(std::forward<G>(g)) { }\n    template\
    \ <class... Args>\n    constexpr decltype(auto) operator () (Args&&... args) const\
    \ {\n        return F::operator()(*this, std::forward<Args>(args)...);\n    }\n\
    };\n\ntemplate <class G>\nRecLambda(G&&) -> RecLambda<std::decay_t<G>>;\n"
  code: "#pragma once\n#include <utility>\n#include <type_traits>\n\ntemplate <class\
    \ F>\nstruct RecLambda: private F {\n    template <class G>\n    explicit constexpr\
    \ RecLambda(G&& g): F(std::forward<G>(g)) { }\n    template <class... Args>\n\
    \    constexpr decltype(auto) operator () (Args&&... args) const {\n        return\
    \ F::operator()(*this, std::forward<Args>(args)...);\n    }\n};\n\ntemplate <class\
    \ G>\nRecLambda(G&&) -> RecLambda<std::decay_t<G>>;\n"
  dependsOn: []
  isVerificationFile: false
  path: utility/rec_lambda.cpp
  requiredBy:
  - math/divisors_from_factors.cpp
  timestamp: '2021-04-07 12:02:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/rec_lambda.cpp
layout: document
redirect_from:
- /library/utility/rec_lambda.cpp
- /library/utility/rec_lambda.cpp.html
title: utility/rec_lambda.cpp
---
