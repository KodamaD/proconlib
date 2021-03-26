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
  bundledCode: "#line 2 \"utility/rec_lambda.cpp\"\n#include <utility>\n\ntemplate\
    \ <class F>\nstruct RecLambda: private F {\n    explicit constexpr RecLambda(F&&\
    \ f): F(std::forward<F>(f)) { }\n    template <class... Args>\n    constexpr decltype(auto)\
    \ operator () (Args&&... args) const {\n        return F::operator()(*this, std::forward<Args>(args)...);\n\
    \    }\n};\n"
  code: "#pragma once\n#include <utility>\n\ntemplate <class F>\nstruct RecLambda:\
    \ private F {\n    explicit constexpr RecLambda(F&& f): F(std::forward<F>(f))\
    \ { }\n    template <class... Args>\n    constexpr decltype(auto) operator ()\
    \ (Args&&... args) const {\n        return F::operator()(*this, std::forward<Args>(args)...);\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: utility/rec_lambda.cpp
  requiredBy:
  - math/divisors_from_factors.cpp
  timestamp: '2021-03-25 15:38:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/rec_lambda.cpp
layout: document
redirect_from:
- /library/utility/rec_lambda.cpp
- /library/utility/rec_lambda.cpp.html
title: utility/rec_lambda.cpp
---
