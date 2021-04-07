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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/union_find.test.cpp
    title: test/union_find.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ { return last; }\n};\n#line 4 \"graph/union_find.cpp\"\n#include <vector>\n\
    #include <cassert>\n#line 7 \"graph/union_find.cpp\"\n\nclass UnionFind {\n  \
    \  usize components;\n    std::vector<usize> data;\n\npublic:\n    explicit UnionFind(const\
    \ usize size = 0): components(size), data(size, (usize) -1) { }\n\n    usize size()\
    \ const { return data.size(); }\n    usize count() const { return components;\
    \ }\n\n    usize leader(const usize u) {\n        assert(u < size());\n      \
    \  if (data[u] >= size()) return u;\n        return data[u] = leader(data[u]);\n\
    \    }\n\n    usize size(const usize u) {\n        assert(u < size());\n     \
    \   return -data[leader(u)];\n    }\n\n    std::pair<usize, bool> merge(usize\
    \ u, usize v) {\n        assert(u < size());\n        assert(v < size());\n  \
    \      u = leader(u); \n        v = leader(v);\n        if (u == v) return std::make_pair(u,\
    \ false);\n        if (data[u] > data[v]) std::swap(u, v);\n        components\
    \ -= 1;\n        data[u] += data[v];\n        data[v] = u;\n        return std::make_pair(u,\
    \ true);\n    }\n\n    bool same(const usize u, const usize v) {\n        assert(u\
    \ < size());\n        assert(v < size());\n        return leader(u) == leader(v);\n\
    \    }\n\n    std::vector<std::vector<usize>> decompose() {\n        std::vector<std::vector<usize>>\
    \ ret(size());\n        for (const usize u: rep(0, size())) {\n            ret[leader(u)].push_back(u);\n\
    \        }\n        ret.erase(std::remove_if(ret.begin(), ret.end(), [&](const\
    \ std::vector<usize>& v) { return v.empty(); }), ret.end());\n        return ret;\n\
    \    }\n};\n"
  code: "#pragma once\n#include \"../utility/int_alias.cpp\"\n#include \"../utility/rep.cpp\"\
    \n#include <vector>\n#include <cassert>\n#include <algorithm>\n\nclass UnionFind\
    \ {\n    usize components;\n    std::vector<usize> data;\n\npublic:\n    explicit\
    \ UnionFind(const usize size = 0): components(size), data(size, (usize) -1) {\
    \ }\n\n    usize size() const { return data.size(); }\n    usize count() const\
    \ { return components; }\n\n    usize leader(const usize u) {\n        assert(u\
    \ < size());\n        if (data[u] >= size()) return u;\n        return data[u]\
    \ = leader(data[u]);\n    }\n\n    usize size(const usize u) {\n        assert(u\
    \ < size());\n        return -data[leader(u)];\n    }\n\n    std::pair<usize,\
    \ bool> merge(usize u, usize v) {\n        assert(u < size());\n        assert(v\
    \ < size());\n        u = leader(u); \n        v = leader(v);\n        if (u ==\
    \ v) return std::make_pair(u, false);\n        if (data[u] > data[v]) std::swap(u,\
    \ v);\n        components -= 1;\n        data[u] += data[v];\n        data[v]\
    \ = u;\n        return std::make_pair(u, true);\n    }\n\n    bool same(const\
    \ usize u, const usize v) {\n        assert(u < size());\n        assert(v < size());\n\
    \        return leader(u) == leader(v);\n    }\n\n    std::vector<std::vector<usize>>\
    \ decompose() {\n        std::vector<std::vector<usize>> ret(size());\n      \
    \  for (const usize u: rep(0, size())) {\n            ret[leader(u)].push_back(u);\n\
    \        }\n        ret.erase(std::remove_if(ret.begin(), ret.end(), [&](const\
    \ std::vector<usize>& v) { return v.empty(); }), ret.end());\n        return ret;\n\
    \    }\n};"
  dependsOn:
  - utility/int_alias.cpp
  - utility/rep.cpp
  isVerificationFile: false
  path: graph/union_find.cpp
  requiredBy: []
  timestamp: '2021-04-06 09:36:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/union_find.test.cpp
documentation_of: graph/union_find.cpp
layout: document
redirect_from:
- /library/graph/union_find.cpp
- /library/graph/union_find.cpp.html
title: graph/union_find.cpp
---
