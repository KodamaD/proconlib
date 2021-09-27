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
  bundledCode: "#line 2 \"container/stack_aggregation.cpp\"\n#include <cassert>\n\
    #include <vector>\n\ntemplate <class M> class StackAggregation {\n    using T\
    \ = typename M::Type;\n\n    struct Node {\n        T value, fold;\n        explicit\
    \ Node(const T value, const T fold) : value(value), fold(fold) {}\n    };\n\n\
    \    std::vector<Node> st;\n\n  public:\n    StackAggregation() = default;\n\n\
    \    bool empty() const { return st.empty(); }\n    T top() const {\n        assert(!empty());\n\
    \        return st.back().value;\n    }\n    T fold() const { return st.empty()\
    \ ? M::identity() : st.back().fold; }\n\n    void push(const T& x) { st.emplace_back(x,\
    \ M::operation(fold(), x)); }\n    void pop() {\n        assert(!empty());\n \
    \       st.pop_back();\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\ntemplate <class M>\
    \ class StackAggregation {\n    using T = typename M::Type;\n\n    struct Node\
    \ {\n        T value, fold;\n        explicit Node(const T value, const T fold)\
    \ : value(value), fold(fold) {}\n    };\n\n    std::vector<Node> st;\n\n  public:\n\
    \    StackAggregation() = default;\n\n    bool empty() const { return st.empty();\
    \ }\n    T top() const {\n        assert(!empty());\n        return st.back().value;\n\
    \    }\n    T fold() const { return st.empty() ? M::identity() : st.back().fold;\
    \ }\n\n    void push(const T& x) { st.emplace_back(x, M::operation(fold(), x));\
    \ }\n    void pop() {\n        assert(!empty());\n        st.pop_back();\n   \
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: container/stack_aggregation.cpp
  requiredBy:
  - container/queue_aggregation.cpp
  timestamp: '2021-09-27 22:23:01+09:00'
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
