---
data:
  _extendedDependsOn:
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
    using isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 2 \"math/rem_euclid.cpp\"\
    \n\ntemplate <class T>\nconstexpr T rem_euclid(T value, const T& mod) {\n    return\
    \ (value %= mod) >= 0 ? value : value + mod;\n}\n#line 2 \"math/inv_gcd.cpp\"\n\
    #include <utility>\n#include <type_traits>\n\ntemplate <class T>\nconstexpr std::pair<T,\
    \ T> inv_gcd(const T& a, const T& b) {\n    using U = std::make_signed_t<T>;\n\
    \    U t = rem_euclid(a, b);\n    if (t == 0) return { b, 0 };\n    U s = b, m0\
    \ = 0, m1 = 1;\n    while (t != 0) {\n        const U u = s / t;\n        s -=\
    \ t * u;\n        m0 -= m1 * u;\n        U tmp = s;\n        s = t;\n        t\
    \ = tmp;\n        tmp = m0;\n        m0 = m1;\n        m1 = tmp;\n    }\n    if\
    \ (m0 < 0) m0 += b / s;\n    return { (T) s, (T) m0 };\n}\n#line 3 \"math/mod_inv.cpp\"\
    \n#include <cassert>\n\ntemplate <class T>\nconstexpr T mod_inv(const T& a, const\
    \ T& mod) {\n    const auto [g, x] = inv_gcd(a, mod);\n    assert(g == 1);\n \
    \   return x;\n}\n#line 6 \"math/dynamic_modint.cpp\"\n#include <ostream>\n#line\
    \ 8 \"math/dynamic_modint.cpp\"\n\ntemplate <usize ID>\nclass DynamicModint {\n\
    \    using Mint = DynamicModint;\n\n    struct Barret {\n        u32 mod;\n  \
    \      u64 near_inv;\n        explicit Barret(const u32 mod) noexcept: mod(mod),\
    \ near_inv((u64) (-1) / mod + 1) { }\n        u32 product(const u32 a, const u32\
    \ b) const noexcept {\n            const u64 z = (u64) a * b;\n            const\
    \ u64 x = ((u128) z * near_inv) >> 64;\n            const u32 v = z - x * mod;\n\
    \            return v < mod ? v : v + mod;\n        }\n    };\n\n    static inline\
    \ auto bt = Barret(1);\n    u32 v;\n\npublic:\n    static u32 mod() noexcept {\
    \ return bt.mod; }\n    static void set_mod(const u32 mod) noexcept {\n      \
    \  assert((u32) 1 <= mod and mod <= ((u32) 1 << 31));\n        bt = Barret(mod);\n\
    \    }\n\n    template <class T, std::enable_if_t<std::is_signed_v<T> and std::is_integral_v<T>>*\
    \ = nullptr>\n    static T normalize(const T x) noexcept { return rem_euclid<std::common_type_t<T,\
    \ i64>>(x, mod()); }\n    template <class T, std::enable_if_t<std::is_unsigned_v<T>\
    \ and std::is_integral_v<T>>* = nullptr>\n    static T normalize(const T x) noexcept\
    \ { return x % mod(); }\n\n    DynamicModint() noexcept: v(0) { }\n    template\
    \ <class T>\n    explicit DynamicModint(const T x) noexcept: v(normalize(x)) {\
    \ }\n    template <class T>\n    static Mint raw(const T x) noexcept {\n     \
    \   Mint ret;\n        ret.v = x;\n        return ret;\n    }\n\n    u32 get()\
    \ const noexcept { return v; }\n    Mint neg() const noexcept { return raw(v ==\
    \ 0 ? 0 : mod() - v); }\n    Mint inv() const noexcept { return raw(mod_inv(v,\
    \ mod())); }\n    Mint pow(u64 exp) const noexcept {\n        Mint ret(1), mult(*this);\n\
    \        for (; exp > 0; exp >>= 1) {\n            if (exp & 1) ret *= mult;\n\
    \            mult *= mult;\n        }\n        return ret;\n    }\n\n    Mint\
    \ operator - () const noexcept { return neg(); }\n    Mint operator ~ () const\
    \ noexcept { return inv(); }\n\n    Mint operator + (const Mint& rhs) const noexcept\
    \ { return Mint(*this) += rhs; }\n    Mint& operator += (const Mint& rhs) noexcept\
    \ {\n        if ((v += rhs.v) >= mod()) v -= mod();\n        return *this;\n \
    \   }\n    \n    Mint operator - (const Mint& rhs) const noexcept { return Mint(*this)\
    \ -= rhs; }\n    Mint& operator -= (const Mint& rhs) noexcept {\n        if (v\
    \ < rhs.v) v += mod();\n        v -= rhs.v;\n        return *this;\n    }\n\n\
    \    Mint operator * (const Mint& rhs) const noexcept { return Mint(*this) *=\
    \ rhs; }\n    Mint& operator *= (const Mint& rhs) noexcept {\n        v = bt.product(v,\
    \ rhs.v);\n        return *this;\n    }\n\n    Mint operator / (const Mint& rhs)\
    \ const noexcept { return Mint(*this) /= rhs; }\n    Mint& operator /= (const\
    \ Mint& rhs) noexcept { \n        return *this *= rhs.inv();\n    }\n\n    bool\
    \ operator == (const Mint& rhs) const noexcept { return v == rhs.v; }\n    bool\
    \ operator != (const Mint& rhs) const noexcept { return v != rhs.v; }\n    friend\
    \ std::ostream& operator << (std::ostream& stream, const Mint& rhs) { \n     \
    \   return stream << rhs.v;\n    }\n};\n"
  code: "#pragma once\n#include \"../utility/int_alias.cpp\"\n#include \"rem_euclid.cpp\"\
    \n#include \"mod_inv.cpp\"\n#include <type_traits>\n#include <ostream>\n#include\
    \ <cassert>\n\ntemplate <usize ID>\nclass DynamicModint {\n    using Mint = DynamicModint;\n\
    \n    struct Barret {\n        u32 mod;\n        u64 near_inv;\n        explicit\
    \ Barret(const u32 mod) noexcept: mod(mod), near_inv((u64) (-1) / mod + 1) { }\n\
    \        u32 product(const u32 a, const u32 b) const noexcept {\n            const\
    \ u64 z = (u64) a * b;\n            const u64 x = ((u128) z * near_inv) >> 64;\n\
    \            const u32 v = z - x * mod;\n            return v < mod ? v : v +\
    \ mod;\n        }\n    };\n\n    static inline auto bt = Barret(1);\n    u32 v;\n\
    \npublic:\n    static u32 mod() noexcept { return bt.mod; }\n    static void set_mod(const\
    \ u32 mod) noexcept {\n        assert((u32) 1 <= mod and mod <= ((u32) 1 << 31));\n\
    \        bt = Barret(mod);\n    }\n\n    template <class T, std::enable_if_t<std::is_signed_v<T>\
    \ and std::is_integral_v<T>>* = nullptr>\n    static T normalize(const T x) noexcept\
    \ { return rem_euclid<std::common_type_t<T, i64>>(x, mod()); }\n    template <class\
    \ T, std::enable_if_t<std::is_unsigned_v<T> and std::is_integral_v<T>>* = nullptr>\n\
    \    static T normalize(const T x) noexcept { return x % mod(); }\n\n    DynamicModint()\
    \ noexcept: v(0) { }\n    template <class T>\n    explicit DynamicModint(const\
    \ T x) noexcept: v(normalize(x)) { }\n    template <class T>\n    static Mint\
    \ raw(const T x) noexcept {\n        Mint ret;\n        ret.v = x;\n        return\
    \ ret;\n    }\n\n    u32 get() const noexcept { return v; }\n    Mint neg() const\
    \ noexcept { return raw(v == 0 ? 0 : mod() - v); }\n    Mint inv() const noexcept\
    \ { return raw(mod_inv(v, mod())); }\n    Mint pow(u64 exp) const noexcept {\n\
    \        Mint ret(1), mult(*this);\n        for (; exp > 0; exp >>= 1) {\n   \
    \         if (exp & 1) ret *= mult;\n            mult *= mult;\n        }\n  \
    \      return ret;\n    }\n\n    Mint operator - () const noexcept { return neg();\
    \ }\n    Mint operator ~ () const noexcept { return inv(); }\n\n    Mint operator\
    \ + (const Mint& rhs) const noexcept { return Mint(*this) += rhs; }\n    Mint&\
    \ operator += (const Mint& rhs) noexcept {\n        if ((v += rhs.v) >= mod())\
    \ v -= mod();\n        return *this;\n    }\n    \n    Mint operator - (const\
    \ Mint& rhs) const noexcept { return Mint(*this) -= rhs; }\n    Mint& operator\
    \ -= (const Mint& rhs) noexcept {\n        if (v < rhs.v) v += mod();\n      \
    \  v -= rhs.v;\n        return *this;\n    }\n\n    Mint operator * (const Mint&\
    \ rhs) const noexcept { return Mint(*this) *= rhs; }\n    Mint& operator *= (const\
    \ Mint& rhs) noexcept {\n        v = bt.product(v, rhs.v);\n        return *this;\n\
    \    }\n\n    Mint operator / (const Mint& rhs) const noexcept { return Mint(*this)\
    \ /= rhs; }\n    Mint& operator /= (const Mint& rhs) noexcept { \n        return\
    \ *this *= rhs.inv();\n    }\n\n    bool operator == (const Mint& rhs) const noexcept\
    \ { return v == rhs.v; }\n    bool operator != (const Mint& rhs) const noexcept\
    \ { return v != rhs.v; }\n    friend std::ostream& operator << (std::ostream&\
    \ stream, const Mint& rhs) { \n        return stream << rhs.v;\n    }\n};\n"
  dependsOn:
  - utility/int_alias.cpp
  - math/rem_euclid.cpp
  - math/mod_inv.cpp
  - math/inv_gcd.cpp
  isVerificationFile: false
  path: math/dynamic_modint.cpp
  requiredBy: []
  timestamp: '2021-04-02 12:34:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/dynamic_modint.cpp
layout: document
redirect_from:
- /library/math/dynamic_modint.cpp
- /library/math/dynamic_modint.cpp.html
title: math/dynamic_modint.cpp
---
