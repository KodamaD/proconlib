---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algorithm/monotone_minima.cpp
    title: algorithm/monotone_minima.cpp
  - icon: ':warning:'
    path: algorithm/smawk.cpp
    title: algorithm/smawk.cpp
  - icon: ':x:'
    path: container/dual_segment_tree.cpp
    title: container/dual_segment_tree.cpp
  - icon: ':heavy_check_mark:'
    path: container/lazy_segment_tree.cpp
    title: container/lazy_segment_tree.cpp
  - icon: ':x:'
    path: container/polynomial_hash.cpp
    title: container/polynomial_hash.cpp
  - icon: ':question:'
    path: container/segment_tree.cpp
    title: container/segment_tree.cpp
  - icon: ':x:'
    path: container/segment_tree_beats.cpp
    title: container/segment_tree_beats.cpp
  - icon: ':x:'
    path: container/sparse_table.cpp
    title: container/sparse_table.cpp
  - icon: ':heavy_check_mark:'
    path: graph/heavy_light_decomposition.cpp
    title: graph/heavy_light_decomposition.cpp
  - icon: ':x:'
    path: graph/union_find.cpp
    title: graph/union_find.cpp
  - icon: ':heavy_check_mark:'
    path: math/modint_util.cpp
    title: math/modint_util.cpp
  - icon: ':x:'
    path: math/prime_sieve.cpp
    title: math/prime_sieve.cpp
  - icon: ':x:'
    path: math/semiring_matrix.cpp
    title: math/semiring_matrix.cpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/dual_segment_tree.test.cpp
    title: test/dual_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fenwick_tree.test.cpp
    title: test/fenwick_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/heavy_light_decomposition.test.cpp
    title: test/heavy_light_decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazy_segment_tree.test.cpp
    title: test/lazy_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/modint_util.test.cpp
    title: test/modint_util.test.cpp
  - icon: ':x:'
    path: test/polynomial_hash.test.cpp
    title: test/polynomial_hash.test.cpp
  - icon: ':x:'
    path: test/prime_sieve.test.cpp
    title: test/prime_sieve.test.cpp
  - icon: ':x:'
    path: test/rollback_union_find.test.cpp
    title: test/rollback_union_find.test.cpp
  - icon: ':x:'
    path: test/segment_tree.test.cpp
    title: test/segment_tree.test.cpp
  - icon: ':x:'
    path: test/segment_tree_beats.test.cpp
    title: test/segment_tree_beats.test.cpp
  - icon: ':x:'
    path: test/semiring_matrix.test.cpp
    title: test/semiring_matrix.test.cpp
  - icon: ':x:'
    path: test/sparse_table.test.cpp
    title: test/sparse_table.test.cpp
  - icon: ':x:'
    path: test/union_find.test.cpp
    title: test/union_find.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/rep.cpp\"\n#include <algorithm>\n#line 2 \"utility/int_alias.cpp\"\
    \n#include <cstddef>\n#include <cstdint>\n\nusing i32 = std::int32_t;\nusing u32\
    \ = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing\
    \ i128 = __int128_t;\nusing u128 = __uint128_t;\nusing isize = std::ptrdiff_t;\n\
    using usize = std::size_t;\n#line 4 \"utility/rep.cpp\"\n\nclass rep {\n    struct\
    \ Iter {\n        usize itr;\n        constexpr Iter(const usize pos) noexcept\
    \ : itr(pos) {}\n        constexpr void operator++() noexcept { ++itr; }\n   \
    \     constexpr bool operator!=(const Iter& other) const noexcept { return itr\
    \ != other.itr; }\n        constexpr usize operator*() const noexcept { return\
    \ itr; }\n    };\n    const Iter first, last;\n\n  public:\n    explicit constexpr\
    \ rep(const usize first, const usize last) noexcept : first(first), last(std::max(first,\
    \ last)) {}\n    constexpr Iter begin() const noexcept { return first; }\n   \
    \ constexpr Iter end() const noexcept { return last; }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include \"int_alias.cpp\"\n\nclass rep\
    \ {\n    struct Iter {\n        usize itr;\n        constexpr Iter(const usize\
    \ pos) noexcept : itr(pos) {}\n        constexpr void operator++() noexcept {\
    \ ++itr; }\n        constexpr bool operator!=(const Iter& other) const noexcept\
    \ { return itr != other.itr; }\n        constexpr usize operator*() const noexcept\
    \ { return itr; }\n    };\n    const Iter first, last;\n\n  public:\n    explicit\
    \ constexpr rep(const usize first, const usize last) noexcept : first(first),\
    \ last(std::max(first, last)) {}\n    constexpr Iter begin() const noexcept {\
    \ return first; }\n    constexpr Iter end() const noexcept { return last; }\n\
    };\n"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: utility/rep.cpp
  requiredBy:
  - container/sparse_table.cpp
  - container/segment_tree_beats.cpp
  - container/segment_tree.cpp
  - container/polynomial_hash.cpp
  - container/dual_segment_tree.cpp
  - container/lazy_segment_tree.cpp
  - graph/union_find.cpp
  - graph/heavy_light_decomposition.cpp
  - algorithm/smawk.cpp
  - algorithm/monotone_minima.cpp
  - math/modint_util.cpp
  - math/prime_sieve.cpp
  - math/semiring_matrix.cpp
  timestamp: '2021-09-04 17:30:23+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/segment_tree_beats.test.cpp
  - test/union_find.test.cpp
  - test/sparse_table.test.cpp
  - test/dual_segment_tree.test.cpp
  - test/fenwick_tree.test.cpp
  - test/rollback_union_find.test.cpp
  - test/segment_tree.test.cpp
  - test/prime_sieve.test.cpp
  - test/semiring_matrix.test.cpp
  - test/modint_util.test.cpp
  - test/polynomial_hash.test.cpp
  - test/heavy_light_decomposition.test.cpp
  - test/lazy_segment_tree.test.cpp
documentation_of: utility/rep.cpp
layout: document
redirect_from:
- /library/utility/rep.cpp
- /library/utility/rep.cpp.html
title: utility/rep.cpp
---
