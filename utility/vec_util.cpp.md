---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/vec_util.cpp\"\n#include <algorithm>\n#include <vector>\n\
    #line 2 \"utility/int_alias.cpp\"\n#include <cstddef>\n#include <cstdint>\n\n\
    using i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing isize = std::ptrdiff_t;\nusing usize = std::size_t;\n\
    #line 5 \"utility/vec_util.cpp\"\n\ntemplate <class T> usize compress(std::vector<T>&\
    \ vec) {\n    std::sort(vec.begin(), vec.end());\n    vec.erase(std::unique(vec.begin(),\
    \ vec.end()), vec.end());\n    return vec.size();\n}\n\ntemplate <class T> usize\
    \ lowb(const std::vector<T>& vec, const T& val) {\n    return std::distance(vec.cbegin(),\
    \ std::lower_bound(vec.cbegin(), vec.cend(), val));\n}\n\ntemplate <class T> usize\
    \ upb(const std::vector<T>& vec, const T& val) {\n    return std::distance(vec.cbegin(),\
    \ std::upper_bound(vec.cbegin(), vec.cend(), val));\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n#include \"../utility/int_alias.cpp\"\
    \n\ntemplate <class T> usize compress(std::vector<T>& vec) {\n    std::sort(vec.begin(),\
    \ vec.end());\n    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());\n\
    \    return vec.size();\n}\n\ntemplate <class T> usize lowb(const std::vector<T>&\
    \ vec, const T& val) {\n    return std::distance(vec.cbegin(), std::lower_bound(vec.cbegin(),\
    \ vec.cend(), val));\n}\n\ntemplate <class T> usize upb(const std::vector<T>&\
    \ vec, const T& val) {\n    return std::distance(vec.cbegin(), std::upper_bound(vec.cbegin(),\
    \ vec.cend(), val));\n}"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: utility/vec_util.cpp
  requiredBy: []
  timestamp: '2021-09-08 18:46:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/vec_util.cpp
layout: document
redirect_from:
- /library/utility/vec_util.cpp
- /library/utility/vec_util.cpp.html
title: utility/vec_util.cpp
---
