---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
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
    #line 2 \"utility/int_alias.cpp\"\n#include <cstddef>\n#include <cstdint>\n\n\
    using i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    using isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 2 \"utility/rep.cpp\"\
    \n#include <algorithm>\n#line 4 \"utility/rep.cpp\"\n\nclass rep {\n    struct\
    \ Iter {\n        usize itr;\n        constexpr Iter(const usize pos) noexcept\
    \ : itr(pos) {}\n        constexpr void operator++() noexcept { ++itr; }\n   \
    \     constexpr bool operator!=(const Iter& other) const noexcept { return itr\
    \ != other.itr; }\n        constexpr usize operator*() const noexcept { return\
    \ itr; }\n    };\n    const Iter first, last;\n\n  public:\n    explicit constexpr\
    \ rep(const usize first, const usize last) noexcept : first(first), last(std::max(first,\
    \ last)) {}\n    constexpr Iter begin() const noexcept { return first; }\n   \
    \ constexpr Iter end() const noexcept { return last; }\n};\n#line 6 \"algorithm/smawk.cpp\"\
    \n\ntemplate <class Index, class Select>\nstd::vector<Index> smawk(const std::vector<Index>&\
    \ row, const std::vector<Index>& column, const Select& select) {\n    const usize\
    \ N = row.size();\n    if (N == 0) return {};\n    std::vector<Index> c2;\n  \
    \  for (const Index i : column) {\n        while (!c2.empty() and select(row[c2.size()\
    \ - 1], c2.back(), i)) c2.pop_back();\n        if (c2.size() < N) c2.push_back(i);\n\
    \    }\n    std::vector<Index> r2;\n    for (usize i = 1; i < N; i += 2) r2.push_back(row[i]);\n\
    \    const std::vector<Index> a2 = smawk(r2, c2, select);\n    std::vector<Index>\
    \ ret(N);\n    for (const usize i : rep(0, a2.size())) ret[2 * i + 1] = a2[i];\n\
    \    usize j = 0;\n    for (usize i = 0; i < N; i += 2) {\n        ret[i] = c2[j];\n\
    \        const Index end = (i + 1 == N ? c2.back() : ret[i + 1]);\n        while\
    \ (c2[j] != end) {\n            j += 1;\n            if (select(row[i], ret[i],\
    \ c2[j])) ret[i] = c2[j];\n        }\n    }\n    return ret;\n}\n\ntemplate <class\
    \ Select> std::vector<usize> smawk(const usize row, const usize column, const\
    \ Select& select) {\n    std::vector<usize> r(row), c(column);\n    std::iota(r.begin(),\
    \ r.end(), (usize)0);\n    std::iota(c.begin(), c.end(), (usize)0);\n    return\
    \ smawk(row, column, select);\n}\n"
  code: "#pragma once\n#include <numeric>\n#include <vector>\n#include \"../utility/int_alias.cpp\"\
    \n#include \"../utility/rep.cpp\"\n\ntemplate <class Index, class Select>\nstd::vector<Index>\
    \ smawk(const std::vector<Index>& row, const std::vector<Index>& column, const\
    \ Select& select) {\n    const usize N = row.size();\n    if (N == 0) return {};\n\
    \    std::vector<Index> c2;\n    for (const Index i : column) {\n        while\
    \ (!c2.empty() and select(row[c2.size() - 1], c2.back(), i)) c2.pop_back();\n\
    \        if (c2.size() < N) c2.push_back(i);\n    }\n    std::vector<Index> r2;\n\
    \    for (usize i = 1; i < N; i += 2) r2.push_back(row[i]);\n    const std::vector<Index>\
    \ a2 = smawk(r2, c2, select);\n    std::vector<Index> ret(N);\n    for (const\
    \ usize i : rep(0, a2.size())) ret[2 * i + 1] = a2[i];\n    usize j = 0;\n   \
    \ for (usize i = 0; i < N; i += 2) {\n        ret[i] = c2[j];\n        const Index\
    \ end = (i + 1 == N ? c2.back() : ret[i + 1]);\n        while (c2[j] != end) {\n\
    \            j += 1;\n            if (select(row[i], ret[i], c2[j])) ret[i] =\
    \ c2[j];\n        }\n    }\n    return ret;\n}\n\ntemplate <class Select> std::vector<usize>\
    \ smawk(const usize row, const usize column, const Select& select) {\n    std::vector<usize>\
    \ r(row), c(column);\n    std::iota(r.begin(), r.end(), (usize)0);\n    std::iota(c.begin(),\
    \ c.end(), (usize)0);\n    return smawk(row, column, select);\n}\n"
  dependsOn:
  - utility/int_alias.cpp
  - utility/rep.cpp
  isVerificationFile: false
  path: algorithm/smawk.cpp
  requiredBy: []
  timestamp: '2021-09-04 17:30:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/smawk.cpp
layout: document
redirect_from:
- /library/algorithm/smawk.cpp
- /library/algorithm/smawk.cpp.html
title: algorithm/smawk.cpp
---
