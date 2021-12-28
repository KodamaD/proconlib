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
  bundledCode: "#line 2 \"algorithm/monotone_minima.cpp\"\n#include <queue>\n#include\
    \ <tuple>\n#include <vector>\n#line 2 \"utility/rep.cpp\"\n#include <algorithm>\n\
    \nclass Range {\n    struct Iter {\n        int itr;\n        constexpr Iter(const\
    \ int pos) noexcept : itr(pos) {}\n        constexpr void operator++() noexcept\
    \ { ++itr; }\n        constexpr bool operator!=(const Iter& other) const noexcept\
    \ { return itr != other.itr; }\n        constexpr int operator*() const noexcept\
    \ { return itr; }\n    };\n    const Iter first, last;\n\n  public:\n    explicit\
    \ constexpr Range(const int first, const int last) noexcept : first(first), last(std::max(first,\
    \ last)) {}\n    constexpr Iter begin() const noexcept { return first; }\n   \
    \ constexpr Iter end() const noexcept { return last; }\n};\n\nconstexpr Range\
    \ rep(const int l, const int r) noexcept { return Range(l, r); }\nconstexpr Range\
    \ rep(const int n) noexcept { return Range(0, n); }\n#line 6 \"algorithm/monotone_minima.cpp\"\
    \n\ntemplate <class Select> std::vector<int> monotone_minima(const int row, const\
    \ int column, const Select& select) {\n    std::vector<int> ret(row);\n    std::queue<std::tuple<int,\
    \ int, int, int>> que;\n    que.emplace(0, row, 0, column);\n    while (!que.empty())\
    \ {\n        const auto [l, r, d, u] = que.front();\n        que.pop();\n    \
    \    const int m = (l + r) / 2;\n        ret[m] = d;\n        for (const int i\
    \ : rep(d + 1, u))\n            if (select(m, ret[m], i)) ret[m] = i;\n      \
    \  if (l != m) que.emplace(l, m, d, ret[m] + 1);\n        if (m + 1 != r) que.emplace(m\
    \ + 1, r, ret[m], u);\n    }\n    return ret;\n}\n"
  code: "#pragma once\n#include <queue>\n#include <tuple>\n#include <vector>\n#include\
    \ \"../utility/rep.cpp\"\n\ntemplate <class Select> std::vector<int> monotone_minima(const\
    \ int row, const int column, const Select& select) {\n    std::vector<int> ret(row);\n\
    \    std::queue<std::tuple<int, int, int, int>> que;\n    que.emplace(0, row,\
    \ 0, column);\n    while (!que.empty()) {\n        const auto [l, r, d, u] = que.front();\n\
    \        que.pop();\n        const int m = (l + r) / 2;\n        ret[m] = d;\n\
    \        for (const int i : rep(d + 1, u))\n            if (select(m, ret[m],\
    \ i)) ret[m] = i;\n        if (l != m) que.emplace(l, m, d, ret[m] + 1);\n   \
    \     if (m + 1 != r) que.emplace(m + 1, r, ret[m], u);\n    }\n    return ret;\n\
    }\n"
  dependsOn:
  - utility/rep.cpp
  isVerificationFile: false
  path: algorithm/monotone_minima.cpp
  requiredBy: []
  timestamp: '2021-12-28 21:38:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/monotone_minima.cpp
layout: document
redirect_from:
- /library/algorithm/monotone_minima.cpp
- /library/algorithm/monotone_minima.cpp.html
title: algorithm/monotone_minima.cpp
---
