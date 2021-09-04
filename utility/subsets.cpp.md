---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/subsets.cpp\"\n#include <variant>\n#line 2 \"utility/int_alias.cpp\"\
    \n#include <cstddef>\n#include <cstdint>\n\nusing i32 = std::int32_t;\nusing u32\
    \ = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing\
    \ i128 = __int128_t;\nusing u128 = __uint128_t;\nusing isize = std::ptrdiff_t;\n\
    using usize = std::size_t;\n#line 4 \"utility/subsets.cpp\"\n\nclass subsets {\n\
    \    struct Iter {\n        u64 s, t;\n        explicit constexpr Iter(const u64\
    \ s, const u64 t) noexcept : s(s), t(t) {}\n        constexpr bool operator!=(std::monostate)\
    \ const noexcept { return ~t != 0; }\n        constexpr void operator++() noexcept\
    \ { t -= 1; }\n        constexpr u64 operator*() noexcept { return t &= s; }\n\
    \    };\n    u64 s;\n\n  public:\n    explicit constexpr subsets(u64 s) noexcept\
    \ : s(s) {}\n    constexpr Iter begin() const noexcept { return Iter(s, s); }\n\
    \    constexpr std::monostate end() noexcept { return {}; }\n};\n"
  code: "#pragma once\n#include <variant>\n#include \"../utility/int_alias.cpp\"\n\
    \nclass subsets {\n    struct Iter {\n        u64 s, t;\n        explicit constexpr\
    \ Iter(const u64 s, const u64 t) noexcept : s(s), t(t) {}\n        constexpr bool\
    \ operator!=(std::monostate) const noexcept { return ~t != 0; }\n        constexpr\
    \ void operator++() noexcept { t -= 1; }\n        constexpr u64 operator*() noexcept\
    \ { return t &= s; }\n    };\n    u64 s;\n\n  public:\n    explicit constexpr\
    \ subsets(u64 s) noexcept : s(s) {}\n    constexpr Iter begin() const noexcept\
    \ { return Iter(s, s); }\n    constexpr std::monostate end() noexcept { return\
    \ {}; }\n};\n"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: utility/subsets.cpp
  requiredBy: []
  timestamp: '2021-09-04 17:30:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/subsets.cpp
layout: document
redirect_from:
- /library/utility/subsets.cpp
- /library/utility/subsets.cpp.html
title: utility/subsets.cpp
---
