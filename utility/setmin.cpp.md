---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/primal_dual.cpp
    title: graph/primal_dual.cpp
  - icon: ':x:'
    path: graph/strongly_connected_components.cpp
    title: graph/strongly_connected_components.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/primal_dual_maxflow.test.cpp
    title: test/primal_dual_maxflow.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/primal_dual_mincostflow.test.cpp
    title: test/primal_dual_mincostflow.test.cpp
  - icon: ':x:'
    path: test/strongly_connected_components.test.cpp
    title: test/strongly_connected_components.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/setmin.cpp\"\n\ntemplate <class T> bool setmin(T&\
    \ lhs, const T& rhs) {\n    if (lhs > rhs) {\n        lhs = rhs;\n        return\
    \ true;\n    }\n    return false;\n}\n"
  code: "#pragma once\n\ntemplate <class T> bool setmin(T& lhs, const T& rhs) {\n\
    \    if (lhs > rhs) {\n        lhs = rhs;\n        return true;\n    }\n    return\
    \ false;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: utility/setmin.cpp
  requiredBy:
  - graph/strongly_connected_components.cpp
  - graph/primal_dual.cpp
  timestamp: '2021-09-04 17:30:23+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/strongly_connected_components.test.cpp
  - test/primal_dual_mincostflow.test.cpp
  - test/primal_dual_maxflow.test.cpp
documentation_of: utility/setmin.cpp
layout: document
redirect_from:
- /library/utility/setmin.cpp
- /library/utility/setmin.cpp.html
title: utility/setmin.cpp
---
