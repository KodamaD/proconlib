---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/rem_euclid.cpp
    title: math/rem_euclid.cpp
  - icon: ':heavy_check_mark:'
    path: math/totient.cpp
    title: math/totient.cpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algorithm/convolution_arbitrary_mod.cpp
    title: algorithm/convolution_arbitrary_mod.cpp
  - icon: ':warning:'
    path: algorithm/convolution_int.cpp
    title: algorithm/convolution_int.cpp
  - icon: ':heavy_check_mark:'
    path: algorithm/convolution_mod.cpp
    title: algorithm/convolution_mod.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/and_convolution.test.cpp
    title: test/and_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/berlekamp_massey.test.cpp
    title: test/berlekamp_massey.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution_arbitrary_mod.test.cpp
    title: test/convolution_arbitrary_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution_mod.test.cpp
    title: test/convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fp_util.test.cpp
    title: test/fp_util.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/heavy_light_decomposition.test.cpp
    title: test/heavy_light_decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazy_segment_tree.test.cpp
    title: test/lazy_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/queue_aggregation.test.cpp
    title: test/queue_aggregation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment_tree.test.cpp
    title: test/segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/semiring_matrix.test.cpp
    title: test/semiring_matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/static_modint.cpp\"\n#include <ostream>\n#include <type_traits>\n\
    #line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n\nusing i32 = std::int32_t;\n\
    using u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n#line 2 \"math/rem_euclid.cpp\"\
    \n#include <cassert>\n\ntemplate <class T> constexpr T rem_euclid(T value, const\
    \ T& mod) {\n    assert(mod > 0);\n    return (value %= mod) >= 0 ? value : value\
    \ + mod;\n}\n#line 2 \"math/totient.cpp\"\n\ntemplate <class T> constexpr T totient(T\
    \ x) {\n    T ret = x;\n    for (T i = 2; i * i <= x; ++i) {\n        if (x %\
    \ i == 0) {\n            ret /= i;\n            ret *= i - 1;\n            while\
    \ (x % i == 0) x /= i;\n        }\n    }\n    if (x > 1) {\n        ret /= x;\n\
    \        ret *= x - 1;\n    }\n    return ret;\n}\n#line 7 \"math/static_modint.cpp\"\
    \n\ntemplate <u32 MOD, std::enable_if_t<((u32)1 <= MOD and MOD <= ((u32)1 << 31))>*\
    \ = nullptr> class StaticModint {\n    using Self = StaticModint;\n\n    static\
    \ inline constexpr u32 PHI = totient(MOD);\n    u32 v;\n\n  public:\n    static\
    \ constexpr u32 mod() noexcept { return MOD; }\n\n    template <class T, std::enable_if_t<std::is_integral_v<T>>*\
    \ = nullptr>\n    static constexpr T normalize(const T& x) noexcept {\n      \
    \  return rem_euclid<std::common_type_t<T, i64>>(x, MOD);\n    }\n\n    constexpr\
    \ StaticModint() noexcept : v(0) {}\n    template <class T> constexpr StaticModint(const\
    \ T& x) noexcept : v(normalize(x)) {}\n    template <class T> static constexpr\
    \ Self raw(const T& x) noexcept {\n        Self ret;\n        ret.v = x;\n   \
    \     return ret;\n    }\n\n    constexpr u32 val() const noexcept { return v;\
    \ }\n    constexpr Self neg() const noexcept { return raw(v == 0 ? 0 : MOD - v);\
    \ }\n    constexpr Self inv() const noexcept { return pow(PHI - 1); }\n    constexpr\
    \ Self pow(u64 exp) const noexcept {\n        Self ret(1), mult(*this);\n    \
    \    for (; exp > 0; exp >>= 1) {\n            if (exp & 1) ret *= mult;\n   \
    \         mult *= mult;\n        }\n        return ret;\n    }\n\n    constexpr\
    \ Self operator-() const noexcept { return neg(); }\n    constexpr Self operator~()\
    \ const noexcept { return inv(); }\n\n    constexpr Self operator+(const Self&\
    \ rhs) const noexcept { return Self(*this) += rhs; }\n    constexpr Self& operator+=(const\
    \ Self& rhs) noexcept {\n        if ((v += rhs.v) >= MOD) v -= MOD;\n        return\
    \ *this;\n    }\n\n    constexpr Self operator-(const Self& rhs) const noexcept\
    \ { return Self(*this) -= rhs; }\n    constexpr Self& operator-=(const Self& rhs)\
    \ noexcept {\n        if (v < rhs.v) v += MOD;\n        v -= rhs.v;\n        return\
    \ *this;\n    }\n\n    constexpr Self operator*(const Self& rhs) const noexcept\
    \ { return Self(*this) *= rhs; }\n    constexpr Self& operator*=(const Self& rhs)\
    \ noexcept {\n        v = (u64)v * rhs.v % MOD;\n        return *this;\n    }\n\
    \n    constexpr Self operator/(const Self& rhs) const noexcept { return Self(*this)\
    \ /= rhs; }\n    constexpr Self& operator/=(const Self& rhs) noexcept { return\
    \ *this *= rhs.inv(); }\n\n    constexpr bool operator==(const Self& rhs) const\
    \ noexcept { return v == rhs.v; }\n    constexpr bool operator!=(const Self& rhs)\
    \ const noexcept { return v != rhs.v; }\n    friend std::ostream& operator<<(std::ostream&\
    \ stream, const Self& rhs) { return stream << rhs.v; }\n};\n\nusing Modint1000000007\
    \ = StaticModint<1000000007>;\nusing Modint998244353 = StaticModint<998244353>;\n"
  code: "#pragma once\n#include <ostream>\n#include <type_traits>\n#include \"../utility/int_alias.cpp\"\
    \n#include \"rem_euclid.cpp\"\n#include \"totient.cpp\"\n\ntemplate <u32 MOD,\
    \ std::enable_if_t<((u32)1 <= MOD and MOD <= ((u32)1 << 31))>* = nullptr> class\
    \ StaticModint {\n    using Self = StaticModint;\n\n    static inline constexpr\
    \ u32 PHI = totient(MOD);\n    u32 v;\n\n  public:\n    static constexpr u32 mod()\
    \ noexcept { return MOD; }\n\n    template <class T, std::enable_if_t<std::is_integral_v<T>>*\
    \ = nullptr>\n    static constexpr T normalize(const T& x) noexcept {\n      \
    \  return rem_euclid<std::common_type_t<T, i64>>(x, MOD);\n    }\n\n    constexpr\
    \ StaticModint() noexcept : v(0) {}\n    template <class T> constexpr StaticModint(const\
    \ T& x) noexcept : v(normalize(x)) {}\n    template <class T> static constexpr\
    \ Self raw(const T& x) noexcept {\n        Self ret;\n        ret.v = x;\n   \
    \     return ret;\n    }\n\n    constexpr u32 val() const noexcept { return v;\
    \ }\n    constexpr Self neg() const noexcept { return raw(v == 0 ? 0 : MOD - v);\
    \ }\n    constexpr Self inv() const noexcept { return pow(PHI - 1); }\n    constexpr\
    \ Self pow(u64 exp) const noexcept {\n        Self ret(1), mult(*this);\n    \
    \    for (; exp > 0; exp >>= 1) {\n            if (exp & 1) ret *= mult;\n   \
    \         mult *= mult;\n        }\n        return ret;\n    }\n\n    constexpr\
    \ Self operator-() const noexcept { return neg(); }\n    constexpr Self operator~()\
    \ const noexcept { return inv(); }\n\n    constexpr Self operator+(const Self&\
    \ rhs) const noexcept { return Self(*this) += rhs; }\n    constexpr Self& operator+=(const\
    \ Self& rhs) noexcept {\n        if ((v += rhs.v) >= MOD) v -= MOD;\n        return\
    \ *this;\n    }\n\n    constexpr Self operator-(const Self& rhs) const noexcept\
    \ { return Self(*this) -= rhs; }\n    constexpr Self& operator-=(const Self& rhs)\
    \ noexcept {\n        if (v < rhs.v) v += MOD;\n        v -= rhs.v;\n        return\
    \ *this;\n    }\n\n    constexpr Self operator*(const Self& rhs) const noexcept\
    \ { return Self(*this) *= rhs; }\n    constexpr Self& operator*=(const Self& rhs)\
    \ noexcept {\n        v = (u64)v * rhs.v % MOD;\n        return *this;\n    }\n\
    \n    constexpr Self operator/(const Self& rhs) const noexcept { return Self(*this)\
    \ /= rhs; }\n    constexpr Self& operator/=(const Self& rhs) noexcept { return\
    \ *this *= rhs.inv(); }\n\n    constexpr bool operator==(const Self& rhs) const\
    \ noexcept { return v == rhs.v; }\n    constexpr bool operator!=(const Self& rhs)\
    \ const noexcept { return v != rhs.v; }\n    friend std::ostream& operator<<(std::ostream&\
    \ stream, const Self& rhs) { return stream << rhs.v; }\n};\n\nusing Modint1000000007\
    \ = StaticModint<1000000007>;\nusing Modint998244353 = StaticModint<998244353>;\n"
  dependsOn:
  - utility/int_alias.cpp
  - math/rem_euclid.cpp
  - math/totient.cpp
  isVerificationFile: false
  path: math/static_modint.cpp
  requiredBy:
  - algorithm/convolution_mod.cpp
  - algorithm/convolution_arbitrary_mod.cpp
  - algorithm/convolution_int.cpp
  timestamp: '2022-01-07 21:48:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution_arbitrary_mod.test.cpp
  - test/queue_aggregation.test.cpp
  - test/semiring_matrix.test.cpp
  - test/lazy_segment_tree.test.cpp
  - test/berlekamp_massey.test.cpp
  - test/heavy_light_decomposition.test.cpp
  - test/segment_tree.test.cpp
  - test/and_convolution.test.cpp
  - test/convolution_mod.test.cpp
  - test/fp_util.test.cpp
documentation_of: math/static_modint.cpp
layout: document
redirect_from:
- /library/math/static_modint.cpp
- /library/math/static_modint.cpp.html
title: math/static_modint.cpp
---
