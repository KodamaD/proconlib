---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algorithm/monotone_minima.cpp
    title: algorithm/monotone_minima.cpp
  - icon: ':warning:'
    path: algorithm/smawk.cpp
    title: algorithm/smawk.cpp
  - icon: ':x:'
    path: bit/bit_lzeros.cpp
    title: bit/bit_lzeros.cpp
  - icon: ':warning:'
    path: bit/bit_reverse.cpp
    title: bit/bit_reverse.cpp
  - icon: ':question:'
    path: bit/bit_rzeros.cpp
    title: bit/bit_rzeros.cpp
  - icon: ':x:'
    path: bit/bit_width.cpp
    title: bit/bit_width.cpp
  - icon: ':question:'
    path: bit/ceil_log2.cpp
    title: bit/ceil_log2.cpp
  - icon: ':warning:'
    path: bit/popcount.cpp
    title: bit/popcount.cpp
  - icon: ':x:'
    path: container/dual_segment_tree.cpp
    title: container/dual_segment_tree.cpp
  - icon: ':heavy_check_mark:'
    path: container/fenwick_tree.cpp
    title: container/fenwick_tree.cpp
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
    path: graph/rollback_union_find.cpp
    title: graph/rollback_union_find.cpp
  - icon: ':x:'
    path: graph/union_find.cpp
    title: graph/union_find.cpp
  - icon: ':warning:'
    path: math/divisors_from_factors.cpp
    title: math/divisors_from_factors.cpp
  - icon: ':warning:'
    path: math/dynamic_modint.cpp
    title: math/dynamic_modint.cpp
  - icon: ':x:'
    path: math/factorize.cpp
    title: math/factorize.cpp
  - icon: ':heavy_check_mark:'
    path: math/modint_util.cpp
    title: math/modint_util.cpp
  - icon: ':x:'
    path: math/prime_sieve.cpp
    title: math/prime_sieve.cpp
  - icon: ':warning:'
    path: math/primitive_root.cpp
    title: math/primitive_root.cpp
  - icon: ':x:'
    path: math/semiring_matrix.cpp
    title: math/semiring_matrix.cpp
  - icon: ':question:'
    path: math/static_modint.cpp
    title: math/static_modint.cpp
  - icon: ':x:'
    path: random/rand_int.cpp
    title: random/rand_int.cpp
  - icon: ':x:'
    path: random/xorshift.cpp
    title: random/xorshift.cpp
  - icon: ':x:'
    path: utility/auto_memoize.cpp
    title: utility/auto_memoize.cpp
  - icon: ':question:'
    path: utility/auto_realloc.cpp
    title: utility/auto_realloc.cpp
  - icon: ':warning:'
    path: utility/multi_array.cpp
    title: utility/multi_array.cpp
  - icon: ':warning:'
    path: utility/multi_vec.cpp
    title: utility/multi_vec.cpp
  - icon: ':warning:'
    path: utility/permutations.cpp
    title: utility/permutations.cpp
  - icon: ':question:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  - icon: ':question:'
    path: utility/revrep.cpp
    title: utility/revrep.cpp
  - icon: ':warning:'
    path: utility/subsets.cpp
    title: utility/subsets.cpp
  - icon: ':warning:'
    path: utility/vec_util.cpp
    title: utility/vec_util.cpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/auto_memoize.test.cpp
    title: test/auto_memoize.test.cpp
  - icon: ':x:'
    path: test/dual_segment_tree.test.cpp
    title: test/dual_segment_tree.test.cpp
  - icon: ':x:'
    path: test/factorize.test.cpp
    title: test/factorize.test.cpp
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
    path: test/queue_aggregation.test.cpp
    title: test/queue_aggregation.test.cpp
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
    path: test/totient.test.cpp
    title: test/totient.test.cpp
  - icon: ':x:'
    path: test/union_find.test.cpp
    title: test/union_find.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: '#line 2 "utility/int_alias.cpp"

    #include <cstddef>

    #include <cstdint>


    using i32 = std::int32_t;

    using u32 = std::uint32_t;

    using i64 = std::int64_t;

    using u64 = std::uint64_t;

    using i128 = __int128_t;

    using u128 = __uint128_t;

    using isize = std::ptrdiff_t;

    using usize = std::size_t;

    '
  code: '#pragma once

    #include <cstddef>

    #include <cstdint>


    using i32 = std::int32_t;

    using u32 = std::uint32_t;

    using i64 = std::int64_t;

    using u64 = std::uint64_t;

    using i128 = __int128_t;

    using u128 = __uint128_t;

    using isize = std::ptrdiff_t;

    using usize = std::size_t;

    '
  dependsOn: []
  isVerificationFile: false
  path: utility/int_alias.cpp
  requiredBy:
  - bit/bit_reverse.cpp
  - bit/popcount.cpp
  - bit/bit_lzeros.cpp
  - bit/bit_rzeros.cpp
  - bit/ceil_log2.cpp
  - bit/bit_width.cpp
  - utility/vec_util.cpp
  - utility/multi_array.cpp
  - utility/auto_memoize.cpp
  - utility/permutations.cpp
  - utility/revrep.cpp
  - utility/rep.cpp
  - utility/multi_vec.cpp
  - utility/auto_realloc.cpp
  - utility/subsets.cpp
  - random/rand_int.cpp
  - random/xorshift.cpp
  - container/sparse_table.cpp
  - container/segment_tree_beats.cpp
  - container/segment_tree.cpp
  - container/fenwick_tree.cpp
  - container/polynomial_hash.cpp
  - container/dual_segment_tree.cpp
  - container/lazy_segment_tree.cpp
  - graph/union_find.cpp
  - graph/rollback_union_find.cpp
  - graph/heavy_light_decomposition.cpp
  - algorithm/smawk.cpp
  - algorithm/monotone_minima.cpp
  - math/dynamic_modint.cpp
  - math/modint_util.cpp
  - math/static_modint.cpp
  - math/primitive_root.cpp
  - math/prime_sieve.cpp
  - math/factorize.cpp
  - math/semiring_matrix.cpp
  - math/divisors_from_factors.cpp
  timestamp: '2021-09-04 17:30:23+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/auto_memoize.test.cpp
  - test/segment_tree_beats.test.cpp
  - test/union_find.test.cpp
  - test/sparse_table.test.cpp
  - test/dual_segment_tree.test.cpp
  - test/fenwick_tree.test.cpp
  - test/totient.test.cpp
  - test/rollback_union_find.test.cpp
  - test/segment_tree.test.cpp
  - test/prime_sieve.test.cpp
  - test/semiring_matrix.test.cpp
  - test/factorize.test.cpp
  - test/queue_aggregation.test.cpp
  - test/modint_util.test.cpp
  - test/polynomial_hash.test.cpp
  - test/heavy_light_decomposition.test.cpp
  - test/lazy_segment_tree.test.cpp
documentation_of: utility/int_alias.cpp
layout: document
redirect_from:
- /library/utility/int_alias.cpp
- /library/utility/int_alias.cpp.html
title: utility/int_alias.cpp
---
