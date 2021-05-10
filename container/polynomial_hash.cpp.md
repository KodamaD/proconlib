---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bit/ceil_log2.cpp
    title: bit/ceil_log2.cpp
  - icon: ':heavy_check_mark:'
    path: random/rand_int.cpp
    title: random/rand_int.cpp
  - icon: ':heavy_check_mark:'
    path: random/xorshift.cpp
    title: random/xorshift.cpp
  - icon: ':heavy_check_mark:'
    path: utility/auto_realloc.cpp
    title: utility/auto_realloc.cpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':heavy_check_mark:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/polynomial_hash.test.cpp
    title: test/polynomial_hash.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n#include <cstddef>\n\
    \nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    using isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 3 \"utility/rep.cpp\"\
    \n#include <algorithm>\n\nclass rep {\n    struct Iter {\n        usize itr;\n\
    \        constexpr Iter(const usize pos) noexcept: itr(pos) { }\n        constexpr\
    \ void operator ++ () noexcept { ++itr; }\n        constexpr bool operator !=\
    \ (const Iter& other) const noexcept { return itr != other.itr; }\n        constexpr\
    \ usize operator * () const noexcept { return itr; }\n    };\n    const Iter first,\
    \ last;\npublic:\n    explicit constexpr rep(const usize first, const usize last)\
    \ noexcept: first(first), last(std::max(first, last)) { }\n    constexpr Iter\
    \ begin() const noexcept { return first; }\n    constexpr Iter end() const noexcept\
    \ { return last; }\n};\n#line 3 \"random/xorshift.cpp\"\n#include <random>\n#include\
    \ <chrono>\n\nu64 xorshift() {\n    static u64 state = std::chrono::system_clock::now().time_since_epoch().count();\n\
    \    state ^= state << 7;\n    state ^= state >> 9;\n    return state;\n}\n#line\
    \ 4 \"random/rand_int.cpp\"\n\ntemplate <class T>\nT rand_int(const T& min, const\
    \ T& max) {\n    static std::default_random_engine gen(xorshift());\n    return\
    \ std::uniform_int_distribution<T>(min, max)(gen);\n}\n#line 3 \"bit/ceil_log2.cpp\"\
    \n\nconstexpr u64 ceil_log2(const u64 x) {\n    u64 e = 0;\n    while (((u64)\
    \ 1 << e) < x) ++e;\n    return e;\n}\n#line 4 \"utility/auto_realloc.cpp\"\n\
    #include <utility>\n#include <vector>\n\ntemplate <class F>\nclass AutoReallocation\
    \ {\n    using R = typename decltype(std::declval<F>()((usize) 0))::value_type;\n\
    \    \n    F func;\n    mutable std::vector<R> data;\n\npublic:\n    explicit\
    \ AutoReallocation(F&& f): func(std::forward<F>(f)), data() { }\n    \n    void\
    \ reserve(const usize size) const {\n        if (data.size() < size) data = func(((usize)\
    \ 1 << ceil_log2(size)));\n    }\n    R operator [] (const usize i) const {\n\
    \        reserve(i + 1);\n        return data[i];\n    }\n};\n\ntemplate <class\
    \ F>\ndecltype(auto) auto_realloc(F&& f) {\n    using G = std::decay_t<F>;\n \
    \   return AutoReallocation<G>(std::forward<G>(f));\n}\n#line 7 \"container/polynomial_hash.cpp\"\
    \n#include <string>\n#include <type_traits>\n#include <cassert>\n\ntemplate <usize\
    \ ID>\nstruct PolynomialHashHelper {\n    static inline constexpr u64 MOD = ((u64)\
    \ 1 << 61) - 1;\n    static inline const u64 BASE = rand_int<u64>(0, MOD - 1);\n\
    \n    static constexpr u64 add(u64 a, const u64 b) { return (a += b) >= MOD ?\
    \ a - MOD : a; }\n    static constexpr u64 sub(u64 a, const u64 b) { return (a\
    \ += MOD - b) >= MOD ? a - MOD : a; }\n    static constexpr u64 mul(const u64\
    \ a, const u64 b) {\n        u128 ret = (u128) a * b;\n        ret = (ret >> 61)\
    \ + (ret & MOD);\n        return ret >= MOD ? ret - MOD : ret;\n    }\n\n    static\
    \ inline const auto BASE_POW = auto_realloc([](const usize n) {\n        std::vector<u64>\
    \ ret(n);\n        ret[0] = 1;\n        for (const usize i: rep(1, n)) {\n   \
    \         ret[i] = mul(ret[i - 1], BASE);\n        }\n        return ret;\n  \
    \  });\n};\n\ntemplate <class T, usize ID = 0, std::enable_if_t<std::is_integral_v<T>>*\
    \ = nullptr>\nclass PolynomialHash {\n    using Helper = PolynomialHashHelper<ID>;\n\
    \n    std::vector<u64> hash;\n    std::vector<T> data;\n\npublic:\n    PolynomialHash():\
    \ PolynomialHash(std::vector<T>()) { }\n    explicit PolynomialHash(const std::vector<T>&\
    \ vec): data(vec) {\n        const usize size = data.size();\n        hash = std::vector<u64>(size\
    \ + 1);\n        for (const usize i: rep(0, size)) {\n            assert(0 <=\
    \ data[i]);\n            assert((u64) data[i] < Helper::MOD);\n            hash[i\
    \ + 1] = Helper::add(Helper::mul(Helper::BASE, hash[i]), (u64) data[i]);\n   \
    \     }\n    }\n\n    usize size() const { return data.size(); }\n    const std::vector<T>&\
    \ get() const { return data; }\n\n    u64 fold() const { return hash.back(); }\n\
    \    u64 fold(const usize l, const usize r) const {\n        assert(l <= r and\
    \ r <= size());\n        return Helper::sub(hash[r], Helper::mul(hash[l], Helper::BASE_POW[r\
    \ - l]));\n    }\n\n    void concat(const PolynomialHash& other) {\n        hash.reserve(hash.size()\
    \ + other.size());\n        u64 val = hash.back();\n        for (const usize i:\
    \ rep(0, other.size())) {\n            val = Helper::mul(val, Helper::BASE);\n\
    \            hash.push_back(Helper::add(val, other.hash[i + 1]));\n        }\n\
    \        data.reserve(data.size() + other.size());\n        std::copy(other.data.cbegin(),\
    \ other.data.cend(), std::back_inserter(data));\n    }\n};\n"
  code: "#pragma once\n#include \"../utility/int_alias.cpp\"\n#include \"../utility/rep.cpp\"\
    \n#include \"../random/rand_int.cpp\"\n#include \"../utility/auto_realloc.cpp\"\
    \n#include <vector>\n#include <string>\n#include <type_traits>\n#include <cassert>\n\
    \ntemplate <usize ID>\nstruct PolynomialHashHelper {\n    static inline constexpr\
    \ u64 MOD = ((u64) 1 << 61) - 1;\n    static inline const u64 BASE = rand_int<u64>(0,\
    \ MOD - 1);\n\n    static constexpr u64 add(u64 a, const u64 b) { return (a +=\
    \ b) >= MOD ? a - MOD : a; }\n    static constexpr u64 sub(u64 a, const u64 b)\
    \ { return (a += MOD - b) >= MOD ? a - MOD : a; }\n    static constexpr u64 mul(const\
    \ u64 a, const u64 b) {\n        u128 ret = (u128) a * b;\n        ret = (ret\
    \ >> 61) + (ret & MOD);\n        return ret >= MOD ? ret - MOD : ret;\n    }\n\
    \n    static inline const auto BASE_POW = auto_realloc([](const usize n) {\n \
    \       std::vector<u64> ret(n);\n        ret[0] = 1;\n        for (const usize\
    \ i: rep(1, n)) {\n            ret[i] = mul(ret[i - 1], BASE);\n        }\n  \
    \      return ret;\n    });\n};\n\ntemplate <class T, usize ID = 0, std::enable_if_t<std::is_integral_v<T>>*\
    \ = nullptr>\nclass PolynomialHash {\n    using Helper = PolynomialHashHelper<ID>;\n\
    \n    std::vector<u64> hash;\n    std::vector<T> data;\n\npublic:\n    PolynomialHash():\
    \ PolynomialHash(std::vector<T>()) { }\n    explicit PolynomialHash(const std::vector<T>&\
    \ vec): data(vec) {\n        const usize size = data.size();\n        hash = std::vector<u64>(size\
    \ + 1);\n        for (const usize i: rep(0, size)) {\n            assert(0 <=\
    \ data[i]);\n            assert((u64) data[i] < Helper::MOD);\n            hash[i\
    \ + 1] = Helper::add(Helper::mul(Helper::BASE, hash[i]), (u64) data[i]);\n   \
    \     }\n    }\n\n    usize size() const { return data.size(); }\n    const std::vector<T>&\
    \ get() const { return data; }\n\n    u64 fold() const { return hash.back(); }\n\
    \    u64 fold(const usize l, const usize r) const {\n        assert(l <= r and\
    \ r <= size());\n        return Helper::sub(hash[r], Helper::mul(hash[l], Helper::BASE_POW[r\
    \ - l]));\n    }\n\n    void concat(const PolynomialHash& other) {\n        hash.reserve(hash.size()\
    \ + other.size());\n        u64 val = hash.back();\n        for (const usize i:\
    \ rep(0, other.size())) {\n            val = Helper::mul(val, Helper::BASE);\n\
    \            hash.push_back(Helper::add(val, other.hash[i + 1]));\n        }\n\
    \        data.reserve(data.size() + other.size());\n        std::copy(other.data.cbegin(),\
    \ other.data.cend(), std::back_inserter(data));\n    }\n};\n"
  dependsOn:
  - utility/int_alias.cpp
  - utility/rep.cpp
  - random/rand_int.cpp
  - random/xorshift.cpp
  - utility/auto_realloc.cpp
  - bit/ceil_log2.cpp
  isVerificationFile: false
  path: container/polynomial_hash.cpp
  requiredBy: []
  timestamp: '2021-05-10 19:00:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/polynomial_hash.test.cpp
documentation_of: container/polynomial_hash.cpp
layout: document
redirect_from:
- /library/container/polynomial_hash.cpp
- /library/container/polynomial_hash.cpp.html
title: container/polynomial_hash.cpp
---
