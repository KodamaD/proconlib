---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
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
  bundledCode: "#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n#include <cstddef>\n\
    \nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    using isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 3 \"utility/auto_memoize.cpp\"\
    \n#include <tuple>\n#include <type_traits>\n#include <utility>\n#include <map>\n\
    \ntemplate <class F>\nclass AutoMemoization {\n    template <class> \n    struct\
    \ GetSig;\n    template <class T, class R, class S, class... Args>\n    struct\
    \ GetSig<R (T::*)(S, Args...) const> {\n        using Ret = R;\n        using\
    \ Tuple = std::tuple<Args...>;\n    };\n\n    using Sig = GetSig<decltype(&F::template\
    \ operator()<AutoMemoization<F>&>)>;\n    using R = typename Sig::Ret;\n    using\
    \ Tuple = typename Sig::Tuple;\n\n    F func;\n    mutable std::map<Tuple, R>\
    \ data;\n\n    template <usize... I>\n    R apply(const Tuple& args_tuple, std::index_sequence<I...>)\
    \ const {\n        return func(*this, std::get<I>(args_tuple)...);\n    }\n\n\
    public:\n    explicit AutoMemoization(F&& f): func(std::forward<F>(f)) { }\n\n\
    \    template <class... Args>\n    R operator () (Args&&... args) const {\n  \
    \      Tuple tup(std::forward<Args>(args)...);\n        const auto itr = data.find(tup);\n\
    \        if (itr != data.end()) return itr -> second;\n        R ret = apply(tup,\
    \ std::make_index_sequence<std::tuple_size_v<Tuple>>());\n        data.emplace(std::move(tup),\
    \ ret);\n        return ret;\n    }\n};\n\ntemplate <class F>\ndecltype(auto)\
    \ auto_memoize(F&& f) {\n    using G = std::decay_t<F>;\n    return AutoMemoization<G>(std::forward<G>(f));\n\
    }\n"
  code: "#pragma once\n#include \"../utility/int_alias.cpp\"\n#include <tuple>\n#include\
    \ <type_traits>\n#include <utility>\n#include <map>\n\ntemplate <class F>\nclass\
    \ AutoMemoization {\n    template <class> \n    struct GetSig;\n    template <class\
    \ T, class R, class S, class... Args>\n    struct GetSig<R (T::*)(S, Args...)\
    \ const> {\n        using Ret = R;\n        using Tuple = std::tuple<Args...>;\n\
    \    };\n\n    using Sig = GetSig<decltype(&F::template operator()<AutoMemoization<F>&>)>;\n\
    \    using R = typename Sig::Ret;\n    using Tuple = typename Sig::Tuple;\n\n\
    \    F func;\n    mutable std::map<Tuple, R> data;\n\n    template <usize... I>\n\
    \    R apply(const Tuple& args_tuple, std::index_sequence<I...>) const {\n   \
    \     return func(*this, std::get<I>(args_tuple)...);\n    }\n\npublic:\n    explicit\
    \ AutoMemoization(F&& f): func(std::forward<F>(f)) { }\n\n    template <class...\
    \ Args>\n    R operator () (Args&&... args) const {\n        Tuple tup(std::forward<Args>(args)...);\n\
    \        const auto itr = data.find(tup);\n        if (itr != data.end()) return\
    \ itr -> second;\n        R ret = apply(tup, std::make_index_sequence<std::tuple_size_v<Tuple>>());\n\
    \        data.emplace(std::move(tup), ret);\n        return ret;\n    }\n};\n\n\
    template <class F>\ndecltype(auto) auto_memoize(F&& f) {\n    using G = std::decay_t<F>;\n\
    \    return AutoMemoization<G>(std::forward<G>(f));\n}"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: utility/auto_memoize.cpp
  requiredBy: []
  timestamp: '2021-05-10 19:00:24+09:00'
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
