---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/factorize_iter.cpp
    title: math/factorize_iter.cpp
  - icon: ':heavy_check_mark:'
    path: math/totient.cpp
    title: math/totient.cpp
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D
  bundledCode: "#line 1 \"test/totient.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D\"\
    \n#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n\nusing i32 = std::int32_t;\n\
    using u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n#line 2 \"math/factorize_iter.cpp\"\
    \n#include <cassert>\n#include <utility>\n#include <variant>\n\ntemplate <class\
    \ T> class Factorizer {\n    struct Iter {\n        T s, t;\n        explicit\
    \ constexpr Iter(const T& s, const T& t) noexcept : s(s), t(t) {}\n        constexpr\
    \ bool operator!=(std::monostate) const noexcept { return s != 1; }\n        constexpr\
    \ void operator++() noexcept { t += 1; }\n        constexpr std::pair<T, int>\
    \ operator*() noexcept {\n            while (s % t != 0) {\n                if\
    \ (t * t > s) {\n                    const T u = s;\n                    s = 1;\n\
    \                    return {u, 1};\n                }\n                t += 1;\n\
    \            }\n            int e = 0;\n            while (s % t == 0) {\n   \
    \             e += 1;\n                s /= t;\n            }\n            return\
    \ {t, e};\n        }\n    };\n    T x;\n\n  public:\n    explicit constexpr Factorizer(const\
    \ T& x) noexcept : x(x) { assert(x > 0); }\n    constexpr Iter begin() const noexcept\
    \ { return Iter(x, 2); }\n    constexpr std::monostate end() noexcept { return\
    \ {}; }\n};\n\ntemplate <class T> constexpr Factorizer<T> factorize_iter(const\
    \ T& x) noexcept { return Factorizer<T>(x); }\n#line 3 \"math/totient.cpp\"\n\n\
    template <class T> constexpr T totient(T x) {\n    T ret = x;\n    for (const\
    \ auto& p : factorize_iter(x)) {\n        ret /= p.first;\n        ret *= p.first\
    \ - 1;\n    }\n    return ret;\n}\n#line 4 \"test/totient.test.cpp\"\n#include\
    \ <iostream>\n\nint main() {\n    u32 x;\n    std::cin >> x;\n    std::cout <<\
    \ totient(x) << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D\"\
    \n#include \"../utility/int_alias.cpp\"\n#include \"../math/totient.cpp\"\n#include\
    \ <iostream>\n\nint main() {\n    u32 x;\n    std::cin >> x;\n    std::cout <<\
    \ totient(x) << '\\n';\n    return 0;\n}"
  dependsOn:
  - utility/int_alias.cpp
  - math/totient.cpp
  - math/factorize_iter.cpp
  isVerificationFile: true
  path: test/totient.test.cpp
  requiredBy: []
  timestamp: '2021-12-28 22:38:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/totient.test.cpp
layout: document
redirect_from:
- /verify/test/totient.test.cpp
- /verify/test/totient.test.cpp.html
title: test/totient.test.cpp
---
