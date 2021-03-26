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
  bundledCode: "#line 2 \"math/divisors.cpp\"\n#include <vector>\n#include <algorithm>\n\
    #include <iterator>\n\ntemplate <class T>\nstd::vector<T> divisors(const T& x)\
    \ {\n    std::vector<T> small, big;\n    for (T i = 1; i * i <= x; ++i) {\n  \
    \      if (x % i == 0) {\n            small.push_back(i);\n            if (i *\
    \ i != x) {\n                big.push_back(x / i);\n            }\n        }\n\
    \    }\n    small.reserve(small.size() + big.size());\n    std::copy(big.rbegin(),\
    \ big.rend(), std::back_inserter(small));\n    return small;\n}\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\n#include <iterator>\n\
    \ntemplate <class T>\nstd::vector<T> divisors(const T& x) {\n    std::vector<T>\
    \ small, big;\n    for (T i = 1; i * i <= x; ++i) {\n        if (x % i == 0) {\n\
    \            small.push_back(i);\n            if (i * i != x) {\n            \
    \    big.push_back(x / i);\n            }\n        }\n    }\n    small.reserve(small.size()\
    \ + big.size());\n    std::copy(big.rbegin(), big.rend(), std::back_inserter(small));\n\
    \    return small;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/divisors.cpp
  requiredBy: []
  timestamp: '2021-03-26 16:54:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/divisors.cpp
layout: document
redirect_from:
- /library/math/divisors.cpp
- /library/math/divisors.cpp.html
title: math/divisors.cpp
---
