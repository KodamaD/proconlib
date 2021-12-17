---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/z_algorithm.test.cpp
    title: test/z_algorithm.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algorithm/z_algorithm.cpp\"\n#include <vector>\n\ntemplate\
    \ <class Cont> std::vector<int> z_algorithm(const Cont& c) {\n    const int size\
    \ = c.size();\n    std::vector<int> ret(size);\n    ret[0] = size;\n    int i\
    \ = 1, j = 0;\n    while (i < size) {\n        while (i + j < size && c[i + j]\
    \ == c[j]) j += 1;\n        ret[i] = j;\n        if (j == 0) {\n            i\
    \ += 1;\n            continue;\n        }\n        int k = 1;\n        while (i\
    \ + k < size && k + ret[k] < j) {\n            ret[i + k] = ret[k];\n        \
    \    k += 1;\n        }\n        i += k;\n        j -= k;\n    }\n    return ret;\n\
    }\n"
  code: "#pragma once\n#include <vector>\n\ntemplate <class Cont> std::vector<int>\
    \ z_algorithm(const Cont& c) {\n    const int size = c.size();\n    std::vector<int>\
    \ ret(size);\n    ret[0] = size;\n    int i = 1, j = 0;\n    while (i < size)\
    \ {\n        while (i + j < size && c[i + j] == c[j]) j += 1;\n        ret[i]\
    \ = j;\n        if (j == 0) {\n            i += 1;\n            continue;\n  \
    \      }\n        int k = 1;\n        while (i + k < size && k + ret[k] < j) {\n\
    \            ret[i + k] = ret[k];\n            k += 1;\n        }\n        i +=\
    \ k;\n        j -= k;\n    }\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/z_algorithm.cpp
  requiredBy: []
  timestamp: '2021-12-17 09:20:39+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/z_algorithm.test.cpp
documentation_of: algorithm/z_algorithm.cpp
layout: document
redirect_from:
- /library/algorithm/z_algorithm.cpp
- /library/algorithm/z_algorithm.cpp.html
title: algorithm/z_algorithm.cpp
---
