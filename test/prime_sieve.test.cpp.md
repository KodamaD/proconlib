---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/prime_sieve.cpp
    title: math/prime_sieve.cpp
  - icon: ':heavy_check_mark:'
    path: utility/auto_realloc.cpp
    title: utility/auto_realloc.cpp
  - icon: ':heavy_check_mark:'
    path: utility/ceil_log2.cpp
    title: utility/ceil_log2.cpp
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':question:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/843
    links:
    - https://yukicoder.me/problems/no/843
  bundledCode: "#line 1 \"test/prime_sieve.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/843\"\
    \n#line 2 \"math/prime_sieve.cpp\"\n#include <cassert>\n#include <numeric>\n#include\
    \ <utility>\n#include <vector>\n#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n\
    \nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    #line 3 \"utility/ceil_log2.cpp\"\n\nconstexpr int ceil_log2(const u64 x) {\n\
    \    int e = 0;\n    while (((u64)1 << e) < x) ++e;\n    return e;\n}\n#line 6\
    \ \"utility/auto_realloc.cpp\"\n\ntemplate <class F> class AutoReallocation {\n\
    \    using R = typename decltype(std::declval<F>()(0))::value_type;\n\n    F func;\n\
    \    mutable std::vector<R> data;\n\n  public:\n    explicit AutoReallocation(F&&\
    \ f) : func(std::forward<F>(f)), data() {}\n\n    void reserve(const int size)\
    \ const {\n        if ((int)data.size() < size) data = func(((int)1 << ceil_log2(size)));\n\
    \    }\n    R operator[](const int i) const {\n        assert(i >= 0);\n     \
    \   reserve(i + 1);\n        return data[i];\n    }\n};\n\ntemplate <class F>\
    \ decltype(auto) auto_realloc(F&& f) { return AutoReallocation<F>(std::forward<F>(f));\
    \ }\n#line 2 \"utility/rep.cpp\"\n#include <algorithm>\n\nclass Range {\n    struct\
    \ Iter {\n        int itr;\n        constexpr Iter(const int pos) noexcept : itr(pos)\
    \ {}\n        constexpr void operator++() noexcept { ++itr; }\n        constexpr\
    \ bool operator!=(const Iter& other) const noexcept { return itr != other.itr;\
    \ }\n        constexpr int operator*() const noexcept { return itr; }\n    };\n\
    \    const Iter first, last;\n\n  public:\n    explicit constexpr Range(const\
    \ int first, const int last) noexcept : first(first), last(std::max(first, last))\
    \ {}\n    constexpr Iter begin() const noexcept { return first; }\n    constexpr\
    \ Iter end() const noexcept { return last; }\n};\n\nconstexpr Range rep(const\
    \ int l, const int r) noexcept { return Range(l, r); }\nconstexpr Range rep(const\
    \ int n) noexcept { return Range(0, n); }\n#line 8 \"math/prime_sieve.cpp\"\n\n\
    struct PrimeSieve {\n    static inline const auto min_prime = auto_realloc([](const\
    \ int n) {\n        std::vector<int> ret(n);\n        std::iota(ret.begin(), ret.end(),\
    \ (int)0);\n        std::vector<int> list;\n        for (const int i : rep(2,\
    \ n)) {\n            if (ret[i] == i) list.push_back(i);\n            for (const\
    \ int p : list) {\n                if (p * i >= n || p > ret[i]) break;\n    \
    \            ret[p * i] = p;\n            }\n        }\n        return ret;\n\
    \    });\n    static bool is_prime(const int n) {\n        if (n <= 1) return\
    \ false;\n        return min_prime[n] == n;\n    }\n    template <class T> static\
    \ std::vector<std::pair<T, int>> factorize(T x) {\n        assert(x > 0);\n  \
    \      std::vector<std::pair<T, int>> ret;\n        while (x != 1) {\n       \
    \     const int p = min_prime[x];\n            ret.emplace_back((T)p, 0);\n  \
    \          while (min_prime[x] == p) {\n                ret.back().second++;\n\
    \                x /= p;\n            }\n        }\n        return ret;\n    }\n\
    };\n#line 5 \"test/prime_sieve.test.cpp\"\n#include <iostream>\n\nint main() {\n\
    \    u32 N;\n    std::cin >> N;\n    if (N == 1) {\n        std::cout << 0 <<\
    \ '\\n';\n        return 0;\n    }\n    u32 ans = 1;\n    for (const u32 r: rep(3,\
    \ N + 1)) {\n        if (r * r - 2 > N) break;\n        if (PrimeSieve::is_prime(r)\
    \ && PrimeSieve::is_prime(r * r - 2)) {\n            ans += 2;\n        }\n  \
    \  }\n    std::cout << ans << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/843\"\n#include \"../math/prime_sieve.cpp\"\
    \n#include \"../utility/int_alias.cpp\"\n#include \"../utility/rep.cpp\"\n#include\
    \ <iostream>\n\nint main() {\n    u32 N;\n    std::cin >> N;\n    if (N == 1)\
    \ {\n        std::cout << 0 << '\\n';\n        return 0;\n    }\n    u32 ans =\
    \ 1;\n    for (const u32 r: rep(3, N + 1)) {\n        if (r * r - 2 > N) break;\n\
    \        if (PrimeSieve::is_prime(r) && PrimeSieve::is_prime(r * r - 2)) {\n \
    \           ans += 2;\n        }\n    }\n    std::cout << ans << '\\n';\n    return\
    \ 0;\n}"
  dependsOn:
  - math/prime_sieve.cpp
  - utility/auto_realloc.cpp
  - utility/ceil_log2.cpp
  - utility/int_alias.cpp
  - utility/rep.cpp
  isVerificationFile: true
  path: test/prime_sieve.test.cpp
  requiredBy: []
  timestamp: '2021-12-28 21:38:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/prime_sieve.test.cpp
layout: document
redirect_from:
- /verify/test/prime_sieve.test.cpp
- /verify/test/prime_sieve.test.cpp.html
title: test/prime_sieve.test.cpp
---
