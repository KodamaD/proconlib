---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/totient.cpp
    title: math/totient.cpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D
  bundledCode: "#line 1 \"test/totient.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D\"\
    \n#line 2 \"utility/int_alias.cpp\"\n#include <cstddef>\n#include <cstdint>\n\n\
    using i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    using isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 2 \"math/totient.cpp\"\
    \n\ntemplate <class T> constexpr T totient(T x) {\n    T ret = x;\n    for (T\
    \ i = 2; i * i <= x; ++i) {\n        if (x % i == 0) {\n            ret /= i;\n\
    \            ret *= i - 1;\n            while (x % i == 0) x /= i;\n        }\n\
    \    }\n    if (x > 1) {\n        ret /= x;\n        ret *= x - 1;\n    }\n  \
    \  return ret;\n}\n#line 4 \"test/totient.test.cpp\"\n#include <iostream>\n\n\
    int main() {\n    u32 x;\n    std::cin >> x;\n    std::cout << totient(x) << '\\\
    n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D\"\
    \n#include \"../utility/int_alias.cpp\"\n#include \"../math/totient.cpp\"\n#include\
    \ <iostream>\n\nint main() {\n    u32 x;\n    std::cin >> x;\n    std::cout <<\
    \ totient(x) << '\\n';\n    return 0;\n}"
  dependsOn:
  - utility/int_alias.cpp
  - math/totient.cpp
  isVerificationFile: true
  path: test/totient.test.cpp
  requiredBy: []
  timestamp: '2021-09-04 17:30:23+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/totient.test.cpp
layout: document
redirect_from:
- /verify/test/totient.test.cpp
- /verify/test/totient.test.cpp.html
title: test/totient.test.cpp
---
