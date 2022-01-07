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
  bundledCode: "#line 2 \"utility/permutations.cpp\"\n#include <algorithm>\n#include\
    \ <numeric>\n#include <variant>\n#include <vector>\n\nclass PermutationScanner\
    \ {\n    struct Iter {\n        bool f;\n        std::vector<int> v;\n       \
    \ explicit Iter(const int n, const int k) noexcept : f(true), v(n) { std::iota(v.begin(),\
    \ v.end(), k); }\n        bool operator!=(std::monostate) const noexcept { return\
    \ f; }\n        void operator++() noexcept { f = std::next_permutation(v.begin(),\
    \ v.end()); }\n        const std::vector<int>& operator*() noexcept { return v;\
    \ }\n    };\n    Iter iter;\n\n  public:\n    explicit PermutationScanner(const\
    \ int n, const int k = 0) noexcept : iter(n, k) {}\n    Iter begin() const noexcept\
    \ { return iter; }\n    std::monostate end() const noexcept { return {}; }\n};\n\
    \nPermutationScanner permutations(const int n, const int k = 0) noexcept { return\
    \ PermutationScanner(n, k); }\n"
  code: "#pragma once\n#include <algorithm>\n#include <numeric>\n#include <variant>\n\
    #include <vector>\n\nclass PermutationScanner {\n    struct Iter {\n        bool\
    \ f;\n        std::vector<int> v;\n        explicit Iter(const int n, const int\
    \ k) noexcept : f(true), v(n) { std::iota(v.begin(), v.end(), k); }\n        bool\
    \ operator!=(std::monostate) const noexcept { return f; }\n        void operator++()\
    \ noexcept { f = std::next_permutation(v.begin(), v.end()); }\n        const std::vector<int>&\
    \ operator*() noexcept { return v; }\n    };\n    Iter iter;\n\n  public:\n  \
    \  explicit PermutationScanner(const int n, const int k = 0) noexcept : iter(n,\
    \ k) {}\n    Iter begin() const noexcept { return iter; }\n    std::monostate\
    \ end() const noexcept { return {}; }\n};\n\nPermutationScanner permutations(const\
    \ int n, const int k = 0) noexcept { return PermutationScanner(n, k); }\n"
  dependsOn: []
  isVerificationFile: false
  path: utility/permutations.cpp
  requiredBy: []
  timestamp: '2022-01-07 21:48:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/permutations.cpp
layout: document
redirect_from:
- /library/utility/permutations.cpp
- /library/utility/permutations.cpp.html
title: utility/permutations.cpp
---
