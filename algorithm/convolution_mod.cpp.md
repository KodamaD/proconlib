---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: internal/barret_reduction.cpp
    title: internal/barret_reduction.cpp
  - icon: ':heavy_check_mark:'
    path: internal/enable_avx2.cpp
    title: internal/enable_avx2.cpp
  - icon: ':heavy_check_mark:'
    path: internal/modulo_transform.cpp
    title: internal/modulo_transform.cpp
  - icon: ':heavy_check_mark:'
    path: math/mod_pow.cpp
    title: math/mod_pow.cpp
  - icon: ':heavy_check_mark:'
    path: math/primitive_root.cpp
    title: math/primitive_root.cpp
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
    path: utility/bit_width.cpp
    title: utility/bit_width.cpp
  - icon: ':heavy_check_mark:'
    path: utility/ceil_log2.cpp
    title: utility/ceil_log2.cpp
  - icon: ':heavy_check_mark:'
    path: utility/countl_zero.cpp
    title: utility/countl_zero.cpp
  - icon: ':heavy_check_mark:'
    path: utility/countr_zero.cpp
    title: utility/countr_zero.cpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':heavy_check_mark:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  - icon: ':heavy_check_mark:'
    path: utility/revrep.cpp
    title: utility/revrep.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algorithm/convolution_arbitrary_mod.cpp
    title: algorithm/convolution_arbitrary_mod.cpp
  - icon: ':warning:'
    path: algorithm/convolution_int.cpp
    title: algorithm/convolution_int.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution_arbitrary_mod.test.cpp
    title: test/convolution_arbitrary_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution_mod.test.cpp
    title: test/convolution_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algorithm/convolution_mod.cpp\"\n#include <algorithm>\n\
    #include <vector>\n#line 2 \"internal/modulo_transform.cpp\"\n#include <array>\n\
    #line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n\nusing i32 = std::int32_t;\n\
    using u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n#line 2 \"math/mod_pow.cpp\"\
    \n#include <cassert>\n#include <type_traits>\n#line 3 \"internal/barret_reduction.cpp\"\
    \n\nnamespace proconlib {\n\nclass BarretReduction {\n    u32 mod;\n    u64 near_inv;\n\
    \n  public:\n    explicit constexpr BarretReduction(const u32 mod) noexcept :\
    \ mod(mod), near_inv((u64)(-1) / mod + 1) {}\n    constexpr u32 product(const\
    \ u32 a, const u32 b) const noexcept {\n        const u64 z = (u64)a * b;\n  \
    \      const u64 x = ((u128)z * near_inv) >> 64;\n        const u32 v = z - x\
    \ * mod;\n        return v < mod ? v : v + mod;\n    }\n    constexpr u32 get_mod()\
    \ const noexcept { return mod; }\n};\n\n}  // namespace proconlib\n#line 3 \"\
    math/rem_euclid.cpp\"\n\ntemplate <class T> constexpr T rem_euclid(T value, const\
    \ T& mod) {\n    assert(mod > 0);\n    return (value %= mod) >= 0 ? value : value\
    \ + mod;\n}\n#line 7 \"math/mod_pow.cpp\"\n\ntemplate <class T> constexpr u32\
    \ mod_pow(T x, u64 exp, const u32 mod) {\n    assert(mod > 0);\n    if (mod ==\
    \ 1) return 0;\n    const proconlib::BarretReduction bt(mod);\n    u32 ret = 1,\
    \ mul = rem_euclid<std::common_type_t<T, i64>>(x, mod);\n    for (; exp > 0; exp\
    \ >>= 1) {\n        if (exp & 1) ret = bt.product(ret, mul);\n        mul = bt.product(mul,\
    \ mul);\n    }\n    return ret;\n}\n#line 5 \"math/primitive_root.cpp\"\n\nconstexpr\
    \ u32 primitive_root(const u32 mod) {\n    std::array<u32, 32> exp{};\n    u32\
    \ cur = mod - 1;\n    int size = 0;\n    for (u32 i = 2; i * i <= cur; ++i) {\n\
    \        if (cur % i == 0) {\n            exp[size++] = (mod - 1) / i;\n     \
    \       while (cur % i == 0) cur /= i;\n        }\n    }\n    if (cur != 1) exp[size++]\
    \ = (mod - 1) / cur;\n    for (u32 check = 1; check < mod; ++check) {\n      \
    \  for (const u32 e : exp) {\n            if (e == 0) return check;\n        \
    \    if (mod_pow(check, e, mod) == 1) break;\n        }\n    }\n    return mod;\n\
    }\n#line 2 \"internal/enable_avx2.cpp\"\n\n#ifdef ENABLE_AVX2\n#define TARGET_AVX2\
    \ __attribute__((target(\"avx2\")))\n#else\n#define TARGET_AVX2\n#endif\n#line\
    \ 5 \"utility/countr_zero.cpp\"\n\nconstexpr int countr_zero(u64 x) {\n    if\
    \ (x == 0) return 64;\n#ifdef __GNUC__\n    return __builtin_ctzll(x);\n#else\n\
    \    constexpr std::array<int, 64> table = {0,  1,  2,  7,  3,  13, 8,  27, 4,\
    \  33, 14, 36, 9,  49, 28, 19,\n                                             5,\
    \  25, 34, 17, 15, 53, 37, 55, 10, 46, 50, 39, 29, 42, 20, 57,\n             \
    \                                63, 6,  12, 26, 32, 35, 48, 18, 24, 16, 52, 54,\
    \ 45, 38, 41, 56,\n                                             62, 11, 31, 47,\
    \ 23, 51, 44, 40, 61, 30, 22, 43, 60, 21, 59, 58};\n    return table[(x & (~x\
    \ + 1)) * 0x218A7A392DD9ABF >> 58 & 0x3F];\n#endif\n}\n#line 3 \"utility/rep.cpp\"\
    \n\nclass Range {\n    struct Iter {\n        int itr;\n        constexpr Iter(const\
    \ int pos) noexcept : itr(pos) {}\n        constexpr void operator++() noexcept\
    \ { ++itr; }\n        constexpr bool operator!=(const Iter& other) const noexcept\
    \ { return itr != other.itr; }\n        constexpr int operator*() const noexcept\
    \ { return itr; }\n    };\n    const Iter first, last;\n\n  public:\n    explicit\
    \ constexpr Range(const int first, const int last) noexcept : first(first), last(std::max(first,\
    \ last)) {}\n    constexpr Iter begin() const noexcept { return first; }\n   \
    \ constexpr Iter end() const noexcept { return last; }\n};\n\nconstexpr Range\
    \ rep(const int l, const int r) noexcept { return Range(l, r); }\nconstexpr Range\
    \ rep(const int n) noexcept { return Range(0, n); }\n#line 3 \"utility/revrep.cpp\"\
    \n\nclass ReversedRange {\n    struct Iter {\n        int itr;\n        constexpr\
    \ Iter(const int pos) noexcept : itr(pos) {}\n        constexpr void operator++()\
    \ noexcept { --itr; }\n        constexpr bool operator!=(const Iter& other) const\
    \ noexcept { return itr != other.itr; }\n        constexpr int operator*() const\
    \ noexcept { return itr; }\n    };\n    const Iter first, last;\n\n  public:\n\
    \    explicit constexpr ReversedRange(const int first, const int last) noexcept\n\
    \        : first(last - 1), last(std::min(first, last) - 1) {}\n    constexpr\
    \ Iter begin() const noexcept { return first; }\n    constexpr Iter end() const\
    \ noexcept { return last; }\n};\n\nconstexpr ReversedRange revrep(const int l,\
    \ const int r) noexcept { return ReversedRange(l, r); }\nconstexpr ReversedRange\
    \ revrep(const int n) noexcept { return ReversedRange(0, n); }\n#line 9 \"internal/modulo_transform.cpp\"\
    \n\nnamespace proconlib {\n\ntemplate <class M> struct ModuloTransform {\n   \
    \ static constexpr u32 MOD = M::mod();\n    static constexpr u32 ROOT = primitive_root(MOD);\n\
    \    static constexpr int RANK = countr_zero(MOD - 1);\n\n    std::array<M, RANK\
    \ + 1> root, iroot;\n    std::array<M, (RANK >= 2 ? RANK - 2 + 1 : 0)> rate2,\
    \ irate2;\n    std::array<M, (RANK >= 3 ? RANK - 3 + 1 : 0)> rate3, irate3;\n\n\
    \    constexpr ModuloTransform() : root(), iroot(), rate2(), irate2(), rate3(),\
    \ irate3() {\n        root[RANK] = M(ROOT).pow((MOD - 1) >> RANK);\n        iroot[RANK]\
    \ = root[RANK].inv();\n        for (const int i : revrep(0, RANK)) {\n       \
    \     root[i] = root[i + 1] * root[i + 1];\n            iroot[i] = iroot[i + 1]\
    \ * iroot[i + 1];\n        }\n        M prod = 1, iprod = 1;\n        for (const\
    \ int i : rep(2, RANK + 1)) {\n            rate2[i - 2] = root[i] * prod;\n  \
    \          irate2[i - 2] = iroot[i] * iprod;\n            prod *= iroot[i];\n\
    \            iprod *= root[i];\n        }\n        prod = 1, iprod = 1;\n    \
    \    for (const int i : rep(3, RANK + 1)) {\n            rate3[i - 3] = root[i]\
    \ * prod;\n            irate3[i - 3] = iroot[i] * iprod;\n            prod *=\
    \ iroot[i];\n            iprod *= root[i];\n        }\n    }\n\n    void butterfly(std::vector<M>&\
    \ a) const {\n        const int n = a.size();\n        const int h = countr_zero(n);\n\
    \        for (int len = 0; len < h;) {\n            if (len + 1 == h) {\n    \
    \            M rot = 1;\n                for (const int s : rep(0, 1 << len))\
    \ {\n                    const int t = s << 1;\n                    const M l\
    \ = a[t], r = a[t + 1] * rot;\n                    a[t] = l + r;\n           \
    \         a[t + 1] = l - r;\n                    if (((s + 1) >> len) == 0) rot\
    \ *= rate2[countr_zero(~s)];\n                }\n                len += 1;\n \
    \           } else {\n                const int p = 1 << (h - len - 2);\n    \
    \            M rot = 1;\n                for (const int s : rep(0, 1 << len))\
    \ {\n                    const int t = s << (h - len);\n                    const\
    \ M rot2 = rot * rot;\n                    const M rot3 = rot2 * rot;\n      \
    \              for (const int i : rep(0, p)) {\n                        const\
    \ M a0 = a[i + t];\n                        const M a1 = a[i + t + p] * rot;\n\
    \                        const M a2 = a[i + t + p * 2] * rot2;\n             \
    \           const M a3 = a[i + t + p * 3] * rot3;\n                        const\
    \ M ax = (a1 - a3) * root[2];\n                        a[i + t] = a0 + a1 + a2\
    \ + a3;\n                        a[i + t + p] = a0 - a1 + a2 - a3;\n         \
    \               a[i + t + p * 2] = a0 - a2 + ax;\n                        a[i\
    \ + t + p * 3] = a0 - a2 - ax;\n                    }\n                    if\
    \ (((s + 1) >> len) == 0) rot *= rate3[countr_zero(~s)];\n                }\n\
    \                len += 2;\n            }\n        }\n    }\n\n    void butterfly_inv(std::vector<M>&\
    \ a) const {\n        const int n = a.size();\n        const int h = countr_zero(n);\n\
    \        for (int len = h; len > 0;) {\n            if (len == 1) {\n        \
    \        const int p = n >> 1;\n                for (const int i : rep(0, p))\
    \ {\n                    const M l = a[i], r = a[i + p];\n                   \
    \ a[i] = l + r;\n                    a[i + p] = l - r;\n                }\n  \
    \              len -= 1;\n            } else {\n                const int p =\
    \ 1 << (h - len);\n                M rot = 1;\n                for (const int\
    \ s : rep(0, 1 << (len - 2))) {\n                    const int t = s << (h - len\
    \ + 2);\n                    const M rot2 = rot * rot;\n                    const\
    \ M rot3 = rot2 * rot;\n                    for (const int i : rep(0, p)) {\n\
    \                        const M a0 = a[i + t];\n                        const\
    \ M a1 = a[i + t + p];\n                        const M a2 = a[i + t + p * 2];\n\
    \                        const M a3 = a[i + t + p * 3];\n                    \
    \    const M ax = (a2 - a3) * iroot[2];\n                        a[i + t] = a0\
    \ + a1 + a2 + a3;\n                        a[i + t + p] = (a0 - a1 + ax) * rot;\n\
    \                        a[i + t + p * 2] = (a0 + a1 - a2 - a3) * rot2;\n    \
    \                    a[i + t + p * 3] = (a0 - a1 - ax) * rot3;\n             \
    \       }\n                    if (((s + 1) >> (len - 2)) == 0) rot *= irate3[countr_zero(~s)];\n\
    \                }\n                len -= 2;\n            }\n        }\n    }\n\
    };\n\n}  // namespace proconlib\n#line 2 \"math/static_modint.cpp\"\n#include\
    \ <ostream>\n#line 2 \"math/totient.cpp\"\n\ntemplate <class T> constexpr T totient(T\
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
    \ = StaticModint<1000000007>;\nusing Modint998244353 = StaticModint<998244353>;\n\
    #line 4 \"utility/countl_zero.cpp\"\n\nTARGET_AVX2 constexpr int countl_zero(u64\
    \ x) {\n#ifdef __GNUC__\n    return x == 0 ? 64 : __builtin_clzll(x);\n#else\n\
    \    x |= x >> 1;\n    x |= x >> 2;\n    x |= x >> 4;\n    x |= x >> 8;\n    x\
    \ |= x >> 16;\n    x |= x >> 32;\n    return 64 - countr_zero(~x);\n#endif\n}\n\
    #line 4 \"utility/bit_width.cpp\"\n\nTARGET_AVX2 constexpr int bit_width(const\
    \ u64 x) { return 64 - countl_zero(x); }\n#line 5 \"utility/ceil_log2.cpp\"\n\n\
    TARGET_AVX2 constexpr int ceil_log2(const u64 x) {\n#ifdef __GNUC__\n    return\
    \ x == 0 ? 0 : bit_width(x - 1);\n#else\n    int e = 0;\n    while (((u64)1 <<\
    \ e) < x) ++e;\n    return e;\n#endif\n}\n#line 9 \"algorithm/convolution_mod.cpp\"\
    \n\nnamespace proconlib {\n\ntemplate <class T> std::vector<T> convolution_naive(const\
    \ std::vector<T>& a, const std::vector<T>& b) {\n    const int n = a.size(), m\
    \ = b.size();\n    std::vector<T> c(n + m - 1);\n    if (n < m) {\n        for\
    \ (const int j : rep(m))\n            for (const int i : rep(n)) c[i + j] += a[i]\
    \ * b[j];\n    } else {\n        for (const int i : rep(n))\n            for (const\
    \ int j : rep(m)) c[i + j] += a[i] * b[j];\n    }\n    return c;\n}\n\ntemplate\
    \ <class M> std::vector<M> convolution_ntt(std::vector<M> a, std::vector<M> b)\
    \ {\n    constexpr ModuloTransform<M> transform;\n    const int n = a.size(),\
    \ m = b.size();\n    const int k = 1 << ceil_log2(n + m - 1);\n    a.resize(k),\
    \ b.resize(k);\n    transform.butterfly(a);\n    transform.butterfly(b);\n   \
    \ for (const int i : rep(k)) a[i] *= b[i];\n    transform.butterfly_inv(a);\n\
    \    a.resize(n + m - 1);\n    const M c = M(k).inv();\n    for (const int i :\
    \ rep(n + m - 1)) a[i] *= c;\n    return a;\n}\n\n}  // namespace proconlib\n\n\
    template <class M> std::vector<M> convolution_mod(std::vector<M>&& a, std::vector<M>&&\
    \ b) {\n    const int n = a.size(), m = b.size();\n    if (n == 0 || m == 0) return\
    \ {};\n    if (std::min(n, m) <= 60) return proconlib::convolution_naive(a, b);\n\
    \    return proconlib::convolution_ntt(std::move(a), std::move(b));\n}\n\ntemplate\
    \ <class M> std::vector<M> convolution_mod(const std::vector<M>& a, const std::vector<M>&\
    \ b) {\n    const int n = a.size(), m = b.size();\n    if (n == 0 || m == 0) return\
    \ {};\n    if (std::min(n, m) <= 60) return proconlib::convolution_naive(a, b);\n\
    \    return proconlib::convolution_ntt(a, b);\n}\n\ntemplate <class T, u32 MOD,\
    \ std::enable_if_t<std::is_integral_v<T>>* = nullptr>\nstd::vector<T> convolution_mod(const\
    \ std::vector<T>& a, const std::vector<T>& b) {\n    const int n = a.size(), m\
    \ = b.size();\n    if (n == 0 || m == 0) return {};\n    using M = StaticModint<MOD>;\n\
    \    std::vector<M> a2(n), b2(m);\n    for (const int i : rep(n)) a2[i] = a[i];\n\
    \    for (const int i : rep(m)) b2[i] = b[i];\n    std::vector<M> c2 = convolution_mod(std::move(a2),\
    \ std::move(b2));\n    std::vector<T> c(n + m - 1);\n    for (const int i : rep(n\
    \ + m - 1)) c[i] = c2[i].val();\n    return c;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n#include \"../internal/modulo_transform.cpp\"\
    \n#include \"../math/static_modint.cpp\"\n#include \"../utility/ceil_log2.cpp\"\
    \n#include \"../utility/int_alias.cpp\"\n#include \"../utility/rep.cpp\"\n\nnamespace\
    \ proconlib {\n\ntemplate <class T> std::vector<T> convolution_naive(const std::vector<T>&\
    \ a, const std::vector<T>& b) {\n    const int n = a.size(), m = b.size();\n \
    \   std::vector<T> c(n + m - 1);\n    if (n < m) {\n        for (const int j :\
    \ rep(m))\n            for (const int i : rep(n)) c[i + j] += a[i] * b[j];\n \
    \   } else {\n        for (const int i : rep(n))\n            for (const int j\
    \ : rep(m)) c[i + j] += a[i] * b[j];\n    }\n    return c;\n}\n\ntemplate <class\
    \ M> std::vector<M> convolution_ntt(std::vector<M> a, std::vector<M> b) {\n  \
    \  constexpr ModuloTransform<M> transform;\n    const int n = a.size(), m = b.size();\n\
    \    const int k = 1 << ceil_log2(n + m - 1);\n    a.resize(k), b.resize(k);\n\
    \    transform.butterfly(a);\n    transform.butterfly(b);\n    for (const int\
    \ i : rep(k)) a[i] *= b[i];\n    transform.butterfly_inv(a);\n    a.resize(n +\
    \ m - 1);\n    const M c = M(k).inv();\n    for (const int i : rep(n + m - 1))\
    \ a[i] *= c;\n    return a;\n}\n\n}  // namespace proconlib\n\ntemplate <class\
    \ M> std::vector<M> convolution_mod(std::vector<M>&& a, std::vector<M>&& b) {\n\
    \    const int n = a.size(), m = b.size();\n    if (n == 0 || m == 0) return {};\n\
    \    if (std::min(n, m) <= 60) return proconlib::convolution_naive(a, b);\n  \
    \  return proconlib::convolution_ntt(std::move(a), std::move(b));\n}\n\ntemplate\
    \ <class M> std::vector<M> convolution_mod(const std::vector<M>& a, const std::vector<M>&\
    \ b) {\n    const int n = a.size(), m = b.size();\n    if (n == 0 || m == 0) return\
    \ {};\n    if (std::min(n, m) <= 60) return proconlib::convolution_naive(a, b);\n\
    \    return proconlib::convolution_ntt(a, b);\n}\n\ntemplate <class T, u32 MOD,\
    \ std::enable_if_t<std::is_integral_v<T>>* = nullptr>\nstd::vector<T> convolution_mod(const\
    \ std::vector<T>& a, const std::vector<T>& b) {\n    const int n = a.size(), m\
    \ = b.size();\n    if (n == 0 || m == 0) return {};\n    using M = StaticModint<MOD>;\n\
    \    std::vector<M> a2(n), b2(m);\n    for (const int i : rep(n)) a2[i] = a[i];\n\
    \    for (const int i : rep(m)) b2[i] = b[i];\n    std::vector<M> c2 = convolution_mod(std::move(a2),\
    \ std::move(b2));\n    std::vector<T> c(n + m - 1);\n    for (const int i : rep(n\
    \ + m - 1)) c[i] = c2[i].val();\n    return c;\n}"
  dependsOn:
  - internal/modulo_transform.cpp
  - math/primitive_root.cpp
  - utility/int_alias.cpp
  - math/mod_pow.cpp
  - internal/barret_reduction.cpp
  - math/rem_euclid.cpp
  - utility/countr_zero.cpp
  - internal/enable_avx2.cpp
  - utility/rep.cpp
  - utility/revrep.cpp
  - math/static_modint.cpp
  - math/totient.cpp
  - utility/ceil_log2.cpp
  - utility/bit_width.cpp
  - utility/countl_zero.cpp
  isVerificationFile: false
  path: algorithm/convolution_mod.cpp
  requiredBy:
  - algorithm/convolution_int.cpp
  - algorithm/convolution_arbitrary_mod.cpp
  timestamp: '2022-01-28 13:07:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution_arbitrary_mod.test.cpp
  - test/convolution_mod.test.cpp
documentation_of: algorithm/convolution_mod.cpp
layout: document
redirect_from:
- /library/algorithm/convolution_mod.cpp
- /library/algorithm/convolution_mod.cpp.html
title: algorithm/convolution_mod.cpp
---
