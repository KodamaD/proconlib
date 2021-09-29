---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/mod_pow.cpp
    title: math/mod_pow.cpp
  - icon: ':heavy_check_mark:'
    path: math/rem_euclid.cpp
    title: math/rem_euclid.cpp
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/primitive_root.cpp\"\n#include <array>\n#line 2 \"\
    math/mod_pow.cpp\"\n#include <cassert>\n#line 2 \"math/rem_euclid.cpp\"\n\ntemplate\
    \ <class T> constexpr T rem_euclid(T value, const T& mod) { return (value %= mod)\
    \ >= 0 ? value : value + mod; }\n#line 4 \"math/mod_pow.cpp\"\n\ntemplate <class\
    \ T> constexpr T mod_pow(T x, u64 exp, const T& mod) {\n    assert(mod > 0);\n\
    \    T ret = T(1) % mod;\n    x = rem_euclid(x, mod);\n    for (; exp > 0; exp\
    \ >>= 1) {\n        if (exp & 1) ret = ret * x % mod;\n        x = x * x % mod;\n\
    \    }\n    return ret;\n}\n#line 2 \"utility/int_alias.cpp\"\n#include <cstddef>\n\
    #include <cstdint>\n\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\n\
    using i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing isize = std::ptrdiff_t;\n\
    using usize = std::size_t;\n#line 5 \"math/primitive_root.cpp\"\n\nconstexpr u32\
    \ primitive_root(const u32 mod) {\n    std::array<u32, 32> exp{};\n    u32 cur\
    \ = mod - 1;\n    usize size = 0;\n    for (u32 i = 2; i * i <= cur; ++i) {\n\
    \        if (cur % i == 0) {\n            exp[size++] = (mod - 1) / i;\n     \
    \       while (cur % i == 0) cur /= i;\n        }\n    }\n    if (cur != 1) exp[size++]\
    \ = (mod - 1) / cur;\n    for (u32 check = 1; check < mod; ++check) {\n      \
    \  for (const auto e : exp) {\n            if (e == 0) return check;\n       \
    \     if (mod_pow<u64>(check, e, mod) == 1) break;\n        }\n    }\n    return\
    \ mod;\n}\n"
  code: "#pragma once\n#include <array>\n#include \"../math/mod_pow.cpp\"\n#include\
    \ \"../utility/int_alias.cpp\"\n\nconstexpr u32 primitive_root(const u32 mod)\
    \ {\n    std::array<u32, 32> exp{};\n    u32 cur = mod - 1;\n    usize size =\
    \ 0;\n    for (u32 i = 2; i * i <= cur; ++i) {\n        if (cur % i == 0) {\n\
    \            exp[size++] = (mod - 1) / i;\n            while (cur % i == 0) cur\
    \ /= i;\n        }\n    }\n    if (cur != 1) exp[size++] = (mod - 1) / cur;\n\
    \    for (u32 check = 1; check < mod; ++check) {\n        for (const auto e :\
    \ exp) {\n            if (e == 0) return check;\n            if (mod_pow<u64>(check,\
    \ e, mod) == 1) break;\n        }\n    }\n    return mod;\n}\n"
  dependsOn:
  - math/mod_pow.cpp
  - math/rem_euclid.cpp
  - utility/int_alias.cpp
  isVerificationFile: false
  path: math/primitive_root.cpp
  requiredBy: []
  timestamp: '2021-09-08 18:46:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/primitive_root.cpp
layout: document
redirect_from:
- /library/math/primitive_root.cpp
- /library/math/primitive_root.cpp.html
title: math/primitive_root.cpp
---
