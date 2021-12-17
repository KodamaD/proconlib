---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algorithm/convolution_arbitrary_mod.cpp
    title: algorithm/convolution_arbitrary_mod.cpp
  - icon: ':warning:'
    path: algorithm/convolution_int.cpp
    title: algorithm/convolution_int.cpp
  - icon: ':heavy_check_mark:'
    path: algorithm/convolution_mod.cpp
    title: algorithm/convolution_mod.cpp
  - icon: ':heavy_check_mark:'
    path: container/dual_segment_tree.cpp
    title: container/dual_segment_tree.cpp
  - icon: ':x:'
    path: container/lazy_segment_tree.cpp
    title: container/lazy_segment_tree.cpp
  - icon: ':heavy_check_mark:'
    path: container/segment_tree.cpp
    title: container/segment_tree.cpp
  - icon: ':x:'
    path: container/segment_tree_beats.cpp
    title: container/segment_tree_beats.cpp
  - icon: ':heavy_check_mark:'
    path: math/modulo_transform.cpp
    title: math/modulo_transform.cpp
  - icon: ':heavy_check_mark:'
    path: utility/fast_io.cpp
    title: utility/fast_io.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution_arbitrary_mod.test.cpp
    title: test/convolution_arbitrary_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution_mod.test.cpp
    title: test/convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/dual_segment_tree.test.cpp
    title: test/dual_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fast_io.test.cpp
    title: test/fast_io.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/heavy_light_decomposition.test.cpp
    title: test/heavy_light_decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/larsch.test.cpp
    title: test/larsch.test.cpp
  - icon: ':x:'
    path: test/lazy_segment_tree.test.cpp
    title: test/lazy_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment_tree.test.cpp
    title: test/segment_tree.test.cpp
  - icon: ':x:'
    path: test/segment_tree_beats.test.cpp
    title: test/segment_tree_beats.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/revrep.cpp\"\n#include <algorithm>\n\nclass ReversedRange\
    \ {\n    struct Iter {\n        int itr;\n        constexpr Iter(const int pos)\
    \ noexcept : itr(pos) {}\n        constexpr void operator++() noexcept { --itr;\
    \ }\n        constexpr bool operator!=(const Iter& other) const noexcept { return\
    \ itr != other.itr; }\n        constexpr int operator*() const noexcept { return\
    \ itr; }\n    };\n    const Iter first, last;\n\n  public:\n    explicit constexpr\
    \ ReversedRange(const int first, const int last) noexcept\n        : first(last\
    \ - 1), last(std::min(first, last) - 1) {}\n    constexpr Iter begin() const noexcept\
    \ { return first; }\n    constexpr Iter end() const noexcept { return last; }\n\
    };\n\nconstexpr ReversedRange revrep(const int l, const int r) noexcept { return\
    \ ReversedRange(l, r); }\nconstexpr ReversedRange revrep(const int n) noexcept\
    \ { return ReversedRange(0, n); }\n"
  code: "#pragma once\n#include <algorithm>\n\nclass ReversedRange {\n    struct Iter\
    \ {\n        int itr;\n        constexpr Iter(const int pos) noexcept : itr(pos)\
    \ {}\n        constexpr void operator++() noexcept { --itr; }\n        constexpr\
    \ bool operator!=(const Iter& other) const noexcept { return itr != other.itr;\
    \ }\n        constexpr int operator*() const noexcept { return itr; }\n    };\n\
    \    const Iter first, last;\n\n  public:\n    explicit constexpr ReversedRange(const\
    \ int first, const int last) noexcept\n        : first(last - 1), last(std::min(first,\
    \ last) - 1) {}\n    constexpr Iter begin() const noexcept { return first; }\n\
    \    constexpr Iter end() const noexcept { return last; }\n};\n\nconstexpr ReversedRange\
    \ revrep(const int l, const int r) noexcept { return ReversedRange(l, r); }\n\
    constexpr ReversedRange revrep(const int n) noexcept { return ReversedRange(0,\
    \ n); }"
  dependsOn: []
  isVerificationFile: false
  path: utility/revrep.cpp
  requiredBy:
  - math/modulo_transform.cpp
  - algorithm/convolution_mod.cpp
  - algorithm/convolution_arbitrary_mod.cpp
  - algorithm/convolution_int.cpp
  - utility/fast_io.cpp
  - container/lazy_segment_tree.cpp
  - container/dual_segment_tree.cpp
  - container/segment_tree_beats.cpp
  - container/segment_tree.cpp
  timestamp: '2021-12-17 09:20:39+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/convolution_arbitrary_mod.test.cpp
  - test/larsch.test.cpp
  - test/fast_io.test.cpp
  - test/lazy_segment_tree.test.cpp
  - test/heavy_light_decomposition.test.cpp
  - test/segment_tree.test.cpp
  - test/segment_tree_beats.test.cpp
  - test/dual_segment_tree.test.cpp
  - test/convolution_mod.test.cpp
documentation_of: utility/revrep.cpp
layout: document
redirect_from:
- /library/utility/revrep.cpp
- /library/utility/revrep.cpp.html
title: utility/revrep.cpp
---
