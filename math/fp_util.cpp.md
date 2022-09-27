---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/fp_util.test.cpp
    title: test/fp_util.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/fp_util.cpp\"\n#include <cassert>\n#include <vector>\n\
    \ntemplate <class M> struct FpUtil {\n    static M fact(const int n) {\n     \
    \   static std::vector<M> vec;\n        assert(n >= 0);\n        if (vec.empty())\
    \ vec = {M(1)};\n        for (int i = vec.size(); i <= n; ++i) vec.push_back(vec.back()\
    \ * M(i));\n        return vec[n];\n    }\n    static M inv(const int n) {\n \
    \       static std::vector<M> vec;\n        assert(n > 0);\n        if (vec.empty())\
    \ vec = {M(0), M(1)};\n        for (int i = vec.size(); i <= n; ++i) vec.push_back(-M(M::mod()\
    \ / i) * vec[M::mod() % i]);\n        return vec[n];\n    }\n    static M inv_fact(const\
    \ int n) {\n        static std::vector<M> vec;\n        assert(n >= 0);\n    \
    \    if (vec.empty()) vec = {M(1)};\n        for (int i = vec.size(); i <= n;\
    \ ++i) vec.push_back(vec.back() * inv(i));\n        return vec[n];\n    }\n  \
    \  static M binom(const int n, const int k) {\n        assert(0 <= k and k <=\
    \ n);\n        return fact(n) * inv_fact(n - k) * inv_fact(k);\n    }\n    static\
    \ M factpow(const int n, const int k) {\n        assert(0 <= k and k <= n);\n\
    \        return fact(n) * inv_fact(n - k);\n    }\n    static M homo(const int\
    \ n, const int k) {\n        assert((n == 0 and k == 0) or (n > 0 and k >= 0));\n\
    \        if (n == 0 and k == 0) return M(1);\n        return binom(n + k - 1,\
    \ k);\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\ntemplate <class M>\
    \ struct FpUtil {\n    static M fact(const int n) {\n        static std::vector<M>\
    \ vec;\n        assert(n >= 0);\n        if (vec.empty()) vec = {M(1)};\n    \
    \    for (int i = vec.size(); i <= n; ++i) vec.push_back(vec.back() * M(i));\n\
    \        return vec[n];\n    }\n    static M inv(const int n) {\n        static\
    \ std::vector<M> vec;\n        assert(n > 0);\n        if (vec.empty()) vec =\
    \ {M(0), M(1)};\n        for (int i = vec.size(); i <= n; ++i) vec.push_back(-M(M::mod()\
    \ / i) * vec[M::mod() % i]);\n        return vec[n];\n    }\n    static M inv_fact(const\
    \ int n) {\n        static std::vector<M> vec;\n        assert(n >= 0);\n    \
    \    if (vec.empty()) vec = {M(1)};\n        for (int i = vec.size(); i <= n;\
    \ ++i) vec.push_back(vec.back() * inv(i));\n        return vec[n];\n    }\n  \
    \  static M binom(const int n, const int k) {\n        assert(0 <= k and k <=\
    \ n);\n        return fact(n) * inv_fact(n - k) * inv_fact(k);\n    }\n    static\
    \ M factpow(const int n, const int k) {\n        assert(0 <= k and k <= n);\n\
    \        return fact(n) * inv_fact(n - k);\n    }\n    static M homo(const int\
    \ n, const int k) {\n        assert((n == 0 and k == 0) or (n > 0 and k >= 0));\n\
    \        if (n == 0 and k == 0) return M(1);\n        return binom(n + k - 1,\
    \ k);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/fp_util.cpp
  requiredBy: []
  timestamp: '2021-12-17 21:33:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/fp_util.test.cpp
documentation_of: math/fp_util.cpp
layout: document
redirect_from:
- /library/math/fp_util.cpp
- /library/math/fp_util.cpp.html
title: math/fp_util.cpp
---