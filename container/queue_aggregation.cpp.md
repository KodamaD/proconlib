---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../utility/reversed_monoid.cpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"../container/stack_aggregation.cpp\"\n#include \"\
    ../utility/reversed_monoid.cpp\"\n\ntemplate <class M> class QueueAggregation\
    \ {\n    using T = typename M::Type;\n    using R = ReversedMonoid<M>;\n\n   \
    \ StackAggregation<R> front_st;\n    StackAggregation<M> back_st;\n\n  public:\n\
    \    QueueAggregation() = default;\n\n    bool empty() const { return front_st.empty();\
    \ }\n    T fold() const { return M::operation(front_st.fold(), back_st.fold());\
    \ }\n\n    void push(const T& x) {\n        if (empty())\n            front_st.push(x);\n\
    \        else\n            back_st.push(x);\n    }\n    void pop() {\n       \
    \ assert(!empty());\n        front_st.pop();\n        if (front_st.empty()) {\n\
    \            while (!back_st.empty()) {\n                front_st.push(back_st.top());\n\
    \                back_st.pop();\n            }\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: container/queue_aggregation.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: container/queue_aggregation.cpp
layout: document
redirect_from:
- /library/container/queue_aggregation.cpp
- /library/container/queue_aggregation.cpp.html
title: container/queue_aggregation.cpp
---
