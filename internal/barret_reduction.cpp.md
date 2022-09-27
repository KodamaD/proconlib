---
data:
  _extendedDependsOn:
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
    path: internal/modulo_transform.cpp
    title: internal/modulo_transform.cpp
  - icon: ':warning:'
    path: math/dynamic_modint.cpp
    title: math/dynamic_modint.cpp
  - icon: ':heavy_check_mark:'
    path: math/mod_pow.cpp
    title: math/mod_pow.cpp
  - icon: ':heavy_check_mark:'
    path: math/primitive_root.cpp
    title: math/primitive_root.cpp
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
  bundledCode: "#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n\nusing i32\
    \ = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing\
    \ u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    #line 3 \"internal/barret_reduction.cpp\"\n\nnamespace proconlib {\n\nclass BarretReduction\
    \ {\n    u32 mod;\n    u64 near_inv;\n\n  public:\n    explicit constexpr BarretReduction(const\
    \ u32 mod) noexcept : mod(mod), near_inv((u64)(-1) / mod + 1) {}\n    constexpr\
    \ u32 product(const u32 a, const u32 b) const noexcept {\n        const u64 z\
    \ = (u64)a * b;\n        const u64 x = ((u128)z * near_inv) >> 64;\n        const\
    \ u32 v = z - x * mod;\n        return v < mod ? v : v + mod;\n    }\n    constexpr\
    \ u32 get_mod() const noexcept { return mod; }\n};\n\n}  // namespace proconlib\n"
  code: "#pragma once\n#include \"../utility/int_alias.cpp\"\n\nnamespace proconlib\
    \ {\n\nclass BarretReduction {\n    u32 mod;\n    u64 near_inv;\n\n  public:\n\
    \    explicit constexpr BarretReduction(const u32 mod) noexcept : mod(mod), near_inv((u64)(-1)\
    \ / mod + 1) {}\n    constexpr u32 product(const u32 a, const u32 b) const noexcept\
    \ {\n        const u64 z = (u64)a * b;\n        const u64 x = ((u128)z * near_inv)\
    \ >> 64;\n        const u32 v = z - x * mod;\n        return v < mod ? v : v +\
    \ mod;\n    }\n    constexpr u32 get_mod() const noexcept { return mod; }\n};\n\
    \n}  // namespace proconlib\n"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: internal/barret_reduction.cpp
  requiredBy:
  - algorithm/convolution_int.cpp
  - algorithm/convolution_arbitrary_mod.cpp
  - algorithm/convolution_mod.cpp
  - math/dynamic_modint.cpp
  - math/mod_pow.cpp
  - math/primitive_root.cpp
  - internal/modulo_transform.cpp
  timestamp: '2022-01-28 13:07:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution_arbitrary_mod.test.cpp
  - test/convolution_mod.test.cpp
documentation_of: internal/barret_reduction.cpp
layout: document
redirect_from:
- /library/internal/barret_reduction.cpp
- /library/internal/barret_reduction.cpp.html
title: internal/barret_reduction.cpp
---
