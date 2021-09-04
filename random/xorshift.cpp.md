---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: container/polynomial_hash.cpp
    title: container/polynomial_hash.cpp
  - icon: ':x:'
    path: random/rand_int.cpp
    title: random/rand_int.cpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/polynomial_hash.test.cpp
    title: test/polynomial_hash.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"random/xorshift.cpp\"\n#include <chrono>\n#include <random>\n\
    #line 2 \"utility/int_alias.cpp\"\n#include <cstddef>\n#include <cstdint>\n\n\
    using i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    using isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 5 \"random/xorshift.cpp\"\
    \n\nu64 xorshift() {\n    static u64 state = std::chrono::system_clock::now().time_since_epoch().count();\n\
    \    state ^= state << 7;\n    state ^= state >> 9;\n    return state;\n}\n"
  code: "#pragma once\n#include <chrono>\n#include <random>\n#include \"../utility/int_alias.cpp\"\
    \n\nu64 xorshift() {\n    static u64 state = std::chrono::system_clock::now().time_since_epoch().count();\n\
    \    state ^= state << 7;\n    state ^= state >> 9;\n    return state;\n}\n"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: random/xorshift.cpp
  requiredBy:
  - random/rand_int.cpp
  - container/polynomial_hash.cpp
  timestamp: '2021-09-04 17:30:23+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/polynomial_hash.test.cpp
documentation_of: random/xorshift.cpp
layout: document
redirect_from:
- /library/random/xorshift.cpp
- /library/random/xorshift.cpp.html
title: random/xorshift.cpp
---
