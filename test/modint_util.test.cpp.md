---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: bit/ceil_log2.cpp
    title: bit/ceil_log2.cpp
  - icon: ':heavy_check_mark:'
    path: math/modint_util.cpp
    title: math/modint_util.cpp
  - icon: ':heavy_check_mark:'
    path: math/rem_euclid.cpp
    title: math/rem_euclid.cpp
  - icon: ':heavy_check_mark:'
    path: math/static_modint.cpp
    title: math/static_modint.cpp
  - icon: ':heavy_check_mark:'
    path: math/totient.cpp
    title: math/totient.cpp
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
    PROBLEM: https://yukicoder.me/problems/no/117
    links:
    - https://yukicoder.me/problems/no/117
  bundledCode: "#line 1 \"test/modint_util.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/117\"\
    \n#line 2 \"math/static_modint.cpp\"\n#include <ostream>\n#include <type_traits>\n\
    #line 2 \"utility/int_alias.cpp\"\n#include <cstddef>\n#include <cstdint>\n\n\
    using i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing isize = std::ptrdiff_t;\nusing usize = std::size_t;\n\
    #line 2 \"math/rem_euclid.cpp\"\n#include <cassert>\n\ntemplate <class T> constexpr\
    \ T rem_euclid(T value, const T& mod) {\n    assert(mod > 0);\n    return (value\
    \ %= mod) >= 0 ? value : value + mod;\n}\n#line 2 \"math/totient.cpp\"\n\ntemplate\
    \ <class T> constexpr T totient(T x) {\n    T ret = x;\n    for (T i = 2; i *\
    \ i <= x; ++i) {\n        if (x % i == 0) {\n            ret /= i;\n         \
    \   ret *= i - 1;\n            while (x % i == 0) x /= i;\n        }\n    }\n\
    \    if (x > 1) {\n        ret /= x;\n        ret *= x - 1;\n    }\n    return\
    \ ret;\n}\n#line 7 \"math/static_modint.cpp\"\n\ntemplate <u32 MOD, std::enable_if_t<((u32)1\
    \ <= MOD and MOD <= ((u32)1 << 31))>* = nullptr> class StaticModint {\n    using\
    \ Self = StaticModint;\n\n    static inline constexpr u32 PHI = totient(MOD);\n\
    \    u32 v;\n\n  public:\n    static constexpr u32 mod() noexcept { return MOD;\
    \ }\n\n    template <class T, std::enable_if_t<std::is_integral_v<T>>* = nullptr>\n\
    \    static constexpr T normalize(const T& x) noexcept {\n        return rem_euclid<std::common_type_t<T,\
    \ i64>>(x, MOD);\n    }\n\n    constexpr StaticModint() noexcept : v(0) {}\n \
    \   template <class T> constexpr StaticModint(const T& x) noexcept : v(normalize(x))\
    \ {}\n    template <class T> static constexpr Self raw(const T& x) noexcept {\n\
    \        Self ret;\n        ret.v = x;\n        return ret;\n    }\n\n    constexpr\
    \ u32 val() const noexcept { return v; }\n    constexpr Self neg() const noexcept\
    \ { return raw(v == 0 ? 0 : MOD - v); }\n    constexpr Self inv() const noexcept\
    \ { return pow(PHI - 1); }\n    constexpr Self pow(u64 exp) const noexcept {\n\
    \        Self ret(1), mult(*this);\n        for (; exp > 0; exp >>= 1) {\n   \
    \         if (exp & 1) ret *= mult;\n            mult *= mult;\n        }\n  \
    \      return ret;\n    }\n\n    constexpr Self operator-() const noexcept { return\
    \ neg(); }\n    constexpr Self operator~() const noexcept { return inv(); }\n\n\
    \    constexpr Self operator+(const Self& rhs) const noexcept { return Self(*this)\
    \ += rhs; }\n    constexpr Self& operator+=(const Self& rhs) noexcept {\n    \
    \    if ((v += rhs.v) >= MOD) v -= MOD;\n        return *this;\n    }\n\n    constexpr\
    \ Self operator-(const Self& rhs) const noexcept { return Self(*this) -= rhs;\
    \ }\n    constexpr Self& operator-=(const Self& rhs) noexcept {\n        if (v\
    \ < rhs.v) v += MOD;\n        v -= rhs.v;\n        return *this;\n    }\n\n  \
    \  constexpr Self operator*(const Self& rhs) const noexcept { return Self(*this)\
    \ *= rhs; }\n    constexpr Self& operator*=(const Self& rhs) noexcept {\n    \
    \    v = (u64)v * rhs.v % MOD;\n        return *this;\n    }\n\n    constexpr\
    \ Self operator/(const Self& rhs) const noexcept { return Self(*this) /= rhs;\
    \ }\n    constexpr Self& operator/=(const Self& rhs) noexcept { return *this *=\
    \ rhs.inv(); }\n\n    constexpr bool operator==(const Self& rhs) const noexcept\
    \ { return v == rhs.v; }\n    constexpr bool operator!=(const Self& rhs) const\
    \ noexcept { return v != rhs.v; }\n    friend std::ostream& operator<<(std::ostream&\
    \ stream, const Self& rhs) { return stream << rhs.v; }\n};\n\nusing Modint1000000007\
    \ = StaticModint<1000000007>;\nusing Modint998244353 = StaticModint<998244353>;\n\
    #line 3 \"math/modint_util.cpp\"\n#include <vector>\n#line 2 \"utility/auto_realloc.cpp\"\
    \n#include <utility>\n#line 3 \"bit/ceil_log2.cpp\"\n\n__attribute__((target(\"\
    avx2\"))) constexpr u64 ceil_log2(const u64 x) {\n    u64 e = 0;\n    while (((u64)1\
    \ << e) < x) ++e;\n    return e;\n}\n#line 6 \"utility/auto_realloc.cpp\"\n\n\
    template <class F> class AutoReallocation {\n    using R = typename decltype(std::declval<F>()((usize)0))::value_type;\n\
    \n    F func;\n    mutable std::vector<R> data;\n\n  public:\n    explicit AutoReallocation(F&&\
    \ f) : func(std::forward<F>(f)), data() {}\n\n    void reserve(const usize size)\
    \ const {\n        if (data.size() < size) data = func(((usize)1 << ceil_log2(size)));\n\
    \    }\n    R operator[](const usize i) const {\n        reserve(i + 1);\n   \
    \     return data[i];\n    }\n};\n\ntemplate <class F> decltype(auto) auto_realloc(F&&\
    \ f) { return AutoReallocation<F>(std::forward<F>(f)); }\n#line 2 \"utility/rep.cpp\"\
    \n#include <algorithm>\n#line 4 \"utility/rep.cpp\"\n\nclass rep {\n    struct\
    \ Iter {\n        usize itr;\n        constexpr Iter(const usize pos) noexcept\
    \ : itr(pos) {}\n        constexpr void operator++() noexcept { ++itr; }\n   \
    \     constexpr bool operator!=(const Iter& other) const noexcept { return itr\
    \ != other.itr; }\n        constexpr usize operator*() const noexcept { return\
    \ itr; }\n    };\n    const Iter first, last;\n\n  public:\n    explicit constexpr\
    \ rep(const usize first, const usize last) noexcept : first(first), last(std::max(first,\
    \ last)) {}\n    constexpr Iter begin() const noexcept { return first; }\n   \
    \ constexpr Iter end() const noexcept { return last; }\n};\n#line 7 \"math/modint_util.cpp\"\
    \n\ntemplate <class M> struct ModintUtil {\n    static inline const auto fact\
    \ = auto_realloc([](const usize n) {\n        std::vector<M> ret(n);\n       \
    \ ret[0] = M(1);\n        for (const usize i : rep(1, n)) {\n            ret[i]\
    \ = ret[i - 1] * M(i);\n        }\n        return ret;\n    });\n    static inline\
    \ const auto inv = auto_realloc([](const usize n) {\n        std::vector<M> ret(n);\n\
    \        if (n == 1) return ret;\n        ret[1] = M(1);\n        for (const usize\
    \ i : rep(2, n)) {\n            ret[i] = -M(M::mod() / i) * ret[M::mod() % i];\n\
    \        }\n        return ret;\n    });\n    static inline const auto inv_fact\
    \ = auto_realloc([](const usize n) {\n        std::vector<M> ret(n);\n       \
    \ ret[0] = M(1);\n        for (const usize i : rep(1, n)) {\n            ret[i]\
    \ = ret[i - 1] * inv[i];\n        }\n        return ret;\n    });\n    static\
    \ M binom(const usize n, const usize k) {\n        assert(k <= n);\n        return\
    \ fact[n] * inv_fact[n - k] * inv_fact[k];\n    }\n    static M factpow(const\
    \ usize n, const usize k) {\n        assert(k <= n);\n        return fact[n] *\
    \ inv_fact[n - k];\n    }\n    static M homo(const usize n, const usize k) {\n\
    \        if (n == 0 and k == 0) return M(1);\n        return binom(n + k - 1,\
    \ k);\n    }\n};\n#line 5 \"test/modint_util.test.cpp\"\n#include <iostream>\n\
    \nusing Fp = StaticModint<1000000007>;\nusing FpUtil = ModintUtil<Fp>;\n\nint\
    \ main() {\n    usize T;\n    std::cin >> T;\n    while (T--) {\n        char\
    \ type, dust;\n        usize N, K;\n        std::cin >> type >> dust >> N >> dust\
    \ >> K >> dust;\n        if (type == 'C') {\n            if (N < K) std::cout\
    \ << 0 << '\\n';\n            else std::cout << FpUtil::binom(N, K) << '\\n';\n\
    \        }\n        if (type == 'P') {\n            if (N < K) std::cout << 0\
    \ << '\\n';\n            else std::cout << FpUtil::factpow(N, K) << '\\n';\n \
    \       }\n        if (type == 'H') {\n            if (N == 0 && K > 0) std::cout\
    \ << 0 << '\\n';\n            else std::cout << FpUtil::homo(N, K) << '\\n';\n\
    \        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/117\"\n#include \"../math/static_modint.cpp\"\
    \n#include \"../math/modint_util.cpp\"\n#include \"../utility/int_alias.cpp\"\n\
    #include <iostream>\n\nusing Fp = StaticModint<1000000007>;\nusing FpUtil = ModintUtil<Fp>;\n\
    \nint main() {\n    usize T;\n    std::cin >> T;\n    while (T--) {\n        char\
    \ type, dust;\n        usize N, K;\n        std::cin >> type >> dust >> N >> dust\
    \ >> K >> dust;\n        if (type == 'C') {\n            if (N < K) std::cout\
    \ << 0 << '\\n';\n            else std::cout << FpUtil::binom(N, K) << '\\n';\n\
    \        }\n        if (type == 'P') {\n            if (N < K) std::cout << 0\
    \ << '\\n';\n            else std::cout << FpUtil::factpow(N, K) << '\\n';\n \
    \       }\n        if (type == 'H') {\n            if (N == 0 && K > 0) std::cout\
    \ << 0 << '\\n';\n            else std::cout << FpUtil::homo(N, K) << '\\n';\n\
    \        }\n    }\n    return 0;\n}"
  dependsOn:
  - math/static_modint.cpp
  - utility/int_alias.cpp
  - math/rem_euclid.cpp
  - math/totient.cpp
  - math/modint_util.cpp
  - utility/auto_realloc.cpp
  - bit/ceil_log2.cpp
  - utility/rep.cpp
  isVerificationFile: true
  path: test/modint_util.test.cpp
  requiredBy: []
  timestamp: '2021-11-10 20:31:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/modint_util.test.cpp
layout: document
redirect_from:
- /verify/test/modint_util.test.cpp
- /verify/test/modint_util.test.cpp.html
title: test/modint_util.test.cpp
---
