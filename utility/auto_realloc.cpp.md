---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/ceil_log2.cpp
    title: utility/ceil_log2.cpp
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/prime_sieve.cpp
    title: math/prime_sieve.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/prime_sieve.test.cpp
    title: test/prime_sieve.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/auto_realloc.cpp\"\n#include <utility>\n#include\
    \ <vector>\n#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n\nusing i32\
    \ = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing\
    \ u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    #line 3 \"utility/ceil_log2.cpp\"\n\nconstexpr int ceil_log2(const u64 x) {\n\
    \    int e = 0;\n    while (((u64)1 << e) < x) ++e;\n    return e;\n}\n#line 6\
    \ \"utility/auto_realloc.cpp\"\n\ntemplate <class F> class AutoReallocation {\n\
    \    using R = typename decltype(std::declval<F>()(0))::value_type;\n\n    F func;\n\
    \    mutable std::vector<R> data;\n\n  public:\n    explicit AutoReallocation(F&&\
    \ f) : func(std::forward<F>(f)), data() {}\n\n    void reserve(const int size)\
    \ const {\n        if ((int)data.size() < size) data = func(((int)1 << ceil_log2(size)));\n\
    \    }\n    R operator[](const int i) const {\n        assert(i >= 0);\n     \
    \   reserve(i + 1);\n        return data[i];\n    }\n};\n\ntemplate <class F>\
    \ decltype(auto) auto_realloc(F&& f) { return AutoReallocation<F>(std::forward<F>(f));\
    \ }\n"
  code: "#pragma once\n#include <utility>\n#include <vector>\n#include \"ceil_log2.cpp\"\
    \n#include \"int_alias.cpp\"\n\ntemplate <class F> class AutoReallocation {\n\
    \    using R = typename decltype(std::declval<F>()(0))::value_type;\n\n    F func;\n\
    \    mutable std::vector<R> data;\n\n  public:\n    explicit AutoReallocation(F&&\
    \ f) : func(std::forward<F>(f)), data() {}\n\n    void reserve(const int size)\
    \ const {\n        if ((int)data.size() < size) data = func(((int)1 << ceil_log2(size)));\n\
    \    }\n    R operator[](const int i) const {\n        assert(i >= 0);\n     \
    \   reserve(i + 1);\n        return data[i];\n    }\n};\n\ntemplate <class F>\
    \ decltype(auto) auto_realloc(F&& f) { return AutoReallocation<F>(std::forward<F>(f));\
    \ }\n"
  dependsOn:
  - utility/ceil_log2.cpp
  - utility/int_alias.cpp
  isVerificationFile: false
  path: utility/auto_realloc.cpp
  requiredBy:
  - math/prime_sieve.cpp
  timestamp: '2021-12-28 21:38:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/prime_sieve.test.cpp
documentation_of: utility/auto_realloc.cpp
layout: document
redirect_from:
- /library/utility/auto_realloc.cpp
- /library/utility/auto_realloc.cpp.html
title: utility/auto_realloc.cpp
---
