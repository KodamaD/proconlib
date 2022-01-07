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
  bundledCode: "#line 2 \"utility/collect.cpp\"\n#include <vector>\n\ntemplate <class\
    \ Cont> decltype(auto) collect(const Cont& c) {\n    std::vector<decltype(*std::declval<Cont>().begin())>\
    \ ret;\n    for (const auto& x : c) ret.push_back(x);\n    return ret;\n}\n\n\
    template <class Cont> decltype(auto) collect(Cont&& c) {\n    std::vector<decltype(*std::declval<Cont>().begin())>\
    \ ret;\n    for (auto&& x : c) ret.push_back(std::move(x));\n    return ret;\n\
    }\n"
  code: "#pragma once\n#include <vector>\n\ntemplate <class Cont> decltype(auto) collect(const\
    \ Cont& c) {\n    std::vector<decltype(*std::declval<Cont>().begin())> ret;\n\
    \    for (const auto& x : c) ret.push_back(x);\n    return ret;\n}\n\ntemplate\
    \ <class Cont> decltype(auto) collect(Cont&& c) {\n    std::vector<decltype(*std::declval<Cont>().begin())>\
    \ ret;\n    for (auto&& x : c) ret.push_back(std::move(x));\n    return ret;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: utility/collect.cpp
  requiredBy: []
  timestamp: '2021-12-28 22:38:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/collect.cpp
layout: document
redirect_from:
- /library/utility/collect.cpp
- /library/utility/collect.cpp.html
title: utility/collect.cpp
---
