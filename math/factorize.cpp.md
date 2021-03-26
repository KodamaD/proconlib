---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
  bundledCode: "#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n#include <cstddef>\n\
    \nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    using isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 3 \"math/factorize.cpp\"\
    \n#include <vector>\n#include <utility>\n#include <cassert>\n\ntemplate <class\
    \ T>\nstd::vector<std::pair<T, usize>> factorize(T x) {\n    assert(x > 0);\n\
    \    std::vector<std::pair<T, usize>> ret;\n    for (T i = 2; i * i <= x; ++i)\
    \ {\n        if (x % i == 0) {\n            ret.emplace_back(i, 0);\n        \
    \    while (x % i == 0) {\n                ret.back().second++;\n            \
    \    x /= i;\n            }\n        }\n    }\n    if (x > 1) {\n        ret.emplace_back(x,\
    \ 1);\n    }\n    return ret;\n}\n"
  code: "#pragma once\n#include \"../utility/int_alias.cpp\"\n#include <vector>\n\
    #include <utility>\n#include <cassert>\n\ntemplate <class T>\nstd::vector<std::pair<T,\
    \ usize>> factorize(T x) {\n    assert(x > 0);\n    std::vector<std::pair<T, usize>>\
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
  timestamp: '2021-03-26 16:54:27+09:00'
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
