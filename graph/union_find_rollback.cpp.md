---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/union_find_rollback.test.cpp
    title: test/union_find_rollback.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n#include <cstddef>\n\
    \nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    using isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 3 \"graph/union_find_rollback.cpp\"\
    \n#include <vector>\n#include <stack>\n#include <utility>\n#include <cassert>\n\
    \nclass UnionFindRollback {\n    std::vector<usize> data;\n    std::stack<std::pair<usize,\
    \ usize>> history;\n\npublic:\n    explicit UnionFindRollback(const usize size\
    \ = 0): data(size, -1), history() { }\n\n    usize size() const { return data.size();\
    \ }\n\n    usize leader(usize u) const {\n        assert(u < size());\n      \
    \  while (data[u] < size()) u = data[u];\n        return u;\n    }\n\n    usize\
    \ size(const usize u) const {\n        assert(u < size());\n        return -data[leader(u)];\n\
    \    }\n\n    std::pair<usize, bool> merge(usize u, usize v) {\n        assert(u\
    \ < size());\n        assert(v < size());\n        u = leader(u); \n        v\
    \ = leader(v);\n        if (u == v) return std::make_pair(u, false);\n       \
    \ if (data[u] > data[v]) std::swap(u, v);\n        history.emplace(u, data[u]);\n\
    \        history.emplace(v, data[v]);\n        data[u] += data[v];\n        data[v]\
    \ = u;\n        return std::make_pair(u, true);\n    }\n\n    bool same(const\
    \ usize u, const usize v) const {\n        assert(u < size());\n        assert(v\
    \ < size());\n        return leader(u) == leader(v);\n    }\n\n    void rollback(const\
    \ usize steps) {\n        assert(2 * steps <= history.size());\n        for (usize\
    \ i = 2 * steps; i > 0; --i) {\n            const auto [k, x] = history.top();\n\
    \            history.pop();\n            data[k] = x;\n        }\n    }\n};\n"
  code: "#pragma once\n#include \"../utility/int_alias.cpp\"\n#include <vector>\n\
    #include <stack>\n#include <utility>\n#include <cassert>\n\nclass UnionFindRollback\
    \ {\n    std::vector<usize> data;\n    std::stack<std::pair<usize, usize>> history;\n\
    \npublic:\n    explicit UnionFindRollback(const usize size = 0): data(size, -1),\
    \ history() { }\n\n    usize size() const { return data.size(); }\n\n    usize\
    \ leader(usize u) const {\n        assert(u < size());\n        while (data[u]\
    \ < size()) u = data[u];\n        return u;\n    }\n\n    usize size(const usize\
    \ u) const {\n        assert(u < size());\n        return -data[leader(u)];\n\
    \    }\n\n    std::pair<usize, bool> merge(usize u, usize v) {\n        assert(u\
    \ < size());\n        assert(v < size());\n        u = leader(u); \n        v\
    \ = leader(v);\n        if (u == v) return std::make_pair(u, false);\n       \
    \ if (data[u] > data[v]) std::swap(u, v);\n        history.emplace(u, data[u]);\n\
    \        history.emplace(v, data[v]);\n        data[u] += data[v];\n        data[v]\
    \ = u;\n        return std::make_pair(u, true);\n    }\n\n    bool same(const\
    \ usize u, const usize v) const {\n        assert(u < size());\n        assert(v\
    \ < size());\n        return leader(u) == leader(v);\n    }\n\n    void rollback(const\
    \ usize steps) {\n        assert(2 * steps <= history.size());\n        for (usize\
    \ i = 2 * steps; i > 0; --i) {\n            const auto [k, x] = history.top();\n\
    \            history.pop();\n            data[k] = x;\n        }\n    }\n};"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: graph/union_find_rollback.cpp
  requiredBy: []
  timestamp: '2021-04-28 16:45:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/union_find_rollback.test.cpp
documentation_of: graph/union_find_rollback.cpp
layout: document
redirect_from:
- /library/graph/union_find_rollback.cpp
- /library/graph/union_find_rollback.cpp.html
title: graph/union_find_rollback.cpp
---
