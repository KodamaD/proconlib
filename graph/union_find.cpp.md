---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/union_find.test.cpp
    title: test/union_find.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/union_find.cpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <vector>\n#line 3 \"utility/rep.cpp\"\n\nclass Range {\n    struct Iter\
    \ {\n        int itr;\n        constexpr Iter(const int pos) noexcept : itr(pos)\
    \ {}\n        constexpr void operator++() noexcept { ++itr; }\n        constexpr\
    \ bool operator!=(const Iter& other) const noexcept { return itr != other.itr;\
    \ }\n        constexpr int operator*() const noexcept { return itr; }\n    };\n\
    \    const Iter first, last;\n\n  public:\n    explicit constexpr Range(const\
    \ int first, const int last) noexcept : first(first), last(std::max(first, last))\
    \ {}\n    constexpr Iter begin() const noexcept { return first; }\n    constexpr\
    \ Iter end() const noexcept { return last; }\n};\n\nconstexpr Range rep(const\
    \ int l, const int r) noexcept { return Range(l, r); }\nconstexpr Range rep(const\
    \ int n) noexcept { return Range(0, n); }\n#line 6 \"graph/union_find.cpp\"\n\n\
    class UnionFind {\n    int components;\n    std::vector<int> data;\n\n  public:\n\
    \    explicit UnionFind(const int size = 0) : components(size), data(size, (int)-1)\
    \ {}\n\n    int size() const { return data.size(); }\n    int count() const {\
    \ return components; }\n\n    int leader(const int u) {\n        assert(0 <= u\
    \ and u < size());\n        return data[u] < 0 ? u : data[u] = leader(data[u]);\n\
    \    }\n\n    int size(const int u) {\n        assert(0 <= u and u < size());\n\
    \        return -data[leader(u)];\n    }\n\n    std::pair<int, bool> merge(int\
    \ u, int v) {\n        assert(0 <= u and u < size());\n        assert(0 <= v and\
    \ v < size());\n        u = leader(u);\n        v = leader(v);\n        if (u\
    \ == v) return std::make_pair(u, false);\n        if (data[u] > data[v]) std::swap(u,\
    \ v);\n        components -= 1;\n        data[u] += data[v];\n        data[v]\
    \ = u;\n        return std::make_pair(u, true);\n    }\n\n    bool same(const\
    \ int u, const int v) {\n        assert(0 <= u and u < size());\n        assert(0\
    \ <= v and v < size());\n        return leader(u) == leader(v);\n    }\n\n   \
    \ std::vector<std::vector<int>> decompose() {\n        std::vector<int> buf(size()),\
    \ len(size());\n        for (const int i : rep(size())) len[buf[i] = leader(i)]++;\n\
    \        std::vector<std::vector<int>> ret(size());\n        for (const int i\
    \ : rep(size())) ret[i].reserve(len[i]);\n        for (const int i : rep(size()))\
    \ ret[buf[i]].push_back(i);\n        ret.erase(std::remove_if(ret.begin(), ret.end(),\
    \ [&](const std::vector<int>& v) { return v.empty(); }),\n                  ret.end());\n\
    \        return ret;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    #include \"../utility/rep.cpp\"\n\nclass UnionFind {\n    int components;\n  \
    \  std::vector<int> data;\n\n  public:\n    explicit UnionFind(const int size\
    \ = 0) : components(size), data(size, (int)-1) {}\n\n    int size() const { return\
    \ data.size(); }\n    int count() const { return components; }\n\n    int leader(const\
    \ int u) {\n        assert(0 <= u and u < size());\n        return data[u] < 0\
    \ ? u : data[u] = leader(data[u]);\n    }\n\n    int size(const int u) {\n   \
    \     assert(0 <= u and u < size());\n        return -data[leader(u)];\n    }\n\
    \n    std::pair<int, bool> merge(int u, int v) {\n        assert(0 <= u and u\
    \ < size());\n        assert(0 <= v and v < size());\n        u = leader(u);\n\
    \        v = leader(v);\n        if (u == v) return std::make_pair(u, false);\n\
    \        if (data[u] > data[v]) std::swap(u, v);\n        components -= 1;\n \
    \       data[u] += data[v];\n        data[v] = u;\n        return std::make_pair(u,\
    \ true);\n    }\n\n    bool same(const int u, const int v) {\n        assert(0\
    \ <= u and u < size());\n        assert(0 <= v and v < size());\n        return\
    \ leader(u) == leader(v);\n    }\n\n    std::vector<std::vector<int>> decompose()\
    \ {\n        std::vector<int> buf(size()), len(size());\n        for (const int\
    \ i : rep(size())) len[buf[i] = leader(i)]++;\n        std::vector<std::vector<int>>\
    \ ret(size());\n        for (const int i : rep(size())) ret[i].reserve(len[i]);\n\
    \        for (const int i : rep(size())) ret[buf[i]].push_back(i);\n        ret.erase(std::remove_if(ret.begin(),\
    \ ret.end(), [&](const std::vector<int>& v) { return v.empty(); }),\n        \
    \          ret.end());\n        return ret;\n    }\n};"
  dependsOn:
  - utility/rep.cpp
  isVerificationFile: false
  path: graph/union_find.cpp
  requiredBy: []
  timestamp: '2022-01-07 21:48:21+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/union_find.test.cpp
documentation_of: graph/union_find.cpp
layout: document
redirect_from:
- /library/graph/union_find.cpp
- /library/graph/union_find.cpp.html
title: graph/union_find.cpp
---
