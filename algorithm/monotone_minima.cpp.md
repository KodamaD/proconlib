---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':heavy_check_mark:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n#include <cstddef>\n\
    \nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    using isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 3 \"utility/rep.cpp\"\
    \n#include <algorithm>\n\nclass rep {\n    struct Iter {\n        usize itr;\n\
    \        constexpr Iter(const usize pos) noexcept: itr(pos) { }\n        constexpr\
    \ void operator ++ () noexcept { ++itr; }\n        constexpr bool operator !=\
    \ (const Iter& other) const noexcept { return itr != other.itr; }\n        constexpr\
    \ usize operator * () const noexcept { return itr; }\n    };\n    const Iter first,\
    \ last;\npublic:\n    explicit constexpr rep(const usize first, const usize last)\
    \ noexcept: first(first), last(std::max(first, last)) { }\n    constexpr Iter\
    \ begin() const noexcept { return first; }\n    constexpr Iter end() const noexcept\
    \ { return last; }\n};\n#line 4 \"algorithm/monotone_minima.cpp\"\n#include <vector>\n\
    #include <queue>\n#include <tuple>\n\ntemplate <class Select>\nstd::vector<usize>\
    \ monotone_minima(const usize row, const usize column, const Select& select) {\n\
    \    std::vector<usize> ret(row);\n    std::queue<std::tuple<usize, usize, usize,\
    \ usize>> que;\n    que.emplace(0, row, 0, column);\n    while (!que.empty())\
    \ {\n        const auto [l, r, d, u] = que.front();\n        que.pop();\n    \
    \    const usize m = (l + r) / 2;\n        ret[m] = d;\n        for (const usize\
    \ i: rep(d + 1, u)) {\n            if (select(m, ret[m], i)) {\n             \
    \   ret[m] = i;\n            }\n        }\n        if (l != m) {\n           \
    \ que.emplace(l, m, d, ret[m] + 1);\n        }\n        if (m + 1 != r) {\n  \
    \          que.emplace(m + 1, r, ret[m], u);\n        }\n    }\n    return ret;\n\
    }\n"
  code: "#pragma once\n#include \"../utility/int_alias.cpp\"\n#include \"../utility/rep.cpp\"\
    \n#include <vector>\n#include <queue>\n#include <tuple>\n\ntemplate <class Select>\n\
    std::vector<usize> monotone_minima(const usize row, const usize column, const\
    \ Select& select) {\n    std::vector<usize> ret(row);\n    std::queue<std::tuple<usize,\
    \ usize, usize, usize>> que;\n    que.emplace(0, row, 0, column);\n    while (!que.empty())\
    \ {\n        const auto [l, r, d, u] = que.front();\n        que.pop();\n    \
    \    const usize m = (l + r) / 2;\n        ret[m] = d;\n        for (const usize\
    \ i: rep(d + 1, u)) {\n            if (select(m, ret[m], i)) {\n             \
    \   ret[m] = i;\n            }\n        }\n        if (l != m) {\n           \
    \ que.emplace(l, m, d, ret[m] + 1);\n        }\n        if (m + 1 != r) {\n  \
    \          que.emplace(m + 1, r, ret[m], u);\n        }\n    }\n    return ret;\n\
    }\n"
  dependsOn:
  - utility/int_alias.cpp
  - utility/rep.cpp
  isVerificationFile: false
  path: algorithm/monotone_minima.cpp
  requiredBy: []
  timestamp: '2021-04-07 12:02:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/monotone_minima.cpp
layout: document
redirect_from:
- /library/algorithm/monotone_minima.cpp
- /library/algorithm/monotone_minima.cpp.html
title: algorithm/monotone_minima.cpp
---
