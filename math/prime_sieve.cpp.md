---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bit/ceil_log2.cpp
    title: bit/ceil_log2.cpp
  - icon: ':heavy_check_mark:'
    path: utility/auto_realloc.cpp
    title: utility/auto_realloc.cpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':heavy_check_mark:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/prime_sieve.test.cpp
    title: test/prime_sieve.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/prime_sieve.cpp\"\n#include <cassert>\n#include <numeric>\n\
    #include <utility>\n#include <vector>\n#line 2 \"utility/int_alias.cpp\"\n#include\
    \ <cstddef>\n#include <cstdint>\n\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\n\
    using i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing isize = std::ptrdiff_t;\n\
    using usize = std::size_t;\n#line 3 \"bit/ceil_log2.cpp\"\n\n__attribute__((target(\"\
    avx2\"))) constexpr u64 ceil_log2(const u64 x) {\n    u64 e = 0;\n    while (((u64)1\
    \ << e) < x) ++e;\n    return e;\n}\n#line 6 \"utility/auto_realloc.cpp\"\n\n\
    template <class F> class AutoReallocation {\n    using R = typename decltype(std::declval<F>()((usize)0))::value_type;\n\
    \n    F func;\n    mutable std::vector<R> data;\n\n  public:\n    explicit AutoReallocation(F&&\
    \ f) : func(std::forward<F>(f)), data() {}\n\n    void reserve(const usize size)\
    \ const {\n        if (data.size() < size) data = func(((usize)1 << ceil_log2(size)));\n\
    \    }\n    R operator[](const usize i) const {\n        reserve(i + 1);\n   \
    \     return data[i];\n    }\n};\n\ntemplate <class F> decltype(auto) auto_realloc(F&&\
    \ f) {\n    using G = std::decay_t<F>;\n    return AutoReallocation<G>(std::forward<G>(f));\n\
    }\n#line 2 \"utility/rep.cpp\"\n#include <algorithm>\n#line 4 \"utility/rep.cpp\"\
    \n\nclass rep {\n    struct Iter {\n        usize itr;\n        constexpr Iter(const\
    \ usize pos) noexcept : itr(pos) {}\n        constexpr void operator++() noexcept\
    \ { ++itr; }\n        constexpr bool operator!=(const Iter& other) const noexcept\
    \ { return itr != other.itr; }\n        constexpr usize operator*() const noexcept\
    \ { return itr; }\n    };\n    const Iter first, last;\n\n  public:\n    explicit\
    \ constexpr rep(const usize first, const usize last) noexcept : first(first),\
    \ last(std::max(first, last)) {}\n    constexpr Iter begin() const noexcept {\
    \ return first; }\n    constexpr Iter end() const noexcept { return last; }\n\
    };\n#line 9 \"math/prime_sieve.cpp\"\n\nstruct PrimeSieve {\n    static inline\
    \ const auto min_prime = auto_realloc([](const usize n) {\n        std::vector<usize>\
    \ ret(n);\n        std::iota(ret.begin(), ret.end(), (usize)0);\n        std::vector<usize>\
    \ list;\n        for (const usize i : rep(2, n)) {\n            if (ret[i] ==\
    \ i) list.push_back(i);\n            for (const usize p : list) {\n          \
    \      if (p * i >= n || p > ret[i]) break;\n                ret[p * i] = p;\n\
    \            }\n        }\n        return ret;\n    });\n    static bool is_prime(const\
    \ usize n) {\n        if (n <= 1) return false;\n        return min_prime[n] ==\
    \ n;\n    }\n    template <class T> static std::vector<std::pair<T, usize>> factorize(T\
    \ x) {\n        assert(x > 0);\n        std::vector<std::pair<T, usize>> ret;\n\
    \        while (x != 1) {\n            const usize p = min_prime[x];\n       \
    \     ret.emplace_back((T)p, 0);\n            while (min_prime[x] == p) {\n  \
    \              ret.back().second++;\n                x /= p;\n            }\n\
    \        }\n        return ret;\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <numeric>\n#include <utility>\n\
    #include <vector>\n#include \"../utility/auto_realloc.cpp\"\n#include \"../utility/int_alias.cpp\"\
    \n#include \"../utility/rep.cpp\"\n\nstruct PrimeSieve {\n    static inline const\
    \ auto min_prime = auto_realloc([](const usize n) {\n        std::vector<usize>\
    \ ret(n);\n        std::iota(ret.begin(), ret.end(), (usize)0);\n        std::vector<usize>\
    \ list;\n        for (const usize i : rep(2, n)) {\n            if (ret[i] ==\
    \ i) list.push_back(i);\n            for (const usize p : list) {\n          \
    \      if (p * i >= n || p > ret[i]) break;\n                ret[p * i] = p;\n\
    \            }\n        }\n        return ret;\n    });\n    static bool is_prime(const\
    \ usize n) {\n        if (n <= 1) return false;\n        return min_prime[n] ==\
    \ n;\n    }\n    template <class T> static std::vector<std::pair<T, usize>> factorize(T\
    \ x) {\n        assert(x > 0);\n        std::vector<std::pair<T, usize>> ret;\n\
    \        while (x != 1) {\n            const usize p = min_prime[x];\n       \
    \     ret.emplace_back((T)p, 0);\n            while (min_prime[x] == p) {\n  \
    \              ret.back().second++;\n                x /= p;\n            }\n\
    \        }\n        return ret;\n    }\n};\n"
  dependsOn:
  - utility/auto_realloc.cpp
  - bit/ceil_log2.cpp
  - utility/int_alias.cpp
  - utility/rep.cpp
  isVerificationFile: false
  path: math/prime_sieve.cpp
  requiredBy: []
  timestamp: '2021-09-08 18:46:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/prime_sieve.test.cpp
documentation_of: math/prime_sieve.cpp
layout: document
redirect_from:
- /library/math/prime_sieve.cpp
- /library/math/prime_sieve.cpp.html
title: math/prime_sieve.cpp
---