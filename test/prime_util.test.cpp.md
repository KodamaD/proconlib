---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bit/ceil_log2.cpp
    title: bit/ceil_log2.cpp
  - icon: ':heavy_check_mark:'
    path: math/prime_util.cpp
    title: math/prime_util.cpp
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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/843
    links:
    - https://yukicoder.me/problems/no/843
  bundledCode: "#line 1 \"test/prime_util.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/843\"\
    \n#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n#include <cstddef>\n\n\
    using i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
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
    \ntemplate <class F>\nclass AutoRealloc {\n    using R = typename decltype(std::declval<F>().operator()(std::declval<usize>()))::value_type;\n\
    \    F func;\n    std::vector<R> data;\npublic:\n    explicit AutoRealloc(F&&\
    \ func): func(std::forward<F>(func)), data() { }\n    explicit AutoRealloc(F&&\
    \ func, const usize capacity): func(std::forward<F>(func)) { reserve(capacity);\
    \ }\n    void reserve(const usize size) {\n        if (data.size() < size) {\n\
    \            const usize pow2 = ((usize) 1 << ceil_log2(size));\n            data\
    \ = func(pow2);\n        }\n    }\n    R operator [] (const usize i) {\n     \
    \   reserve(i + 1);\n        return data[i];\n    }\n};\n#line 7 \"math/prime_util.cpp\"\
    \n#include <numeric>\n#include <cassert>\n\nstruct PrimeUtil {\n    static inline\
    \ auto min_prime = AutoRealloc([](const usize n) {\n        std::vector<usize>\
    \ ret(n);\n        std::iota(ret.begin(), ret.end(), (usize) 0);\n        std::vector<usize>\
    \ list;\n        for (const usize i: rep(2, n)) {\n            if (ret[i] == i)\
    \ list.push_back(i);\n            for (const usize p: list) {\n              \
    \  if (p * i >= n || p > ret[i]) break;\n                ret[p * i] = p;\n   \
    \         }\n        }\n        return ret;\n    });\n    static bool is_prime(const\
    \ usize n) {\n        if (n <= 1) return false;\n        return min_prime[n] ==\
    \ n;\n    }\n    template <class T>\n    static std::vector<std::pair<T, usize>>\
    \ factorize(T x) {\n        assert(x > 0);\n        std::vector<std::pair<T, usize>>\
    \ ret;\n        while (x != 1) {\n            const usize p = min_prime[x];\n\
    \            ret.emplace_back((T) p, 0);\n            while (min_prime[x] == p)\
    \ {\n                ret.back().second++;\n                x /= p;\n         \
    \   }\n        }\n        return ret;\n    }\n};\n#line 5 \"test/prime_util.test.cpp\"\
    \n#include <iostream>\n\nint main() {\n    u32 N;\n    std::cin >> N;\n    if\
    \ (N == 1) {\n        std::cout << 0 << '\\n';\n        return 0;\n    }\n   \
    \ u32 ans = 1;\n    for (const u32 r: rep(3, N + 1)) {\n        if (r * r - 2\
    \ > N) break;\n        if (PrimeUtil::is_prime(r) && PrimeUtil::is_prime(r * r\
    \ - 2)) {\n            ans += 2;\n        }\n    }\n    std::cout << ans << '\\\
    n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/843\"\n#include \"../math/prime_util.cpp\"\
    \n#include \"../utility/int_alias.cpp\"\n#include \"../utility/rep.cpp\"\n#include\
    \ <iostream>\n\nint main() {\n    u32 N;\n    std::cin >> N;\n    if (N == 1)\
    \ {\n        std::cout << 0 << '\\n';\n        return 0;\n    }\n    u32 ans =\
    \ 1;\n    for (const u32 r: rep(3, N + 1)) {\n        if (r * r - 2 > N) break;\n\
    \        if (PrimeUtil::is_prime(r) && PrimeUtil::is_prime(r * r - 2)) {\n   \
    \         ans += 2;\n        }\n    }\n    std::cout << ans << '\\n';\n    return\
    \ 0;\n}"
  dependsOn:
  - math/prime_util.cpp
  - utility/int_alias.cpp
  - utility/rep.cpp
  - utility/auto_realloc.cpp
  - bit/ceil_log2.cpp
  isVerificationFile: true
  path: test/prime_util.test.cpp
  requiredBy: []
  timestamp: '2021-03-26 16:54:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/prime_util.test.cpp
layout: document
redirect_from:
- /verify/test/prime_util.test.cpp
- /verify/test/prime_util.test.cpp.html
title: test/prime_util.test.cpp
---
