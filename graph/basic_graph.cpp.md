---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/index_offset.cpp
    title: utility/index_offset.cpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/heavy_light_decomposition.test.cpp
    title: test/heavy_light_decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/strongly_connected_components.test.cpp
    title: test/strongly_connected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/basic_graph.cpp\"\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n#line 2 \"utility/int_alias.cpp\"\n#include <cstddef>\n#include\
    \ <cstdint>\n\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64\
    \ = std::int64_t;\nusing u64 = std::uint64_t;\nusing isize = std::ptrdiff_t;\n\
    using usize = std::size_t;\n#line 4 \"utility/index_offset.cpp\"\n\nclass IndexOffset\
    \ {\n    usize offset, len;\n\n  public:\n    IndexOffset() : offset(), len()\
    \ {}\n    explicit constexpr IndexOffset(const usize o, const usize l) noexcept\
    \ : offset(o), len(l) {}\n    constexpr usize size() const { return len; }\n \
    \   constexpr usize operator[](const usize i) const noexcept {\n        assert(i\
    \ < len);\n        return offset + i;\n    }\n    constexpr usize to_idx(const\
    \ usize i) const noexcept {\n        assert(offset <= i and i < offset + len);\n\
    \        return i - offset;\n    }\n};\n#line 7 \"graph/basic_graph.cpp\"\n\n\
    template <class E = usize> class BasicGraph {\n    std::vector<std::vector<E>>\
    \ graph;\n\n  public:\n    BasicGraph() : graph() {}\n    explicit BasicGraph(const\
    \ usize n) : graph(n) {}\n\n    class EdgePtr {\n        friend class BasicGraph;\n\
    \        usize u, e;\n        BasicGraph* self;\n\n        explicit EdgePtr(const\
    \ usize u, const usize e, BasicGraph* p) : u(u), e(e), self(p) {}\n\n      public:\n\
    \        EdgePtr() : u(0), e(0), self(nullptr) {}\n        usize src() const {\
    \ return u; }\n        E& operator*() const { return self->graph[u][e]; }\n  \
    \      E* operator->() const { return &self->graph[u][e]; }\n    };\n\n    usize\
    \ size() const { return graph.size(); }\n    std::vector<E>& operator[](const\
    \ usize u) {\n        assert(u < size());\n        return graph[u];\n    }\n \
    \   const std::vector<E>& operator[](const usize u) const {\n        assert(u\
    \ < size());\n        return graph[u];\n    }\n\n    usize add_vertex() {\n  \
    \      graph.emplace_back();\n        return size() - 1;\n    }\n    IndexOffset\
    \ add_vertices(usize n) {\n        IndexOffset ret(size(), n);\n        while\
    \ (n--) graph.emplace_back();\n        return ret;\n    }\n\n    template <class...\
    \ Args> EdgePtr add_edge(const usize u, Args&&... args) {\n        assert(u <\
    \ size());\n        const usize e = graph[u].size();\n        graph[u].emplace_back(std::forward<Args>(args)...);\n\
    \        return EdgePtr(u, e, this);\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    #include \"../utility/index_offset.cpp\"\n#include \"../utility/int_alias.cpp\"\
    \n\ntemplate <class E = usize> class BasicGraph {\n    std::vector<std::vector<E>>\
    \ graph;\n\n  public:\n    BasicGraph() : graph() {}\n    explicit BasicGraph(const\
    \ usize n) : graph(n) {}\n\n    class EdgePtr {\n        friend class BasicGraph;\n\
    \        usize u, e;\n        BasicGraph* self;\n\n        explicit EdgePtr(const\
    \ usize u, const usize e, BasicGraph* p) : u(u), e(e), self(p) {}\n\n      public:\n\
    \        EdgePtr() : u(0), e(0), self(nullptr) {}\n        usize src() const {\
    \ return u; }\n        E& operator*() const { return self->graph[u][e]; }\n  \
    \      E* operator->() const { return &self->graph[u][e]; }\n    };\n\n    usize\
    \ size() const { return graph.size(); }\n    std::vector<E>& operator[](const\
    \ usize u) {\n        assert(u < size());\n        return graph[u];\n    }\n \
    \   const std::vector<E>& operator[](const usize u) const {\n        assert(u\
    \ < size());\n        return graph[u];\n    }\n\n    usize add_vertex() {\n  \
    \      graph.emplace_back();\n        return size() - 1;\n    }\n    IndexOffset\
    \ add_vertices(usize n) {\n        IndexOffset ret(size(), n);\n        while\
    \ (n--) graph.emplace_back();\n        return ret;\n    }\n\n    template <class...\
    \ Args> EdgePtr add_edge(const usize u, Args&&... args) {\n        assert(u <\
    \ size());\n        const usize e = graph[u].size();\n        graph[u].emplace_back(std::forward<Args>(args)...);\n\
    \        return EdgePtr(u, e, this);\n    }\n};\n"
  dependsOn:
  - utility/index_offset.cpp
  - utility/int_alias.cpp
  isVerificationFile: false
  path: graph/basic_graph.cpp
  requiredBy: []
  timestamp: '2021-11-22 20:09:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/heavy_light_decomposition.test.cpp
  - test/strongly_connected_components.test.cpp
documentation_of: graph/basic_graph.cpp
layout: document
redirect_from:
- /library/graph/basic_graph.cpp
- /library/graph/basic_graph.cpp.html
title: graph/basic_graph.cpp
---
