---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
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
  bundledCode: "#line 2 \"graph/tree_manager.cpp\"\n#include <utility>\n#include <variant>\n\
    #include <vector>\n#line 2 \"utility/int_alias.cpp\"\n#include <cstddef>\n#include\
    \ <cstdint>\n\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64\
    \ = std::int64_t;\nusing u64 = std::uint64_t;\nusing isize = std::ptrdiff_t;\n\
    using usize = std::size_t;\n#line 2 \"utility/rec_lambda.cpp\"\n#include <type_traits>\n\
    #line 4 \"utility/rec_lambda.cpp\"\n\ntemplate <class F> struct RecursiveLambda\
    \ : private F {\n    explicit constexpr RecursiveLambda(F&& f) : F(std::forward<F>(f))\
    \ {}\n    template <class... Args> constexpr decltype(auto) operator()(Args&&...\
    \ args) const {\n        return F::operator()(*this, std::forward<Args>(args)...);\n\
    \    }\n};\n\ntemplate <class F> constexpr decltype(auto) rec_lambda(F&& f) {\
    \ return RecursiveLambda<F>(std::forward<F>(f)); }\n#line 7 \"graph/tree_manager.cpp\"\
    \n\ntemplate <class G> class TreeManager {\n  public:\n    class NodeInfo {\n\
    \        friend class TreeManager;\n        NodeInfo() : parent(0), subtree(0),\
    \ head(0), enter(0), exit(0) {}\n\n      public:\n        usize parent, subtree,\
    \ head, next, enter, exit;\n    };\n\n  private:\n    using Self = TreeManager;\n\
    \    std::vector<NodeInfo> node;\n\n  public:\n    TreeManager() : node() {}\n\
    \    explicit TreeManager(const G& graph, const usize root = 0) : Self(graph,\
    \ std::vector<usize>({root})) {}\n    explicit TreeManager(const G& graph, const\
    \ std::vector<usize>& root) : node(graph.size(), NodeInfo()) {\n        const\
    \ usize n = size();\n        const auto build = rec_lambda([&](auto&& dfs, const\
    \ usize u, const usize p) -> void {\n            node[u].parent = p;\n       \
    \     node[u].subtree = 1;\n            for (const usize v : graph[u]) {\n   \
    \             if (v != p) {\n                    dfs(v, u);\n                \
    \    node[u].subtree += node[v].subtree;\n                }\n            }\n \
    \       });\n        usize time_stamp = 0;\n        const auto decompose = rec_lambda([&](auto&&\
    \ dfs, const usize u, const usize h) -> void {\n            node[u].head = h;\n\
    \            node[u].enter = time_stamp++;\n            usize& s = node[u].next;\n\
    \            s = u;\n            for (const usize v : graph[u])\n            \
    \    if (v != node[u].parent and (s == u or node[s].subtree < node[v].subtree))\
    \ s = v;\n            if (s != u) {\n                dfs(s, h);\n            \
    \    for (const usize v : graph[u])\n                    if (v != node[u].parent\
    \ and v != s) dfs(v, v);\n            }\n            node[u].exit = time_stamp;\n\
    \        });\n        for (const usize r : root) {\n            assert(r < n);\n\
    \            assert(node[r].subtree == 0);\n            build(r, r);\n       \
    \     decompose(r, r);\n        }\n    }\n\n    class Path {\n        friend class\
    \ TreeManager;\n        usize src, dst;\n        const Self* self;\n\n       \
    \ explicit Path(const usize s, const usize d, const Self* p) : src(s), dst(d),\
    \ self(p) {}\n\n      public:\n        Path begin() const { return *this; }\n\
    \        std::monostate end() const { return {}; }\n        bool operator!=(std::monostate)\
    \ const { return src != dst; }\n        void operator++() { src = self->node[src].parent;\
    \ }\n        std::pair<usize, usize> operator*() {\n            const usize x\
    \ = src;\n            const usize y = self->node[src].head;\n            const\
    \ usize z = self->node[dst].next;\n            src = (y != self->node[dst].head\
    \ ? y : z);\n            return std::make_pair(x, src);\n        }\n    };\n\n\
    \    usize size() const { return node.size(); }\n    const NodeInfo& operator[](const\
    \ usize u) const {\n        assert(u < size());\n        return node[u];\n   \
    \ }\n\n    usize lca(usize u, usize v) const {\n        assert(u < size());\n\
    \        assert(v < size());\n        if (node[u].enter > node[v].enter) std::swap(u,\
    \ v);\n        while (node[u].enter < node[v].enter) {\n            if (node[u].head\
    \ == node[v].head) return u;\n            v = node[node[v].head].parent;\n   \
    \     }\n        return v;\n    }\n\n    Path path(const usize des, const usize\
    \ anc) const {\n        assert(des < size());\n        assert(anc < size());\n\
    \        assert(node[anc].enter <= node[des].enter and node[des].exit <= node[anc].exit);\n\
    \        return Path(des, anc, this);\n    }\n};\n"
  code: "#pragma once\n#include <utility>\n#include <variant>\n#include <vector>\n\
    #include \"../utility/int_alias.cpp\"\n#include \"../utility/rec_lambda.cpp\"\n\
    \ntemplate <class G> class TreeManager {\n  public:\n    class NodeInfo {\n  \
    \      friend class TreeManager;\n        NodeInfo() : parent(0), subtree(0),\
    \ head(0), enter(0), exit(0) {}\n\n      public:\n        usize parent, subtree,\
    \ head, next, enter, exit;\n    };\n\n  private:\n    using Self = TreeManager;\n\
    \    std::vector<NodeInfo> node;\n\n  public:\n    TreeManager() : node() {}\n\
    \    explicit TreeManager(const G& graph, const usize root = 0) : Self(graph,\
    \ std::vector<usize>({root})) {}\n    explicit TreeManager(const G& graph, const\
    \ std::vector<usize>& root) : node(graph.size(), NodeInfo()) {\n        const\
    \ usize n = size();\n        const auto build = rec_lambda([&](auto&& dfs, const\
    \ usize u, const usize p) -> void {\n            node[u].parent = p;\n       \
    \     node[u].subtree = 1;\n            for (const usize v : graph[u]) {\n   \
    \             if (v != p) {\n                    dfs(v, u);\n                \
    \    node[u].subtree += node[v].subtree;\n                }\n            }\n \
    \       });\n        usize time_stamp = 0;\n        const auto decompose = rec_lambda([&](auto&&\
    \ dfs, const usize u, const usize h) -> void {\n            node[u].head = h;\n\
    \            node[u].enter = time_stamp++;\n            usize& s = node[u].next;\n\
    \            s = u;\n            for (const usize v : graph[u])\n            \
    \    if (v != node[u].parent and (s == u or node[s].subtree < node[v].subtree))\
    \ s = v;\n            if (s != u) {\n                dfs(s, h);\n            \
    \    for (const usize v : graph[u])\n                    if (v != node[u].parent\
    \ and v != s) dfs(v, v);\n            }\n            node[u].exit = time_stamp;\n\
    \        });\n        for (const usize r : root) {\n            assert(r < n);\n\
    \            assert(node[r].subtree == 0);\n            build(r, r);\n       \
    \     decompose(r, r);\n        }\n    }\n\n    class Path {\n        friend class\
    \ TreeManager;\n        usize src, dst;\n        const Self* self;\n\n       \
    \ explicit Path(const usize s, const usize d, const Self* p) : src(s), dst(d),\
    \ self(p) {}\n\n      public:\n        Path begin() const { return *this; }\n\
    \        std::monostate end() const { return {}; }\n        bool operator!=(std::monostate)\
    \ const { return src != dst; }\n        void operator++() { src = self->node[src].parent;\
    \ }\n        std::pair<usize, usize> operator*() {\n            const usize x\
    \ = src;\n            const usize y = self->node[src].head;\n            const\
    \ usize z = self->node[dst].next;\n            src = (y != self->node[dst].head\
    \ ? y : z);\n            return std::make_pair(x, src);\n        }\n    };\n\n\
    \    usize size() const { return node.size(); }\n    const NodeInfo& operator[](const\
    \ usize u) const {\n        assert(u < size());\n        return node[u];\n   \
    \ }\n\n    usize lca(usize u, usize v) const {\n        assert(u < size());\n\
    \        assert(v < size());\n        if (node[u].enter > node[v].enter) std::swap(u,\
    \ v);\n        while (node[u].enter < node[v].enter) {\n            if (node[u].head\
    \ == node[v].head) return u;\n            v = node[node[v].head].parent;\n   \
    \     }\n        return v;\n    }\n\n    Path path(const usize des, const usize\
    \ anc) const {\n        assert(des < size());\n        assert(anc < size());\n\
    \        assert(node[anc].enter <= node[des].enter and node[des].exit <= node[anc].exit);\n\
    \        return Path(des, anc, this);\n    }\n};"
  dependsOn:
  - utility/int_alias.cpp
  - utility/rec_lambda.cpp
  isVerificationFile: false
  path: graph/tree_manager.cpp
  requiredBy: []
  timestamp: '2021-11-03 19:13:26+09:00'
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
