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
    \n#include <cstdint>\n\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\n\
    using i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\n#line 4 \"utility/subsets.cpp\"\n\nclass SubsetScanner\
    \ {\n    struct Iter {\n        u64 s, t;\n        explicit constexpr Iter(const\
    \ u64 s, const u64 t) noexcept : s(s), t(t) {}\n        constexpr bool operator!=(std::monostate)\
    \ const noexcept { return ~t != 0; }\n        constexpr void operator++() noexcept\
    \ { t -= 1; }\n        constexpr u64 operator*() noexcept { return t &= s; }\n\
    \    };\n    u64 s;\n\n  public:\n    explicit constexpr SubsetScanner(u64 s)\
    \ noexcept : s(s) {}\n    constexpr Iter begin() const noexcept { return Iter(s,\
    \ s); }\n    constexpr std::monostate end() noexcept { return {}; }\n};\n\nconstexpr\
    \ SubsetScanner subsets(const u64 set) noexcept { return SubsetScanner(set); }\n"
  code: "#pragma once\n#include <variant>\n#include \"int_alias.cpp\"\n\nclass SubsetScanner\
    \ {\n    struct Iter {\n        u64 s, t;\n        explicit constexpr Iter(const\
    \ u64 s, const u64 t) noexcept : s(s), t(t) {}\n        constexpr bool operator!=(std::monostate)\
    \ const noexcept { return ~t != 0; }\n        constexpr void operator++() noexcept\
    \ { t -= 1; }\n        constexpr u64 operator*() noexcept { return t &= s; }\n\
    \    };\n    u64 s;\n\n  public:\n    explicit constexpr SubsetScanner(u64 s)\
    \ noexcept : s(s) {}\n    constexpr Iter begin() const noexcept { return Iter(s,\
    \ s); }\n    constexpr std::monostate end() noexcept { return {}; }\n};\n\nconstexpr\
    \ SubsetScanner subsets(const u64 set) noexcept { return SubsetScanner(set); }"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: utility/subsets.cpp
  requiredBy: []
  timestamp: '2021-12-17 09:20:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/subsets.cpp
layout: document
redirect_from:
- /library/utility/subsets.cpp
- /library/utility/subsets.cpp.html
title: utility/subsets.cpp
---
