---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bit/bit_rzeros.cpp
    title: bit/bit_rzeros.cpp
  - icon: ':heavy_check_mark:'
    path: bit/ceil_log2.cpp
    title: bit/ceil_log2.cpp
  - icon: ':heavy_check_mark:'
    path: container/dual_segment_tree.cpp
    title: container/dual_segment_tree.cpp
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
    \n#line 2 \"utility/int_alias.cpp\"\n#include <cstddef>\n#include <cstdint>\n\n\
    using i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing isize = std::ptrdiff_t;\nusing usize = std::size_t;\n\
    #line 2 \"container/dual_segment_tree.cpp\"\n#include <cassert>\n#include <vector>\n\
    #line 3 \"bit/bit_rzeros.cpp\"\n\n__attribute__((target(\"avx2\"))) constexpr\
    \ u64 bit_rzeros(const u64 x) { return x == 0 ? 64 : __builtin_ctzll(x); }\n#line\
    \ 3 \"bit/ceil_log2.cpp\"\n\n__attribute__((target(\"avx2\"))) constexpr u64 ceil_log2(const\
    \ u64 x) {\n    u64 e = 0;\n    while (((u64)1 << e) < x) ++e;\n    return e;\n\
    }\n#line 2 \"utility/rep.cpp\"\n#include <algorithm>\n#line 4 \"utility/rep.cpp\"\
    \n\nclass rep {\n    struct Iter {\n        usize itr;\n        constexpr Iter(const\
    \ usize pos) noexcept : itr(pos) {}\n        constexpr void operator++() noexcept\
    \ { ++itr; }\n        constexpr bool operator!=(const Iter& other) const noexcept\
    \ { return itr != other.itr; }\n        constexpr usize operator*() const noexcept\
    \ { return itr; }\n    };\n    const Iter first, last;\n\n  public:\n    explicit\
    \ constexpr rep(const usize first, const usize last) noexcept : first(first),\
    \ last(std::max(first, last)) {}\n    constexpr Iter begin() const noexcept {\
    \ return first; }\n    constexpr Iter end() const noexcept { return last; }\n\
    };\n#line 4 \"utility/revrep.cpp\"\n\nclass revrep {\n    struct Iter {\n    \
    \    usize itr;\n        constexpr Iter(const usize pos) noexcept : itr(pos) {}\n\
    \        constexpr void operator++() noexcept { --itr; }\n        constexpr bool\
    \ operator!=(const Iter& other) const noexcept { return itr != other.itr; }\n\
    \        constexpr usize operator*() const noexcept { return itr; }\n    };\n\
    \    const Iter first, last;\n\n  public:\n    explicit constexpr revrep(const\
    \ usize first, const usize last) noexcept\n        : first(last - 1), last(std::min(first,\
    \ last) - 1) {}\n    constexpr Iter begin() const noexcept { return first; }\n\
    \    constexpr Iter end() const noexcept { return last; }\n};\n#line 9 \"container/dual_segment_tree.cpp\"\
    \n\ntemplate <class Effector> class DualSegmentTree {\n    using E = Effector;\n\
    \    usize internal_size, logn;\n    std::vector<E> lazy;\n\n    void apply(const\
    \ usize k, const E& e) { lazy[k] = lazy[k] * e; }\n    void flush(const usize\
    \ k) {\n        apply(2 * k, lazy[k]);\n        apply(2 * k + 1, lazy[k]);\n \
    \       lazy[k] = E::one();\n    }\n    void push(const usize k) {\n        for\
    \ (const usize d : revrep(bit_rzeros(k) + 1, logn + 1)) {\n            flush(k\
    \ >> d);\n        }\n    }\n\n  public:\n    explicit DualSegmentTree(const usize\
    \ size = 0, const E& value = E::one())\n        : DualSegmentTree(std::vector<E>(size,\
    \ value)) {}\n    explicit DualSegmentTree(const std::vector<E>& vec) : internal_size(vec.size())\
    \ {\n        logn = ceil_log2(internal_size);\n        lazy = std::vector<E>(2\
    \ * internal_size, E::one());\n        for (const usize i : rep(0, internal_size))\
    \ lazy[i] = vec[i];\n    }\n\n    usize size() const { return internal_size; }\n\
    \n    void operate(usize l, usize r, const E& e) {\n        assert(l <= r and\
    \ r <= internal_size);\n        l += internal_size;\n        r += internal_size;\n\
    \        push(l);\n        push(r);\n        while (l < r) {\n            if (l\
    \ & 1) apply(l++, e);\n            if (r & 1) apply(--r, e);\n            l >>=\
    \ 1;\n            r >>= 1;\n        }\n    }\n    void assign(usize i, const E&\
    \ e) {\n        assert(i < internal_size);\n        i += internal_size;\n    \
    \    for (const usize d : revrep(1, logn + 1)) flush(i >> d);\n        lazy[i]\
    \ = e;\n    }\n\n    E get(usize i) const {\n        assert(i < internal_size);\n\
    \        i += internal_size;\n        E ret = E::one();\n        while (i > 0)\
    \ {\n            ret = ret * lazy[i];\n            i >>= 1;\n        }\n     \
    \   return ret;\n    }\n};\n#line 4 \"test/dual_segment_tree.test.cpp\"\n#include\
    \ <iostream>\n#include <optional>\n\nstruct Effector {\n    static Effector one()\
    \ {\n        return Effector { std::nullopt };\n    }\n    std::optional<u32>\
    \ val;\n    Effector operator * (const Effector& other) const {\n        if (!other.val)\
    \ return *this;\n        return other;\n    }\n};\n\nint main() {\n    usize N,\
    \ Q;\n    std::cin >> N >> Q;\n    DualSegmentTree<Effector> seg(N);\n    while\
    \ (Q--) {\n        usize t;\n        std::cin >> t;\n        if (t == 0) {\n \
    \           usize l, r;\n            std::cin >> l >> r;\n            u32 x;\n\
    \            std::cin >> x;\n            seg.operate(l, r + 1, Effector { x });\n\
    \        }\n        else {\n            usize p;\n            std::cin >> p;\n\
    \            const auto e = seg.get(p);\n            if (!e.val) {\n         \
    \       std::cout << (1u << 31) - 1 << '\\n';\n            }\n            else\
    \ {\n                std::cout << *e.val << '\\n';\n            }\n        }\n\
    \    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\"\
    \n#include \"../utility/int_alias.cpp\"\n#include \"../container/dual_segment_tree.cpp\"\
    \n#include <iostream>\n#include <optional>\n\nstruct Effector {\n    static Effector\
    \ one() {\n        return Effector { std::nullopt };\n    }\n    std::optional<u32>\
    \ val;\n    Effector operator * (const Effector& other) const {\n        if (!other.val)\
    \ return *this;\n        return other;\n    }\n};\n\nint main() {\n    usize N,\
    \ Q;\n    std::cin >> N >> Q;\n    DualSegmentTree<Effector> seg(N);\n    while\
    \ (Q--) {\n        usize t;\n        std::cin >> t;\n        if (t == 0) {\n \
    \           usize l, r;\n            std::cin >> l >> r;\n            u32 x;\n\
    \            std::cin >> x;\n            seg.operate(l, r + 1, Effector { x });\n\
    \        }\n        else {\n            usize p;\n            std::cin >> p;\n\
    \            const auto e = seg.get(p);\n            if (!e.val) {\n         \
    \       std::cout << (1u << 31) - 1 << '\\n';\n            }\n            else\
    \ {\n                std::cout << *e.val << '\\n';\n            }\n        }\n\
    \    }\n    return 0;\n}"
  dependsOn:
  - utility/int_alias.cpp
  - container/dual_segment_tree.cpp
  - bit/bit_rzeros.cpp
  - bit/ceil_log2.cpp
  - utility/rep.cpp
  - utility/revrep.cpp
  isVerificationFile: true
  path: test/dual_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2021-09-08 18:46:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/dual_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/test/dual_segment_tree.test.cpp
- /verify/test/dual_segment_tree.test.cpp.html
title: test/dual_segment_tree.test.cpp
---
