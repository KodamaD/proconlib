---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: random/rand_int.cpp
    title: random/rand_int.cpp
  - icon: ':x:'
    path: random/xorshift.cpp
    title: random/xorshift.cpp
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':question:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/polynomial_hash.test.cpp
    title: test/polynomial_hash.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"container/polynomial_hash.cpp\"\n#include <cassert>\n#include\
    \ <string>\n#include <type_traits>\n#include <vector>\n#line 2 \"random/rand_int.cpp\"\
    \n#include <random>\n#line 2 \"random/xorshift.cpp\"\n#include <chrono>\n#line\
    \ 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n\nusing i32 = std::int32_t;\n\
    using u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n#line 5 \"random/xorshift.cpp\"\
    \n\nu64 xorshift() {\n    static u64 state = std::chrono::system_clock::now().time_since_epoch().count();\n\
    \    state ^= state << 7;\n    state ^= state >> 9;\n    return state;\n}\n#line\
    \ 4 \"random/rand_int.cpp\"\n\ntemplate <class T> T rand_int(const T& min, const\
    \ T& max) {\n    static std::default_random_engine gen(xorshift());\n    return\
    \ std::uniform_int_distribution<T>(min, max)(gen);\n}\n#line 2 \"utility/rep.cpp\"\
    \n#include <algorithm>\n\nclass Range {\n    struct Iter {\n        int itr;\n\
    \        constexpr Iter(const int pos) noexcept : itr(pos) {}\n        constexpr\
    \ void operator++() noexcept { ++itr; }\n        constexpr bool operator!=(const\
    \ Iter& other) const noexcept { return itr != other.itr; }\n        constexpr\
    \ int operator*() const noexcept { return itr; }\n    };\n    const Iter first,\
    \ last;\n\n  public:\n    explicit constexpr Range(const int first, const int\
    \ last) noexcept : first(first), last(std::max(first, last)) {}\n    constexpr\
    \ Iter begin() const noexcept { return first; }\n    constexpr Iter end() const\
    \ noexcept { return last; }\n};\n\nconstexpr Range rep(const int l, const int\
    \ r) noexcept { return Range(l, r); }\nconstexpr Range rep(const int n) noexcept\
    \ { return Range(0, n); }\n#line 9 \"container/polynomial_hash.cpp\"\n\nstruct\
    \ PolynomialHashOperations {\n    static inline constexpr u64 MOD = ((u64)1 <<\
    \ 61) - 1;\n    static constexpr u64 sum(u64 a, const u64 b) { return (a += b)\
    \ >= MOD ? a - MOD : a; }\n    static constexpr u64 difference(u64 a, const u64\
    \ b) { return (a += MOD - b) >= MOD ? a - MOD : a; }\n    static constexpr u64\
    \ product(const u64 a, const u64 b) {\n        u128 ret = (u128)a * b;\n     \
    \   ret = (ret >> 61) + (ret & MOD);\n        return ret >= MOD ? ret - MOD :\
    \ ret;\n    }\n};\n\ntemplate <int ID> struct PolynomialHashBase {\n    static\
    \ inline const u64 BASE = rand_int<u64>(0, MOD - 1);\n    static u64 base_pow(const\
    \ int n) {\n        static std::vector<u64> vec;\n        if (vec.empty()) vec\
    \ = {1};\n        while ((int)vec.size() <= n) vec.push_back(PolynomialHashOperations::product(vec.back(),\
    \ BASE));\n        return vec[n];\n    }\n};\n\ntemplate <class T, int ID = -1,\
    \ std::enable_if_t<std::is_integral_v<T>>* = nullptr> class PolynomialHash {\n\
    \    using Oper = PolynomialHashOperations;\n    using Base = PolynomialHashBase<ID>;\n\
    \n    std::vector<u64> hash;\n    std::vector<T> data;\n\n  public:\n    PolynomialHash()\
    \ : PolynomialHash(std::vector<T>()) {}\n    explicit PolynomialHash(const std::vector<T>&\
    \ vec) : data(vec) {\n        const int size = data.size();\n        hash = std::vector<u64>(size\
    \ + 1);\n        for (const int i : rep(size)) {\n            assert(0 <= data[i]\
    \ and (u64) data[i] < Base::MOD);\n            hash[i + 1] = Oper::sum(Oper::product(Base::BASE,\
    \ hash[i]), (u64)data[i]);\n        }\n    }\n\n    int size() const { return\
    \ data.size(); }\n    const std::vector<T>& get() const { return data; }\n\n \
    \   u64 fold() const { return hash.back(); }\n    u64 fold(const int l, const\
    \ int r) const {\n        assert(0 <= l and l <= r and r <= size());\n       \
    \ return Oper::difference(hash[r], Oper::product(hash[l], Base::base_pow(r - l)));\n\
    \    }\n\n    void concat(const PolynomialHash& other) {\n        hash.reserve(hash.size()\
    \ + other.size());\n        u64 val = hash.back();\n        for (const int i :\
    \ rep(other.size())) {\n            val = Oper::product(val, Base::BASE);\n  \
    \          hash.push_back(Oper::sum(val, other.hash[i + 1]));\n        }\n   \
    \     data.reserve(data.size() + other.size());\n        std::copy(other.data.cbegin(),\
    \ other.data.cend(), std::back_inserter(data));\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <string>\n#include <type_traits>\n\
    #include <vector>\n#include \"../random/rand_int.cpp\"\n#include \"../utility/int_alias.cpp\"\
    \n#include \"../utility/rep.cpp\"\n\nstruct PolynomialHashOperations {\n    static\
    \ inline constexpr u64 MOD = ((u64)1 << 61) - 1;\n    static constexpr u64 sum(u64\
    \ a, const u64 b) { return (a += b) >= MOD ? a - MOD : a; }\n    static constexpr\
    \ u64 difference(u64 a, const u64 b) { return (a += MOD - b) >= MOD ? a - MOD\
    \ : a; }\n    static constexpr u64 product(const u64 a, const u64 b) {\n     \
    \   u128 ret = (u128)a * b;\n        ret = (ret >> 61) + (ret & MOD);\n      \
    \  return ret >= MOD ? ret - MOD : ret;\n    }\n};\n\ntemplate <int ID> struct\
    \ PolynomialHashBase {\n    static inline const u64 BASE = rand_int<u64>(0, MOD\
    \ - 1);\n    static u64 base_pow(const int n) {\n        static std::vector<u64>\
    \ vec;\n        if (vec.empty()) vec = {1};\n        while ((int)vec.size() <=\
    \ n) vec.push_back(PolynomialHashOperations::product(vec.back(), BASE));\n   \
    \     return vec[n];\n    }\n};\n\ntemplate <class T, int ID = -1, std::enable_if_t<std::is_integral_v<T>>*\
    \ = nullptr> class PolynomialHash {\n    using Oper = PolynomialHashOperations;\n\
    \    using Base = PolynomialHashBase<ID>;\n\n    std::vector<u64> hash;\n    std::vector<T>\
    \ data;\n\n  public:\n    PolynomialHash() : PolynomialHash(std::vector<T>())\
    \ {}\n    explicit PolynomialHash(const std::vector<T>& vec) : data(vec) {\n \
    \       const int size = data.size();\n        hash = std::vector<u64>(size +\
    \ 1);\n        for (const int i : rep(size)) {\n            assert(0 <= data[i]\
    \ and (u64) data[i] < Base::MOD);\n            hash[i + 1] = Oper::sum(Oper::product(Base::BASE,\
    \ hash[i]), (u64)data[i]);\n        }\n    }\n\n    int size() const { return\
    \ data.size(); }\n    const std::vector<T>& get() const { return data; }\n\n \
    \   u64 fold() const { return hash.back(); }\n    u64 fold(const int l, const\
    \ int r) const {\n        assert(0 <= l and l <= r and r <= size());\n       \
    \ return Oper::difference(hash[r], Oper::product(hash[l], Base::base_pow(r - l)));\n\
    \    }\n\n    void concat(const PolynomialHash& other) {\n        hash.reserve(hash.size()\
    \ + other.size());\n        u64 val = hash.back();\n        for (const int i :\
    \ rep(other.size())) {\n            val = Oper::product(val, Base::BASE);\n  \
    \          hash.push_back(Oper::sum(val, other.hash[i + 1]));\n        }\n   \
    \     data.reserve(data.size() + other.size());\n        std::copy(other.data.cbegin(),\
    \ other.data.cend(), std::back_inserter(data));\n    }\n};\n"
  dependsOn:
  - random/rand_int.cpp
  - random/xorshift.cpp
  - utility/int_alias.cpp
  - utility/rep.cpp
  isVerificationFile: false
  path: container/polynomial_hash.cpp
  requiredBy: []
  timestamp: '2022-01-07 21:48:21+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/polynomial_hash.test.cpp
documentation_of: container/polynomial_hash.cpp
layout: document
redirect_from:
- /library/container/polynomial_hash.cpp
- /library/container/polynomial_hash.cpp.html
title: container/polynomial_hash.cpp
---
