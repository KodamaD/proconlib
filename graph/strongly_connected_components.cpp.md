---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utility/rec_lambda.cpp
    title: utility/rec_lambda.cpp
  - icon: ':question:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  - icon: ':question:'
    path: utility/setmin.cpp
    title: utility/setmin.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/strongly_connected_components.test.cpp
    title: test/strongly_connected_components.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/strongly_connected_components.cpp\"\n#include <cassert>\n\
    #include <vector>\n#line 2 \"utility/rec_lambda.cpp\"\n#include <type_traits>\n\
    #include <utility>\n\ntemplate <class F> struct RecursiveLambda : private F {\n\
    \    explicit constexpr RecursiveLambda(F&& f) : F(std::forward<F>(f)) {}\n  \
    \  template <class... Args> constexpr decltype(auto) operator()(Args&&... args)\
    \ const {\n        return F::operator()(*this, std::forward<Args>(args)...);\n\
    \    }\n};\n\ntemplate <class F> constexpr decltype(auto) rec_lambda(F&& f) {\
    \ return RecursiveLambda<F>(std::forward<F>(f)); }\n#line 2 \"utility/rep.cpp\"\
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
    \ { return Range(0, n); }\n#line 2 \"utility/setmin.cpp\"\n\ntemplate <class T>\
    \ bool setmin(T& lhs, const T& rhs) {\n    if (lhs > rhs) {\n        lhs = rhs;\n\
    \        return true;\n    }\n    return false;\n}\n#line 7 \"graph/strongly_connected_components.cpp\"\
    \n\ntemplate <class G> class StronglyConnectedComponents {\n    int count;\n \
    \   std::vector<int> index;\n\n  public:\n    StronglyConnectedComponents() :\
    \ count(0), index() {}\n    explicit StronglyConnectedComponents(const G& graph)\
    \ : count(0), index(graph.size()) {\n        const int n = size();\n        int\
    \ time_stamp = 0;\n        std::vector<int> visited, low(n), ord(n);\n       \
    \ visited.reserve(n);\n        const auto dfs = rec_lambda([&](auto&& dfs, const\
    \ int u) -> void {\n            low[u] = ord[u] = ++time_stamp;\n            visited.push_back(u);\n\
    \            for (const int v : graph[u]) {\n                if (!ord[v]) {\n\
    \                    dfs(v);\n                    setmin(low[u], low[v]);\n  \
    \              } else {\n                    setmin(low[u], ord[v]);\n       \
    \         }\n            }\n            if (low[u] == ord[u]) {\n            \
    \    while (true) {\n                    const int v = visited.back();\n     \
    \               visited.pop_back();\n                    ord[v] = n;\n       \
    \             index[v] = count;\n                    if (u == v) break;\n    \
    \            }\n                count += 1;\n            }\n        });\n    \
    \    for (const int u : rep(0, n))\n            if (!ord[u]) dfs(u);\n       \
    \ for (auto& x : index) x = count - x - 1;\n    }\n\n    int size() const { return\
    \ index.size(); }\n    int group_count() const { return count; }\n    int group_id(const\
    \ int u) const {\n        assert(0 <= u and u < size());\n        return index[u];\n\
    \    }\n\n    std::vector<std::vector<int>> decopmose() const {\n        std::vector<std::vector<int>>\
    \ ret(group_count());\n        for (const int u : rep(0, size())) ret[index[u]].push_back(u);\n\
    \        return ret;\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n#include \"../utility/rec_lambda.cpp\"\
    \n#include \"../utility/rep.cpp\"\n#include \"../utility/setmin.cpp\"\n\ntemplate\
    \ <class G> class StronglyConnectedComponents {\n    int count;\n    std::vector<int>\
    \ index;\n\n  public:\n    StronglyConnectedComponents() : count(0), index() {}\n\
    \    explicit StronglyConnectedComponents(const G& graph) : count(0), index(graph.size())\
    \ {\n        const int n = size();\n        int time_stamp = 0;\n        std::vector<int>\
    \ visited, low(n), ord(n);\n        visited.reserve(n);\n        const auto dfs\
    \ = rec_lambda([&](auto&& dfs, const int u) -> void {\n            low[u] = ord[u]\
    \ = ++time_stamp;\n            visited.push_back(u);\n            for (const int\
    \ v : graph[u]) {\n                if (!ord[v]) {\n                    dfs(v);\n\
    \                    setmin(low[u], low[v]);\n                } else {\n     \
    \               setmin(low[u], ord[v]);\n                }\n            }\n  \
    \          if (low[u] == ord[u]) {\n                while (true) {\n         \
    \           const int v = visited.back();\n                    visited.pop_back();\n\
    \                    ord[v] = n;\n                    index[v] = count;\n    \
    \                if (u == v) break;\n                }\n                count\
    \ += 1;\n            }\n        });\n        for (const int u : rep(0, n))\n \
    \           if (!ord[u]) dfs(u);\n        for (auto& x : index) x = count - x\
    \ - 1;\n    }\n\n    int size() const { return index.size(); }\n    int group_count()\
    \ const { return count; }\n    int group_id(const int u) const {\n        assert(0\
    \ <= u and u < size());\n        return index[u];\n    }\n\n    std::vector<std::vector<int>>\
    \ decopmose() const {\n        std::vector<std::vector<int>> ret(group_count());\n\
    \        for (const int u : rep(0, size())) ret[index[u]].push_back(u);\n    \
    \    return ret;\n    }\n};\n"
  dependsOn:
  - utility/rec_lambda.cpp
  - utility/rep.cpp
  - utility/setmin.cpp
  isVerificationFile: false
  path: graph/strongly_connected_components.cpp
  requiredBy: []
  timestamp: '2021-12-17 09:20:39+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/strongly_connected_components.test.cpp
documentation_of: graph/strongly_connected_components.cpp
layout: document
redirect_from:
- /library/graph/strongly_connected_components.cpp
- /library/graph/strongly_connected_components.cpp.html
title: graph/strongly_connected_components.cpp
---
