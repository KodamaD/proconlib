---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: container/segment_tree.cpp
    title: container/segment_tree.cpp
  - icon: ':heavy_check_mark:'
    path: graph/basic_graph.cpp
    title: graph/basic_graph.cpp
  - icon: ':heavy_check_mark:'
    path: graph/tree_manager.cpp
    title: graph/tree_manager.cpp
  - icon: ':question:'
    path: math/rem_euclid.cpp
    title: math/rem_euclid.cpp
  - icon: ':question:'
    path: math/static_modint.cpp
    title: math/static_modint.cpp
  - icon: ':question:'
    path: math/totient.cpp
    title: math/totient.cpp
  - icon: ':heavy_check_mark:'
    path: traits/affine_composite_monoid.cpp
    title: traits/affine_composite_monoid.cpp
  - icon: ':heavy_check_mark:'
    path: traits/reversed_monoid.cpp
    title: traits/reversed_monoid.cpp
  - icon: ':question:'
    path: utility/ceil_log2.cpp
    title: utility/ceil_log2.cpp
  - icon: ':heavy_check_mark:'
    path: utility/index_offset.cpp
    title: utility/index_offset.cpp
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':heavy_check_mark:'
    path: utility/rec_lambda.cpp
    title: utility/rec_lambda.cpp
  - icon: ':question:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  - icon: ':question:'
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
    \ \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\n#include <iostream>\n\
    #include <vector>\n#line 2 \"container/segment_tree.cpp\"\n#include <cassert>\n\
    #line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n\nusing i32 = std::int32_t;\n\
    using u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n#line 3 \"utility/ceil_log2.cpp\"\
    \n\n__attribute__((target(\"avx2\"))) constexpr int ceil_log2(const u64 x) {\n\
    \    int e = 0;\n    while (((u64)1 << e) < x) ++e;\n    return e;\n}\n#line 2\
    \ \"utility/rep.cpp\"\n#include <algorithm>\n\nclass Range {\n    struct Iter\
    \ {\n        int itr;\n        constexpr Iter(const int pos) noexcept : itr(pos)\
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
    \ revrep(const int n) noexcept { return ReversedRange(0, n); }\n#line 7 \"container/segment_tree.cpp\"\
    \n\ntemplate <class M> class SegmentTree {\n    using T = typename M::Type;\n\
    \    int internal_size, seg_size;\n    std::vector<T> data;\n\n    void fetch(const\
    \ int k) { data[k] = M::operation(data[2 * k], data[2 * k + 1]); }\n\n  public:\n\
    \    explicit SegmentTree(const int size = 0, const T& value = M::identity())\n\
    \        : SegmentTree(std::vector<T>(size, value)) {}\n    explicit SegmentTree(const\
    \ std::vector<T>& vec) : internal_size(vec.size()) {\n        seg_size = 1 <<\
    \ ceil_log2(internal_size);\n        data = std::vector<T>(2 * seg_size, M::identity());\n\
    \        for (const int i : rep(0, internal_size)) data[seg_size + i] = vec[i];\n\
    \        for (const int i : revrep(1, seg_size)) fetch(i);\n    }\n\n    int size()\
    \ const { return internal_size; }\n\n    void assign(int i, const T& value) {\n\
    \        assert(0 <= i and i < internal_size);\n        i += seg_size;\n     \
    \   data[i] = value;\n        while (i > 1) {\n            i >>= 1;\n        \
    \    fetch(i);\n        }\n    }\n\n    T fold() const { return data[1]; }\n \
    \   T fold(int l, int r) const {\n        assert(0 <= l and l <= r and r <= internal_size);\n\
    \        l += seg_size;\n        r += seg_size;\n        T ret_l = M::identity(),\
    \ ret_r = M::identity();\n        while (l < r) {\n            if (l & 1) ret_l\
    \ = M::operation(ret_l, data[l++]);\n            if (r & 1) ret_r = M::operation(data[--r],\
    \ ret_r);\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ M::operation(ret_l, ret_r);\n    }\n\n    template <class F> int max_right(int\
    \ l, const F& f) const {\n        assert(0 <= l and l <= internal_size);\n   \
    \     assert(f(M::identity()));\n        if (l == internal_size) return internal_size;\n\
    \        l += seg_size;\n        T sum = M::identity();\n        do {\n      \
    \      while (!(l & 1)) l >>= 1;\n            if (!f(M::operation(sum, data[l])))\
    \ {\n                while (l < seg_size) {\n                    l = 2 * l;\n\
    \                    if (f(M::operation(sum, data[l]))) sum = M::operation(sum,\
    \ data[l++]);\n                }\n                return l - seg_size;\n     \
    \       }\n            sum = M::operation(sum, data[l++]);\n        } while ((l\
    \ & -l) != l);\n        return internal_size;\n    }\n\n    template <class F>\
    \ int min_left(int r, const F& f) const {\n        assert(0 <= r and r <= internal_size);\n\
    \        assert(f(M::identity()));\n        if (r == 0) return 0;\n        r +=\
    \ seg_size;\n        T sum = M::identity();\n        do {\n            r -= 1;\n\
    \            while (r > 1 and (r & 1)) r >>= 1;\n            if (!f(M::operation(data[r],\
    \ sum))) {\n                while (r < seg_size) {\n                    r = 2\
    \ * r + 1;\n                    if (f(M::operation(data[r], sum))) sum = M::operation(data[r--],\
    \ sum);\n                }\n                return r + 1 - seg_size;\n       \
    \     }\n            sum = M::operation(data[r], sum);\n        } while ((r &\
    \ -r) != r);\n        return 0;\n    }\n};\n#line 3 \"graph/basic_graph.cpp\"\n\
    #include <utility>\n#line 3 \"utility/index_offset.cpp\"\n\nclass IndexOffset\
    \ {\n    int offset, len;\n\n  public:\n    constexpr IndexOffset() noexcept :\
    \ offset(), len() {}\n    explicit constexpr IndexOffset(const int o, const int\
    \ l) noexcept : offset(o), len(l) {}\n    constexpr int size() const { return\
    \ len; }\n    constexpr int operator[](const int i) const noexcept {\n       \
    \ assert(i < len);\n        return offset + i;\n    }\n    constexpr int to_idx(const\
    \ int i) const noexcept {\n        assert(offset <= i and i < offset + len);\n\
    \        return i - offset;\n    }\n};\n#line 6 \"graph/basic_graph.cpp\"\n\n\
    template <class E = int> class BasicGraph {\n    std::vector<std::vector<E>> graph;\n\
    \n  public:\n    BasicGraph() : graph() {}\n    explicit BasicGraph(const int\
    \ n) : graph(n) {}\n\n    class EdgePtr {\n        friend class BasicGraph;\n\
    \        int u, e;\n        BasicGraph* self;\n\n        explicit EdgePtr(const\
    \ int u, const int e, BasicGraph* p) : u(u), e(e), self(p) {}\n\n      public:\n\
    \        EdgePtr() : u(0), e(0), self(nullptr) {}\n        int src() const { return\
    \ u; }\n        E& operator*() const { return self->graph[u][e]; }\n        E*\
    \ operator->() const { return &self->graph[u][e]; }\n    };\n\n    int size()\
    \ const { return graph.size(); }\n    std::vector<E>& operator[](const int u)\
    \ {\n        assert(0 <= u and u < (int)size());\n        return graph[u];\n \
    \   }\n    const std::vector<E>& operator[](const int u) const {\n        assert(0\
    \ <= u and u < (int)size());\n        return graph[u];\n    }\n\n    int add_vertex()\
    \ {\n        graph.emplace_back();\n        return size() - 1;\n    }\n    IndexOffset\
    \ add_vertices(int n) {\n        IndexOffset ret(size(), n);\n        while (n--)\
    \ graph.emplace_back();\n        return ret;\n    }\n\n    template <class...\
    \ Args> EdgePtr add_edge(const int u, Args&&... args) {\n        assert(0 <= u\
    \ and u < (int)size());\n        const int e = graph[u].size();\n        graph[u].emplace_back(std::forward<Args>(args)...);\n\
    \        return EdgePtr(u, e, this);\n    }\n};\n#line 4 \"graph/tree_manager.cpp\"\
    \n#include <variant>\n#line 2 \"utility/rec_lambda.cpp\"\n#include <type_traits>\n\
    #line 4 \"utility/rec_lambda.cpp\"\n\ntemplate <class F> struct RecursiveLambda\
    \ : private F {\n    explicit constexpr RecursiveLambda(F&& f) : F(std::forward<F>(f))\
    \ {}\n    template <class... Args> constexpr decltype(auto) operator()(Args&&...\
    \ args) const {\n        return F::operator()(*this, std::forward<Args>(args)...);\n\
    \    }\n};\n\ntemplate <class F> constexpr decltype(auto) rec_lambda(F&& f) {\
    \ return RecursiveLambda<F>(std::forward<F>(f)); }\n#line 7 \"graph/tree_manager.cpp\"\
    \n\ntemplate <class G> class TreeManager {\n  public:\n    class NodeInfo {\n\
    \        friend class TreeManager;\n        NodeInfo() : parent(0), subtree(0),\
    \ head(0), enter(0), exit(0) {}\n\n      public:\n        int parent, subtree,\
    \ head, next, enter, exit;\n    };\n\n  private:\n    using Self = TreeManager;\n\
    \    std::vector<NodeInfo> node;\n\n  public:\n    TreeManager() : node() {}\n\
    \    explicit TreeManager(const G& graph, const int root = 0) : Self(graph, std::vector<int>({root}))\
    \ {}\n    explicit TreeManager(const G& graph, const std::vector<int>& root) :\
    \ node(graph.size(), NodeInfo()) {\n        const int n = size();\n        const\
    \ auto build = rec_lambda([&](auto&& dfs, const int u, const int p) -> void {\n\
    \            node[u].parent = p;\n            node[u].subtree = 1;\n         \
    \   for (const int v : graph[u]) {\n                if (v != p) {\n          \
    \          dfs(v, u);\n                    node[u].subtree += node[v].subtree;\n\
    \                }\n            }\n        });\n        int time_stamp = 0;\n\
    \        const auto decompose = rec_lambda([&](auto&& dfs, const int u, const\
    \ int h) -> void {\n            node[u].head = h;\n            node[u].enter =\
    \ time_stamp++;\n            int& s = node[u].next;\n            s = u;\n    \
    \        for (const int v : graph[u])\n                if (v != node[u].parent\
    \ and (s == u or node[s].subtree < node[v].subtree)) s = v;\n            if (s\
    \ != u) {\n                dfs(s, h);\n                for (const int v : graph[u])\n\
    \                    if (v != node[u].parent and v != s) dfs(v, v);\n        \
    \    }\n            node[u].exit = time_stamp;\n        });\n        for (const\
    \ int r : root) {\n            assert(0 <= r < n);\n            assert(node[r].subtree\
    \ == 0);\n            build(r, r);\n            decompose(r, r);\n        }\n\
    \    }\n\n    class Path {\n        friend class TreeManager;\n        int src,\
    \ dst;\n        const Self* self;\n\n        explicit Path(const int s, const\
    \ int d, const Self* p) : src(s), dst(d), self(p) {}\n\n      public:\n      \
    \  Path begin() const { return *this; }\n        std::monostate end() const {\
    \ return {}; }\n        bool operator!=(std::monostate) const { return src !=\
    \ dst; }\n        void operator++() { src = self->node[src].parent; }\n      \
    \  std::pair<int, int> operator*() {\n            const int x = src;\n       \
    \     const int y = self->node[src].head;\n            const int z = self->node[dst].next;\n\
    \            src = (y != self->node[dst].head ? y : z);\n            return std::make_pair(x,\
    \ src);\n        }\n    };\n\n    int size() const { return node.size(); }\n \
    \   const NodeInfo& operator[](const int u) const {\n        assert(u < size());\n\
    \        return node[u];\n    }\n\n    int lca(int u, int v) const {\n       \
    \ assert(u < size());\n        assert(v < size());\n        if (node[u].enter\
    \ > node[v].enter) std::swap(u, v);\n        while (node[u].enter < node[v].enter)\
    \ {\n            if (node[u].head == node[v].head) return u;\n            v =\
    \ node[node[v].head].parent;\n        }\n        return v;\n    }\n\n    Path\
    \ path(const int des, const int anc) const {\n        assert(des < size());\n\
    \        assert(anc < size());\n        assert(node[anc].enter <= node[des].enter\
    \ and node[des].exit <= node[anc].exit);\n        return Path(des, anc, this);\n\
    \    }\n};\n#line 2 \"math/static_modint.cpp\"\n#include <ostream>\n#line 3 \"\
    math/rem_euclid.cpp\"\n\ntemplate <class T> constexpr T rem_euclid(T value, const\
    \ T& mod) {\n    assert(mod > 0);\n    return (value %= mod) >= 0 ? value : value\
    \ + mod;\n}\n#line 2 \"math/totient.cpp\"\n\ntemplate <class T> constexpr T totient(T\
    \ x) {\n    T ret = x;\n    for (T i = 2; i * i <= x; ++i) {\n        if (x %\
    \ i == 0) {\n            ret /= i;\n            ret *= i - 1;\n            while\
    \ (x % i == 0) x /= i;\n        }\n    }\n    if (x > 1) {\n        ret /= x;\n\
    \        ret *= x - 1;\n    }\n    return ret;\n}\n#line 7 \"math/static_modint.cpp\"\
    \n\ntemplate <u32 MOD, std::enable_if_t<((u32)1 <= MOD and MOD <= ((u32)1 << 31))>*\
    \ = nullptr> class StaticModint {\n    using Self = StaticModint;\n\n    static\
    \ inline constexpr u32 PHI = totient(MOD);\n    u32 v;\n\n  public:\n    static\
    \ constexpr u32 mod() noexcept { return MOD; }\n\n    template <class T, std::enable_if_t<std::is_integral_v<T>>*\
    \ = nullptr>\n    static constexpr T normalize(const T& x) noexcept {\n      \
    \  return rem_euclid<std::common_type_t<T, i64>>(x, MOD);\n    }\n\n    constexpr\
    \ StaticModint() noexcept : v(0) {}\n    template <class T> constexpr StaticModint(const\
    \ T& x) noexcept : v(normalize(x)) {}\n    template <class T> static constexpr\
    \ Self raw(const T& x) noexcept {\n        Self ret;\n        ret.v = x;\n   \
    \     return ret;\n    }\n\n    constexpr u32 val() const noexcept { return v;\
    \ }\n    constexpr Self neg() const noexcept { return raw(v == 0 ? 0 : MOD - v);\
    \ }\n    constexpr Self inv() const noexcept { return pow(PHI - 1); }\n    constexpr\
    \ Self pow(u64 exp) const noexcept {\n        Self ret(1), mult(*this);\n    \
    \    for (; exp > 0; exp >>= 1) {\n            if (exp & 1) ret *= mult;\n   \
    \         mult *= mult;\n        }\n        return ret;\n    }\n\n    constexpr\
    \ Self operator-() const noexcept { return neg(); }\n    constexpr Self operator~()\
    \ const noexcept { return inv(); }\n\n    constexpr Self operator+(const Self&\
    \ rhs) const noexcept { return Self(*this) += rhs; }\n    constexpr Self& operator+=(const\
    \ Self& rhs) noexcept {\n        if ((v += rhs.v) >= MOD) v -= MOD;\n        return\
    \ *this;\n    }\n\n    constexpr Self operator-(const Self& rhs) const noexcept\
    \ { return Self(*this) -= rhs; }\n    constexpr Self& operator-=(const Self& rhs)\
    \ noexcept {\n        if (v < rhs.v) v += MOD;\n        v -= rhs.v;\n        return\
    \ *this;\n    }\n\n    constexpr Self operator*(const Self& rhs) const noexcept\
    \ { return Self(*this) *= rhs; }\n    constexpr Self& operator*=(const Self& rhs)\
    \ noexcept {\n        v = (u64)v * rhs.v % MOD;\n        return *this;\n    }\n\
    \n    constexpr Self operator/(const Self& rhs) const noexcept { return Self(*this)\
    \ /= rhs; }\n    constexpr Self& operator/=(const Self& rhs) noexcept { return\
    \ *this *= rhs.inv(); }\n\n    constexpr bool operator==(const Self& rhs) const\
    \ noexcept { return v == rhs.v; }\n    constexpr bool operator!=(const Self& rhs)\
    \ const noexcept { return v != rhs.v; }\n    friend std::ostream& operator<<(std::ostream&\
    \ stream, const Self& rhs) { return stream << rhs.v; }\n};\n\nusing Modint1000000007\
    \ = StaticModint<1000000007>;\nusing Modint998244353 = StaticModint<998244353>;\n\
    #line 2 \"traits/affine_composite_monoid.cpp\"\n\ntemplate <class T> struct Affine\
    \ {\n    T a, b;\n    constexpr Affine(const T& a = 1, const T& b = 0) : a(a),\
    \ b(b) {}\n    constexpr T eval(const T& x) const { return a * x + b; }\n    constexpr\
    \ Affine operator+(const Affine& other) const { return affine(a + other.a, b +\
    \ other.b); }\n    constexpr Affine composite(const Affine& other) const { return\
    \ Affine(a * other.a, b * other.a + other.b); }\n};\n\ntemplate <class T> struct\
    \ AffineCompositeMonoid {\n    using Type = Affine<T>;\n    static constexpr Type\
    \ identity() { return Type(); }\n    static constexpr Type operation(const Type&\
    \ l, const Type& r) noexcept { return l.composite(r); }\n};\n#line 2 \"traits/reversed_monoid.cpp\"\
    \n\ntemplate <class M> struct ReversedMonoid {\n    using Type = typename M::Type;\n\
    \    static constexpr Type identity() { return M::identity(); }\n    static constexpr\
    \ Type operation(const Type& l, const Type& r) { return M::operation(r, l); }\n\
    };\n#line 12 \"test/heavy_light_decomposition.test.cpp\"\n\nusing Fp = Modint998244353;\n\
    using Line = Affine<Fp>;\nusing Monoid = AffineCompositeMonoid<Fp>;\nusing RevMonoid\
    \ = ReversedMonoid<Monoid>;\n\nint main() {\n    int N, Q;\n    std::cin >> N\
    \ >> Q;\n    std::vector<Line> F(N);\n    for (auto& f : F) {\n        u32 x,\
    \ y;\n        std::cin >> x >> y;\n        f = Line(x, y);\n    }\n    BasicGraph\
    \ graph(N);\n    for (const auto _ : rep(1, N)) {\n        int x, y;\n       \
    \ std::cin >> x >> y;\n        graph.add_edge(x, y);\n        graph.add_edge(y,\
    \ x);\n    }\n    TreeManager tree(graph);\n    SegmentTree<Monoid> seg;\n   \
    \ SegmentTree<RevMonoid> seg_rev;\n    {\n        std::vector<Line> build(N);\n\
    \        for (const auto i : rep(0, N)) {\n            build[tree[i].enter] =\
    \ F[i];\n        }\n        seg = SegmentTree<Monoid>(build);\n        seg_rev\
    \ = SegmentTree<RevMonoid>(build);\n    }\n    while (Q--) {\n        int t;\n\
    \        std::cin >> t;\n        if (t == 0) {\n            int p;\n         \
    \   u32 c, d;\n            std::cin >> p >> c >> d;\n            F[p] = Line(c,\
    \ d);\n            seg.assign(tree[p].enter, F[p]);\n            seg_rev.assign(tree[p].enter,\
    \ F[p]);\n        } else {\n            int u, v;\n            u32 x;\n      \
    \      std::cin >> u >> v >> x;\n            const auto lca = tree.lca(u, v);\n\
    \            Line sum_u, sum_v;\n            for (const auto [a, b] : tree.path(u,\
    \ lca)) {\n                sum_u = sum_u.composite(seg_rev.fold(tree[b].enter,\
    \ tree[a].enter + 1));\n            }\n            for (const auto [a, b] : tree.path(v,\
    \ lca)) {\n                sum_v = seg.fold(tree[b].enter, tree[a].enter + 1).composite(sum_v);\n\
    \            }\n            std::cout << sum_u.composite(F[lca]).composite(sum_v).eval(x)\
    \ << '\\n';\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n#include <iostream>\n#include <vector>\n#include \"../container/segment_tree.cpp\"\
    \n#include \"../graph/basic_graph.cpp\"\n#include \"../graph/tree_manager.cpp\"\
    \n#include \"../math/static_modint.cpp\"\n#include \"../traits/affine_composite_monoid.cpp\"\
    \n#include \"../traits/reversed_monoid.cpp\"\n#include \"../utility/int_alias.cpp\"\
    \n#include \"../utility/rep.cpp\"\n\nusing Fp = Modint998244353;\nusing Line =\
    \ Affine<Fp>;\nusing Monoid = AffineCompositeMonoid<Fp>;\nusing RevMonoid = ReversedMonoid<Monoid>;\n\
    \nint main() {\n    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<Line>\
    \ F(N);\n    for (auto& f : F) {\n        u32 x, y;\n        std::cin >> x >>\
    \ y;\n        f = Line(x, y);\n    }\n    BasicGraph graph(N);\n    for (const\
    \ auto _ : rep(1, N)) {\n        int x, y;\n        std::cin >> x >> y;\n    \
    \    graph.add_edge(x, y);\n        graph.add_edge(y, x);\n    }\n    TreeManager\
    \ tree(graph);\n    SegmentTree<Monoid> seg;\n    SegmentTree<RevMonoid> seg_rev;\n\
    \    {\n        std::vector<Line> build(N);\n        for (const auto i : rep(0,\
    \ N)) {\n            build[tree[i].enter] = F[i];\n        }\n        seg = SegmentTree<Monoid>(build);\n\
    \        seg_rev = SegmentTree<RevMonoid>(build);\n    }\n    while (Q--) {\n\
    \        int t;\n        std::cin >> t;\n        if (t == 0) {\n            int\
    \ p;\n            u32 c, d;\n            std::cin >> p >> c >> d;\n          \
    \  F[p] = Line(c, d);\n            seg.assign(tree[p].enter, F[p]);\n        \
    \    seg_rev.assign(tree[p].enter, F[p]);\n        } else {\n            int u,\
    \ v;\n            u32 x;\n            std::cin >> u >> v >> x;\n            const\
    \ auto lca = tree.lca(u, v);\n            Line sum_u, sum_v;\n            for\
    \ (const auto [a, b] : tree.path(u, lca)) {\n                sum_u = sum_u.composite(seg_rev.fold(tree[b].enter,\
    \ tree[a].enter + 1));\n            }\n            for (const auto [a, b] : tree.path(v,\
    \ lca)) {\n                sum_v = seg.fold(tree[b].enter, tree[a].enter + 1).composite(sum_v);\n\
    \            }\n            std::cout << sum_u.composite(F[lca]).composite(sum_v).eval(x)\
    \ << '\\n';\n        }\n    }\n    return 0;\n}"
  dependsOn:
  - container/segment_tree.cpp
  - utility/ceil_log2.cpp
  - utility/int_alias.cpp
  - utility/rep.cpp
  - utility/revrep.cpp
  - graph/basic_graph.cpp
  - utility/index_offset.cpp
  - graph/tree_manager.cpp
  - utility/rec_lambda.cpp
  - math/static_modint.cpp
  - math/rem_euclid.cpp
  - math/totient.cpp
  - traits/affine_composite_monoid.cpp
  - traits/reversed_monoid.cpp
  isVerificationFile: true
  path: test/heavy_light_decomposition.test.cpp
  requiredBy: []
  timestamp: '2021-12-17 09:48:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/heavy_light_decomposition.test.cpp
layout: document
redirect_from:
- /verify/test/heavy_light_decomposition.test.cpp
- /verify/test/heavy_light_decomposition.test.cpp.html
title: test/heavy_light_decomposition.test.cpp
---
