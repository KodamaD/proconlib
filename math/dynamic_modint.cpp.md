---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/barret_reduction.cpp
    title: math/barret_reduction.cpp
  - icon: ':warning:'
    path: math/inv_gcd.cpp
    title: math/inv_gcd.cpp
  - icon: ':warning:'
    path: math/mod_inv.cpp
    title: math/mod_inv.cpp
  - icon: ':heavy_check_mark:'
    path: math/rem_euclid.cpp
    title: math/rem_euclid.cpp
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias_extended.cpp
    title: utility/int_alias_extended.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/dynamic_modint.cpp\"\n#include <cassert>\n#include\
    \ <ostream>\n#include <type_traits>\n#line 2 \"utility/int_alias.cpp\"\n#include\
    \ <cstddef>\n#include <cstdint>\n\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\n\
    using i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing isize = std::ptrdiff_t;\n\
    using usize = std::size_t;\n#line 4 \"utility/int_alias_extended.cpp\"\n\nusing\
    \ i8 = std::int8_t;\nusing u8 = std::uint8_t;\nusing i16 = std::int16_t;\nusing\
    \ u16 = std::uint16_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    #line 4 \"math/barret_reduction.cpp\"\n\nclass BarretReduction {\n    u32 mod;\n\
    \    u64 near_inv;\n\n  public:\n    explicit constexpr BarretReduction(const\
    \ u32 mod) noexcept : mod(mod), near_inv((u64)(-1) / mod + 1) {}\n    constexpr\
    \ u32 product(const u32 a, const u32 b) const noexcept {\n        const u64 z\
    \ = (u64)a * b;\n        const u64 x = ((u128)z * near_inv) >> 64;\n        const\
    \ u32 v = z - x * mod;\n        return v < mod ? v : v + mod;\n    }\n};\n#line\
    \ 3 \"math/inv_gcd.cpp\"\n#include <utility>\n#line 3 \"math/rem_euclid.cpp\"\n\
    \ntemplate <class T> constexpr T rem_euclid(T value, const T& mod) {\n    assert(mod\
    \ > 0);\n    return (value %= mod) >= 0 ? value : value + mod;\n}\n#line 5 \"\
    math/inv_gcd.cpp\"\n\ntemplate <class T> constexpr std::pair<T, T> inv_gcd(const\
    \ T& a, const T& b) {\n    using U = std::make_signed_t<T>;\n    U t = rem_euclid(a,\
    \ b);\n    if (t == 0) return {b, 0};\n    U s = b, m0 = 0, m1 = 1;\n    while\
    \ (t != 0) {\n        const U u = s / t;\n        s -= t * u;\n        m0 -= m1\
    \ * u;\n        U tmp = s;\n        s = t;\n        t = tmp;\n        tmp = m0;\n\
    \        m0 = m1;\n        m1 = tmp;\n    }\n    if (m0 < 0) m0 += b / s;\n  \
    \  return {(T)s, (T)m0};\n}\n#line 4 \"math/mod_inv.cpp\"\n\ntemplate <class T>\
    \ constexpr T mod_inv(const T& a, const T& mod) {\n    const auto [g, x] = inv_gcd(a,\
    \ mod);\n    assert(g == 1);\n    return x;\n}\n#line 9 \"math/dynamic_modint.cpp\"\
    \n\ntemplate <usize ID> class DynamicModint {\n    using Self = DynamicModint;\n\
    \n    static inline auto bt = BarretReduction(1);\n    u32 v;\n\n  public:\n \
    \   static u32 mod() noexcept { return bt.mod; }\n    static void set_mod(const\
    \ u32 mod) noexcept {\n        assert((u32)1 <= mod and mod <= ((u32)1 << 31));\n\
    \        bt = BarretReduction(mod);\n    }\n\n    template <class T, std::enable_if_t<std::is_integral_v<T>>*\
    \ = nullptr> static T normalize(const T& x) noexcept {\n        return rem_euclid<std::common_type_t<T,\
    \ i64>>(x, mod());\n    }\n\n    DynamicModint() noexcept : v(0) {}\n    template\
    \ <class T> DynamicModint(const T& x) noexcept : v(normalize(x)) {}\n    template\
    \ <class T> static Self raw(const T& x) noexcept {\n        Self ret;\n      \
    \  ret.v = x;\n        return ret;\n    }\n\n    u32 get() const noexcept { return\
    \ v; }\n    Self neg() const noexcept { return raw(v == 0 ? 0 : mod() - v); }\n\
    \    Self inv() const noexcept { return raw(mod_inv(v, mod())); }\n    Self pow(u64\
    \ exp) const noexcept {\n        Self ret(1), mult(*this);\n        for (; exp\
    \ > 0; exp >>= 1) {\n            if (exp & 1) ret *= mult;\n            mult *=\
    \ mult;\n        }\n        return ret;\n    }\n\n    Self operator-() const noexcept\
    \ { return neg(); }\n    Self operator~() const noexcept { return inv(); }\n\n\
    \    Self operator+(const Self& rhs) const noexcept { return Self(*this) += rhs;\
    \ }\n    Self& operator+=(const Self& rhs) noexcept {\n        if ((v += rhs.v)\
    \ >= mod()) v -= mod();\n        return *this;\n    }\n\n    Self operator-(const\
    \ Self& rhs) const noexcept { return Self(*this) -= rhs; }\n    Self& operator-=(const\
    \ Self& rhs) noexcept {\n        if (v < rhs.v) v += mod();\n        v -= rhs.v;\n\
    \        return *this;\n    }\n\n    Self operator*(const Self& rhs) const noexcept\
    \ { return Self(*this) *= rhs; }\n    Self& operator*=(const Self& rhs) noexcept\
    \ {\n        v = bt.product(v, rhs.v);\n        return *this;\n    }\n\n    Self\
    \ operator/(const Self& rhs) const noexcept { return Self(*this) /= rhs; }\n \
    \   Self& operator/=(const Self& rhs) noexcept { return *this *= rhs.inv(); }\n\
    \n    bool operator==(const Self& rhs) const noexcept { return v == rhs.v; }\n\
    \    bool operator!=(const Self& rhs) const noexcept { return v != rhs.v; }\n\
    \    friend std::ostream& operator<<(std::ostream& stream, const Self& rhs) {\
    \ return stream << rhs.v; }\n};\n\nusing Modint = DynamicModint<__COUNTER__>;\n"
  code: "#pragma once\n#include <cassert>\n#include <ostream>\n#include <type_traits>\n\
    #include \"../math/barret_reduction.cpp\"\n#include \"../math/mod_inv.cpp\"\n\
    #include \"../math/rem_euclid.cpp\"\n#include \"../utility/int_alias.cpp\"\n\n\
    template <usize ID> class DynamicModint {\n    using Self = DynamicModint;\n\n\
    \    static inline auto bt = BarretReduction(1);\n    u32 v;\n\n  public:\n  \
    \  static u32 mod() noexcept { return bt.mod; }\n    static void set_mod(const\
    \ u32 mod) noexcept {\n        assert((u32)1 <= mod and mod <= ((u32)1 << 31));\n\
    \        bt = BarretReduction(mod);\n    }\n\n    template <class T, std::enable_if_t<std::is_integral_v<T>>*\
    \ = nullptr> static T normalize(const T& x) noexcept {\n        return rem_euclid<std::common_type_t<T,\
    \ i64>>(x, mod());\n    }\n\n    DynamicModint() noexcept : v(0) {}\n    template\
    \ <class T> DynamicModint(const T& x) noexcept : v(normalize(x)) {}\n    template\
    \ <class T> static Self raw(const T& x) noexcept {\n        Self ret;\n      \
    \  ret.v = x;\n        return ret;\n    }\n\n    u32 get() const noexcept { return\
    \ v; }\n    Self neg() const noexcept { return raw(v == 0 ? 0 : mod() - v); }\n\
    \    Self inv() const noexcept { return raw(mod_inv(v, mod())); }\n    Self pow(u64\
    \ exp) const noexcept {\n        Self ret(1), mult(*this);\n        for (; exp\
    \ > 0; exp >>= 1) {\n            if (exp & 1) ret *= mult;\n            mult *=\
    \ mult;\n        }\n        return ret;\n    }\n\n    Self operator-() const noexcept\
    \ { return neg(); }\n    Self operator~() const noexcept { return inv(); }\n\n\
    \    Self operator+(const Self& rhs) const noexcept { return Self(*this) += rhs;\
    \ }\n    Self& operator+=(const Self& rhs) noexcept {\n        if ((v += rhs.v)\
    \ >= mod()) v -= mod();\n        return *this;\n    }\n\n    Self operator-(const\
    \ Self& rhs) const noexcept { return Self(*this) -= rhs; }\n    Self& operator-=(const\
    \ Self& rhs) noexcept {\n        if (v < rhs.v) v += mod();\n        v -= rhs.v;\n\
    \        return *this;\n    }\n\n    Self operator*(const Self& rhs) const noexcept\
    \ { return Self(*this) *= rhs; }\n    Self& operator*=(const Self& rhs) noexcept\
    \ {\n        v = bt.product(v, rhs.v);\n        return *this;\n    }\n\n    Self\
    \ operator/(const Self& rhs) const noexcept { return Self(*this) /= rhs; }\n \
    \   Self& operator/=(const Self& rhs) noexcept { return *this *= rhs.inv(); }\n\
    \n    bool operator==(const Self& rhs) const noexcept { return v == rhs.v; }\n\
    \    bool operator!=(const Self& rhs) const noexcept { return v != rhs.v; }\n\
    \    friend std::ostream& operator<<(std::ostream& stream, const Self& rhs) {\
    \ return stream << rhs.v; }\n};\n\nusing Modint = DynamicModint<__COUNTER__>;\n"
  dependsOn:
  - math/barret_reduction.cpp
  - utility/int_alias.cpp
  - utility/int_alias_extended.cpp
  - math/mod_inv.cpp
  - math/inv_gcd.cpp
  - math/rem_euclid.cpp
  isVerificationFile: false
  path: math/dynamic_modint.cpp
  requiredBy: []
  timestamp: '2021-11-01 18:27:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/dynamic_modint.cpp
layout: document
redirect_from:
- /library/math/dynamic_modint.cpp
- /library/math/dynamic_modint.cpp.html
title: math/dynamic_modint.cpp
---
