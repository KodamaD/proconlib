---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bit/bit_lzeros.cpp
    title: bit/bit_lzeros.cpp
  - icon: ':heavy_check_mark:'
    path: bit/bit_width.cpp
    title: bit/bit_width.cpp
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
    \ <vector>\n#line 2 \"utility/int_alias.cpp\"\n#include <cstddef>\n#include <cstdint>\n\
    \nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing isize = std::ptrdiff_t;\nusing usize = std::size_t;\n\
    #line 3 \"bit/bit_lzeros.cpp\"\n\n__attribute__((target(\"avx2\"))) constexpr\
    \ u64 bit_lzeros(const u64 x) { return x == 0 ? 64 : __builtin_clzll(x); }\n#line\
    \ 4 \"bit/bit_width.cpp\"\n\n__attribute__((target(\"avx2\"))) constexpr u64 bit_width(const\
    \ u64 x) { return 64 - bit_lzeros(x); }\n#line 2 \"utility/rep.cpp\"\n#include\
    \ <algorithm>\n#line 4 \"utility/rep.cpp\"\n\nclass rep {\n    struct Iter {\n\
    \        usize itr;\n        constexpr Iter(const usize pos) noexcept : itr(pos)\
    \ {}\n        constexpr void operator++() noexcept { ++itr; }\n        constexpr\
    \ bool operator!=(const Iter& other) const noexcept { return itr != other.itr;\
    \ }\n        constexpr usize operator*() const noexcept { return itr; }\n    };\n\
    \    const Iter first, last;\n\n  public:\n    explicit constexpr rep(const usize\
    \ first, const usize last) noexcept : first(first), last(std::max(first, last))\
    \ {}\n    constexpr Iter begin() const noexcept { return first; }\n    constexpr\
    \ Iter end() const noexcept { return last; }\n};\n#line 7 \"container/sparse_table.cpp\"\
    \n\ntemplate <class M> class SparseTable {\n    using T = typename M::Type;\n\
    \    std::vector<std::vector<T>> table;\n\n  public:\n    SparseTable() : SparseTable(std::vector<T>())\
    \ {}\n    explicit SparseTable(const std::vector<T>& vec) {\n        const usize\
    \ size = vec.size();\n        const usize height = bit_width(size);\n        table.reserve(height);\n\
    \        table.push_back(vec);\n        for (const usize d : rep(1, height)) {\n\
    \            table.push_back(std::vector<T>(size - (1 << d) + 1, M::identity()));\n\
    \            for (const usize i : rep(0, table[d].size())) {\n               \
    \ table[d][i] = M::operation(table[d - 1][i], table[d - 1][i + (1 << (d - 1))]);\n\
    \            }\n        }\n    }\n\n    usize size() const { return table[0].size();\
    \ }\n\n    T fold(const usize l, const usize r) const {\n        if (l == r) return\
    \ M::identity();\n        assert(l < r);\n        const auto d = bit_width(r -\
    \ l) - 1;\n        return M::operation(table[d][l], table[d][r - (1 << d)]);\n\
    \    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n#include \"../bit/bit_width.cpp\"\
    \n#include \"../utility/int_alias.cpp\"\n#include \"../utility/rep.cpp\"\n\ntemplate\
    \ <class M> class SparseTable {\n    using T = typename M::Type;\n    std::vector<std::vector<T>>\
    \ table;\n\n  public:\n    SparseTable() : SparseTable(std::vector<T>()) {}\n\
    \    explicit SparseTable(const std::vector<T>& vec) {\n        const usize size\
    \ = vec.size();\n        const usize height = bit_width(size);\n        table.reserve(height);\n\
    \        table.push_back(vec);\n        for (const usize d : rep(1, height)) {\n\
    \            table.push_back(std::vector<T>(size - (1 << d) + 1, M::identity()));\n\
    \            for (const usize i : rep(0, table[d].size())) {\n               \
    \ table[d][i] = M::operation(table[d - 1][i], table[d - 1][i + (1 << (d - 1))]);\n\
    \            }\n        }\n    }\n\n    usize size() const { return table[0].size();\
    \ }\n\n    T fold(const usize l, const usize r) const {\n        if (l == r) return\
    \ M::identity();\n        assert(l < r);\n        const auto d = bit_width(r -\
    \ l) - 1;\n        return M::operation(table[d][l], table[d][r - (1 << d)]);\n\
    \    }\n};\n"
  dependsOn:
  - bit/bit_width.cpp
  - utility/int_alias.cpp
  - bit/bit_lzeros.cpp
  - utility/rep.cpp
  isVerificationFile: false
  path: container/sparse_table.cpp
  requiredBy: []
  timestamp: '2021-11-04 19:10:29+09:00'
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
