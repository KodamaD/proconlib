---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: internal/enable_avx2.cpp
    title: internal/enable_avx2.cpp
  - icon: ':heavy_check_mark:'
    path: utility/bit_width.cpp
    title: utility/bit_width.cpp
  - icon: ':heavy_check_mark:'
    path: utility/countl_zero.cpp
    title: utility/countl_zero.cpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':heavy_check_mark:'
    path: utility/popcount.cpp
    title: utility/popcount.cpp
  - icon: ':heavy_check_mark:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algorithm/subset_convolution.cpp
    title: algorithm/subset_convolution.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/subset_convolution.test.cpp
    title: test/subset_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algorithm/ranked_subset_mobius_transform.cpp\"\n#include\
    \ <cassert>\n#include <vector>\n#line 2 \"internal/enable_avx2.cpp\"\n\n#ifdef\
    \ ENABLE_AVX2\n#define TARGET_AVX2 __attribute__((target(\"avx2\")))\n#else\n\
    #define TARGET_AVX2\n#endif\n#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n\
    \nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    #line 4 \"utility/countl_zero.cpp\"\n\nTARGET_AVX2 constexpr int countl_zero(u64\
    \ x) {\n#ifdef __GNUC__\n    return x == 0 ? 64 : __builtin_clzll(x);\n#else\n\
    \    x |= x >> 1;\n    x |= x >> 2;\n    x |= x >> 4;\n    x |= x >> 8;\n    x\
    \ |= x >> 16;\n    x |= x >> 32;\n    return 64 - countr_zero(~x);\n#endif\n}\n\
    #line 4 \"utility/bit_width.cpp\"\n\nTARGET_AVX2 constexpr int bit_width(const\
    \ u64 x) { return 64 - countl_zero(x); }\n#line 4 \"utility/popcount.cpp\"\n\n\
    TARGET_AVX2 constexpr int popcount(u64 x) {\n#ifdef __GNUC__\n    return __builtin_popcountll(x);\n\
    #else\n    x -= x >> 1 & 0x5555555555555555;\n    x = (x & 0x3333333333333333)\
    \ + (x >> 2 & 0x3333333333333333);\n    x = (x + (x >> 4)) & 0x0F0F0F0F0F0F0F0F;\n\
    \    return x * 0x0101010101010101 >> 56 & 0x7f;\n#endif\n}\n#line 2 \"utility/rep.cpp\"\
    \n#include <algorithm>\n\nclass Range {\n    struct Iter {\n        int itr;\n\
    \        constexpr Iter(const int pos) noexcept : itr(pos) {}\n        constexpr\
    \ void operator++() noexcept { ++itr; }\n        constexpr bool operator!=(const\
    \ Iter& other) const noexcept { return itr != other.itr; }\n        constexpr\
    \ int operator*() const noexcept { return itr; }\n    };\n    const Iter first,\
    \ last;\n\n  public:\n    explicit constexpr Range(const int first, const int\
    \ last) noexcept : first(first), last(std::max(first, last)) {}\n    constexpr\
    \ Iter begin() const noexcept { return first; }\n    constexpr Iter end() const\
    \ noexcept { return last; }\n};\n\nconstexpr Range rep(const int l, const int\
    \ r) noexcept { return Range(l, r); }\nconstexpr Range rep(const int n) noexcept\
    \ { return Range(0, n); }\n#line 7 \"algorithm/ranked_subset_mobius_transform.cpp\"\
    \n\ntemplate <class G>\nstd::vector<typename G::Type> ranked_subset_mobius_transform(std::vector<std::vector<typename\
    \ G::Type>> f) {\n    const int n = f.size();\n    assert((n & (n - 1)) == 0);\n\
    \    const int logn = bit_width(n);\n    for (int i = n; i >>= 1;) {\n       \
    \ for (const int j : rep(n)) {\n            if (j & i) {\n                auto&\
    \ a = f[j];\n                const auto& b = f[j & ~i];\n                for (const\
    \ int k : rep(logn)) a[k] = G::operation(G::inverse(b[k]), a[k]);\n          \
    \  }\n        }\n    }\n    std::vector<typename G::Type> g(n, G::identity());\n\
    \    for (const int i : rep(n)) g[i] = f[i][popcount(i)];\n    return g;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n#include \"../utility/bit_width.cpp\"\
    \n#include \"../utility/popcount.cpp\"\n#include \"../utility/rep.cpp\"\n\ntemplate\
    \ <class G>\nstd::vector<typename G::Type> ranked_subset_mobius_transform(std::vector<std::vector<typename\
    \ G::Type>> f) {\n    const int n = f.size();\n    assert((n & (n - 1)) == 0);\n\
    \    const int logn = bit_width(n);\n    for (int i = n; i >>= 1;) {\n       \
    \ for (const int j : rep(n)) {\n            if (j & i) {\n                auto&\
    \ a = f[j];\n                const auto& b = f[j & ~i];\n                for (const\
    \ int k : rep(logn)) a[k] = G::operation(G::inverse(b[k]), a[k]);\n          \
    \  }\n        }\n    }\n    std::vector<typename G::Type> g(n, G::identity());\n\
    \    for (const int i : rep(n)) g[i] = f[i][popcount(i)];\n    return g;\n}\n"
  dependsOn:
  - utility/bit_width.cpp
  - internal/enable_avx2.cpp
  - utility/countl_zero.cpp
  - utility/int_alias.cpp
  - utility/popcount.cpp
  - utility/rep.cpp
  isVerificationFile: false
  path: algorithm/ranked_subset_mobius_transform.cpp
  requiredBy:
  - algorithm/subset_convolution.cpp
  timestamp: '2022-01-28 13:07:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/subset_convolution.test.cpp
documentation_of: algorithm/ranked_subset_mobius_transform.cpp
layout: document
redirect_from:
- /library/algorithm/ranked_subset_mobius_transform.cpp
- /library/algorithm/ranked_subset_mobius_transform.cpp.html
title: algorithm/ranked_subset_mobius_transform.cpp
---
