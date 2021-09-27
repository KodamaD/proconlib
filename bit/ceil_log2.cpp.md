---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: container/dual_segment_tree.cpp
    title: container/dual_segment_tree.cpp
  - icon: ':heavy_check_mark:'
    path: container/fenwick_tree.cpp
    title: container/fenwick_tree.cpp
  - icon: ':warning:'
    path: container/lazy_segment_tree.cpp
    title: container/lazy_segment_tree.cpp
  - icon: ':heavy_check_mark:'
    path: container/polynomial_hash.cpp
    title: container/polynomial_hash.cpp
  - icon: ':heavy_check_mark:'
    path: container/segment_tree.cpp
    title: container/segment_tree.cpp
  - icon: ':heavy_check_mark:'
    path: container/segment_tree_beats.cpp
    title: container/segment_tree_beats.cpp
  - icon: ':heavy_check_mark:'
    path: math/modint_util.cpp
    title: math/modint_util.cpp
  - icon: ':heavy_check_mark:'
    path: math/prime_sieve.cpp
    title: math/prime_sieve.cpp
  - icon: ':heavy_check_mark:'
    path: utility/auto_realloc.cpp
    title: utility/auto_realloc.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dual_segment_tree.test.cpp
    title: test/dual_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fenwick_tree.test.cpp
    title: test/fenwick_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/modint_util.test.cpp
    title: test/modint_util.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial_hash.test.cpp
    title: test/polynomial_hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/prime_sieve.test.cpp
    title: test/prime_sieve.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment_tree.test.cpp
    title: test/segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment_tree_beats.test.cpp
    title: test/segment_tree_beats.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/int_alias.cpp\"\n#include <cstddef>\n#include <cstdint>\n\
    \nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing isize = std::ptrdiff_t;\nusing usize = std::size_t;\n\
    #line 3 \"bit/ceil_log2.cpp\"\n\n__attribute__((target(\"avx2\"))) constexpr u64\
    \ ceil_log2(const u64 x) {\n    u64 e = 0;\n    while (((u64)1 << e) < x) ++e;\n\
    \    return e;\n}\n"
  code: "#pragma once\n#include \"../utility/int_alias.cpp\"\n\n__attribute__((target(\"\
    avx2\"))) constexpr u64 ceil_log2(const u64 x) {\n    u64 e = 0;\n    while (((u64)1\
    \ << e) < x) ++e;\n    return e;\n}\n"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: bit/ceil_log2.cpp
  requiredBy:
  - utility/auto_realloc.cpp
  - container/fenwick_tree.cpp
  - container/dual_segment_tree.cpp
  - container/segment_tree_beats.cpp
  - container/polynomial_hash.cpp
  - container/lazy_segment_tree.cpp
  - container/segment_tree.cpp
  - math/prime_sieve.cpp
  - math/modint_util.cpp
  timestamp: '2021-09-08 18:46:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dual_segment_tree.test.cpp
  - test/prime_sieve.test.cpp
  - test/segment_tree_beats.test.cpp
  - test/modint_util.test.cpp
  - test/polynomial_hash.test.cpp
  - test/segment_tree.test.cpp
  - test/fenwick_tree.test.cpp
documentation_of: bit/ceil_log2.cpp
layout: document
redirect_from:
- /library/bit/ceil_log2.cpp
- /library/bit/ceil_log2.cpp.html
title: bit/ceil_log2.cpp
---
