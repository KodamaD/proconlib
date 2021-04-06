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
  bundledCode: "#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n#include <cstddef>\n\
    \nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    using isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 3 \"utility/rep.cpp\"\
    \n#include <algorithm>\n\nclass rep {\n    struct Iter {\n        usize itr;\n\
    \        constexpr Iter(const usize pos) noexcept: itr(pos) { }\n        constexpr\
    \ void operator ++ () noexcept { ++itr; }\n        constexpr bool operator !=\
    \ (const Iter& other) const noexcept { return itr != other.itr; }\n        constexpr\
    \ usize operator * () const noexcept { return itr; }\n    };\n    const Iter first,\
    \ last;\npublic:\n    explicit constexpr rep(const usize first, const usize last)\
    \ noexcept: first(first), last(std::max(first, last)) { }\n    constexpr Iter\
    \ begin() const noexcept { return first; }\n    constexpr Iter end() const noexcept\
    \ { return last; }\n};\n#line 3 \"bit/bit_lzeros.cpp\"\n\nconstexpr u64 bit_lzeros(const\
    \ u64 x) {\n    return x == 0 ? 64 : __builtin_clzll(x);\n}\n#line 4 \"bit/bit_width.cpp\"\
    \n\nconstexpr u64 bit_width(const u64 x) {\n    return 64 - bit_lzeros(x);\n}\n\
    #line 5 \"container/sparse_table.cpp\"\n#include <vector>\n#include <cassert>\n\
    \ntemplate <class IdempotentMonoid>\nclass SparseTable {\n    using M = IdempotentMonoid;\n\
    \    std::vector<std::vector<M>> table;\n\npublic:\n    SparseTable(): SparseTable(std::vector<M>())\
    \ { }\n    explicit SparseTable(const std::vector<M>& vec) {\n        const auto\
    \ size = vec.size();\n        const auto height = bit_width(size); // 4: 3, 7:\
    \ 3, 8: 4\n        table.reserve(height);\n        table.push_back(vec);\n   \
    \     for (const usize d: rep(1, height)) {\n            table.push_back(std::vector<M>(size\
    \ - (1 << d) + 1, M::zero()));\n            for (const usize i: rep(0, table[d].size()))\
    \ {\n                table[d][i] = table[d - 1][i] + table[d - 1][i + (1 << (d\
    \ - 1))];\n            }\n        }\n    }\n\n    usize size() const { return\
    \ table[0].size(); }\n\n    M fold(const usize l, const usize r) const {\n   \
    \     if (l == r) return M::zero();\n        assert(l < r);\n        const auto\
    \ d = bit_width(r - l) - 1;\n        return table[d][l] + table[d][r - (1 << d)];\n\
    \    }\n};\n"
  code: "#pragma once\n#include \"../utility/int_alias.cpp\"\n#include \"../utility/rep.cpp\"\
    \n#include \"../bit/bit_width.cpp\"\n#include <vector>\n#include <cassert>\n\n\
    template <class IdempotentMonoid>\nclass SparseTable {\n    using M = IdempotentMonoid;\n\
    \    std::vector<std::vector<M>> table;\n\npublic:\n    SparseTable(): SparseTable(std::vector<M>())\
    \ { }\n    explicit SparseTable(const std::vector<M>& vec) {\n        const auto\
    \ size = vec.size();\n        const auto height = bit_width(size); // 4: 3, 7:\
    \ 3, 8: 4\n        table.reserve(height);\n        table.push_back(vec);\n   \
    \     for (const usize d: rep(1, height)) {\n            table.push_back(std::vector<M>(size\
    \ - (1 << d) + 1, M::zero()));\n            for (const usize i: rep(0, table[d].size()))\
    \ {\n                table[d][i] = table[d - 1][i] + table[d - 1][i + (1 << (d\
    \ - 1))];\n            }\n        }\n    }\n\n    usize size() const { return\
    \ table[0].size(); }\n\n    M fold(const usize l, const usize r) const {\n   \
    \     if (l == r) return M::zero();\n        assert(l < r);\n        const auto\
    \ d = bit_width(r - l) - 1;\n        return table[d][l] + table[d][r - (1 << d)];\n\
    \    }\n};\n"
  dependsOn:
  - utility/int_alias.cpp
  - utility/rep.cpp
  - bit/bit_width.cpp
  - bit/bit_lzeros.cpp
  isVerificationFile: false
  path: container/sparse_table.cpp
  requiredBy: []
  timestamp: '2021-04-02 12:34:15+09:00'
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
