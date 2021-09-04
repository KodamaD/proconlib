---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/rem_euclid.cpp
    title: math/rem_euclid.cpp
  - icon: ':question:'
    path: math/totient.cpp
    title: math/totient.cpp
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/heavy_light_decomposition.test.cpp
    title: test/heavy_light_decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazy_segment_tree.test.cpp
    title: test/lazy_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/modint_util.test.cpp
    title: test/modint_util.test.cpp
  - icon: ':x:'
    path: test/queue_aggregation.test.cpp
    title: test/queue_aggregation.test.cpp
  - icon: ':x:'
    path: test/segment_tree.test.cpp
    title: test/segment_tree.test.cpp
  - icon: ':x:'
    path: test/semiring_matrix.test.cpp
    title: test/semiring_matrix.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/static_modint.cpp\"\n#include <ostream>\n#include <type_traits>\n\
    #line 2 \"math/totient.cpp\"\n\ntemplate <class T> constexpr T totient(T x) {\n\
    \    T ret = x;\n    for (T i = 2; i * i <= x; ++i) {\n        if (x % i == 0)\
    \ {\n            ret /= i;\n            ret *= i - 1;\n            while (x %\
    \ i == 0) x /= i;\n        }\n    }\n    if (x > 1) {\n        ret /= x;\n   \
    \     ret *= x - 1;\n    }\n    return ret;\n}\n#line 2 \"utility/int_alias.cpp\"\
    \n#include <cstddef>\n#include <cstdint>\n\nusing i32 = std::int32_t;\nusing u32\
    \ = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing\
    \ i128 = __int128_t;\nusing u128 = __uint128_t;\nusing isize = std::ptrdiff_t;\n\
    using usize = std::size_t;\n#line 2 \"math/rem_euclid.cpp\"\n\ntemplate <class\
    \ T> constexpr T rem_euclid(T value, const T& mod) { return (value %= mod) >=\
    \ 0 ? value : value + mod; }\n#line 7 \"math/static_modint.cpp\"\n\ntemplate <u32\
    \ MOD, std::enable_if_t<((u32)1 <= MOD and MOD <= ((u32)1 << 31))>* = nullptr>\
    \ class StaticModint {\n    using Mint = StaticModint;\n\n    static inline constexpr\
    \ u32 PHI = totient(MOD);\n    u32 v;\n\n  public:\n    static constexpr u32 mod()\
    \ noexcept { return MOD; }\n\n    template <class T, std::enable_if_t<std::is_signed_v<T>\
    \ and std::is_integral_v<T>>* = nullptr>\n    static constexpr T normalize(const\
    \ T x) noexcept {\n        return rem_euclid<std::common_type_t<T, i64>>(x, MOD);\n\
    \    }\n    template <class T, std::enable_if_t<std::is_unsigned_v<T> and std::is_integral_v<T>>*\
    \ = nullptr>\n    static constexpr T normalize(const T x) noexcept {\n       \
    \ return x % MOD;\n    }\n\n    constexpr StaticModint() noexcept : v(0) {}\n\
    \    template <class T> constexpr StaticModint(const T x) noexcept : v(normalize(x))\
    \ {}\n    template <class T> static constexpr Mint raw(const T x) noexcept {\n\
    \        Mint ret;\n        ret.v = x;\n        return ret;\n    }\n\n    constexpr\
    \ u32 get() const noexcept { return v; }\n    constexpr Mint neg() const noexcept\
    \ { return raw(v == 0 ? 0 : MOD - v); }\n    constexpr Mint inv() const noexcept\
    \ { return pow(PHI - 1); }\n    constexpr Mint pow(u64 exp) const noexcept {\n\
    \        Mint ret(1), mult(*this);\n        for (; exp > 0; exp >>= 1) {\n   \
    \         if (exp & 1) ret *= mult;\n            mult *= mult;\n        }\n  \
    \      return ret;\n    }\n\n    constexpr Mint operator-() const noexcept { return\
    \ neg(); }\n    constexpr Mint operator~() const noexcept { return inv(); }\n\n\
    \    constexpr Mint operator+(const Mint& rhs) const noexcept { return Mint(*this)\
    \ += rhs; }\n    constexpr Mint& operator+=(const Mint& rhs) noexcept {\n    \
    \    if ((v += rhs.v) >= MOD) v -= MOD;\n        return *this;\n    }\n\n    constexpr\
    \ Mint operator-(const Mint& rhs) const noexcept { return Mint(*this) -= rhs;\
    \ }\n    constexpr Mint& operator-=(const Mint& rhs) noexcept {\n        if (v\
    \ < rhs.v) v += MOD;\n        v -= rhs.v;\n        return *this;\n    }\n\n  \
    \  constexpr Mint operator*(const Mint& rhs) const noexcept { return Mint(*this)\
    \ *= rhs; }\n    constexpr Mint& operator*=(const Mint& rhs) noexcept {\n    \
    \    v = (u64)v * rhs.v % MOD;\n        return *this;\n    }\n\n    constexpr\
    \ Mint operator/(const Mint& rhs) const noexcept { return Mint(*this) /= rhs;\
    \ }\n    constexpr Mint& operator/=(const Mint& rhs) noexcept { return *this *=\
    \ rhs.inv(); }\n\n    constexpr bool operator==(const Mint& rhs) const noexcept\
    \ { return v == rhs.v; }\n    constexpr bool operator!=(const Mint& rhs) const\
    \ noexcept { return v != rhs.v; }\n    friend std::ostream& operator<<(std::ostream&\
    \ stream, const Mint& rhs) { return stream << rhs.v; }\n};\n\nusing Modint1000000007\
    \ = StaticModint<1000000007>;\nusing Modint998244353 = StaticModint<998244353>;\n"
  code: "#pragma once\n#include <ostream>\n#include <type_traits>\n#include \"../math/totient.cpp\"\
    \n#include \"../utility/int_alias.cpp\"\n#include \"rem_euclid.cpp\"\n\ntemplate\
    \ <u32 MOD, std::enable_if_t<((u32)1 <= MOD and MOD <= ((u32)1 << 31))>* = nullptr>\
    \ class StaticModint {\n    using Mint = StaticModint;\n\n    static inline constexpr\
    \ u32 PHI = totient(MOD);\n    u32 v;\n\n  public:\n    static constexpr u32 mod()\
    \ noexcept { return MOD; }\n\n    template <class T, std::enable_if_t<std::is_signed_v<T>\
    \ and std::is_integral_v<T>>* = nullptr>\n    static constexpr T normalize(const\
    \ T x) noexcept {\n        return rem_euclid<std::common_type_t<T, i64>>(x, MOD);\n\
    \    }\n    template <class T, std::enable_if_t<std::is_unsigned_v<T> and std::is_integral_v<T>>*\
    \ = nullptr>\n    static constexpr T normalize(const T x) noexcept {\n       \
    \ return x % MOD;\n    }\n\n    constexpr StaticModint() noexcept : v(0) {}\n\
    \    template <class T> constexpr StaticModint(const T x) noexcept : v(normalize(x))\
    \ {}\n    template <class T> static constexpr Mint raw(const T x) noexcept {\n\
    \        Mint ret;\n        ret.v = x;\n        return ret;\n    }\n\n    constexpr\
    \ u32 get() const noexcept { return v; }\n    constexpr Mint neg() const noexcept\
    \ { return raw(v == 0 ? 0 : MOD - v); }\n    constexpr Mint inv() const noexcept\
    \ { return pow(PHI - 1); }\n    constexpr Mint pow(u64 exp) const noexcept {\n\
    \        Mint ret(1), mult(*this);\n        for (; exp > 0; exp >>= 1) {\n   \
    \         if (exp & 1) ret *= mult;\n            mult *= mult;\n        }\n  \
    \      return ret;\n    }\n\n    constexpr Mint operator-() const noexcept { return\
    \ neg(); }\n    constexpr Mint operator~() const noexcept { return inv(); }\n\n\
    \    constexpr Mint operator+(const Mint& rhs) const noexcept { return Mint(*this)\
    \ += rhs; }\n    constexpr Mint& operator+=(const Mint& rhs) noexcept {\n    \
    \    if ((v += rhs.v) >= MOD) v -= MOD;\n        return *this;\n    }\n\n    constexpr\
    \ Mint operator-(const Mint& rhs) const noexcept { return Mint(*this) -= rhs;\
    \ }\n    constexpr Mint& operator-=(const Mint& rhs) noexcept {\n        if (v\
    \ < rhs.v) v += MOD;\n        v -= rhs.v;\n        return *this;\n    }\n\n  \
    \  constexpr Mint operator*(const Mint& rhs) const noexcept { return Mint(*this)\
    \ *= rhs; }\n    constexpr Mint& operator*=(const Mint& rhs) noexcept {\n    \
    \    v = (u64)v * rhs.v % MOD;\n        return *this;\n    }\n\n    constexpr\
    \ Mint operator/(const Mint& rhs) const noexcept { return Mint(*this) /= rhs;\
    \ }\n    constexpr Mint& operator/=(const Mint& rhs) noexcept { return *this *=\
    \ rhs.inv(); }\n\n    constexpr bool operator==(const Mint& rhs) const noexcept\
    \ { return v == rhs.v; }\n    constexpr bool operator!=(const Mint& rhs) const\
    \ noexcept { return v != rhs.v; }\n    friend std::ostream& operator<<(std::ostream&\
    \ stream, const Mint& rhs) { return stream << rhs.v; }\n};\n\nusing Modint1000000007\
    \ = StaticModint<1000000007>;\nusing Modint998244353 = StaticModint<998244353>;\n"
  dependsOn:
  - math/totient.cpp
  - utility/int_alias.cpp
  - math/rem_euclid.cpp
  isVerificationFile: false
  path: math/static_modint.cpp
  requiredBy: []
  timestamp: '2021-09-04 17:30:23+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/segment_tree.test.cpp
  - test/semiring_matrix.test.cpp
  - test/queue_aggregation.test.cpp
  - test/modint_util.test.cpp
  - test/heavy_light_decomposition.test.cpp
  - test/lazy_segment_tree.test.cpp
documentation_of: math/static_modint.cpp
layout: document
redirect_from:
- /library/math/static_modint.cpp
- /library/math/static_modint.cpp.html
title: math/static_modint.cpp
---
