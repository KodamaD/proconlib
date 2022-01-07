---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/factorize.cpp
    title: math/factorize.cpp
  - icon: ':x:'
    path: utility/collect.cpp
    title: utility/collect.cpp
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
  bundledCode: "#line 1 \"test/factorize.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
    \n#line 2 \"math/factorize.cpp\"\n#include <cassert>\n#include <utility>\n#include\
    \ <vector>\n#line 3 \"utility/collect.cpp\"\n\ntemplate <class Cont> decltype(auto)\
    \ collect(const Cont& c) {\n    std::vector<decltype(*std::declval<Cont>().begin())>\
    \ ret;\n    for (const auto& x : c) ret.push_back(x);\n    return ret;\n}\n\n\
    template <class Cont> decltype(auto) collect(Cont&& c) {\n    std::vector<decltype(*std::declval<Cont>().begin())>\
    \ ret;\n    for (auto&& x : c) ret.push_back(std::move(x));\n    return ret;\n\
    }\n#line 6 \"math/factorize.cpp\"\n\ntemplate <class T> std::vector<std::pair<T,\
    \ int>> factorize(const T& x) {\n    assert(x > 0);\n    std::vector<std::pair<T,\
    \ int>> ret;\n    for (T p = 2; p * p <= x; ++p) {\n        if (x % p == 0) {\n\
    \            int e = 0;\n            while (x % p == 0) {\n                x /=\
    \ p;\n                e += 1;\n            }\n            ret.emplace_back(p,\
    \ e);\n        }\n    }\n    if (x > 1) ret.emplace_back(x, 1);\n    return ret;\n\
    }\n#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n\nusing i32 = std::int32_t;\n\
    using u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n#line 4 \"test/factorize.test.cpp\"\
    \n#include <iostream>\n\nint main() {\n    u32 n;\n    std::cin >> n;\n    std::cout\
    \ << n << ':';\n    for (auto [p, e]: factorize(n)) {\n        while (e--) {\n\
    \            std::cout << ' ' << p;\n        }\n    }\n    std::cout << '\\n';\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
    \n#include \"../math/factorize.cpp\"\n#include \"../utility/int_alias.cpp\"\n\
    #include <iostream>\n\nint main() {\n    u32 n;\n    std::cin >> n;\n    std::cout\
    \ << n << ':';\n    for (auto [p, e]: factorize(n)) {\n        while (e--) {\n\
    \            std::cout << ' ' << p;\n        }\n    }\n    std::cout << '\\n';\n\
    \    return 0;\n}"
  dependsOn:
  - math/factorize.cpp
  - utility/collect.cpp
  - utility/int_alias.cpp
  isVerificationFile: true
  path: test/factorize.test.cpp
  requiredBy: []
  timestamp: '2022-01-07 21:48:21+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/factorize.test.cpp
layout: document
redirect_from:
- /verify/test/factorize.test.cpp
- /verify/test/factorize.test.cpp.html
title: test/factorize.test.cpp
---
