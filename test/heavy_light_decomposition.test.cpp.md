---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bit/ceil_log2.cpp
    title: bit/ceil_log2.cpp
  - icon: ':heavy_check_mark:'
    path: container/segment_tree.cpp
    title: container/segment_tree.cpp
  - icon: ':heavy_check_mark:'
    path: graph/heavy_light_decomposition.cpp
    title: graph/heavy_light_decomposition.cpp
  - icon: ':heavy_check_mark:'
    path: math/rem_euclid.cpp
    title: math/rem_euclid.cpp
  - icon: ':heavy_check_mark:'
    path: math/static_modint.cpp
    title: math/static_modint.cpp
  - icon: ':heavy_check_mark:'
    path: math/totient.cpp
    title: math/totient.cpp
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
    path: utility/revrep.cpp
    title: utility/revrep.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "#line 1 \"test/heavy_light_decomposition.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\n#line 2 \"utility/int_alias.cpp\"\
    \n#include <cstdint>\n#include <cstddef>\n\nusing i32 = std::int32_t;\nusing u32\
    \ = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing\
    \ i128 = __int128_t;\nusing u128 = __uint128_t;\nusing isize = std::ptrdiff_t;\n\
    using usize = std::size_t;\n#line 2 \"math/totient.cpp\"\n\ntemplate <class T>\n\
    constexpr T totient(T x) {\n    T ret = x;\n    for (T i = 2; i * i <= x; ++i)\
    \ {\n        if (x % i == 0) {\n            ret /= i; ret *= i - 1;\n        \
    \    while (x % i == 0) x /= i;\n        }\n    }\n    if (x > 1) { ret /= x;\
    \ ret *= x - 1; }\n    return ret;\n}\n#line 2 \"math/rem_euclid.cpp\"\n\ntemplate\
    \ <class T>\nconstexpr T rem_euclid(T value, const T& mod) {\n    return (value\
    \ %= mod) >= 0 ? value : value + mod;\n}\n#line 5 \"math/static_modint.cpp\"\n\
    #include <type_traits>\n#include <ostream>\n\ntemplate <u32 MOD, std::enable_if_t<((u32)\
    \ 1 <= MOD and MOD <= ((u32) 1 << 31))>* = nullptr>\nclass StaticModint {\n  \
    \  using Mint = StaticModint;\n    \n    static inline constexpr u32 PHI = totient(MOD);\n\
    \    u32 v;\n\npublic:\n    static constexpr u32 mod() noexcept { return MOD;\
    \ }\n\n    template <class T, std::enable_if_t<std::is_signed_v<T> and std::is_integral_v<T>>*\
    \ = nullptr>\n    static constexpr T normalize(const T x) noexcept { return rem_euclid<std::common_type_t<T,\
    \ i64>>(x, MOD); }\n    template <class T, std::enable_if_t<std::is_unsigned_v<T>\
    \ and std::is_integral_v<T>>* = nullptr>\n    static constexpr T normalize(const\
    \ T x) noexcept { return x % MOD; }\n\n    constexpr StaticModint() noexcept:\
    \ v(0) { }\n    template <class T>\n    constexpr StaticModint(const T x) noexcept:\
    \ v(normalize(x)) { }\n    template <class T>\n    static constexpr Mint raw(const\
    \ T x) noexcept {\n        Mint ret;\n        ret.v = x;\n        return ret;\n\
    \    }\n\n    constexpr u32 get() const noexcept { return v; }\n    constexpr\
    \ Mint neg() const noexcept { return raw(v == 0 ? 0 : MOD - v); }\n    constexpr\
    \ Mint inv() const noexcept { return pow(PHI - 1); }\n    constexpr Mint pow(u64\
    \ exp) const noexcept {\n        Mint ret(1), mult(*this);\n        for (; exp\
    \ > 0; exp >>= 1) {\n            if (exp & 1) ret *= mult;\n            mult *=\
    \ mult;\n        }\n        return ret;\n    }\n    \n    constexpr Mint operator\
    \ - () const noexcept { return neg(); }\n    constexpr Mint operator ~ () const\
    \ noexcept { return inv(); }\n\n    constexpr Mint operator + (const Mint& rhs)\
    \ const noexcept { return Mint(*this) += rhs; }\n    constexpr Mint& operator\
    \ += (const Mint& rhs) noexcept {\n        if ((v += rhs.v) >= MOD) v -= MOD;\n\
    \        return *this;\n    }\n    \n    constexpr Mint operator - (const Mint&\
    \ rhs) const noexcept { return Mint(*this) -= rhs; }\n    constexpr Mint& operator\
    \ -= (const Mint& rhs) noexcept {\n        if (v < rhs.v) v += MOD;\n        v\
    \ -= rhs.v;\n        return *this;\n    }\n\n    constexpr Mint operator * (const\
    \ Mint& rhs) const noexcept { return Mint(*this) *= rhs; }\n    constexpr Mint&\
    \ operator *= (const Mint& rhs) noexcept {\n        v = (u64) v * rhs.v % MOD;\n\
    \        return *this;\n    }\n\n    constexpr Mint operator / (const Mint& rhs)\
    \ const noexcept { return Mint(*this) /= rhs; }\n    constexpr Mint& operator\
    \ /= (const Mint& rhs) noexcept { \n        return *this *= rhs.inv();\n    }\n\
    \n    constexpr bool operator == (const Mint& rhs) const noexcept { return v ==\
    \ rhs.v; }\n    constexpr bool operator != (const Mint& rhs) const noexcept {\
    \ return v != rhs.v; }\n    friend std::ostream& operator << (std::ostream& stream,\
    \ const Mint& rhs) { \n        return stream << rhs.v;\n    }\n};\n\nusing Modint1000000007\
    \ = StaticModint<1000000007>;\nusing Modint998244353 = StaticModint<998244353>;\n\
    #line 3 \"utility/rep.cpp\"\n#include <algorithm>\n\nclass rep {\n    struct Iter\
    \ {\n        usize itr;\n        constexpr Iter(const usize pos) noexcept: itr(pos)\
    \ { }\n        constexpr void operator ++ () noexcept { ++itr; }\n        constexpr\
    \ bool operator != (const Iter& other) const noexcept { return itr != other.itr;\
    \ }\n        constexpr usize operator * () const noexcept { return itr; }\n  \
    \  };\n    const Iter first, last;\npublic:\n    explicit constexpr rep(const\
    \ usize first, const usize last) noexcept: first(first), last(std::max(first,\
    \ last)) { }\n    constexpr Iter begin() const noexcept { return first; }\n  \
    \  constexpr Iter end() const noexcept { return last; }\n};\n#line 4 \"utility/revrep.cpp\"\
    \n\nclass revrep {\n    struct Iter {\n        usize itr;\n        constexpr Iter(const\
    \ usize pos) noexcept: itr(pos) { }\n        constexpr void operator ++ () noexcept\
    \ { --itr; }\n        constexpr bool operator != (const Iter& other) const noexcept\
    \ { return itr != other.itr; }\n        constexpr usize operator * () const noexcept\
    \ { return itr; }\n    };\n    const Iter first, last;\npublic:\n    explicit\
    \ constexpr revrep(const usize first, const usize last) noexcept: first(last -\
    \ 1), last(std::min(first, last) - 1) { }\n    constexpr Iter begin() const noexcept\
    \ { return first; }\n    constexpr Iter end() const noexcept { return last; }\n\
    };\n#line 3 \"bit/ceil_log2.cpp\"\n\nconstexpr u64 ceil_log2(const u64 x) {\n\
    \    u64 e = 0;\n    while (((u64) 1 << e) < x) ++e;\n    return e;\n}\n#line\
    \ 6 \"container/segment_tree.cpp\"\n#include <vector>\n#include <cassert>\n\n\
    template <class Monoid>\nclass SegmentTree {\n    using M = Monoid;\n    usize\
    \ internal_size, seg_size;\n    std::vector<M> data;\n\n    void fetch(const usize\
    \ k) { data[k] = data[2 * k] + data[2 * k + 1]; }\n\npublic:\n    explicit SegmentTree(const\
    \ usize size = 0, const M& value = M::zero()): \n        SegmentTree(std::vector<M>(size,\
    \ value)) { }\n    explicit SegmentTree(const std::vector<M>& vec): internal_size(vec.size())\
    \ {\n        seg_size = 1 << ceil_log2(internal_size);\n        data = std::vector<M>(2\
    \ * seg_size, M::zero());\n        for (const usize i: rep(0, internal_size))\
    \ data[seg_size + i] = vec[i];\n        for (const usize i: revrep(1, seg_size))\
    \ fetch(i);\n    }\n\n    usize size() const { return internal_size; }\n\n   \
    \ void assign(usize i, const M& value) {\n        assert(i < internal_size);\n\
    \        i += seg_size;\n        data[i] = value;\n        while (i > 1) {\n \
    \           i >>= 1;\n            fetch(i);\n        }\n    }\n\n    M fold()\
    \ const { return data[1]; }\n    M fold(usize l, usize r) const {\n        assert(l\
    \ <= r and r <= internal_size);\n        l += seg_size; r += seg_size;\n     \
    \   M ret_l = M::zero(), ret_r = M::zero();\n        while (l < r) {\n       \
    \     if (l & 1) ret_l = ret_l + data[l++];\n            if (r & 1) ret_r = data[--r]\
    \ + ret_r;\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ ret_l + ret_r;\n    }\n\n    template <class F>\n    usize max_right(usize l,\
    \ const F& f) const {\n        assert(l <= internal_size);\n        assert(f(M::zero()));\n\
    \        if (l == internal_size) return internal_size;\n        l += seg_size;\n\
    \        M sum = M::zero();\n        do {\n            while (!(l & 1)) l >>=\
    \ 1;\n            if (!f(sum + data[l])) {\n                while (l < seg_size)\
    \ {\n                    l = 2 * l;\n                    if (f(sum + data[l]))\
    \ sum = sum + data[l++];\n                }\n                return l - seg_size;\n\
    \            }\n            sum = sum + data[l++];\n        } while ((l & -l)\
    \ != l);\n        return internal_size;\n    }\n\n    template <class F>\n   \
    \ usize min_left(usize r, const F& f) const {\n        assert(r <= internal_size);\n\
    \        assert(f(M::zero()));\n        if (r == 0) return 0;\n        r += seg_size;\n\
    \        M sum = M::zero();\n        do {\n            r -= 1;\n            while\
    \ (r > 1 and (r & 1)) r >>= 1;\n            if (!f(data[r] + sum)) {\n       \
    \         while (r < seg_size) {\n                    r = 2 * r + 1;\n       \
    \             if (f(data[r] + sum)) sum = data[r--] + sum;\n                }\n\
    \                return r + 1 - seg_size;\n            }\n            sum = data[r]\
    \ + sum;\n        } while ((r & -r) != r);\n        return 0;\n    }\n};\n#line\
    \ 2 \"utility/rec_lambda.cpp\"\n#include <utility>\n#line 4 \"utility/rec_lambda.cpp\"\
    \n\ntemplate <class F>\nstruct RecursiveLambda: private F {\n    explicit constexpr\
    \ RecursiveLambda(F&& f): F(std::forward<F>(f)) { }\n    template <class... Args>\n\
    \    constexpr decltype(auto) operator () (Args&&... args) const {\n        return\
    \ F::operator()(*this, std::forward<Args>(args)...);\n    }\n};\n\ntemplate <class\
    \ F>\nconstexpr decltype(auto) rec_lambda(F&& f) {\n    using G = std::decay_t<F>;\n\
    \    return RecursiveLambda<G>(std::forward<G>(f));\n}\n#line 8 \"graph/heavy_light_decomposition.cpp\"\
    \n\nclass HeavyLightDecomposition {\n    struct Node {\n        std::vector<usize>\
    \ adjacent;\n        usize parent, subtree, head, enter, exit;\n        Node()\
    \ = default;\n    };\n    std::vector<Node> node;\n\npublic:\n    explicit HeavyLightDecomposition(const\
    \ std::vector<std::vector<usize>>& tree, const usize root = 0):\n        HeavyLightDecomposition(tree,\
    \ std::vector<usize>({ root })) { }\n    explicit HeavyLightDecomposition(const\
    \ std::vector<std::vector<usize>>& forest, const std::vector<usize>& root): node(forest.size())\
    \ {\n        for (const auto i: rep(0, size())) node[i].adjacent = forest[i];\n\
    \        const auto setup = rec_lambda([&](auto&& dfs, const usize u, const usize\
    \ p) -> void {\n            node[u].parent = p;\n            node[u].subtree =\
    \ 1;\n            for (const auto v: node[u].adjacent) {\n                if (v\
    \ != p) {\n                    dfs(v, u);\n                    node[u].subtree\
    \ += node[v].subtree;\n                }\n            }\n        });\n       \
    \ for (const auto r: root) setup(r, r);\n        usize time = 0;\n        const\
    \ auto decompose = rec_lambda([&](auto&& dfs, const usize u, const usize h) ->\
    \ void {\n            node[u].head = h;\n            node[u].enter = time;\n \
    \           time += 1;\n            usize select = size();\n            for (const\
    \ auto v: node[u].adjacent) {\n                if (v != node[u].parent and (select\
    \ == size() or node[select].subtree < node[v].subtree)) {\n                  \
    \  select = v;\n                }\n            }\n            if (select != size())\
    \ {\n                dfs(select, h);\n                for (const auto v: node[u].adjacent)\
    \ {\n                    if (v != node[u].parent and v != select) {\n        \
    \                dfs(v, v);\n                    }\n                }\n      \
    \      }\n            node[u].exit = time;\n        });\n        for (const auto\
    \ r: root) decompose(r, r);\n    }\n\n    usize size() const { return node.size();\
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
    \ p);\n        return ret;\n    }\n};\n#line 6 \"test/heavy_light_decomposition.test.cpp\"\
    \n#include <iostream>\n\nusing Fp = Modint998244353;\n\nstruct Line {\n    Fp\
    \ a, b;\n    Fp get(const Fp& x) const {\n        return a * x + b;\n    }\n \
    \   Line operator + (const Line& other) const {\n        return Line { other.a\
    \ * a, other.a * b + other.b };\n    }\n};\n\nstruct Monoid {\n    static Monoid\
    \ zero() {\n        return Monoid(1, 0);\n    }\n    Line line, line_rev;\n  \
    \  explicit Monoid(const Fp& a, const Fp& b): line({a, b}), line_rev({a, b}) {\
    \ }\n    explicit Monoid(const Line& line, const Line& line_rev): line(line),\
    \ line_rev(line_rev) { }\n    Monoid operator + (const Monoid& other) const {\n\
    \        return Monoid(line + other.line, other.line_rev + line_rev);\n    }\n\
    };\n\nint main() {\n    usize N, Q;\n    std::cin >> N >> Q;\n    std::vector<std::vector<usize>>\
    \ graph(N);\n    std::vector<Fp> A(N), B(N);\n    for (const auto i: rep(0, N))\
    \ {\n        u32 a, b;\n        std::cin >> a >> b;\n        A[i] = a;\n     \
    \   B[i] = b;\n    }\n    for (const auto i: rep(0, N - 1)) {\n        usize u,\
    \ v;\n        std::cin >> u >> v;\n        graph[u].push_back(v);\n        graph[v].push_back(u);\n\
    \    }\n    HeavyLightDecomposition hld(graph);\n    SegmentTree<Monoid> seg;\n\
    \    {\n        std::vector<Monoid> build(N, Monoid::zero());\n        for (const\
    \ auto i: rep(0, N)) {\n            build[hld.info(i).enter] = Monoid(A[i], B[i]);\n\
    \        }\n        seg = SegmentTree(build);\n    }\n    while (Q--) {\n    \
    \    usize t;\n        std::cin >> t;\n        if (t == 0) {\n            usize\
    \ p;\n            u32 c, d;\n            std::cin >> p >> c >> d;\n          \
    \  seg.assign(hld.info(p).enter, Monoid(c, d));\n        }\n        else {\n \
    \           usize u, v;\n            u32 x;\n            std::cin >> u >> v >>\
    \ x;\n            const auto lca = hld.lca(u, v);\n            Line sum_u { 1,\
    \ 0 };\n            for (const auto [a, b]: hld.path(u, lca)) {\n            \
    \    sum_u = sum_u + seg.fold(hld.info(b).enter, hld.info(a).enter + 1).line_rev;\n\
    \            }\n            Line sum_v { 1, 0 };\n            for (const auto\
    \ [a, b]: hld.path(v, lca)) {\n                if (b == lca) {\n             \
    \       sum_v = seg.fold(hld.info(b).enter + 1, hld.info(a).enter + 1).line +\
    \ sum_v;\n                }\n                else {\n                    sum_v\
    \ = seg.fold(hld.info(b).enter, hld.info(a).enter + 1).line + sum_v;\n       \
    \         }\n            }\n            std::cout << (sum_u + sum_v).get(x) <<\
    \ '\\n';\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n#include \"../utility/int_alias.cpp\"\n#include \"../math/static_modint.cpp\"\
    \n#include \"../container/segment_tree.cpp\"\n#include \"../graph/heavy_light_decomposition.cpp\"\
    \n#include <iostream>\n\nusing Fp = Modint998244353;\n\nstruct Line {\n    Fp\
    \ a, b;\n    Fp get(const Fp& x) const {\n        return a * x + b;\n    }\n \
    \   Line operator + (const Line& other) const {\n        return Line { other.a\
    \ * a, other.a * b + other.b };\n    }\n};\n\nstruct Monoid {\n    static Monoid\
    \ zero() {\n        return Monoid(1, 0);\n    }\n    Line line, line_rev;\n  \
    \  explicit Monoid(const Fp& a, const Fp& b): line({a, b}), line_rev({a, b}) {\
    \ }\n    explicit Monoid(const Line& line, const Line& line_rev): line(line),\
    \ line_rev(line_rev) { }\n    Monoid operator + (const Monoid& other) const {\n\
    \        return Monoid(line + other.line, other.line_rev + line_rev);\n    }\n\
    };\n\nint main() {\n    usize N, Q;\n    std::cin >> N >> Q;\n    std::vector<std::vector<usize>>\
    \ graph(N);\n    std::vector<Fp> A(N), B(N);\n    for (const auto i: rep(0, N))\
    \ {\n        u32 a, b;\n        std::cin >> a >> b;\n        A[i] = a;\n     \
    \   B[i] = b;\n    }\n    for (const auto i: rep(0, N - 1)) {\n        usize u,\
    \ v;\n        std::cin >> u >> v;\n        graph[u].push_back(v);\n        graph[v].push_back(u);\n\
    \    }\n    HeavyLightDecomposition hld(graph);\n    SegmentTree<Monoid> seg;\n\
    \    {\n        std::vector<Monoid> build(N, Monoid::zero());\n        for (const\
    \ auto i: rep(0, N)) {\n            build[hld.info(i).enter] = Monoid(A[i], B[i]);\n\
    \        }\n        seg = SegmentTree(build);\n    }\n    while (Q--) {\n    \
    \    usize t;\n        std::cin >> t;\n        if (t == 0) {\n            usize\
    \ p;\n            u32 c, d;\n            std::cin >> p >> c >> d;\n          \
    \  seg.assign(hld.info(p).enter, Monoid(c, d));\n        }\n        else {\n \
    \           usize u, v;\n            u32 x;\n            std::cin >> u >> v >>\
    \ x;\n            const auto lca = hld.lca(u, v);\n            Line sum_u { 1,\
    \ 0 };\n            for (const auto [a, b]: hld.path(u, lca)) {\n            \
    \    sum_u = sum_u + seg.fold(hld.info(b).enter, hld.info(a).enter + 1).line_rev;\n\
    \            }\n            Line sum_v { 1, 0 };\n            for (const auto\
    \ [a, b]: hld.path(v, lca)) {\n                if (b == lca) {\n             \
    \       sum_v = seg.fold(hld.info(b).enter + 1, hld.info(a).enter + 1).line +\
    \ sum_v;\n                }\n                else {\n                    sum_v\
    \ = seg.fold(hld.info(b).enter, hld.info(a).enter + 1).line + sum_v;\n       \
    \         }\n            }\n            std::cout << (sum_u + sum_v).get(x) <<\
    \ '\\n';\n        }\n    }\n    return 0;\n}"
  dependsOn:
  - utility/int_alias.cpp
  - math/static_modint.cpp
  - math/totient.cpp
  - math/rem_euclid.cpp
  - container/segment_tree.cpp
  - utility/rep.cpp
  - utility/revrep.cpp
  - bit/ceil_log2.cpp
  - graph/heavy_light_decomposition.cpp
  - utility/rec_lambda.cpp
  isVerificationFile: true
  path: test/heavy_light_decomposition.test.cpp
  requiredBy: []
  timestamp: '2021-05-10 19:00:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/heavy_light_decomposition.test.cpp
layout: document
redirect_from:
- /verify/test/heavy_light_decomposition.test.cpp
- /verify/test/heavy_light_decomposition.test.cpp.html
title: test/heavy_light_decomposition.test.cpp
---
