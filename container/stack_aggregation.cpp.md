---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: container/queue_aggregation.cpp
    title: container/queue_aggregation.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/queue_aggregation.test.cpp
    title: test/queue_aggregation.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"container/stack_aggregation.cpp\"\n#include <vector>\n#include\
    \ <cassert>\n\ntemplate <class Monoid> class StackAggregation {\n    using M =\
    \ Monoid;\n\n    struct Node {\n        M value, fold;\n        explicit Node(const\
    \ M value, const M fold) : value(value), fold(fold) {}\n    };\n\n    std::vector<Node>\
    \ st;\n\n  public:\n    StackAggregation() = default;\n\n    bool empty() const\
    \ { return st.empty(); }\n    M top() const {\n        assert(!empty());\n   \
    \     return st.back().value;\n    }\n    M fold() const { return st.empty() ?\
    \ M::zero() : st.back().fold; }\n\n    void push(const M& x) { st.emplace_back(x,\
    \ fold() + x); }\n    void pop() {\n        assert(!empty());\n        st.pop_back();\n\
    \    }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\n\ntemplate <class Monoid>\
    \ class StackAggregation {\n    using M = Monoid;\n\n    struct Node {\n     \
    \   M value, fold;\n        explicit Node(const M value, const M fold) : value(value),\
    \ fold(fold) {}\n    };\n\n    std::vector<Node> st;\n\n  public:\n    StackAggregation()\
    \ = default;\n\n    bool empty() const { return st.empty(); }\n    M top() const\
    \ {\n        assert(!empty());\n        return st.back().value;\n    }\n    M\
    \ fold() const { return st.empty() ? M::zero() : st.back().fold; }\n\n    void\
    \ push(const M& x) { st.emplace_back(x, fold() + x); }\n    void pop() {\n   \
    \     assert(!empty());\n        st.pop_back();\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: container/stack_aggregation.cpp
  requiredBy:
  - container/queue_aggregation.cpp
  timestamp: '2021-09-04 18:33:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/queue_aggregation.test.cpp
documentation_of: container/stack_aggregation.cpp
layout: document
redirect_from:
- /library/container/stack_aggregation.cpp
- /library/container/stack_aggregation.cpp.html
title: container/stack_aggregation.cpp
---
