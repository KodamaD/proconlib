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
    path: utility/int_alias_extended.cpp
    title: utility/int_alias_extended.cpp
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
  bundledCode: "#line 2 \"container/polynomial_hash.cpp\"\n#include <cassert>\n#include\
    \ <string>\n#include <type_traits>\n#include <vector>\n#line 2 \"random/rand_int.cpp\"\
    \n#include <random>\n#line 2 \"random/xorshift.cpp\"\n#include <chrono>\n#line\
    \ 2 \"utility/int_alias.cpp\"\n#include <cstddef>\n#include <cstdint>\n\nusing\
    \ i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing isize = std::ptrdiff_t;\nusing usize = std::size_t;\n\
    #line 5 \"random/xorshift.cpp\"\n\nu64 xorshift() {\n    static u64 state = std::chrono::system_clock::now().time_since_epoch().count();\n\
    \    state ^= state << 7;\n    state ^= state >> 9;\n    return state;\n}\n#line\
    \ 4 \"random/rand_int.cpp\"\n\ntemplate <class T> T rand_int(const T& min, const\
    \ T& max) {\n    static std::default_random_engine gen(xorshift());\n    return\
    \ std::uniform_int_distribution<T>(min, max)(gen);\n}\n#line 2 \"utility/auto_realloc.cpp\"\
    \n#include <utility>\n#line 3 \"bit/ceil_log2.cpp\"\n\n__attribute__((target(\"\
    avx2\"))) constexpr u64 ceil_log2(const u64 x) {\n    u64 e = 0;\n    while (((u64)1\
    \ << e) < x) ++e;\n    return e;\n}\n#line 6 \"utility/auto_realloc.cpp\"\n\n\
    template <class F> class AutoReallocation {\n    using R = typename decltype(std::declval<F>()((usize)0))::value_type;\n\
    \n    F func;\n    mutable std::vector<R> data;\n\n  public:\n    explicit AutoReallocation(F&&\
    \ f) : func(std::move(f)), data() {}\n\n    void reserve(const usize size) const\
    \ {\n        if (data.size() < size) data = func(((usize)1 << ceil_log2(size)));\n\
    \    }\n    R operator[](const usize i) const {\n        reserve(i + 1);\n   \
    \     return data[i];\n    }\n};\n\ntemplate <class F> decltype(auto) auto_realloc(F&&\
    \ f) { return AutoReallocation<F>(std::move(f)); }\n#line 4 \"utility/int_alias_extended.cpp\"\
    \n\nusing i8 = std::int8_t;\nusing u8 = std::uint8_t;\nusing i16 = std::int16_t;\n\
    using u16 = std::uint16_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    #line 2 \"utility/rep.cpp\"\n#include <algorithm>\n#line 4 \"utility/rep.cpp\"\
    \n\nclass rep {\n    struct Iter {\n        usize itr;\n        constexpr Iter(const\
    \ usize pos) noexcept : itr(pos) {}\n        constexpr void operator++() noexcept\
    \ { ++itr; }\n        constexpr bool operator!=(const Iter& other) const noexcept\
    \ { return itr != other.itr; }\n        constexpr usize operator*() const noexcept\
    \ { return itr; }\n    };\n    const Iter first, last;\n\n  public:\n    explicit\
    \ constexpr rep(const usize first, const usize last) noexcept : first(first),\
    \ last(std::max(first, last)) {}\n    constexpr Iter begin() const noexcept {\
    \ return first; }\n    constexpr Iter end() const noexcept { return last; }\n\
    };\n#line 11 \"container/polynomial_hash.cpp\"\n\ntemplate <usize ID> struct PolynomialHashHelper\
    \ {\n    static inline constexpr u64 MOD = ((u64)1 << 61) - 1;\n    static inline\
    \ const u64 BASE = rand_int<u64>(0, MOD - 1);\n\n    static constexpr u64 add(u64\
    \ a, const u64 b) { return (a += b) >= MOD ? a - MOD : a; }\n    static constexpr\
    \ u64 sub(u64 a, const u64 b) { return (a += MOD - b) >= MOD ? a - MOD : a; }\n\
    \    static constexpr u64 mul(const u64 a, const u64 b) {\n        u128 ret =\
    \ (u128)a * b;\n        ret = (ret >> 61) + (ret & MOD);\n        return ret >=\
    \ MOD ? ret - MOD : ret;\n    }\n\n    static inline const auto BASE_POW = auto_realloc([](const\
    \ usize n) {\n        std::vector<u64> ret(n);\n        ret[0] = 1;\n        for\
    \ (const usize i : rep(1, n)) {\n            ret[i] = mul(ret[i - 1], BASE);\n\
    \        }\n        return ret;\n    });\n};\n\ntemplate <class T, usize ID =\
    \ 0, std::enable_if_t<std::is_integral_v<T>>* = nullptr> class PolynomialHash\
    \ {\n    using Helper = PolynomialHashHelper<ID>;\n\n    std::vector<u64> hash;\n\
    \    std::vector<T> data;\n\n  public:\n    PolynomialHash() : PolynomialHash(std::vector<T>())\
    \ {}\n    explicit PolynomialHash(const std::vector<T>& vec) : data(vec) {\n \
    \       const usize size = data.size();\n        hash = std::vector<u64>(size\
    \ + 1);\n        for (const usize i : rep(0, size)) {\n            assert(0 <=\
    \ data[i]);\n            assert((u64)data[i] < Helper::MOD);\n            hash[i\
    \ + 1] = Helper::add(Helper::mul(Helper::BASE, hash[i]), (u64)data[i]);\n    \
    \    }\n    }\n\n    usize size() const { return data.size(); }\n    const std::vector<T>&\
    \ get() const { return data; }\n\n    u64 fold() const { return hash.back(); }\n\
    \    u64 fold(const usize l, const usize r) const {\n        assert(l <= r and\
    \ r <= size());\n        return Helper::sub(hash[r], Helper::mul(hash[l], Helper::BASE_POW[r\
    \ - l]));\n    }\n\n    void concat(const PolynomialHash& other) {\n        hash.reserve(hash.size()\
    \ + other.size());\n        u64 val = hash.back();\n        for (const usize i\
    \ : rep(0, other.size())) {\n            val = Helper::mul(val, Helper::BASE);\n\
    \            hash.push_back(Helper::add(val, other.hash[i + 1]));\n        }\n\
    \        data.reserve(data.size() + other.size());\n        std::copy(other.data.cbegin(),\
    \ other.data.cend(), std::back_inserter(data));\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <string>\n#include <type_traits>\n\
    #include <vector>\n#include \"../random/rand_int.cpp\"\n#include \"../utility/auto_realloc.cpp\"\
    \n#include \"../utility/int_alias.cpp\"\n#include \"../utility/int_alias_extended.cpp\"\
    \n#include \"../utility/rep.cpp\"\n\ntemplate <usize ID> struct PolynomialHashHelper\
    \ {\n    static inline constexpr u64 MOD = ((u64)1 << 61) - 1;\n    static inline\
    \ const u64 BASE = rand_int<u64>(0, MOD - 1);\n\n    static constexpr u64 add(u64\
    \ a, const u64 b) { return (a += b) >= MOD ? a - MOD : a; }\n    static constexpr\
    \ u64 sub(u64 a, const u64 b) { return (a += MOD - b) >= MOD ? a - MOD : a; }\n\
    \    static constexpr u64 mul(const u64 a, const u64 b) {\n        u128 ret =\
    \ (u128)a * b;\n        ret = (ret >> 61) + (ret & MOD);\n        return ret >=\
    \ MOD ? ret - MOD : ret;\n    }\n\n    static inline const auto BASE_POW = auto_realloc([](const\
    \ usize n) {\n        std::vector<u64> ret(n);\n        ret[0] = 1;\n        for\
    \ (const usize i : rep(1, n)) {\n            ret[i] = mul(ret[i - 1], BASE);\n\
    \        }\n        return ret;\n    });\n};\n\ntemplate <class T, usize ID =\
    \ 0, std::enable_if_t<std::is_integral_v<T>>* = nullptr> class PolynomialHash\
    \ {\n    using Helper = PolynomialHashHelper<ID>;\n\n    std::vector<u64> hash;\n\
    \    std::vector<T> data;\n\n  public:\n    PolynomialHash() : PolynomialHash(std::vector<T>())\
    \ {}\n    explicit PolynomialHash(const std::vector<T>& vec) : data(vec) {\n \
    \       const usize size = data.size();\n        hash = std::vector<u64>(size\
    \ + 1);\n        for (const usize i : rep(0, size)) {\n            assert(0 <=\
    \ data[i]);\n            assert((u64)data[i] < Helper::MOD);\n            hash[i\
    \ + 1] = Helper::add(Helper::mul(Helper::BASE, hash[i]), (u64)data[i]);\n    \
    \    }\n    }\n\n    usize size() const { return data.size(); }\n    const std::vector<T>&\
    \ get() const { return data; }\n\n    u64 fold() const { return hash.back(); }\n\
    \    u64 fold(const usize l, const usize r) const {\n        assert(l <= r and\
    \ r <= size());\n        return Helper::sub(hash[r], Helper::mul(hash[l], Helper::BASE_POW[r\
    \ - l]));\n    }\n\n    void concat(const PolynomialHash& other) {\n        hash.reserve(hash.size()\
    \ + other.size());\n        u64 val = hash.back();\n        for (const usize i\
    \ : rep(0, other.size())) {\n            val = Helper::mul(val, Helper::BASE);\n\
    \            hash.push_back(Helper::add(val, other.hash[i + 1]));\n        }\n\
    \        data.reserve(data.size() + other.size());\n        std::copy(other.data.cbegin(),\
    \ other.data.cend(), std::back_inserter(data));\n    }\n};\n"
  dependsOn:
  - random/rand_int.cpp
  - random/xorshift.cpp
  - utility/int_alias.cpp
  - utility/auto_realloc.cpp
  - bit/ceil_log2.cpp
  - utility/int_alias_extended.cpp
  - utility/rep.cpp
  isVerificationFile: false
  path: container/polynomial_hash.cpp
  requiredBy: []
  timestamp: '2021-11-01 21:39:08+09:00'
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
