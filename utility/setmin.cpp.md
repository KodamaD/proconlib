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
  bundledCode: "#line 2 \"utility/setmin.cpp\"\n\ntemplate <class T>\nbool setmin(T&\
    \ lhs, const T& rhs) {\n    if (lhs > rhs) {\n        lhs = rhs;\n        return\
    \ true;\n    }\n    return false;\n}\n"
  code: "#pragma once\n\ntemplate <class T>\nbool setmin(T& lhs, const T& rhs) {\n\
    \    if (lhs > rhs) {\n        lhs = rhs;\n        return true;\n    }\n    return\
    \ false;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: utility/setmin.cpp
  requiredBy: []
  timestamp: '2021-03-25 15:37:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/setmin.cpp
layout: document
redirect_from:
- /library/utility/setmin.cpp
- /library/utility/setmin.cpp.html
title: utility/setmin.cpp
---
