---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/factorize.test.cpp
    title: test/factorize.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/factorize.cpp\"\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n\nusing\
    \ i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    #line 6 \"math/factorize.cpp\"\n\ntemplate <class T> std::vector<std::pair<T,\
    \ int>> factorize(T x) {\n    assert(x > 0);\n    std::vector<std::pair<T, int>>\
    \ ret;\n    for (T i = 2; i * i <= x; ++i) {\n        if (x % i == 0) {\n    \
    \        ret.emplace_back(i, 0);\n            while (x % i == 0) {\n         \
    \       ret.back().second++;\n                x /= i;\n            }\n       \
    \ }\n    }\n    if (x > 1) {\n        ret.emplace_back(x, 1);\n    }\n    return\
    \ ret;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    #include \"../utility/int_alias.cpp\"\n\ntemplate <class T> std::vector<std::pair<T,\
    \ int>> factorize(T x) {\n    assert(x > 0);\n    std::vector<std::pair<T, int>>\
    \ ret;\n    for (T i = 2; i * i <= x; ++i) {\n        if (x % i == 0) {\n    \
    \        ret.emplace_back(i, 0);\n            while (x % i == 0) {\n         \
    \       ret.back().second++;\n                x /= i;\n            }\n       \
    \ }\n    }\n    if (x > 1) {\n        ret.emplace_back(x, 1);\n    }\n    return\
    \ ret;\n}\n"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: math/factorize.cpp
  requiredBy: []
  timestamp: '2021-12-17 09:20:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/factorize.test.cpp
documentation_of: math/factorize.cpp
layout: document
redirect_from:
- /library/math/factorize.cpp
- /library/math/factorize.cpp.html
title: math/factorize.cpp
---
