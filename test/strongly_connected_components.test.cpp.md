---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/basic_graph.cpp
    title: graph/basic_graph.cpp
  - icon: ':heavy_check_mark:'
    path: graph/strongly_connected_components.cpp
    title: graph/strongly_connected_components.cpp
  - icon: ':heavy_check_mark:'
    path: utility/index_offset.cpp
    title: utility/index_offset.cpp
  - icon: ':heavy_check_mark:'
    path: utility/rec_lambda.cpp
    title: utility/rec_lambda.cpp
  - icon: ':question:'
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
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/strongly_connected_components.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/scc\"\n#line 2 \"graph/strongly_connected_components.cpp\"\
    \n#include <cassert>\n#include <vector>\n#line 2 \"utility/rec_lambda.cpp\"\n\
    #include <type_traits>\n#include <utility>\n\ntemplate <class F> struct RecursiveLambda\
    \ : private F {\n    explicit constexpr RecursiveLambda(F&& f) : F(std::forward<F>(f))\
    \ {}\n    template <class... Args> constexpr decltype(auto) operator()(Args&&...\
    \ args) const {\n        return F::operator()(*this, std::forward<Args>(args)...);\n\
    \    }\n};\n\ntemplate <class F> constexpr decltype(auto) rec_lambda(F&& f) {\
    \ return RecursiveLambda<F>(std::forward<F>(f)); }\n#line 2 \"utility/rep.cpp\"\
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
    \ { return Range(0, n); }\n#line 2 \"utility/setmin.cpp\"\n\ntemplate <class T>\
    \ bool setmin(T& lhs, const T& rhs) {\n    if (lhs > rhs) {\n        lhs = rhs;\n\
    \        return true;\n    }\n    return false;\n}\n#line 7 \"graph/strongly_connected_components.cpp\"\
    \n\ntemplate <class G> class StronglyConnectedComponents {\n    int count;\n \
    \   std::vector<int> index;\n\n  public:\n    StronglyConnectedComponents() :\
    \ count(0), index() {}\n    explicit StronglyConnectedComponents(const G& graph)\
    \ : count(0), index(graph.size()) {\n        const int n = size();\n        int\
    \ time_stamp = 0;\n        std::vector<int> visited, low(n), ord(n);\n       \
    \ visited.reserve(n);\n        const auto dfs = rec_lambda([&](auto&& dfs, const\
    \ int u) -> void {\n            low[u] = ord[u] = ++time_stamp;\n            visited.push_back(u);\n\
    \            for (const int v : graph[u]) {\n                if (!ord[v]) {\n\
    \                    dfs(v);\n                    setmin(low[u], low[v]);\n  \
    \              } else {\n                    setmin(low[u], ord[v]);\n       \
    \         }\n            }\n            if (low[u] == ord[u]) {\n            \
    \    while (true) {\n                    const int v = visited.back();\n     \
    \               visited.pop_back();\n                    ord[v] = n;\n       \
    \             index[v] = count;\n                    if (u == v) break;\n    \
    \            }\n                count += 1;\n            }\n        });\n    \
    \    for (const int u : rep(n))\n            if (!ord[u]) dfs(u);\n        for\
    \ (auto& x : index) x = count - x - 1;\n    }\n\n    int size() const { return\
    \ index.size(); }\n    int group_count() const { return count; }\n    int group_id(const\
    \ int u) const {\n        assert(0 <= u and u < size());\n        return index[u];\n\
    \    }\n\n    std::vector<std::vector<int>> decopmose() const {\n        std::vector<std::vector<int>>\
    \ ret(group_count());\n        for (const int u : rep(size())) ret[index[u]].push_back(u);\n\
    \        return ret;\n    }\n};\n#line 3 \"utility/index_offset.cpp\"\n\nclass\
    \ IndexOffset {\n    int offset, len;\n\n  public:\n    constexpr IndexOffset()\
    \ noexcept : offset(), len() {}\n    explicit constexpr IndexOffset(const int\
    \ o, const int l) noexcept : offset(o), len(l) {}\n    constexpr int size() const\
    \ { return len; }\n    constexpr int operator[](const int i) const noexcept {\n\
    \        assert(i < len);\n        return offset + i;\n    }\n    constexpr int\
    \ to_idx(const int i) const noexcept {\n        assert(offset <= i and i < offset\
    \ + len);\n        return i - offset;\n    }\n};\n#line 6 \"graph/basic_graph.cpp\"\
    \n\ntemplate <class E = int> class BasicGraph {\n    std::vector<std::vector<E>>\
    \ graph;\n\n  public:\n    BasicGraph() : graph() {}\n    explicit BasicGraph(const\
    \ int n) : graph(n) {}\n\n    class EdgePtr {\n        friend class BasicGraph;\n\
    \        int u, e;\n        BasicGraph* self;\n\n        explicit EdgePtr(const\
    \ int u, const int e, BasicGraph* p) : u(u), e(e), self(p) {}\n\n      public:\n\
    \        EdgePtr() : u(0), e(0), self(nullptr) {}\n        int src() const { return\
    \ u; }\n        E& operator*() const { return self->graph[u][e]; }\n        E*\
    \ operator->() const { return &self->graph[u][e]; }\n    };\n\n    int size()\
    \ const { return graph.size(); }\n    std::vector<E>& operator[](const int u)\
    \ {\n        assert(0 <= u and u < size());\n        return graph[u];\n    }\n\
    \    const std::vector<E>& operator[](const int u) const {\n        assert(0 <=\
    \ u and u < size());\n        return graph[u];\n    }\n\n    int add_vertex()\
    \ {\n        graph.emplace_back();\n        return size() - 1;\n    }\n    IndexOffset\
    \ add_vertices(int n) {\n        IndexOffset ret(size(), n);\n        while (n--)\
    \ graph.emplace_back();\n        return ret;\n    }\n\n    template <class...\
    \ Args> EdgePtr add_edge(const int u, Args&&... args) {\n        assert(0 <= u\
    \ and u < size());\n        const int e = graph[u].size();\n        graph[u].emplace_back(std::forward<Args>(args)...);\n\
    \        return EdgePtr(u, e, this);\n    }\n};\n#line 4 \"test/strongly_connected_components.test.cpp\"\
    \n#include <iostream>\n\nint main() {\n    int N, M;\n    std::cin >> N >> M;\n\
    \    BasicGraph graph(N);\n    while (M--) {\n        int a, b;\n        std::cin\
    \ >> a >> b;\n        graph.add_edge(a, b);\n    }\n    const auto ans = StronglyConnectedComponents(graph).decopmose();\n\
    \    std::cout << ans.size() << '\\n';\n    for (const auto& v : ans) {\n    \
    \    std::cout << v.size();\n        for (const auto x : v) {\n            std::cout\
    \ << ' ' << x;\n        }\n        std::cout << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n#include \"../graph/strongly_connected_components.cpp\"\
    \n#include \"../graph/basic_graph.cpp\"\n#include <iostream>\n\nint main() {\n\
    \    int N, M;\n    std::cin >> N >> M;\n    BasicGraph graph(N);\n    while (M--)\
    \ {\n        int a, b;\n        std::cin >> a >> b;\n        graph.add_edge(a,\
    \ b);\n    }\n    const auto ans = StronglyConnectedComponents(graph).decopmose();\n\
    \    std::cout << ans.size() << '\\n';\n    for (const auto& v : ans) {\n    \
    \    std::cout << v.size();\n        for (const auto x : v) {\n            std::cout\
    \ << ' ' << x;\n        }\n        std::cout << '\\n';\n    }\n}"
  dependsOn:
  - graph/strongly_connected_components.cpp
  - utility/rec_lambda.cpp
  - utility/rep.cpp
  - utility/setmin.cpp
  - graph/basic_graph.cpp
  - utility/index_offset.cpp
  isVerificationFile: true
  path: test/strongly_connected_components.test.cpp
  requiredBy: []
  timestamp: '2021-12-28 21:38:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/strongly_connected_components.test.cpp
layout: document
redirect_from:
- /verify/test/strongly_connected_components.test.cpp
- /verify/test/strongly_connected_components.test.cpp.html
title: test/strongly_connected_components.test.cpp
---
