---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algorithm/convolution_arbitrary_mod.cpp
    title: algorithm/convolution_arbitrary_mod.cpp
  - icon: ':warning:'
    path: algorithm/convolution_int.cpp
    title: algorithm/convolution_int.cpp
  - icon: ':heavy_check_mark:'
    path: algorithm/convolution_mod.cpp
    title: algorithm/convolution_mod.cpp
  - icon: ':heavy_check_mark:'
    path: math/factorize.cpp
    title: math/factorize.cpp
  - icon: ':heavy_check_mark:'
    path: math/static_modint.cpp
    title: math/static_modint.cpp
  - icon: ':heavy_check_mark:'
    path: math/totient.cpp
    title: math/totient.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/and_convolution.test.cpp
    title: test/and_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/berlekamp_massey.test.cpp
    title: test/berlekamp_massey.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution_arbitrary_mod.test.cpp
    title: test/convolution_arbitrary_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/convolution_mod.test.cpp
    title: test/convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/factorize.test.cpp
    title: test/factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fp_util.test.cpp
    title: test/fp_util.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/heavy_light_decomposition.test.cpp
    title: test/heavy_light_decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazy_segment_tree.test.cpp
    title: test/lazy_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/queue_aggregation.test.cpp
    title: test/queue_aggregation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment_tree.test.cpp
    title: test/segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/semiring_matrix.test.cpp
    title: test/semiring_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/totient.test.cpp
    title: test/totient.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/factorize_iter.cpp\"\n#include <cassert>\n#include\
    \ <utility>\n#include <variant>\n\ntemplate <class T> class Factorizer {\n   \
    \ struct Iter {\n        T s, t;\n        explicit constexpr Iter(const T& s,\
    \ const T& t) noexcept : s(s), t(t) {}\n        constexpr bool operator!=(std::monostate)\
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
    \ T& x) noexcept { return Factorizer<T>(x); }\n"
  code: "#pragma once\n#include <cassert>\n#include <utility>\n#include <variant>\n\
    \ntemplate <class T> class Factorizer {\n    struct Iter {\n        T s, t;\n\
    \        explicit constexpr Iter(const T& s, const T& t) noexcept : s(s), t(t)\
    \ {}\n        constexpr bool operator!=(std::monostate) const noexcept { return\
    \ s != 1; }\n        constexpr void operator++() noexcept { t += 1; }\n      \
    \  constexpr std::pair<T, int> operator*() noexcept {\n            while (s %\
    \ t != 0) {\n                if (t * t > s) {\n                    const T u =\
    \ s;\n                    s = 1;\n                    return {u, 1};\n       \
    \         }\n                t += 1;\n            }\n            int e = 0;\n\
    \            while (s % t == 0) {\n                e += 1;\n                s\
    \ /= t;\n            }\n            return {t, e};\n        }\n    };\n    T x;\n\
    \n  public:\n    explicit constexpr Factorizer(const T& x) noexcept : x(x) { assert(x\
    \ > 0); }\n    constexpr Iter begin() const noexcept { return Iter(x, 2); }\n\
    \    constexpr std::monostate end() noexcept { return {}; }\n};\n\ntemplate <class\
    \ T> constexpr Factorizer<T> factorize_iter(const T& x) noexcept { return Factorizer<T>(x);\
    \ }"
  dependsOn: []
  isVerificationFile: false
  path: math/factorize_iter.cpp
  requiredBy:
  - math/factorize.cpp
  - math/totient.cpp
  - math/static_modint.cpp
  - algorithm/convolution_mod.cpp
  - algorithm/convolution_arbitrary_mod.cpp
  - algorithm/convolution_int.cpp
  timestamp: '2021-12-28 22:38:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution_arbitrary_mod.test.cpp
  - test/totient.test.cpp
  - test/queue_aggregation.test.cpp
  - test/semiring_matrix.test.cpp
  - test/lazy_segment_tree.test.cpp
  - test/berlekamp_massey.test.cpp
  - test/heavy_light_decomposition.test.cpp
  - test/segment_tree.test.cpp
  - test/and_convolution.test.cpp
  - test/convolution_mod.test.cpp
  - test/fp_util.test.cpp
  - test/factorize.test.cpp
documentation_of: math/factorize_iter.cpp
layout: document
redirect_from:
- /library/math/factorize_iter.cpp
- /library/math/factorize_iter.cpp.html
title: math/factorize_iter.cpp
---
