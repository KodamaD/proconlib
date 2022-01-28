---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/ranked_subset_mobius_transform.cpp
    title: algorithm/ranked_subset_mobius_transform.cpp
  - icon: ':heavy_check_mark:'
    path: algorithm/ranked_subset_zeta_transform.cpp
    title: algorithm/ranked_subset_zeta_transform.cpp
  - icon: ':heavy_check_mark:'
    path: algorithm/subset_convolution.cpp
    title: algorithm/subset_convolution.cpp
  - icon: ':heavy_check_mark:'
    path: internal/enable_avx2.cpp
    title: internal/enable_avx2.cpp
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
    path: traits/num_ring.cpp
    title: traits/num_ring.cpp
  - icon: ':heavy_check_mark:'
    path: traits/product_monoid.cpp
    title: traits/product_monoid.cpp
  - icon: ':heavy_check_mark:'
    path: traits/sum_group.cpp
    title: traits/sum_group.cpp
  - icon: ':heavy_check_mark:'
    path: utility/bit_width.cpp
    title: utility/bit_width.cpp
  - icon: ':heavy_check_mark:'
    path: utility/countl_zero.cpp
    title: utility/countl_zero.cpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':heavy_check_mark:'
    path: utility/popcount.cpp
    title: utility/popcount.cpp
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
    PROBLEM: https://judge.yosupo.jp/problem/subset_convolution
    links:
    - https://judge.yosupo.jp/problem/subset_convolution
  bundledCode: "#line 1 \"test/subset_convolution.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/subset_convolution\"\
    \n#line 2 \"algorithm/subset_convolution.cpp\"\n#include <cassert>\n#include <vector>\n\
    #line 2 \"internal/enable_avx2.cpp\"\n\n#ifdef ENABLE_AVX2\n#define TARGET_AVX2\
    \ __attribute__((target(\"avx2\")))\n#else\n#define TARGET_AVX2\n#endif\n#line\
    \ 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n\nusing i32 = std::int32_t;\n\
    using u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n#line 4 \"utility/countl_zero.cpp\"\
    \n\nTARGET_AVX2 constexpr int countl_zero(u64 x) {\n#ifdef __GNUC__\n    return\
    \ x == 0 ? 64 : __builtin_clzll(x);\n#else\n    x |= x >> 1;\n    x |= x >> 2;\n\
    \    x |= x >> 4;\n    x |= x >> 8;\n    x |= x >> 16;\n    x |= x >> 32;\n  \
    \  return 64 - countr_zero(~x);\n#endif\n}\n#line 4 \"utility/bit_width.cpp\"\n\
    \nTARGET_AVX2 constexpr int bit_width(const u64 x) { return 64 - countl_zero(x);\
    \ }\n#line 2 \"utility/rep.cpp\"\n#include <algorithm>\n\nclass Range {\n    struct\
    \ Iter {\n        int itr;\n        constexpr Iter(const int pos) noexcept : itr(pos)\
    \ {}\n        constexpr void operator++() noexcept { ++itr; }\n        constexpr\
    \ bool operator!=(const Iter& other) const noexcept { return itr != other.itr;\
    \ }\n        constexpr int operator*() const noexcept { return itr; }\n    };\n\
    \    const Iter first, last;\n\n  public:\n    explicit constexpr Range(const\
    \ int first, const int last) noexcept : first(first), last(std::max(first, last))\
    \ {}\n    constexpr Iter begin() const noexcept { return first; }\n    constexpr\
    \ Iter end() const noexcept { return last; }\n};\n\nconstexpr Range rep(const\
    \ int l, const int r) noexcept { return Range(l, r); }\nconstexpr Range rep(const\
    \ int n) noexcept { return Range(0, n); }\n#line 4 \"utility/popcount.cpp\"\n\n\
    TARGET_AVX2 constexpr int popcount(u64 x) {\n#ifdef __GNUC__\n    return __builtin_popcountll(x);\n\
    #else\n    x -= x >> 1 & 0x5555555555555555;\n    x = (x & 0x3333333333333333)\
    \ + (x >> 2 & 0x3333333333333333);\n    x = (x + (x >> 4)) & 0x0F0F0F0F0F0F0F0F;\n\
    \    return x * 0x0101010101010101 >> 56 & 0x7f;\n#endif\n}\n#line 7 \"algorithm/ranked_subset_mobius_transform.cpp\"\
    \n\ntemplate <class G>\nstd::vector<typename G::Type> ranked_subset_mobius_transform(std::vector<std::vector<typename\
    \ G::Type>> f) {\n    const int n = f.size();\n    assert((n & (n - 1)) == 0);\n\
    \    const int logn = bit_width(n);\n    for (int i = n; i >>= 1;) {\n       \
    \ for (const int j : rep(n)) {\n            if (j & i) {\n                auto&\
    \ a = f[j];\n                const auto& b = f[j & ~i];\n                for (const\
    \ int k : rep(logn)) a[k] = G::operation(G::inverse(b[k]), a[k]);\n          \
    \  }\n        }\n    }\n    std::vector<typename G::Type> g(n, G::identity());\n\
    \    for (const int i : rep(n)) g[i] = f[i][popcount(i)];\n    return g;\n}\n\
    #line 7 \"algorithm/ranked_subset_zeta_transform.cpp\"\n\ntemplate <class S>\n\
    std::vector<std::vector<typename S::Type>> ranked_subset_zeta_transform(const\
    \ std::vector<typename S::Type>& f) {\n    const int n = f.size();\n    assert((n\
    \ & (n - 1)) == 0);\n    const int logn = bit_width(n);\n    std::vector<std::vector<typename\
    \ S::Type>> g(n, std::vector<typename S::Type>(logn, S::identity()));\n    for\
    \ (const int i : rep(n)) g[i][popcount(i)] = f[i];\n    for (int i = 1; i < n;\
    \ i <<= 1) {\n        for (const int j : rep(n)) {\n            if (j & i) {\n\
    \                auto& a = g[j];\n                const auto& b = g[j & ~i];\n\
    \                for (const int k : rep(logn)) a[k] = S::operation(b[k], a[k]);\n\
    \            }\n        }\n    }\n    return g;\n}\n#line 8 \"algorithm/subset_convolution.cpp\"\
    \n\ntemplate <class R>\nstd::vector<typename R::Type> subset_convolution(const\
    \ std::vector<typename R::Type>& a,\n                                        \
    \         const std::vector<typename R::Type>& b) {\n    assert(a.size() == b.size());\n\
    \    const auto f = ranked_subset_zeta_transform<typename R::Sum>(a);\n    const\
    \ auto g = ranked_subset_zeta_transform<typename R::Sum>(b);\n    const int n\
    \ = a.size();\n    const int logn = bit_width(n);\n    std::vector<std::vector<typename\
    \ R::Type>> h(n, std::vector<typename R::Type>(logn, R::Sum::identity()));\n \
    \   for (const int i : rep(n))\n        for (const int j : rep(logn))\n      \
    \      for (const int k : rep(logn - j))\n                h[i][j + k] = R::Sum::operation(h[i][j\
    \ + k], R::Product::operation(f[i][j], g[i][k]));\n    return ranked_subset_mobius_transform<typename\
    \ R::Sum>(std::move(h));\n}\n#line 2 \"math/static_modint.cpp\"\n#include <ostream>\n\
    #include <type_traits>\n#line 3 \"math/rem_euclid.cpp\"\n\ntemplate <class T>\
    \ constexpr T rem_euclid(T value, const T& mod) {\n    assert(mod > 0);\n    return\
    \ (value %= mod) >= 0 ? value : value + mod;\n}\n#line 2 \"math/totient.cpp\"\n\
    \ntemplate <class T> constexpr T totient(T x) {\n    T ret = x;\n    for (T i\
    \ = 2; i * i <= x; ++i) {\n        if (x % i == 0) {\n            ret /= i;\n\
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
    #line 2 \"traits/sum_group.cpp\"\n\ntemplate <class T> struct SumGroup {\n   \
    \ using Type = T;\n    static constexpr T identity() { return T(0); }\n    static\
    \ constexpr T operation(const T& l, const T& r) { return l + r; }\n    static\
    \ constexpr T inverse(const T& x) { return -x; }\n};\n#line 2 \"traits/product_monoid.cpp\"\
    \n\ntemplate <class T> struct ProductMonoid {\n    using Type = T;\n    static\
    \ constexpr T identity() { return T(1); }\n    static constexpr T operation(const\
    \ T& l, const T& r) { return l * r; }\n};\n#line 4 \"traits/num_ring.cpp\"\n\n\
    template <class T> struct NumRing {\n    using Type = T;\n    using Sum = SumGroup<T>;\n\
    \    using Product = ProductMonoid<T>;\n};\n#line 5 \"test/subset_convolution.test.cpp\"\
    \n#include <iostream>\n#line 7 \"test/subset_convolution.test.cpp\"\n\nusing Fp\
    \ = Modint998244353;\n\nint main() {\n    int N;\n    std::cin >> N;\n    N =\
    \ 1 << N;\n    std::vector<Fp> A(N), B(N);\n    for (auto& x : A) {\n        u32\
    \ t;\n        std::cin >> t;\n        x = t;\n    }\n    for (auto& x : B) {\n\
    \        u32 t;\n        std::cin >> t;\n        x = t;\n    }\n    const auto\
    \ C = subset_convolution<NumRing<Fp>>(A, B);\n    for (const int i : rep(N)) {\n\
    \        std::cout << C[i] << \" \\n\"[i + 1 == N];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/subset_convolution\"\n\
    #include \"../algorithm/subset_convolution.cpp\"\n#include \"../math/static_modint.cpp\"\
    \n#include \"../traits/num_ring.cpp\"\n#include <iostream>\n#include <vector>\n\
    \nusing Fp = Modint998244353;\n\nint main() {\n    int N;\n    std::cin >> N;\n\
    \    N = 1 << N;\n    std::vector<Fp> A(N), B(N);\n    for (auto& x : A) {\n \
    \       u32 t;\n        std::cin >> t;\n        x = t;\n    }\n    for (auto&\
    \ x : B) {\n        u32 t;\n        std::cin >> t;\n        x = t;\n    }\n  \
    \  const auto C = subset_convolution<NumRing<Fp>>(A, B);\n    for (const int i\
    \ : rep(N)) {\n        std::cout << C[i] << \" \\n\"[i + 1 == N];\n    }\n}"
  dependsOn:
  - algorithm/subset_convolution.cpp
  - utility/bit_width.cpp
  - internal/enable_avx2.cpp
  - utility/countl_zero.cpp
  - utility/int_alias.cpp
  - utility/rep.cpp
  - algorithm/ranked_subset_mobius_transform.cpp
  - utility/popcount.cpp
  - algorithm/ranked_subset_zeta_transform.cpp
  - math/static_modint.cpp
  - math/rem_euclid.cpp
  - math/totient.cpp
  - traits/num_ring.cpp
  - traits/sum_group.cpp
  - traits/product_monoid.cpp
  isVerificationFile: true
  path: test/subset_convolution.test.cpp
  requiredBy: []
  timestamp: '2022-01-28 13:07:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/subset_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/subset_convolution.test.cpp
- /verify/test/subset_convolution.test.cpp.html
title: test/subset_convolution.test.cpp
---
