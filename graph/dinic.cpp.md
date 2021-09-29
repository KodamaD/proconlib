---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':heavy_check_mark:'
    path: utility/rec_lambda.cpp
    title: utility/rec_lambda.cpp
  _extendedRequiredBy: []
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
    #include <limits>\n#include <queue>\n#include <type_traits>\n#include <vector>\n\
    #line 2 \"utility/int_alias.cpp\"\n#include <cstddef>\n#include <cstdint>\n\n\
    using i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing isize = std::ptrdiff_t;\nusing usize = std::size_t;\n\
    #line 3 \"utility/rec_lambda.cpp\"\n#include <utility>\n\ntemplate <class F> struct\
    \ RecursiveLambda : private F {\n    explicit constexpr RecursiveLambda(F&& f)\
    \ : F(std::forward<F>(f)) {}\n    template <class... Args> constexpr decltype(auto)\
    \ operator()(Args&&... args) const {\n        return F::operator()(*this, std::forward<Args>(args)...);\n\
    \    }\n};\n\ntemplate <class F> constexpr decltype(auto) rec_lambda(F&& f) {\n\
    \    using G = std::decay_t<F>;\n    return RecursiveLambda<G>(std::forward<G>(f));\n\
    }\n#line 10 \"graph/dinic.cpp\"\n\ntemplate <class Flow, std::enable_if_t<std::is_integral_v<Flow>>*\
    \ = nullptr> class Dinic {\n    struct Edge {\n        usize dst, rev;\n     \
    \   Flow cap;\n    };\n\n    std::vector<std::vector<Edge>> graph;\n\n  public:\n\
    \    Dinic() : graph() {}\n    explicit Dinic(const usize n) : graph(n) {}\n\n\
    \    class EdgePtr {\n        friend class Dinic;\n        Dinic* self;\n    \
    \    usize u, e;\n\n        explicit EdgePtr(Dinic* p, const usize u, const usize\
    \ e) : self(p), u(u), e(e) {}\n\n        const Edge& edge() const { return self->graph[u][e];\
    \ }\n        const Edge& rev_edge() const { return self->graph[edge().dst][edge().rev];\
    \ }\n\n      public:\n        EdgePtr() : self(nullptr), u(0), e(0) {}\n     \
    \   usize src() const { return u; }\n        usize dst() const { return edge().dst;\
    \ }\n        Flow flow() const { return rev_edge().cap; }\n        Flow cap()\
    \ const { return edge().cap + rev_edge().cap; }\n    };\n\n    class Vertices\
    \ {\n        friend class Dinic;\n        usize offset, len;\n        explicit\
    \ Vertices(const usize o, const usize l) : offset(o), len(l) {}\n\n      public:\n\
    \        Vertices() : offset(0), len(0) {}\n        usize operator[](const usize\
    \ i) const {\n            assert(i < len);\n            return offset + i;\n \
    \       }\n        usize to_idx(const usize i) const {\n            assert(offset\
    \ <= i and i < offset + len);\n            return i - offset;\n        }\n   \
    \ };\n\n    usize size() const { return graph.size(); }\n\n    usize add_vertex()\
    \ {\n        graph.emplace_back();\n        return size() - 1;\n    }\n    Vertices\
    \ add_vertices(usize n) {\n        Vertices ret{size(), n};\n        while (n--)\
    \ graph.emplace_back();\n        return ret;\n    }\n\n    EdgePtr add_edge(const\
    \ usize src, const usize dst, const Flow cap) {\n        assert(src < size());\n\
    \        assert(dst < size());\n        assert(cap >= 0);\n        const usize\
    \ src_id = graph[src].size();\n        const usize dst_id = graph[dst].size()\
    \ + (src == dst);\n        graph[src].push_back(Edge{dst, dst_id, cap});\n   \
    \     graph[dst].push_back(Edge{src, src_id, 0});\n        return EdgePtr(this,\
    \ src, src_id);\n    }\n\n    Flow flow(const usize src, const usize dst) { return\
    \ flow(src, dst, std::numeric_limits<Flow>::max()); }\n    Flow flow(const usize\
    \ src, const usize dst, const Flow flow_limit) {\n        assert(src < size());\n\
    \        assert(dst < size());\n        assert(src != dst);\n        std::vector<usize>\
    \ level(size()), iter(size());\n        std::queue<usize> que;\n        const\
    \ auto bfs = [&] {\n            std::fill(level.begin(), level.end(), size());\n\
    \            level[src] = 0;\n            while (!que.empty()) que.pop();\n  \
    \          que.push(src);\n            while (!que.empty()) {\n              \
    \  const usize u = que.front();\n                que.pop();\n                for\
    \ (const Edge& e : graph[u]) {\n                    if (e.cap == 0 or level[e.dst]\
    \ < size()) continue;\n                    level[e.dst] = level[u] + 1;\n    \
    \                if (e.dst == dst) return;\n                    que.push(e.dst);\n\
    \                }\n            }\n        };\n        const auto dfs = rec_lambda([&](auto&&\
    \ dfs, const usize u, const Flow ub) -> Flow {\n            if (u == src) return\
    \ ub;\n            Flow ret = 0;\n            for (usize& i = iter[u]; i < graph[u].size();\
    \ i += 1) {\n                Edge& e = graph[u][i];\n                Edge& re\
    \ = graph[e.dst][e.rev];\n                if (level[u] <= level[e.dst] or re.cap\
    \ == 0) continue;\n                const Flow d = dfs(e.dst, std::min(ub - ret,\
    \ re.cap));\n                if (d == 0) continue;\n                e.cap += d;\n\
    \                re.cap -= d;\n                ret += d;\n                if (ret\
    \ == ub) return ret;\n            }\n            level[u] = size();\n        \
    \    return ret;\n        });\n        Flow ret = 0;\n        while (ret < flow_limit)\
    \ {\n            bfs();\n            if (level[dst] == size()) break;\n      \
    \      std::fill(iter.begin(), iter.end(), (usize)0);\n            const Flow\
    \ f = dfs(dst, flow_limit - ret);\n            if (f == 0) break;\n          \
    \  ret += f;\n        }\n        return ret;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <limits>\n\
    #include <queue>\n#include <type_traits>\n#include <vector>\n#include \"../utility/int_alias.cpp\"\
    \n#include \"../utility/rec_lambda.cpp\"\n\ntemplate <class Flow, std::enable_if_t<std::is_integral_v<Flow>>*\
    \ = nullptr> class Dinic {\n    struct Edge {\n        usize dst, rev;\n     \
    \   Flow cap;\n    };\n\n    std::vector<std::vector<Edge>> graph;\n\n  public:\n\
    \    Dinic() : graph() {}\n    explicit Dinic(const usize n) : graph(n) {}\n\n\
    \    class EdgePtr {\n        friend class Dinic;\n        Dinic* self;\n    \
    \    usize u, e;\n\n        explicit EdgePtr(Dinic* p, const usize u, const usize\
    \ e) : self(p), u(u), e(e) {}\n\n        const Edge& edge() const { return self->graph[u][e];\
    \ }\n        const Edge& rev_edge() const { return self->graph[edge().dst][edge().rev];\
    \ }\n\n      public:\n        EdgePtr() : self(nullptr), u(0), e(0) {}\n     \
    \   usize src() const { return u; }\n        usize dst() const { return edge().dst;\
    \ }\n        Flow flow() const { return rev_edge().cap; }\n        Flow cap()\
    \ const { return edge().cap + rev_edge().cap; }\n    };\n\n    class Vertices\
    \ {\n        friend class Dinic;\n        usize offset, len;\n        explicit\
    \ Vertices(const usize o, const usize l) : offset(o), len(l) {}\n\n      public:\n\
    \        Vertices() : offset(0), len(0) {}\n        usize operator[](const usize\
    \ i) const {\n            assert(i < len);\n            return offset + i;\n \
    \       }\n        usize to_idx(const usize i) const {\n            assert(offset\
    \ <= i and i < offset + len);\n            return i - offset;\n        }\n   \
    \ };\n\n    usize size() const { return graph.size(); }\n\n    usize add_vertex()\
    \ {\n        graph.emplace_back();\n        return size() - 1;\n    }\n    Vertices\
    \ add_vertices(usize n) {\n        Vertices ret{size(), n};\n        while (n--)\
    \ graph.emplace_back();\n        return ret;\n    }\n\n    EdgePtr add_edge(const\
    \ usize src, const usize dst, const Flow cap) {\n        assert(src < size());\n\
    \        assert(dst < size());\n        assert(cap >= 0);\n        const usize\
    \ src_id = graph[src].size();\n        const usize dst_id = graph[dst].size()\
    \ + (src == dst);\n        graph[src].push_back(Edge{dst, dst_id, cap});\n   \
    \     graph[dst].push_back(Edge{src, src_id, 0});\n        return EdgePtr(this,\
    \ src, src_id);\n    }\n\n    Flow flow(const usize src, const usize dst) { return\
    \ flow(src, dst, std::numeric_limits<Flow>::max()); }\n    Flow flow(const usize\
    \ src, const usize dst, const Flow flow_limit) {\n        assert(src < size());\n\
    \        assert(dst < size());\n        assert(src != dst);\n        std::vector<usize>\
    \ level(size()), iter(size());\n        std::queue<usize> que;\n        const\
    \ auto bfs = [&] {\n            std::fill(level.begin(), level.end(), size());\n\
    \            level[src] = 0;\n            while (!que.empty()) que.pop();\n  \
    \          que.push(src);\n            while (!que.empty()) {\n              \
    \  const usize u = que.front();\n                que.pop();\n                for\
    \ (const Edge& e : graph[u]) {\n                    if (e.cap == 0 or level[e.dst]\
    \ < size()) continue;\n                    level[e.dst] = level[u] + 1;\n    \
    \                if (e.dst == dst) return;\n                    que.push(e.dst);\n\
    \                }\n            }\n        };\n        const auto dfs = rec_lambda([&](auto&&\
    \ dfs, const usize u, const Flow ub) -> Flow {\n            if (u == src) return\
    \ ub;\n            Flow ret = 0;\n            for (usize& i = iter[u]; i < graph[u].size();\
    \ i += 1) {\n                Edge& e = graph[u][i];\n                Edge& re\
    \ = graph[e.dst][e.rev];\n                if (level[u] <= level[e.dst] or re.cap\
    \ == 0) continue;\n                const Flow d = dfs(e.dst, std::min(ub - ret,\
    \ re.cap));\n                if (d == 0) continue;\n                e.cap += d;\n\
    \                re.cap -= d;\n                ret += d;\n                if (ret\
    \ == ub) return ret;\n            }\n            level[u] = size();\n        \
    \    return ret;\n        });\n        Flow ret = 0;\n        while (ret < flow_limit)\
    \ {\n            bfs();\n            if (level[dst] == size()) break;\n      \
    \      std::fill(iter.begin(), iter.end(), (usize)0);\n            const Flow\
    \ f = dfs(dst, flow_limit - ret);\n            if (f == 0) break;\n          \
    \  ret += f;\n        }\n        return ret;\n    }\n};\n"
  dependsOn:
  - utility/int_alias.cpp
  - utility/rec_lambda.cpp
  isVerificationFile: false
  path: graph/dinic.cpp
  requiredBy: []
  timestamp: '2021-09-17 22:43:40+09:00'
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
