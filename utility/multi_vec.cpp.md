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
  bundledCode: "#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n#include <cstddef>\n\
    \nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    using isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 3 \"utility/multi_vec.cpp\"\
    \n#include <vector>\n#include <type_traits>\n#include <utility>\n\ntemplate <class\
    \ T, usize N, std::enable_if_t<(N != 0)>* = nullptr>\nstruct MultiVecImpl {\n\
    \    using type = std::vector<typename MultiVecImpl<T, N - 1>::type>;\n};\n\n\
    template <class T>\nstruct MultiVecImpl<T, 1> {\n    using type = std::vector<T>;\n\
    };\n\ntemplate <class T, usize N>\nusing MultiVec = typename MultiVecImpl<T, N>::type;\n\
    \ntemplate <class T, class U>\nstd::vector<U> make_vec(T&& size, U&& value) {\n\
    \    return std::vector<U>(std::forward<T>(size), std::forward<U>(value));\n}\n\
    \ntemplate <class T, class... Args>\ndecltype(auto) make_vec(T&& size, Args&&...\
    \ args) {\n    return std::vector<decltype(make_vec(std::forward<Args>(args)...))>(std::forward<T>(size),\
    \ make_vec(std::forward<Args>(args)...));\n}\n"
  code: "#pragma once\n#include \"../utility/int_alias.cpp\"\n#include <vector>\n\
    #include <type_traits>\n#include <utility>\n\ntemplate <class T, usize N, std::enable_if_t<(N\
    \ != 0)>* = nullptr>\nstruct MultiVecImpl {\n    using type = std::vector<typename\
    \ MultiVecImpl<T, N - 1>::type>;\n};\n\ntemplate <class T>\nstruct MultiVecImpl<T,\
    \ 1> {\n    using type = std::vector<T>;\n};\n\ntemplate <class T, usize N>\n\
    using MultiVec = typename MultiVecImpl<T, N>::type;\n\ntemplate <class T, class\
    \ U>\nstd::vector<U> make_vec(T&& size, U&& value) {\n    return std::vector<U>(std::forward<T>(size),\
    \ std::forward<U>(value));\n}\n\ntemplate <class T, class... Args>\ndecltype(auto)\
    \ make_vec(T&& size, Args&&... args) {\n    return std::vector<decltype(make_vec(std::forward<Args>(args)...))>(std::forward<T>(size),\
    \ make_vec(std::forward<Args>(args)...));\n}\n"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: utility/multi_vec.cpp
  requiredBy: []
  timestamp: '2021-04-24 15:52:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/multi_vec.cpp
layout: document
redirect_from:
- /library/utility/multi_vec.cpp
- /library/utility/multi_vec.cpp.html
title: utility/multi_vec.cpp
---
