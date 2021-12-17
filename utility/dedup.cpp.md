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
  bundledCode: "#line 2 \"utility/dedup.cpp\"\n#include <algorithm>\n#include <vector>\n\
    \ntemplate <class T> int dedup(std::vector<T>& vec) {\n    std::sort(vec.begin(),\
    \ vec.end());\n    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());\n\
    \    return vec.size();\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\ntemplate <class\
    \ T> int dedup(std::vector<T>& vec) {\n    std::sort(vec.begin(), vec.end());\n\
    \    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());\n    return vec.size();\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: utility/dedup.cpp
  requiredBy: []
  timestamp: '2021-12-17 09:20:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/dedup.cpp
layout: document
redirect_from:
- /library/utility/dedup.cpp
- /library/utility/dedup.cpp.html
title: utility/dedup.cpp
---
