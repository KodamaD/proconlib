---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/auto_memoize.test.cpp
    title: test/auto_memoize.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/auto_memoize.cpp\"\n#include <map>\n#include <tuple>\n\
    #include <type_traits>\n#include <utility>\n\ntemplate <class F> class AutoMemoization\
    \ {\n    template <class> struct GetSig;\n    template <class T, class R, class\
    \ S, class... Args> struct GetSig<R (T::*)(S, Args...) const> {\n        using\
    \ Ret = R;\n        using Tuple = std::tuple<std::decay_t<Args>...>;\n    };\n\
    \n    using Sig = GetSig<decltype(&F::template operator()<AutoMemoization<F>&>)>;\n\
    \    using R = typename Sig::Ret;\n    using Tuple = typename Sig::Tuple;\n\n\
    \    F func;\n    mutable std::map<Tuple, R> data;\n\n    template <std::size_t...\
    \ I> R apply(const Tuple& args_tuple, std::index_sequence<I...>) const {\n   \
    \     return func(*this, std::get<I>(args_tuple)...);\n    }\n\n  public:\n  \
    \  explicit AutoMemoization(F&& f) : func(std::forward<F>(f)) {}\n\n    template\
    \ <class... Args> R operator()(Args&&... args) const {\n        Tuple tup(std::forward<Args>(args)...);\n\
    \        const auto itr = data.find(tup);\n        if (itr != data.end()) return\
    \ itr->second;\n        R ret = apply(tup, std::make_index_sequence<std::tuple_size_v<Tuple>>());\n\
    \        data.emplace(std::move(tup), ret);\n        return ret;\n    }\n};\n\n\
    template <class F> decltype(auto) auto_memoize(F&& f) { return AutoMemoization<F>(std::forward<F>(f));\
    \ }\n"
  code: "#pragma once\n#include <map>\n#include <tuple>\n#include <type_traits>\n\
    #include <utility>\n\ntemplate <class F> class AutoMemoization {\n    template\
    \ <class> struct GetSig;\n    template <class T, class R, class S, class... Args>\
    \ struct GetSig<R (T::*)(S, Args...) const> {\n        using Ret = R;\n      \
    \  using Tuple = std::tuple<std::decay_t<Args>...>;\n    };\n\n    using Sig =\
    \ GetSig<decltype(&F::template operator()<AutoMemoization<F>&>)>;\n    using R\
    \ = typename Sig::Ret;\n    using Tuple = typename Sig::Tuple;\n\n    F func;\n\
    \    mutable std::map<Tuple, R> data;\n\n    template <std::size_t... I> R apply(const\
    \ Tuple& args_tuple, std::index_sequence<I...>) const {\n        return func(*this,\
    \ std::get<I>(args_tuple)...);\n    }\n\n  public:\n    explicit AutoMemoization(F&&\
    \ f) : func(std::forward<F>(f)) {}\n\n    template <class... Args> R operator()(Args&&...\
    \ args) const {\n        Tuple tup(std::forward<Args>(args)...);\n        const\
    \ auto itr = data.find(tup);\n        if (itr != data.end()) return itr->second;\n\
    \        R ret = apply(tup, std::make_index_sequence<std::tuple_size_v<Tuple>>());\n\
    \        data.emplace(std::move(tup), ret);\n        return ret;\n    }\n};\n\n\
    template <class F> decltype(auto) auto_memoize(F&& f) { return AutoMemoization<F>(std::forward<F>(f));\
    \ }"
  dependsOn: []
  isVerificationFile: false
  path: utility/auto_memoize.cpp
  requiredBy: []
  timestamp: '2022-09-27 19:53:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/auto_memoize.test.cpp
documentation_of: utility/auto_memoize.cpp
layout: document
redirect_from:
- /library/utility/auto_memoize.cpp
- /library/utility/auto_memoize.cpp.html
title: utility/auto_memoize.cpp
---
