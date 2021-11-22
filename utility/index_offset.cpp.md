---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
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
  bundledCode: "#line 2 \"utility/index_offset.cpp\"\n#include <cassert>\n#line 2\
    \ \"utility/int_alias.cpp\"\n#include <cstddef>\n#include <cstdint>\n\nusing i32\
    \ = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing\
    \ u64 = std::uint64_t;\nusing isize = std::ptrdiff_t;\nusing usize = std::size_t;\n\
    #line 4 \"utility/index_offset.cpp\"\n\nclass IndexOffset {\n    usize offset,\
    \ len;\n\n  public:\n    IndexOffset() : offset(), len() {}\n    explicit constexpr\
    \ IndexOffset(const usize o, const usize l) noexcept : offset(o), len(l) {}\n\
    \    constexpr usize size() const { return len; }\n    constexpr usize operator[](const\
    \ usize i) const noexcept {\n        assert(i < len);\n        return offset +\
    \ i;\n    }\n    constexpr usize to_idx(const usize i) const noexcept {\n    \
    \    assert(offset <= i and i < offset + len);\n        return i - offset;\n \
    \   }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include \"int_alias.cpp\"\n\nclass IndexOffset\
    \ {\n    usize offset, len;\n\n  public:\n    IndexOffset() : offset(), len()\
    \ {}\n    explicit constexpr IndexOffset(const usize o, const usize l) noexcept\
    \ : offset(o), len(l) {}\n    constexpr usize size() const { return len; }\n \
    \   constexpr usize operator[](const usize i) const noexcept {\n        assert(i\
    \ < len);\n        return offset + i;\n    }\n    constexpr usize to_idx(const\
    \ usize i) const noexcept {\n        assert(offset <= i and i < offset + len);\n\
    \        return i - offset;\n    }\n};\n"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: utility/index_offset.cpp
  requiredBy:
  - graph/dinic.cpp
  - graph/binary_optimization.cpp
  - graph/basic_graph.cpp
  - graph/primal_dual.cpp
  timestamp: '2021-11-22 20:09:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/heavy_light_decomposition.test.cpp
  - test/primal_dual_mincostflow.test.cpp
  - test/bipartite_matching.test.cpp
  - test/primal_dual_maxflow.test.cpp
  - test/strongly_connected_components.test.cpp
documentation_of: utility/index_offset.cpp
layout: document
redirect_from:
- /library/utility/index_offset.cpp
- /library/utility/index_offset.cpp.html
title: utility/index_offset.cpp
---
