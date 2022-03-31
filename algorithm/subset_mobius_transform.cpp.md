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
  bundledCode: "#line 2 \"algorithm/subset_mobius_transform.cpp\"\n#include <cassert>\n\
    #include <vector>\n#line 2 \"utility/rep.cpp\"\n#include <algorithm>\n\nclass\
    \ Range {\n    struct Iter {\n        int itr;\n        constexpr Iter(const int\
    \ pos) noexcept : itr(pos) {}\n        constexpr void operator++() noexcept {\
    \ ++itr; }\n        constexpr bool operator!=(const Iter& other) const noexcept\
    \ { return itr != other.itr; }\n        constexpr int operator*() const noexcept\
    \ { return itr; }\n    };\n    const Iter first, last;\n\n  public:\n    explicit\
    \ constexpr Range(const int first, const int last) noexcept : first(first), last(std::max(first,\
    \ last)) {}\n    constexpr Iter begin() const noexcept { return first; }\n   \
    \ constexpr Iter end() const noexcept { return last; }\n};\n\nconstexpr Range\
    \ rep(const int l, const int r) noexcept { return Range(l, r); }\nconstexpr Range\
    \ rep(const int n) noexcept { return Range(0, n); }\n#line 5 \"algorithm/subset_mobius_transform.cpp\"\
    \n\ntemplate <class G> void subset_mobius_transform(std::vector<typename G::Type>&\
    \ f) {\n    const int n = f.size();\n    assert((n & (n - 1)) == 0);\n    for\
    \ (int i = n; i >>= 1;)\n        for (const int j : rep(n))\n            if (j\
    \ & i) f[j] = G::operation(G::inverse(f[j & ~i]), f[j]);\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n#include \"../utility/rep.cpp\"\
    \n\ntemplate <class G> void subset_mobius_transform(std::vector<typename G::Type>&\
    \ f) {\n    const int n = f.size();\n    assert((n & (n - 1)) == 0);\n    for\
    \ (int i = n; i >>= 1;)\n        for (const int j : rep(n))\n            if (j\
    \ & i) f[j] = G::operation(G::inverse(f[j & ~i]), f[j]);\n}\n"
  dependsOn:
  - utility/rep.cpp
  isVerificationFile: false
  path: algorithm/subset_mobius_transform.cpp
  requiredBy:
  - algorithm/or_convolution.cpp
  timestamp: '2021-12-28 21:38:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/subset_mobius_transform.cpp
layout: document
redirect_from:
- /library/algorithm/subset_mobius_transform.cpp
- /library/algorithm/subset_mobius_transform.cpp.html
title: algorithm/subset_mobius_transform.cpp
---