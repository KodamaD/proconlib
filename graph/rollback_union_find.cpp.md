---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/rollback_union_find.test.cpp
    title: test/rollback_union_find.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/rollback_union_find.cpp\"\n#include <cassert>\n#include\
    \ <stack>\n#include <utility>\n#include <vector>\n#line 2 \"utility/int_alias.cpp\"\
    \n#include <cstddef>\n#include <cstdint>\n\nusing i32 = std::int32_t;\nusing u32\
    \ = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing\
    \ isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 7 \"graph/rollback_union_find.cpp\"\
    \n\nclass RollbackUnionFind {\n    std::vector<usize> data;\n    std::stack<std::pair<usize,\
    \ usize>> history;\n\n  public:\n    explicit RollbackUnionFind(const usize size\
    \ = 0) : data(size, -1), history() {}\n\n    usize size() const { return data.size();\
    \ }\n\n    usize leader(usize u) const {\n        assert(u < size());\n      \
    \  while (data[u] < size()) u = data[u];\n        return u;\n    }\n\n    usize\
    \ size(const usize u) const {\n        assert(u < size());\n        return -data[leader(u)];\n\
    \    }\n\n    std::pair<usize, bool> merge(usize u, usize v) {\n        assert(u\
    \ < size());\n        assert(v < size());\n        u = leader(u);\n        v =\
    \ leader(v);\n        if (u == v) return std::make_pair(u, false);\n        if\
    \ (data[u] > data[v]) std::swap(u, v);\n        history.emplace(u, data[u]);\n\
    \        history.emplace(v, data[v]);\n        data[u] += data[v];\n        data[v]\
    \ = u;\n        return std::make_pair(u, true);\n    }\n\n    bool same(const\
    \ usize u, const usize v) const {\n        assert(u < size());\n        assert(v\
    \ < size());\n        return leader(u) == leader(v);\n    }\n\n    void rollback(const\
    \ usize steps) {\n        assert(2 * steps <= history.size());\n        for (usize\
    \ i = 2 * steps; i > 0; --i) {\n            const auto [k, x] = history.top();\n\
    \            history.pop();\n            data[k] = x;\n        }\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <stack>\n#include <utility>\n\
    #include <vector>\n#include \"../utility/int_alias.cpp\"\n\nclass RollbackUnionFind\
    \ {\n    std::vector<usize> data;\n    std::stack<std::pair<usize, usize>> history;\n\
    \n  public:\n    explicit RollbackUnionFind(const usize size = 0) : data(size,\
    \ -1), history() {}\n\n    usize size() const { return data.size(); }\n\n    usize\
    \ leader(usize u) const {\n        assert(u < size());\n        while (data[u]\
    \ < size()) u = data[u];\n        return u;\n    }\n\n    usize size(const usize\
    \ u) const {\n        assert(u < size());\n        return -data[leader(u)];\n\
    \    }\n\n    std::pair<usize, bool> merge(usize u, usize v) {\n        assert(u\
    \ < size());\n        assert(v < size());\n        u = leader(u);\n        v =\
    \ leader(v);\n        if (u == v) return std::make_pair(u, false);\n        if\
    \ (data[u] > data[v]) std::swap(u, v);\n        history.emplace(u, data[u]);\n\
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
  path: graph/rollback_union_find.cpp
  requiredBy: []
  timestamp: '2021-09-08 18:46:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/rollback_union_find.test.cpp
documentation_of: graph/rollback_union_find.cpp
layout: document
redirect_from:
- /library/graph/rollback_union_find.cpp
- /library/graph/rollback_union_find.cpp.html
title: graph/rollback_union_find.cpp
---
