---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/factorize.cpp
    title: math/factorize.cpp
  - icon: ':heavy_check_mark:'
    path: math/factorize_iter.cpp
    title: math/factorize_iter.cpp
  - icon: ':heavy_check_mark:'
    path: utility/collect.cpp
    title: utility/collect.cpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
  bundledCode: "#line 1 \"test/factorize.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
    \n#line 2 \"math/factorize.cpp\"\n#include <utility>\n#include <vector>\n#line\
    \ 2 \"math/factorize_iter.cpp\"\n#include <cassert>\n#line 4 \"math/factorize_iter.cpp\"\
    \n#include <variant>\n\ntemplate <class T> class Factorizer {\n    struct Iter\
    \ {\n        T s, t;\n        explicit constexpr Iter(const T& s, const T& t)\
    \ noexcept : s(s), t(t) {}\n        constexpr bool operator!=(std::monostate)\
    \ const noexcept { return s != 1; }\n        constexpr void operator++() noexcept\
    \ { t += 1; }\n        constexpr std::pair<T, int> operator*() noexcept {\n  \
    \          while (s % t != 0) {\n                if (t * t > s) {\n          \
    \          const T u = s;\n                    s = 1;\n                    return\
    \ {u, 1};\n                }\n                t += 1;\n            }\n       \
    \     int e = 0;\n            while (s % t == 0) {\n                e += 1;\n\
    \                s /= t;\n            }\n            return {t, e};\n        }\n\
    \    };\n    T x;\n\n  public:\n    explicit constexpr Factorizer(const T& x)\
    \ noexcept : x(x) { assert(x > 0); }\n    constexpr Iter begin() const noexcept\
    \ { return Iter(x, 2); }\n    constexpr std::monostate end() noexcept { return\
    \ {}; }\n};\n\ntemplate <class T> constexpr Factorizer<T> factorize_iter(const\
    \ T& x) noexcept { return Factorizer<T>(x); }\n#line 3 \"utility/collect.cpp\"\
    \n\ntemplate <class Cont> decltype(auto) collect(const Cont& c) {\n    std::vector<decltype(*std::declval<Cont>().begin())>\
    \ ret;\n    for (const auto& x : c) ret.push_back(x);\n    return ret;\n}\n\n\
    template <class Cont> decltype(auto) collect(Cont&& c) {\n    std::vector<decltype(*std::declval<Cont>().begin())>\
    \ ret;\n    for (auto&& x : c) ret.push_back(std::move(x));\n    return ret;\n\
    }\n#line 6 \"math/factorize.cpp\"\n\ntemplate <class T> std::vector<std::pair<T,\
    \ int>> factorize(const T& x) { return collect(factorize_iter(x)); }\n#line 2\
    \ \"utility/int_alias.cpp\"\n#include <cstdint>\n\nusing i32 = std::int32_t;\n\
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
  - math/factorize_iter.cpp
  - utility/collect.cpp
  - utility/int_alias.cpp
  isVerificationFile: true
  path: test/factorize.test.cpp
  requiredBy: []
  timestamp: '2021-12-28 22:38:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/factorize.test.cpp
layout: document
redirect_from:
- /verify/test/factorize.test.cpp
- /verify/test/factorize.test.cpp.html
title: test/factorize.test.cpp
---
