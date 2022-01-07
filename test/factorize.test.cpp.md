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
    \n#line 2 \"math/factorize.cpp\"\n#include <cassert>\n#include <utility>\n#include\
    \ <vector>\n\ntemplate <class T> std::vector<std::pair<T, int>> factorize(T x)\
    \ {\n    assert(x > 0);\n    std::vector<std::pair<T, int>> ret;\n    for (T p\
    \ = 2; p * p <= x; ++p) {\n        if (x % p == 0) {\n            int e = 0;\n\
    \            while (x % p == 0) {\n                x /= p;\n                e\
    \ += 1;\n            }\n            ret.emplace_back(p, e);\n        }\n    }\n\
    \    if (x > 1) ret.emplace_back(x, 1);\n    return ret;\n}\n#line 2 \"utility/int_alias.cpp\"\
    \n#include <cstdint>\n\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\n\
    using i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\n#line 4 \"test/factorize.test.cpp\"\n#include <iostream>\n\
    \nint main() {\n    u32 n;\n    std::cin >> n;\n    std::cout << n << ':';\n \
    \   for (auto [p, e]: factorize(n)) {\n        while (e--) {\n            std::cout\
    \ << ' ' << p;\n        }\n    }\n    std::cout << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
    \n#include \"../math/factorize.cpp\"\n#include \"../utility/int_alias.cpp\"\n\
    #include <iostream>\n\nint main() {\n    u32 n;\n    std::cin >> n;\n    std::cout\
    \ << n << ':';\n    for (auto [p, e]: factorize(n)) {\n        while (e--) {\n\
    \            std::cout << ' ' << p;\n        }\n    }\n    std::cout << '\\n';\n\
    \    return 0;\n}"
  dependsOn:
  - math/factorize.cpp
  - utility/int_alias.cpp
  isVerificationFile: true
  path: test/factorize.test.cpp
  requiredBy: []
  timestamp: '2022-01-07 22:21:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/factorize.test.cpp
layout: document
redirect_from:
- /verify/test/factorize.test.cpp
- /verify/test/factorize.test.cpp.html
title: test/factorize.test.cpp
---
