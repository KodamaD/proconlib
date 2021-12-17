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
  bundledCode: "#line 2 \"utility/lowb.cpp\"\n#include <algorithm>\n#include <iterator>\n\
    #include <vector>\n\ntemplate <class T> int lowb(const std::vector<T>& vec, const\
    \ T& val) {\n    return std::distance(vec.cbegin(), std::lower_bound(vec.cbegin(),\
    \ vec.cend(), val));\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <iterator>\n#include <vector>\n\
    \ntemplate <class T> int lowb(const std::vector<T>& vec, const T& val) {\n   \
    \ return std::distance(vec.cbegin(), std::lower_bound(vec.cbegin(), vec.cend(),\
    \ val));\n}"
  dependsOn: []
  isVerificationFile: false
  path: utility/lowb.cpp
  requiredBy: []
  timestamp: '2021-12-17 09:20:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/lowb.cpp
layout: document
redirect_from:
- /library/utility/lowb.cpp
- /library/utility/lowb.cpp.html
title: utility/lowb.cpp
---
