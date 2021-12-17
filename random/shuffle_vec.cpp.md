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
    path: random/rand_perm.cpp
    title: random/rand_perm.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"random/shuffle_vec.cpp\"\n#include <algorithm>\n#include\
    \ <random>\n#include <vector>\n#line 2 \"random/xorshift.cpp\"\n#include <chrono>\n\
    #line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n\nusing i32 = std::int32_t;\n\
    using u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n#line 5 \"random/xorshift.cpp\"\
    \n\nu64 xorshift() {\n    static u64 state = std::chrono::system_clock::now().time_since_epoch().count();\n\
    \    state ^= state << 7;\n    state ^= state >> 9;\n    return state;\n}\n#line\
    \ 6 \"random/shuffle_vec.cpp\"\n\ntemplate <class C> void shuffle_vec(C& v) {\n\
    \    static std::default_random_engine gen(xorshift());\n    std::shuffle(v.begin(),\
    \ v.end(), gen);\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <random>\n#include <vector>\n\
    #include \"xorshift.cpp\"\n\ntemplate <class C> void shuffle_vec(C& v) {\n   \
    \ static std::default_random_engine gen(xorshift());\n    std::shuffle(v.begin(),\
    \ v.end(), gen);\n}"
  dependsOn:
  - random/xorshift.cpp
  - utility/int_alias.cpp
  isVerificationFile: false
  path: random/shuffle_vec.cpp
  requiredBy:
  - random/rand_perm.cpp
  timestamp: '2021-12-17 09:20:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: random/shuffle_vec.cpp
layout: document
redirect_from:
- /library/random/shuffle_vec.cpp
- /library/random/shuffle_vec.cpp.html
title: random/shuffle_vec.cpp
---
