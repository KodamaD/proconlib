---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n#include <cstddef>\n\
    \nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    using isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 3 \"utility/auto_memoize.cpp\"\
    \n#include <tuple>\n#include <type_traits>\n#include <utility>\n#include <map>\n\
    \ntemplate <class F>\nclass AutoMemoize {\n    template <class> \n    class GetSig;\n\
    \    template <class T, class R, class S, class... Args>\n    class GetSig<R (T::*)(S,\
    \ Args...) const> {\n        using Ret = R;\n        using Tuple = std::tuple<Args...>;\n\
    \    };\n\n    using Sig = GetSig<decltype(&F::template operator()<AutoMemoize<F>&>)>;\n\
    \    using R = typename Sig::Ret;\n    using Tuple = typename Sig::Tuple;\n\n\
    \    F func;\n    std::map<Tuple, R> data;\n\n    template <usize... I>\n    R\
    \ apply(const Tuple& args_tuple, std::index_sequence<I...>) {\n        return\
    \ func(*this, std::get<I>(args_tuple)...);\n    }\n\npublic:\n    template <class\
    \ G>\n    explicit AutoMemoize(G&& g): F(std::forward<G>(g)) { }\n\n    template\
    \ <class... Args>\n    R operator () (Args&&... args) {\n        Tuple tup(std::forward<Args>(args)...);\n\
    \        const auto itr = data.find(tup);\n        if (itr != data.end()) return\
    \ itr -> second;\n        R ret = apply(tup, std::make_index_sequence<std::tuple_size_v<Tuple>>());\n\
    \        data.emplace(std::move(tup), ret);\n        return ret;\n    }\n};\n\n\
    template <class G>\nAutoMemoize(G&&) -> AutoMemoize<std::decay_t<G>>;\n"
  code: "#pragma once\n#include \"../utility/int_alias.cpp\"\n#include <tuple>\n#include\
    \ <type_traits>\n#include <utility>\n#include <map>\n\ntemplate <class F>\nclass\
    \ AutoMemoize {\n    template <class> \n    class GetSig;\n    template <class\
    \ T, class R, class S, class... Args>\n    class GetSig<R (T::*)(S, Args...) const>\
    \ {\n        using Ret = R;\n        using Tuple = std::tuple<Args...>;\n    };\n\
    \n    using Sig = GetSig<decltype(&F::template operator()<AutoMemoize<F>&>)>;\n\
    \    using R = typename Sig::Ret;\n    using Tuple = typename Sig::Tuple;\n\n\
    \    F func;\n    std::map<Tuple, R> data;\n\n    template <usize... I>\n    R\
    \ apply(const Tuple& args_tuple, std::index_sequence<I...>) {\n        return\
    \ func(*this, std::get<I>(args_tuple)...);\n    }\n\npublic:\n    template <class\
    \ G>\n    explicit AutoMemoize(G&& g): F(std::forward<G>(g)) { }\n\n    template\
    \ <class... Args>\n    R operator () (Args&&... args) {\n        Tuple tup(std::forward<Args>(args)...);\n\
    \        const auto itr = data.find(tup);\n        if (itr != data.end()) return\
    \ itr -> second;\n        R ret = apply(tup, std::make_index_sequence<std::tuple_size_v<Tuple>>());\n\
    \        data.emplace(std::move(tup), ret);\n        return ret;\n    }\n};\n\n\
    template <class G>\nAutoMemoize(G&&) -> AutoMemoize<std::decay_t<G>>;\n"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: utility/auto_memoize.cpp
  requiredBy: []
  timestamp: '2021-04-07 12:02:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/auto_memoize.cpp
layout: document
redirect_from:
- /library/utility/auto_memoize.cpp
- /library/utility/auto_memoize.cpp.html
title: utility/auto_memoize.cpp
---
