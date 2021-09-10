---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: proconlib/int_alias:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <limits>\n\
    #include <queue>\n#include <type_traits>\n#include <vector>\n#include \"proconlib/int_alias\"\
    \n#include \"proconlib/rec_lambda\"\n\ntemplate <class Cap, std::enable_if_t<std::is_integral_v<Cap>>*\
    \ = nullptr> class Dinic {\n    struct Edge {\n        usize dst, rev;\n     \
    \   Cap cap;\n    };\n\n    std::vector<std::vector<Edge>> graph;\n\n  public:\n\
    \    Dinic() : graph() {}\n\n    class EdgePtr {\n        friend class Dinic;\n\
    \        Dinic* self;\n        usize u, e;\n\n        explicit EdgePtr(Dinic*\
    \ p, const usize u, const usize e) : self(p), u(u), e(e) {}\n\n        const Edge&\
    \ edge() const { return self->graph[u][e]; }\n        const Edge& rev_edge() const\
    \ { return self->graph[edge().dst][edge().rev]; }\n\n      public:\n        EdgePtr()\
    \ : self(nullptr), u(0), e(0) {}\n        usize src() const { return u; }\n  \
    \      usize dst() const { return edge().dst; }\n        Cap flow() const { return\
    \ rev_edge().cap; }\n        Cap capacity() const { return edge().cap + rev_edge().cap;\
    \ }\n    };\n\n    class VerList {\n        friend class Dinic;\n        usize\
    \ offset, len;\n        explicit VerList(const usize o, const usize l) : offset(o),\
    \ len(l) {}\n\n      public:\n        VerList() : offset(0), len(0) {}\n     \
    \   usize operator[](const usize i) const {\n            assert(i < len);\n  \
    \          return offset + i;\n        }\n        usize to_idx(const usize i)\
    \ const {\n            assert(offset <= i and i < offset + len);\n           \
    \ return i - offset;\n        }\n    };\n\n    usize size() const { return graph.size();\
    \ }\n\n    usize add_vertex() {\n        graph.emplace_back();\n        return\
    \ size() - 1;\n    }\n    VerList add_vertices(usize n) {\n        VerList ret{size(),\
    \ n};\n        while (n--) graph.emplace_back();\n        return ret;\n    }\n\
    \n    EdgePtr add_edge(const usize src, const usize dst, const Cap capacity) {\n\
    \        assert(src < size());\n        assert(dst < size());\n        assert(capacity\
    \ >= 0);\n        usize src_id = graph[src].size();\n        usize dst_id = graph[dst].size();\n\
    \        if (dst == src) dst_id += 1;\n        graph[src].push_back(Edge{dst,\
    \ dst_id, capacity});\n        graph[dst].push_back(Edge{src, src_id, 0});\n \
    \       return EdgePtr(this, src, src_id);\n    }\n\n    Cap flow(const usize\
    \ src, const usize dst) { return flow(src, dst, std::numeric_limits<Cap>::max());\
    \ }\n    Cap flow(const usize src, const usize dst, const Cap flow_limit) {\n\
    \        assert(src < size());\n        assert(dst < size());\n        assert(src\
    \ != dst);\n        std::vector<usize> level(size()), iter(size());\n        std::queue<usize>\
    \ que;\n        const auto bfs = [&] {\n            std::fill(level.begin(), level.end(),\
    \ size());\n            level[src] = 0;\n            while (!que.empty()) que.pop();\n\
    \            que.push(src);\n            while (!que.empty()) {\n            \
    \    const usize u = que.front();\n                que.pop();\n              \
    \  for (const Edge& e : graph[u]) {\n                    if (e.cap == 0 or level[e.dst]\
    \ < size()) continue;\n                    level[e.dst] = level[u] + 1;\n    \
    \                if (e.dst == dst) return;\n                    que.push(e.dst);\n\
    \                }\n            }\n        };\n        const auto dfs = rec_lambda([&](auto&&\
    \ dfs, const usize u, const Cap ub) -> Cap {\n            if (u == src) return\
    \ ub;\n            Cap ret = 0;\n            for (usize& i = iter[u]; i < graph[u].size();\
    \ i += 1) {\n                Edge& e = graph[u][i];\n                Edge& re\
    \ = graph[e.dst][e.rev];\n                if (level[u] <= level[e.dst] or re.cap\
    \ == 0) continue;\n                const Cap d = dfs(e.dst, std::min(ub - ret,\
    \ re.cap));\n                if (d == 0) continue;\n                e.cap += d;\n\
    \                re.cap -= d;\n                ret += d;\n                if (ret\
    \ == ub) return ret;\n            }\n            level[u] = size();\n        \
    \    return ret;\n        });\n        Cap ret = 0;\n        while (ret < flow_limit)\
    \ {\n            bfs();\n            if (level[dst] == size()) break;\n      \
    \      std::fill(iter.begin(), iter.end(), (usize)0);\n            const Cap f\
    \ = dfs(dst, flow_limit - ret);\n            if (f == 0) break;\n            ret\
    \ += f;\n        }\n        return ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/dinic.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dinic.cpp
layout: document
redirect_from:
- /library/graph/dinic.cpp
- /library/graph/dinic.cpp.html
title: graph/dinic.cpp
---
