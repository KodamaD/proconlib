---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/factorize.test.cpp
    title: test/factorize.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/factorize.cpp\"\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n\ntemplate <class T> std::vector<std::pair<T, int>> factorize(T\
    \ x) {\n    assert(x > 0);\n    std::vector<std::pair<T, int>> ret;\n    for (T\
    \ p = 2; p * p <= x; ++p) {\n        if (x % p == 0) {\n            int e = 0;\n\
    \            while (x % p == 0) {\n                x /= p;\n                e\
    \ += 1;\n            }\n            ret.emplace_back(p, e);\n        }\n    }\n\
    \    if (x > 1) ret.emplace_back(x, 1);\n    return ret;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    \ntemplate <class T> std::vector<std::pair<T, int>> factorize(T x) {\n    assert(x\
    \ > 0);\n    std::vector<std::pair<T, int>> ret;\n    for (T p = 2; p * p <= x;\
    \ ++p) {\n        if (x % p == 0) {\n            int e = 0;\n            while\
    \ (x % p == 0) {\n                x /= p;\n                e += 1;\n         \
    \   }\n            ret.emplace_back(p, e);\n        }\n    }\n    if (x > 1) ret.emplace_back(x,\
    \ 1);\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/factorize.cpp
  requiredBy: []
  timestamp: '2022-01-07 22:21:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/factorize.test.cpp
documentation_of: math/factorize.cpp
layout: document
redirect_from:
- /library/math/factorize.cpp
- /library/math/factorize.cpp.html
title: math/factorize.cpp
---
