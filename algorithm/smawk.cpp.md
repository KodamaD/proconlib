---
data:
  _extendedDependsOn:
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
  bundledCode: "#line 2 \"algorithm/smawk.cpp\"\n#include <numeric>\n#include <vector>\n\
    #line 2 \"utility/rep.cpp\"\n#include <algorithm>\n\nclass Range {\n    struct\
    \ Iter {\n        int itr;\n        constexpr Iter(const int pos) noexcept : itr(pos)\
    \ {}\n        constexpr void operator++() noexcept { ++itr; }\n        constexpr\
    \ bool operator!=(const Iter& other) const noexcept { return itr != other.itr;\
    \ }\n        constexpr int operator*() const noexcept { return itr; }\n    };\n\
    \    const Iter first, last;\n\n  public:\n    explicit constexpr Range(const\
    \ int first, const int last) noexcept : first(first), last(std::max(first, last))\
    \ {}\n    constexpr Iter begin() const noexcept { return first; }\n    constexpr\
    \ Iter end() const noexcept { return last; }\n};\n\nconstexpr Range rep(const\
    \ int l, const int r) noexcept { return Range(l, r); }\nconstexpr Range rep(const\
    \ int n) noexcept { return Range(0, n); }\n#line 5 \"algorithm/smawk.cpp\"\n\n\
    template <class T, class Select>\nstd::vector<T> smawk(const std::vector<T>& row,\
    \ const std::vector<T>& column, const Select& select) {\n    const int n = row.size();\n\
    \    if (n == 0) return {};\n    std::vector<T> c2;\n    for (const T i : column)\
    \ {\n        while (!c2.empty() and select(row[c2.size() - 1], c2.back(), i))\
    \ c2.pop_back();\n        if (c2.size() < n) c2.push_back(i);\n    }\n    std::vector<T>\
    \ r2;\n    for (int i = 1; i < n; i += 2) r2.push_back(row[i]);\n    const std::vector<T>\
    \ a2 = smawk(r2, c2, select);\n    std::vector<T> ret(n);\n    for (const int\
    \ i : rep(0, a2.size())) ret[2 * i + 1] = a2[i];\n    int j = 0;\n    for (int\
    \ i = 0; i < n; i += 2) {\n        ret[i] = c2[j];\n        const T end = (i +\
    \ 1 == n ? c2.back() : ret[i + 1]);\n        while (c2[j] != end) {\n        \
    \    j += 1;\n            if (select(row[i], ret[i], c2[j])) ret[i] = c2[j];\n\
    \        }\n    }\n    return ret;\n}\n\ntemplate <class Select> std::vector<int>\
    \ smawk(const int row, const int column, const Select& select) {\n    std::vector<int>\
    \ r(row), c(column);\n    std::iota(r.begin(), r.end(), 0);\n    std::iota(c.begin(),\
    \ c.end(), 0);\n    return smawk(r, c, select);\n}\n"
  code: "#pragma once\n#include <numeric>\n#include <vector>\n#include \"../utility/rep.cpp\"\
    \n\ntemplate <class T, class Select>\nstd::vector<T> smawk(const std::vector<T>&\
    \ row, const std::vector<T>& column, const Select& select) {\n    const int n\
    \ = row.size();\n    if (n == 0) return {};\n    std::vector<T> c2;\n    for (const\
    \ T i : column) {\n        while (!c2.empty() and select(row[c2.size() - 1], c2.back(),\
    \ i)) c2.pop_back();\n        if (c2.size() < n) c2.push_back(i);\n    }\n   \
    \ std::vector<T> r2;\n    for (int i = 1; i < n; i += 2) r2.push_back(row[i]);\n\
    \    const std::vector<T> a2 = smawk(r2, c2, select);\n    std::vector<T> ret(n);\n\
    \    for (const int i : rep(0, a2.size())) ret[2 * i + 1] = a2[i];\n    int j\
    \ = 0;\n    for (int i = 0; i < n; i += 2) {\n        ret[i] = c2[j];\n      \
    \  const T end = (i + 1 == n ? c2.back() : ret[i + 1]);\n        while (c2[j]\
    \ != end) {\n            j += 1;\n            if (select(row[i], ret[i], c2[j]))\
    \ ret[i] = c2[j];\n        }\n    }\n    return ret;\n}\n\ntemplate <class Select>\
    \ std::vector<int> smawk(const int row, const int column, const Select& select)\
    \ {\n    std::vector<int> r(row), c(column);\n    std::iota(r.begin(), r.end(),\
    \ 0);\n    std::iota(c.begin(), c.end(), 0);\n    return smawk(r, c, select);\n\
    }\n"
  dependsOn:
  - utility/rep.cpp
  isVerificationFile: false
  path: algorithm/smawk.cpp
  requiredBy: []
  timestamp: '2021-12-17 09:20:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/smawk.cpp
layout: document
redirect_from:
- /library/algorithm/smawk.cpp
- /library/algorithm/smawk.cpp.html
title: algorithm/smawk.cpp
---
