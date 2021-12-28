---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/factorize_iter.cpp
    title: math/factorize_iter.cpp
  - icon: ':heavy_check_mark:'
    path: utility/collect.cpp
    title: utility/collect.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/factorize.test.cpp
    title: test/factorize.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/factorize.cpp\"\n#include <utility>\n#include <vector>\n\
    #line 2 \"math/factorize_iter.cpp\"\n#include <cassert>\n#line 4 \"math/factorize_iter.cpp\"\
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
    \ int>> factorize(const T& x) { return collect(factorize_iter(x)); }\n"
  code: '#pragma once

    #include <utility>

    #include <vector>

    #include "../math/factorize_iter.cpp"

    #include "../utility/collect.cpp"


    template <class T> std::vector<std::pair<T, int>> factorize(const T& x) { return
    collect(factorize_iter(x)); }

    '
  dependsOn:
  - math/factorize_iter.cpp
  - utility/collect.cpp
  isVerificationFile: false
  path: math/factorize.cpp
  requiredBy: []
  timestamp: '2021-12-28 22:38:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/factorize.test.cpp
documentation_of: math/factorize.cpp
layout: document
redirect_from:
- /library/math/factorize.cpp
- /library/math/factorize.cpp.html
title: math/factorize.cpp
---
