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
    path: math/rem_euclid.cpp
    title: math/rem_euclid.cpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
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
  - icon: ':heavy_check_mark:'
    path: math/modulo_transform.cpp
    title: math/modulo_transform.cpp
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
  bundledCode: "#line 2 \"math/primitive_root.cpp\"\n#include <array>\n#line 2 \"\
    utility/int_alias.cpp\"\n#include <cstdint>\n\nusing i32 = std::int32_t;\nusing\
    \ u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n#line 2 \"math/mod_pow.cpp\"\
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
    \ mod;\n}\n"
  code: "#pragma once\n#include <array>\n#include \"../utility/int_alias.cpp\"\n#include\
    \ \"mod_pow.cpp\"\n\nconstexpr u32 primitive_root(const u32 mod) {\n    std::array<u32,\
    \ 32> exp{};\n    u32 cur = mod - 1;\n    int size = 0;\n    for (u32 i = 2; i\
    \ * i <= cur; ++i) {\n        if (cur % i == 0) {\n            exp[size++] = (mod\
    \ - 1) / i;\n            while (cur % i == 0) cur /= i;\n        }\n    }\n  \
    \  if (cur != 1) exp[size++] = (mod - 1) / cur;\n    for (u32 check = 1; check\
    \ < mod; ++check) {\n        for (const u32 e : exp) {\n            if (e == 0)\
    \ return check;\n            if (mod_pow(check, e, mod) == 1) break;\n       \
    \ }\n    }\n    return mod;\n}\n"
  dependsOn:
  - utility/int_alias.cpp
  - math/mod_pow.cpp
  - math/barret_reduction.cpp
  - math/rem_euclid.cpp
  isVerificationFile: false
  path: math/primitive_root.cpp
  requiredBy:
  - math/modulo_transform.cpp
  - algorithm/convolution_mod.cpp
  - algorithm/convolution_arbitrary_mod.cpp
  - algorithm/convolution_int.cpp
  timestamp: '2021-12-17 09:20:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution_arbitrary_mod.test.cpp
  - test/convolution_mod.test.cpp
documentation_of: math/primitive_root.cpp
layout: document
redirect_from:
- /library/math/primitive_root.cpp
- /library/math/primitive_root.cpp.html
title: math/primitive_root.cpp
---
