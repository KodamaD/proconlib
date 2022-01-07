---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: container/fenwick_tree.cpp
    title: container/fenwick_tree.cpp
  - icon: ':heavy_check_mark:'
    path: internal/enable_avx2.cpp
    title: internal/enable_avx2.cpp
  - icon: ':heavy_check_mark:'
    path: traits/sum_group.cpp
    title: traits/sum_group.cpp
  - icon: ':heavy_check_mark:'
    path: utility/bit_width.cpp
    title: utility/bit_width.cpp
  - icon: ':heavy_check_mark:'
    path: utility/ceil_log2.cpp
    title: utility/ceil_log2.cpp
  - icon: ':heavy_check_mark:'
    path: utility/countl_zero.cpp
    title: utility/countl_zero.cpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':heavy_check_mark:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/fenwick_tree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\
    \n#include <iostream>\n#line 2 \"container/fenwick_tree.cpp\"\n#include <cassert>\n\
    #include <vector>\n#line 2 \"internal/enable_avx2.cpp\"\n\n#ifdef ENABLE_AVX2\n\
    #define TARGET_AVX2 __attribute__((target(\"avx2\")))\n#else\n#define TARGET_AVX2\n\
    #endif\n#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n\nusing i32 = std::int32_t;\n\
    using u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n#line 4 \"utility/countl_zero.cpp\"\
    \n\nTARGET_AVX2 constexpr int countl_zero(u64 x) {\n#ifdef __GNUC__\n    return\
    \ x == 0 ? 64 : __builtin_clzll(x);\n#else\n    x |= x >> 1;\n    x |= x >> 2;\n\
    \    x |= x >> 4;\n    x |= x >> 8;\n    x |= x >> 16;\n    x |= x >> 32;\n  \
    \  return 64 - countr_zero(~x);\n#endif\n}\n#line 4 \"utility/bit_width.cpp\"\n\
    \nTARGET_AVX2 constexpr int bit_width(const u64 x) { return 64 - countl_zero(x);\
    \ }\n#line 5 \"utility/ceil_log2.cpp\"\n\nTARGET_AVX2 constexpr int ceil_log2(const\
    \ u64 x) {\n#ifdef __GNUC__\n    return x == 0 ? 0 : bit_width(x - 1);\n#else\n\
    \    int e = 0;\n    while (((u64)1 << e) < x) ++e;\n    return e;\n#endif\n}\n\
    #line 5 \"container/fenwick_tree.cpp\"\n\ntemplate <class G> class FenwickTree\
    \ {\n    using T = typename G::Type;\n\n    int logn;\n    std::vector<T> data;\n\
    \n  public:\n    explicit FenwickTree(const int size = 0) {\n        logn = ceil_log2(size\
    \ + 1) - 1;\n        data = std::vector<T>(size + 1, G::identity());\n    }\n\n\
    \    int size() const { return data.size() - 1; }\n\n    void add(int i, const\
    \ T& x) {\n        assert(0 <= i and i < size());\n        i += 1;\n        while\
    \ (i <= size()) {\n            data[i] = G::operation(data[i], x);\n         \
    \   i += i & -i;\n        }\n    }\n\n    T fold() const { return fold(0, size());\
    \ }\n    T fold(int l, int r) const {\n        assert(0 <= l and l <= r and r\
    \ <= size());\n        T ret = G::identity();\n        while (l < r) {\n     \
    \       ret = G::operation(ret, data[r]);\n            r -= r & -r;\n        }\n\
    \        while (r < l) {\n            ret = G::operation(ret, G::inverse(data[l]));\n\
    \            l -= l & -l;\n        }\n        return ret;\n    }\n\n    template\
    \ <class F> int max_right(const F& f) const {\n        assert(f(G::identity()));\n\
    \        int i = 0;\n        T sum = G::identity();\n        for (int k = (1 <<\
    \ logn); k > 0; k >>= 1) {\n            if (i + k <= size() && f(G::operation(sum,\
    \ data[i + k]))) {\n                sum = G::operation(sum, data[i += k]);\n \
    \           }\n        }\n        return i;\n    }\n};\n#line 2 \"traits/sum_group.cpp\"\
    \n\ntemplate <class T> struct SumGroup {\n    using Type = T;\n    static constexpr\
    \ T identity() { return T(0); }\n    static constexpr T operation(const T& l,\
    \ const T& r) { return l + r; }\n    static constexpr T inverse(const T& x) {\
    \ return -x; }\n};\n#line 2 \"utility/rep.cpp\"\n#include <algorithm>\n\nclass\
    \ Range {\n    struct Iter {\n        int itr;\n        constexpr Iter(const int\
    \ pos) noexcept : itr(pos) {}\n        constexpr void operator++() noexcept {\
    \ ++itr; }\n        constexpr bool operator!=(const Iter& other) const noexcept\
    \ { return itr != other.itr; }\n        constexpr int operator*() const noexcept\
    \ { return itr; }\n    };\n    const Iter first, last;\n\n  public:\n    explicit\
    \ constexpr Range(const int first, const int last) noexcept : first(first), last(std::max(first,\
    \ last)) {}\n    constexpr Iter begin() const noexcept { return first; }\n   \
    \ constexpr Iter end() const noexcept { return last; }\n};\n\nconstexpr Range\
    \ rep(const int l, const int r) noexcept { return Range(l, r); }\nconstexpr Range\
    \ rep(const int n) noexcept { return Range(0, n); }\n#line 7 \"test/fenwick_tree.test.cpp\"\
    \n\nint main() {\n    int N, Q;\n    std::cin >> N >> Q;\n    FenwickTree<SumGroup<u64>>\
    \ fen(N);\n    for (const int i : rep(0, N)) {\n        u64 x;\n        std::cin\
    \ >> x;\n        fen.add(i, x);\n    }\n    while (Q--) {\n        int t;\n  \
    \      std::cin >> t;\n        if (t == 0) {\n            int p;\n           \
    \ u64 x;\n            std::cin >> p >> x;\n            fen.add(p, x);\n      \
    \  } else {\n            int l, r;\n            std::cin >> l >> r;\n        \
    \    std::cout << fen.fold(l, r) << '\\n';\n        }\n    }\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include <iostream>\n#include \"../container/fenwick_tree.cpp\"\n#include \"../traits/sum_group.cpp\"\
    \n#include \"../utility/int_alias.cpp\"\n#include \"../utility/rep.cpp\"\n\nint\
    \ main() {\n    int N, Q;\n    std::cin >> N >> Q;\n    FenwickTree<SumGroup<u64>>\
    \ fen(N);\n    for (const int i : rep(0, N)) {\n        u64 x;\n        std::cin\
    \ >> x;\n        fen.add(i, x);\n    }\n    while (Q--) {\n        int t;\n  \
    \      std::cin >> t;\n        if (t == 0) {\n            int p;\n           \
    \ u64 x;\n            std::cin >> p >> x;\n            fen.add(p, x);\n      \
    \  } else {\n            int l, r;\n            std::cin >> l >> r;\n        \
    \    std::cout << fen.fold(l, r) << '\\n';\n        }\n    }\n    return 0;\n}"
  dependsOn:
  - container/fenwick_tree.cpp
  - utility/ceil_log2.cpp
  - internal/enable_avx2.cpp
  - utility/bit_width.cpp
  - utility/countl_zero.cpp
  - utility/int_alias.cpp
  - traits/sum_group.cpp
  - utility/rep.cpp
  isVerificationFile: true
  path: test/fenwick_tree.test.cpp
  requiredBy: []
  timestamp: '2022-01-07 21:48:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/fenwick_tree.test.cpp
layout: document
redirect_from:
- /verify/test/fenwick_tree.test.cpp
- /verify/test/fenwick_tree.test.cpp.html
title: test/fenwick_tree.test.cpp
---
