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
  bundledCode: "#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n#include <cstddef>\n\
    \nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    using isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 3 \"bit/popcount.cpp\"\
    \n\nconstexpr u64 popcount(const u64 x) {\n    return __builtin_popcountll(x);\n\
    }\n"
  code: "#pragma once\n#include \"../utility/int_alias.cpp\"\n\nconstexpr u64 popcount(const\
    \ u64 x) {\n    return __builtin_popcountll(x);\n}\n"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: bit/popcount.cpp
  requiredBy: []
  timestamp: '2021-03-26 16:52:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: bit/popcount.cpp
layout: document
redirect_from:
- /library/bit/popcount.cpp
- /library/bit/popcount.cpp.html
title: bit/popcount.cpp
---
