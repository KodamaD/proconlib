---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':warning:'
    path: utility/rec_lambda.cpp
    title: utility/rec_lambda.cpp
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
    using isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 2 \"utility/rec_lambda.cpp\"\
    \n#include <utility>\n\ntemplate <class F>\nstruct RecLambda: private F {\n  \
    \  explicit constexpr RecLambda(F&& f): F(std::forward<F>(f)) { }\n    template\
    \ <class... Args>\n    constexpr decltype(auto) operator () (Args&&... args) const\
    \ {\n        return F::operator()(*this, std::forward<Args>(args)...);\n    }\n\
    };\n#line 4 \"math/divisors_from_factors.cpp\"\n#include <vector>\n#include <algorithm>\n\
    \ntemplate <class T>\nstd::vector<T> divisors_from_factors(const std::vector<std::pair<T,\
    \ usize>>& factors, const bool sort = true) {\n    usize size = 1;\n    for (const\
    \ std::pair<T, usize>& f: factors) size *= f.second;\n    std::vector<T> ret;\n\
    \    ret.reserve(size);\n    RecLambda([&](auto&& dfs, const usize i, T x) ->\
    \ void {\n        if (i == factors.size()) {\n            ret.push_back(x);\n\
    \            return;\n        }\n        dfs(i + 1, x);\n        const T p = factors[i].first;\n\
    \        usize e = factors[i].second;\n        while (e--) {\n            x *=\
    \ p;\n            dfs(i + 1, x);\n        }\n    })(0, 1);\n    if (sort) std::sort(ret.begin(),\
    \ ret.end());\n    return ret;\n}\n"
  code: "#pragma once\n#include \"../utility/int_alias.cpp\"\n#include \"../utility/rec_lambda.cpp\"\
    \n#include <vector>\n#include <algorithm>\n\ntemplate <class T>\nstd::vector<T>\
    \ divisors_from_factors(const std::vector<std::pair<T, usize>>& factors, const\
    \ bool sort = true) {\n    usize size = 1;\n    for (const std::pair<T, usize>&\
    \ f: factors) size *= f.second;\n    std::vector<T> ret;\n    ret.reserve(size);\n\
    \    RecLambda([&](auto&& dfs, const usize i, T x) -> void {\n        if (i ==\
    \ factors.size()) {\n            ret.push_back(x);\n            return;\n    \
    \    }\n        dfs(i + 1, x);\n        const T p = factors[i].first;\n      \
    \  usize e = factors[i].second;\n        while (e--) {\n            x *= p;\n\
    \            dfs(i + 1, x);\n        }\n    })(0, 1);\n    if (sort) std::sort(ret.begin(),\
    \ ret.end());\n    return ret;\n}\n"
  dependsOn:
  - utility/int_alias.cpp
  - utility/rec_lambda.cpp
  isVerificationFile: false
  path: math/divisors_from_factors.cpp
  requiredBy: []
  timestamp: '2021-03-31 11:13:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/divisors_from_factors.cpp
layout: document
redirect_from:
- /library/math/divisors_from_factors.cpp
- /library/math/divisors_from_factors.cpp.html
title: math/divisors_from_factors.cpp
---
