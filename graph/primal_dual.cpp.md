---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utility/index_offset.cpp
    title: utility/index_offset.cpp
  - icon: ':question:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/primal_dual_maxflow.test.cpp
    title: test/primal_dual_maxflow.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/primal_dual_mincostflow.test.cpp
    title: test/primal_dual_mincostflow.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/primal_dual.cpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <limits>\n#include <type_traits>\n#include <vector>\n#line\
    \ 3 \"utility/index_offset.cpp\"\n\nclass IndexOffset {\n    int offset, len;\n\
    \n  public:\n    constexpr IndexOffset() noexcept : offset(), len() {}\n    explicit\
    \ constexpr IndexOffset(const int o, const int l) noexcept : offset(o), len(l)\
    \ {}\n    constexpr int size() const { return len; }\n    constexpr int operator[](const\
    \ int i) const noexcept {\n        assert(i < len);\n        return offset + i;\n\
    \    }\n    constexpr int to_idx(const int i) const noexcept {\n        assert(offset\
    \ <= i and i < offset + len);\n        return i - offset;\n    }\n};\n#line 3\
    \ \"utility/rep.cpp\"\n\nclass Range {\n    struct Iter {\n        int itr;\n\
    \        constexpr Iter(const int pos) noexcept : itr(pos) {}\n        constexpr\
    \ void operator++() noexcept { ++itr; }\n        constexpr bool operator!=(const\
    \ Iter& other) const noexcept { return itr != other.itr; }\n        constexpr\
    \ int operator*() const noexcept { return itr; }\n    };\n    const Iter first,\
    \ last;\n\n  public:\n    explicit constexpr Range(const int first, const int\
    \ last) noexcept : first(first), last(std::max(first, last)) {}\n    constexpr\
    \ Iter begin() const noexcept { return first; }\n    constexpr Iter end() const\
    \ noexcept { return last; }\n};\n\nconstexpr Range rep(const int l, const int\
    \ r) noexcept { return Range(l, r); }\nconstexpr Range rep(const int n) noexcept\
    \ { return Range(0, n); }\n#line 9 \"graph/primal_dual.cpp\"\n\ntemplate <class\
    \ Flow, class Cost> class PrimalDual {\n  public:\n    struct Edge {\n       \
    \ int src, dst;\n        Flow flow, cap;\n        Cost cost;\n    };\n\n  private:\n\
    \    int node_count;\n    std::vector<Edge> graph;\n    std::vector<Cost> potential;\n\
    \n  public:\n    PrimalDual() : node_count(0), graph() {}\n    explicit PrimalDual(const\
    \ int n) : node_count(n), graph() {}\n\n    int size() const { return node_count;\
    \ }\n    int edge_count() const { return graph.size(); }\n\n    int add_vertex()\
    \ { return node_count++; }\n    IndexOffset add_vertices(const int n) {\n    \
    \    assert(n >= 0);\n        const IndexOffset ret(size(), n);\n        node_count\
    \ += n;\n        return ret;\n    }\n\n    const Edge& get_edge(const int i) const\
    \ {\n        assert(0 <= i and i < edge_count());\n        return graph[i];\n\
    \    }\n    int add_edge(const int src, const int dst, const Flow& cap, const\
    \ Cost& cost) {\n        assert(0 <= src and src < size());\n        assert(0\
    \ <= dst and dst < size());\n        assert(cap >= 0);\n        graph.push_back(Edge{src,\
    \ dst, 0, cap, cost});\n        return edge_count() - 1;\n    }\n\n    Cost get_potential(const\
    \ int u) const {\n        assert(!potential.empty());\n        assert(0 <= u and\
    \ u < size());\n        return potential[u];\n    }\n    void set_potential(const\
    \ std::vector<Cost>& p) {\n        assert((int)p.size() == size());\n        for\
    \ (const auto& e : graph) {\n            if (e.cap == 0) continue;\n         \
    \   assert(e.cost - p[e.dst] + p[e.src] >= 0);\n        }\n        potential =\
    \ p;\n    }\n\n    std::pair<Flow, Cost> flow(const int src, const int dst) {\n\
    \        return flow(src, dst, std::numeric_limits<Flow>::max());\n    }\n   \
    \ std::pair<Flow, Cost> flow(const int src, const int dst, const Flow& flow_limit)\
    \ {\n        return slope(src, dst, flow_limit).back();\n    }\n    std::vector<std::pair<Flow,\
    \ Cost>> slope(const int src, const int dst) {\n        return slope(src, dst,\
    \ std::numeric_limits<Flow>::max());\n    }\n    std::vector<std::pair<Flow, Cost>>\
    \ slope(const int src, const int dst, const Flow& flow_limit) {\n        assert(0\
    \ <= src and src < size());\n        assert(0 <= dst and dst < size());\n    \
    \    assert(src != dst);\n        const int n = size();\n        const int m =\
    \ edge_count();\n        struct E {\n            int dst, rev;\n            Flow\
    \ cap;\n            Cost cost;\n        };\n        std::vector<E> edge(2 * m);\n\
    \        std::vector<int> start(n + 1), eidx(m);\n        {\n            std::vector<int>\
    \ deg(n), reidx(m);\n            for (const int i : rep(m)) {\n              \
    \  eidx[i] = deg[graph[i].src]++;\n                reidx[i] = deg[graph[i].dst]++;\n\
    \            }\n            for (const int i : rep(n)) start[i + 1] = start[i]\
    \ + deg[i];\n            for (const int i : rep(m)) {\n                const auto&\
    \ e = graph[i];\n                const int u = e.src, v = e.dst;\n           \
    \     eidx[i] += start[u];\n                reidx[i] += start[v];\n          \
    \      edge[eidx[i]] = {v, reidx[i], e.cap - e.flow, e.cost};\n              \
    \  edge[reidx[i]] = {u, eidx[i], e.flow, -e.cost};\n            }\n        }\n\
    \        if (potential.empty()) set_potential(std::vector<Cost>(n));\n       \
    \ std::vector<Cost> dist(n);\n        std::vector<int> prev_e(n);\n        std::vector<char>\
    \ visited(n);\n        struct Q {\n            Cost key;\n            int to;\n\
    \            bool operator<(const Q& r) const { return key > r.key; }\n      \
    \  };\n        std::vector<int> que_min;\n        std::vector<Q> que;\n      \
    \  const auto dual = [&]() {\n            for (const int i : rep(n)) dist[i] =\
    \ std::numeric_limits<Cost>::max();\n            std::fill(visited.begin(), visited.end(),\
    \ false);\n            que_min.clear();\n            que.clear();\n          \
    \  int heap_size = 0;\n            dist[src] = 0;\n            que_min.push_back(src);\n\
    \            while (!que_min.empty() || !que.empty()) {\n                int u;\n\
    \                if (!que_min.empty()) {\n                    u = que_min.back();\n\
    \                    que_min.pop_back();\n                } else {\n         \
    \           while (heap_size < (int)que.size()) {\n                        heap_size++;\n\
    \                        std::push_heap(que.begin(), que.begin() + heap_size);\n\
    \                    }\n                    u = que.front().to;\n            \
    \        std::pop_heap(que.begin(), que.end());\n                    que.pop_back();\n\
    \                    heap_size--;\n                }\n                if (visited[u])\
    \ continue;\n                visited[u] = true;\n                if (u == dst)\
    \ break;\n                for (const int i : rep(start[u], start[u + 1])) {\n\
    \                    const auto& e = edge[i];\n                    if (e.cap ==\
    \ 0) continue;\n                    const int v = e.dst;\n                   \
    \ const Cost cost = e.cost - potential[v] + potential[u];\n                  \
    \  if (dist[v] - dist[u] > cost) {\n                        dist[v] = dist[u]\
    \ + cost;\n                        prev_e[v] = e.rev;\n                      \
    \  if (cost == 0) {\n                            que_min.push_back(v);\n     \
    \                   } else {\n                            que.push_back(Q{dist[v],\
    \ v});\n                        }\n                    }\n                }\n\
    \            }\n            if (!visited[dst]) return false;\n            for\
    \ (const int u : rep(n)) {\n                if (!visited[u]) continue;\n     \
    \           potential[u] -= dist[dst] - dist[u];\n            }\n            return\
    \ true;\n        };\n        Flow flow = 0;\n        Cost cost = 0, ratio = -1;\n\
    \        std::vector<std::pair<Flow, Cost>> result = {{Flow(0), Cost(0)}};\n \
    \       while (flow < flow_limit) {\n            if (!dual()) break;\n       \
    \     Flow push = flow_limit - flow;\n            for (int u = dst; u != src;\
    \ u = edge[prev_e[u]].dst) {\n                push = std::min(push, edge[edge[prev_e[u]].rev].cap);\n\
    \            }\n            for (int u = dst; u != src; u = edge[prev_e[u]].dst)\
    \ {\n                auto& e = edge[prev_e[u]];\n                e.cap += push;\n\
    \                edge[e.rev].cap -= push;\n            }\n            const Cost\
    \ per_flow = potential[dst] - potential[src];\n            flow += push;\n   \
    \         cost += push * per_flow;\n            if (ratio == per_flow) result.pop_back();\n\
    \            result.emplace_back(flow, cost);\n            ratio = per_flow;\n\
    \        }\n        for (const int i : rep(m)) graph[i].flow = graph[i].cap -\
    \ edge[eidx[i]].cap;\n        return result;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <limits>\n\
    #include <type_traits>\n#include <vector>\n#include \"../utility/index_offset.cpp\"\
    \n#include \"../utility/rep.cpp\"\n\ntemplate <class Flow, class Cost> class PrimalDual\
    \ {\n  public:\n    struct Edge {\n        int src, dst;\n        Flow flow, cap;\n\
    \        Cost cost;\n    };\n\n  private:\n    int node_count;\n    std::vector<Edge>\
    \ graph;\n    std::vector<Cost> potential;\n\n  public:\n    PrimalDual() : node_count(0),\
    \ graph() {}\n    explicit PrimalDual(const int n) : node_count(n), graph() {}\n\
    \n    int size() const { return node_count; }\n    int edge_count() const { return\
    \ graph.size(); }\n\n    int add_vertex() { return node_count++; }\n    IndexOffset\
    \ add_vertices(const int n) {\n        assert(n >= 0);\n        const IndexOffset\
    \ ret(size(), n);\n        node_count += n;\n        return ret;\n    }\n\n  \
    \  const Edge& get_edge(const int i) const {\n        assert(0 <= i and i < edge_count());\n\
    \        return graph[i];\n    }\n    int add_edge(const int src, const int dst,\
    \ const Flow& cap, const Cost& cost) {\n        assert(0 <= src and src < size());\n\
    \        assert(0 <= dst and dst < size());\n        assert(cap >= 0);\n     \
    \   graph.push_back(Edge{src, dst, 0, cap, cost});\n        return edge_count()\
    \ - 1;\n    }\n\n    Cost get_potential(const int u) const {\n        assert(!potential.empty());\n\
    \        assert(0 <= u and u < size());\n        return potential[u];\n    }\n\
    \    void set_potential(const std::vector<Cost>& p) {\n        assert((int)p.size()\
    \ == size());\n        for (const auto& e : graph) {\n            if (e.cap ==\
    \ 0) continue;\n            assert(e.cost - p[e.dst] + p[e.src] >= 0);\n     \
    \   }\n        potential = p;\n    }\n\n    std::pair<Flow, Cost> flow(const int\
    \ src, const int dst) {\n        return flow(src, dst, std::numeric_limits<Flow>::max());\n\
    \    }\n    std::pair<Flow, Cost> flow(const int src, const int dst, const Flow&\
    \ flow_limit) {\n        return slope(src, dst, flow_limit).back();\n    }\n \
    \   std::vector<std::pair<Flow, Cost>> slope(const int src, const int dst) {\n\
    \        return slope(src, dst, std::numeric_limits<Flow>::max());\n    }\n  \
    \  std::vector<std::pair<Flow, Cost>> slope(const int src, const int dst, const\
    \ Flow& flow_limit) {\n        assert(0 <= src and src < size());\n        assert(0\
    \ <= dst and dst < size());\n        assert(src != dst);\n        const int n\
    \ = size();\n        const int m = edge_count();\n        struct E {\n       \
    \     int dst, rev;\n            Flow cap;\n            Cost cost;\n        };\n\
    \        std::vector<E> edge(2 * m);\n        std::vector<int> start(n + 1), eidx(m);\n\
    \        {\n            std::vector<int> deg(n), reidx(m);\n            for (const\
    \ int i : rep(m)) {\n                eidx[i] = deg[graph[i].src]++;\n        \
    \        reidx[i] = deg[graph[i].dst]++;\n            }\n            for (const\
    \ int i : rep(n)) start[i + 1] = start[i] + deg[i];\n            for (const int\
    \ i : rep(m)) {\n                const auto& e = graph[i];\n                const\
    \ int u = e.src, v = e.dst;\n                eidx[i] += start[u];\n          \
    \      reidx[i] += start[v];\n                edge[eidx[i]] = {v, reidx[i], e.cap\
    \ - e.flow, e.cost};\n                edge[reidx[i]] = {u, eidx[i], e.flow, -e.cost};\n\
    \            }\n        }\n        if (potential.empty()) set_potential(std::vector<Cost>(n));\n\
    \        std::vector<Cost> dist(n);\n        std::vector<int> prev_e(n);\n   \
    \     std::vector<char> visited(n);\n        struct Q {\n            Cost key;\n\
    \            int to;\n            bool operator<(const Q& r) const { return key\
    \ > r.key; }\n        };\n        std::vector<int> que_min;\n        std::vector<Q>\
    \ que;\n        const auto dual = [&]() {\n            for (const int i : rep(n))\
    \ dist[i] = std::numeric_limits<Cost>::max();\n            std::fill(visited.begin(),\
    \ visited.end(), false);\n            que_min.clear();\n            que.clear();\n\
    \            int heap_size = 0;\n            dist[src] = 0;\n            que_min.push_back(src);\n\
    \            while (!que_min.empty() || !que.empty()) {\n                int u;\n\
    \                if (!que_min.empty()) {\n                    u = que_min.back();\n\
    \                    que_min.pop_back();\n                } else {\n         \
    \           while (heap_size < (int)que.size()) {\n                        heap_size++;\n\
    \                        std::push_heap(que.begin(), que.begin() + heap_size);\n\
    \                    }\n                    u = que.front().to;\n            \
    \        std::pop_heap(que.begin(), que.end());\n                    que.pop_back();\n\
    \                    heap_size--;\n                }\n                if (visited[u])\
    \ continue;\n                visited[u] = true;\n                if (u == dst)\
    \ break;\n                for (const int i : rep(start[u], start[u + 1])) {\n\
    \                    const auto& e = edge[i];\n                    if (e.cap ==\
    \ 0) continue;\n                    const int v = e.dst;\n                   \
    \ const Cost cost = e.cost - potential[v] + potential[u];\n                  \
    \  if (dist[v] - dist[u] > cost) {\n                        dist[v] = dist[u]\
    \ + cost;\n                        prev_e[v] = e.rev;\n                      \
    \  if (cost == 0) {\n                            que_min.push_back(v);\n     \
    \                   } else {\n                            que.push_back(Q{dist[v],\
    \ v});\n                        }\n                    }\n                }\n\
    \            }\n            if (!visited[dst]) return false;\n            for\
    \ (const int u : rep(n)) {\n                if (!visited[u]) continue;\n     \
    \           potential[u] -= dist[dst] - dist[u];\n            }\n            return\
    \ true;\n        };\n        Flow flow = 0;\n        Cost cost = 0, ratio = -1;\n\
    \        std::vector<std::pair<Flow, Cost>> result = {{Flow(0), Cost(0)}};\n \
    \       while (flow < flow_limit) {\n            if (!dual()) break;\n       \
    \     Flow push = flow_limit - flow;\n            for (int u = dst; u != src;\
    \ u = edge[prev_e[u]].dst) {\n                push = std::min(push, edge[edge[prev_e[u]].rev].cap);\n\
    \            }\n            for (int u = dst; u != src; u = edge[prev_e[u]].dst)\
    \ {\n                auto& e = edge[prev_e[u]];\n                e.cap += push;\n\
    \                edge[e.rev].cap -= push;\n            }\n            const Cost\
    \ per_flow = potential[dst] - potential[src];\n            flow += push;\n   \
    \         cost += push * per_flow;\n            if (ratio == per_flow) result.pop_back();\n\
    \            result.emplace_back(flow, cost);\n            ratio = per_flow;\n\
    \        }\n        for (const int i : rep(m)) graph[i].flow = graph[i].cap -\
    \ edge[eidx[i]].cap;\n        return result;\n    }\n};"
  dependsOn:
  - utility/index_offset.cpp
  - utility/rep.cpp
  isVerificationFile: false
  path: graph/primal_dual.cpp
  requiredBy: []
  timestamp: '2022-01-07 21:48:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/primal_dual_mincostflow.test.cpp
  - test/primal_dual_maxflow.test.cpp
documentation_of: graph/primal_dual.cpp
layout: document
redirect_from:
- /library/graph/primal_dual.cpp
- /library/graph/primal_dual.cpp.html
title: graph/primal_dual.cpp
---
