---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/inv_gcd.cpp
    title: math/inv_gcd.cpp
  - icon: ':heavy_check_mark:'
    path: math/rem_euclid.cpp
    title: math/rem_euclid.cpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':heavy_check_mark:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/congruence_equations.cpp\"\n#include <optional>\n#include\
    \ <type_traits>\n#include <utility>\n#include <vector>\n#line 2 \"math/rem_euclid.cpp\"\
    \n#include <cassert>\n\ntemplate <class T> constexpr T rem_euclid(T value, const\
    \ T& mod) {\n    assert(mod > 0);\n    return (value %= mod) >= 0 ? value : value\
    \ + mod;\n}\n#line 5 \"math/inv_gcd.cpp\"\n\ntemplate <class T> constexpr std::pair<T,\
    \ T> inv_gcd(const T& a, const T& b) {\n    using U = std::make_signed_t<T>;\n\
    \    U t = rem_euclid(a, b);\n    if (t == 0) return {b, 0};\n    U s = b, m0\
    \ = 0, m1 = 1;\n    while (t != 0) {\n        const U u = s / t;\n        s -=\
    \ t * u;\n        m0 -= m1 * u;\n        U tmp = s;\n        s = t;\n        t\
    \ = tmp;\n        tmp = m0;\n        m0 = m1;\n        m1 = tmp;\n    }\n    if\
    \ (m0 < 0) m0 += b / s;\n    return {(T)s, (T)m0};\n}\n#line 2 \"utility/rep.cpp\"\
    \n#include <algorithm>\n#line 2 \"utility/int_alias.cpp\"\n#include <cstddef>\n\
    #include <cstdint>\n\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\n\
    using i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing isize = std::ptrdiff_t;\n\
    using usize = std::size_t;\n#line 4 \"utility/rep.cpp\"\n\nclass rep {\n    struct\
    \ Iter {\n        usize itr;\n        constexpr Iter(const usize pos) noexcept\
    \ : itr(pos) {}\n        constexpr void operator++() noexcept { ++itr; }\n   \
    \     constexpr bool operator!=(const Iter& other) const noexcept { return itr\
    \ != other.itr; }\n        constexpr usize operator*() const noexcept { return\
    \ itr; }\n    };\n    const Iter first, last;\n\n  public:\n    explicit constexpr\
    \ rep(const usize first, const usize last) noexcept : first(first), last(std::max(first,\
    \ last)) {}\n    constexpr Iter begin() const noexcept { return first; }\n   \
    \ constexpr Iter end() const noexcept { return last; }\n};\n#line 9 \"math/congruence_equations.cpp\"\
    \n\ntemplate <class T, class Result = T>\nstd::optional<std::pair<Result, Result>>\
    \ congruence_equations(const std::vector<T>& m, const std::vector<T>& r) {\n \
    \   using U = std::make_signed_t<Result>;\n    assert(m.size() == r.size());\n\
    \    const usize n = m.size();\n    U r0 = 0, m0 = 1;\n    for (const usize i\
    \ : rep(0, n)) {\n        assert(m[i] > 0);\n        U r1 = rem_euclid(r[i], m[i]),\
    \ m1 = m[i];\n        if (m0 < m1) {\n            std::swap(r0, r1);\n       \
    \     std::swap(m0, m1);\n        }\n        if (m0 % m1 == 0) {\n           \
    \ if (r0 % m1 != r1) return std::nullopt;\n            continue;\n        }\n\
    \        const auto [g, inv_m] = inv_gcd(m0, m1);\n        if ((r1 - r0) % g !=\
    \ 0) return std::nullopt;\n        const U u1 = m1 / g;\n        const U x = (r1\
    \ - r0) / g % u1 * inv_m % u1;\n        r0 += x * m0;\n        m0 *= u1;\n   \
    \     if (r0 < 0) r0 += m0;\n    }\n    return std::pair<Result, Result>(r0, m0);\n\
    }\n"
  code: "#pragma once\n#include <optional>\n#include <type_traits>\n#include <utility>\n\
    #include <vector>\n#include \"../math/inv_gcd.cpp\"\n#include \"../math/rem_euclid.cpp\"\
    \n#include \"../utility/rep.cpp\"\n\ntemplate <class T, class Result = T>\nstd::optional<std::pair<Result,\
    \ Result>> congruence_equations(const std::vector<T>& m, const std::vector<T>&\
    \ r) {\n    using U = std::make_signed_t<Result>;\n    assert(m.size() == r.size());\n\
    \    const usize n = m.size();\n    U r0 = 0, m0 = 1;\n    for (const usize i\
    \ : rep(0, n)) {\n        assert(m[i] > 0);\n        U r1 = rem_euclid(r[i], m[i]),\
    \ m1 = m[i];\n        if (m0 < m1) {\n            std::swap(r0, r1);\n       \
    \     std::swap(m0, m1);\n        }\n        if (m0 % m1 == 0) {\n           \
    \ if (r0 % m1 != r1) return std::nullopt;\n            continue;\n        }\n\
    \        const auto [g, inv_m] = inv_gcd(m0, m1);\n        if ((r1 - r0) % g !=\
    \ 0) return std::nullopt;\n        const U u1 = m1 / g;\n        const U x = (r1\
    \ - r0) / g % u1 * inv_m % u1;\n        r0 += x * m0;\n        m0 *= u1;\n   \
    \     if (r0 < 0) r0 += m0;\n    }\n    return std::pair<Result, Result>(r0, m0);\n\
    }\n"
  dependsOn:
  - math/inv_gcd.cpp
  - math/rem_euclid.cpp
  - utility/rep.cpp
  - utility/int_alias.cpp
  isVerificationFile: false
  path: math/congruence_equations.cpp
  requiredBy: []
  timestamp: '2021-11-01 21:39:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/congruence_equations.cpp
layout: document
redirect_from:
- /library/math/congruence_equations.cpp
- /library/math/congruence_equations.cpp.html
title: math/congruence_equations.cpp
---
