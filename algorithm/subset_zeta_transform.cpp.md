---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':heavy_check_mark:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algorithm/or_convolution.cpp
    title: algorithm/or_convolution.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algorithm/subset_zeta_transform.cpp\"\n#include <vector>\n\
    #include <cassert>\n#line 2 \"utility/int_alias.cpp\"\n#include <cstddef>\n#include\
    \ <cstdint>\n\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64\
    \ = std::int64_t;\nusing u64 = std::uint64_t;\nusing isize = std::ptrdiff_t;\n\
    using usize = std::size_t;\n#line 2 \"utility/rep.cpp\"\n#include <algorithm>\n\
    #line 4 \"utility/rep.cpp\"\n\nclass rep {\n    struct Iter {\n        usize itr;\n\
    \        constexpr Iter(const usize pos) noexcept : itr(pos) {}\n        constexpr\
    \ void operator++() noexcept { ++itr; }\n        constexpr bool operator!=(const\
    \ Iter& other) const noexcept { return itr != other.itr; }\n        constexpr\
    \ usize operator*() const noexcept { return itr; }\n    };\n    const Iter first,\
    \ last;\n\n  public:\n    explicit constexpr rep(const usize first, const usize\
    \ last) noexcept : first(first), last(std::max(first, last)) {}\n    constexpr\
    \ Iter begin() const noexcept { return first; }\n    constexpr Iter end() const\
    \ noexcept { return last; }\n};\n#line 6 \"algorithm/subset_zeta_transform.cpp\"\
    \n\ntemplate <class T> void subset_zeta_transform(std::vector<T>& f) {\n    const\
    \ usize n = f.size();\n    assert((n & (n - 1)) == 0);\n    for (usize i = 1;\
    \ i < n; i <<= 1) {\n        for (const usize j : rep(0, n)) {\n            if\
    \ (j & i) f[j] += f[j & ~i];\n        }\n    }\n}\n"
  code: "#pragma once\n#include <vector>\n#include <cassert>\n#include \"../utility/int_alias.cpp\"\
    \n#include \"../utility/rep.cpp\"\n\ntemplate <class T> void subset_zeta_transform(std::vector<T>&\
    \ f) {\n    const usize n = f.size();\n    assert((n & (n - 1)) == 0);\n    for\
    \ (usize i = 1; i < n; i <<= 1) {\n        for (const usize j : rep(0, n)) {\n\
    \            if (j & i) f[j] += f[j & ~i];\n        }\n    }\n}\n"
  dependsOn:
  - utility/int_alias.cpp
  - utility/rep.cpp
  isVerificationFile: false
  path: algorithm/subset_zeta_transform.cpp
  requiredBy:
  - algorithm/or_convolution.cpp
  timestamp: '2021-10-04 09:51:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/subset_zeta_transform.cpp
layout: document
redirect_from:
- /library/algorithm/subset_zeta_transform.cpp
- /library/algorithm/subset_zeta_transform.cpp.html
title: algorithm/subset_zeta_transform.cpp
---
