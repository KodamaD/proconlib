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
    path: container/lazy_segment_tree.cpp
    title: container/lazy_segment_tree.cpp
  - icon: ':heavy_check_mark:'
    path: container/segment_tree.cpp
    title: container/segment_tree.cpp
  - icon: ':heavy_check_mark:'
    path: container/segment_tree_beats.cpp
    title: container/segment_tree_beats.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dual_segment_tree.test.cpp
    title: test/dual_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/heavy_light_decomposition.test.cpp
    title: test/heavy_light_decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazy_segment_tree.test.cpp
    title: test/lazy_segment_tree.test.cpp
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
  bundledCode: "#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n#include <cstddef>\n\
    \nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    using isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 3 \"utility/revrep.cpp\"\
    \n#include <algorithm>\n\nclass revrep {\n    struct Iter {\n        usize itr;\n\
    \        constexpr Iter(const usize pos) noexcept: itr(pos) { }\n        constexpr\
    \ void operator ++ () noexcept { --itr; }\n        constexpr bool operator !=\
    \ (const Iter& other) const noexcept { return itr != other.itr; }\n        constexpr\
    \ usize operator * () const noexcept { return itr; }\n    };\n    const Iter first,\
    \ last;\npublic:\n    explicit constexpr revrep(const usize first, const usize\
    \ last) noexcept: first(last - 1), last(std::min(first, last) - 1) { }\n    constexpr\
    \ Iter begin() const noexcept { return first; }\n    constexpr Iter end() const\
    \ noexcept { return last; }\n};\n"
  code: "#pragma once\n#include \"int_alias.cpp\"\n#include <algorithm>\n\nclass revrep\
    \ {\n    struct Iter {\n        usize itr;\n        constexpr Iter(const usize\
    \ pos) noexcept: itr(pos) { }\n        constexpr void operator ++ () noexcept\
    \ { --itr; }\n        constexpr bool operator != (const Iter& other) const noexcept\
    \ { return itr != other.itr; }\n        constexpr usize operator * () const noexcept\
    \ { return itr; }\n    };\n    const Iter first, last;\npublic:\n    explicit\
    \ constexpr revrep(const usize first, const usize last) noexcept: first(last -\
    \ 1), last(std::min(first, last) - 1) { }\n    constexpr Iter begin() const noexcept\
    \ { return first; }\n    constexpr Iter end() const noexcept { return last; }\n\
    };\n"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: utility/revrep.cpp
  requiredBy:
  - container/lazy_segment_tree.cpp
  - container/dual_segment_tree.cpp
  - container/segment_tree_beats.cpp
  - container/segment_tree.cpp
  timestamp: '2021-03-26 16:46:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/lazy_segment_tree.test.cpp
  - test/dual_segment_tree.test.cpp
  - test/segment_tree_beats.test.cpp
  - test/segment_tree.test.cpp
  - test/heavy_light_decomposition.test.cpp
documentation_of: utility/revrep.cpp
layout: document
redirect_from:
- /library/utility/revrep.cpp
- /library/utility/revrep.cpp.html
title: utility/revrep.cpp
---
