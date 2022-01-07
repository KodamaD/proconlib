---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: internal/enable_avx2.cpp
    title: internal/enable_avx2.cpp
  - icon: ':question:'
    path: utility/bit_width.cpp
    title: utility/bit_width.cpp
  - icon: ':question:'
    path: utility/ceil_log2.cpp
    title: utility/ceil_log2.cpp
  - icon: ':question:'
    path: utility/countl_zero.cpp
    title: utility/countl_zero.cpp
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
    \ <vector>\n#line 2 \"internal/enable_avx2.cpp\"\n\n#ifdef ENABLE_AVX2\n#define\
    \ TARGET_AVX2 __attribute__((target(\"avx2\")))\n#else\n#define TARGET_AVX2\n\
    #endif\n#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n\nusing i32 = std::int32_t;\n\
    using u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n#line 4 \"utility/countl_zero.cpp\"\
    \n\nTARGET_AVX2 constexpr int countl_zero(u64 x) {\n#ifdef __GNUC__\n    return\
    \ x == 0 ? 64 : __builtin_clzll(x);\n#else\n    x |= x >> 1;\n    x |= x >> 2;\n\
    \    x |= x >> 4;\n    x |= x >> 8;\n    x |= x >> 16;\n    x |= x >> 32;\n  \
    \  return 64 - countr_zero(~x);\n#endif\n}\n#line 4 \"utility/bit_width.cpp\"\n\
    \nTARGET_AVX2 constexpr int bit_width(const u64 x) { return 64 - countl_zero(x);\
    \ }\n#line 5 \"utility/ceil_log2.cpp\"\n\nTARGET_AVX2 constexpr int ceil_log2(const\
    \ u64 x) {\n#ifdef __GNUC__\n    return x == 0 ? 0 : bit_width(x - 1);\n#else\n\
    \    int e = 0;\n    while (((u64)1 << e) < x) ++e;\n    return e;\n#endif\n}\n\
    #line 6 \"utility/auto_realloc.cpp\"\n\ntemplate <class F> class AutoReallocation\
    \ {\n    using R = typename decltype(std::declval<F>()(0))::value_type;\n\n  \
    \  F func;\n    mutable std::vector<R> data;\n\n  public:\n    explicit AutoReallocation(F&&\
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
  - internal/enable_avx2.cpp
  - utility/bit_width.cpp
  - utility/countl_zero.cpp
  - utility/int_alias.cpp
  isVerificationFile: false
  path: utility/auto_realloc.cpp
  requiredBy:
  - math/prime_sieve.cpp
  timestamp: '2022-01-07 21:48:21+09:00'
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
