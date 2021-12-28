---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: random/shuffle_vec.cpp
    title: random/shuffle_vec.cpp
  - icon: ':question:'
    path: random/xorshift.cpp
    title: random/xorshift.cpp
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
  bundledCode: "#line 2 \"random/rand_perm.cpp\"\n#include <numeric>\n#include <vector>\n\
    #line 2 \"random/shuffle_vec.cpp\"\n#include <algorithm>\n#include <random>\n\
    #line 2 \"random/xorshift.cpp\"\n#include <chrono>\n#line 2 \"utility/int_alias.cpp\"\
    \n#include <cstdint>\n\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\n\
    using i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\n#line 5 \"random/xorshift.cpp\"\n\nu64 xorshift() {\n\
    \    static u64 state = std::chrono::system_clock::now().time_since_epoch().count();\n\
    \    state ^= state << 7;\n    state ^= state >> 9;\n    return state;\n}\n#line\
    \ 6 \"random/shuffle_vec.cpp\"\n\ntemplate <class C> void shuffle_vec(C& v) {\n\
    \    static std::default_random_engine gen(xorshift());\n    std::shuffle(v.begin(),\
    \ v.end(), gen);\n}\n#line 5 \"random/rand_perm.cpp\"\n\ntemplate <class T> std::vector<T>\
    \ rand_perm(const int n, const T& first = 0) {\n    std::vector<T> p(n);\n   \
    \ std::iota(p.begin(), p.end(), first);\n    shuffle_vec(p);\n    return p;\n\
    }\n"
  code: "#pragma once\n#include <numeric>\n#include <vector>\n#include \"shuffle_vec.cpp\"\
    \n\ntemplate <class T> std::vector<T> rand_perm(const int n, const T& first =\
    \ 0) {\n    std::vector<T> p(n);\n    std::iota(p.begin(), p.end(), first);\n\
    \    shuffle_vec(p);\n    return p;\n}"
  dependsOn:
  - random/shuffle_vec.cpp
  - random/xorshift.cpp
  - utility/int_alias.cpp
  isVerificationFile: false
  path: random/rand_perm.cpp
  requiredBy: []
  timestamp: '2021-12-17 09:20:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: random/rand_perm.cpp
layout: document
redirect_from:
- /library/random/rand_perm.cpp
- /library/random/rand_perm.cpp.html
title: random/rand_perm.cpp
---
