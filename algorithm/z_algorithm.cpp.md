---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/z_algorithm.test.cpp
    title: test/z_algorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algorithm/z_algorithm.cpp\"\n#include <vector>\n#line 2\
    \ \"utility/int_alias.cpp\"\n#include <cstddef>\n#include <cstdint>\n\nusing i32\
    \ = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing\
    \ u64 = std::uint64_t;\nusing isize = std::ptrdiff_t;\nusing usize = std::size_t;\n\
    #line 4 \"algorithm/z_algorithm.cpp\"\n\ntemplate <class Cont> std::vector<usize>\
    \ z_algorithm(const Cont& c) {\n    const usize size = c.size();\n    std::vector<usize>\
    \ ret(size);\n    ret[0] = size;\n    usize i = 1, j = 0;\n    while (i < size)\
    \ {\n        while (i + j < size && c[i + j] == c[j]) j += 1;\n        ret[i]\
    \ = j;\n        if (j == 0) {\n            i += 1;\n            continue;\n  \
    \      }\n        usize k = 1;\n        while (i + k < size && k + ret[k] < j)\
    \ {\n            ret[i + k] = ret[k];\n            k += 1;\n        }\n      \
    \  i += k;\n        j -= k;\n    }\n    return ret;\n}\n"
  code: "#pragma once\n#include <vector>\n#include \"../utility/int_alias.cpp\"\n\n\
    template <class Cont> std::vector<usize> z_algorithm(const Cont& c) {\n    const\
    \ usize size = c.size();\n    std::vector<usize> ret(size);\n    ret[0] = size;\n\
    \    usize i = 1, j = 0;\n    while (i < size) {\n        while (i + j < size\
    \ && c[i + j] == c[j]) j += 1;\n        ret[i] = j;\n        if (j == 0) {\n \
    \           i += 1;\n            continue;\n        }\n        usize k = 1;\n\
    \        while (i + k < size && k + ret[k] < j) {\n            ret[i + k] = ret[k];\n\
    \            k += 1;\n        }\n        i += k;\n        j -= k;\n    }\n   \
    \ return ret;\n}\n"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: algorithm/z_algorithm.cpp
  requiredBy: []
  timestamp: '2021-10-04 09:51:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/z_algorithm.test.cpp
documentation_of: algorithm/z_algorithm.cpp
layout: document
redirect_from:
- /library/algorithm/z_algorithm.cpp
- /library/algorithm/z_algorithm.cpp.html
title: algorithm/z_algorithm.cpp
---
