---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/superset_mobius_transform.cpp
    title: algorithm/superset_mobius_transform.cpp
  - icon: ':heavy_check_mark:'
    path: algorithm/superset_zeta_transform.cpp
    title: algorithm/superset_zeta_transform.cpp
  - icon: ':question:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/and_convolution.test.cpp
    title: test/and_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algorithm/and_convolution.cpp\"\n#include <vector>\n#include\
    \ <cassert>\n#line 2 \"utility/rep.cpp\"\n#include <algorithm>\n\nclass Range\
    \ {\n    struct Iter {\n        int itr;\n        constexpr Iter(const int pos)\
    \ noexcept : itr(pos) {}\n        constexpr void operator++() noexcept { ++itr;\
    \ }\n        constexpr bool operator!=(const Iter& other) const noexcept { return\
    \ itr != other.itr; }\n        constexpr int operator*() const noexcept { return\
    \ itr; }\n    };\n    const Iter first, last;\n\n  public:\n    explicit constexpr\
    \ Range(const int first, const int last) noexcept : first(first), last(std::max(first,\
    \ last)) {}\n    constexpr Iter begin() const noexcept { return first; }\n   \
    \ constexpr Iter end() const noexcept { return last; }\n};\n\nconstexpr Range\
    \ rep(const int l, const int r) noexcept { return Range(l, r); }\nconstexpr Range\
    \ rep(const int n) noexcept { return Range(0, n); }\n#line 5 \"algorithm/superset_zeta_transform.cpp\"\
    \n\ntemplate <class T> void superset_zeta_transform(std::vector<T>& f) {\n   \
    \ const int n = f.size();\n    assert((n & (n - 1)) == 0);\n    for (int i = 1;\
    \ i < n; i <<= 1) {\n        for (const int j : rep(0, n)) {\n            if (j\
    \ & i) f[j & ~i] += f[j];\n        }\n    }\n}\n#line 5 \"algorithm/superset_mobius_transform.cpp\"\
    \n\ntemplate <class T> void superset_mobius_transform(std::vector<T>& f) {\n \
    \   const int n = f.size();\n    assert((n & (n - 1)) == 0);\n    for (int i =\
    \ n; i >>= 1;) {\n        for (const int j : rep(0, n)) {\n            if (j &\
    \ i) f[j & ~i] -= f[j];\n        }\n    }\n}\n#line 7 \"algorithm/and_convolution.cpp\"\
    \n\ntemplate <class T> std::vector<T> and_convolution(std::vector<T> a, std::vector<T>\
    \ b) {\n    assert(a.size() == b.size());\n    superset_zeta_transform(a);\n \
    \   superset_zeta_transform(b);\n    for (const int i : rep(0, a.size())) a[i]\
    \ *= b[i];\n    superset_mobius_transform(a);\n    return a;\n}\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\n#include \"../utility/rep.cpp\"\
    \n#include \"superset_zeta_transform.cpp\"\n#include \"superset_mobius_transform.cpp\"\
    \n\ntemplate <class T> std::vector<T> and_convolution(std::vector<T> a, std::vector<T>\
    \ b) {\n    assert(a.size() == b.size());\n    superset_zeta_transform(a);\n \
    \   superset_zeta_transform(b);\n    for (const int i : rep(0, a.size())) a[i]\
    \ *= b[i];\n    superset_mobius_transform(a);\n    return a;\n}\n"
  dependsOn:
  - utility/rep.cpp
  - algorithm/superset_zeta_transform.cpp
  - algorithm/superset_mobius_transform.cpp
  isVerificationFile: false
  path: algorithm/and_convolution.cpp
  requiredBy: []
  timestamp: '2021-12-17 09:20:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/and_convolution.test.cpp
documentation_of: algorithm/and_convolution.cpp
layout: document
redirect_from:
- /library/algorithm/and_convolution.cpp
- /library/algorithm/and_convolution.cpp.html
title: algorithm/and_convolution.cpp
---
