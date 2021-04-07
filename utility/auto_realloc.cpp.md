---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bit/ceil_log2.cpp
    title: bit/ceil_log2.cpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/modint_util.cpp
    title: math/modint_util.cpp
  - icon: ':heavy_check_mark:'
    path: math/prime_sieve.cpp
    title: math/prime_sieve.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/modint_util.test.cpp
    title: test/modint_util.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/prime_sieve.test.cpp
    title: test/prime_sieve.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n#include <cstddef>\n\
    \nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    using isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 3 \"bit/ceil_log2.cpp\"\
    \n\nconstexpr u64 ceil_log2(const u64 x) {\n    u64 e = 0;\n    while (((u64)\
    \ 1 << e) < x) ++e;\n    return e;\n}\n#line 4 \"utility/auto_realloc.cpp\"\n\
    #include <utility>\n#include <vector>\n\ntemplate <class F>\nclass AutoRealloc\
    \ {\n    using R = typename decltype(std::declval<F>()((usize) 0))::value_type;\n\
    \    F func;\n    std::vector<R> data;\npublic:\n    template <class G>\n    explicit\
    \ AutoRealloc(G&& g, const usize capacity = 0): func(std::forward<G>(g)), data()\
    \ { reserve(capacity); }\n    void reserve(const usize size) {\n        if (data.size()\
    \ < size) {\n            const usize pow2 = ((usize) 1 << ceil_log2(size));\n\
    \            data = func(pow2);\n        }\n    }\n    R operator [] (const usize\
    \ i) {\n        reserve(i + 1);\n        return data[i];\n    }\n};\n\ntemplate\
    \ <class G>\nAutoRealloc(G&&, usize = 0) -> AutoRealloc<std::decay_t<G>>;\n"
  code: "#pragma once\n#include \"../utility/int_alias.cpp\"\n#include \"../bit/ceil_log2.cpp\"\
    \n#include <utility>\n#include <vector>\n\ntemplate <class F>\nclass AutoRealloc\
    \ {\n    using R = typename decltype(std::declval<F>()((usize) 0))::value_type;\n\
    \    F func;\n    std::vector<R> data;\npublic:\n    template <class G>\n    explicit\
    \ AutoRealloc(G&& g, const usize capacity = 0): func(std::forward<G>(g)), data()\
    \ { reserve(capacity); }\n    void reserve(const usize size) {\n        if (data.size()\
    \ < size) {\n            const usize pow2 = ((usize) 1 << ceil_log2(size));\n\
    \            data = func(pow2);\n        }\n    }\n    R operator [] (const usize\
    \ i) {\n        reserve(i + 1);\n        return data[i];\n    }\n};\n\ntemplate\
    \ <class G>\nAutoRealloc(G&&, usize = 0) -> AutoRealloc<std::decay_t<G>>;\n"
  dependsOn:
  - utility/int_alias.cpp
  - bit/ceil_log2.cpp
  isVerificationFile: false
  path: utility/auto_realloc.cpp
  requiredBy:
  - math/modint_util.cpp
  - math/prime_sieve.cpp
  timestamp: '2021-04-07 13:24:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/modint_util.test.cpp
  - test/prime_sieve.test.cpp
documentation_of: utility/auto_realloc.cpp
layout: document
redirect_from:
- /library/utility/auto_realloc.cpp
- /library/utility/auto_realloc.cpp.html
title: utility/auto_realloc.cpp
---
