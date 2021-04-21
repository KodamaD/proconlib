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
  bundledCode: "#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n#include <cstddef>\n\
    \nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    using isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 3 \"utility/rep.cpp\"\
    \n#include <algorithm>\n\nclass rep {\n    struct Iter {\n        usize itr;\n\
    \        constexpr Iter(const usize pos) noexcept: itr(pos) { }\n        constexpr\
    \ void operator ++ () noexcept { ++itr; }\n        constexpr bool operator !=\
    \ (const Iter& other) const noexcept { return itr != other.itr; }\n        constexpr\
    \ usize operator * () const noexcept { return itr; }\n    };\n    const Iter first,\
    \ last;\npublic:\n    explicit constexpr rep(const usize first, const usize last)\
    \ noexcept: first(first), last(std::max(first, last)) { }\n    constexpr Iter\
    \ begin() const noexcept { return first; }\n    constexpr Iter end() const noexcept\
    \ { return last; }\n};\n#line 2 \"utility/rec_lambda.cpp\"\n#include <utility>\n\
    #include <type_traits>\n\ntemplate <class F>\nstruct RecLambda: private F {\n\
    \    template <class G>\n    explicit constexpr RecLambda(G&& g): F(std::forward<G>(g))\
    \ { }\n    template <class... Args>\n    constexpr decltype(auto) operator ()\
    \ (Args&&... args) const {\n        return F::operator()(*this, std::forward<Args>(args)...);\n\
    \    }\n};\n\ntemplate <class G>\nexplicit RecLambda(G&&) -> RecLambda<std::decay_t<G>>;\n\
    #line 5 \"graph/heavy_light_decomposition.cpp\"\n#include <vector>\n#line 7 \"\
    graph/heavy_light_decomposition.cpp\"\n#include <cassert>\n\nclass HeavyLightDecomposition\
    \ {\n    struct Node {\n        std::vector<usize> adjacent;\n        usize parent,\
    \ subtree, head, enter, exit;\n        Node() = default;\n    };\n    std::vector<Node>\
    \ node;\n\npublic:\n    explicit HeavyLightDecomposition(const std::vector<std::vector<usize>>&\
    \ tree, const usize root = 0):\n        HeavyLightDecomposition(tree, std::vector<usize>({\
    \ root })) { }\n    explicit HeavyLightDecomposition(const std::vector<std::vector<usize>>&\
    \ forest, const std::vector<usize>& root): node(forest.size()) {\n        for\
    \ (const auto i: rep(0, size())) node[i].adjacent = forest[i];\n        const\
    \ auto setup = RecLambda([&](auto&& dfs, const usize u, const usize p) -> void\
    \ {\n            node[u].parent = p;\n            node[u].subtree = 1;\n     \
    \       for (const auto v: node[u].adjacent) {\n                if (v != p) {\n\
    \                    dfs(v, u);\n                    node[u].subtree += node[v].subtree;\n\
    \                }\n            }\n        });\n        for (const auto r: root)\
    \ setup(r, r);\n        usize time = 0;\n        const auto decompose = RecLambda([&](auto&&\
    \ dfs, const usize u, const usize h) -> void {\n            node[u].head = h;\n\
    \            node[u].enter = time;\n            time += 1;\n            usize\
    \ select = size();\n            for (const auto v: node[u].adjacent) {\n     \
    \           if (v != node[u].parent and (select == size() or node[select].subtree\
    \ < node[v].subtree)) {\n                    select = v;\n                }\n\
    \            }\n            if (select != size()) {\n                dfs(select,\
    \ h);\n                for (const auto v: node[u].adjacent) {\n              \
    \      if (v != node[u].parent and v != select) {\n                        dfs(v,\
    \ v);\n                    }\n                }\n            }\n            node[u].exit\
    \ = time;\n        });\n        for (const auto r: root) decompose(r, r);\n  \
    \  }\n\n    usize size() const { return node.size(); }\n    const Node& info(const\
    \ usize u) const {\n        assert(u < size());\n        return node[u];\n   \
    \ }\n\n    usize lca(usize u, usize v) const {\n        assert(u < size());\n\
    \        assert(v < size());\n        if (node[u].enter > node[v].enter) std::swap(u,\
    \ v);\n        while (node[u].enter < node[v].enter) {\n            if (node[u].head\
    \ == node[v].head) return u;\n            v = node[node[v].head].parent;\n   \
    \     }\n        return v;\n    }\n\n    std::vector<std::pair<usize, usize>>\
    \ path(usize u, usize p) const {\n        assert(u < size());\n        assert(p\
    \ < size());\n        assert(node[p].enter <= node[u].enter and node[u].exit <=\
    \ node[p].exit);\n        std::vector<std::pair<usize, usize>> ret;\n        while\
    \ (node[u].head != node[p].head) {\n            ret.emplace_back(u, node[u].head);\n\
    \            u = node[node[u].head].parent;\n        }\n        ret.emplace_back(u,\
    \ p);\n        return ret;\n    }\n};\n"
  code: "#pragma once\n#include \"../utility/int_alias.cpp\"\n#include \"../utility/rep.cpp\"\
    \n#include \"../utility/rec_lambda.cpp\"\n#include <vector>\n#include <utility>\n\
    #include <cassert>\n\nclass HeavyLightDecomposition {\n    struct Node {\n   \
    \     std::vector<usize> adjacent;\n        usize parent, subtree, head, enter,\
    \ exit;\n        Node() = default;\n    };\n    std::vector<Node> node;\n\npublic:\n\
    \    explicit HeavyLightDecomposition(const std::vector<std::vector<usize>>& tree,\
    \ const usize root = 0):\n        HeavyLightDecomposition(tree, std::vector<usize>({\
    \ root })) { }\n    explicit HeavyLightDecomposition(const std::vector<std::vector<usize>>&\
    \ forest, const std::vector<usize>& root): node(forest.size()) {\n        for\
    \ (const auto i: rep(0, size())) node[i].adjacent = forest[i];\n        const\
    \ auto setup = RecLambda([&](auto&& dfs, const usize u, const usize p) -> void\
    \ {\n            node[u].parent = p;\n            node[u].subtree = 1;\n     \
    \       for (const auto v: node[u].adjacent) {\n                if (v != p) {\n\
    \                    dfs(v, u);\n                    node[u].subtree += node[v].subtree;\n\
    \                }\n            }\n        });\n        for (const auto r: root)\
    \ setup(r, r);\n        usize time = 0;\n        const auto decompose = RecLambda([&](auto&&\
    \ dfs, const usize u, const usize h) -> void {\n            node[u].head = h;\n\
    \            node[u].enter = time;\n            time += 1;\n            usize\
    \ select = size();\n            for (const auto v: node[u].adjacent) {\n     \
    \           if (v != node[u].parent and (select == size() or node[select].subtree\
    \ < node[v].subtree)) {\n                    select = v;\n                }\n\
    \            }\n            if (select != size()) {\n                dfs(select,\
    \ h);\n                for (const auto v: node[u].adjacent) {\n              \
    \      if (v != node[u].parent and v != select) {\n                        dfs(v,\
    \ v);\n                    }\n                }\n            }\n            node[u].exit\
    \ = time;\n        });\n        for (const auto r: root) decompose(r, r);\n  \
    \  }\n\n    usize size() const { return node.size(); }\n    const Node& info(const\
    \ usize u) const {\n        assert(u < size());\n        return node[u];\n   \
    \ }\n\n    usize lca(usize u, usize v) const {\n        assert(u < size());\n\
    \        assert(v < size());\n        if (node[u].enter > node[v].enter) std::swap(u,\
    \ v);\n        while (node[u].enter < node[v].enter) {\n            if (node[u].head\
    \ == node[v].head) return u;\n            v = node[node[v].head].parent;\n   \
    \     }\n        return v;\n    }\n\n    std::vector<std::pair<usize, usize>>\
    \ path(usize u, usize p) const {\n        assert(u < size());\n        assert(p\
    \ < size());\n        assert(node[p].enter <= node[u].enter and node[u].exit <=\
    \ node[p].exit);\n        std::vector<std::pair<usize, usize>> ret;\n        while\
    \ (node[u].head != node[p].head) {\n            ret.emplace_back(u, node[u].head);\n\
    \            u = node[node[u].head].parent;\n        }\n        ret.emplace_back(u,\
    \ p);\n        return ret;\n    }\n};"
  dependsOn:
  - utility/int_alias.cpp
  - utility/rep.cpp
  - utility/rec_lambda.cpp
  isVerificationFile: false
  path: graph/heavy_light_decomposition.cpp
  requiredBy: []
  timestamp: '2021-04-21 21:38:52+09:00'
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
