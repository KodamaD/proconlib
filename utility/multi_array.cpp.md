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
  bundledCode: "#line 2 \"utility/multi_array.cpp\"\n#include <array>\n#include <type_traits>\n\
    #line 2 \"utility/int_alias.cpp\"\n#include <cstddef>\n#include <cstdint>\n\n\
    using i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    using isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 5 \"utility/multi_array.cpp\"\
    \n\ntemplate <class T, usize N, usize... Seq> struct MultiArrayImpl {\n    using\
    \ type = std::array<typename MultiArrayImpl<T, Seq...>::type, N>;\n};\n\ntemplate\
    \ <class T, usize N> struct MultiArrayImpl<T, N> { using type = std::array<T,\
    \ N>; };\n\ntemplate <class T, usize N, usize... Seq> using MultiArray = typename\
    \ MultiArrayImpl<T, N, Seq...>::type;\n"
  code: "#pragma once\n#include <array>\n#include <type_traits>\n#include \"../utility/int_alias.cpp\"\
    \n\ntemplate <class T, usize N, usize... Seq> struct MultiArrayImpl {\n    using\
    \ type = std::array<typename MultiArrayImpl<T, Seq...>::type, N>;\n};\n\ntemplate\
    \ <class T, usize N> struct MultiArrayImpl<T, N> { using type = std::array<T,\
    \ N>; };\n\ntemplate <class T, usize N, usize... Seq> using MultiArray = typename\
    \ MultiArrayImpl<T, N, Seq...>::type;\n"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: utility/multi_array.cpp
  requiredBy: []
  timestamp: '2021-09-04 17:30:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/multi_array.cpp
layout: document
redirect_from:
- /library/utility/multi_array.cpp
- /library/utility/multi_array.cpp.html
title: utility/multi_array.cpp
---
