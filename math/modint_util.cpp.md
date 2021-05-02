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
    path: test/modint_util.test.cpp
    title: test/modint_util.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n#include <cstddef>\n\
    \nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    using isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 3 \"utility/rep.cpp\"\
    \n#include <algorithm>\n\nclass rep {\n    struct Iter {\n        usize itr;\n\
    \        constexpr Iter(const usize pos) noexcept: itr(pos) { }\n        constexpr\
    \ void operator ++ () noexcept { ++itr; }\n        constexpr bool operator !=\
    \ (const Iter& other) const noexcept { return itr != other.itr; }\n        constexpr\
    \ usize operator * () const noexcept { return itr; }\n    };\n    const Iter first,\
    \ last;\npublic:\n    explicit constexpr rep(const usize first, const usize last)\
    \ noexcept: first(first), last(std::max(first, last)) { }\n    constexpr Iter\
    \ begin() const noexcept { return first; }\n    constexpr Iter end() const noexcept\
    \ { return last; }\n};\n#line 3 \"bit/ceil_log2.cpp\"\n\nconstexpr u64 ceil_log2(const\
    \ u64 x) {\n    u64 e = 0;\n    while (((u64) 1 << e) < x) ++e;\n    return e;\n\
    }\n#line 4 \"utility/auto_realloc.cpp\"\n#include <utility>\n#include <vector>\n\
    \ntemplate <class F>\nclass AutoRealloc {\n    using R = typename decltype(std::declval<F>()((usize)\
    \ 0))::value_type;\n    \n    F func;\n    mutable std::vector<R> data;\n\npublic:\n\
    \    template <class G>\n    explicit AutoRealloc(G&& g): func(std::forward<G>(g)),\
    \ data() { }\n    \n    void reserve(const usize size) const {\n        if (data.size()\
    \ < size) data = func(((usize) 1 << ceil_log2(size)));\n    }\n    R operator\
    \ [] (const usize i) const {\n        reserve(i + 1);\n        return data[i];\n\
    \    }\n};\n\ntemplate <class G>\nexplicit AutoRealloc(G&&) -> AutoRealloc<std::decay_t<G>>;\n\
    #line 6 \"math/modint_util.cpp\"\n#include <cassert>\n\ntemplate <class M>\nstruct\
    \ ModintUtil {\n    static inline const auto fact = AutoRealloc([](const usize\
    \ n) {\n        std::vector<M> ret(n);\n        ret[0] = M(1);\n        for (const\
    \ usize i: rep(1, n)) {\n            ret[i] = ret[i - 1] * M(i);\n        }\n\
    \        return ret;\n    });\n    static inline const auto inv = AutoRealloc([](const\
    \ usize n) {\n        std::vector<M> ret(n);\n        if (n == 1) return ret;\n\
    \        ret[1] = M(1);\n        for (const usize i: rep(2, n)) {\n          \
    \  ret[i] = -M(M::mod() / i) * ret[M::mod() % i];\n        }\n        return ret;\n\
    \    });\n    static inline const auto inv_fact = AutoRealloc([](const usize n)\
    \ {\n        std::vector<M> ret(n);\n        ret[0] = M(1);\n        for (const\
    \ usize i: rep(1, n)) {\n            ret[i] = ret[i - 1] * inv[i];\n        }\n\
    \        return ret;\n    });\n    static M binom(const usize n, const usize k)\
    \ {\n        assert(k <= n);\n        return fact[n] * inv_fact[n - k] * inv_fact[k];\n\
    \    }\n    static M factpow(const usize n, const usize k) {\n        assert(k\
    \ <= n);\n        return fact[n] * inv_fact[n - k];\n    }\n    static M homo(const\
    \ usize n, const usize k) {\n        if (n == 0 and k == 0) return M(1);\n   \
    \     return binom(n + k - 1, k);\n    }\n};\n"
  code: "#pragma once\n#include \"../utility/int_alias.cpp\"\n#include \"../utility/rep.cpp\"\
    \n#include \"../utility/auto_realloc.cpp\"\n#include <vector>\n#include <cassert>\n\
    \ntemplate <class M>\nstruct ModintUtil {\n    static inline const auto fact =\
    \ AutoRealloc([](const usize n) {\n        std::vector<M> ret(n);\n        ret[0]\
    \ = M(1);\n        for (const usize i: rep(1, n)) {\n            ret[i] = ret[i\
    \ - 1] * M(i);\n        }\n        return ret;\n    });\n    static inline const\
    \ auto inv = AutoRealloc([](const usize n) {\n        std::vector<M> ret(n);\n\
    \        if (n == 1) return ret;\n        ret[1] = M(1);\n        for (const usize\
    \ i: rep(2, n)) {\n            ret[i] = -M(M::mod() / i) * ret[M::mod() % i];\n\
    \        }\n        return ret;\n    });\n    static inline const auto inv_fact\
    \ = AutoRealloc([](const usize n) {\n        std::vector<M> ret(n);\n        ret[0]\
    \ = M(1);\n        for (const usize i: rep(1, n)) {\n            ret[i] = ret[i\
    \ - 1] * inv[i];\n        }\n        return ret;\n    });\n    static M binom(const\
    \ usize n, const usize k) {\n        assert(k <= n);\n        return fact[n] *\
    \ inv_fact[n - k] * inv_fact[k];\n    }\n    static M factpow(const usize n, const\
    \ usize k) {\n        assert(k <= n);\n        return fact[n] * inv_fact[n - k];\n\
    \    }\n    static M homo(const usize n, const usize k) {\n        if (n == 0\
    \ and k == 0) return M(1);\n        return binom(n + k - 1, k);\n    }\n};\n"
  dependsOn:
  - utility/int_alias.cpp
  - utility/rep.cpp
  - utility/auto_realloc.cpp
  - bit/ceil_log2.cpp
  isVerificationFile: false
  path: math/modint_util.cpp
  requiredBy: []
  timestamp: '2021-05-02 18:39:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/modint_util.test.cpp
documentation_of: math/modint_util.cpp
layout: document
redirect_from:
- /library/math/modint_util.cpp
- /library/math/modint_util.cpp.html
title: math/modint_util.cpp
---
