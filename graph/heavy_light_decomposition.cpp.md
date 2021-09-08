---
data:
  _extendedDependsOn:
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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/heavy_light_decomposition.test.cpp
    title: test/heavy_light_decomposition.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/heavy_light_decomposition.cpp\"\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n#line 2 \"utility/int_alias.cpp\"\n#include\
    \ <cstddef>\n#include <cstdint>\n\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\n\
    using i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing isize = std::ptrdiff_t;\n\
    using usize = std::size_t;\n#line 2 \"utility/rec_lambda.cpp\"\n#include <type_traits>\n\
    #line 4 \"utility/rec_lambda.cpp\"\n\ntemplate <class F> struct RecursiveLambda\
    \ : private F {\n    explicit constexpr RecursiveLambda(F&& f) : F(std::forward<F>(f))\
    \ {}\n    template <class... Args> constexpr decltype(auto) operator()(Args&&...\
    \ args) const {\n        return F::operator()(*this, std::forward<Args>(args)...);\n\
    \    }\n};\n\ntemplate <class F> constexpr decltype(auto) rec_lambda(F&& f) {\n\
    \    using G = std::decay_t<F>;\n    return RecursiveLambda<G>(std::forward<G>(f));\n\
    }\n#line 2 \"utility/rep.cpp\"\n#include <algorithm>\n#line 4 \"utility/rep.cpp\"\
    \n\nclass rep {\n    struct Iter {\n        usize itr;\n        constexpr Iter(const\
    \ usize pos) noexcept : itr(pos) {}\n        constexpr void operator++() noexcept\
    \ { ++itr; }\n        constexpr bool operator!=(const Iter& other) const noexcept\
    \ { return itr != other.itr; }\n        constexpr usize operator*() const noexcept\
    \ { return itr; }\n    };\n    const Iter first, last;\n\n  public:\n    explicit\
    \ constexpr rep(const usize first, const usize last) noexcept : first(first),\
    \ last(std::max(first, last)) {}\n    constexpr Iter begin() const noexcept {\
    \ return first; }\n    constexpr Iter end() const noexcept { return last; }\n\
    };\n#line 8 \"graph/heavy_light_decomposition.cpp\"\n\nclass HeavyLightDecomposition\
    \ {\n    struct Node {\n        std::vector<usize> adjacent;\n        usize parent,\
    \ subtree, head, enter, exit;\n        Node() = default;\n    };\n    std::vector<Node>\
    \ node;\n\n  public:\n    HeavyLightDecomposition() = default;\n    explicit HeavyLightDecomposition(const\
    \ std::vector<std::vector<usize>>& tree, const usize root = 0)\n        : HeavyLightDecomposition(tree,\
    \ std::vector<usize>({root})) {}\n    explicit HeavyLightDecomposition(const std::vector<std::vector<usize>>&\
    \ forest, const std::vector<usize>& root)\n        : node(forest.size()) {\n \
    \       for (const auto i : rep(0, size())) node[i].adjacent = forest[i];\n  \
    \      const auto setup = rec_lambda([&](auto&& dfs, const usize u, const usize\
    \ p) -> void {\n            node[u].parent = p;\n            node[u].subtree =\
    \ 1;\n            for (const auto v : node[u].adjacent) {\n                if\
    \ (v != p) {\n                    dfs(v, u);\n                    node[u].subtree\
    \ += node[v].subtree;\n                }\n            }\n        });\n       \
    \ for (const auto r : root) setup(r, r);\n        usize time = 0;\n        const\
    \ auto decompose = rec_lambda([&](auto&& dfs, const usize u, const usize h) ->\
    \ void {\n            node[u].head = h;\n            node[u].enter = time;\n \
    \           time += 1;\n            usize select = size();\n            for (const\
    \ auto v : node[u].adjacent) {\n                if (v != node[u].parent and (select\
    \ == size() or node[select].subtree < node[v].subtree)) {\n                  \
    \  select = v;\n                }\n            }\n            if (select != size())\
    \ {\n                dfs(select, h);\n                for (const auto v : node[u].adjacent)\
    \ {\n                    if (v != node[u].parent and v != select) {\n        \
    \                dfs(v, v);\n                    }\n                }\n      \
    \      }\n            node[u].exit = time;\n        });\n        for (const auto\
    \ r : root) decompose(r, r);\n    }\n\n    usize size() const { return node.size();\
    \ }\n    const Node& info(const usize u) const {\n        assert(u < size());\n\
    \        return node[u];\n    }\n\n    usize lca(usize u, usize v) const {\n \
    \       assert(u < size());\n        assert(v < size());\n        if (node[u].enter\
    \ > node[v].enter) std::swap(u, v);\n        while (node[u].enter < node[v].enter)\
    \ {\n            if (node[u].head == node[v].head) return u;\n            v =\
    \ node[node[v].head].parent;\n        }\n        return v;\n    }\n\n    std::vector<std::pair<usize,\
    \ usize>> path(usize u, usize p) const {\n        assert(u < size());\n      \
    \  assert(p < size());\n        assert(node[p].enter <= node[u].enter and node[u].exit\
    \ <= node[p].exit);\n        std::vector<std::pair<usize, usize>> ret;\n     \
    \   while (node[u].head != node[p].head) {\n            ret.emplace_back(u, node[u].head);\n\
    \            u = node[node[u].head].parent;\n        }\n        ret.emplace_back(u,\
    \ p);\n        return ret;\n    }\n\n    std::vector<std::vector<usize>> decompose()\
    \ const {\n        std::vector<usize> vec(node.size());\n        for (const usize\
    \ u : rep(0, node.size())) vec[node[u].enter] = u;\n        std::vector<std::vector<usize>>\
    \ ret;\n        usize last = node.size();\n        for (const usize u : vec) {\n\
    \            if (last != node[u].head) {\n                ret.push_back({});\n\
    \                last = node[u].head;\n            }\n            ret.back().push_back(u);\n\
    \        }\n        return ret;\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    #include \"../utility/int_alias.cpp\"\n#include \"../utility/rec_lambda.cpp\"\n\
    #include \"../utility/rep.cpp\"\n\nclass HeavyLightDecomposition {\n    struct\
    \ Node {\n        std::vector<usize> adjacent;\n        usize parent, subtree,\
    \ head, enter, exit;\n        Node() = default;\n    };\n    std::vector<Node>\
    \ node;\n\n  public:\n    HeavyLightDecomposition() = default;\n    explicit HeavyLightDecomposition(const\
    \ std::vector<std::vector<usize>>& tree, const usize root = 0)\n        : HeavyLightDecomposition(tree,\
    \ std::vector<usize>({root})) {}\n    explicit HeavyLightDecomposition(const std::vector<std::vector<usize>>&\
    \ forest, const std::vector<usize>& root)\n        : node(forest.size()) {\n \
    \       for (const auto i : rep(0, size())) node[i].adjacent = forest[i];\n  \
    \      const auto setup = rec_lambda([&](auto&& dfs, const usize u, const usize\
    \ p) -> void {\n            node[u].parent = p;\n            node[u].subtree =\
    \ 1;\n            for (const auto v : node[u].adjacent) {\n                if\
    \ (v != p) {\n                    dfs(v, u);\n                    node[u].subtree\
    \ += node[v].subtree;\n                }\n            }\n        });\n       \
    \ for (const auto r : root) setup(r, r);\n        usize time = 0;\n        const\
    \ auto decompose = rec_lambda([&](auto&& dfs, const usize u, const usize h) ->\
    \ void {\n            node[u].head = h;\n            node[u].enter = time;\n \
    \           time += 1;\n            usize select = size();\n            for (const\
    \ auto v : node[u].adjacent) {\n                if (v != node[u].parent and (select\
    \ == size() or node[select].subtree < node[v].subtree)) {\n                  \
    \  select = v;\n                }\n            }\n            if (select != size())\
    \ {\n                dfs(select, h);\n                for (const auto v : node[u].adjacent)\
    \ {\n                    if (v != node[u].parent and v != select) {\n        \
    \                dfs(v, v);\n                    }\n                }\n      \
    \      }\n            node[u].exit = time;\n        });\n        for (const auto\
    \ r : root) decompose(r, r);\n    }\n\n    usize size() const { return node.size();\
    \ }\n    const Node& info(const usize u) const {\n        assert(u < size());\n\
    \        return node[u];\n    }\n\n    usize lca(usize u, usize v) const {\n \
    \       assert(u < size());\n        assert(v < size());\n        if (node[u].enter\
    \ > node[v].enter) std::swap(u, v);\n        while (node[u].enter < node[v].enter)\
    \ {\n            if (node[u].head == node[v].head) return u;\n            v =\
    \ node[node[v].head].parent;\n        }\n        return v;\n    }\n\n    std::vector<std::pair<usize,\
    \ usize>> path(usize u, usize p) const {\n        assert(u < size());\n      \
    \  assert(p < size());\n        assert(node[p].enter <= node[u].enter and node[u].exit\
    \ <= node[p].exit);\n        std::vector<std::pair<usize, usize>> ret;\n     \
    \   while (node[u].head != node[p].head) {\n            ret.emplace_back(u, node[u].head);\n\
    \            u = node[node[u].head].parent;\n        }\n        ret.emplace_back(u,\
    \ p);\n        return ret;\n    }\n\n    std::vector<std::vector<usize>> decompose()\
    \ const {\n        std::vector<usize> vec(node.size());\n        for (const usize\
    \ u : rep(0, node.size())) vec[node[u].enter] = u;\n        std::vector<std::vector<usize>>\
    \ ret;\n        usize last = node.size();\n        for (const usize u : vec) {\n\
    \            if (last != node[u].head) {\n                ret.push_back({});\n\
    \                last = node[u].head;\n            }\n            ret.back().push_back(u);\n\
    \        }\n        return ret;\n    }\n};"
  dependsOn:
  - utility/int_alias.cpp
  - utility/rec_lambda.cpp
  - utility/rep.cpp
  isVerificationFile: false
  path: graph/heavy_light_decomposition.cpp
  requiredBy: []
  timestamp: '2021-09-08 18:46:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/heavy_light_decomposition.test.cpp
documentation_of: graph/heavy_light_decomposition.cpp
layout: document
redirect_from:
- /library/graph/heavy_light_decomposition.cpp
- /library/graph/heavy_light_decomposition.cpp.html
title: graph/heavy_light_decomposition.cpp
---
