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
  - icon: ':heavy_check_mark:'
    path: utility/setmin.cpp
    title: utility/setmin.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/strongly_connected_components.test.cpp
    title: test/strongly_connected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/strongly_connected_components.cpp\"\n#include <cassert>\n\
    #include <vector>\n#line 2 \"utility/int_alias.cpp\"\n#include <cstddef>\n#include\
    \ <cstdint>\n\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64\
    \ = std::int64_t;\nusing u64 = std::uint64_t;\nusing isize = std::ptrdiff_t;\n\
    using usize = std::size_t;\n#line 2 \"utility/rec_lambda.cpp\"\n#include <type_traits>\n\
    #include <utility>\n\ntemplate <class F> struct RecursiveLambda : private F {\n\
    \    explicit constexpr RecursiveLambda(F&& f) : F(std::forward<F>(f)) {}\n  \
    \  template <class... Args> constexpr decltype(auto) operator()(Args&&... args)\
    \ const {\n        return F::operator()(*this, std::forward<Args>(args)...);\n\
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
    };\n#line 2 \"utility/setmin.cpp\"\n\ntemplate <class T> bool setmin(T& lhs, const\
    \ T& rhs) {\n    if (lhs > rhs) {\n        lhs = rhs;\n        return true;\n\
    \    }\n    return false;\n}\n#line 8 \"graph/strongly_connected_components.cpp\"\
    \n\ntemplate <class G> class StronglyConnectedComponents {\n    usize count;\n\
    \    std::vector<usize> index;\n\n  public:\n    StronglyConnectedComponents()\
    \ : count(0), index() {}\n    explicit StronglyConnectedComponents(const G& graph)\
    \ : count(0), index(graph.size()) {\n        const usize n = size();\n       \
    \ usize time_stamp = 0;\n        std::vector<usize> visited, low(n), ord(n);\n\
    \        visited.reserve(n);\n        const auto dfs = rec_lambda([&](auto&& dfs,\
    \ const usize u) -> void {\n            low[u] = ord[u] = ++time_stamp;\n    \
    \        visited.push_back(u);\n            for (const usize v : graph[u]) {\n\
    \                if (!ord[v]) {\n                    dfs(v);\n               \
    \     setmin(low[u], low[v]);\n                } else {\n                    setmin(low[u],\
    \ ord[v]);\n                }\n            }\n            if (low[u] == ord[u])\
    \ {\n                while (true) {\n                    const usize v = visited.back();\n\
    \                    visited.pop_back();\n                    ord[v] = n;\n  \
    \                  index[v] = count;\n                    if (u == v) break;\n\
    \                }\n                count += 1;\n            }\n        });\n\
    \        for (const usize u : rep(0, n))\n            if (!ord[u]) dfs(u);\n \
    \       for (auto& x : index) x = count - x - 1;\n    }\n\n    usize size() const\
    \ { return index.size(); }\n    usize group_count() const { return count; }\n\
    \    usize group_id(const usize u) const {\n        assert(u < size());\n    \
    \    return index[u];\n    }\n\n    std::vector<std::vector<usize>> decopmose()\
    \ const {\n        std::vector<std::vector<usize>> ret(group_count());\n     \
    \   for (const usize u : rep(0, size())) ret[index[u]].push_back(u);\n       \
    \ return ret;\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n#include \"../utility/int_alias.cpp\"\
    \n#include \"../utility/rec_lambda.cpp\"\n#include \"../utility/rep.cpp\"\n#include\
    \ \"../utility/setmin.cpp\"\n\ntemplate <class G> class StronglyConnectedComponents\
    \ {\n    usize count;\n    std::vector<usize> index;\n\n  public:\n    StronglyConnectedComponents()\
    \ : count(0), index() {}\n    explicit StronglyConnectedComponents(const G& graph)\
    \ : count(0), index(graph.size()) {\n        const usize n = size();\n       \
    \ usize time_stamp = 0;\n        std::vector<usize> visited, low(n), ord(n);\n\
    \        visited.reserve(n);\n        const auto dfs = rec_lambda([&](auto&& dfs,\
    \ const usize u) -> void {\n            low[u] = ord[u] = ++time_stamp;\n    \
    \        visited.push_back(u);\n            for (const usize v : graph[u]) {\n\
    \                if (!ord[v]) {\n                    dfs(v);\n               \
    \     setmin(low[u], low[v]);\n                } else {\n                    setmin(low[u],\
    \ ord[v]);\n                }\n            }\n            if (low[u] == ord[u])\
    \ {\n                while (true) {\n                    const usize v = visited.back();\n\
    \                    visited.pop_back();\n                    ord[v] = n;\n  \
    \                  index[v] = count;\n                    if (u == v) break;\n\
    \                }\n                count += 1;\n            }\n        });\n\
    \        for (const usize u : rep(0, n))\n            if (!ord[u]) dfs(u);\n \
    \       for (auto& x : index) x = count - x - 1;\n    }\n\n    usize size() const\
    \ { return index.size(); }\n    usize group_count() const { return count; }\n\
    \    usize group_id(const usize u) const {\n        assert(u < size());\n    \
    \    return index[u];\n    }\n\n    std::vector<std::vector<usize>> decopmose()\
    \ const {\n        std::vector<std::vector<usize>> ret(group_count());\n     \
    \   for (const usize u : rep(0, size())) ret[index[u]].push_back(u);\n       \
    \ return ret;\n    }\n};\n"
  dependsOn:
  - utility/int_alias.cpp
  - utility/rec_lambda.cpp
  - utility/rep.cpp
  - utility/setmin.cpp
  isVerificationFile: false
  path: graph/strongly_connected_components.cpp
  requiredBy: []
  timestamp: '2021-11-01 18:27:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/strongly_connected_components.test.cpp
documentation_of: graph/strongly_connected_components.cpp
layout: document
redirect_from:
- /library/graph/strongly_connected_components.cpp
- /library/graph/strongly_connected_components.cpp.html
title: graph/strongly_connected_components.cpp
---
