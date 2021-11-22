---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/convolution_arbitrary_mod.cpp
    title: algorithm/convolution_arbitrary_mod.cpp
  - icon: ':heavy_check_mark:'
    path: algorithm/convolution_mod.cpp
    title: algorithm/convolution_mod.cpp
  - icon: ':heavy_check_mark:'
    path: bit/bit_rzeros.cpp
    title: bit/bit_rzeros.cpp
  - icon: ':heavy_check_mark:'
    path: bit/ceil_log2.cpp
    title: bit/ceil_log2.cpp
  - icon: ':heavy_check_mark:'
    path: math/barret_reduction.cpp
    title: math/barret_reduction.cpp
  - icon: ':heavy_check_mark:'
    path: math/inv_gcd.cpp
    title: math/inv_gcd.cpp
  - icon: ':heavy_check_mark:'
    path: math/mod_inv.cpp
    title: math/mod_inv.cpp
  - icon: ':heavy_check_mark:'
    path: math/mod_pow.cpp
    title: math/mod_pow.cpp
  - icon: ':heavy_check_mark:'
    path: math/modulo_transform.cpp
    title: math/modulo_transform.cpp
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
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias_extended.cpp
    title: utility/int_alias_extended.cpp
  - icon: ':heavy_check_mark:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  - icon: ':heavy_check_mark:'
    path: utility/revrep.cpp
    title: utility/revrep.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod_1000000007
    links:
    - https://judge.yosupo.jp/problem/convolution_mod_1000000007
  bundledCode: "#line 1 \"test/convolution_arbitrary_mod.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\n#include <iostream>\n\
    #include <vector>\n#line 2 \"math/mod_inv.cpp\"\n#include <cassert>\n#line 2 \"\
    math/inv_gcd.cpp\"\n#include <type_traits>\n#include <utility>\n#line 3 \"math/rem_euclid.cpp\"\
    \n\ntemplate <class T> constexpr T rem_euclid(T value, const T& mod) {\n    assert(mod\
    \ > 0);\n    return (value %= mod) >= 0 ? value : value + mod;\n}\n#line 5 \"\
    math/inv_gcd.cpp\"\n\ntemplate <class T> constexpr std::pair<T, T> inv_gcd(const\
    \ T& a, const T& b) {\n    using U = std::make_signed_t<T>;\n    U t = rem_euclid(a,\
    \ b);\n    if (t == 0) return {b, 0};\n    U s = b, m0 = 0, m1 = 1;\n    while\
    \ (t != 0) {\n        const U u = s / t;\n        s -= t * u;\n        m0 -= m1\
    \ * u;\n        U tmp = s;\n        s = t;\n        t = tmp;\n        tmp = m0;\n\
    \        m0 = m1;\n        m1 = tmp;\n    }\n    if (m0 < 0) m0 += b / s;\n  \
    \  return {(T)s, (T)m0};\n}\n#line 4 \"math/mod_inv.cpp\"\n\ntemplate <class T>\
    \ constexpr T mod_inv(const T& a, const T& mod) {\n    const auto [g, x] = inv_gcd(a,\
    \ mod);\n    assert(g == 1);\n    return x;\n}\n#line 2 \"utility/int_alias.cpp\"\
    \n#include <cstddef>\n#include <cstdint>\n\nusing i32 = std::int32_t;\nusing u32\
    \ = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing\
    \ isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 4 \"utility/int_alias_extended.cpp\"\
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
    };\n#line 3 \"bit/ceil_log2.cpp\"\n\n__attribute__((target(\"avx2\"))) constexpr\
    \ u64 ceil_log2(const u64 x) {\n    u64 e = 0;\n    while (((u64)1 << e) < x)\
    \ ++e;\n    return e;\n}\n#line 2 \"math/modulo_transform.cpp\"\n#include <array>\n\
    #line 3 \"bit/bit_rzeros.cpp\"\n\n__attribute__((target(\"avx2\"))) constexpr\
    \ u64 bit_rzeros(const u64 x) { return x == 0 ? 64 : __builtin_ctzll(x); }\n#line\
    \ 4 \"utility/revrep.cpp\"\n\nclass revrep {\n    struct Iter {\n        usize\
    \ itr;\n        constexpr Iter(const usize pos) noexcept : itr(pos) {}\n     \
    \   constexpr void operator++() noexcept { --itr; }\n        constexpr bool operator!=(const\
    \ Iter& other) const noexcept { return itr != other.itr; }\n        constexpr\
    \ usize operator*() const noexcept { return itr; }\n    };\n    const Iter first,\
    \ last;\n\n  public:\n    explicit constexpr revrep(const usize first, const usize\
    \ last) noexcept\n        : first(last - 1), last(std::min(first, last) - 1) {}\n\
    \    constexpr Iter begin() const noexcept { return first; }\n    constexpr Iter\
    \ end() const noexcept { return last; }\n};\n#line 4 \"math/barret_reduction.cpp\"\
    \n\nclass BarretReduction {\n    u32 mod;\n    u64 near_inv;\n\n  public:\n  \
    \  explicit constexpr BarretReduction(const u32 mod) noexcept : mod(mod), near_inv((u64)(-1)\
    \ / mod + 1) {}\n    constexpr u32 product(const u32 a, const u32 b) const noexcept\
    \ {\n        const u64 z = (u64)a * b;\n        const u64 x = ((u128)z * near_inv)\
    \ >> 64;\n        const u32 v = z - x * mod;\n        return v < mod ? v : v +\
    \ mod;\n    }\n};\n#line 7 \"math/mod_pow.cpp\"\n\ntemplate <class T> constexpr\
    \ u32 mod_pow(T x, u64 exp, const u32 mod) {\n    assert(mod > 0);\n    if (mod\
    \ == 1) return 0;\n    const BarretReduction bt(mod);\n    u32 ret = 1, mul =\
    \ rem_euclid<std::common_type_t<T, i64>>(x, mod);\n    for (; exp > 0; exp >>=\
    \ 1) {\n        if (exp & 1) ret = bt.product(ret, mul);\n        mul = bt.product(mul,\
    \ mul);\n    }\n    return ret;\n}\n#line 5 \"math/primitive_root.cpp\"\n\nconstexpr\
    \ u32 primitive_root(const u32 mod) {\n    std::array<u32, 32> exp{};\n    u32\
    \ cur = mod - 1;\n    usize size = 0;\n    for (u32 i = 2; i * i <= cur; ++i)\
    \ {\n        if (cur % i == 0) {\n            exp[size++] = (mod - 1) / i;\n \
    \           while (cur % i == 0) cur /= i;\n        }\n    }\n    if (cur != 1)\
    \ exp[size++] = (mod - 1) / cur;\n    for (u32 check = 1; check < mod; ++check)\
    \ {\n        for (const u32 e : exp) {\n            if (e == 0) return check;\n\
    \            if (mod_pow(check, e, mod) == 1) break;\n        }\n    }\n    return\
    \ mod;\n}\n#line 9 \"math/modulo_transform.cpp\"\n\ntemplate <class M> struct\
    \ ModuloTransform {\n    static constexpr u32 ROOT = primitive_root(M::mod());\n\
    \    static constexpr usize RANK = bit_rzeros(M::mod() - 1);\n\n    std::array<M,\
    \ RANK + 1> root, iroot;\n    std::array<M, (RANK >= 2 ? RANK - 2 + 1 : 0)> rate2,\
    \ irate2;\n    std::array<M, (RANK >= 3 ? RANK - 3 + 1 : 0)> rate3, irate3;\n\n\
    \    constexpr ModuloTransform() {\n        root[RANK] = M(ROOT).pow((M::mod()\
    \ - 1) >> RANK);\n        iroot[RANK] = root[RANK].inv();\n        for (const\
    \ usize i : revrep(0, RANK)) {\n            root[i] = root[i + 1] * root[i + 1];\n\
    \            iroot[i] = iroot[i + 1] * iroot[i + 1];\n        }\n        M prod\
    \ = 1, iprod = 1;\n        for (const usize i : rep(2, RANK + 1)) {\n        \
    \    rate2[i - 2] = root[i] * prod;\n            irate2[i - 2] = iroot[i] * iprod;\n\
    \            prod *= iroot[i];\n            iprod *= root[i];\n        }\n   \
    \     prod = 1, iprod = 1;\n        for (const usize i : rep(3, RANK + 1)) {\n\
    \            rate3[i - 3] = root[i] * prod;\n            irate3[i - 3] = iroot[i]\
    \ * iprod;\n            prod *= iroot[i];\n            iprod *= root[i];\n   \
    \     }\n    }\n\n    void butterfly(std::vector<M>& a) const {\n        const\
    \ usize n = a.size();\n        const usize h = bit_rzeros(n);\n        for (usize\
    \ len = 0; len < h;) {\n            if (len + 1 == h) {\n                M rot\
    \ = 1;\n                for (const usize s : rep(0, 1 << len)) {\n           \
    \         const usize t = s << 1;\n                    const M l = a[t], r = a[t\
    \ + 1] * rot;\n                    a[t] = l + r;\n                    a[t + 1]\
    \ = l - r;\n                    if (((s + 1) >> len) == 0) rot *= rate2[bit_rzeros(~s)];\n\
    \                }\n                len += 1;\n            } else {\n        \
    \        const usize p = 1 << (h - len - 2);\n                M rot = 1;\n   \
    \             for (const usize s : rep(0, 1 << len)) {\n                    const\
    \ usize t = s << (h - len);\n                    const M rot2 = rot * rot;\n \
    \                   const M rot3 = rot2 * rot;\n                    for (const\
    \ usize i : rep(0, p)) {\n                        const M a0 = a[i + t];\n   \
    \                     const M a1 = a[i + t + p] * rot;\n                     \
    \   const M a2 = a[i + t + p * 2] * rot2;\n                        const M a3\
    \ = a[i + t + p * 3] * rot3;\n                        const M ax = (a1 - a3) *\
    \ root[2];\n                        a[i + t] = a0 + a1 + a2 + a3;\n          \
    \              a[i + t + p] = a0 - a1 + a2 - a3;\n                        a[i\
    \ + t + p * 2] = a0 - a2 + ax;\n                        a[i + t + p * 3] = a0\
    \ - a2 - ax;\n                    }\n                    if (((s + 1) >> len)\
    \ == 0) rot *= rate3[bit_rzeros(~s)];\n                }\n                len\
    \ += 2;\n            }\n        }\n    }\n\n    void butterfly_inv(std::vector<M>&\
    \ a) const {\n        const usize n = a.size();\n        const usize h = bit_rzeros(n);\n\
    \        for (usize len = h; len > 0;) {\n            if (len == 1) {\n      \
    \          const usize p = n >> 1;\n                for (const usize i : rep(0,\
    \ p)) {\n                    const M l = a[i], r = a[i + p];\n               \
    \     a[i] = l + r;\n                    a[i + p] = l - r;\n                }\n\
    \                len -= 1;\n            } else {\n                const usize\
    \ p = 1 << (h - len);\n                M rot = 1;\n                for (const\
    \ usize s : rep(0, 1 << (len - 2))) {\n                    const usize t = s <<\
    \ (h - len + 2);\n                    const M rot2 = rot * rot;\n            \
    \        const M rot3 = rot2 * rot;\n                    for (const usize i :\
    \ rep(0, p)) {\n                        const M a0 = a[i + t];\n             \
    \           const M a1 = a[i + t + p];\n                        const M a2 = a[i\
    \ + t + p * 2];\n                        const M a3 = a[i + t + p * 3];\n    \
    \                    const M ax = (a2 - a3) * iroot[2];\n                    \
    \    a[i + t] = a0 + a1 + a2 + a3;\n                        a[i + t + p] = (a0\
    \ - a1 + ax) * rot;\n                        a[i + t + p * 2] = (a0 + a1 - a2\
    \ - a3) * rot2;\n                        a[i + t + p * 3] = (a0 - a1 - ax) * rot3;\n\
    \                    }\n                    if (((s + 1) >> (len - 2)) == 0) rot\
    \ *= irate3[bit_rzeros(~s)];\n                }\n                len -= 2;\n \
    \           }\n        }\n    }\n};\n#line 2 \"math/static_modint.cpp\"\n#include\
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
    #line 9 \"algorithm/convolution_mod.cpp\"\n\ntemplate <class T> std::vector<T>\
    \ convolution_naive(const std::vector<T>& a, const std::vector<T>& b) {\n    const\
    \ usize n = a.size(), m = b.size();\n    std::vector<T> c(n + m - 1);\n    if\
    \ (n < m) {\n        for (const usize j : rep(0, m))\n            for (const usize\
    \ i : rep(0, n)) c[i + j] += a[i] * b[j];\n    } else {\n        for (const usize\
    \ i : rep(0, n))\n            for (const usize j : rep(0, m)) c[i + j] += a[i]\
    \ * b[j];\n    }\n    return c;\n}\n\ntemplate <class M> std::vector<M> convolution_ntt(std::vector<M>\
    \ a, std::vector<M> b) {\n    static constexpr ModuloTransform<M> transform;\n\
    \    const usize n = a.size(), m = b.size();\n    const usize k = 1 << ceil_log2(n\
    \ + m - 1);\n    a.resize(k), b.resize(k);\n    transform.butterfly(a);\n    transform.butterfly(b);\n\
    \    for (const usize i : rep(0, k)) a[i] *= b[i];\n    transform.butterfly_inv(a);\n\
    \    a.resize(n + m - 1);\n    const M c = M(k).inv();\n    for (const usize i\
    \ : rep(0, n + m - 1)) a[i] *= c;\n    return a;\n}\n\ntemplate <class M> std::vector<M>\
    \ convolution_mod(std::vector<M>&& a, std::vector<M>&& b) {\n    const usize n\
    \ = a.size(), m = b.size();\n    if (n == 0 || m == 0) return {};\n    if (std::min(n,\
    \ m) <= 60) return convolution_naive(a, b);\n    return convolution_ntt(std::move(a),\
    \ std::move(b));\n}\n\ntemplate <class M> std::vector<M> convolution_mod(const\
    \ std::vector<M>& a, const std::vector<M>& b) {\n    const usize n = a.size(),\
    \ m = b.size();\n    if (n == 0 || m == 0) return {};\n    if (std::min(n, m)\
    \ <= 60) return convolution_naive(a, b);\n    return convolution_ntt(a, b);\n\
    }\n\ntemplate <class T, u32 MOD, std::enable_if_t<std::is_integral_v<T>>* = nullptr>\n\
    std::vector<T> convolution_mod(const std::vector<T>& a, const std::vector<T>&\
    \ b) {\n    const usize n = a.size(), m = b.size();\n    if (n == 0 || m == 0)\
    \ return {};\n    using M = StaticModint<MOD>;\n    std::vector<M> a2(n), b2(m);\n\
    \    for (const usize i : rep(0, n)) a2[i] = a[i];\n    for (const usize i : rep(0,\
    \ m)) b2[i] = b[i];\n    std::vector<M> c2 = convolution_mod(std::move(a2), std::move(b2));\n\
    \    std::vector<T> c(n + m - 1);\n    for (const usize i : rep(0, n + m - 1))\
    \ c[i] = c2[i].val();\n    return c;\n}\n#line 9 \"algorithm/convolution_arbitrary_mod.cpp\"\
    \n\ntemplate <class T>\nstd::vector<T> convolution_arbitrary_mod(const std::vector<T>&\
    \ a, const std::vector<T>& b, const T& mod) {\n    const usize n = a.size(), m\
    \ = b.size();\n    if (n == 0 || m == 0) return {};\n    static constexpr u64\
    \ MOD1 = 754974721, MOD2 = 167772161, MOD3 = 469762049;\n    static constexpr\
    \ u64 M1M2 = MOD1 * MOD2;\n    static constexpr u64 I2 = mod_inv(MOD1, MOD2);\n\
    \    static constexpr u64 I3 = mod_inv(M1M2, MOD3);\n    std::vector<T> c1 = convolution_mod<T,\
    \ MOD1>(a, b);\n    std::vector<T> c2 = convolution_mod<T, MOD2>(a, b);\n    std::vector<T>\
    \ c3 = convolution_mod<T, MOD3>(a, b);\n    std::vector<T> c(n + m - 1);\n   \
    \ for (const usize i : rep(0, n + m - 1)) {\n        const u32 x = c1[i];\n  \
    \      const u64 y = (u64)(c2[i] + MOD2 - x % MOD2) * I2 % MOD2 * MOD1 + x;\n\
    \        c[i] = ((u128)(c3[i] + MOD3 - y % MOD3) * I3 % MOD3 * M1M2 + y) % mod;\n\
    \    }\n    return c;\n}\n\ntemplate <class M> std::vector<M> convolution_arbitrary_mod(const\
    \ std::vector<M>& a, const std::vector<M>& b) {\n    const usize n = a.size(),\
    \ m = b.size();\n    if (n == 0 || m == 0) return {};\n    std::vector<u32> a2(n),\
    \ b2(m);\n    for (const usize i : rep(0, n)) a2[i] = a[i].val();\n    for (const\
    \ usize i : rep(0, m)) b2[i] = b[i].val();\n    std::vector<u32> c2 = convolution_arbitrary_mod(a2,\
    \ b2, M::mod());\n    std::vector<M> c(n + m - 1);\n    for (const usize i : rep(0,\
    \ n + m - 1)) c[i] = c2[i];\n    return c;\n}\n#line 8 \"test/convolution_arbitrary_mod.test.cpp\"\
    \n\nusing Fp = Modint1000000007;\n\nint main() {\n    usize n, m;\n    std::cin\
    \ >> n >> m;\n    std::vector<Fp> a(n), b(m);\n    for (auto& x : a) {\n     \
    \   u32 t;\n        std::cin >> t;\n        x = t;\n    }\n    for (auto& x :\
    \ b) {\n        u32 t;\n        std::cin >> t;\n        x = t;\n    }\n    const\
    \ auto c = convolution_arbitrary_mod(std::move(a), std::move(b));\n    for (const\
    \ auto i : rep(0, c.size())) {\n        std::cout << c[i] << \" \\n\"[i + 1 ==\
    \ c.size()];\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
    \n#include <iostream>\n#include <vector>\n#include \"../algorithm/convolution_arbitrary_mod.cpp\"\
    \n#include \"../math/static_modint.cpp\"\n#include \"../utility/int_alias.cpp\"\
    \n#include \"../utility/rep.cpp\"\n\nusing Fp = Modint1000000007;\n\nint main()\
    \ {\n    usize n, m;\n    std::cin >> n >> m;\n    std::vector<Fp> a(n), b(m);\n\
    \    for (auto& x : a) {\n        u32 t;\n        std::cin >> t;\n        x =\
    \ t;\n    }\n    for (auto& x : b) {\n        u32 t;\n        std::cin >> t;\n\
    \        x = t;\n    }\n    const auto c = convolution_arbitrary_mod(std::move(a),\
    \ std::move(b));\n    for (const auto i : rep(0, c.size())) {\n        std::cout\
    \ << c[i] << \" \\n\"[i + 1 == c.size()];\n    }\n    return 0;\n}"
  dependsOn:
  - algorithm/convolution_arbitrary_mod.cpp
  - math/mod_inv.cpp
  - math/inv_gcd.cpp
  - math/rem_euclid.cpp
  - utility/int_alias.cpp
  - utility/int_alias_extended.cpp
  - utility/rep.cpp
  - algorithm/convolution_mod.cpp
  - bit/ceil_log2.cpp
  - math/modulo_transform.cpp
  - bit/bit_rzeros.cpp
  - utility/revrep.cpp
  - math/primitive_root.cpp
  - math/mod_pow.cpp
  - math/barret_reduction.cpp
  - math/static_modint.cpp
  - math/totient.cpp
  isVerificationFile: true
  path: test/convolution_arbitrary_mod.test.cpp
  requiredBy: []
  timestamp: '2021-11-10 20:31:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/convolution_arbitrary_mod.test.cpp
layout: document
redirect_from:
- /verify/test/convolution_arbitrary_mod.test.cpp
- /verify/test/convolution_arbitrary_mod.test.cpp.html
title: test/convolution_arbitrary_mod.test.cpp
---
