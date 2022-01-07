---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: internal/simple_queue.cpp
    title: internal/simple_queue.cpp
  - icon: ':heavy_check_mark:'
    path: utility/index_offset.cpp
    title: utility/index_offset.cpp
  - icon: ':heavy_check_mark:'
    path: utility/rec_lambda.cpp
    title: utility/rec_lambda.cpp
  - icon: ':heavy_check_mark:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/binary_optimization.cpp
    title: graph/binary_optimization.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/bipartite_matching.test.cpp
    title: test/bipartite_matching.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/dinic.cpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <limits>\n#include <type_traits>\n#include <vector>\n#line 3 \"internal/simple_queue.cpp\"\
    \n\nnamespace proconlib {\n\ntemplate <class T> class SimpleQueue {\n    std::vector<T>\
    \ payload;\n    int pos;\n\n  public:\n    SimpleQueue() : payload(), pos(0) {}\n\
    \    explicit SimpleQueue(const int n) : SimpleQueue() { reserve(n); }\n\n   \
    \ int size() const { return (int)payload.size() - pos; }\n    bool empty() const\
    \ { return size() == 0; }\n    T& front() { return payload[pos]; }\n\n    void\
    \ push(const T& t) { payload.push_back(t); }\n    void push(T&& t) { payload.push_back(std::move(t));\
    \ }\n    void pop() { pos++; }\n\n    void reserve(int n) { payload.reserve(n);\
    \ }\n    void clear() {\n        payload.clear();\n        pos = 0;\n    }\n};\n\
    \n}  // namespace proconlib\n#line 3 \"utility/index_offset.cpp\"\n\nclass IndexOffset\
    \ {\n    int offset, len;\n\n  public:\n    constexpr IndexOffset() noexcept :\
    \ offset(), len() {}\n    explicit constexpr IndexOffset(const int o, const int\
    \ l) noexcept : offset(o), len(l) {}\n    constexpr int size() const { return\
    \ len; }\n    constexpr int operator[](const int i) const noexcept {\n       \
    \ assert(i < len);\n        return offset + i;\n    }\n    constexpr int to_idx(const\
    \ int i) const noexcept {\n        assert(offset <= i and i < offset + len);\n\
    \        return i - offset;\n    }\n};\n#line 3 \"utility/rec_lambda.cpp\"\n#include\
    \ <utility>\n\ntemplate <class F> struct RecursiveLambda : private F {\n    explicit\
    \ constexpr RecursiveLambda(F&& f) : F(std::forward<F>(f)) {}\n    template <class...\
    \ Args> constexpr decltype(auto) operator()(Args&&... args) const {\n        return\
    \ F::operator()(*this, std::forward<Args>(args)...);\n    }\n};\n\ntemplate <class\
    \ F> constexpr decltype(auto) rec_lambda(F&& f) { return RecursiveLambda<F>(std::forward<F>(f));\
    \ }\n#line 3 \"utility/rep.cpp\"\n\nclass Range {\n    struct Iter {\n       \
    \ int itr;\n        constexpr Iter(const int pos) noexcept : itr(pos) {}\n   \
    \     constexpr void operator++() noexcept { ++itr; }\n        constexpr bool\
    \ operator!=(const Iter& other) const noexcept { return itr != other.itr; }\n\
    \        constexpr int operator*() const noexcept { return itr; }\n    };\n  \
    \  const Iter first, last;\n\n  public:\n    explicit constexpr Range(const int\
    \ first, const int last) noexcept : first(first), last(std::max(first, last))\
    \ {}\n    constexpr Iter begin() const noexcept { return first; }\n    constexpr\
    \ Iter end() const noexcept { return last; }\n};\n\nconstexpr Range rep(const\
    \ int l, const int r) noexcept { return Range(l, r); }\nconstexpr Range rep(const\
    \ int n) noexcept { return Range(0, n); }\n#line 11 \"graph/dinic.cpp\"\n\ntemplate\
    \ <class Flow, std::enable_if_t<std::is_integral_v<Flow>>* = nullptr> class Dinic\
    \ {\n  public:\n    struct Edge {\n        int src, dst;\n        Flow flow, cap;\n\
    \    };\n\n  private:\n    int node_count;\n    std::vector<Edge> graph;\n\n \
    \ public:\n    Dinic() : node_count(0), graph() {}\n    explicit Dinic(const int\
    \ n) : node_count(n), graph() {}\n\n    int size() const { return node_count;\
    \ }\n    int edge_count() const { return graph.size(); }\n\n    int add_vertex()\
    \ { return node_count++; }\n    IndexOffset add_vertices(const int n) {\n    \
    \    assert(n >= 0);\n        const IndexOffset ret(size(), n);\n        node_count\
    \ += n;\n        return ret;\n    }\n\n    const Edge& get_edge(const int i) const\
    \ { \n        assert(0 <= i and i < edge_count());\n        return graph[i]; \n\
    \    }\n    int add_edge(const int src, const int dst, const Flow& cap) {\n  \
    \      assert(0 <= src and src < size());\n        assert(0 <= dst and dst < size());\n\
    \        assert(cap >= 0);\n        graph.push_back(Edge{src, dst, 0, cap});\n\
    \        return edge_count() - 1;\n    }\n\n    Flow flow(const int src, const\
    \ int dst) { return flow(src, dst, std::numeric_limits<Flow>::max()); }\n    Flow\
    \ flow(const int src, const int dst, const Flow& flow_limit) {\n        assert(0\
    \ <= src and src < size());\n        assert(0 <= dst and dst < size());\n    \
    \    assert(src != dst);\n        const int n = size();\n        const int m =\
    \ edge_count();\n        struct E {\n            int dst, rev;\n            Flow\
    \ cap;\n        };\n        std::vector<E> edge(2 * m);\n        std::vector<int>\
    \ start(n + 1), eidx(m);\n        {\n            std::vector<int> deg(n), reidx(m);\n\
    \            for (const int i : rep(m)) {\n                eidx[i] = deg[graph[i].src]++;\n\
    \                reidx[i] = deg[graph[i].dst]++;\n            }\n            for\
    \ (const int i : rep(n)) start[i + 1] = start[i] + deg[i];\n            for (const\
    \ int i : rep(m)) {\n                const auto& e = graph[i];\n             \
    \   const int u = e.src, v = e.dst;\n                eidx[i] += start[u];\n  \
    \              reidx[i] += start[v];\n                edge[eidx[i]] = {v, reidx[i],\
    \ e.cap - e.flow};\n                edge[reidx[i]] = {u, eidx[i], e.flow};\n \
    \           }\n        }\n        std::vector<int> level(n), iter(n);\n      \
    \  proconlib::SimpleQueue<int> que;\n        const auto bfs = [&] {\n        \
    \    std::fill(level.begin(), level.end(), n);\n            level[src] = 0;\n\
    \            while (!que.empty()) que.pop();\n            que.push(src);\n   \
    \         while (!que.empty()) {\n                const int u = que.front();\n\
    \                que.pop();\n                for (const int i : rep(start[u],\
    \ start[u + 1])) {\n                    const auto& e = edge[i];\n           \
    \         if (e.cap == 0 or level[e.dst] < n) continue;\n                    level[e.dst]\
    \ = level[u] + 1;\n                    if (e.dst == dst) return;\n           \
    \         que.push(e.dst);\n                }\n            }\n        };\n   \
    \     const auto dfs = rec_lambda([&](auto&& dfs, const int u, const Flow& ub)\
    \ -> Flow {\n            if (u == src) return ub;\n            Flow ret = 0;\n\
    \            for (int& i = iter[u]; i < start[u + 1]; i += 1) {\n            \
    \    auto& e = edge[i];\n                auto& re = edge[e.rev];\n           \
    \     if (level[u] <= level[e.dst] or re.cap == 0) continue;\n               \
    \ const Flow d = dfs(e.dst, std::min(ub - ret, re.cap));\n                if (d\
    \ == 0) continue;\n                e.cap += d;\n                re.cap -= d;\n\
    \                ret += d;\n                if (ret == ub) return ret;\n     \
    \       }\n            level[u] = n;\n            return ret;\n        });\n \
    \       Flow ret = 0;\n        while (ret < flow_limit) {\n            bfs();\n\
    \            if (level[dst] == n) break;\n            std::copy(start.begin(),\
    \ start.begin() + n, iter.begin());\n            const Flow f = dfs(dst, flow_limit\
    \ - ret);\n            if (f == 0) break;\n            ret += f;\n        }\n\
    \        for (const int i : rep(m)) graph[i].flow = graph[i].cap - edge[eidx[i]].cap;\n\
    \        return ret;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <limits>\n\
    #include <type_traits>\n#include <vector>\n#include \"../internal/simple_queue.cpp\"\
    \n#include \"../utility/index_offset.cpp\"\n#include \"../utility/rec_lambda.cpp\"\
    \n#include \"../utility/rep.cpp\"\n\ntemplate <class Flow, std::enable_if_t<std::is_integral_v<Flow>>*\
    \ = nullptr> class Dinic {\n  public:\n    struct Edge {\n        int src, dst;\n\
    \        Flow flow, cap;\n    };\n\n  private:\n    int node_count;\n    std::vector<Edge>\
    \ graph;\n\n  public:\n    Dinic() : node_count(0), graph() {}\n    explicit Dinic(const\
    \ int n) : node_count(n), graph() {}\n\n    int size() const { return node_count;\
    \ }\n    int edge_count() const { return graph.size(); }\n\n    int add_vertex()\
    \ { return node_count++; }\n    IndexOffset add_vertices(const int n) {\n    \
    \    assert(n >= 0);\n        const IndexOffset ret(size(), n);\n        node_count\
    \ += n;\n        return ret;\n    }\n\n    const Edge& get_edge(const int i) const\
    \ { \n        assert(0 <= i and i < edge_count());\n        return graph[i]; \n\
    \    }\n    int add_edge(const int src, const int dst, const Flow& cap) {\n  \
    \      assert(0 <= src and src < size());\n        assert(0 <= dst and dst < size());\n\
    \        assert(cap >= 0);\n        graph.push_back(Edge{src, dst, 0, cap});\n\
    \        return edge_count() - 1;\n    }\n\n    Flow flow(const int src, const\
    \ int dst) { return flow(src, dst, std::numeric_limits<Flow>::max()); }\n    Flow\
    \ flow(const int src, const int dst, const Flow& flow_limit) {\n        assert(0\
    \ <= src and src < size());\n        assert(0 <= dst and dst < size());\n    \
    \    assert(src != dst);\n        const int n = size();\n        const int m =\
    \ edge_count();\n        struct E {\n            int dst, rev;\n            Flow\
    \ cap;\n        };\n        std::vector<E> edge(2 * m);\n        std::vector<int>\
    \ start(n + 1), eidx(m);\n        {\n            std::vector<int> deg(n), reidx(m);\n\
    \            for (const int i : rep(m)) {\n                eidx[i] = deg[graph[i].src]++;\n\
    \                reidx[i] = deg[graph[i].dst]++;\n            }\n            for\
    \ (const int i : rep(n)) start[i + 1] = start[i] + deg[i];\n            for (const\
    \ int i : rep(m)) {\n                const auto& e = graph[i];\n             \
    \   const int u = e.src, v = e.dst;\n                eidx[i] += start[u];\n  \
    \              reidx[i] += start[v];\n                edge[eidx[i]] = {v, reidx[i],\
    \ e.cap - e.flow};\n                edge[reidx[i]] = {u, eidx[i], e.flow};\n \
    \           }\n        }\n        std::vector<int> level(n), iter(n);\n      \
    \  proconlib::SimpleQueue<int> que;\n        const auto bfs = [&] {\n        \
    \    std::fill(level.begin(), level.end(), n);\n            level[src] = 0;\n\
    \            while (!que.empty()) que.pop();\n            que.push(src);\n   \
    \         while (!que.empty()) {\n                const int u = que.front();\n\
    \                que.pop();\n                for (const int i : rep(start[u],\
    \ start[u + 1])) {\n                    const auto& e = edge[i];\n           \
    \         if (e.cap == 0 or level[e.dst] < n) continue;\n                    level[e.dst]\
    \ = level[u] + 1;\n                    if (e.dst == dst) return;\n           \
    \         que.push(e.dst);\n                }\n            }\n        };\n   \
    \     const auto dfs = rec_lambda([&](auto&& dfs, const int u, const Flow& ub)\
    \ -> Flow {\n            if (u == src) return ub;\n            Flow ret = 0;\n\
    \            for (int& i = iter[u]; i < start[u + 1]; i += 1) {\n            \
    \    auto& e = edge[i];\n                auto& re = edge[e.rev];\n           \
    \     if (level[u] <= level[e.dst] or re.cap == 0) continue;\n               \
    \ const Flow d = dfs(e.dst, std::min(ub - ret, re.cap));\n                if (d\
    \ == 0) continue;\n                e.cap += d;\n                re.cap -= d;\n\
    \                ret += d;\n                if (ret == ub) return ret;\n     \
    \       }\n            level[u] = n;\n            return ret;\n        });\n \
    \       Flow ret = 0;\n        while (ret < flow_limit) {\n            bfs();\n\
    \            if (level[dst] == n) break;\n            std::copy(start.begin(),\
    \ start.begin() + n, iter.begin());\n            const Flow f = dfs(dst, flow_limit\
    \ - ret);\n            if (f == 0) break;\n            ret += f;\n        }\n\
    \        for (const int i : rep(m)) graph[i].flow = graph[i].cap - edge[eidx[i]].cap;\n\
    \        return ret;\n    }\n};"
  dependsOn:
  - internal/simple_queue.cpp
  - utility/index_offset.cpp
  - utility/rec_lambda.cpp
  - utility/rep.cpp
  isVerificationFile: false
  path: graph/dinic.cpp
  requiredBy:
  - graph/binary_optimization.cpp
  timestamp: '2022-01-07 21:48:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/bipartite_matching.test.cpp
documentation_of: graph/dinic.cpp
layout: document
redirect_from:
- /library/graph/dinic.cpp
- /library/graph/dinic.cpp.html
title: graph/dinic.cpp
---
