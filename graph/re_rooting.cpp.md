---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  - icon: ':heavy_check_mark:'
    path: utility/revrep.cpp
    title: utility/revrep.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/re_rooting.cpp\"\n#include <cassert>\n#include <vector>\n\
    #line 2 \"utility/rep.cpp\"\n#include <algorithm>\n\nclass Range {\n    struct\
    \ Iter {\n        int itr;\n        constexpr Iter(const int pos) noexcept : itr(pos)\
    \ {}\n        constexpr void operator++() noexcept { ++itr; }\n        constexpr\
    \ bool operator!=(const Iter& other) const noexcept { return itr != other.itr;\
    \ }\n        constexpr int operator*() const noexcept { return itr; }\n    };\n\
    \    const Iter first, last;\n\n  public:\n    explicit constexpr Range(const\
    \ int first, const int last) noexcept : first(first), last(std::max(first, last))\
    \ {}\n    constexpr Iter begin() const noexcept { return first; }\n    constexpr\
    \ Iter end() const noexcept { return last; }\n};\n\nconstexpr Range rep(const\
    \ int l, const int r) noexcept { return Range(l, r); }\nconstexpr Range rep(const\
    \ int n) noexcept { return Range(0, n); }\n#line 3 \"utility/revrep.cpp\"\n\n\
    class ReversedRange {\n    struct Iter {\n        int itr;\n        constexpr\
    \ Iter(const int pos) noexcept : itr(pos) {}\n        constexpr void operator++()\
    \ noexcept { --itr; }\n        constexpr bool operator!=(const Iter& other) const\
    \ noexcept { return itr != other.itr; }\n        constexpr int operator*() const\
    \ noexcept { return itr; }\n    };\n    const Iter first, last;\n\n  public:\n\
    \    explicit constexpr ReversedRange(const int first, const int last) noexcept\n\
    \        : first(last - 1), last(std::min(first, last) - 1) {}\n    constexpr\
    \ Iter begin() const noexcept { return first; }\n    constexpr Iter end() const\
    \ noexcept { return last; }\n};\n\nconstexpr ReversedRange revrep(const int l,\
    \ const int r) noexcept { return ReversedRange(l, r); }\nconstexpr ReversedRange\
    \ revrep(const int n) noexcept { return ReversedRange(0, n); }\n#line 6 \"graph/re_rooting.cpp\"\
    \n\ntemplate <class M> class ReRooting {\n    using T = typename M::Type;\n\n\
    \    std::vector<T> result;\n\n  public:\n    ReRooting() : result() {}\n    template\
    \ <class G, class F> explicit ReRooting(const G& graph, const F& fetch, const\
    \ int root = 0) {\n        const int n = graph.size();\n        assert(0 <= root\
    \ and root < n);\n        std::vector<int> start(n + 1), dst(2 * (n - 1));\n \
    \       for (const int u : rep(n)) {\n            start[u + 1] = start[u];\n \
    \           for (const int v : graph[u]) {\n                assert(start[u + 1]\
    \ < 2 * (n - 1));\n                dst[start[u + 1]] = v;\n                start[u\
    \ + 1] += 1;\n            }\n        }\n        std::vector<int> parent(n, -1),\
    \ order, stack;\n        order.reserve(n);\n        stack.reserve(n);\n      \
    \  stack.push_back(root);\n        while (!stack.empty()) {\n            const\
    \ int u = stack.back();\n            stack.pop_back();\n            order.push_back(u);\n\
    \            for (const int e : rep(start[u], start[u + 1])) {\n             \
    \   const int v = dst[e];\n                if (v != parent[u]) {\n           \
    \         parent[v] = u;\n                    stack.push_back(v);\n          \
    \      }\n            }\n        }\n        assert((int)order.size() == n);\n\
    \        std::vector<T> bottom(n, M::identity());\n        for (const int i :\
    \ revrep(n)) {\n            const int u = order[i];\n            T sum = M::identity();\n\
    \            for (const int e : rep(start[u], start[u + 1])) {\n             \
    \   if (dst[e] != parent[u]) sum = M::operation(sum, bottom[dst[e]]);\n      \
    \      }\n            bottom[u] = fetch(u, sum);\n        }\n        std::vector<T>\
    \ up(n, M::identity());\n        result = std::vector<T>(n, M::identity());\n\
    \        for (const int i : rep(n)) {\n            const int u = order[i];\n \
    \           std::vector<T> accum(start[u + 1] - start[u], M::identity());\n  \
    \          for (const int e : revrep(start[u] + 1, start[u + 1])) {\n        \
    \        accum[e - start[u] - 1] =\n                    M::operation(dst[e] ==\
    \ parent[u] ? up[u] : bottom[dst[e]], accum[e - start[u]]);\n            }\n \
    \           T sum = M::identity();\n            for (const int e : rep(start[u],\
    \ start[u + 1])) {\n                if (dst[e] == parent[u]) {\n             \
    \       sum = M::operation(sum, up[u]);\n                } else {\n          \
    \          up[dst[e]] = fetch(u, M::operation(sum, accum[e - start[u]]));\n  \
    \                  sum = M::operation(sum, bottom[dst[e]]);\n                }\n\
    \            }\n            result[u] = fetch(u, sum);\n        }\n    }\n\n \
    \   int size() const { return result.size(); }\n\n    T operator[](const int u)\
    \ const {\n        assert(0 <= u and u < size());\n        return result[u];\n\
    \    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n#include \"../utility/rep.cpp\"\
    \n#include \"../utility/revrep.cpp\"\n\ntemplate <class M> class ReRooting {\n\
    \    using T = typename M::Type;\n\n    std::vector<T> result;\n\n  public:\n\
    \    ReRooting() : result() {}\n    template <class G, class F> explicit ReRooting(const\
    \ G& graph, const F& fetch, const int root = 0) {\n        const int n = graph.size();\n\
    \        assert(0 <= root and root < n);\n        std::vector<int> start(n + 1),\
    \ dst(2 * (n - 1));\n        for (const int u : rep(n)) {\n            start[u\
    \ + 1] = start[u];\n            for (const int v : graph[u]) {\n             \
    \   assert(start[u + 1] < 2 * (n - 1));\n                dst[start[u + 1]] = v;\n\
    \                start[u + 1] += 1;\n            }\n        }\n        std::vector<int>\
    \ parent(n, -1), order, stack;\n        order.reserve(n);\n        stack.reserve(n);\n\
    \        stack.push_back(root);\n        while (!stack.empty()) {\n          \
    \  const int u = stack.back();\n            stack.pop_back();\n            order.push_back(u);\n\
    \            for (const int e : rep(start[u], start[u + 1])) {\n             \
    \   const int v = dst[e];\n                if (v != parent[u]) {\n           \
    \         parent[v] = u;\n                    stack.push_back(v);\n          \
    \      }\n            }\n        }\n        assert((int)order.size() == n);\n\
    \        std::vector<T> bottom(n, M::identity());\n        for (const int i :\
    \ revrep(n)) {\n            const int u = order[i];\n            T sum = M::identity();\n\
    \            for (const int e : rep(start[u], start[u + 1])) {\n             \
    \   if (dst[e] != parent[u]) sum = M::operation(sum, bottom[dst[e]]);\n      \
    \      }\n            bottom[u] = fetch(u, sum);\n        }\n        std::vector<T>\
    \ up(n, M::identity());\n        result = std::vector<T>(n, M::identity());\n\
    \        for (const int i : rep(n)) {\n            const int u = order[i];\n \
    \           std::vector<T> accum(start[u + 1] - start[u], M::identity());\n  \
    \          for (const int e : revrep(start[u] + 1, start[u + 1])) {\n        \
    \        accum[e - start[u] - 1] =\n                    M::operation(dst[e] ==\
    \ parent[u] ? up[u] : bottom[dst[e]], accum[e - start[u]]);\n            }\n \
    \           T sum = M::identity();\n            for (const int e : rep(start[u],\
    \ start[u + 1])) {\n                if (dst[e] == parent[u]) {\n             \
    \       sum = M::operation(sum, up[u]);\n                } else {\n          \
    \          up[dst[e]] = fetch(u, M::operation(sum, accum[e - start[u]]));\n  \
    \                  sum = M::operation(sum, bottom[dst[e]]);\n                }\n\
    \            }\n            result[u] = fetch(u, sum);\n        }\n    }\n\n \
    \   int size() const { return result.size(); }\n\n    T operator[](const int u)\
    \ const {\n        assert(0 <= u and u < size());\n        return result[u];\n\
    \    }\n};\n"
  dependsOn:
  - utility/rep.cpp
  - utility/revrep.cpp
  isVerificationFile: false
  path: graph/re_rooting.cpp
  requiredBy: []
  timestamp: '2022-03-31 10:32:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/re_rooting.cpp
layout: document
redirect_from:
- /library/graph/re_rooting.cpp
- /library/graph/re_rooting.cpp.html
title: graph/re_rooting.cpp
---
