---
data:
  _extendedDependsOn: []
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
    \ <utility>\n#include <vector>\n\nclass RollbackUnionFind {\n    std::vector<int>\
    \ data;\n    std::vector<std::pair<int, int>> history;\n\n  public:\n    explicit\
    \ RollbackUnionFind(const int size = 0) : data(size, -1), history() {}\n\n   \
    \ int size() const { return data.size(); }\n\n    int leader(int u) const {\n\
    \        assert(0 <= u and u < size());\n        while (data[u] >= 0) u = data[u];\n\
    \        return u;\n    }\n\n    int size(const int u) const {\n        assert(0\
    \ <= u and u < size());\n        return -data[leader(u)];\n    }\n\n    std::pair<int,\
    \ bool> merge(int u, int v) {\n        assert(0 <= u and u < size());\n      \
    \  assert(0 <= v and v < size());\n        u = leader(u);\n        v = leader(v);\n\
    \        if (u == v) return std::make_pair(u, false);\n        if (data[u] > data[v])\
    \ std::swap(u, v);\n        history.emplace_back(u, data[u]);\n        history.emplace_back(v,\
    \ data[v]);\n        data[u] += data[v];\n        data[v] = u;\n        return\
    \ std::make_pair(u, true);\n    }\n\n    bool same(const int u, const int v) const\
    \ {\n        assert(0 <= u and u < size());\n        assert(0 <= v and v < size());\n\
    \        return leader(u) == leader(v);\n    }\n\n    void rollback(const int\
    \ steps) {\n        assert(0 <= steps and 2 * steps <= history.size());\n    \
    \    for (int i = 2 * steps; i > 0; --i) {\n            const auto [k, x] = history.back();\n\
    \            history.pop_back();\n            data[k] = x;\n        }\n    }\n\
    };\n"
  code: "#pragma once\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    \nclass RollbackUnionFind {\n    std::vector<int> data;\n    std::vector<std::pair<int,\
    \ int>> history;\n\n  public:\n    explicit RollbackUnionFind(const int size =\
    \ 0) : data(size, -1), history() {}\n\n    int size() const { return data.size();\
    \ }\n\n    int leader(int u) const {\n        assert(0 <= u and u < size());\n\
    \        while (data[u] >= 0) u = data[u];\n        return u;\n    }\n\n    int\
    \ size(const int u) const {\n        assert(0 <= u and u < size());\n        return\
    \ -data[leader(u)];\n    }\n\n    std::pair<int, bool> merge(int u, int v) {\n\
    \        assert(0 <= u and u < size());\n        assert(0 <= v and v < size());\n\
    \        u = leader(u);\n        v = leader(v);\n        if (u == v) return std::make_pair(u,\
    \ false);\n        if (data[u] > data[v]) std::swap(u, v);\n        history.emplace_back(u,\
    \ data[u]);\n        history.emplace_back(v, data[v]);\n        data[u] += data[v];\n\
    \        data[v] = u;\n        return std::make_pair(u, true);\n    }\n\n    bool\
    \ same(const int u, const int v) const {\n        assert(0 <= u and u < size());\n\
    \        assert(0 <= v and v < size());\n        return leader(u) == leader(v);\n\
    \    }\n\n    void rollback(const int steps) {\n        assert(0 <= steps and\
    \ 2 * steps <= history.size());\n        for (int i = 2 * steps; i > 0; --i) {\n\
    \            const auto [k, x] = history.back();\n            history.pop_back();\n\
    \            data[k] = x;\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/rollback_union_find.cpp
  requiredBy: []
  timestamp: '2021-12-17 09:20:39+09:00'
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
