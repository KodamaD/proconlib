---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bit/ceil_log2.cpp
    title: bit/ceil_log2.cpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: container/polynomial_hash.cpp
    title: container/polynomial_hash.cpp
  - icon: ':heavy_check_mark:'
    path: math/modint_util.cpp
    title: math/modint_util.cpp
  - icon: ':heavy_check_mark:'
    path: math/prime_sieve.cpp
    title: math/prime_sieve.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/modint_util.test.cpp
    title: test/modint_util.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/polynomial_hash.test.cpp
    title: test/polynomial_hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/prime_sieve.test.cpp
    title: test/prime_sieve.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/auto_realloc.cpp\"\n#include <utility>\n#include\
    \ <vector>\n#line 2 \"utility/int_alias.cpp\"\n#include <cstddef>\n#include <cstdint>\n\
    \nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing isize = std::ptrdiff_t;\nusing usize = std::size_t;\n\
    #line 3 \"bit/ceil_log2.cpp\"\n\n__attribute__((target(\"avx2\"))) constexpr u64\
    \ ceil_log2(const u64 x) {\n    u64 e = 0;\n    while (((u64)1 << e) < x) ++e;\n\
    \    return e;\n}\n#line 6 \"utility/auto_realloc.cpp\"\n\ntemplate <class F>\
    \ class AutoReallocation {\n    using R = typename decltype(std::declval<F>()((usize)0))::value_type;\n\
    \n    F func;\n    mutable std::vector<R> data;\n\n  public:\n    explicit AutoReallocation(F&&\
    \ f) : func(std::forward<F>(f)), data() {}\n\n    void reserve(const usize size)\
    \ const {\n        if (data.size() < size) data = func(((usize)1 << ceil_log2(size)));\n\
    \    }\n    R operator[](const usize i) const {\n        reserve(i + 1);\n   \
    \     return data[i];\n    }\n};\n\ntemplate <class F> decltype(auto) auto_realloc(F&&\
    \ f) { return AutoReallocation<F>(std::forward<F>(f)); }\n"
  code: "#pragma once\n#include <utility>\n#include <vector>\n#include \"../bit/ceil_log2.cpp\"\
    \n#include \"../utility/int_alias.cpp\"\n\ntemplate <class F> class AutoReallocation\
    \ {\n    using R = typename decltype(std::declval<F>()((usize)0))::value_type;\n\
    \n    F func;\n    mutable std::vector<R> data;\n\n  public:\n    explicit AutoReallocation(F&&\
    \ f) : func(std::forward<F>(f)), data() {}\n\n    void reserve(const usize size)\
    \ const {\n        if (data.size() < size) data = func(((usize)1 << ceil_log2(size)));\n\
    \    }\n    R operator[](const usize i) const {\n        reserve(i + 1);\n   \
    \     return data[i];\n    }\n};\n\ntemplate <class F> decltype(auto) auto_realloc(F&&\
    \ f) { return AutoReallocation<F>(std::forward<F>(f)); }\n"
  dependsOn:
  - bit/ceil_log2.cpp
  - utility/int_alias.cpp
  isVerificationFile: false
  path: utility/auto_realloc.cpp
  requiredBy:
  - math/modint_util.cpp
  - math/prime_sieve.cpp
  - container/polynomial_hash.cpp
  timestamp: '2021-11-03 19:13:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/modint_util.test.cpp
  - test/polynomial_hash.test.cpp
  - test/prime_sieve.test.cpp
documentation_of: utility/auto_realloc.cpp
layout: document
redirect_from:
- /library/utility/auto_realloc.cpp
- /library/utility/auto_realloc.cpp.html
title: utility/auto_realloc.cpp
---
