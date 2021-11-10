---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/and_convolution.cpp
    title: algorithm/and_convolution.cpp
  - icon: ':heavy_check_mark:'
    path: algorithm/superset_mobius_transform.cpp
    title: algorithm/superset_mobius_transform.cpp
  - icon: ':heavy_check_mark:'
    path: algorithm/superset_zeta_transform.cpp
    title: algorithm/superset_zeta_transform.cpp
  - icon: ':question:'
    path: math/rem_euclid.cpp
    title: math/rem_euclid.cpp
  - icon: ':question:'
    path: math/static_modint.cpp
    title: math/static_modint.cpp
  - icon: ':question:'
    path: math/totient.cpp
    title: math/totient.cpp
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':question:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_and_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_and_convolution
  bundledCode: "#line 1 \"test/and_convolution.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\
    \n#line 2 \"algorithm/and_convolution.cpp\"\n#include <vector>\n#include <cassert>\n\
    #line 2 \"utility/int_alias.cpp\"\n#include <cstddef>\n#include <cstdint>\n\n\
    using i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing isize = std::ptrdiff_t;\nusing usize = std::size_t;\n\
    #line 2 \"utility/rep.cpp\"\n#include <algorithm>\n#line 4 \"utility/rep.cpp\"\
    \n\nclass rep {\n    struct Iter {\n        usize itr;\n        constexpr Iter(const\
    \ usize pos) noexcept : itr(pos) {}\n        constexpr void operator++() noexcept\
    \ { ++itr; }\n        constexpr bool operator!=(const Iter& other) const noexcept\
    \ { return itr != other.itr; }\n        constexpr usize operator*() const noexcept\
    \ { return itr; }\n    };\n    const Iter first, last;\n\n  public:\n    explicit\
    \ constexpr rep(const usize first, const usize last) noexcept : first(first),\
    \ last(std::max(first, last)) {}\n    constexpr Iter begin() const noexcept {\
    \ return first; }\n    constexpr Iter end() const noexcept { return last; }\n\
    };\n#line 6 \"algorithm/superset_zeta_transform.cpp\"\n\ntemplate <class T> void\
    \ superset_zeta_transform(std::vector<T>& f) {\n    const usize n = f.size();\n\
    \    assert((n & (n - 1)) == 0);\n    for (usize i = 1; i < n; i <<= 1) {\n  \
    \      for (const usize j : rep(0, n)) {\n            if (j & i) f[j & ~i] +=\
    \ f[j];\n        }\n    }\n}\n#line 6 \"algorithm/superset_mobius_transform.cpp\"\
    \n\ntemplate <class T> void superset_mobius_transform(std::vector<T>& f) {\n \
    \   const usize n = f.size();\n    assert((n & (n - 1)) == 0);\n    for (usize\
    \ i = n; i >>= 1;) {\n        for (const usize j : rep(0, n)) {\n            if\
    \ (j & i) f[j & ~i] -= f[j];\n        }\n    }\n}\n#line 8 \"algorithm/and_convolution.cpp\"\
    \n\ntemplate <class T> std::vector<T> and_convolution(std::vector<T> a, std::vector<T>\
    \ b) {\n    assert(a.size() == b.size());\n    superset_zeta_transform(a);\n \
    \   superset_zeta_transform(b);\n    for (const usize i : rep(0, a.size())) a[i]\
    \ *= b[i];\n    superset_mobius_transform(a);\n    return a;\n}\n#line 2 \"math/static_modint.cpp\"\
    \n#include <ostream>\n#include <type_traits>\n#line 3 \"math/rem_euclid.cpp\"\n\
    \ntemplate <class T> constexpr T rem_euclid(T value, const T& mod) {\n    assert(mod\
    \ > 0);\n    return (value %= mod) >= 0 ? value : value + mod;\n}\n#line 2 \"\
    math/totient.cpp\"\n\ntemplate <class T> constexpr T totient(T x) {\n    T ret\
    \ = x;\n    for (T i = 2; i * i <= x; ++i) {\n        if (x % i == 0) {\n    \
    \        ret /= i;\n            ret *= i - 1;\n            while (x % i == 0)\
    \ x /= i;\n        }\n    }\n    if (x > 1) {\n        ret /= x;\n        ret\
    \ *= x - 1;\n    }\n    return ret;\n}\n#line 7 \"math/static_modint.cpp\"\n\n\
    template <u32 MOD, std::enable_if_t<((u32)1 <= MOD and MOD <= ((u32)1 << 31))>*\
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
    \ = StaticModint<1000000007>;\nusing Modint998244353 = StaticModint<998244353>;\n\
    #line 4 \"test/and_convolution.test.cpp\"\n#include <iostream>\n#line 6 \"test/and_convolution.test.cpp\"\
    \n\nusing Fp = Modint998244353;\n\nint main() {\n    usize N;\n    std::cin >>\
    \ N;\n    N = 1 << N;\n    std::vector<Fp> A(N), B(N);\n    for (auto& x : A)\
    \ {\n        u32 t;\n        std::cin >> t;\n        x = t;\n    }\n    for (auto&\
    \ x : B) {\n        u32 t;\n        std::cin >> t;\n        x = t;\n    }\n  \
    \  const auto C = and_convolution(A, B);\n    for (const auto i : rep(0, N)) {\n\
    \        std::cout << C[i] << \" \\n\"[i + 1 == N];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\
    \n#include \"../algorithm/and_convolution.cpp\"\n#include \"../math/static_modint.cpp\"\
    \n#include <iostream>\n#include <vector>\n\nusing Fp = Modint998244353;\n\nint\
    \ main() {\n    usize N;\n    std::cin >> N;\n    N = 1 << N;\n    std::vector<Fp>\
    \ A(N), B(N);\n    for (auto& x : A) {\n        u32 t;\n        std::cin >> t;\n\
    \        x = t;\n    }\n    for (auto& x : B) {\n        u32 t;\n        std::cin\
    \ >> t;\n        x = t;\n    }\n    const auto C = and_convolution(A, B);\n  \
    \  for (const auto i : rep(0, N)) {\n        std::cout << C[i] << \" \\n\"[i +\
    \ 1 == N];\n    }\n}"
  dependsOn:
  - algorithm/and_convolution.cpp
  - utility/int_alias.cpp
  - utility/rep.cpp
  - algorithm/superset_zeta_transform.cpp
  - algorithm/superset_mobius_transform.cpp
  - math/static_modint.cpp
  - math/rem_euclid.cpp
  - math/totient.cpp
  isVerificationFile: true
  path: test/and_convolution.test.cpp
  requiredBy: []
  timestamp: '2021-11-10 20:31:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/and_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/and_convolution.test.cpp
- /verify/test/and_convolution.test.cpp.html
title: test/and_convolution.test.cpp
---
