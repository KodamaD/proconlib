---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':heavy_check_mark:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/berlekamp_massey.test.cpp
    title: test/berlekamp_massey.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algorithm/berlekamp_massey.cpp\"\n#include <vector>\n#line\
    \ 2 \"utility/int_alias.cpp\"\n#include <cstddef>\n#include <cstdint>\n\nusing\
    \ i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing isize = std::ptrdiff_t;\nusing usize = std::size_t;\n\
    #line 2 \"utility/rep.cpp\"\n#include <algorithm>\n#line 4 \"utility/rep.cpp\"\
    \n\nclass rep {\n    struct Iter {\n        usize itr;\n        constexpr Iter(const\
    \ usize pos) noexcept : itr(pos) {}\n        constexpr void operator++() noexcept\
    \ { ++itr; }\n        constexpr bool operator!=(const Iter& other) const noexcept\
    \ { return itr != other.itr; }\n        constexpr usize operator*() const noexcept\
    \ { return itr; }\n    };\n    const Iter first, last;\n\n  public:\n    explicit\
    \ constexpr rep(const usize first, const usize last) noexcept : first(first),\
    \ last(std::max(first, last)) {}\n    constexpr Iter begin() const noexcept {\
    \ return first; }\n    constexpr Iter end() const noexcept { return last; }\n\
    };\n#line 5 \"algorithm/berlekamp_massey.cpp\"\n\ntemplate <class T> std::vector<T>\
    \ berlekamp_massey(const std::vector<T>& a) {\n    const usize n = a.size();\n\
    \    std::vector<T> c = {T(-1)}, c2 = {T(0)};\n    T r2 = 1;\n    usize i2 = 0;\n\
    \    for (const usize i : rep(0, n)) {\n        T r = 0;\n        const usize\
    \ d = c.size();\n        for (const usize j : rep(0, d)) r += c[j] * a[i - j];\n\
    \        if (r == T(0)) continue;\n        T coeff = -r / r2;\n        const usize\
    \ d2 = c2.size(), shift = i - i2 + 1;\n        if (d2 + shift <= d) {\n      \
    \      for (const usize j : rep(0, d2)) c[j + shift] += c2[j] * coeff;\n     \
    \   } else {\n            std::vector<T> tmp = c;\n            c.resize(d2 + shift);\n\
    \            for (const usize j : rep(0, d2)) c[j + shift] += c2[j] * coeff;\n\
    \            c2 = std::move(tmp);\n            i2 = i + 1;\n            r2 = r;\n\
    \        }\n    }\n    c.erase(c.begin());\n    return c;\n}\n"
  code: "#pragma once\n#include <vector>\n#include \"../utility/int_alias.cpp\"\n\
    #include \"../utility/rep.cpp\"\n\ntemplate <class T> std::vector<T> berlekamp_massey(const\
    \ std::vector<T>& a) {\n    const usize n = a.size();\n    std::vector<T> c =\
    \ {T(-1)}, c2 = {T(0)};\n    T r2 = 1;\n    usize i2 = 0;\n    for (const usize\
    \ i : rep(0, n)) {\n        T r = 0;\n        const usize d = c.size();\n    \
    \    for (const usize j : rep(0, d)) r += c[j] * a[i - j];\n        if (r == T(0))\
    \ continue;\n        T coeff = -r / r2;\n        const usize d2 = c2.size(), shift\
    \ = i - i2 + 1;\n        if (d2 + shift <= d) {\n            for (const usize\
    \ j : rep(0, d2)) c[j + shift] += c2[j] * coeff;\n        } else {\n         \
    \   std::vector<T> tmp = c;\n            c.resize(d2 + shift);\n            for\
    \ (const usize j : rep(0, d2)) c[j + shift] += c2[j] * coeff;\n            c2\
    \ = std::move(tmp);\n            i2 = i + 1;\n            r2 = r;\n        }\n\
    \    }\n    c.erase(c.begin());\n    return c;\n}"
  dependsOn:
  - utility/int_alias.cpp
  - utility/rep.cpp
  isVerificationFile: false
  path: algorithm/berlekamp_massey.cpp
  requiredBy: []
  timestamp: '2021-11-04 19:10:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/berlekamp_massey.test.cpp
documentation_of: algorithm/berlekamp_massey.cpp
layout: document
redirect_from:
- /library/algorithm/berlekamp_massey.cpp
- /library/algorithm/berlekamp_massey.cpp.html
title: algorithm/berlekamp_massey.cpp
---
