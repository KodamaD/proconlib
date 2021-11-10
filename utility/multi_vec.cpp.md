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
  bundledCode: "#line 2 \"utility/multi_vec.cpp\"\n#include <type_traits>\n#include\
    \ <utility>\n#include <vector>\n#line 2 \"utility/int_alias.cpp\"\n#include <cstddef>\n\
    #include <cstdint>\n\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\n\
    using i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing isize = std::ptrdiff_t;\n\
    using usize = std::size_t;\n#line 6 \"utility/multi_vec.cpp\"\n\ntemplate <class\
    \ T, usize N, std::enable_if_t<(N != 0)>* = nullptr> struct MultiVecImpl {\n \
    \   using type = std::vector<typename MultiVecImpl<T, N - 1>::type>;\n};\n\ntemplate\
    \ <class T> struct MultiVecImpl<T, 1> { using type = std::vector<T>; };\n\ntemplate\
    \ <class T, usize N> using MultiVec = typename MultiVecImpl<T, N>::type;\n\ntemplate\
    \ <class T, class U> decltype(auto) make_vec(T&& size, U&& value) {\n    using\
    \ V = std::decay_t<U>;\n    return std::vector<V>(std::forward<T>(size), std::forward<V>(value));\n\
    }\n\ntemplate <class T, class... Args> decltype(auto) make_vec(T&& size, Args&&...\
    \ args) {\n    return std::vector<decltype(make_vec(std::forward<Args>(args)...))>(std::forward<T>(size),\n\
    \                                                                        make_vec(std::forward<Args>(args)...));\n\
    }\n"
  code: "#pragma once\n#include <type_traits>\n#include <utility>\n#include <vector>\n\
    #include \"int_alias.cpp\"\n\ntemplate <class T, usize N, std::enable_if_t<(N\
    \ != 0)>* = nullptr> struct MultiVecImpl {\n    using type = std::vector<typename\
    \ MultiVecImpl<T, N - 1>::type>;\n};\n\ntemplate <class T> struct MultiVecImpl<T,\
    \ 1> { using type = std::vector<T>; };\n\ntemplate <class T, usize N> using MultiVec\
    \ = typename MultiVecImpl<T, N>::type;\n\ntemplate <class T, class U> decltype(auto)\
    \ make_vec(T&& size, U&& value) {\n    using V = std::decay_t<U>;\n    return\
    \ std::vector<V>(std::forward<T>(size), std::forward<V>(value));\n}\n\ntemplate\
    \ <class T, class... Args> decltype(auto) make_vec(T&& size, Args&&... args) {\n\
    \    return std::vector<decltype(make_vec(std::forward<Args>(args)...))>(std::forward<T>(size),\n\
    \                                                                        make_vec(std::forward<Args>(args)...));\n\
    }\n"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: utility/multi_vec.cpp
  requiredBy: []
  timestamp: '2021-11-10 20:31:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/multi_vec.cpp
layout: document
redirect_from:
- /library/utility/multi_vec.cpp
- /library/utility/multi_vec.cpp.html
title: utility/multi_vec.cpp
---
