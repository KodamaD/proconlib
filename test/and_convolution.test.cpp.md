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
  - icon: ':heavy_check_mark:'
    path: math/factorize_iter.cpp
    title: math/factorize_iter.cpp
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
    path: traits/sum_group.cpp
    title: traits/sum_group.cpp
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
    \n#line 2 \"algorithm/and_convolution.cpp\"\n#include <cassert>\n#include <vector>\n\
    #line 2 \"traits/sum_group.cpp\"\n\ntemplate <class T> struct SumGroup {\n   \
    \ using Type = T;\n    static constexpr T identity() { return T(0); }\n    static\
    \ constexpr T operation(const T& l, const T& r) { return l + r; }\n    static\
    \ constexpr T inverse(const T& x) { return -x; }\n};\n#line 2 \"utility/rep.cpp\"\
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
    \ { return Range(0, n); }\n#line 5 \"algorithm/superset_mobius_transform.cpp\"\
    \n\ntemplate <class G> void superset_mobius_transform(std::vector<typename G::Type>&\
    \ f) {\n    const int n = f.size();\n    assert((n & (n - 1)) == 0);\n    for\
    \ (int i = n; i >>= 1;)\n        for (const int j : rep(n))\n            if (j\
    \ & i) f[j & ~i] = G::operation(f[j & ~i], G::inverse(f[j]));\n}\n#line 5 \"algorithm/superset_zeta_transform.cpp\"\
    \n\ntemplate <class S> void superset_zeta_transform(std::vector<typename S::Type>&\
    \ f) {\n    const int n = f.size();\n    assert((n & (n - 1)) == 0);\n    for\
    \ (int i = 1; i < n; i <<= 1)\n        for (const int j : rep(n))\n          \
    \  if (j & i) f[j & ~i] = S::operation(f[j & ~i], f[j]);\n}\n#line 8 \"algorithm/and_convolution.cpp\"\
    \n\ntemplate <class T> std::vector<T> and_convolution(std::vector<T> a, std::vector<T>\
    \ b) {\n    assert(a.size() == b.size());\n    superset_zeta_transform<SumGroup<T>>(a);\n\
    \    superset_zeta_transform<SumGroup<T>>(b);\n    for (const int i : rep(a.size()))\
    \ a[i] *= b[i];\n    superset_mobius_transform<SumGroup<T>>(a);\n    return a;\n\
    }\n#line 2 \"math/static_modint.cpp\"\n#include <ostream>\n#include <type_traits>\n\
    #line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n\nusing i32 = std::int32_t;\n\
    using u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n#line 3 \"math/rem_euclid.cpp\"\
    \n\ntemplate <class T> constexpr T rem_euclid(T value, const T& mod) {\n    assert(mod\
    \ > 0);\n    return (value %= mod) >= 0 ? value : value + mod;\n}\n#line 3 \"\
    math/factorize_iter.cpp\"\n#include <utility>\n#include <variant>\n\ntemplate\
    \ <class T> class Factorizer {\n    struct Iter {\n        T s, t;\n        explicit\
    \ constexpr Iter(const T& s, const T& t) noexcept : s(s), t(t) {}\n        constexpr\
    \ bool operator!=(std::monostate) const noexcept { return s != 1; }\n        constexpr\
    \ void operator++() noexcept { t += 1; }\n        constexpr std::pair<T, int>\
    \ operator*() noexcept {\n            while (s % t != 0) {\n                if\
    \ (t * t > s) {\n                    const T u = s;\n                    s = 1;\n\
    \                    return {u, 1};\n                }\n                t += 1;\n\
    \            }\n            int e = 0;\n            while (s % t == 0) {\n   \
    \             e += 1;\n                s /= t;\n            }\n            return\
    \ {t, e};\n        }\n    };\n    T x;\n\n  public:\n    explicit constexpr Factorizer(const\
    \ T& x) noexcept : x(x) { assert(x > 0); }\n    constexpr Iter begin() const noexcept\
    \ { return Iter(x, 2); }\n    constexpr std::monostate end() noexcept { return\
    \ {}; }\n};\n\ntemplate <class T> constexpr Factorizer<T> factorize_iter(const\
    \ T& x) noexcept { return Factorizer<T>(x); }\n#line 3 \"math/totient.cpp\"\n\n\
    template <class T> constexpr T totient(T x) {\n    T ret = x;\n    for (const\
    \ auto& p : factorize_iter(x)) {\n        ret /= p.first;\n        ret *= p.first\
    \ - 1;\n    }\n    return ret;\n}\n#line 7 \"math/static_modint.cpp\"\n\ntemplate\
    \ <u32 MOD, std::enable_if_t<((u32)1 <= MOD and MOD <= ((u32)1 << 31))>* = nullptr>\
    \ class StaticModint {\n    using Self = StaticModint;\n\n    static inline constexpr\
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
    \ = StaticModint<1000000007>;\nusing Modint998244353 = StaticModint<998244353>;\n\
    #line 4 \"test/and_convolution.test.cpp\"\n#include <iostream>\n#line 6 \"test/and_convolution.test.cpp\"\
    \n\nusing Fp = Modint998244353;\n\nint main() {\n    int N;\n    std::cin >> N;\n\
    \    N = 1 << N;\n    std::vector<Fp> A(N), B(N);\n    for (auto& x : A) {\n \
    \       u32 t;\n        std::cin >> t;\n        x = t;\n    }\n    for (auto&\
    \ x : B) {\n        u32 t;\n        std::cin >> t;\n        x = t;\n    }\n  \
    \  const auto C = and_convolution(A, B);\n    for (const auto i : rep(0, N)) {\n\
    \        std::cout << C[i] << \" \\n\"[i + 1 == N];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\
    \n#include \"../algorithm/and_convolution.cpp\"\n#include \"../math/static_modint.cpp\"\
    \n#include <iostream>\n#include <vector>\n\nusing Fp = Modint998244353;\n\nint\
    \ main() {\n    int N;\n    std::cin >> N;\n    N = 1 << N;\n    std::vector<Fp>\
    \ A(N), B(N);\n    for (auto& x : A) {\n        u32 t;\n        std::cin >> t;\n\
    \        x = t;\n    }\n    for (auto& x : B) {\n        u32 t;\n        std::cin\
    \ >> t;\n        x = t;\n    }\n    const auto C = and_convolution(A, B);\n  \
    \  for (const auto i : rep(0, N)) {\n        std::cout << C[i] << \" \\n\"[i +\
    \ 1 == N];\n    }\n}"
  dependsOn:
  - algorithm/and_convolution.cpp
  - traits/sum_group.cpp
  - utility/rep.cpp
  - algorithm/superset_mobius_transform.cpp
  - algorithm/superset_zeta_transform.cpp
  - math/static_modint.cpp
  - utility/int_alias.cpp
  - math/rem_euclid.cpp
  - math/totient.cpp
  - math/factorize_iter.cpp
  isVerificationFile: true
  path: test/and_convolution.test.cpp
  requiredBy: []
  timestamp: '2021-12-28 22:38:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/and_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/and_convolution.test.cpp
- /verify/test/and_convolution.test.cpp.html
title: test/and_convolution.test.cpp
---
