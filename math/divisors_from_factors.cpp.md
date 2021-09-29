---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':heavy_check_mark:'
    path: utility/rec_lambda.cpp
    title: utility/rec_lambda.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/divisors_from_factors.cpp\"\n#include <algorithm>\n\
    #include <vector>\n#line 2 \"utility/int_alias.cpp\"\n#include <cstddef>\n#include\
    \ <cstdint>\n\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64\
    \ = std::int64_t;\nusing u64 = std::uint64_t;\nusing isize = std::ptrdiff_t;\n\
    using usize = std::size_t;\n#line 2 \"utility/rec_lambda.cpp\"\n#include <type_traits>\n\
    #include <utility>\n\ntemplate <class F> struct RecursiveLambda : private F {\n\
    \    explicit constexpr RecursiveLambda(F&& f) : F(std::forward<F>(f)) {}\n  \
    \  template <class... Args> constexpr decltype(auto) operator()(Args&&... args)\
    \ const {\n        return F::operator()(*this, std::forward<Args>(args)...);\n\
    \    }\n};\n\ntemplate <class F> constexpr decltype(auto) rec_lambda(F&& f) {\n\
    \    using G = std::decay_t<F>;\n    return RecursiveLambda<G>(std::forward<G>(f));\n\
    }\n#line 6 \"math/divisors_from_factors.cpp\"\n\ntemplate <class T>\nstd::vector<T>\
    \ divisors_from_factors(const std::vector<std::pair<T, usize>>& factors, const\
    \ bool sort = true) {\n    usize size = 1;\n    for (const std::pair<T, usize>&\
    \ f : factors) size *= f.second;\n    std::vector<T> ret;\n    ret.reserve(size);\n\
    \    rec_lambda([&](auto&& dfs, const usize i, T x) -> void {\n        if (i ==\
    \ factors.size()) {\n            ret.push_back(x);\n            return;\n    \
    \    }\n        dfs(i + 1, x);\n        const T p = factors[i].first;\n      \
    \  usize e = factors[i].second;\n        while (e--) {\n            x *= p;\n\
    \            dfs(i + 1, x);\n        }\n    })(0, 1);\n    if (sort) std::sort(ret.begin(),\
    \ ret.end());\n    return ret;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n#include \"../utility/int_alias.cpp\"\
    \n#include \"../utility/rec_lambda.cpp\"\n\ntemplate <class T>\nstd::vector<T>\
    \ divisors_from_factors(const std::vector<std::pair<T, usize>>& factors, const\
    \ bool sort = true) {\n    usize size = 1;\n    for (const std::pair<T, usize>&\
    \ f : factors) size *= f.second;\n    std::vector<T> ret;\n    ret.reserve(size);\n\
    \    rec_lambda([&](auto&& dfs, const usize i, T x) -> void {\n        if (i ==\
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
  timestamp: '2021-09-08 18:46:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/divisors_from_factors.cpp
layout: document
redirect_from:
- /library/math/divisors_from_factors.cpp
- /library/math/divisors_from_factors.cpp.html
title: math/divisors_from_factors.cpp
---
