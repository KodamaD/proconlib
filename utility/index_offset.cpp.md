---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/basic_graph.cpp
    title: graph/basic_graph.cpp
  - icon: ':warning:'
    path: graph/binary_optimization.cpp
    title: graph/binary_optimization.cpp
  - icon: ':heavy_check_mark:'
    path: graph/dinic.cpp
    title: graph/dinic.cpp
  - icon: ':heavy_check_mark:'
    path: graph/primal_dual.cpp
    title: graph/primal_dual.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/bipartite_matching.test.cpp
    title: test/bipartite_matching.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/heavy_light_decomposition.test.cpp
    title: test/heavy_light_decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/primal_dual_maxflow.test.cpp
    title: test/primal_dual_maxflow.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/primal_dual_mincostflow.test.cpp
    title: test/primal_dual_mincostflow.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/strongly_connected_components.test.cpp
    title: test/strongly_connected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/index_offset.cpp\"\n#include <cassert>\n\nclass\
    \ IndexOffset {\n    int offset, len;\n\n  public:\n    constexpr IndexOffset()\
    \ noexcept : offset(), len() {}\n    explicit constexpr IndexOffset(const int\
    \ o, const int l) noexcept : offset(o), len(l) {}\n    constexpr int size() const\
    \ { return len; }\n    constexpr int operator[](const int i) const noexcept {\n\
    \        assert(i < len);\n        return offset + i;\n    }\n    constexpr int\
    \ to_idx(const int i) const noexcept {\n        assert(offset <= i and i < offset\
    \ + len);\n        return i - offset;\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n\nclass IndexOffset {\n    int offset,\
    \ len;\n\n  public:\n    constexpr IndexOffset() noexcept : offset(), len() {}\n\
    \    explicit constexpr IndexOffset(const int o, const int l) noexcept : offset(o),\
    \ len(l) {}\n    constexpr int size() const { return len; }\n    constexpr int\
    \ operator[](const int i) const noexcept {\n        assert(i < len);\n       \
    \ return offset + i;\n    }\n    constexpr int to_idx(const int i) const noexcept\
    \ {\n        assert(offset <= i and i < offset + len);\n        return i - offset;\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: utility/index_offset.cpp
  requiredBy:
  - graph/basic_graph.cpp
  - graph/dinic.cpp
  - graph/primal_dual.cpp
  - graph/binary_optimization.cpp
  timestamp: '2021-12-17 09:20:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/primal_dual_maxflow.test.cpp
  - test/primal_dual_mincostflow.test.cpp
  - test/heavy_light_decomposition.test.cpp
  - test/bipartite_matching.test.cpp
  - test/strongly_connected_components.test.cpp
documentation_of: utility/index_offset.cpp
layout: document
redirect_from:
- /library/utility/index_offset.cpp
- /library/utility/index_offset.cpp.html
title: utility/index_offset.cpp
---
