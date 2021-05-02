---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: random/xorshift.cpp
    title: random/xorshift.cpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: container/polynomial_hash.cpp
    title: container/polynomial_hash.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/polynomial_hash.test.cpp
    title: test/polynomial_hash.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n#include <cstddef>\n\
    \nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    using isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 3 \"random/xorshift.cpp\"\
    \n#include <random>\n#include <chrono>\n\nu64 xorshift() {\n    static u64 state\
    \ = std::chrono::system_clock::now().time_since_epoch().count();\n    state ^=\
    \ state << 7;\n    state ^= state >> 9;\n    return state;\n}\n#line 4 \"random/rand_int.cpp\"\
    \n\ntemplate <class T>\nT rand_int(const T& min, const T& max) {\n    static std::default_random_engine\
    \ gen(xorshift());\n    return std::uniform_int_distribution<T>(min, max)(gen);\n\
    }\n"
  code: "#pragma once\n#include \"../random/xorshift.cpp\"\n#include <random>\n\n\
    template <class T>\nT rand_int(const T& min, const T& max) {\n    static std::default_random_engine\
    \ gen(xorshift());\n    return std::uniform_int_distribution<T>(min, max)(gen);\n\
    }"
  dependsOn:
  - random/xorshift.cpp
  - utility/int_alias.cpp
  isVerificationFile: false
  path: random/rand_int.cpp
  requiredBy:
  - container/polynomial_hash.cpp
  timestamp: '2021-04-13 21:27:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/polynomial_hash.test.cpp
documentation_of: random/rand_int.cpp
layout: document
redirect_from:
- /library/random/rand_int.cpp
- /library/random/rand_int.cpp.html
title: random/rand_int.cpp
---
