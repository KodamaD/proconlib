---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/multi_array.cpp\"\n#include <array>\n#include <type_traits>\n\
    \nnamespace proconlib {\n\ntemplate <class T, int N, int... Seq> struct MultiArrayImpl\
    \ {\n    using type = std::array<typename MultiArrayImpl<T, Seq...>::type, N>;\n\
    };\n\ntemplate <class T, int N> struct MultiArrayImpl<T, N> { using type = std::array<T,\
    \ N>; };\n\n}  // namespace proconlib\n\ntemplate <class T, int N, int... Seq>\
    \ using MultiArray = typename proconlib::MultiArrayImpl<T, N, Seq...>::type;\n"
  code: "#pragma once\n#include <array>\n#include <type_traits>\n\nnamespace proconlib\
    \ {\n\ntemplate <class T, int N, int... Seq> struct MultiArrayImpl {\n    using\
    \ type = std::array<typename MultiArrayImpl<T, Seq...>::type, N>;\n};\n\ntemplate\
    \ <class T, int N> struct MultiArrayImpl<T, N> { using type = std::array<T, N>;\
    \ };\n\n}  // namespace proconlib\n\ntemplate <class T, int N, int... Seq> using\
    \ MultiArray = typename proconlib::MultiArrayImpl<T, N, Seq...>::type;\n"
  dependsOn: []
  isVerificationFile: false
  path: utility/multi_array.cpp
  requiredBy: []
  timestamp: '2021-12-17 09:20:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/multi_array.cpp
layout: document
redirect_from:
- /library/utility/multi_array.cpp
- /library/utility/multi_array.cpp.html
title: utility/multi_array.cpp
---
