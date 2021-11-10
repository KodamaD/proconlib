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
  bundledCode: "#line 2 \"utility/permutations.cpp\"\n#include <algorithm>\n#include\
    \ <numeric>\n#include <variant>\n#include <vector>\n#line 2 \"utility/int_alias.cpp\"\
    \n#include <cstddef>\n#include <cstdint>\n\nusing i32 = std::int32_t;\nusing u32\
    \ = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing\
    \ isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 7 \"utility/permutations.cpp\"\
    \n\nclass permutations {\n    struct Iter {\n        bool f;\n        std::vector<usize>\
    \ v;\n        explicit Iter(const usize n, const usize k) noexcept : f(true),\
    \ v(n) { std::iota(v.begin(), v.end(), k); }\n        bool operator!=(std::monostate)\
    \ const noexcept { return f; }\n        void operator++() noexcept { f = std::next_permutation(v.begin(),\
    \ v.end()); }\n        const std::vector<usize>& operator*() noexcept { return\
    \ v; }\n    };\n    Iter iter;\n\n  public:\n    explicit permutations(const usize\
    \ n, const usize k = 0) noexcept : iter(n, k) {}\n    Iter begin() const noexcept\
    \ { return iter; }\n    std::monostate end() noexcept { return {}; }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <numeric>\n#include <variant>\n\
    #include <vector>\n#include \"int_alias.cpp\"\n\nclass permutations {\n    struct\
    \ Iter {\n        bool f;\n        std::vector<usize> v;\n        explicit Iter(const\
    \ usize n, const usize k) noexcept : f(true), v(n) { std::iota(v.begin(), v.end(),\
    \ k); }\n        bool operator!=(std::monostate) const noexcept { return f; }\n\
    \        void operator++() noexcept { f = std::next_permutation(v.begin(), v.end());\
    \ }\n        const std::vector<usize>& operator*() noexcept { return v; }\n  \
    \  };\n    Iter iter;\n\n  public:\n    explicit permutations(const usize n, const\
    \ usize k = 0) noexcept : iter(n, k) {}\n    Iter begin() const noexcept { return\
    \ iter; }\n    std::monostate end() noexcept { return {}; }\n};\n"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: utility/permutations.cpp
  requiredBy: []
  timestamp: '2021-11-10 20:31:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/permutations.cpp
layout: document
redirect_from:
- /library/utility/permutations.cpp
- /library/utility/permutations.cpp.html
title: utility/permutations.cpp
---
