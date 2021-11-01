---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/sparse_table.test.cpp
    title: test/sparse_table.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"traits/lambda_semigroup.cpp\"\n#include <memory>\n#include\
    \ <utility>\n\ntemplate <class F> class LambdaSemiGroup {\n    template <class>\
    \ struct GetArg;\n    template <class C, class T> struct GetArg<T (C::*)(T, T)\
    \ const> { using Type = T; };\n\n    static inline std::unique_ptr<F> OP;\n\n\
    \  public:\n    using Type = typename GetArg<decltype(&F::operator())>::Type;\n\
    \    static constexpr Type operation(const Type& l, const Type& r) {\n       \
    \ assert(OP);\n        return OP->operator()(l, r);\n    }\n    explicit constexpr\
    \ LambdaSemiGroup(F&& f) { OP = std::make_unique<F>(std::move(f)); }\n};\n\ntemplate\
    \ <class F> decltype(auto) lambda_semigroup(F&& f) { return LambdaSemiGroup<F>(std::move(f));\
    \ }\n"
  code: "#pragma once\n#include <memory>\n#include <utility>\n\ntemplate <class F>\
    \ class LambdaSemiGroup {\n    template <class> struct GetArg;\n    template <class\
    \ C, class T> struct GetArg<T (C::*)(T, T) const> { using Type = T; };\n\n   \
    \ static inline std::unique_ptr<F> OP;\n\n  public:\n    using Type = typename\
    \ GetArg<decltype(&F::operator())>::Type;\n    static constexpr Type operation(const\
    \ Type& l, const Type& r) {\n        assert(OP);\n        return OP->operator()(l,\
    \ r);\n    }\n    explicit constexpr LambdaSemiGroup(F&& f) { OP = std::make_unique<F>(std::move(f));\
    \ }\n};\n\ntemplate <class F> decltype(auto) lambda_semigroup(F&& f) { return\
    \ LambdaSemiGroup<F>(std::move(f)); }\n"
  dependsOn: []
  isVerificationFile: false
  path: traits/lambda_semigroup.cpp
  requiredBy: []
  timestamp: '2021-11-01 21:39:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/sparse_table.test.cpp
documentation_of: traits/lambda_semigroup.cpp
layout: document
redirect_from:
- /library/traits/lambda_semigroup.cpp
- /library/traits/lambda_semigroup.cpp.html
title: traits/lambda_semigroup.cpp
---
