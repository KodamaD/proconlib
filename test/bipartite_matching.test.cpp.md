---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dinic.cpp
    title: graph/dinic.cpp
  - icon: ':heavy_check_mark:'
    path: utility/index_offset.cpp
    title: utility/index_offset.cpp
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':heavy_check_mark:'
    path: utility/rec_lambda.cpp
    title: utility/rec_lambda.cpp
  - icon: ':question:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"test/bipartite_matching.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\
    \n#line 2 \"utility/rep.cpp\"\n#include <algorithm>\n\nclass Range {\n    struct\
    \ Iter {\n        int itr;\n        constexpr Iter(const int pos) noexcept : itr(pos)\
    \ {}\n        constexpr void operator++() noexcept { ++itr; }\n        constexpr\
    \ bool operator!=(const Iter& other) const noexcept { return itr != other.itr;\
    \ }\n        constexpr int operator*() const noexcept { return itr; }\n    };\n\
    \    const Iter first, last;\n\n  public:\n    explicit constexpr Range(const\
    \ int first, const int last) noexcept : first(first), last(std::max(first, last))\
    \ {}\n    constexpr Iter begin() const noexcept { return first; }\n    constexpr\
    \ Iter end() const noexcept { return last; }\n};\n\nconstexpr Range rep(const\
    \ int l, const int r) noexcept { return Range(l, r); }\nconstexpr Range rep(const\
    \ int n) noexcept { return Range(0, n); }\n#line 3 \"graph/dinic.cpp\"\n#include\
    \ <cassert>\n#include <limits>\n#include <queue>\n#include <type_traits>\n#include\
    \ <vector>\n#line 3 \"utility/index_offset.cpp\"\n\nclass IndexOffset {\n    int\
    \ offset, len;\n\n  public:\n    constexpr IndexOffset() noexcept : offset(),\
    \ len() {}\n    explicit constexpr IndexOffset(const int o, const int l) noexcept\
    \ : offset(o), len(l) {}\n    constexpr int size() const { return len; }\n   \
    \ constexpr int operator[](const int i) const noexcept {\n        assert(i < len);\n\
    \        return offset + i;\n    }\n    constexpr int to_idx(const int i) const\
    \ noexcept {\n        assert(offset <= i and i < offset + len);\n        return\
    \ i - offset;\n    }\n};\n#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n\
    \nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    #line 3 \"utility/rec_lambda.cpp\"\n#include <utility>\n\ntemplate <class F> struct\
    \ RecursiveLambda : private F {\n    explicit constexpr RecursiveLambda(F&& f)\
    \ : F(std::forward<F>(f)) {}\n    template <class... Args> constexpr decltype(auto)\
    \ operator()(Args&&... args) const {\n        return F::operator()(*this, std::forward<Args>(args)...);\n\
    \    }\n};\n\ntemplate <class F> constexpr decltype(auto) rec_lambda(F&& f) {\
    \ return RecursiveLambda<F>(std::forward<F>(f)); }\n#line 11 \"graph/dinic.cpp\"\
    \n\ntemplate <class Flow, std::enable_if_t<std::is_integral_v<Flow>>* = nullptr>\
    \ class Dinic {\n    struct Edge {\n        int dst, rev;\n        Flow cap;\n\
    \    };\n\n    std::vector<std::vector<Edge>> graph;\n\n  public:\n    Dinic()\
    \ : graph() {}\n    explicit Dinic(const int n) : graph(n) {}\n\n    class EdgePtr\
    \ {\n        friend class Dinic;\n        Dinic* self;\n        int u, e;\n\n\
    \        explicit EdgePtr(Dinic* p, const int u, const int e) : self(p), u(u),\
    \ e(e) {}\n\n        const Edge& edge() const { return self->graph[u][e]; }\n\
    \        const Edge& rev_edge() const { return self->graph[edge().dst][edge().rev];\
    \ }\n\n      public:\n        EdgePtr() : self(nullptr), u(0), e(0) {}\n     \
    \   int src() const { return u; }\n        int dst() const { return edge().dst;\
    \ }\n        Flow flow() const { return rev_edge().cap; }\n        Flow cap()\
    \ const { return edge().cap + rev_edge().cap; }\n    };\n\n    int size() const\
    \ { return graph.size(); }\n\n    int add_vertex() {\n        graph.emplace_back();\n\
    \        return size() - 1;\n    }\n    IndexOffset add_vertices(int n) {\n  \
    \      IndexOffset ret(size(), n);\n        while (n--) graph.emplace_back();\n\
    \        return ret;\n    }\n\n    EdgePtr add_edge(const int src, const int dst,\
    \ const Flow cap) {\n        assert(0 <= src and src < size());\n        assert(0\
    \ <= dst and dst < size());\n        assert(cap >= 0);\n        const int src_id\
    \ = graph[src].size();\n        const int dst_id = graph[dst].size() + (src ==\
    \ dst);\n        graph[src].push_back(Edge{dst, dst_id, cap});\n        graph[dst].push_back(Edge{src,\
    \ src_id, 0});\n        return EdgePtr(this, src, src_id);\n    }\n\n    Flow\
    \ flow(const int src, const int dst) { return flow(src, dst, std::numeric_limits<Flow>::max());\
    \ }\n    Flow flow(const int src, const int dst, const Flow flow_limit) {\n  \
    \      assert(0 <= src and src < size());\n        assert(0 <= dst and dst < size());\n\
    \        assert(src != dst);\n        std::vector<int> level(size()), iter(size());\n\
    \        std::queue<int> que;\n        const auto bfs = [&] {\n            std::fill(level.begin(),\
    \ level.end(), size());\n            level[src] = 0;\n            while (!que.empty())\
    \ que.pop();\n            que.push(src);\n            while (!que.empty()) {\n\
    \                const int u = que.front();\n                que.pop();\n    \
    \            for (const Edge& e : graph[u]) {\n                    if (e.cap ==\
    \ 0 or level[e.dst] < size()) continue;\n                    level[e.dst] = level[u]\
    \ + 1;\n                    if (e.dst == dst) return;\n                    que.push(e.dst);\n\
    \                }\n            }\n        };\n        const auto dfs = rec_lambda([&](auto&&\
    \ dfs, const int u, const Flow ub) -> Flow {\n            if (u == src) return\
    \ ub;\n            Flow ret = 0;\n            for (int& i = iter[u]; i < graph[u].size();\
    \ i += 1) {\n                Edge& e = graph[u][i];\n                Edge& re\
    \ = graph[e.dst][e.rev];\n                if (level[u] <= level[e.dst] or re.cap\
    \ == 0) continue;\n                const Flow d = dfs(e.dst, std::min(ub - ret,\
    \ re.cap));\n                if (d == 0) continue;\n                e.cap += d;\n\
    \                re.cap -= d;\n                ret += d;\n                if (ret\
    \ == ub) return ret;\n            }\n            level[u] = size();\n        \
    \    return ret;\n        });\n        Flow ret = 0;\n        while (ret < flow_limit)\
    \ {\n            bfs();\n            if (level[dst] == size()) break;\n      \
    \      std::fill(iter.begin(), iter.end(), (int)0);\n            const Flow f\
    \ = dfs(dst, flow_limit - ret);\n            if (f == 0) break;\n            ret\
    \ += f;\n        }\n        return ret;\n    }\n\n    std::vector<char> min_cut(const\
    \ int src) const {\n        std::vector<char> ret(size());\n        std::queue<int>\
    \ que;\n        ret[src] = true;\n        que.push(src);\n        while (!que.empty())\
    \ {\n            const int u = que.front();\n            que.pop();\n        \
    \    for (const Edge& e : graph[u]) {\n                if (e.cap > 0 and !ret[e.dst])\
    \ {\n                    ret[e.dst] = true;\n                    que.push(e.dst);\n\
    \                }\n            }\n        }\n        return ret;\n    }\n};\n\
    #line 4 \"test/bipartite_matching.test.cpp\"\n#include <iostream>\n#line 6 \"\
    test/bipartite_matching.test.cpp\"\n\nint main() {\n    int L, R, M;\n    std::cin\
    \ >> L >> R >> M;\n    Dinic<int> dinic;\n    const auto src = dinic.add_vertex();\n\
    \    const auto dst = dinic.add_vertex();\n    const auto left = dinic.add_vertices(L);\n\
    \    const auto right = dinic.add_vertices(R);\n    std::vector<Dinic<int>::EdgePtr>\
    \ ptr(M);\n    for (const auto i : rep(0, L)) {\n        dinic.add_edge(src, left[i],\
    \ 1);\n    }\n    for (const auto i : rep(0, R)) {\n        dinic.add_edge(right[i],\
    \ dst, 1);\n    }\n    for (const auto i : rep(0, M)) {\n        int a, b;\n \
    \       std::cin >> a >> b;\n        ptr[i] = dinic.add_edge(left[a], right[b],\
    \ 1);\n    }\n    std::cout << dinic.flow(src, dst) << '\\n';\n    for (const\
    \ auto i : rep(0, M)) {\n        if (ptr[i].flow() == 1) {\n            std::cout\
    \ << left.to_idx(ptr[i].src()) << ' ' << right.to_idx(ptr[i].dst()) << '\\n';\n\
    \        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n#include\
    \ \"../utility/rep.cpp\"\n#include \"../graph/dinic.cpp\"\n#include <iostream>\n\
    #include <vector>\n\nint main() {\n    int L, R, M;\n    std::cin >> L >> R >>\
    \ M;\n    Dinic<int> dinic;\n    const auto src = dinic.add_vertex();\n    const\
    \ auto dst = dinic.add_vertex();\n    const auto left = dinic.add_vertices(L);\n\
    \    const auto right = dinic.add_vertices(R);\n    std::vector<Dinic<int>::EdgePtr>\
    \ ptr(M);\n    for (const auto i : rep(0, L)) {\n        dinic.add_edge(src, left[i],\
    \ 1);\n    }\n    for (const auto i : rep(0, R)) {\n        dinic.add_edge(right[i],\
    \ dst, 1);\n    }\n    for (const auto i : rep(0, M)) {\n        int a, b;\n \
    \       std::cin >> a >> b;\n        ptr[i] = dinic.add_edge(left[a], right[b],\
    \ 1);\n    }\n    std::cout << dinic.flow(src, dst) << '\\n';\n    for (const\
    \ auto i : rep(0, M)) {\n        if (ptr[i].flow() == 1) {\n            std::cout\
    \ << left.to_idx(ptr[i].src()) << ' ' << right.to_idx(ptr[i].dst()) << '\\n';\n\
    \        }\n    }\n    return 0;\n}"
  dependsOn:
  - utility/rep.cpp
  - graph/dinic.cpp
  - utility/index_offset.cpp
  - utility/int_alias.cpp
  - utility/rec_lambda.cpp
  isVerificationFile: true
  path: test/bipartite_matching.test.cpp
  requiredBy: []
  timestamp: '2021-12-17 09:20:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/bipartite_matching.test.cpp
layout: document
redirect_from:
- /verify/test/bipartite_matching.test.cpp
- /verify/test/bipartite_matching.test.cpp.html
title: test/bipartite_matching.test.cpp
---
