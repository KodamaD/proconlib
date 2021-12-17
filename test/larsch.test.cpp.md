---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/larsch.cpp
    title: algorithm/larsch.cpp
  - icon: ':heavy_check_mark:'
    path: container/segment_tree.cpp
    title: container/segment_tree.cpp
  - icon: ':heavy_check_mark:'
    path: traits/max_monoid.cpp
    title: traits/max_monoid.cpp
  - icon: ':question:'
    path: traits/optional_monoid.cpp
    title: traits/optional_monoid.cpp
  - icon: ':question:'
    path: utility/ceil_log2.cpp
    title: utility/ceil_log2.cpp
  - icon: ':heavy_check_mark:'
    path: utility/infty.cpp
    title: utility/infty.cpp
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/challenges/sources/UOA/UAPC/3086?year=2020
    links:
    - https://onlinejudge.u-aizu.ac.jp/challenges/sources/UOA/UAPC/3086?year=2020
  bundledCode: "#line 1 \"test/larsch.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/challenges/sources/UOA/UAPC/3086?year=2020\"\
    \n#line 2 \"algorithm/larsch.cpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <functional>\n#include <memory>\n#include <vector>\n\nclass LARSCH {\n\
    \    using Select = std::function<bool(int, int, int)>;\n    struct ReduceRow;\n\
    \    struct ReduceCol;\n\n    struct ReduceRow {\n        int n, m, x, k;\n  \
    \      Select f;\n        std::unique_ptr<ReduceCol> rec;\n\n        explicit\
    \ ReduceRow(const int n_, const Select& f_) : n(n_), m(0), x(0), k(0), f(f_),\
    \ rec() {\n            const int h = n / 2;\n            if (h != 0) rec = std::make_unique<ReduceCol>(h,\
    \ [&](int i, int j, int k) { return f(2 * i + 1, j, k); });\n        }\n\n   \
    \     void add_column() {\n            if ((x & 1) and f(x, k, m)) k = m;\n  \
    \          if (rec) rec->add_column();\n            m += 1;\n        }\n\n   \
    \     int get_argmin() {\n            if (x & 1) {\n                x += 1;\n\
    \                return k;\n            } else {\n                int ret = k;\n\
    \                if (x + 1 == n)\n                    k = m - 1;\n           \
    \     else\n                    k = rec->get_argmin();\n                for (int\
    \ j = ret + 1; j <= k; j += 1)\n                    if (f(x, ret, j)) ret = j;\n\
    \                x += 1;\n                return ret;\n            }\n       \
    \ }\n    };\n\n    struct ReduceCol {\n        int n, m, x, y;\n        std::vector<int>\
    \ c;\n        Select f;\n        ReduceRow rec;\n\n        explicit ReduceCol(const\
    \ int n_, const Select& f_)\n            : n(n_), m(0), x(0), y(0), c(), f(f_),\
    \ rec(n_, [&](int i, int j, int k) { return f(i, c[j], c[k]); }) {}\n\n      \
    \  void add_column() {\n            while (true) {\n                const int\
    \ i = c.size();\n                if (i <= x or !f(i - 1, c[i - 1], m)) break;\n\
    \                c.pop_back();\n            }\n            if (c.size() != n)\
    \ c.push_back(m);\n            m += 1;\n        }\n\n        int get_argmin()\
    \ {\n            x += 1;\n            while (y < std::min(x, (int)c.size())) {\n\
    \                rec.add_column();\n                y += 1;\n            }\n \
    \           return c[rec.get_argmin()];\n        }\n    };\n\n    int row, col;\n\
    \    ReduceRow machine;\n\n  public:\n    explicit LARSCH(const int n, const Select&\
    \ f) : row(n), col(0), machine(n, f) {}\n\n    void add_column() {\n        assert(row\
    \ != 0);\n        col += 1;\n        machine.add_column();\n    }\n\n    int get_argmin()\
    \ {\n        assert(row != 0 and col != 0);\n        row -= 1;\n        return\
    \ machine.get_argmin();\n    }\n};\n\ntemplate <class T, class Comp = std::less<T>>\
    \ class CompLARSCH {\n    std::function<T(int, int)> func;\n    Comp comp;\n \
    \   LARSCH machine;\n\n  public:\n    explicit CompLARSCH(const int n, const std::function<T(int,\
    \ int)>& f, const Comp& c = Comp())\n        : func(f), comp(c), machine(n, [&](int\
    \ i, int j, int k) { return comp(func(i, k), func(i, j)); }) {}\n\n    void add_column()\
    \ { machine.add_column(); }\n\n    int get_argmin() { return machine.get_argmin();\
    \ }\n};\n#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n\nusing i32 =\
    \ std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing\
    \ u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    #line 3 \"utility/ceil_log2.cpp\"\n\n__attribute__((target(\"avx2\"))) constexpr\
    \ int ceil_log2(const u64 x) {\n    int e = 0;\n    while (((u64)1 << e) < x)\
    \ ++e;\n    return e;\n}\n#line 3 \"utility/rep.cpp\"\n\nclass Range {\n    struct\
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
    \ -r) != r);\n        return 0;\n    }\n};\n#line 2 \"traits/optional_monoid.cpp\"\
    \n#include <optional>\n#include <utility>\n\ntemplate <class S> struct OptionalMonoid\
    \ {\n    using Type = std::optional<typename S::Type>;\n    static constexpr Type\
    \ identity() { return std::nullopt; }\n    static constexpr Type operation(const\
    \ Type& l, const Type& r) {\n        if (!l) return r;\n        if (!r) return\
    \ l;\n        return Type(std::in_place, S::operation(*l, *r));\n    }\n};\n#line\
    \ 4 \"traits/max_monoid.cpp\"\n\ntemplate <class T> struct MaxSemiGroup {\n  \
    \  using Type = T;\n    static constexpr T operation(const T& l, const T& r) {\
    \ return std::max(l, r); }\n};\n\ntemplate <class T> using MaxMonoid = OptionalMonoid<MaxSemiGroup<T>>;\n\
    #line 2 \"utility/infty.cpp\"\n#include <limits>\n\ntemplate <class T, T Div =\
    \ 2> constexpr T INFTY = std::numeric_limits<T>::max() / Div;\n#line 8 \"test/larsch.test.cpp\"\
    \n#include <iostream>\n#line 10 \"test/larsch.test.cpp\"\n\nint main() {\n   \
    \ int N, L;\n    std::cin >> N >> L;\n    std::vector<std::optional<i64>> A(N);\n\
    \    for (auto& x : A) {\n        i64 t;\n        std::cin >> t;\n        x =\
    \ t;\n    }\n    SegmentTree<MaxMonoid<i64>> seg(A);\n    std::vector<i64> dp(N\
    \ + 1);\n    const auto transit = [&](int i, int j) {\n        i += 1;\n     \
    \   if (j + L > i) return -INFTY<i64>;\n        return dp[j] + *seg.fold(j, i);\n\
    \    };\n    CompLARSCH<i64, std::greater<i64>> larsch(N, transit);\n    for (const\
    \ auto i : rep(0, N)) {\n        larsch.add_column();\n        dp[i + 1] = transit(i,\
    \ larsch.get_argmin());\n    }\n    std::cout << dp[N] << '\\n';\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/challenges/sources/UOA/UAPC/3086?year=2020\"\
    \n#include \"../algorithm/larsch.cpp\"\n#include \"../container/segment_tree.cpp\"\
    \n#include \"../traits/max_monoid.cpp\"\n#include \"../utility/infty.cpp\"\n#include\
    \ \"../utility/int_alias.cpp\"\n#include \"../utility/rep.cpp\"\n#include <iostream>\n\
    #include <vector>\n\nint main() {\n    int N, L;\n    std::cin >> N >> L;\n  \
    \  std::vector<std::optional<i64>> A(N);\n    for (auto& x : A) {\n        i64\
    \ t;\n        std::cin >> t;\n        x = t;\n    }\n    SegmentTree<MaxMonoid<i64>>\
    \ seg(A);\n    std::vector<i64> dp(N + 1);\n    const auto transit = [&](int i,\
    \ int j) {\n        i += 1;\n        if (j + L > i) return -INFTY<i64>;\n    \
    \    return dp[j] + *seg.fold(j, i);\n    };\n    CompLARSCH<i64, std::greater<i64>>\
    \ larsch(N, transit);\n    for (const auto i : rep(0, N)) {\n        larsch.add_column();\n\
    \        dp[i + 1] = transit(i, larsch.get_argmin());\n    }\n    std::cout <<\
    \ dp[N] << '\\n';\n    return 0;\n}"
  dependsOn:
  - algorithm/larsch.cpp
  - container/segment_tree.cpp
  - utility/ceil_log2.cpp
  - utility/int_alias.cpp
  - utility/rep.cpp
  - utility/revrep.cpp
  - traits/max_monoid.cpp
  - traits/optional_monoid.cpp
  - utility/infty.cpp
  isVerificationFile: true
  path: test/larsch.test.cpp
  requiredBy: []
  timestamp: '2021-12-17 09:48:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/larsch.test.cpp
layout: document
redirect_from:
- /verify/test/larsch.test.cpp
- /verify/test/larsch.test.cpp.html
title: test/larsch.test.cpp
---
