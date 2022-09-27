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
  bundledCode: "#line 2 \"utility/scan.cpp\"\n#include <array>\n#include <cassert>\n\
    #include <iostream>\n#include <iterator>\n#include <string>\n#include <vector>\n\
    \ntemplate <class T>\nT scan() {\n    T x;\n    std::cin >> x;\n    return x;\n\
    }\n\ntemplate <class T>\nstd::vector<T> scan_vec(int n = -1) {\n    if (n == -1)\n\
    \        std::cin >> n;\n    assert(n >= 0);\n    std::vector<T> v(n);\n    for\
    \ (auto& x : v)\n        std::cin >> x;\n    return v;\n}\n\ntemplate <class T,\
    \ int N>\nstd::array<T, N> scan_array() {\n    std::array<T, N> a;\n    for (auto&\
    \ x : a)\n        std::cin >> x;\n    return a;\n}\n\nstd::vector<char> scan_chars()\
    \ {\n    std::string s;\n    std::cin >> s;\n    return std::vector<char>(std::cbegin(s),\
    \ std::cend(s));\n}\n"
  code: "#pragma once\n#include <array>\n#include <cassert>\n#include <iostream>\n\
    #include <iterator>\n#include <string>\n#include <vector>\n\ntemplate <class T>\n\
    T scan() {\n    T x;\n    std::cin >> x;\n    return x;\n}\n\ntemplate <class\
    \ T>\nstd::vector<T> scan_vec(int n = -1) {\n    if (n == -1)\n        std::cin\
    \ >> n;\n    assert(n >= 0);\n    std::vector<T> v(n);\n    for (auto& x : v)\n\
    \        std::cin >> x;\n    return v;\n}\n\ntemplate <class T, int N>\nstd::array<T,\
    \ N> scan_array() {\n    std::array<T, N> a;\n    for (auto& x : a)\n        std::cin\
    \ >> x;\n    return a;\n}\n\nstd::vector<char> scan_chars() {\n    std::string\
    \ s;\n    std::cin >> s;\n    return std::vector<char>(std::cbegin(s), std::cend(s));\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: utility/scan.cpp
  requiredBy: []
  timestamp: '2022-09-27 19:53:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/scan.cpp
layout: document
redirect_from:
- /library/utility/scan.cpp
- /library/utility/scan.cpp.html
title: utility/scan.cpp
---
