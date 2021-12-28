---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: algorithm/subset_mobius_transform.cpp
    title: algorithm/subset_mobius_transform.cpp
  - icon: ':warning:'
    path: algorithm/subset_zeta_transform.cpp
    title: algorithm/subset_zeta_transform.cpp
  - icon: ':heavy_check_mark:'
    path: traits/sum_group.cpp
    title: traits/sum_group.cpp
  - icon: ':question:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algorithm/or_convolution.cpp\"\n#include <cassert>\n#include\
    \ <vector>\n#line 2 \"traits/sum_group.cpp\"\n\ntemplate <class T> struct SumGroup\
    \ {\n    using Type = T;\n    static constexpr T identity() { return T(0); }\n\
    \    static constexpr T operation(const T& l, const T& r) { return l + r; }\n\
    \    static constexpr T inverse(const T& x) { return -x; }\n};\n#line 2 \"utility/rep.cpp\"\
    \n#include <algorithm>\n\nclass Range {\n    struct Iter {\n        int itr;\n\
    \        constexpr Iter(const int pos) noexcept : itr(pos) {}\n        constexpr\
    \ void operator++() noexcept { ++itr; }\n        constexpr bool operator!=(const\
    \ Iter& other) const noexcept { return itr != other.itr; }\n        constexpr\
    \ int operator*() const noexcept { return itr; }\n    };\n    const Iter first,\
    \ last;\n\n  public:\n    explicit constexpr Range(const int first, const int\
    \ last) noexcept : first(first), last(std::max(first, last)) {}\n    constexpr\
    \ Iter begin() const noexcept { return first; }\n    constexpr Iter end() const\
    \ noexcept { return last; }\n};\n\nconstexpr Range rep(const int l, const int\
    \ r) noexcept { return Range(l, r); }\nconstexpr Range rep(const int n) noexcept\
    \ { return Range(0, n); }\n#line 5 \"algorithm/subset_mobius_transform.cpp\"\n\
    \ntemplate <class G> void subset_mobius_transform(std::vector<typename G::Type>&\
    \ f) {\n    const int n = f.size();\n    assert((n & (n - 1)) == 0);\n    for\
    \ (int i = n; i >>= 1;)\n        for (const int j : rep(n))\n            if (j\
    \ & i) f[j] = G::operation(G::inverse(f[j & ~i]), f[j]);\n}\n#line 5 \"algorithm/subset_zeta_transform.cpp\"\
    \n\ntemplate <class S> void subset_zeta_transform(std::vector<typename S::Type>&\
    \ f) {\n    const int n = f.size();\n    assert((n & (n - 1)) == 0);\n    for\
    \ (int i = 1; i < n; i <<= 1)\n        for (const int j : rep(n))\n          \
    \  if (j & i) f[j] = S::operation(f[j & ~i], f[j]);\n}\n#line 8 \"algorithm/or_convolution.cpp\"\
    \n\ntemplate <class T> std::vector<T> or_convolution(std::vector<T> a, std::vector<T>\
    \ b) {\n    assert(a.size() == b.size());\n    subset_zeta_transform<SumGroup<T>>(a);\n\
    \    subset_zeta_transform<SumGroup<T>>(b);\n    for (const int i : rep(a.size()))\
    \ a[i] *= b[i];\n    subset_mobius_transform<SumGroup<T>>(a);\n    return a;\n\
    }\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n#include \"../traits/sum_group.cpp\"\
    \n#include \"../utility/rep.cpp\"\n#include \"subset_mobius_transform.cpp\"\n\
    #include \"subset_zeta_transform.cpp\"\n\ntemplate <class T> std::vector<T> or_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n    assert(a.size() == b.size());\n    subset_zeta_transform<SumGroup<T>>(a);\n\
    \    subset_zeta_transform<SumGroup<T>>(b);\n    for (const int i : rep(a.size()))\
    \ a[i] *= b[i];\n    subset_mobius_transform<SumGroup<T>>(a);\n    return a;\n\
    }\n"
  dependsOn:
  - traits/sum_group.cpp
  - utility/rep.cpp
  - algorithm/subset_mobius_transform.cpp
  - algorithm/subset_zeta_transform.cpp
  isVerificationFile: false
  path: algorithm/or_convolution.cpp
  requiredBy: []
  timestamp: '2021-12-28 21:38:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/or_convolution.cpp
layout: document
redirect_from:
- /library/algorithm/or_convolution.cpp
- /library/algorithm/or_convolution.cpp.html
title: algorithm/or_convolution.cpp
---
