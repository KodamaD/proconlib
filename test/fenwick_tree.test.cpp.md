---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: container/fenwick_tree.cpp
    title: container/fenwick_tree.cpp
  - icon: ':question:'
    path: utility/ceil_log2.cpp
    title: utility/ceil_log2.cpp
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':question:'
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
    \n#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n\nusing i32 = std::int32_t;\n\
    using u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n#line 2 \"utility/rep.cpp\"\
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
    \ { return Range(0, n); }\n#line 2 \"container/fenwick_tree.cpp\"\n#include <cassert>\n\
    #include <vector>\n#line 3 \"utility/ceil_log2.cpp\"\n\n__attribute__((target(\"\
    avx2\"))) constexpr int ceil_log2(const u64 x) {\n    int e = 0;\n    while (((u64)1\
    \ << e) < x) ++e;\n    return e;\n}\n#line 5 \"container/fenwick_tree.cpp\"\n\n\
    template <class T> class FenwickTree {\n    int logn;\n    std::vector<T> data;\n\
    \n  public:\n    explicit FenwickTree(const int size = 0) {\n        logn = ceil_log2(size\
    \ + 1) - 1;\n        data = std::vector<T>(size + 1, T(0));\n    }\n\n    int\
    \ size() const { return data.size() - 1; }\n\n    void add(int i, const T& x)\
    \ {\n        assert(0 <= i and i < size());\n        i += 1;\n        while (i\
    \ < data.size()) {\n            data[i] += x;\n            i += i & -i;\n    \
    \    }\n    }\n    void subtract(int i, const T& x) {\n        assert(0 <= i and\
    \ i < size());\n        i += 1;\n        while (i < data.size()) {\n         \
    \   data[i] -= x;\n            i += i & -i;\n        }\n    }\n\n    T fold()\
    \ const { return fold(0, size()); }\n    T fold(int l, int r) const {\n      \
    \  assert(0 <= l and l <= r and r <= size());\n        T ret(0);\n        while\
    \ (l < r) {\n            ret += data[r];\n            r -= r & -r;\n        }\n\
    \        while (r < l) {\n            ret -= data[l];\n            l -= l & -l;\n\
    \        }\n        return ret;\n    }\n\n    template <class F> int max_right(const\
    \ F& f) const {\n        assert(f(T(0)));\n        int i = 0;\n        T sum(0);\n\
    \        for (int k = (1 << logn); k > 0; k >>= 1) {\n            if (i + k <=\
    \ size() && f(sum + data[i + k])) {\n                i += k;\n               \
    \ sum += data[i];\n            }\n        }\n        return i;\n    }\n};\n#line\
    \ 5 \"test/fenwick_tree.test.cpp\"\n#include <iostream>\n\nint main() {\n    int\
    \ N, Q;\n    std::cin >> N >> Q;\n    FenwickTree<u64> fen(N);\n    for (const\
    \ int i: rep(0, N)) {\n        u64 x;\n        std::cin >> x;\n        fen.add(i,\
    \ x);\n    }\n    while (Q--) {\n        int t;\n        std::cin >> t;\n    \
    \    if (t == 0) {\n            int p;\n            u64 x;\n            std::cin\
    \ >> p >> x;\n            fen.add(p, x);\n        }\n        else {\n        \
    \    int l, r;\n            std::cin >> l >> r;\n            std::cout << fen.fold(l,\
    \ r) << '\\n';\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include \"../utility/int_alias.cpp\"\n#include \"../utility/rep.cpp\"\n#include\
    \ \"../container/fenwick_tree.cpp\"\n#include <iostream>\n\nint main() {\n   \
    \ int N, Q;\n    std::cin >> N >> Q;\n    FenwickTree<u64> fen(N);\n    for (const\
    \ int i: rep(0, N)) {\n        u64 x;\n        std::cin >> x;\n        fen.add(i,\
    \ x);\n    }\n    while (Q--) {\n        int t;\n        std::cin >> t;\n    \
    \    if (t == 0) {\n            int p;\n            u64 x;\n            std::cin\
    \ >> p >> x;\n            fen.add(p, x);\n        }\n        else {\n        \
    \    int l, r;\n            std::cin >> l >> r;\n            std::cout << fen.fold(l,\
    \ r) << '\\n';\n        }\n    }\n    return 0;\n}"
  dependsOn:
  - utility/int_alias.cpp
  - utility/rep.cpp
  - container/fenwick_tree.cpp
  - utility/ceil_log2.cpp
  isVerificationFile: true
  path: test/fenwick_tree.test.cpp
  requiredBy: []
  timestamp: '2021-12-17 09:48:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/fenwick_tree.test.cpp
layout: document
redirect_from:
- /verify/test/fenwick_tree.test.cpp
- /verify/test/fenwick_tree.test.cpp.html
title: test/fenwick_tree.test.cpp
---
