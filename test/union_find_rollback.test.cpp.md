---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/union_find_rollback.cpp
    title: graph/union_find_rollback.cpp
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
  bundledCode: "#line 1 \"test/union_find_rollback.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/persistent_unionfind\"\n#line 2 \"utility/int_alias.cpp\"\
    \n#include <cstdint>\n#include <cstddef>\n\nusing i32 = std::int32_t;\nusing u32\
    \ = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing\
    \ i128 = __int128_t;\nusing u128 = __uint128_t;\nusing isize = std::ptrdiff_t;\n\
    using usize = std::size_t;\n#line 3 \"utility/rep.cpp\"\n#include <algorithm>\n\
    \nclass rep {\n    struct Iter {\n        usize itr;\n        constexpr Iter(const\
    \ usize pos) noexcept: itr(pos) { }\n        constexpr void operator ++ () noexcept\
    \ { ++itr; }\n        constexpr bool operator != (const Iter& other) const noexcept\
    \ { return itr != other.itr; }\n        constexpr usize operator * () const noexcept\
    \ { return itr; }\n    };\n    const Iter first, last;\npublic:\n    explicit\
    \ constexpr rep(const usize first, const usize last) noexcept: first(first), last(std::max(first,\
    \ last)) { }\n    constexpr Iter begin() const noexcept { return first; }\n  \
    \  constexpr Iter end() const noexcept { return last; }\n};\n#line 2 \"utility/rec_lambda.cpp\"\
    \n#include <utility>\n#include <type_traits>\n\ntemplate <class F>\nstruct RecLambda:\
    \ private F {\n    template <class G>\n    explicit constexpr RecLambda(G&& g):\
    \ F(std::forward<G>(g)) { }\n    template <class... Args>\n    constexpr decltype(auto)\
    \ operator () (Args&&... args) const {\n        return F::operator()(*this, std::forward<Args>(args)...);\n\
    \    }\n};\n\ntemplate <class G>\nexplicit RecLambda(G&&) -> RecLambda<std::decay_t<G>>;\n\
    #line 3 \"graph/union_find_rollback.cpp\"\n#include <vector>\n#include <stack>\n\
    #line 6 \"graph/union_find_rollback.cpp\"\n#include <cassert>\n\nclass UnionFindRollback\
    \ {\n    std::vector<usize> data;\n    std::stack<std::pair<usize, usize>> history;\n\
    \npublic:\n    explicit UnionFindRollback(const usize size = 0): data(size, -1),\
    \ history() { }\n\n    usize size() const { return data.size(); }\n\n    usize\
    \ leader(usize u) const {\n        assert(u < size());\n        while (data[u]\
    \ < size()) u = data[u];\n        return u;\n    }\n\n    usize size(const usize\
    \ u) const {\n        assert(u < size());\n        return -data[leader(u)];\n\
    \    }\n\n    std::pair<usize, bool> merge(usize u, usize v) {\n        assert(u\
    \ < size());\n        assert(v < size());\n        u = leader(u); \n        v\
    \ = leader(v);\n        if (u == v) return std::make_pair(u, false);\n       \
    \ if (data[u] > data[v]) std::swap(u, v);\n        history.emplace(u, data[u]);\n\
    \        history.emplace(v, data[v]);\n        data[u] += data[v];\n        data[v]\
    \ = u;\n        return std::make_pair(u, true);\n    }\n\n    bool same(const\
    \ usize u, const usize v) const {\n        assert(u < size());\n        assert(v\
    \ < size());\n        return leader(u) == leader(v);\n    }\n\n    void rollback(const\
    \ usize steps) {\n        assert(2 * steps <= history.size());\n        for (usize\
    \ i = 2 * steps; i > 0; --i) {\n            const auto [k, x] = history.top();\n\
    \            history.pop();\n            data[k] = x;\n        }\n    }\n};\n\
    #line 6 \"test/union_find_rollback.test.cpp\"\n#include <iostream>\n\nint main()\
    \ {\n    usize N, Q;\n    std::cin >> N >> Q;\n    std::vector<std::pair<usize,\
    \ usize>> connect(Q + 1);\n    std::vector<std::vector<usize>> graph(Q + 1);\n\
    \    std::vector<std::vector<std::tuple<usize, usize, usize>>> query(Q + 1);\n\
    \    std::vector<bool> ans(Q + 1);\n    std::vector<usize> output;\n    output.reserve(Q);\n\
    \    for (const auto i: rep(1, Q + 1)) {\n        isize t, k;\n        usize u,\
    \ v;\n        std::cin >> t >> k >> u >> v;\n        k += 1;\n        if (t ==\
    \ 0) {\n            connect[i] = {u, v};\n            graph[k].push_back(i);\n\
    \        }\n        else {\n            output.push_back(i);\n            query[k].emplace_back(i,\
    \ u, v);\n        }\n    }\n    UnionFindRollback dsu(N);\n    std::vector<bool>\
    \ done(Q);\n    RecLambda([&](auto&& dfs, const usize u) -> void {\n        const\
    \ auto f = dsu.merge(connect[u].first, connect[u].second).second;\n        for\
    \ (const auto [i, x, y]: query[u]) {\n            ans[i] = dsu.same(x, y);\n \
    \       }\n        for (const auto v: graph[u]) {\n            dfs(v);\n     \
    \   }\n        dsu.rollback(f);\n        done[u] = true;\n    })(0);\n    for\
    \ (const auto i: output) {\n        std::cout << ans[i] << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    #include \"../utility/int_alias.cpp\"\n#include \"../utility/rep.cpp\"\n#include\
    \ \"../utility/rec_lambda.cpp\"\n#include \"../graph/union_find_rollback.cpp\"\
    \n#include <iostream>\n\nint main() {\n    usize N, Q;\n    std::cin >> N >> Q;\n\
    \    std::vector<std::pair<usize, usize>> connect(Q + 1);\n    std::vector<std::vector<usize>>\
    \ graph(Q + 1);\n    std::vector<std::vector<std::tuple<usize, usize, usize>>>\
    \ query(Q + 1);\n    std::vector<bool> ans(Q + 1);\n    std::vector<usize> output;\n\
    \    output.reserve(Q);\n    for (const auto i: rep(1, Q + 1)) {\n        isize\
    \ t, k;\n        usize u, v;\n        std::cin >> t >> k >> u >> v;\n        k\
    \ += 1;\n        if (t == 0) {\n            connect[i] = {u, v};\n           \
    \ graph[k].push_back(i);\n        }\n        else {\n            output.push_back(i);\n\
    \            query[k].emplace_back(i, u, v);\n        }\n    }\n    UnionFindRollback\
    \ dsu(N);\n    std::vector<bool> done(Q);\n    RecLambda([&](auto&& dfs, const\
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
  - graph/union_find_rollback.cpp
  isVerificationFile: true
  path: test/union_find_rollback.test.cpp
  requiredBy: []
  timestamp: '2021-04-28 16:45:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/union_find_rollback.test.cpp
layout: document
redirect_from:
- /verify/test/union_find_rollback.test.cpp
- /verify/test/union_find_rollback.test.cpp.html
title: test/union_find_rollback.test.cpp
---
