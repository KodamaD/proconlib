---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bit/bit_reverse.cpp
    title: bit/bit_reverse.cpp
  - icon: ':heavy_check_mark:'
    path: bit/bit_rzeros.cpp
    title: bit/bit_rzeros.cpp
  - icon: ':heavy_check_mark:'
    path: bit/ceil_log2.cpp
    title: bit/ceil_log2.cpp
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
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':heavy_check_mark:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  - icon: ':heavy_check_mark:'
    path: utility/revrep.cpp
    title: utility/revrep.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution.test.cpp
    title: test/convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/convolution.cpp\"\n#include <vector>\n#include <utility>\n\
    #include <array>\n#include <algorithm>\n#line 2 \"utility/int_alias.cpp\"\n#include\
    \ <cstdint>\n#include <cstddef>\n\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\n\
    using i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\nusing isize = std::ptrdiff_t;\nusing usize = std::size_t;\n\
    #line 4 \"utility/rep.cpp\"\n\nclass rep {\n    struct Iter {\n        usize itr;\n\
    \        constexpr Iter(const usize pos) noexcept: itr(pos) { }\n        constexpr\
    \ void operator ++ () noexcept { ++itr; }\n        constexpr bool operator !=\
    \ (const Iter& other) const noexcept { return itr != other.itr; }\n        constexpr\
    \ usize operator * () const noexcept { return itr; }\n    };\n    const Iter first,\
    \ last;\npublic:\n    explicit constexpr rep(const usize first, const usize last)\
    \ noexcept: first(first), last(std::max(first, last)) { }\n    constexpr Iter\
    \ begin() const noexcept { return first; }\n    constexpr Iter end() const noexcept\
    \ { return last; }\n};\n#line 4 \"utility/revrep.cpp\"\n\nclass revrep {\n   \
    \ struct Iter {\n        usize itr;\n        constexpr Iter(const usize pos) noexcept:\
    \ itr(pos) { }\n        constexpr void operator ++ () noexcept { --itr; }\n  \
    \      constexpr bool operator != (const Iter& other) const noexcept { return\
    \ itr != other.itr; }\n        constexpr usize operator * () const noexcept {\
    \ return itr; }\n    };\n    const Iter first, last;\npublic:\n    explicit constexpr\
    \ revrep(const usize first, const usize last) noexcept: first(last - 1), last(std::min(first,\
    \ last) - 1) { }\n    constexpr Iter begin() const noexcept { return first; }\n\
    \    constexpr Iter end() const noexcept { return last; }\n};\n#line 3 \"bit/ceil_log2.cpp\"\
    \n\nconstexpr u64 ceil_log2(const u64 x) {\n    u64 e = 0;\n    while (((u64)\
    \ 1 << e) < x) ++e;\n    return e;\n}\n#line 3 \"bit/bit_rzeros.cpp\"\n\nconstexpr\
    \ u64 bit_rzeros(const u64 x) {\n    return x == 0 ? 64 : __builtin_ctzll(x);\n\
    }\n#line 3 \"bit/bit_reverse.cpp\"\n\nconstexpr u64 bit_reverse(u64 x) {\n   \
    \ x = ((x >> 1) & 0x5555555555555555) | ((x & 0x5555555555555555) << 1);\n   \
    \ x = ((x >> 2) & 0x3333333333333333) | ((x & 0x3333333333333333) << 2);\n   \
    \ x = ((x >> 4) & 0x0F0F0F0F0F0F0F0F) | ((x & 0x0F0F0F0F0F0F0F0F) << 4);\n   \
    \ x = ((x >> 8) & 0x00FF00FF00FF00FF) | ((x & 0x00FF00FF00FF00FF) << 8);\n   \
    \ x = ((x >> 16) & 0x0000FFFF0000FFFF) | ((x & 0x0000FFFF0000FFFF) << 16);\n \
    \   x = (x >> 32) | (x << 32);\n    return x;\n}\n#line 2 \"math/rem_euclid.cpp\"\
    \n\ntemplate <class T>\nconstexpr T rem_euclid(T value, const T& mod) {\n    return\
    \ (value %= mod) >= 0 ? value : value + mod;\n}\n#line 3 \"math/mod_pow.cpp\"\n\
    #include <cassert>\n\ntemplate <class T>\nconstexpr T mod_pow(T x, u64 exp, const\
    \ T& mod) {\n    assert(mod > 0);\n    T ret = T(1) % mod;\n    x = rem_euclid(x,\
    \ mod);\n    for (; exp > 0; exp >>= 1) {\n        if (exp & 1) ret = ret * x\
    \ % mod;\n        x = x * x % mod;\n    }\n    return ret;\n}\n#line 5 \"math/primitive_root.cpp\"\
    \n\nconstexpr u32 primitive_root(const u32 mod) {\n    std::array<u32, 32> exp{};\n\
    \    u32 cur = mod - 1;\n    usize size = 0;\n    for (u32 i = 2; i * i <= cur;\
    \ ++i) {\n        if (cur % i == 0) {\n            exp[size++] = (mod - 1) / i;\n\
    \            while (cur % i == 0) cur /= i;\n        }\n    }\n    if (cur !=\
    \ 1) exp[size++] = (mod - 1) / cur;\n    for (u32 check = 1; check < mod; ++check)\
    \ {\n        for (const auto e: exp) {\n            if (e == 0) return check;\n\
    \            if (mod_pow<u64>(check, e, mod) == 1) break;\n        }\n    }\n\
    \    return mod;\n}\n#line 13 \"math/convolution.cpp\"\n\ntemplate <class M, bool\
    \ INV = false>\nvoid modulo_transform(std::vector<M>& f) {\n    static constexpr\
    \ u32 MOD = M::mod();\n    static constexpr u32 ROOT = primitive_root(MOD);\n\
    \    static constexpr usize LEVEL = bit_rzeros(MOD - 1);\n    static constexpr\
    \ auto COEFF = [] {\n        std::array<M, LEVEL> ret{};\n        ret[LEVEL -\
    \ 1] = M(ROOT).pow((MOD - 1) >> LEVEL);\n        if (INV) ret[LEVEL - 1] = ret[LEVEL\
    \ - 1].inv();\n        for (const usize i: revrep(1, LEVEL)) {\n            ret[i\
    \ - 1] = ret[i] * ret[i];\n        }\n        return ret;\n    }();\n    const\
    \ usize size = f.size();\n    const usize logn = bit_rzeros(size);\n    for (const\
    \ usize i: rep(0, size)) {\n        const usize j = bit_reverse(i) >> (64 - logn);\n\
    \        if (i < j) std::swap(f[i], f[j]);\n    }\n    for (const usize s: rep(0,\
    \ logn)) {\n        const usize mh = (usize) 1 << s;\n        const usize m =\
    \ mh << 1;\n        for (usize i = 0; i < size; i += m) {\n            M coeff\
    \ = M(1);\n            for (const usize j: rep(i, i + mh)) {\n               \
    \ const M a = f[j];\n                const M b = f[j + mh] * coeff;\n        \
    \        f[j] = a + b;\n                f[j + mh] = a - b;\n                coeff\
    \ *= COEFF[s];\n            }\n        }\n    }\n}\n\ntemplate <class M>\nstd::vector<M>\
    \ convolution(const std::vector<M>& a, const std::vector<M>& b) {\n    const usize\
    \ min = std::min(a.size(), b.size());\n    if (min == 0) return { };\n    if (min\
    \ <= 60) {\n        std::vector<M> ret(a.size() + b.size() - 1, M(0));\n     \
    \   for (const usize i: rep(0, a.size()))\n            for (const usize j: rep(0,\
    \ b.size()))\n                ret[i + j] += a[i] * b[j];\n        return ret;\n\
    \    }\n    const usize size = (usize) 1 << ceil_log2(a.size() + b.size() - 1);\n\
    \    std::vector<M> f(size, M(0)), g(size, M(0));\n    std::copy(a.cbegin(), a.cend(),\
    \ f.begin());\n    std::copy(b.cbegin(), b.cend(), g.begin());\n    modulo_transform(f);\n\
    \    modulo_transform(g);\n    for (const usize i: rep(0, size)) f[i] *= g[i];\n\
    \    modulo_transform<M, true>(f);\n    f.resize(a.size() + b.size() - 1);\n \
    \   const M inv = M(size).inv();\n    for (auto& x: f) x *= inv;\n    return f;\n\
    }\n"
  code: "#pragma once\n#include <vector>\n#include <utility>\n#include <array>\n#include\
    \ <algorithm>\n#include \"../utility/int_alias.cpp\"\n#include \"../utility/rep.cpp\"\
    \n#include \"../utility/revrep.cpp\"\n#include \"../bit/ceil_log2.cpp\"\n#include\
    \ \"../bit/bit_rzeros.cpp\"\n#include \"../bit/bit_reverse.cpp\"\n#include \"\
    ../math/primitive_root.cpp\"\n\ntemplate <class M, bool INV = false>\nvoid modulo_transform(std::vector<M>&\
    \ f) {\n    static constexpr u32 MOD = M::mod();\n    static constexpr u32 ROOT\
    \ = primitive_root(MOD);\n    static constexpr usize LEVEL = bit_rzeros(MOD -\
    \ 1);\n    static constexpr auto COEFF = [] {\n        std::array<M, LEVEL> ret{};\n\
    \        ret[LEVEL - 1] = M(ROOT).pow((MOD - 1) >> LEVEL);\n        if (INV) ret[LEVEL\
    \ - 1] = ret[LEVEL - 1].inv();\n        for (const usize i: revrep(1, LEVEL))\
    \ {\n            ret[i - 1] = ret[i] * ret[i];\n        }\n        return ret;\n\
    \    }();\n    const usize size = f.size();\n    const usize logn = bit_rzeros(size);\n\
    \    for (const usize i: rep(0, size)) {\n        const usize j = bit_reverse(i)\
    \ >> (64 - logn);\n        if (i < j) std::swap(f[i], f[j]);\n    }\n    for (const\
    \ usize s: rep(0, logn)) {\n        const usize mh = (usize) 1 << s;\n       \
    \ const usize m = mh << 1;\n        for (usize i = 0; i < size; i += m) {\n  \
    \          M coeff = M(1);\n            for (const usize j: rep(i, i + mh)) {\n\
    \                const M a = f[j];\n                const M b = f[j + mh] * coeff;\n\
    \                f[j] = a + b;\n                f[j + mh] = a - b;\n         \
    \       coeff *= COEFF[s];\n            }\n        }\n    }\n}\n\ntemplate <class\
    \ M>\nstd::vector<M> convolution(const std::vector<M>& a, const std::vector<M>&\
    \ b) {\n    const usize min = std::min(a.size(), b.size());\n    if (min == 0)\
    \ return { };\n    if (min <= 60) {\n        std::vector<M> ret(a.size() + b.size()\
    \ - 1, M(0));\n        for (const usize i: rep(0, a.size()))\n            for\
    \ (const usize j: rep(0, b.size()))\n                ret[i + j] += a[i] * b[j];\n\
    \        return ret;\n    }\n    const usize size = (usize) 1 << ceil_log2(a.size()\
    \ + b.size() - 1);\n    std::vector<M> f(size, M(0)), g(size, M(0));\n    std::copy(a.cbegin(),\
    \ a.cend(), f.begin());\n    std::copy(b.cbegin(), b.cend(), g.begin());\n   \
    \ modulo_transform(f);\n    modulo_transform(g);\n    for (const usize i: rep(0,\
    \ size)) f[i] *= g[i];\n    modulo_transform<M, true>(f);\n    f.resize(a.size()\
    \ + b.size() - 1);\n    const M inv = M(size).inv();\n    for (auto& x: f) x *=\
    \ inv;\n    return f;\n}"
  dependsOn:
  - utility/int_alias.cpp
  - utility/rep.cpp
  - utility/revrep.cpp
  - bit/ceil_log2.cpp
  - bit/bit_rzeros.cpp
  - bit/bit_reverse.cpp
  - math/primitive_root.cpp
  - math/mod_pow.cpp
  - math/rem_euclid.cpp
  isVerificationFile: false
  path: math/convolution.cpp
  requiredBy: []
  timestamp: '2021-05-10 19:01:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution.test.cpp
documentation_of: math/convolution.cpp
layout: document
redirect_from:
- /library/math/convolution.cpp
- /library/math/convolution.cpp.html
title: math/convolution.cpp
---
