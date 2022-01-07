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
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/fenwick_tree.test.cpp
    title: test/fenwick_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"container/fenwick_tree.cpp\"\n#include <cassert>\n#include\
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
    #line 5 \"container/fenwick_tree.cpp\"\n\ntemplate <class G> class FenwickTree\
    \ {\n    using T = typename G::Type;\n\n    int logn;\n    std::vector<T> data;\n\
    \n  public:\n    explicit FenwickTree(const int size = 0) {\n        logn = ceil_log2(size\
    \ + 1) - 1;\n        data = std::vector<T>(size + 1, G::identity());\n    }\n\n\
    \    int size() const { return data.size() - 1; }\n\n    void add(int i, const\
    \ T& x) {\n        assert(0 <= i and i < size());\n        i += 1;\n        while\
    \ (i <= size()) {\n            data[i] = G::operation(data[i], x);\n         \
    \   i += i & -i;\n        }\n    }\n\n    T fold() const { return fold(0, size());\
    \ }\n    T fold(int l, int r) const {\n        assert(0 <= l and l <= r and r\
    \ <= size());\n        T ret = G::identity();\n        while (l < r) {\n     \
    \       ret = G::operation(ret, data[r]);\n            r -= r & -r;\n        }\n\
    \        while (r < l) {\n            ret = G::operation(ret, G::inverse(data[l]));\n\
    \            l -= l & -l;\n        }\n        return ret;\n    }\n\n    template\
    \ <class F> int max_right(const F& f) const {\n        assert(f(G::identity()));\n\
    \        int i = 0;\n        T sum = G::identity();\n        for (int k = (1 <<\
    \ logn); k > 0; k >>= 1) {\n            if (i + k <= size() && f(G::operation(sum,\
    \ data[i + k]))) {\n                sum = G::operation(sum, data[i += k]);\n \
    \           }\n        }\n        return i;\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n#include \"../utility/ceil_log2.cpp\"\
    \n\ntemplate <class G> class FenwickTree {\n    using T = typename G::Type;\n\n\
    \    int logn;\n    std::vector<T> data;\n\n  public:\n    explicit FenwickTree(const\
    \ int size = 0) {\n        logn = ceil_log2(size + 1) - 1;\n        data = std::vector<T>(size\
    \ + 1, G::identity());\n    }\n\n    int size() const { return data.size() - 1;\
    \ }\n\n    void add(int i, const T& x) {\n        assert(0 <= i and i < size());\n\
    \        i += 1;\n        while (i <= size()) {\n            data[i] = G::operation(data[i],\
    \ x);\n            i += i & -i;\n        }\n    }\n\n    T fold() const { return\
    \ fold(0, size()); }\n    T fold(int l, int r) const {\n        assert(0 <= l\
    \ and l <= r and r <= size());\n        T ret = G::identity();\n        while\
    \ (l < r) {\n            ret = G::operation(ret, data[r]);\n            r -= r\
    \ & -r;\n        }\n        while (r < l) {\n            ret = G::operation(ret,\
    \ G::inverse(data[l]));\n            l -= l & -l;\n        }\n        return ret;\n\
    \    }\n\n    template <class F> int max_right(const F& f) const {\n        assert(f(G::identity()));\n\
    \        int i = 0;\n        T sum = G::identity();\n        for (int k = (1 <<\
    \ logn); k > 0; k >>= 1) {\n            if (i + k <= size() && f(G::operation(sum,\
    \ data[i + k]))) {\n                sum = G::operation(sum, data[i += k]);\n \
    \           }\n        }\n        return i;\n    }\n};\n"
  dependsOn:
  - utility/ceil_log2.cpp
  - internal/enable_avx2.cpp
  - utility/bit_width.cpp
  - utility/countl_zero.cpp
  - utility/int_alias.cpp
  isVerificationFile: false
  path: container/fenwick_tree.cpp
  requiredBy: []
  timestamp: '2022-01-07 21:48:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/fenwick_tree.test.cpp
documentation_of: container/fenwick_tree.cpp
layout: document
redirect_from:
- /library/container/fenwick_tree.cpp
- /library/container/fenwick_tree.cpp.html
title: container/fenwick_tree.cpp
---
