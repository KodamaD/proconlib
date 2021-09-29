---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/rollback_union_find.cpp
    title: graph/rollback_union_find.cpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
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
    https://judge.yosupo.jp/problem/persistent_unionfind\"\n#line 2 \"utility/int_alias.cpp\"\
    \n#include <cstddef>\n#include <cstdint>\n\nusing i32 = std::int32_t;\nusing u32\
    \ = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing\
    \ isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 2 \"utility/rep.cpp\"\
    \n#include <algorithm>\n#line 4 \"utility/rep.cpp\"\n\nclass rep {\n    struct\
    \ Iter {\n        usize itr;\n        constexpr Iter(const usize pos) noexcept\
    \ : itr(pos) {}\n        constexpr void operator++() noexcept { ++itr; }\n   \
    \     constexpr bool operator!=(const Iter& other) const noexcept { return itr\
    \ != other.itr; }\n        constexpr usize operator*() const noexcept { return\
    \ itr; }\n    };\n    const Iter first, last;\n\n  public:\n    explicit constexpr\
    \ rep(const usize first, const usize last) noexcept : first(first), last(std::max(first,\
    \ last)) {}\n    constexpr Iter begin() const noexcept { return first; }\n   \
    \ constexpr Iter end() const noexcept { return last; }\n};\n#line 2 \"utility/rec_lambda.cpp\"\
    \n#include <type_traits>\n#include <utility>\n\ntemplate <class F> struct RecursiveLambda\
    \ : private F {\n    explicit constexpr RecursiveLambda(F&& f) : F(std::forward<F>(f))\
    \ {}\n    template <class... Args> constexpr decltype(auto) operator()(Args&&...\
    \ args) const {\n        return F::operator()(*this, std::forward<Args>(args)...);\n\
    \    }\n};\n\ntemplate <class F> constexpr decltype(auto) rec_lambda(F&& f) {\n\
    \    using G = std::decay_t<F>;\n    return RecursiveLambda<G>(std::forward<G>(f));\n\
    }\n#line 2 \"graph/rollback_union_find.cpp\"\n#include <cassert>\n#include <stack>\n\
    #line 5 \"graph/rollback_union_find.cpp\"\n#include <vector>\n#line 7 \"graph/rollback_union_find.cpp\"\
    \n\nclass RollbackUnionFind {\n    std::vector<usize> data;\n    std::stack<std::pair<usize,\
    \ usize>> history;\n\n  public:\n    explicit RollbackUnionFind(const usize size\
    \ = 0) : data(size, -1), history() {}\n\n    usize size() const { return data.size();\
    \ }\n\n    usize leader(usize u) const {\n        assert(u < size());\n      \
    \  while (data[u] < size()) u = data[u];\n        return u;\n    }\n\n    usize\
    \ size(const usize u) const {\n        assert(u < size());\n        return -data[leader(u)];\n\
    \    }\n\n    std::pair<usize, bool> merge(usize u, usize v) {\n        assert(u\
    \ < size());\n        assert(v < size());\n        u = leader(u);\n        v =\
    \ leader(v);\n        if (u == v) return std::make_pair(u, false);\n        if\
    \ (data[u] > data[v]) std::swap(u, v);\n        history.emplace(u, data[u]);\n\
    \        history.emplace(v, data[v]);\n        data[u] += data[v];\n        data[v]\
    \ = u;\n        return std::make_pair(u, true);\n    }\n\n    bool same(const\
    \ usize u, const usize v) const {\n        assert(u < size());\n        assert(v\
    \ < size());\n        return leader(u) == leader(v);\n    }\n\n    void rollback(const\
    \ usize steps) {\n        assert(2 * steps <= history.size());\n        for (usize\
    \ i = 2 * steps; i > 0; --i) {\n            const auto [k, x] = history.top();\n\
    \            history.pop();\n            data[k] = x;\n        }\n    }\n};\n\
    #line 6 \"test/rollback_union_find.test.cpp\"\n#include <iostream>\n\nint main()\
    \ {\n    usize N, Q;\n    std::cin >> N >> Q;\n    std::vector<std::pair<usize,\
    \ usize>> connect(Q + 1);\n    std::vector<std::vector<usize>> graph(Q + 1);\n\
    \    std::vector<std::vector<std::tuple<usize, usize, usize>>> query(Q + 1);\n\
    \    std::vector<bool> ans(Q + 1);\n    std::vector<usize> output;\n    output.reserve(Q);\n\
    \    for (const auto i: rep(1, Q + 1)) {\n        isize t, k;\n        usize u,\
    \ v;\n        std::cin >> t >> k >> u >> v;\n        k += 1;\n        if (t ==\
    \ 0) {\n            connect[i] = {u, v};\n            graph[k].push_back(i);\n\
    \        }\n        else {\n            output.push_back(i);\n            query[k].emplace_back(i,\
    \ u, v);\n        }\n    }\n    RollbackUnionFind dsu(N);\n    std::vector<bool>\
    \ done(Q);\n    rec_lambda([&](auto&& dfs, const usize u) -> void {\n        const\
    \ auto f = dsu.merge(connect[u].first, connect[u].second).second;\n        for\
    \ (const auto [i, x, y]: query[u]) {\n            ans[i] = dsu.same(x, y);\n \
    \       }\n        for (const auto v: graph[u]) {\n            dfs(v);\n     \
    \   }\n        dsu.rollback(f);\n        done[u] = true;\n    })(0);\n    for\
    \ (const auto i: output) {\n        std::cout << ans[i] << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    #include \"../utility/int_alias.cpp\"\n#include \"../utility/rep.cpp\"\n#include\
    \ \"../utility/rec_lambda.cpp\"\n#include \"../graph/rollback_union_find.cpp\"\
    \n#include <iostream>\n\nint main() {\n    usize N, Q;\n    std::cin >> N >> Q;\n\
    \    std::vector<std::pair<usize, usize>> connect(Q + 1);\n    std::vector<std::vector<usize>>\
    \ graph(Q + 1);\n    std::vector<std::vector<std::tuple<usize, usize, usize>>>\
    \ query(Q + 1);\n    std::vector<bool> ans(Q + 1);\n    std::vector<usize> output;\n\
    \    output.reserve(Q);\n    for (const auto i: rep(1, Q + 1)) {\n        isize\
    \ t, k;\n        usize u, v;\n        std::cin >> t >> k >> u >> v;\n        k\
    \ += 1;\n        if (t == 0) {\n            connect[i] = {u, v};\n           \
    \ graph[k].push_back(i);\n        }\n        else {\n            output.push_back(i);\n\
    \            query[k].emplace_back(i, u, v);\n        }\n    }\n    RollbackUnionFind\
    \ dsu(N);\n    std::vector<bool> done(Q);\n    rec_lambda([&](auto&& dfs, const\
    \ usize u) -> void {\n        const auto f = dsu.merge(connect[u].first, connect[u].second).second;\n\
    \        for (const auto [i, x, y]: query[u]) {\n            ans[i] = dsu.same(x,\
    \ y);\n        }\n        for (const auto v: graph[u]) {\n            dfs(v);\n\
    \        }\n        dsu.rollback(f);\n        done[u] = true;\n    })(0);\n  \
    \  for (const auto i: output) {\n        std::cout << ans[i] << '\\n';\n    }\n\
    }"
  dependsOn:
  - utility/int_alias.cpp
  - utility/rep.cpp
  - utility/rec_lambda.cpp
  - graph/rollback_union_find.cpp
  isVerificationFile: true
  path: test/rollback_union_find.test.cpp
  requiredBy: []
  timestamp: '2021-09-08 18:46:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/rollback_union_find.test.cpp
layout: document
redirect_from:
- /verify/test/rollback_union_find.test.cpp
- /verify/test/rollback_union_find.test.cpp.html
title: test/rollback_union_find.test.cpp
---
