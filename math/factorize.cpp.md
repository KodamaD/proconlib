---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: utility/collect.cpp
    title: utility/collect.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/factorize.test.cpp
    title: test/factorize.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/factorize.cpp\"\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n#line 3 \"utility/collect.cpp\"\n\ntemplate <class Cont> decltype(auto)\
    \ collect(const Cont& c) {\n    std::vector<decltype(*std::declval<Cont>().begin())>\
    \ ret;\n    for (const auto& x : c) ret.push_back(x);\n    return ret;\n}\n\n\
    template <class Cont> decltype(auto) collect(Cont&& c) {\n    std::vector<decltype(*std::declval<Cont>().begin())>\
    \ ret;\n    for (auto&& x : c) ret.push_back(std::move(x));\n    return ret;\n\
    }\n#line 6 \"math/factorize.cpp\"\n\ntemplate <class T> std::vector<std::pair<T,\
    \ int>> factorize(const T& x) {\n    assert(x > 0);\n    std::vector<std::pair<T,\
    \ int>> ret;\n    for (T p = 2; p * p <= x; ++p) {\n        if (x % p == 0) {\n\
    \            int e = 0;\n            while (x % p == 0) {\n                x /=\
    \ p;\n                e += 1;\n            }\n            ret.emplace_back(p,\
    \ e);\n        }\n    }\n    if (x > 1) ret.emplace_back(x, 1);\n    return ret;\n\
    }\n"
  code: "#pragma once\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    #include \"../utility/collect.cpp\"\n\ntemplate <class T> std::vector<std::pair<T,\
    \ int>> factorize(const T& x) {\n    assert(x > 0);\n    std::vector<std::pair<T,\
    \ int>> ret;\n    for (T p = 2; p * p <= x; ++p) {\n        if (x % p == 0) {\n\
    \            int e = 0;\n            while (x % p == 0) {\n                x /=\
    \ p;\n                e += 1;\n            }\n            ret.emplace_back(p,\
    \ e);\n        }\n    }\n    if (x > 1) ret.emplace_back(x, 1);\n    return ret;\n\
    }\n"
  dependsOn:
  - utility/collect.cpp
  isVerificationFile: false
  path: math/factorize.cpp
  requiredBy: []
  timestamp: '2022-01-07 21:48:21+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/factorize.test.cpp
documentation_of: math/factorize.cpp
layout: document
redirect_from:
- /library/math/factorize.cpp
- /library/math/factorize.cpp.html
title: math/factorize.cpp
---
