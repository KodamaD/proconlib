---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/berlekamp_massey.test.cpp
    title: test/berlekamp_massey.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algorithm/berlekamp_massey.cpp\"\n#include <vector>\n#line\
    \ 2 \"utility/rep.cpp\"\n#include <algorithm>\n\nclass Range {\n    struct Iter\
    \ {\n        int itr;\n        constexpr Iter(const int pos) noexcept : itr(pos)\
    \ {}\n        constexpr void operator++() noexcept { ++itr; }\n        constexpr\
    \ bool operator!=(const Iter& other) const noexcept { return itr != other.itr;\
    \ }\n        constexpr int operator*() const noexcept { return itr; }\n    };\n\
    \    const Iter first, last;\n\n  public:\n    explicit constexpr Range(const\
    \ int first, const int last) noexcept : first(first), last(std::max(first, last))\
    \ {}\n    constexpr Iter begin() const noexcept { return first; }\n    constexpr\
    \ Iter end() const noexcept { return last; }\n};\n\nconstexpr Range rep(const\
    \ int l, const int r) noexcept { return Range(l, r); }\nconstexpr Range rep(const\
    \ int n) noexcept { return Range(0, n); }\n#line 4 \"algorithm/berlekamp_massey.cpp\"\
    \n\ntemplate <class T> std::vector<T> berlekamp_massey(const std::vector<T>& a)\
    \ {\n    const int n = a.size();\n    std::vector<T> c = {T(-1)}, c2 = {T(0)};\n\
    \    T r2 = 1;\n    int i2 = 0;\n    for (const int i : rep(n)) {\n        T r\
    \ = 0;\n        const int d = c.size();\n        for (const int j : rep(d)) r\
    \ += c[j] * a[i - j];\n        if (r == T(0)) continue;\n        T coeff = -r\
    \ / r2;\n        const int d2 = c2.size(), shift = i - i2 + 1;\n        if (d2\
    \ + shift <= d) {\n            for (const int j : rep(d2)) c[j + shift] += c2[j]\
    \ * coeff;\n        } else {\n            std::vector<T> tmp = c;\n          \
    \  c.resize(d2 + shift);\n            for (const int j : rep(d2)) c[j + shift]\
    \ += c2[j] * coeff;\n            c2 = std::move(tmp);\n            i2 = i + 1;\n\
    \            r2 = r;\n        }\n    }\n    c.erase(c.begin());\n    return c;\n\
    }\n"
  code: "#pragma once\n#include <vector>\n#include \"../utility/rep.cpp\"\n\ntemplate\
    \ <class T> std::vector<T> berlekamp_massey(const std::vector<T>& a) {\n    const\
    \ int n = a.size();\n    std::vector<T> c = {T(-1)}, c2 = {T(0)};\n    T r2 =\
    \ 1;\n    int i2 = 0;\n    for (const int i : rep(n)) {\n        T r = 0;\n  \
    \      const int d = c.size();\n        for (const int j : rep(d)) r += c[j] *\
    \ a[i - j];\n        if (r == T(0)) continue;\n        T coeff = -r / r2;\n  \
    \      const int d2 = c2.size(), shift = i - i2 + 1;\n        if (d2 + shift <=\
    \ d) {\n            for (const int j : rep(d2)) c[j + shift] += c2[j] * coeff;\n\
    \        } else {\n            std::vector<T> tmp = c;\n            c.resize(d2\
    \ + shift);\n            for (const int j : rep(d2)) c[j + shift] += c2[j] * coeff;\n\
    \            c2 = std::move(tmp);\n            i2 = i + 1;\n            r2 = r;\n\
    \        }\n    }\n    c.erase(c.begin());\n    return c;\n}"
  dependsOn:
  - utility/rep.cpp
  isVerificationFile: false
  path: algorithm/berlekamp_massey.cpp
  requiredBy: []
  timestamp: '2021-12-28 21:38:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/berlekamp_massey.test.cpp
documentation_of: algorithm/berlekamp_massey.cpp
layout: document
redirect_from:
- /library/algorithm/berlekamp_massey.cpp
- /library/algorithm/berlekamp_massey.cpp.html
title: algorithm/berlekamp_massey.cpp
---
