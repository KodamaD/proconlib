---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: algorithm/z_algorithm.cpp
    title: algorithm/z_algorithm.cpp
  - icon: ':question:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/z_algorithm.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
    \n#line 2 \"algorithm/z_algorithm.cpp\"\n#include <vector>\n\ntemplate <class\
    \ Cont> std::vector<int> z_algorithm(const Cont& c) {\n    const int size = c.size();\n\
    \    std::vector<int> ret(size);\n    ret[0] = size;\n    int i = 1, j = 0;\n\
    \    while (i < size) {\n        while (i + j < size && c[i + j] == c[j]) j +=\
    \ 1;\n        ret[i] = j;\n        if (j == 0) {\n            i += 1;\n      \
    \      continue;\n        }\n        int k = 1;\n        while (i + k < size &&\
    \ k + ret[k] < j) {\n            ret[i + k] = ret[k];\n            k += 1;\n \
    \       }\n        i += k;\n        j -= k;\n    }\n    return ret;\n}\n#line\
    \ 2 \"utility/rep.cpp\"\n#include <algorithm>\n\nclass Range {\n    struct Iter\
    \ {\n        int itr;\n        constexpr Iter(const int pos) noexcept : itr(pos)\
    \ {}\n        constexpr void operator++() noexcept { ++itr; }\n        constexpr\
    \ bool operator!=(const Iter& other) const noexcept { return itr != other.itr;\
    \ }\n        constexpr int operator*() const noexcept { return itr; }\n    };\n\
    \    const Iter first, last;\n\n  public:\n    explicit constexpr Range(const\
    \ int first, const int last) noexcept : first(first), last(std::max(first, last))\
    \ {}\n    constexpr Iter begin() const noexcept { return first; }\n    constexpr\
    \ Iter end() const noexcept { return last; }\n};\n\nconstexpr Range rep(const\
    \ int l, const int r) noexcept { return Range(l, r); }\nconstexpr Range rep(const\
    \ int n) noexcept { return Range(0, n); }\n#line 4 \"test/z_algorithm.test.cpp\"\
    \n#include <iostream>\n#include <string>\n\nint main() {\n    std::string s;\n\
    \    std::cin >> s;\n    const auto a = z_algorithm(s);\n    for (const auto i\
    \ : rep(0, s.size())) {\n        std::cout << a[i] << \" \\n\"[i + 1 == s.size()];\n\
    \    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include\
    \ \"../algorithm/z_algorithm.cpp\"\n#include \"../utility/rep.cpp\"\n#include\
    \ <iostream>\n#include <string>\n\nint main() {\n    std::string s;\n    std::cin\
    \ >> s;\n    const auto a = z_algorithm(s);\n    for (const auto i : rep(0, s.size()))\
    \ {\n        std::cout << a[i] << \" \\n\"[i + 1 == s.size()];\n    }\n    return\
    \ 0;\n}"
  dependsOn:
  - algorithm/z_algorithm.cpp
  - utility/rep.cpp
  isVerificationFile: true
  path: test/z_algorithm.test.cpp
  requiredBy: []
  timestamp: '2021-12-17 09:20:39+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/z_algorithm.test.cpp
layout: document
redirect_from:
- /verify/test/z_algorithm.test.cpp
- /verify/test/z_algorithm.test.cpp.html
title: test/z_algorithm.test.cpp
---
