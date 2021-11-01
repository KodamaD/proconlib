---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/union_find.cpp
    title: graph/union_find.cpp
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
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/union_find.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n#line 2 \"utility/int_alias.cpp\"\n#include <cstddef>\n#include <cstdint>\n\n\
    using i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing isize = std::ptrdiff_t;\nusing usize = std::size_t;\n\
    #line 2 \"graph/union_find.cpp\"\n#include <algorithm>\n#include <cassert>\n#include\
    \ <vector>\n#line 4 \"utility/rep.cpp\"\n\nclass rep {\n    struct Iter {\n  \
    \      usize itr;\n        constexpr Iter(const usize pos) noexcept : itr(pos)\
    \ {}\n        constexpr void operator++() noexcept { ++itr; }\n        constexpr\
    \ bool operator!=(const Iter& other) const noexcept { return itr != other.itr;\
    \ }\n        constexpr usize operator*() const noexcept { return itr; }\n    };\n\
    \    const Iter first, last;\n\n  public:\n    explicit constexpr rep(const usize\
    \ first, const usize last) noexcept : first(first), last(std::max(first, last))\
    \ {}\n    constexpr Iter begin() const noexcept { return first; }\n    constexpr\
    \ Iter end() const noexcept { return last; }\n};\n#line 7 \"graph/union_find.cpp\"\
    \n\nclass UnionFind {\n    usize components;\n    std::vector<usize> data;\n\n\
    \  public:\n    explicit UnionFind(const usize size = 0) : components(size), data(size,\
    \ (usize)-1) {}\n\n    usize size() const { return data.size(); }\n    usize count()\
    \ const { return components; }\n\n    usize leader(const usize u) {\n        assert(u\
    \ < size());\n        if (data[u] >= size()) return u;\n        return data[u]\
    \ = leader(data[u]);\n    }\n\n    usize size(const usize u) {\n        assert(u\
    \ < size());\n        return -data[leader(u)];\n    }\n\n    std::pair<usize,\
    \ bool> merge(usize u, usize v) {\n        assert(u < size());\n        assert(v\
    \ < size());\n        u = leader(u);\n        v = leader(v);\n        if (u ==\
    \ v) return std::make_pair(u, false);\n        if (data[u] > data[v]) std::swap(u,\
    \ v);\n        components -= 1;\n        data[u] += data[v];\n        data[v]\
    \ = u;\n        return std::make_pair(u, true);\n    }\n\n    bool same(const\
    \ usize u, const usize v) {\n        assert(u < size());\n        assert(v < size());\n\
    \        return leader(u) == leader(v);\n    }\n\n    std::vector<std::vector<usize>>\
    \ decompose() {\n        std::vector<std::vector<usize>> ret(size());\n      \
    \  for (const usize u : rep(0, size())) {\n            ret[leader(u)].push_back(u);\n\
    \        }\n        ret.erase(std::remove_if(ret.begin(), ret.end(), [&](const\
    \ std::vector<usize>& v) { return v.empty(); }),\n                  ret.end());\n\
    \        return ret;\n    }\n};\n#line 4 \"test/union_find.test.cpp\"\n#include\
    \ <iostream>\n\nint main() {\n    usize N, Q;\n    std::cin >> N >> Q;\n    UnionFind\
    \ dsu(N);\n    while (Q--) {\n        usize t, u, v;\n        std::cin >> t >>\
    \ u >> v;\n        if (t == 0) {\n            dsu.merge(u, v);\n        }\n  \
    \      else {\n            std::cout << dsu.same(u, v) << '\\n';\n        }\n\
    \    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include \"\
    ../utility/int_alias.cpp\"\n#include \"../graph/union_find.cpp\"\n#include <iostream>\n\
    \nint main() {\n    usize N, Q;\n    std::cin >> N >> Q;\n    UnionFind dsu(N);\n\
    \    while (Q--) {\n        usize t, u, v;\n        std::cin >> t >> u >> v;\n\
    \        if (t == 0) {\n            dsu.merge(u, v);\n        }\n        else\
    \ {\n            std::cout << dsu.same(u, v) << '\\n';\n        }\n    }\n   \
    \ return 0;\n}"
  dependsOn:
  - utility/int_alias.cpp
  - graph/union_find.cpp
  - utility/rep.cpp
  isVerificationFile: true
  path: test/union_find.test.cpp
  requiredBy: []
  timestamp: '2021-09-08 18:46:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/union_find.test.cpp
layout: document
redirect_from:
- /verify/test/union_find.test.cpp
- /verify/test/union_find.test.cpp.html
title: test/union_find.test.cpp
---
