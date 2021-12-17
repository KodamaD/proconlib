---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: random/xorshift.cpp
    title: random/xorshift.cpp
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: random/rand_bool.cpp
    title: random/rand_bool.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"random/rand_real.cpp\"\n#include <random>\n#line 2 \"random/xorshift.cpp\"\
    \n#include <chrono>\n#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n\n\
    using i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    #line 5 \"random/xorshift.cpp\"\n\nu64 xorshift() {\n    static u64 state = std::chrono::system_clock::now().time_since_epoch().count();\n\
    \    state ^= state << 7;\n    state ^= state >> 9;\n    return state;\n}\n#line\
    \ 4 \"random/rand_real.cpp\"\n\ntemplate <class T> T rand_real(const T& min, const\
    \ T& max) {\n    static std::default_random_engine gen(xorshift());\n    return\
    \ std::uniform_real_distribution<T>(min, max)(gen);\n}\n"
  code: "#pragma once\n#include <random>\n#include \"xorshift.cpp\"\n\ntemplate <class\
    \ T> T rand_real(const T& min, const T& max) {\n    static std::default_random_engine\
    \ gen(xorshift());\n    return std::uniform_real_distribution<T>(min, max)(gen);\n\
    }"
  dependsOn:
  - random/xorshift.cpp
  - utility/int_alias.cpp
  isVerificationFile: false
  path: random/rand_real.cpp
  requiredBy:
  - random/rand_bool.cpp
  timestamp: '2021-12-17 09:20:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: random/rand_real.cpp
layout: document
redirect_from:
- /library/random/rand_real.cpp
- /library/random/rand_real.cpp.html
title: random/rand_real.cpp
---
