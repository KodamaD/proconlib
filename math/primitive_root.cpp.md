---
data:
  _extendedDependsOn:
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
    path: math/convolution.cpp
    title: math/convolution.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution.test.cpp
    title: test/convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n#include <cstddef>\n\
    \nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    using isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 2 \"math/rem_euclid.cpp\"\
    \n\ntemplate <class T>\nconstexpr T rem_euclid(T value, const T& mod) {\n    return\
    \ (value %= mod) >= 0 ? value : value + mod;\n}\n#line 3 \"math/mod_pow.cpp\"\n\
    #include <cassert>\n\ntemplate <class T>\nconstexpr T mod_pow(T x, u64 exp, const\
    \ T& mod) {\n    assert(mod > 0);\n    T ret = T(1) % mod;\n    x = rem_euclid(x,\
    \ mod);\n    for (; exp > 0; exp >>= 1) {\n        if (exp & 1) ret = ret * x\
    \ % mod;\n        x = x * x % mod;\n    }\n    return ret;\n}\n#line 4 \"math/primitive_root.cpp\"\
    \n#include <array>\n\nconstexpr u32 primitive_root(const u32 mod) {\n    std::array<u32,\
    \ 32> exp{};\n    u32 cur = mod - 1;\n    usize size = 0;\n    for (u32 i = 2;\
    \ i * i <= cur; ++i) {\n        if (cur % i == 0) {\n            exp[size++] =\
    \ (mod - 1) / i;\n            while (cur % i == 0) cur /= i;\n        }\n    }\n\
    \    if (cur != 1) exp[size++] = (mod - 1) / cur;\n    for (u32 check = 1; check\
    \ < mod; ++check) {\n        for (const auto e: exp) {\n            if (e == 0)\
    \ return check;\n            if (mod_pow<u64>(check, e, mod) == 1) break;\n  \
    \      }\n    }\n    return mod;\n}\n"
  code: "#pragma once\n#include \"../utility/int_alias.cpp\"\n#include \"../math/mod_pow.cpp\"\
    \n#include <array>\n\nconstexpr u32 primitive_root(const u32 mod) {\n    std::array<u32,\
    \ 32> exp{};\n    u32 cur = mod - 1;\n    usize size = 0;\n    for (u32 i = 2;\
    \ i * i <= cur; ++i) {\n        if (cur % i == 0) {\n            exp[size++] =\
    \ (mod - 1) / i;\n            while (cur % i == 0) cur /= i;\n        }\n    }\n\
    \    if (cur != 1) exp[size++] = (mod - 1) / cur;\n    for (u32 check = 1; check\
    \ < mod; ++check) {\n        for (const auto e: exp) {\n            if (e == 0)\
    \ return check;\n            if (mod_pow<u64>(check, e, mod) == 1) break;\n  \
    \      }\n    }\n    return mod;\n}\n"
  dependsOn:
  - utility/int_alias.cpp
  - math/mod_pow.cpp
  - math/rem_euclid.cpp
  isVerificationFile: false
  path: math/primitive_root.cpp
  requiredBy:
  - math/convolution.cpp
  timestamp: '2021-05-10 19:01:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution.test.cpp
documentation_of: math/primitive_root.cpp
layout: document
redirect_from:
- /library/math/primitive_root.cpp
- /library/math/primitive_root.cpp.html
title: math/primitive_root.cpp
---
