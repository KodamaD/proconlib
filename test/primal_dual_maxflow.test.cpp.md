---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/primal_dual.cpp
    title: graph/primal_dual.cpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':heavy_check_mark:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  - icon: ':heavy_check_mark:'
    path: utility/setmin.cpp
    title: utility/setmin.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
  bundledCode: "#line 1 \"test/primal_dual_maxflow.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\n#line 2 \"\
    graph/primal_dual.cpp\"\n#include <algorithm>\n#include <cassert>\n#include <type_traits>\n\
    #include <utility>\n#include <vector>\n#line 2 \"utility/int_alias.cpp\"\n#include\
    \ <cstddef>\n#include <cstdint>\n\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\n\
    using i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing isize = std::ptrdiff_t;\n\
    using usize = std::size_t;\n#line 4 \"utility/rep.cpp\"\n\nclass rep {\n    struct\
    \ Iter {\n        usize itr;\n        constexpr Iter(const usize pos) noexcept\
    \ : itr(pos) {}\n        constexpr void operator++() noexcept { ++itr; }\n   \
    \     constexpr bool operator!=(const Iter& other) const noexcept { return itr\
    \ != other.itr; }\n        constexpr usize operator*() const noexcept { return\
    \ itr; }\n    };\n    const Iter first, last;\n\n  public:\n    explicit constexpr\
    \ rep(const usize first, const usize last) noexcept : first(first), last(std::max(first,\
    \ last)) {}\n    constexpr Iter begin() const noexcept { return first; }\n   \
    \ constexpr Iter end() const noexcept { return last; }\n};\n#line 2 \"utility/setmin.cpp\"\
    \n\ntemplate <class T> bool setmin(T& lhs, const T& rhs) {\n    if (lhs > rhs)\
    \ {\n        lhs = rhs;\n        return true;\n    }\n    return false;\n}\n#line\
    \ 10 \"graph/primal_dual.cpp\"\n\ntemplate <class Flow,\n          class Cost,\n\
    \          std::enable_if_t<std::is_integral_v<Flow> and std::is_integral_v<Cost>\
    \ and std::is_signed_v<Flow> and\n                           std::is_signed_v<Cost>>*\
    \ = nullptr>\nclass PrimalDual {\n    struct Edge {\n        usize dst, rev;\n\
    \        Flow flow, cap;\n        Cost cost;\n    };\n\n    std::vector<std::vector<Edge>>\
    \ graph;\n    std::vector<Flow> gap;\n    std::vector<Cost> potential;\n\n  public:\n\
    \    PrimalDual() : graph() {}\n    explicit PrimalDual(const usize n) : graph(n),\
    \ gap(n) {}\n\n    class EdgePtr {\n        friend class PrimalDual;\n       \
    \ PrimalDual* self;\n        usize u, e;\n\n        explicit EdgePtr(PrimalDual*\
    \ p, const usize u, const usize e) : self(p), u(u), e(e) {}\n\n        const Edge&\
    \ edge() const { return self->graph[u][e]; }\n        const Edge& rev_edge() const\
    \ { return self->graph[edge().dst][edge().rev]; }\n\n      public:\n        EdgePtr()\
    \ : self(nullptr), u(0), e(0) {}\n        usize src() const { return u; }\n  \
    \      usize dst() const { return edge().dst; }\n        Flow flow() const { return\
    \ edge().flow; }\n        Flow lower() const { return -rev_edge().cap; }\n   \
    \     Flow upper() const { return edge().cap; }\n        Cost cost() const { return\
    \ edge().cost; }\n    };\n\n    class Vertices {\n        friend class PrimalDual;\n\
    \        usize offset, len;\n        explicit Vertices(const usize o, const usize\
    \ l) : offset(o), len(l) {}\n\n      public:\n        Vertices() : offset(0),\
    \ len(0) {}\n        usize operator[](const usize i) const {\n            assert(i\
    \ < len);\n            return offset + i;\n        }\n        usize to_idx(const\
    \ usize i) const {\n            assert(offset <= i and i < offset + len);\n  \
    \          return i - offset;\n        }\n    };\n\n    usize size() const { return\
    \ graph.size(); }\n\n    usize add_vertex() {\n        graph.emplace_back();\n\
    \        gap.emplace_back();\n        return size() - 1;\n    }\n    Vertices\
    \ add_vertices(usize n) {\n        Vertices ret{size(), n};\n        while (n--)\
    \ {\n            graph.emplace_back();\n            gap.emplace_back();\n    \
    \    }\n        return ret;\n    }\n\n    EdgePtr add_edge(const usize src, const\
    \ usize dst, const Flow lower, const Flow upper, const Cost cost) {\n        assert(src\
    \ < size());\n        assert(dst < size());\n        assert(lower <= upper);\n\
    \        const usize src_id = graph[src].size();\n        const usize dst_id =\
    \ graph[dst].size() + (src == dst);\n        graph[src].push_back(Edge{dst, dst_id,\
    \ 0, upper, cost});\n        graph[dst].push_back(Edge{src, src_id, 0, -lower,\
    \ -cost});\n        return EdgePtr(this, src, src_id);\n    }\n\n    void add_supply(const\
    \ usize u, const Flow f) {\n        assert(u < size());\n        gap[u] += f;\n\
    \    }\n    void add_demand(const usize u, const Flow f) {\n        assert(u <\
    \ size());\n        gap[u] -= f;\n    }\n    void set_potential(const std::vector<Cost>&\
    \ p) {\n        assert(p.size() == size());\n        potential = p;\n    }\n\n\
    \    template <class Result = Cost> std::pair<Result, bool> solve_bflow() {\n\
    \        potential.resize(size(), 0);\n        for (const usize u : rep(0, size()))\
    \ {\n            for (Edge& e : graph[u]) {\n                if (e.cap < 0 or\
    \ e.cost + potential[u] - potential[e.dst] < 0) {\n                    e.flow\
    \ += e.cap;\n                    graph[e.dst][e.rev].flow -= e.cap;\n        \
    \            gap[u] -= e.cap;\n                    gap[e.dst] += e.cap;\n    \
    \            }\n            }\n        }\n        std::vector<usize> over, lack;\n\
    \        for (const usize u : rep(0, size())) {\n            if (gap[u] > 0) over.push_back(u);\n\
    \            if (gap[u] < 0) lack.push_back(u);\n        }\n        struct State\
    \ {\n            Cost cost;\n            usize vertex;\n            bool operator<(const\
    \ State& other) const { return cost > other.cost; }\n        };\n        std::vector<State>\
    \ heap;\n        std::vector<Edge*> parent;\n        std::vector<usize> que_min;\n\
    \        std::vector<Cost> dist;\n        std::vector<char> seen;\n        Cost\
    \ farthest;\n        const auto dual = [&] {\n            over.erase(std::remove_if(over.begin(),\
    \ over.end(), [&](const usize u) { return gap[u] <= 0; }),\n                 \
    \      over.end());\n            lack.erase(std::remove_if(lack.begin(), lack.end(),\
    \ [&](const usize u) { return gap[u] >= 0; }),\n                       lack.end());\n\
    \            if (over.empty() or lack.empty()) return false;\n            dist.assign(size(),\
    \ std::numeric_limits<Cost>::max());\n            parent.assign(size(), nullptr);\n\
    \            seen.assign(size(), false);\n            que_min.clear();\n     \
    \       heap.clear();\n            usize heap_size = 0, lack_cnt = 0;\n      \
    \      farthest = 0;\n            for (const usize src : over) {\n           \
    \     dist[src] = 0;\n                que_min.push_back(src);\n            }\n\
    \            while (!que_min.empty() or !heap.empty()) {\n                usize\
    \ u;\n                if (!que_min.empty()) {\n                    u = que_min.back();\n\
    \                    que_min.pop_back();\n                } else {\n         \
    \           while (heap_size < heap.size()) {\n                        heap_size\
    \ += 1;\n                        std::push_heap(heap.begin(), heap.begin() + heap_size);\n\
    \                    }\n                    u = heap.front().vertex;\n       \
    \             std::pop_heap(heap.begin(), heap.end());\n                    heap.pop_back();\n\
    \                    heap_size -= 1;\n                }\n                if (seen[u])\
    \ continue;\n                seen[u] = true;\n                farthest = dist[u];\n\
    \                if (gap[u] < 0) {\n                    lack_cnt += 1;\n     \
    \               if (lack_cnt == lack.size()) break;\n                }\n     \
    \           for (const usize i : rep(0, graph[u].size())) {\n                \
    \    const Edge& e = graph[u][i];\n                    if (e.flow == e.cap) continue;\n\
    \                    const usize v = e.dst;\n                    if (setmin(dist[v],\
    \ dist[u] + e.cost + potential[u] - potential[v])) {\n                       \
    \ parent[v] = &graph[e.dst][e.rev];\n                        if (dist[v] == dist[u])\
    \ {\n                            que_min.push_back(v);\n                     \
    \   } else {\n                            heap.push_back(State{dist[v], v});\n\
    \                        }\n                    }\n                }\n       \
    \     }\n            if (lack_cnt == 0) return false;\n            for (const\
    \ usize u : rep(0, size())) {\n                potential[u] += std::min(farthest,\
    \ dist[u]);\n            }\n            return true;\n        };\n        while\
    \ (dual()) {\n            for (const usize dst : lack) {\n                if (dist[dst]\
    \ > farthest) continue;\n                Flow f = -gap[dst];\n               \
    \ usize u = dst;\n                while (parent[u] and f > 0) {\n            \
    \        const Edge& e = graph[parent[u]->dst][parent[u]->rev];\n            \
    \        setmin(f, e.cap - e.flow);\n                    u = parent[u]->dst;\n\
    \                }\n                setmin(f, gap[u]);\n                if (f\
    \ == 0) continue;\n                u = dst;\n                while (parent[u])\
    \ {\n                    Edge& e = graph[parent[u]->dst][parent[u]->rev];\n  \
    \                  e.flow += f;\n                    graph[e.dst][e.rev].flow\
    \ -= f;\n                    u = parent[u]->dst;\n                }\n        \
    \        gap[u] -= f;\n                gap[dst] += f;\n            }\n       \
    \ }\n        Result sum = 0;\n        for (const auto& v : graph) {\n        \
    \    for (const Edge& e : v) {\n                if (e.flow > 0) sum += (Result)e.flow\
    \ * (Result)e.cost;\n            }\n        }\n        return std::make_pair(sum,\
    \ over.empty() and lack.empty());\n    }\n\n    template <class Result = Cost>\
    \ std::pair<Flow, Result> flow(const usize src, const usize dst) {\n        return\
    \ flow<Result>(src, dst, std::numeric_limits<Flow>::max());\n    }\n    template\
    \ <class Result = Cost>\n    std::pair<Flow, Result> flow(const usize src, const\
    \ usize dst, const Flow flow_limit) {\n        assert(src != dst);\n        assert(std::all_of(gap.begin(),\
    \ gap.end(), [&](const Flow f) { return f == 0; }));\n        Flow inf_flow =\
    \ 0;\n        for (const Edge& e : graph[src]) inf_flow += std::max<Flow>(e.cap,\
    \ 0);\n        add_edge(dst, src, 0, inf_flow, 0);\n        assert(solve_bflow<Result>().second);\n\
    \        gap[src] = flow_limit;\n        gap[dst] = -flow_limit;\n        const\
    \ Result cost = solve_bflow<Result>().first;\n        const Flow flow = flow_limit\
    \ - gap[src];\n        graph[src].pop_back();\n        graph[dst].pop_back();\n\
    \        return std::make_pair(flow, cost);\n    }\n};\n#line 3 \"test/primal_dual_maxflow.test.cpp\"\
    \n#include <iostream>\n\nint main() {\n    usize N, M;\n    std::cin >> N >> M;\n\
    \    PrimalDual<i32, i32> graph(N);\n    while (M--) {\n        usize u, v;\n\
    \        i32 c;\n        std::cin >> u >> v >> c;\n        graph.add_edge(u, v,\
    \ 0, c, 0);\n    }\n    std::cout << graph.flow(0, N - 1).first << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\
    \n#include \"../graph/primal_dual.cpp\"\n#include <iostream>\n\nint main() {\n\
    \    usize N, M;\n    std::cin >> N >> M;\n    PrimalDual<i32, i32> graph(N);\n\
    \    while (M--) {\n        usize u, v;\n        i32 c;\n        std::cin >> u\
    \ >> v >> c;\n        graph.add_edge(u, v, 0, c, 0);\n    }\n    std::cout <<\
    \ graph.flow(0, N - 1).first << '\\n';\n}"
  dependsOn:
  - graph/primal_dual.cpp
  - utility/int_alias.cpp
  - utility/rep.cpp
  - utility/setmin.cpp
  isVerificationFile: true
  path: test/primal_dual_maxflow.test.cpp
  requiredBy: []
  timestamp: '2021-09-23 14:08:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/primal_dual_maxflow.test.cpp
layout: document
redirect_from:
- /verify/test/primal_dual_maxflow.test.cpp
- /verify/test/primal_dual_maxflow.test.cpp.html
title: test/primal_dual_maxflow.test.cpp
---
