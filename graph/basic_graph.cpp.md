---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utility/index_offset.cpp
    title: utility/index_offset.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/heavy_light_decomposition.test.cpp
    title: test/heavy_light_decomposition.test.cpp
  - icon: ':x:'
    path: test/strongly_connected_components.test.cpp
    title: test/strongly_connected_components.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/basic_graph.cpp\"\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n#line 3 \"utility/index_offset.cpp\"\n\nclass IndexOffset {\n\
    \    int offset, len;\n\n  public:\n    constexpr IndexOffset() noexcept : offset(),\
    \ len() {}\n    explicit constexpr IndexOffset(const int o, const int l) noexcept\
    \ : offset(o), len(l) {}\n    constexpr int size() const { return len; }\n   \
    \ constexpr int operator[](const int i) const noexcept {\n        assert(i < len);\n\
    \        return offset + i;\n    }\n    constexpr int to_idx(const int i) const\
    \ noexcept {\n        assert(offset <= i and i < offset + len);\n        return\
    \ i - offset;\n    }\n};\n#line 6 \"graph/basic_graph.cpp\"\n\ntemplate <class\
    \ E = int> class BasicGraph {\n    std::vector<std::vector<E>> graph;\n\n  public:\n\
    \    BasicGraph() : graph() {}\n    explicit BasicGraph(const int n) : graph(n)\
    \ {}\n\n    class EdgePtr {\n        friend class BasicGraph;\n        int u,\
    \ e;\n        BasicGraph* self;\n\n        explicit EdgePtr(const int u, const\
    \ int e, BasicGraph* p) : u(u), e(e), self(p) {}\n\n      public:\n        EdgePtr()\
    \ : u(0), e(0), self(nullptr) {}\n        int src() const { return u; }\n    \
    \    E& operator*() const { return self->graph[u][e]; }\n        E* operator->()\
    \ const { return &self->graph[u][e]; }\n    };\n\n    int size() const { return\
    \ graph.size(); }\n    std::vector<E>& operator[](const int u) {\n        assert(0\
    \ <= u and u < (int)size());\n        return graph[u];\n    }\n    const std::vector<E>&\
    \ operator[](const int u) const {\n        assert(0 <= u and u < (int)size());\n\
    \        return graph[u];\n    }\n\n    int add_vertex() {\n        graph.emplace_back();\n\
    \        return size() - 1;\n    }\n    IndexOffset add_vertices(int n) {\n  \
    \      IndexOffset ret(size(), n);\n        while (n--) graph.emplace_back();\n\
    \        return ret;\n    }\n\n    template <class... Args> EdgePtr add_edge(const\
    \ int u, Args&&... args) {\n        assert(0 <= u and u < (int)size());\n    \
    \    const int e = graph[u].size();\n        graph[u].emplace_back(std::forward<Args>(args)...);\n\
    \        return EdgePtr(u, e, this);\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    #include \"../utility/index_offset.cpp\"\n\ntemplate <class E = int> class BasicGraph\
    \ {\n    std::vector<std::vector<E>> graph;\n\n  public:\n    BasicGraph() : graph()\
    \ {}\n    explicit BasicGraph(const int n) : graph(n) {}\n\n    class EdgePtr\
    \ {\n        friend class BasicGraph;\n        int u, e;\n        BasicGraph*\
    \ self;\n\n        explicit EdgePtr(const int u, const int e, BasicGraph* p) :\
    \ u(u), e(e), self(p) {}\n\n      public:\n        EdgePtr() : u(0), e(0), self(nullptr)\
    \ {}\n        int src() const { return u; }\n        E& operator*() const { return\
    \ self->graph[u][e]; }\n        E* operator->() const { return &self->graph[u][e];\
    \ }\n    };\n\n    int size() const { return graph.size(); }\n    std::vector<E>&\
    \ operator[](const int u) {\n        assert(0 <= u and u < (int)size());\n   \
    \     return graph[u];\n    }\n    const std::vector<E>& operator[](const int\
    \ u) const {\n        assert(0 <= u and u < (int)size());\n        return graph[u];\n\
    \    }\n\n    int add_vertex() {\n        graph.emplace_back();\n        return\
    \ size() - 1;\n    }\n    IndexOffset add_vertices(int n) {\n        IndexOffset\
    \ ret(size(), n);\n        while (n--) graph.emplace_back();\n        return ret;\n\
    \    }\n\n    template <class... Args> EdgePtr add_edge(const int u, Args&&...\
    \ args) {\n        assert(0 <= u and u < (int)size());\n        const int e =\
    \ graph[u].size();\n        graph[u].emplace_back(std::forward<Args>(args)...);\n\
    \        return EdgePtr(u, e, this);\n    }\n};\n"
  dependsOn:
  - utility/index_offset.cpp
  isVerificationFile: false
  path: graph/basic_graph.cpp
  requiredBy: []
  timestamp: '2021-12-17 09:20:39+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/strongly_connected_components.test.cpp
  - test/heavy_light_decomposition.test.cpp
documentation_of: graph/basic_graph.cpp
layout: document
redirect_from:
- /library/graph/basic_graph.cpp
- /library/graph/basic_graph.cpp.html
title: graph/basic_graph.cpp
---
