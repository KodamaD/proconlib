---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/berlekamp_massey.cpp
    title: algorithm/berlekamp_massey.cpp
  - icon: ':heavy_check_mark:'
    path: math/rem_euclid.cpp
    title: math/rem_euclid.cpp
  - icon: ':heavy_check_mark:'
    path: math/static_modint.cpp
    title: math/static_modint.cpp
  - icon: ':heavy_check_mark:'
    path: math/totient.cpp
    title: math/totient.cpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':heavy_check_mark:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/find_linear_recurrence
    links:
    - https://judge.yosupo.jp/problem/find_linear_recurrence
  bundledCode: "#line 1 \"test/berlekamp_massey.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/find_linear_recurrence\"\
    \n#include <iostream>\n#include <vector>\n#line 2 \"utility/int_alias.cpp\"\n\
    #include <cstddef>\n#include <cstdint>\n\nusing i32 = std::int32_t;\nusing u32\
    \ = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing\
    \ isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 2 \"utility/rep.cpp\"\
    \n#include <algorithm>\n#line 4 \"utility/rep.cpp\"\n\nclass rep {\n    struct\
    \ Iter {\n        usize itr;\n        constexpr Iter(const usize pos) noexcept\
    \ : itr(pos) {}\n        constexpr void operator++() noexcept { ++itr; }\n   \
    \     constexpr bool operator!=(const Iter& other) const noexcept { return itr\
    \ != other.itr; }\n        constexpr usize operator*() const noexcept { return\
    \ itr; }\n    };\n    const Iter first, last;\n\n  public:\n    explicit constexpr\
    \ rep(const usize first, const usize last) noexcept : first(first), last(std::max(first,\
    \ last)) {}\n    constexpr Iter begin() const noexcept { return first; }\n   \
    \ constexpr Iter end() const noexcept { return last; }\n};\n#line 5 \"algorithm/berlekamp_massey.cpp\"\
    \n\ntemplate <class T> std::vector<T> berlekamp_massey(const std::vector<T>& a)\
    \ {\n    const usize n = a.size();\n    std::vector<T> c = {T(-1)}, c2 = {T(0)};\n\
    \    T r2 = 1;\n    usize i2 = 0;\n    for (const usize i : rep(0, n)) {\n   \
    \     T r = 0;\n        const usize d = c.size();\n        for (const usize j\
    \ : rep(0, d)) r += c[j] * a[i - j];\n        if (r == T(0)) continue;\n     \
    \   T coeff = -r / r2;\n        const usize d2 = c2.size(), shift = i - i2 + 1;\n\
    \        if (d2 + shift <= d) {\n            for (const usize j : rep(0, d2))\
    \ c[j + shift] += c2[j] * coeff;\n        } else {\n            std::vector<T>\
    \ tmp = c;\n            c.resize(d2 + shift);\n            for (const usize j\
    \ : rep(0, d2)) c[j + shift] += c2[j] * coeff;\n            c2 = std::move(tmp);\n\
    \            i2 = i + 1;\n            r2 = r;\n        }\n    }\n    c.erase(c.begin());\n\
    \    return c;\n}\n#line 2 \"math/static_modint.cpp\"\n#include <ostream>\n#include\
    \ <type_traits>\n#line 2 \"math/rem_euclid.cpp\"\n#include <cassert>\n\ntemplate\
    \ <class T> constexpr T rem_euclid(T value, const T& mod) {\n    assert(mod >\
    \ 0);\n    return (value %= mod) >= 0 ? value : value + mod;\n}\n#line 2 \"math/totient.cpp\"\
    \n\ntemplate <class T> constexpr T totient(T x) {\n    T ret = x;\n    for (T\
    \ i = 2; i * i <= x; ++i) {\n        if (x % i == 0) {\n            ret /= i;\n\
    \            ret *= i - 1;\n            while (x % i == 0) x /= i;\n        }\n\
    \    }\n    if (x > 1) {\n        ret /= x;\n        ret *= x - 1;\n    }\n  \
    \  return ret;\n}\n#line 7 \"math/static_modint.cpp\"\n\ntemplate <u32 MOD, std::enable_if_t<((u32)1\
    \ <= MOD and MOD <= ((u32)1 << 31))>* = nullptr> class StaticModint {\n    using\
    \ Self = StaticModint;\n\n    static inline constexpr u32 PHI = totient(MOD);\n\
    \    u32 v;\n\n  public:\n    static constexpr u32 mod() noexcept { return MOD;\
    \ }\n\n    template <class T, std::enable_if_t<std::is_integral_v<T>>* = nullptr>\n\
    \    static constexpr T normalize(const T& x) noexcept {\n        return rem_euclid<std::common_type_t<T,\
    \ i64>>(x, MOD);\n    }\n\n    constexpr StaticModint() noexcept : v(0) {}\n \
    \   template <class T> constexpr StaticModint(const T& x) noexcept : v(normalize(x))\
    \ {}\n    template <class T> static constexpr Self raw(const T& x) noexcept {\n\
    \        Self ret;\n        ret.v = x;\n        return ret;\n    }\n\n    constexpr\
    \ u32 val() const noexcept { return v; }\n    constexpr Self neg() const noexcept\
    \ { return raw(v == 0 ? 0 : MOD - v); }\n    constexpr Self inv() const noexcept\
    \ { return pow(PHI - 1); }\n    constexpr Self pow(u64 exp) const noexcept {\n\
    \        Self ret(1), mult(*this);\n        for (; exp > 0; exp >>= 1) {\n   \
    \         if (exp & 1) ret *= mult;\n            mult *= mult;\n        }\n  \
    \      return ret;\n    }\n\n    constexpr Self operator-() const noexcept { return\
    \ neg(); }\n    constexpr Self operator~() const noexcept { return inv(); }\n\n\
    \    constexpr Self operator+(const Self& rhs) const noexcept { return Self(*this)\
    \ += rhs; }\n    constexpr Self& operator+=(const Self& rhs) noexcept {\n    \
    \    if ((v += rhs.v) >= MOD) v -= MOD;\n        return *this;\n    }\n\n    constexpr\
    \ Self operator-(const Self& rhs) const noexcept { return Self(*this) -= rhs;\
    \ }\n    constexpr Self& operator-=(const Self& rhs) noexcept {\n        if (v\
    \ < rhs.v) v += MOD;\n        v -= rhs.v;\n        return *this;\n    }\n\n  \
    \  constexpr Self operator*(const Self& rhs) const noexcept { return Self(*this)\
    \ *= rhs; }\n    constexpr Self& operator*=(const Self& rhs) noexcept {\n    \
    \    v = (u64)v * rhs.v % MOD;\n        return *this;\n    }\n\n    constexpr\
    \ Self operator/(const Self& rhs) const noexcept { return Self(*this) /= rhs;\
    \ }\n    constexpr Self& operator/=(const Self& rhs) noexcept { return *this *=\
    \ rhs.inv(); }\n\n    constexpr bool operator==(const Self& rhs) const noexcept\
    \ { return v == rhs.v; }\n    constexpr bool operator!=(const Self& rhs) const\
    \ noexcept { return v != rhs.v; }\n    friend std::ostream& operator<<(std::ostream&\
    \ stream, const Self& rhs) { return stream << rhs.v; }\n};\n\nusing Modint1000000007\
    \ = StaticModint<1000000007>;\nusing Modint998244353 = StaticModint<998244353>;\n\
    #line 7 \"test/berlekamp_massey.test.cpp\"\n\nusing Fp = Modint998244353;\n\n\
    int main() { \n    usize n;\n    std::cin >> n;\n    std::vector<Fp> a(n);\n \
    \   for (auto& x : a) {\n        u32 t;\n        std::cin >> t;\n        x = t;\n\
    \    }\n    const auto c = berlekamp_massey(a);\n    std::cout << c.size() <<\
    \ '\\n';\n    for (const usize i : rep(0, c.size())) {\n        std::cout << c[i]\
    \ << \" \\n\"[i + 1 == c.size()];\n    }\n    return 0; \n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/find_linear_recurrence\"\
    \n#include <iostream>\n#include <vector>\n#include \"../algorithm/berlekamp_massey.cpp\"\
    \n#include \"../math/static_modint.cpp\"\n#include \"../utility/int_alias.cpp\"\
    \n\nusing Fp = Modint998244353;\n\nint main() { \n    usize n;\n    std::cin >>\
    \ n;\n    std::vector<Fp> a(n);\n    for (auto& x : a) {\n        u32 t;\n   \
    \     std::cin >> t;\n        x = t;\n    }\n    const auto c = berlekamp_massey(a);\n\
    \    std::cout << c.size() << '\\n';\n    for (const usize i : rep(0, c.size()))\
    \ {\n        std::cout << c[i] << \" \\n\"[i + 1 == c.size()];\n    }\n    return\
    \ 0; \n}"
  dependsOn:
  - algorithm/berlekamp_massey.cpp
  - utility/int_alias.cpp
  - utility/rep.cpp
  - math/static_modint.cpp
  - math/rem_euclid.cpp
  - math/totient.cpp
  isVerificationFile: true
  path: test/berlekamp_massey.test.cpp
  requiredBy: []
  timestamp: '2021-11-04 19:10:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/berlekamp_massey.test.cpp
layout: document
redirect_from:
- /verify/test/berlekamp_massey.test.cpp
- /verify/test/berlekamp_massey.test.cpp.html
title: test/berlekamp_massey.test.cpp
---
