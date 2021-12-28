---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/rec_lambda.cpp
    title: utility/rec_lambda.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/heavy_light_decomposition.test.cpp
    title: test/heavy_light_decomposition.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/tree_manager.cpp\"\n#include <cassert>\n#include <utility>\n\
    #include <variant>\n#include <vector>\n#line 2 \"utility/rec_lambda.cpp\"\n#include\
    \ <type_traits>\n#line 4 \"utility/rec_lambda.cpp\"\n\ntemplate <class F> struct\
    \ RecursiveLambda : private F {\n    explicit constexpr RecursiveLambda(F&& f)\
    \ : F(std::forward<F>(f)) {}\n    template <class... Args> constexpr decltype(auto)\
    \ operator()(Args&&... args) const {\n        return F::operator()(*this, std::forward<Args>(args)...);\n\
    \    }\n};\n\ntemplate <class F> constexpr decltype(auto) rec_lambda(F&& f) {\
    \ return RecursiveLambda<F>(std::forward<F>(f)); }\n#line 7 \"graph/tree_manager.cpp\"\
    \n\ntemplate <class G> class TreeManager {\n  public:\n    class NodeInfo {\n\
    \        friend class TreeManager;\n        NodeInfo() : parent(0), subtree(0),\
    \ head(0), enter(0), exit(0) {}\n\n      public:\n        int parent, subtree,\
    \ head, next, enter, exit;\n    };\n\n  private:\n    using Self = TreeManager;\n\
    \    std::vector<NodeInfo> node;\n\n  public:\n    TreeManager() : node() {}\n\
    \    explicit TreeManager(const G& graph, const int root = 0) : Self(graph, std::vector<int>({root}))\
    \ {}\n    explicit TreeManager(const G& graph, const std::vector<int>& root) :\
    \ node(graph.size(), NodeInfo()) {\n        const int n = size();\n        const\
    \ auto build = rec_lambda([&](auto&& dfs, const int u, const int p) -> void {\n\
    \            node[u].parent = p;\n            node[u].subtree = 1;\n         \
    \   for (const int v : graph[u]) {\n                if (v != p) {\n          \
    \          dfs(v, u);\n                    node[u].subtree += node[v].subtree;\n\
    \                }\n            }\n        });\n        int time_stamp = 0;\n\
    \        const auto decompose = rec_lambda([&](auto&& dfs, const int u, const\
    \ int h) -> void {\n            node[u].head = h;\n            node[u].enter =\
    \ time_stamp++;\n            int& s = node[u].next;\n            s = u;\n    \
    \        for (const int v : graph[u])\n                if (v != node[u].parent\
    \ and (s == u or node[s].subtree < node[v].subtree)) s = v;\n            if (s\
    \ != u) {\n                dfs(s, h);\n                for (const int v : graph[u])\n\
    \                    if (v != node[u].parent and v != s) dfs(v, v);\n        \
    \    }\n            node[u].exit = time_stamp;\n        });\n        for (const\
    \ int r : root) {\n            assert(0 <= r < n);\n            assert(node[r].subtree\
    \ == 0);\n            build(r, r);\n            decompose(r, r);\n        }\n\
    \    }\n\n    class Path {\n        friend class TreeManager;\n        int src,\
    \ dst;\n        const Self* self;\n\n        explicit Path(const int s, const\
    \ int d, const Self* p) : src(s), dst(d), self(p) {}\n\n      public:\n      \
    \  Path begin() const { return *this; }\n        std::monostate end() const {\
    \ return {}; }\n        bool operator!=(std::monostate) const { return src !=\
    \ dst; }\n        void operator++() { src = self->node[src].parent; }\n      \
    \  std::pair<int, int> operator*() {\n            const int x = src;\n       \
    \     const int y = self->node[src].head;\n            const int z = self->node[dst].next;\n\
    \            src = (y != self->node[dst].head ? y : z);\n            return std::make_pair(x,\
    \ src);\n        }\n    };\n\n    int size() const { return node.size(); }\n \
    \   const NodeInfo& operator[](const int u) const {\n        assert(0 <= u and\
    \ u < size());\n        return node[u];\n    }\n\n    int lca(int u, int v) const\
    \ {\n        assert(0 <= u and u < size());\n        assert(0 <= v and v < size());\n\
    \        if (node[u].enter > node[v].enter) std::swap(u, v);\n        while (node[u].enter\
    \ < node[v].enter) {\n            if (node[u].head == node[v].head) return u;\n\
    \            v = node[node[v].head].parent;\n        }\n        return v;\n  \
    \  }\n\n    Path path(const int des, const int anc) const {\n        assert(0\
    \ <= des and des < size());\n        assert(0 <= anc and anc < size());\n    \
    \    assert(node[anc].enter <= node[des].enter and node[des].exit <= node[anc].exit);\n\
    \        return Path(des, anc, this);\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <utility>\n#include <variant>\n\
    #include <vector>\n#include \"../utility/rec_lambda.cpp\"\n\ntemplate <class G>\
    \ class TreeManager {\n  public:\n    class NodeInfo {\n        friend class TreeManager;\n\
    \        NodeInfo() : parent(0), subtree(0), head(0), enter(0), exit(0) {}\n\n\
    \      public:\n        int parent, subtree, head, next, enter, exit;\n    };\n\
    \n  private:\n    using Self = TreeManager;\n    std::vector<NodeInfo> node;\n\
    \n  public:\n    TreeManager() : node() {}\n    explicit TreeManager(const G&\
    \ graph, const int root = 0) : Self(graph, std::vector<int>({root})) {}\n    explicit\
    \ TreeManager(const G& graph, const std::vector<int>& root) : node(graph.size(),\
    \ NodeInfo()) {\n        const int n = size();\n        const auto build = rec_lambda([&](auto&&\
    \ dfs, const int u, const int p) -> void {\n            node[u].parent = p;\n\
    \            node[u].subtree = 1;\n            for (const int v : graph[u]) {\n\
    \                if (v != p) {\n                    dfs(v, u);\n             \
    \       node[u].subtree += node[v].subtree;\n                }\n            }\n\
    \        });\n        int time_stamp = 0;\n        const auto decompose = rec_lambda([&](auto&&\
    \ dfs, const int u, const int h) -> void {\n            node[u].head = h;\n  \
    \          node[u].enter = time_stamp++;\n            int& s = node[u].next;\n\
    \            s = u;\n            for (const int v : graph[u])\n              \
    \  if (v != node[u].parent and (s == u or node[s].subtree < node[v].subtree))\
    \ s = v;\n            if (s != u) {\n                dfs(s, h);\n            \
    \    for (const int v : graph[u])\n                    if (v != node[u].parent\
    \ and v != s) dfs(v, v);\n            }\n            node[u].exit = time_stamp;\n\
    \        });\n        for (const int r : root) {\n            assert(0 <= r <\
    \ n);\n            assert(node[r].subtree == 0);\n            build(r, r);\n \
    \           decompose(r, r);\n        }\n    }\n\n    class Path {\n        friend\
    \ class TreeManager;\n        int src, dst;\n        const Self* self;\n\n   \
    \     explicit Path(const int s, const int d, const Self* p) : src(s), dst(d),\
    \ self(p) {}\n\n      public:\n        Path begin() const { return *this; }\n\
    \        std::monostate end() const { return {}; }\n        bool operator!=(std::monostate)\
    \ const { return src != dst; }\n        void operator++() { src = self->node[src].parent;\
    \ }\n        std::pair<int, int> operator*() {\n            const int x = src;\n\
    \            const int y = self->node[src].head;\n            const int z = self->node[dst].next;\n\
    \            src = (y != self->node[dst].head ? y : z);\n            return std::make_pair(x,\
    \ src);\n        }\n    };\n\n    int size() const { return node.size(); }\n \
    \   const NodeInfo& operator[](const int u) const {\n        assert(0 <= u and\
    \ u < size());\n        return node[u];\n    }\n\n    int lca(int u, int v) const\
    \ {\n        assert(0 <= u and u < size());\n        assert(0 <= v and v < size());\n\
    \        if (node[u].enter > node[v].enter) std::swap(u, v);\n        while (node[u].enter\
    \ < node[v].enter) {\n            if (node[u].head == node[v].head) return u;\n\
    \            v = node[node[v].head].parent;\n        }\n        return v;\n  \
    \  }\n\n    Path path(const int des, const int anc) const {\n        assert(0\
    \ <= des and des < size());\n        assert(0 <= anc and anc < size());\n    \
    \    assert(node[anc].enter <= node[des].enter and node[des].exit <= node[anc].exit);\n\
    \        return Path(des, anc, this);\n    }\n};"
  dependsOn:
  - utility/rec_lambda.cpp
  isVerificationFile: false
  path: graph/tree_manager.cpp
  requiredBy: []
  timestamp: '2021-12-28 21:38:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/heavy_light_decomposition.test.cpp
documentation_of: graph/tree_manager.cpp
layout: document
redirect_from:
- /library/graph/tree_manager.cpp
- /library/graph/tree_manager.cpp.html
title: graph/tree_manager.cpp
---
