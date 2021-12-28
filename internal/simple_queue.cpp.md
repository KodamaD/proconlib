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
  bundledCode: "#line 2 \"internal/simple_queue.cpp\"\n#include <vector>\n\nnamespace\
    \ proconlib {\n\ntemplate <class T> class SimpleQueue {\n    std::vector<T> payload;\n\
    \    int pos;\n\n  public:\n    SimpleQueue() : payload(), pos(0) {}\n    explicit\
    \ SimpleQueue(const int n) : SimpleQueue() { reserve(n); }\n\n    int size() const\
    \ { return (int)payload.size() - pos; }\n    bool empty() const { return size()\
    \ == 0; }\n    T& front() { return payload[pos]; }\n\n    void push(const T& t)\
    \ { payload.push_back(t); }\n    void push(T&& t) { payload.push_back(std::move(t));\
    \ }\n    void pop() { pos++; }\n\n    void reserve(int n) { payload.reserve(n);\
    \ }\n    void clear() {\n        payload.clear();\n        pos = 0;\n    }\n};\n\
    \n}  // namespace proconlib\n"
  code: "#pragma once\n#include <vector>\n\nnamespace proconlib {\n\ntemplate <class\
    \ T> class SimpleQueue {\n    std::vector<T> payload;\n    int pos;\n\n  public:\n\
    \    SimpleQueue() : payload(), pos(0) {}\n    explicit SimpleQueue(const int\
    \ n) : SimpleQueue() { reserve(n); }\n\n    int size() const { return (int)payload.size()\
    \ - pos; }\n    bool empty() const { return size() == 0; }\n    T& front() { return\
    \ payload[pos]; }\n\n    void push(const T& t) { payload.push_back(t); }\n   \
    \ void push(T&& t) { payload.push_back(std::move(t)); }\n    void pop() { pos++;\
    \ }\n\n    void reserve(int n) { payload.reserve(n); }\n    void clear() {\n \
    \       payload.clear();\n        pos = 0;\n    }\n};\n\n}  // namespace proconlib\n"
  dependsOn: []
  isVerificationFile: false
  path: internal/simple_queue.cpp
  requiredBy: []
  timestamp: '2021-12-28 21:38:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: internal/simple_queue.cpp
layout: document
redirect_from:
- /library/internal/simple_queue.cpp
- /library/internal/simple_queue.cpp.html
title: internal/simple_queue.cpp
---
