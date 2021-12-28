---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/bit_width.cpp
    title: utility/bit_width.cpp
  - icon: ':heavy_check_mark:'
    path: utility/countl_zero.cpp
    title: utility/countl_zero.cpp
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':question:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/sparse_table.test.cpp
    title: test/sparse_table.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"container/sparse_table.cpp\"\n#include <cassert>\n#include\
    \ <vector>\n#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n\nusing i32\
    \ = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing\
    \ u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    #line 3 \"utility/countl_zero.cpp\"\n\nconstexpr int countl_zero(const u64 x)\
    \ { return x == 0 ? 64 : __builtin_clzll(x); }\n#line 3 \"utility/bit_width.cpp\"\
    \n\nconstexpr int bit_width(const u64 x) { return 64 - countl_zero(x); }\n#line\
    \ 2 \"utility/rep.cpp\"\n#include <algorithm>\n\nclass Range {\n    struct Iter\
    \ {\n        int itr;\n        constexpr Iter(const int pos) noexcept : itr(pos)\
    \ {}\n        constexpr void operator++() noexcept { ++itr; }\n        constexpr\
    \ bool operator!=(const Iter& other) const noexcept { return itr != other.itr;\
    \ }\n        constexpr int operator*() const noexcept { return itr; }\n    };\n\
    \    const Iter first, last;\n\n  public:\n    explicit constexpr Range(const\
    \ int first, const int last) noexcept : first(first), last(std::max(first, last))\
    \ {}\n    constexpr Iter begin() const noexcept { return first; }\n    constexpr\
    \ Iter end() const noexcept { return last; }\n};\n\nconstexpr Range rep(const\
    \ int l, const int r) noexcept { return Range(l, r); }\nconstexpr Range rep(const\
    \ int n) noexcept { return Range(0, n); }\n#line 6 \"container/sparse_table.cpp\"\
    \n\ntemplate <class M> class SparseTable {\n    using T = typename M::Type;\n\
    \    std::vector<std::vector<T>> table;\n\n  public:\n    SparseTable() : SparseTable(std::vector<T>())\
    \ {}\n    explicit SparseTable(const std::vector<T>& vec) {\n        const int\
    \ size = vec.size();\n        const int height = bit_width(size);\n        table.reserve(height);\n\
    \        table.push_back(vec);\n        for (const int d : rep(1, height)) {\n\
    \            table.push_back(std::vector<T>(size - (1 << d) + 1, M::identity()));\n\
    \            for (const int i : rep(table[d].size())) {\n                table[d][i]\
    \ = M::operation(table[d - 1][i], table[d - 1][i + (1 << (d - 1))]);\n       \
    \     }\n        }\n    }\n\n    int size() const { return table[0].size(); }\n\
    \n    T fold(const int l, const int r) const {\n        assert(0 <= l and l <=\
    \ r and r <= size());\n        if (l == r) return M::identity();\n        const\
    \ auto d = bit_width(r - l) - 1;\n        return M::operation(table[d][l], table[d][r\
    \ - (1 << d)]);\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n#include \"../utility/bit_width.cpp\"\
    \n#include \"../utility/rep.cpp\"\n\ntemplate <class M> class SparseTable {\n\
    \    using T = typename M::Type;\n    std::vector<std::vector<T>> table;\n\n \
    \ public:\n    SparseTable() : SparseTable(std::vector<T>()) {}\n    explicit\
    \ SparseTable(const std::vector<T>& vec) {\n        const int size = vec.size();\n\
    \        const int height = bit_width(size);\n        table.reserve(height);\n\
    \        table.push_back(vec);\n        for (const int d : rep(1, height)) {\n\
    \            table.push_back(std::vector<T>(size - (1 << d) + 1, M::identity()));\n\
    \            for (const int i : rep(table[d].size())) {\n                table[d][i]\
    \ = M::operation(table[d - 1][i], table[d - 1][i + (1 << (d - 1))]);\n       \
    \     }\n        }\n    }\n\n    int size() const { return table[0].size(); }\n\
    \n    T fold(const int l, const int r) const {\n        assert(0 <= l and l <=\
    \ r and r <= size());\n        if (l == r) return M::identity();\n        const\
    \ auto d = bit_width(r - l) - 1;\n        return M::operation(table[d][l], table[d][r\
    \ - (1 << d)]);\n    }\n};\n"
  dependsOn:
  - utility/bit_width.cpp
  - utility/countl_zero.cpp
  - utility/int_alias.cpp
  - utility/rep.cpp
  isVerificationFile: false
  path: container/sparse_table.cpp
  requiredBy: []
  timestamp: '2021-12-28 21:38:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/sparse_table.test.cpp
documentation_of: container/sparse_table.cpp
layout: document
redirect_from:
- /library/container/sparse_table.cpp
- /library/container/sparse_table.cpp.html
title: container/sparse_table.cpp
---
