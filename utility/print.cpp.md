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
  bundledCode: "#line 2 \"utility/print.cpp\"\n\n#include <iostream>\n#include <utility>\n\
    \ntemplate <class T>\nvoid print(T&& x) {\n    std::cout << x;\n}\n\ntemplate\
    \ <class T, class... Args>\nvoid print(T&& x, Args&&... args) {\n    std::cout\
    \ << x << ' ';\n    print(std::forward<Args>(args)...);\n}\n\nvoid println() {\n\
    \    std::cout << '\\n';\n}\n\ntemplate <class... Args>\nvoid println(Args&&...\
    \ args) {\n    print(std::forward<Args>(args)...);\n    std::cout << '\\n';\n\
    }\n\ntemplate <class C>\nvoid print_seq(C&& c, const char* sep = \" \", const\
    \ char* end = \"\\n\") {\n    bool f = false;\n    for (auto&& x : c) {\n    \
    \    if (f) {\n            std::cout << sep;\n        } else {\n            f\
    \ = true;\n        }\n        std::cout << x;\n    }\n    std::cout << end;\n\
    }\n"
  code: "#pragma once\n\n#include <iostream>\n#include <utility>\n\ntemplate <class\
    \ T>\nvoid print(T&& x) {\n    std::cout << x;\n}\n\ntemplate <class T, class...\
    \ Args>\nvoid print(T&& x, Args&&... args) {\n    std::cout << x << ' ';\n   \
    \ print(std::forward<Args>(args)...);\n}\n\nvoid println() {\n    std::cout <<\
    \ '\\n';\n}\n\ntemplate <class... Args>\nvoid println(Args&&... args) {\n    print(std::forward<Args>(args)...);\n\
    \    std::cout << '\\n';\n}\n\ntemplate <class C>\nvoid print_seq(C&& c, const\
    \ char* sep = \" \", const char* end = \"\\n\") {\n    bool f = false;\n    for\
    \ (auto&& x : c) {\n        if (f) {\n            std::cout << sep;\n        }\
    \ else {\n            f = true;\n        }\n        std::cout << x;\n    }\n \
    \   std::cout << end;\n}"
  dependsOn: []
  isVerificationFile: false
  path: utility/print.cpp
  requiredBy: []
  timestamp: '2022-09-27 19:53:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/print.cpp
layout: document
redirect_from:
- /library/utility/print.cpp
- /library/utility/print.cpp.html
title: utility/print.cpp
---
