---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/barret_reduction.cpp
    title: math/barret_reduction.cpp
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
  - icon: ':heavy_check_mark:'
    path: algorithm/convolution_mod.cpp
    title: algorithm/convolution_mod.cpp
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
  bundledCode: "#line 2 \"math/modulo_transform.cpp\"\n#include <array>\n#include\
    \ <vector>\n#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n\nusing i32\
    \ = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing\
    \ u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    #line 3 \"utility/countr_zero.cpp\"\n\n__attribute__((target(\"avx2\"))) constexpr\
    \ int countr_zero(const u64 x) { return x == 0 ? 64 : __builtin_ctzll(x); }\n\
    #line 2 \"utility/rep.cpp\"\n#include <algorithm>\n\nclass Range {\n    struct\
    \ Iter {\n        int itr;\n        constexpr Iter(const int pos) noexcept : itr(pos)\
    \ {}\n        constexpr void operator++() noexcept { ++itr; }\n        constexpr\
    \ bool operator!=(const Iter& other) const noexcept { return itr != other.itr;\
    \ }\n        constexpr int operator*() const noexcept { return itr; }\n    };\n\
    \    const Iter first, last;\n\n  public:\n    explicit constexpr Range(const\
    \ int first, const int last) noexcept : first(first), last(std::max(first, last))\
    \ {}\n    constexpr Iter begin() const noexcept { return first; }\n    constexpr\
    \ Iter end() const noexcept { return last; }\n};\n\nconstexpr Range rep(const\
    \ int l, const int r) noexcept { return Range(l, r); }\nconstexpr Range rep(const\
    \ int n) noexcept { return Range(0, n); }\n#line 3 \"utility/revrep.cpp\"\n\n\
    class ReversedRange {\n    struct Iter {\n        int itr;\n        constexpr\
    \ Iter(const int pos) noexcept : itr(pos) {}\n        constexpr void operator++()\
    \ noexcept { --itr; }\n        constexpr bool operator!=(const Iter& other) const\
    \ noexcept { return itr != other.itr; }\n        constexpr int operator*() const\
    \ noexcept { return itr; }\n    };\n    const Iter first, last;\n\n  public:\n\
    \    explicit constexpr ReversedRange(const int first, const int last) noexcept\n\
    \        : first(last - 1), last(std::min(first, last) - 1) {}\n    constexpr\
    \ Iter begin() const noexcept { return first; }\n    constexpr Iter end() const\
    \ noexcept { return last; }\n};\n\nconstexpr ReversedRange revrep(const int l,\
    \ const int r) noexcept { return ReversedRange(l, r); }\nconstexpr ReversedRange\
    \ revrep(const int n) noexcept { return ReversedRange(0, n); }\n#line 2 \"math/mod_pow.cpp\"\
    \n#include <cassert>\n#include <type_traits>\n#line 3 \"math/barret_reduction.cpp\"\
    \n\nclass BarretReduction {\n    u32 mod;\n    u64 near_inv;\n\n  public:\n  \
    \  explicit constexpr BarretReduction(const u32 mod) noexcept : mod(mod), near_inv((u64)(-1)\
    \ / mod + 1) {}\n    constexpr u32 product(const u32 a, const u32 b) const noexcept\
    \ {\n        const u64 z = (u64)a * b;\n        const u64 x = ((u128)z * near_inv)\
    \ >> 64;\n        const u32 v = z - x * mod;\n        return v < mod ? v : v +\
    \ mod;\n    }\n    constexpr u32 get_mod() const noexcept { return mod; }\n};\n\
    #line 3 \"math/rem_euclid.cpp\"\n\ntemplate <class T> constexpr T rem_euclid(T\
    \ value, const T& mod) {\n    assert(mod > 0);\n    return (value %= mod) >= 0\
    \ ? value : value + mod;\n}\n#line 7 \"math/mod_pow.cpp\"\n\ntemplate <class T>\
    \ constexpr u32 mod_pow(T x, u64 exp, const u32 mod) {\n    assert(mod > 0);\n\
    \    if (mod == 1) return 0;\n    const BarretReduction bt(mod);\n    u32 ret\
    \ = 1, mul = rem_euclid<std::common_type_t<T, i64>>(x, mod);\n    for (; exp >\
    \ 0; exp >>= 1) {\n        if (exp & 1) ret = bt.product(ret, mul);\n        mul\
    \ = bt.product(mul, mul);\n    }\n    return ret;\n}\n#line 5 \"math/primitive_root.cpp\"\
    \n\nconstexpr u32 primitive_root(const u32 mod) {\n    std::array<u32, 32> exp{};\n\
    \    u32 cur = mod - 1;\n    int size = 0;\n    for (u32 i = 2; i * i <= cur;\
    \ ++i) {\n        if (cur % i == 0) {\n            exp[size++] = (mod - 1) / i;\n\
    \            while (cur % i == 0) cur /= i;\n        }\n    }\n    if (cur !=\
    \ 1) exp[size++] = (mod - 1) / cur;\n    for (u32 check = 1; check < mod; ++check)\
    \ {\n        for (const u32 e : exp) {\n            if (e == 0) return check;\n\
    \            if (mod_pow(check, e, mod) == 1) break;\n        }\n    }\n    return\
    \ mod;\n}\n#line 9 \"math/modulo_transform.cpp\"\n\ntemplate <class M> struct\
    \ ModuloTransform {\n    static constexpr u32 ROOT = primitive_root(M::mod());\n\
    \    static constexpr int RANK = countr_zero(M::mod() - 1);\n\n    std::array<M,\
    \ RANK + 1> root, iroot;\n    std::array<M, (RANK >= 2 ? RANK - 2 + 1 : 0)> rate2,\
    \ irate2;\n    std::array<M, (RANK >= 3 ? RANK - 3 + 1 : 0)> rate3, irate3;\n\n\
    \    constexpr ModuloTransform() : root(), iroot(), rate2(), irate2(), rate3(),\
    \ irate3() {\n        root[RANK] = M(ROOT).pow((M::mod() - 1) >> RANK);\n    \
    \    iroot[RANK] = root[RANK].inv();\n        for (const int i : revrep(0, RANK))\
    \ {\n            root[i] = root[i + 1] * root[i + 1];\n            iroot[i] =\
    \ iroot[i + 1] * iroot[i + 1];\n        }\n        M prod = 1, iprod = 1;\n  \
    \      for (const int i : rep(2, RANK + 1)) {\n            rate2[i - 2] = root[i]\
    \ * prod;\n            irate2[i - 2] = iroot[i] * iprod;\n            prod *=\
    \ iroot[i];\n            iprod *= root[i];\n        }\n        prod = 1, iprod\
    \ = 1;\n        for (const int i : rep(3, RANK + 1)) {\n            rate3[i -\
    \ 3] = root[i] * prod;\n            irate3[i - 3] = iroot[i] * iprod;\n      \
    \      prod *= iroot[i];\n            iprod *= root[i];\n        }\n    }\n\n\
    \    void butterfly(std::vector<M>& a) const {\n        const int n = a.size();\n\
    \        const int h = countr_zero(n);\n        for (int len = 0; len < h;) {\n\
    \            if (len + 1 == h) {\n                M rot = 1;\n               \
    \ for (const int s : rep(0, 1 << len)) {\n                    const int t = s\
    \ << 1;\n                    const M l = a[t], r = a[t + 1] * rot;\n         \
    \           a[t] = l + r;\n                    a[t + 1] = l - r;\n           \
    \         if (((s + 1) >> len) == 0) rot *= rate2[countr_zero(~s)];\n        \
    \        }\n                len += 1;\n            } else {\n                const\
    \ int p = 1 << (h - len - 2);\n                M rot = 1;\n                for\
    \ (const int s : rep(0, 1 << len)) {\n                    const int t = s << (h\
    \ - len);\n                    const M rot2 = rot * rot;\n                   \
    \ const M rot3 = rot2 * rot;\n                    for (const int i : rep(0, p))\
    \ {\n                        const M a0 = a[i + t];\n                        const\
    \ M a1 = a[i + t + p] * rot;\n                        const M a2 = a[i + t + p\
    \ * 2] * rot2;\n                        const M a3 = a[i + t + p * 3] * rot3;\n\
    \                        const M ax = (a1 - a3) * root[2];\n                 \
    \       a[i + t] = a0 + a1 + a2 + a3;\n                        a[i + t + p] =\
    \ a0 - a1 + a2 - a3;\n                        a[i + t + p * 2] = a0 - a2 + ax;\n\
    \                        a[i + t + p * 3] = a0 - a2 - ax;\n                  \
    \  }\n                    if (((s + 1) >> len) == 0) rot *= rate3[countr_zero(~s)];\n\
    \                }\n                len += 2;\n            }\n        }\n    }\n\
    \n    void butterfly_inv(std::vector<M>& a) const {\n        const int n = a.size();\n\
    \        const int h = countr_zero(n);\n        for (int len = h; len > 0;) {\n\
    \            if (len == 1) {\n                const int p = n >> 1;\n        \
    \        for (const int i : rep(0, p)) {\n                    const M l = a[i],\
    \ r = a[i + p];\n                    a[i] = l + r;\n                    a[i +\
    \ p] = l - r;\n                }\n                len -= 1;\n            } else\
    \ {\n                const int p = 1 << (h - len);\n                M rot = 1;\n\
    \                for (const int s : rep(0, 1 << (len - 2))) {\n              \
    \      const int t = s << (h - len + 2);\n                    const M rot2 = rot\
    \ * rot;\n                    const M rot3 = rot2 * rot;\n                   \
    \ for (const int i : rep(0, p)) {\n                        const M a0 = a[i +\
    \ t];\n                        const M a1 = a[i + t + p];\n                  \
    \      const M a2 = a[i + t + p * 2];\n                        const M a3 = a[i\
    \ + t + p * 3];\n                        const M ax = (a2 - a3) * iroot[2];\n\
    \                        a[i + t] = a0 + a1 + a2 + a3;\n                     \
    \   a[i + t + p] = (a0 - a1 + ax) * rot;\n                        a[i + t + p\
    \ * 2] = (a0 + a1 - a2 - a3) * rot2;\n                        a[i + t + p * 3]\
    \ = (a0 - a1 - ax) * rot3;\n                    }\n                    if (((s\
    \ + 1) >> (len - 2)) == 0) rot *= irate3[countr_zero(~s)];\n                }\n\
    \                len -= 2;\n            }\n        }\n    }\n};\n"
  code: "#pragma once\n#include <array>\n#include <vector>\n#include \"../utility/countr_zero.cpp\"\
    \n#include \"../utility/int_alias.cpp\"\n#include \"../utility/rep.cpp\"\n#include\
    \ \"../utility/revrep.cpp\"\n#include \"primitive_root.cpp\"\n\ntemplate <class\
    \ M> struct ModuloTransform {\n    static constexpr u32 ROOT = primitive_root(M::mod());\n\
    \    static constexpr int RANK = countr_zero(M::mod() - 1);\n\n    std::array<M,\
    \ RANK + 1> root, iroot;\n    std::array<M, (RANK >= 2 ? RANK - 2 + 1 : 0)> rate2,\
    \ irate2;\n    std::array<M, (RANK >= 3 ? RANK - 3 + 1 : 0)> rate3, irate3;\n\n\
    \    constexpr ModuloTransform() : root(), iroot(), rate2(), irate2(), rate3(),\
    \ irate3() {\n        root[RANK] = M(ROOT).pow((M::mod() - 1) >> RANK);\n    \
    \    iroot[RANK] = root[RANK].inv();\n        for (const int i : revrep(0, RANK))\
    \ {\n            root[i] = root[i + 1] * root[i + 1];\n            iroot[i] =\
    \ iroot[i + 1] * iroot[i + 1];\n        }\n        M prod = 1, iprod = 1;\n  \
    \      for (const int i : rep(2, RANK + 1)) {\n            rate2[i - 2] = root[i]\
    \ * prod;\n            irate2[i - 2] = iroot[i] * iprod;\n            prod *=\
    \ iroot[i];\n            iprod *= root[i];\n        }\n        prod = 1, iprod\
    \ = 1;\n        for (const int i : rep(3, RANK + 1)) {\n            rate3[i -\
    \ 3] = root[i] * prod;\n            irate3[i - 3] = iroot[i] * iprod;\n      \
    \      prod *= iroot[i];\n            iprod *= root[i];\n        }\n    }\n\n\
    \    void butterfly(std::vector<M>& a) const {\n        const int n = a.size();\n\
    \        const int h = countr_zero(n);\n        for (int len = 0; len < h;) {\n\
    \            if (len + 1 == h) {\n                M rot = 1;\n               \
    \ for (const int s : rep(0, 1 << len)) {\n                    const int t = s\
    \ << 1;\n                    const M l = a[t], r = a[t + 1] * rot;\n         \
    \           a[t] = l + r;\n                    a[t + 1] = l - r;\n           \
    \         if (((s + 1) >> len) == 0) rot *= rate2[countr_zero(~s)];\n        \
    \        }\n                len += 1;\n            } else {\n                const\
    \ int p = 1 << (h - len - 2);\n                M rot = 1;\n                for\
    \ (const int s : rep(0, 1 << len)) {\n                    const int t = s << (h\
    \ - len);\n                    const M rot2 = rot * rot;\n                   \
    \ const M rot3 = rot2 * rot;\n                    for (const int i : rep(0, p))\
    \ {\n                        const M a0 = a[i + t];\n                        const\
    \ M a1 = a[i + t + p] * rot;\n                        const M a2 = a[i + t + p\
    \ * 2] * rot2;\n                        const M a3 = a[i + t + p * 3] * rot3;\n\
    \                        const M ax = (a1 - a3) * root[2];\n                 \
    \       a[i + t] = a0 + a1 + a2 + a3;\n                        a[i + t + p] =\
    \ a0 - a1 + a2 - a3;\n                        a[i + t + p * 2] = a0 - a2 + ax;\n\
    \                        a[i + t + p * 3] = a0 - a2 - ax;\n                  \
    \  }\n                    if (((s + 1) >> len) == 0) rot *= rate3[countr_zero(~s)];\n\
    \                }\n                len += 2;\n            }\n        }\n    }\n\
    \n    void butterfly_inv(std::vector<M>& a) const {\n        const int n = a.size();\n\
    \        const int h = countr_zero(n);\n        for (int len = h; len > 0;) {\n\
    \            if (len == 1) {\n                const int p = n >> 1;\n        \
    \        for (const int i : rep(0, p)) {\n                    const M l = a[i],\
    \ r = a[i + p];\n                    a[i] = l + r;\n                    a[i +\
    \ p] = l - r;\n                }\n                len -= 1;\n            } else\
    \ {\n                const int p = 1 << (h - len);\n                M rot = 1;\n\
    \                for (const int s : rep(0, 1 << (len - 2))) {\n              \
    \      const int t = s << (h - len + 2);\n                    const M rot2 = rot\
    \ * rot;\n                    const M rot3 = rot2 * rot;\n                   \
    \ for (const int i : rep(0, p)) {\n                        const M a0 = a[i +\
    \ t];\n                        const M a1 = a[i + t + p];\n                  \
    \      const M a2 = a[i + t + p * 2];\n                        const M a3 = a[i\
    \ + t + p * 3];\n                        const M ax = (a2 - a3) * iroot[2];\n\
    \                        a[i + t] = a0 + a1 + a2 + a3;\n                     \
    \   a[i + t + p] = (a0 - a1 + ax) * rot;\n                        a[i + t + p\
    \ * 2] = (a0 + a1 - a2 - a3) * rot2;\n                        a[i + t + p * 3]\
    \ = (a0 - a1 - ax) * rot3;\n                    }\n                    if (((s\
    \ + 1) >> (len - 2)) == 0) rot *= irate3[countr_zero(~s)];\n                }\n\
    \                len -= 2;\n            }\n        }\n    }\n};\n"
  dependsOn:
  - utility/countr_zero.cpp
  - utility/int_alias.cpp
  - utility/rep.cpp
  - utility/revrep.cpp
  - math/primitive_root.cpp
  - math/mod_pow.cpp
  - math/barret_reduction.cpp
  - math/rem_euclid.cpp
  isVerificationFile: false
  path: math/modulo_transform.cpp
  requiredBy:
  - algorithm/convolution_mod.cpp
  - algorithm/convolution_arbitrary_mod.cpp
  - algorithm/convolution_int.cpp
  timestamp: '2021-12-17 09:20:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution_arbitrary_mod.test.cpp
  - test/convolution_mod.test.cpp
documentation_of: math/modulo_transform.cpp
layout: document
redirect_from:
- /library/math/modulo_transform.cpp
- /library/math/modulo_transform.cpp.html
title: math/modulo_transform.cpp
---
