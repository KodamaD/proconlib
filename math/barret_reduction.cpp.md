---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias_extended.cpp
    title: utility/int_alias_extended.cpp
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
  - icon: ':warning:'
    path: math/dynamic_modint.cpp
    title: math/dynamic_modint.cpp
  - icon: ':heavy_check_mark:'
    path: math/mod_pow.cpp
    title: math/mod_pow.cpp
  - icon: ':heavy_check_mark:'
    path: math/modulo_transform.cpp
    title: math/modulo_transform.cpp
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
  bundledCode: "#line 2 \"utility/int_alias.cpp\"\n#include <cstddef>\n#include <cstdint>\n\
    \nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing isize = std::ptrdiff_t;\nusing usize = std::size_t;\n\
    #line 4 \"utility/int_alias_extended.cpp\"\n\nusing i8 = std::int8_t;\nusing u8\
    \ = std::uint8_t;\nusing i16 = std::int16_t;\nusing u16 = std::uint16_t;\nusing\
    \ i128 = __int128_t;\nusing u128 = __uint128_t;\n#line 4 \"math/barret_reduction.cpp\"\
    \n\nclass BarretReduction {\n    u32 mod;\n    u64 near_inv;\n\n  public:\n  \
    \  explicit constexpr BarretReduction(const u32 mod) noexcept : mod(mod), near_inv((u64)(-1)\
    \ / mod + 1) {}\n    constexpr u32 product(const u32 a, const u32 b) const noexcept\
    \ {\n        const u64 z = (u64)a * b;\n        const u64 x = ((u128)z * near_inv)\
    \ >> 64;\n        const u32 v = z - x * mod;\n        return v < mod ? v : v +\
    \ mod;\n    }\n};\n"
  code: "#pragma once\n#include \"../utility/int_alias.cpp\"\n#include \"../utility/int_alias_extended.cpp\"\
    \n\nclass BarretReduction {\n    u32 mod;\n    u64 near_inv;\n\n  public:\n  \
    \  explicit constexpr BarretReduction(const u32 mod) noexcept : mod(mod), near_inv((u64)(-1)\
    \ / mod + 1) {}\n    constexpr u32 product(const u32 a, const u32 b) const noexcept\
    \ {\n        const u64 z = (u64)a * b;\n        const u64 x = ((u128)z * near_inv)\
    \ >> 64;\n        const u32 v = z - x * mod;\n        return v < mod ? v : v +\
    \ mod;\n    }\n};"
  dependsOn:
  - utility/int_alias.cpp
  - utility/int_alias_extended.cpp
  isVerificationFile: false
  path: math/barret_reduction.cpp
  requiredBy:
  - math/modulo_transform.cpp
  - math/mod_pow.cpp
  - math/primitive_root.cpp
  - math/dynamic_modint.cpp
  - algorithm/convolution_mod.cpp
  - algorithm/convolution_int.cpp
  - algorithm/convolution_arbitrary_mod.cpp
  timestamp: '2021-11-01 18:27:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution_mod.test.cpp
  - test/convolution_arbitrary_mod.test.cpp
documentation_of: math/barret_reduction.cpp
layout: document
redirect_from:
- /library/math/barret_reduction.cpp
- /library/math/barret_reduction.cpp.html
title: math/barret_reduction.cpp
---
