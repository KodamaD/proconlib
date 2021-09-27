---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: container/stack_aggregation.cpp
    title: container/stack_aggregation.cpp
  - icon: ':heavy_check_mark:'
    path: traits/reversed_monoid.cpp
    title: traits/reversed_monoid.cpp
  _extendedRequiredBy: []
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
    \       st.pop_back();\n    }\n};\n#line 2 \"traits/reversed_monoid.cpp\"\n\n\
    template <class M> struct ReversedMonoid {\n    using Type = typename M::Type;\n\
    \    static constexpr Type identity() { return M::identity(); }\n    static constexpr\
    \ Type operation(const Type& l, const Type& r) { return M::operation(r, l); }\n\
    };\n#line 4 \"container/queue_aggregation.cpp\"\n\ntemplate <class M> class QueueAggregation\
    \ {\n    using T = typename M::Type;\n    using R = ReversedMonoid<M>;\n\n   \
    \ StackAggregation<R> front_st;\n    StackAggregation<M> back_st;\n\n  public:\n\
    \    QueueAggregation() = default;\n\n    bool empty() const { return front_st.empty();\
    \ }\n    T fold() const { return M::operation(front_st.fold(), back_st.fold());\
    \ }\n\n    void push(const T& x) {\n        if (empty())\n            front_st.push(x);\n\
    \        else\n            back_st.push(x);\n    }\n    void pop() {\n       \
    \ assert(!empty());\n        front_st.pop();\n        if (front_st.empty()) {\n\
    \            while (!back_st.empty()) {\n                front_st.push(back_st.top());\n\
    \                back_st.pop();\n            }\n        }\n    }\n};\n"
  code: "#pragma once\n#include \"../container/stack_aggregation.cpp\"\n#include \"\
    ../traits/reversed_monoid.cpp\"\n\ntemplate <class M> class QueueAggregation {\n\
    \    using T = typename M::Type;\n    using R = ReversedMonoid<M>;\n\n    StackAggregation<R>\
    \ front_st;\n    StackAggregation<M> back_st;\n\n  public:\n    QueueAggregation()\
    \ = default;\n\n    bool empty() const { return front_st.empty(); }\n    T fold()\
    \ const { return M::operation(front_st.fold(), back_st.fold()); }\n\n    void\
    \ push(const T& x) {\n        if (empty())\n            front_st.push(x);\n  \
    \      else\n            back_st.push(x);\n    }\n    void pop() {\n        assert(!empty());\n\
    \        front_st.pop();\n        if (front_st.empty()) {\n            while (!back_st.empty())\
    \ {\n                front_st.push(back_st.top());\n                back_st.pop();\n\
    \            }\n        }\n    }\n};\n"
  dependsOn:
  - container/stack_aggregation.cpp
  - traits/reversed_monoid.cpp
  isVerificationFile: false
  path: container/queue_aggregation.cpp
  requiredBy: []
  timestamp: '2021-09-27 22:41:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/queue_aggregation.test.cpp
documentation_of: container/queue_aggregation.cpp
layout: document
redirect_from:
- /library/container/queue_aggregation.cpp
- /library/container/queue_aggregation.cpp.html
title: container/queue_aggregation.cpp
---
