---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/rollback_union_find.cpp
    title: graph/rollback_union_find.cpp
  - icon: ':heavy_check_mark:'
    path: utility/rec_lambda.cpp
    title: utility/rec_lambda.cpp
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
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"test/rollback_union_find.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/persistent_unionfind\"\n#line 2 \"utility/rep.cpp\"\
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
    \ { return Range(0, n); }\n#line 2 \"utility/rec_lambda.cpp\"\n#include <type_traits>\n\
    #include <utility>\n\ntemplate <class F> struct RecursiveLambda : private F {\n\
    \    explicit constexpr RecursiveLambda(F&& f) : F(std::forward<F>(f)) {}\n  \
    \  template <class... Args> constexpr decltype(auto) operator()(Args&&... args)\
    \ const {\n        return F::operator()(*this, std::forward<Args>(args)...);\n\
    \    }\n};\n\ntemplate <class F> constexpr decltype(auto) rec_lambda(F&& f) {\
    \ return RecursiveLambda<F>(std::forward<F>(f)); }\n#line 2 \"graph/rollback_union_find.cpp\"\
    \n#include <cassert>\n#line 4 \"graph/rollback_union_find.cpp\"\n#include <vector>\n\
    \nclass RollbackUnionFind {\n    std::vector<int> data;\n    std::vector<std::pair<int,\
    \ int>> history;\n\n  public:\n    explicit RollbackUnionFind(const int size =\
    \ 0) : data(size, -1), history() {}\n\n    int size() const { return data.size();\
    \ }\n\n    int leader(int u) const {\n        assert(0 <= u and u < size());\n\
    \        while (data[u] >= 0) u = data[u];\n        return u;\n    }\n\n    int\
    \ size(const int u) const {\n        assert(0 <= u and u < size());\n        return\
    \ -data[leader(u)];\n    }\n\n    std::pair<int, bool> merge(int u, int v) {\n\
    \        assert(0 <= u and u < size());\n        assert(0 <= v and v < size());\n\
    \        u = leader(u);\n        v = leader(v);\n        if (u == v) return std::make_pair(u,\
    \ false);\n        if (data[u] > data[v]) std::swap(u, v);\n        history.emplace_back(u,\
    \ data[u]);\n        history.emplace_back(v, data[v]);\n        data[u] += data[v];\n\
    \        data[v] = u;\n        return std::make_pair(u, true);\n    }\n\n    bool\
    \ same(const int u, const int v) const {\n        assert(0 <= u and u < size());\n\
    \        assert(0 <= v and v < size());\n        return leader(u) == leader(v);\n\
    \    }\n\n    void rollback(const int steps) {\n        assert(0 <= steps and\
    \ 2 * steps <= (int)history.size());\n        for (int i = 2 * steps; i > 0; --i)\
    \ {\n            const auto [k, x] = history.back();\n            history.pop_back();\n\
    \            data[k] = x;\n        }\n    }\n};\n#line 5 \"test/rollback_union_find.test.cpp\"\
    \n#include <iostream>\n\nint main() {\n    int N, Q;\n    std::cin >> N >> Q;\n\
    \    std::vector<std::pair<int, int>> connect(Q + 1);\n    std::vector<std::vector<int>>\
    \ graph(Q + 1);\n    std::vector<std::vector<std::tuple<int, int, int>>> query(Q\
    \ + 1);\n    std::vector<bool> ans(Q + 1);\n    std::vector<int> output;\n   \
    \ output.reserve(Q);\n    for (const auto i: rep(1, Q + 1)) {\n        int t,\
    \ k;\n        int u, v;\n        std::cin >> t >> k >> u >> v;\n        k += 1;\n\
    \        if (t == 0) {\n            connect[i] = {u, v};\n            graph[k].push_back(i);\n\
    \        }\n        else {\n            output.push_back(i);\n            query[k].emplace_back(i,\
    \ u, v);\n        }\n    }\n    RollbackUnionFind dsu(N);\n    std::vector<bool>\
    \ done(Q);\n    rec_lambda([&](auto&& dfs, const int u) -> void {\n        const\
    \ auto f = dsu.merge(connect[u].first, connect[u].second).second;\n        for\
    \ (const auto [i, x, y]: query[u]) {\n            ans[i] = dsu.same(x, y);\n \
    \       }\n        for (const auto v: graph[u]) {\n            dfs(v);\n     \
    \   }\n        dsu.rollback(f);\n        done[u] = true;\n    })(0);\n    for\
    \ (const auto i: output) {\n        std::cout << ans[i] << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    #include \"../utility/rep.cpp\"\n#include \"../utility/rec_lambda.cpp\"\n#include\
    \ \"../graph/rollback_union_find.cpp\"\n#include <iostream>\n\nint main() {\n\
    \    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<std::pair<int, int>>\
    \ connect(Q + 1);\n    std::vector<std::vector<int>> graph(Q + 1);\n    std::vector<std::vector<std::tuple<int,\
    \ int, int>>> query(Q + 1);\n    std::vector<bool> ans(Q + 1);\n    std::vector<int>\
    \ output;\n    output.reserve(Q);\n    for (const auto i: rep(1, Q + 1)) {\n \
    \       int t, k;\n        int u, v;\n        std::cin >> t >> k >> u >> v;\n\
    \        k += 1;\n        if (t == 0) {\n            connect[i] = {u, v};\n  \
    \          graph[k].push_back(i);\n        }\n        else {\n            output.push_back(i);\n\
    \            query[k].emplace_back(i, u, v);\n        }\n    }\n    RollbackUnionFind\
    \ dsu(N);\n    std::vector<bool> done(Q);\n    rec_lambda([&](auto&& dfs, const\
    \ int u) -> void {\n        const auto f = dsu.merge(connect[u].first, connect[u].second).second;\n\
    \        for (const auto [i, x, y]: query[u]) {\n            ans[i] = dsu.same(x,\
    \ y);\n        }\n        for (const auto v: graph[u]) {\n            dfs(v);\n\
    \        }\n        dsu.rollback(f);\n        done[u] = true;\n    })(0);\n  \
    \  for (const auto i: output) {\n        std::cout << ans[i] << '\\n';\n    }\n\
    }"
  dependsOn:
  - utility/rep.cpp
  - utility/rec_lambda.cpp
  - graph/rollback_union_find.cpp
  isVerificationFile: true
  path: test/rollback_union_find.test.cpp
  requiredBy: []
  timestamp: '2021-12-28 22:38:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/rollback_union_find.test.cpp
layout: document
redirect_from:
- /verify/test/rollback_union_find.test.cpp
- /verify/test/rollback_union_find.test.cpp.html
title: test/rollback_union_find.test.cpp
---
