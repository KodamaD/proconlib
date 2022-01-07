---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/union_find.cpp
    title: graph/union_find.cpp
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
    \n#line 2 \"graph/union_find.cpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <vector>\n#line 3 \"utility/rep.cpp\"\n\nclass Range {\n    struct Iter\
    \ {\n        int itr;\n        constexpr Iter(const int pos) noexcept : itr(pos)\
    \ {}\n        constexpr void operator++() noexcept { ++itr; }\n        constexpr\
    \ bool operator!=(const Iter& other) const noexcept { return itr != other.itr;\
    \ }\n        constexpr int operator*() const noexcept { return itr; }\n    };\n\
    \    const Iter first, last;\n\n  public:\n    explicit constexpr Range(const\
    \ int first, const int last) noexcept : first(first), last(std::max(first, last))\
    \ {}\n    constexpr Iter begin() const noexcept { return first; }\n    constexpr\
    \ Iter end() const noexcept { return last; }\n};\n\nconstexpr Range rep(const\
    \ int l, const int r) noexcept { return Range(l, r); }\nconstexpr Range rep(const\
    \ int n) noexcept { return Range(0, n); }\n#line 6 \"graph/union_find.cpp\"\n\n\
    class UnionFind {\n    int components;\n    std::vector<int> data;\n\n  public:\n\
    \    explicit UnionFind(const int size = 0) : components(size), data(size, (int)-1)\
    \ {}\n\n    int size() const { return data.size(); }\n    int count() const {\
    \ return components; }\n\n    int leader(const int u) {\n        assert(0 <= u\
    \ and u < size());\n        return data[u] < 0 ? u : data[u] = leader(data[u]);\n\
    \    }\n\n    int size(const int u) {\n        assert(0 <= u and u < size());\n\
    \        return -data[leader(u)];\n    }\n\n    std::pair<int, bool> merge(int\
    \ u, int v) {\n        assert(0 <= u and u < size());\n        assert(0 <= v and\
    \ v < size());\n        u = leader(u);\n        v = leader(v);\n        if (u\
    \ == v) return std::make_pair(u, false);\n        if (data[u] > data[v]) std::swap(u,\
    \ v);\n        components -= 1;\n        data[u] += data[v];\n        data[v]\
    \ = u;\n        return std::make_pair(u, true);\n    }\n\n    bool same(const\
    \ int u, const int v) {\n        assert(0 <= u and u < size());\n        assert(0\
    \ <= v and v < size());\n        return leader(u) == leader(v);\n    }\n\n   \
    \ std::vector<std::vector<int>> decompose() {\n        std::vector<int> buf(size()),\
    \ len(size());\n        for (const int i : rep(size())) len[buf[i] = leader(i)]++;\n\
    \        std::vector<std::vector<int>> ret(size());\n        for (const int i\
    \ : rep(size())) ret[i].reserve(len[i]);\n        for (const int i : rep(size()))\
    \ ret[buf[i]].push_back(i);\n        ret.erase(std::remove_if(ret.begin(), ret.end(),\
    \ [&](const std::vector<int>& v) { return v.empty(); }),\n                  ret.end());\n\
    \        return ret;\n    }\n};\n#line 3 \"test/union_find.test.cpp\"\n#include\
    \ <iostream>\n\nint main() {\n    int N, Q;\n    std::cin >> N >> Q;\n    UnionFind\
    \ dsu(N);\n    while (Q--) {\n        int t, u, v;\n        std::cin >> t >> u\
    \ >> v;\n        if (t == 0) {\n            dsu.merge(u, v);\n        }\n    \
    \    else {\n            std::cout << dsu.same(u, v) << '\\n';\n        }\n  \
    \  }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n#include \"\
    ../graph/union_find.cpp\"\n#include <iostream>\n\nint main() {\n    int N, Q;\n\
    \    std::cin >> N >> Q;\n    UnionFind dsu(N);\n    while (Q--) {\n        int\
    \ t, u, v;\n        std::cin >> t >> u >> v;\n        if (t == 0) {\n        \
    \    dsu.merge(u, v);\n        }\n        else {\n            std::cout << dsu.same(u,\
    \ v) << '\\n';\n        }\n    }\n    return 0;\n}"
  dependsOn:
  - graph/union_find.cpp
  - utility/rep.cpp
  isVerificationFile: true
  path: test/union_find.test.cpp
  requiredBy: []
  timestamp: '2022-01-07 21:48:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/union_find.test.cpp
layout: document
redirect_from:
- /verify/test/union_find.test.cpp
- /verify/test/union_find.test.cpp.html
title: test/union_find.test.cpp
---
