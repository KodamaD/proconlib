---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: container/dual_segment_tree.cpp
    title: container/dual_segment_tree.cpp
  - icon: ':heavy_check_mark:'
    path: traits/assign_monoid.cpp
    title: traits/assign_monoid.cpp
  - icon: ':heavy_check_mark:'
    path: utility/ceil_log2.cpp
    title: utility/ceil_log2.cpp
  - icon: ':heavy_check_mark:'
    path: utility/countr_zero.cpp
    title: utility/countr_zero.cpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
  bundledCode: "#line 1 \"test/dual_segment_tree.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\"\
    \n#line 2 \"container/dual_segment_tree.cpp\"\n#include <cassert>\n#include <vector>\n\
    #line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n\nusing i32 = std::int32_t;\n\
    using u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n#line 3 \"utility/ceil_log2.cpp\"\
    \n\n__attribute__((target(\"avx2\"))) constexpr int ceil_log2(const u64 x) {\n\
    \    int e = 0;\n    while (((u64)1 << e) < x) ++e;\n    return e;\n}\n#line 3\
    \ \"utility/countr_zero.cpp\"\n\n__attribute__((target(\"avx2\"))) constexpr int\
    \ countr_zero(const u64 x) { return x == 0 ? 64 : __builtin_ctzll(x); }\n#line\
    \ 2 \"utility/rep.cpp\"\n#include <algorithm>\n\nclass Range {\n    struct Iter\
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
    \ revrep(const int n) noexcept { return ReversedRange(0, n); }\n#line 9 \"container/dual_segment_tree.cpp\"\
    \n\ntemplate <class M> class DualSegmentTree {\n    using T = typename M::Type;\n\
    \    int internal_size, logn;\n    std::vector<T> lazy;\n\n    void apply(const\
    \ int k, const T& e) { lazy[k] = M::operation(lazy[k], e); }\n    void flush(const\
    \ int k) {\n        apply(2 * k, lazy[k]);\n        apply(2 * k + 1, lazy[k]);\n\
    \        lazy[k] = M::identity();\n    }\n    void push(const int k) {\n     \
    \   for (const int d : revrep(countr_zero(k) + 1, logn + 1)) {\n            flush(k\
    \ >> d);\n        }\n    }\n\n  public:\n    explicit DualSegmentTree(const int\
    \ size = 0, const T& value = M::identity())\n        : DualSegmentTree(std::vector<T>(size,\
    \ value)) {}\n    explicit DualSegmentTree(const std::vector<T>& vec) : internal_size(vec.size())\
    \ {\n        logn = ceil_log2(internal_size);\n        lazy = std::vector<T>(2\
    \ * internal_size, M::identity());\n        for (const int i : rep(0, internal_size))\
    \ lazy[i] = vec[i];\n    }\n\n    int size() const { return internal_size; }\n\
    \n    void operate(int l, int r, const T& e) {\n        assert(l <= r and r <=\
    \ internal_size);\n        l += internal_size;\n        r += internal_size;\n\
    \        push(l);\n        push(r);\n        while (l < r) {\n            if (l\
    \ & 1) apply(l++, e);\n            if (r & 1) apply(--r, e);\n            l >>=\
    \ 1;\n            r >>= 1;\n        }\n    }\n    void assign(int i, const T&\
    \ e) {\n        assert(i < internal_size);\n        i += internal_size;\n    \
    \    for (const int d : revrep(1, logn + 1)) flush(i >> d);\n        lazy[i] =\
    \ e;\n    }\n\n    T get(int i) const {\n        assert(i < internal_size);\n\
    \        i += internal_size;\n        T ret = M::identity();\n        while (i\
    \ > 0) {\n            ret = M::operation(ret, lazy[i]);\n            i >>= 1;\n\
    \        }\n        return ret;\n    }\n};\n#line 3 \"test/dual_segment_tree.test.cpp\"\
    \n#include <iostream>\n#include <optional>\n#line 3 \"traits/assign_monoid.cpp\"\
    \n\ntemplate <class T> struct AssignMonoid {\n    using Type = std::optional<T>;\n\
    \    static constexpr Type identity() { return std::nullopt; }\n    static constexpr\
    \ Type operation(const Type& l, const Type& r) { return r ? r : l; }\n};\n#line\
    \ 7 \"test/dual_segment_tree.test.cpp\"\n\nint main() {\n    int N, Q;\n    std::cin\
    \ >> N >> Q;\n    DualSegmentTree<AssignMonoid<u32>> seg(N);\n    while (Q--)\
    \ {\n        int t;\n        std::cin >> t;\n        if (t == 0) {\n         \
    \   int l, r;\n            std::cin >> l >> r;\n            u32 x;\n         \
    \   std::cin >> x;\n            seg.operate(l, r + 1, x);\n        } else {\n\
    \            int p;\n            std::cin >> p;\n            const auto e = seg.get(p);\n\
    \            if (!e) {\n                std::cout << (1u << 31) - 1 << '\\n';\n\
    \            } else {\n                std::cout << *e << '\\n';\n           \
    \ }\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\"\
    \n#include \"../container/dual_segment_tree.cpp\"\n#include <iostream>\n#include\
    \ <optional>\n#include \"../utility/int_alias.cpp\"\n#include \"../traits/assign_monoid.cpp\"\
    \n\nint main() {\n    int N, Q;\n    std::cin >> N >> Q;\n    DualSegmentTree<AssignMonoid<u32>>\
    \ seg(N);\n    while (Q--) {\n        int t;\n        std::cin >> t;\n       \
    \ if (t == 0) {\n            int l, r;\n            std::cin >> l >> r;\n    \
    \        u32 x;\n            std::cin >> x;\n            seg.operate(l, r + 1,\
    \ x);\n        } else {\n            int p;\n            std::cin >> p;\n    \
    \        const auto e = seg.get(p);\n            if (!e) {\n                std::cout\
    \ << (1u << 31) - 1 << '\\n';\n            } else {\n                std::cout\
    \ << *e << '\\n';\n            }\n        }\n    }\n    return 0;\n}"
  dependsOn:
  - container/dual_segment_tree.cpp
  - utility/ceil_log2.cpp
  - utility/int_alias.cpp
  - utility/countr_zero.cpp
  - utility/rep.cpp
  - utility/revrep.cpp
  - traits/assign_monoid.cpp
  isVerificationFile: true
  path: test/dual_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2021-12-17 09:20:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dual_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/test/dual_segment_tree.test.cpp
- /verify/test/dual_segment_tree.test.cpp.html
title: test/dual_segment_tree.test.cpp
---
