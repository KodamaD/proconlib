---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: container/stack_aggregation.cpp
    title: container/stack_aggregation.cpp
  - icon: ':heavy_check_mark:'
    path: utility/reversed_monoid.cpp
    title: utility/reversed_monoid.cpp
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
  bundledCode: "#line 2 \"container/stack_aggregation.cpp\"\n#include <vector>\n#include\
    \ <cassert>\n\ntemplate <class Monoid> class StackAggregation {\n    using M =\
    \ Monoid;\n\n    struct Node {\n        M value, fold;\n        explicit Node(const\
    \ M value, const M fold) : value(value), fold(fold) {}\n    };\n\n    std::vector<Node>\
    \ st;\n\n  public:\n    StackAggregation() = default;\n\n    bool empty() const\
    \ { return st.empty(); }\n    M top() const {\n        assert(!empty());\n   \
    \     return st.back().value;\n    }\n    M fold() const { return st.empty() ?\
    \ M::zero() : st.back().fold; }\n\n    void push(const M& x) { st.emplace_back(x,\
    \ fold() + x); }\n    void pop() {\n        assert(!empty());\n        st.pop_back();\n\
    \    }\n};\n#line 2 \"utility/reversed_monoid.cpp\"\n\ntemplate <class Monoid>\
    \ struct ReversedMonoid {\n    using M = Monoid;\n    using Self = ReversedMonoid;\n\
    \    M raw;\n    constexpr ReversedMonoid(const M& m): raw(m) {}\n    static constexpr\
    \ Self zero() { return Self(M::zero()); }\n    constexpr Self operator+(const\
    \ Self& other) const { return other.raw + raw; }\n};\n#line 4 \"container/queue_aggregation.cpp\"\
    \n\ntemplate <class Monoid> class QueueAggregation {\n    using M = Monoid;\n\n\
    \    StackAggregation<ReversedMonoid<M>> front_st;\n    StackAggregation<M> back_st;\n\
    \n  public:\n    QueueAggregation() = default;\n\n    bool empty() const { return\
    \ front_st.empty(); }\n    M fold() const { return front_st.fold().raw + back_st.fold();\
    \ }\n\n    void push(const M& x) {\n        if (empty())\n            front_st.push(x);\n\
    \        else\n            back_st.push(x);\n    }\n    void pop() {\n       \
    \ assert(!empty());\n        front_st.pop();\n        if (front_st.empty()) {\n\
    \            while (!back_st.empty()) {\n                front_st.push(back_st.top());\n\
    \                back_st.pop();\n            }\n        }\n    }\n};\n"
  code: "#pragma once\n#include \"../container/stack_aggregation.cpp\"\n#include \"\
    ../utility/reversed_monoid.cpp\"\n\ntemplate <class Monoid> class QueueAggregation\
    \ {\n    using M = Monoid;\n\n    StackAggregation<ReversedMonoid<M>> front_st;\n\
    \    StackAggregation<M> back_st;\n\n  public:\n    QueueAggregation() = default;\n\
    \n    bool empty() const { return front_st.empty(); }\n    M fold() const { return\
    \ front_st.fold().raw + back_st.fold(); }\n\n    void push(const M& x) {\n   \
    \     if (empty())\n            front_st.push(x);\n        else\n            back_st.push(x);\n\
    \    }\n    void pop() {\n        assert(!empty());\n        front_st.pop();\n\
    \        if (front_st.empty()) {\n            while (!back_st.empty()) {\n   \
    \             front_st.push(back_st.top());\n                back_st.pop();\n\
    \            }\n        }\n    }\n};\n"
  dependsOn:
  - container/stack_aggregation.cpp
  - utility/reversed_monoid.cpp
  isVerificationFile: false
  path: container/queue_aggregation.cpp
  requiredBy: []
  timestamp: '2021-09-04 18:33:40+09:00'
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
