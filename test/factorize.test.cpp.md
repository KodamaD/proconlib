---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/factorize.cpp
    title: math/factorize.cpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
  bundledCode: "#line 1 \"test/factorize.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
    \n#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n#include <cstddef>\n\n\
    using i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    using isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 3 \"math/factorize.cpp\"\
    \n#include <vector>\n#include <utility>\n#include <cassert>\n\ntemplate <class\
    \ T>\nstd::vector<std::pair<T, usize>> factorize(T x) {\n    assert(x > 0);\n\
    \    std::vector<std::pair<T, usize>> ret;\n    for (T i = 2; i * i <= x; ++i)\
    \ {\n        if (x % i == 0) {\n            ret.emplace_back(i, 0);\n        \
    \    while (x % i == 0) {\n                ret.back().second++;\n            \
    \    x /= i;\n            }\n        }\n    }\n    if (x > 1) {\n        ret.emplace_back(x,\
    \ 1);\n    }\n    return ret;\n}\n#line 4 \"test/factorize.test.cpp\"\n#include\
    \ <iostream>\n\nint main() {\n    u32 n;\n    std::cin >> n;\n    std::cout <<\
    \ n << ':';\n    for (auto [p, e]: factorize(n)) {\n        while (e--) {\n  \
    \          std::cout << ' ' << p;\n        }\n    }\n    std::cout << '\\n';\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
    \n#include \"../math/factorize.cpp\"\n#include \"../utility/int_alias.cpp\"\n\
    #include <iostream>\n\nint main() {\n    u32 n;\n    std::cin >> n;\n    std::cout\
    \ << n << ':';\n    for (auto [p, e]: factorize(n)) {\n        while (e--) {\n\
    \            std::cout << ' ' << p;\n        }\n    }\n    std::cout << '\\n';\n\
    }"
  dependsOn:
  - math/factorize.cpp
  - utility/int_alias.cpp
  isVerificationFile: true
  path: test/factorize.test.cpp
  requiredBy: []
  timestamp: '2021-03-26 16:54:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/factorize.test.cpp
layout: document
redirect_from:
- /verify/test/factorize.test.cpp
- /verify/test/factorize.test.cpp.html
title: test/factorize.test.cpp
---