---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: container/polynomial_hash.cpp
    title: container/polynomial_hash.cpp
  - icon: ':heavy_check_mark:'
    path: random/rand_int.cpp
    title: random/rand_int.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/polynomial_hash.test.cpp
    title: test/polynomial_hash.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"random/xorshift.cpp\"\n#include <chrono>\n#include <random>\n\
    #line 2 \"utility/int_alias.cpp\"\n#include <cstddef>\n#include <cstdint>\n\n\
    using i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing isize = std::ptrdiff_t;\nusing usize = std::size_t;\n\
    #line 5 \"random/xorshift.cpp\"\n\nu64 xorshift() {\n    static u64 state = std::chrono::system_clock::now().time_since_epoch().count();\n\
    \    state ^= state << 7;\n    state ^= state >> 9;\n    return state;\n}\n"
  code: "#pragma once\n#include <chrono>\n#include <random>\n#include \"../utility/int_alias.cpp\"\
    \n\nu64 xorshift() {\n    static u64 state = std::chrono::system_clock::now().time_since_epoch().count();\n\
    \    state ^= state << 7;\n    state ^= state >> 9;\n    return state;\n}\n"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: random/xorshift.cpp
  requiredBy:
  - container/polynomial_hash.cpp
  - random/rand_int.cpp
  timestamp: '2021-09-08 18:46:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/polynomial_hash.test.cpp
documentation_of: random/xorshift.cpp
layout: document
redirect_from:
- /library/random/xorshift.cpp
- /library/random/xorshift.cpp.html
title: random/xorshift.cpp
---
