---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bit/bit_lzeros.cpp
    title: bit/bit_lzeros.cpp
  - icon: ':heavy_check_mark:'
    path: bit/bit_width.cpp
    title: bit/bit_width.cpp
  - icon: ':heavy_check_mark:'
    path: container/sparse_table.cpp
    title: container/sparse_table.cpp
  - icon: ':heavy_check_mark:'
    path: traits/min_monoid.cpp
    title: traits/min_monoid.cpp
  - icon: ':question:'
    path: utility/infty.cpp
    title: utility/infty.cpp
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/sparse_table.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \n#line 2 \"utility/int_alias.cpp\"\n#include <cstddef>\n#include <cstdint>\n\n\
    using i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing isize = std::ptrdiff_t;\nusing usize = std::size_t;\n\
    #line 2 \"utility/rep.cpp\"\n#include <algorithm>\n#line 4 \"utility/rep.cpp\"\
    \n\nclass rep {\n    struct Iter {\n        usize itr;\n        constexpr Iter(const\
    \ usize pos) noexcept : itr(pos) {}\n        constexpr void operator++() noexcept\
    \ { ++itr; }\n        constexpr bool operator!=(const Iter& other) const noexcept\
    \ { return itr != other.itr; }\n        constexpr usize operator*() const noexcept\
    \ { return itr; }\n    };\n    const Iter first, last;\n\n  public:\n    explicit\
    \ constexpr rep(const usize first, const usize last) noexcept : first(first),\
    \ last(std::max(first, last)) {}\n    constexpr Iter begin() const noexcept {\
    \ return first; }\n    constexpr Iter end() const noexcept { return last; }\n\
    };\n#line 2 \"utility/infty.cpp\"\n#include <limits>\n\ntemplate <class T, T Div\
    \ = 2> constexpr T INFTY = std::numeric_limits<T>::max() / Div;\n#line 2 \"traits/min_monoid.cpp\"\
    \n#include <functional>\n#line 4 \"traits/min_monoid.cpp\"\n\ntemplate <class\
    \ T> struct MinMonoid {\n    using Type = T;\n    static constexpr T identity()\
    \ { return std::numeric_limits<T>::max(); }\n    static constexpr T operation(const\
    \ T& l, const T& r) { return std::min(l, r); }\n};\n#line 2 \"container/sparse_table.cpp\"\
    \n#include <cassert>\n#include <vector>\n#line 3 \"bit/bit_lzeros.cpp\"\n\n__attribute__((target(\"\
    avx2\"))) constexpr u64 bit_lzeros(const u64 x) { return x == 0 ? 64 : __builtin_clzll(x);\
    \ }\n#line 4 \"bit/bit_width.cpp\"\n\n__attribute__((target(\"avx2\"))) constexpr\
    \ u64 bit_width(const u64 x) { return 64 - bit_lzeros(x); }\n#line 7 \"container/sparse_table.cpp\"\
    \n\ntemplate <class M> class SparseTable {\n    using T = typename M::Type;\n\
    \    std::vector<std::vector<T>> table;\n\n  public:\n    SparseTable() : SparseTable(std::vector<T>())\
    \ {}\n    explicit SparseTable(const std::vector<T>& vec) {\n        const auto\
    \ size = vec.size();\n        const auto height = bit_width(size);\n        table.reserve(height);\n\
    \        table.push_back(vec);\n        for (const usize d : rep(1, height)) {\n\
    \            table.push_back(std::vector<T>(size - (1 << d) + 1, M::identity()));\n\
    \            for (const usize i : rep(0, table[d].size())) {\n               \
    \ table[d][i] = M::operation(table[d - 1][i], table[d - 1][i + (1 << (d - 1))]);\n\
    \            }\n        }\n    }\n\n    usize size() const { return table[0].size();\
    \ }\n\n    T fold(const usize l, const usize r) const {\n        if (l == r) return\
    \ M::identity();\n        assert(l < r);\n        const auto d = bit_width(r -\
    \ l) - 1;\n        return M::operation(table[d][l], table[d][r - (1 << d)]);\n\
    \    }\n};\n#line 7 \"test/sparse_table.test.cpp\"\n#include <iostream>\n\nint\
    \ main() {\n    usize N, Q;\n    std::cin >> N >> Q;\n    std::vector<u32> A(N);\n\
    \    for (auto& x : A) {\n        std::cin >> x;\n    }\n    SparseTable<MinMonoid<u32>>\
    \ table(A);\n    while (Q--) {\n        usize l, r;\n        std::cin >> l >>\
    \ r;\n        std::cout << table.fold(l, r) << '\\n';\n    }\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include \"\
    ../utility/int_alias.cpp\"\n#include \"../utility/rep.cpp\"\n#include \"../utility/infty.cpp\"\
    \n#include \"../traits/min_monoid.cpp\"\n#include \"../container/sparse_table.cpp\"\
    \n#include <iostream>\n\nint main() {\n    usize N, Q;\n    std::cin >> N >> Q;\n\
    \    std::vector<u32> A(N);\n    for (auto& x : A) {\n        std::cin >> x;\n\
    \    }\n    SparseTable<MinMonoid<u32>> table(A);\n    while (Q--) {\n       \
    \ usize l, r;\n        std::cin >> l >> r;\n        std::cout << table.fold(l,\
    \ r) << '\\n';\n    }\n    return 0;\n}"
  dependsOn:
  - utility/int_alias.cpp
  - utility/rep.cpp
  - utility/infty.cpp
  - traits/min_monoid.cpp
  - container/sparse_table.cpp
  - bit/bit_width.cpp
  - bit/bit_lzeros.cpp
  isVerificationFile: true
  path: test/sparse_table.test.cpp
  requiredBy: []
  timestamp: '2021-09-27 22:23:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/sparse_table.test.cpp
layout: document
redirect_from:
- /verify/test/sparse_table.test.cpp
- /verify/test/sparse_table.test.cpp.html
title: test/sparse_table.test.cpp
---
