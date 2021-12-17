---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algorithm/or_convolution.cpp
    title: algorithm/or_convolution.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algorithm/subset_zeta_transform.cpp\"\n#include <vector>\n\
    #include <cassert>\n#line 2 \"utility/rep.cpp\"\n#include <algorithm>\n\nclass\
    \ Range {\n    struct Iter {\n        int itr;\n        constexpr Iter(const int\
    \ pos) noexcept : itr(pos) {}\n        constexpr void operator++() noexcept {\
    \ ++itr; }\n        constexpr bool operator!=(const Iter& other) const noexcept\
    \ { return itr != other.itr; }\n        constexpr int operator*() const noexcept\
    \ { return itr; }\n    };\n    const Iter first, last;\n\n  public:\n    explicit\
    \ constexpr Range(const int first, const int last) noexcept : first(first), last(std::max(first,\
    \ last)) {}\n    constexpr Iter begin() const noexcept { return first; }\n   \
    \ constexpr Iter end() const noexcept { return last; }\n};\n\nconstexpr Range\
    \ rep(const int l, const int r) noexcept { return Range(l, r); }\nconstexpr Range\
    \ rep(const int n) noexcept { return Range(0, n); }\n#line 5 \"algorithm/subset_zeta_transform.cpp\"\
    \n\ntemplate <class T> void subset_zeta_transform(std::vector<T>& f) {\n    const\
    \ int n = f.size();\n    assert((n & (n - 1)) == 0);\n    for (int i = 1; i <\
    \ n; i <<= 1) {\n        for (const int j : rep(0, n)) {\n            if (j &\
    \ i) f[j] += f[j & ~i];\n        }\n    }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\n#include \"../utility/rep.cpp\"\
    \n\ntemplate <class T> void subset_zeta_transform(std::vector<T>& f) {\n    const\
    \ int n = f.size();\n    assert((n & (n - 1)) == 0);\n    for (int i = 1; i <\
    \ n; i <<= 1) {\n        for (const int j : rep(0, n)) {\n            if (j &\
    \ i) f[j] += f[j & ~i];\n        }\n    }\n}\n"
  dependsOn:
  - utility/rep.cpp
  isVerificationFile: false
  path: algorithm/subset_zeta_transform.cpp
  requiredBy:
  - algorithm/or_convolution.cpp
  timestamp: '2021-12-17 09:20:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/subset_zeta_transform.cpp
layout: document
redirect_from:
- /library/algorithm/subset_zeta_transform.cpp
- /library/algorithm/subset_zeta_transform.cpp.html
title: algorithm/subset_zeta_transform.cpp
---
