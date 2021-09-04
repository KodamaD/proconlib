---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/rem_euclid.cpp
    title: math/rem_euclid.cpp
  - icon: ':x:'
    path: math/semiring_matrix.cpp
    title: math/semiring_matrix.cpp
  - icon: ':question:'
    path: math/static_modint.cpp
    title: math/static_modint.cpp
  - icon: ':question:'
    path: math/totient.cpp
    title: math/totient.cpp
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':x:'
    path: utility/num_semiring.cpp
    title: utility/num_semiring.cpp
  - icon: ':question:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_product
    links:
    - https://judge.yosupo.jp/problem/matrix_product
  bundledCode: "#line 1 \"test/semiring_matrix.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\
    \n#line 2 \"math/static_modint.cpp\"\n#include <ostream>\n#include <type_traits>\n\
    #line 2 \"math/totient.cpp\"\n\ntemplate <class T> constexpr T totient(T x) {\n\
    \    T ret = x;\n    for (T i = 2; i * i <= x; ++i) {\n        if (x % i == 0)\
    \ {\n            ret /= i;\n            ret *= i - 1;\n            while (x %\
    \ i == 0) x /= i;\n        }\n    }\n    if (x > 1) {\n        ret /= x;\n   \
    \     ret *= x - 1;\n    }\n    return ret;\n}\n#line 2 \"utility/int_alias.cpp\"\
    \n#include <cstddef>\n#include <cstdint>\n\nusing i32 = std::int32_t;\nusing u32\
    \ = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing\
    \ i128 = __int128_t;\nusing u128 = __uint128_t;\nusing isize = std::ptrdiff_t;\n\
    using usize = std::size_t;\n#line 2 \"math/rem_euclid.cpp\"\n\ntemplate <class\
    \ T> constexpr T rem_euclid(T value, const T& mod) { return (value %= mod) >=\
    \ 0 ? value : value + mod; }\n#line 7 \"math/static_modint.cpp\"\n\ntemplate <u32\
    \ MOD, std::enable_if_t<((u32)1 <= MOD and MOD <= ((u32)1 << 31))>* = nullptr>\
    \ class StaticModint {\n    using Mint = StaticModint;\n\n    static inline constexpr\
    \ u32 PHI = totient(MOD);\n    u32 v;\n\n  public:\n    static constexpr u32 mod()\
    \ noexcept { return MOD; }\n\n    template <class T, std::enable_if_t<std::is_signed_v<T>\
    \ and std::is_integral_v<T>>* = nullptr>\n    static constexpr T normalize(const\
    \ T x) noexcept {\n        return rem_euclid<std::common_type_t<T, i64>>(x, MOD);\n\
    \    }\n    template <class T, std::enable_if_t<std::is_unsigned_v<T> and std::is_integral_v<T>>*\
    \ = nullptr>\n    static constexpr T normalize(const T x) noexcept {\n       \
    \ return x % MOD;\n    }\n\n    constexpr StaticModint() noexcept : v(0) {}\n\
    \    template <class T> constexpr StaticModint(const T x) noexcept : v(normalize(x))\
    \ {}\n    template <class T> static constexpr Mint raw(const T x) noexcept {\n\
    \        Mint ret;\n        ret.v = x;\n        return ret;\n    }\n\n    constexpr\
    \ u32 get() const noexcept { return v; }\n    constexpr Mint neg() const noexcept\
    \ { return raw(v == 0 ? 0 : MOD - v); }\n    constexpr Mint inv() const noexcept\
    \ { return pow(PHI - 1); }\n    constexpr Mint pow(u64 exp) const noexcept {\n\
    \        Mint ret(1), mult(*this);\n        for (; exp > 0; exp >>= 1) {\n   \
    \         if (exp & 1) ret *= mult;\n            mult *= mult;\n        }\n  \
    \      return ret;\n    }\n\n    constexpr Mint operator-() const noexcept { return\
    \ neg(); }\n    constexpr Mint operator~() const noexcept { return inv(); }\n\n\
    \    constexpr Mint operator+(const Mint& rhs) const noexcept { return Mint(*this)\
    \ += rhs; }\n    constexpr Mint& operator+=(const Mint& rhs) noexcept {\n    \
    \    if ((v += rhs.v) >= MOD) v -= MOD;\n        return *this;\n    }\n\n    constexpr\
    \ Mint operator-(const Mint& rhs) const noexcept { return Mint(*this) -= rhs;\
    \ }\n    constexpr Mint& operator-=(const Mint& rhs) noexcept {\n        if (v\
    \ < rhs.v) v += MOD;\n        v -= rhs.v;\n        return *this;\n    }\n\n  \
    \  constexpr Mint operator*(const Mint& rhs) const noexcept { return Mint(*this)\
    \ *= rhs; }\n    constexpr Mint& operator*=(const Mint& rhs) noexcept {\n    \
    \    v = (u64)v * rhs.v % MOD;\n        return *this;\n    }\n\n    constexpr\
    \ Mint operator/(const Mint& rhs) const noexcept { return Mint(*this) /= rhs;\
    \ }\n    constexpr Mint& operator/=(const Mint& rhs) noexcept { return *this *=\
    \ rhs.inv(); }\n\n    constexpr bool operator==(const Mint& rhs) const noexcept\
    \ { return v == rhs.v; }\n    constexpr bool operator!=(const Mint& rhs) const\
    \ noexcept { return v != rhs.v; }\n    friend std::ostream& operator<<(std::ostream&\
    \ stream, const Mint& rhs) { return stream << rhs.v; }\n};\n\nusing Modint1000000007\
    \ = StaticModint<1000000007>;\nusing Modint998244353 = StaticModint<998244353>;\n\
    #line 2 \"math/semiring_matrix.cpp\"\n#include <array>\n#include <cassert>\n#include\
    \ <initializer_list>\n#include <vector>\n#line 2 \"utility/rep.cpp\"\n#include\
    \ <algorithm>\n#line 4 \"utility/rep.cpp\"\n\nclass rep {\n    struct Iter {\n\
    \        usize itr;\n        constexpr Iter(const usize pos) noexcept : itr(pos)\
    \ {}\n        constexpr void operator++() noexcept { ++itr; }\n        constexpr\
    \ bool operator!=(const Iter& other) const noexcept { return itr != other.itr;\
    \ }\n        constexpr usize operator*() const noexcept { return itr; }\n    };\n\
    \    const Iter first, last;\n\n  public:\n    explicit constexpr rep(const usize\
    \ first, const usize last) noexcept : first(first), last(std::max(first, last))\
    \ {}\n    constexpr Iter begin() const noexcept { return first; }\n    constexpr\
    \ Iter end() const noexcept { return last; }\n};\n#line 8 \"math/semiring_matrix.cpp\"\
    \n\ntemplate <class SemiRing> class SemiRingMatrix {\n    using Self = SemiRingMatrix;\n\
    \    std::vector<std::vector<SemiRing>> data;\n\n  public:\n    SemiRingMatrix()\
    \ = default;\n    explicit SemiRingMatrix(const usize h, const usize w, const\
    \ SemiRing& val = SemiRing::zero())\n        : data(h, std::vector<SemiRing>(w,\
    \ val)) {}\n\n    SemiRingMatrix(const std::vector<std::vector<SemiRing>>& vec)\
    \ : data(vec) {}\n    SemiRingMatrix(const std::initializer_list<std::initializer_list<SemiRing>>&\
    \ list) {\n        data.reserve(list.size());\n        for (const auto& v : list)\
    \ {\n            data.emplace_back(v.begin(), v.end());\n        }\n    }\n  \
    \  template <usize H, usize W> SemiRingMatrix(const std::array<std::array<SemiRing,\
    \ W>, H>& arr) {\n        data.reserve(H);\n        for (const auto& v : arr)\
    \ {\n            data.emplace_back(v.begin(), v.end());\n        }\n    }\n\n\
    \    usize height() const { return data.size(); }\n    usize width() const { return\
    \ data.empty() ? 0 : data[0].size(); }\n\n    SemiRing& operator()(const usize\
    \ i, const usize j) {\n        assert(i < height());\n        assert(j < width());\n\
    \        return data[i][j];\n    }\n    const SemiRing& operator()(const usize\
    \ i, const usize j) const {\n        assert(i < height());\n        assert(j <\
    \ width());\n        return data[i][j];\n    }\n\n    Self operator+(const Self&\
    \ other) const { return Self(*this) += other; }\n    Self& operator+=(const Self&\
    \ other) {\n        assert(height() == other.height());\n        assert(width()\
    \ == other.width());\n        for (const usize i : rep(0, height())) {\n     \
    \       for (const usize j : rep(0, width())) {\n                data[i][j] =\
    \ data[i][j] + other.data[i][j];\n            }\n        }\n        return *this;\n\
    \    }\n\n    Self operator*(const Self& other) const {\n        assert(width()\
    \ == other.height());\n        Self ret(height(), other.width(), SemiRing::zero());\n\
    \        for (const usize i : rep(0, height())) {\n            for (const usize\
    \ k : rep(0, width())) {\n                for (const usize j : rep(0, other.width()))\
    \ {\n                    ret.data[i][j] = ret.data[i][j] + data[i][k] * other.data[k][j];\n\
    \                }\n            }\n        }\n        return ret;\n    }\n\n \
    \   Self operator*(const SemiRing& other) const { return Self(*this) *= other;\
    \ }\n    Self& operator*=(const SemiRing& other) {\n        for (const usize i\
    \ : rep(0, height())) {\n            for (const usize j : rep(0, width())) {\n\
    \                data[i][j] = data[i][j] * other;\n            }\n        }\n\
    \    }\n\n    Self pow(u64 exp) const {\n        assert(height() == width());\n\
    \        Self ret(height(), width(), SemiRing::zero()), mult(*this);\n       \
    \ for (const usize i : rep(0, height())) {\n            ret.data[i][i] = SemiRing::one();\n\
    \        }\n        for (; exp > 0; exp >>= 1) {\n            if (exp & 1) ret\
    \ = ret * mult;\n            mult = mult * mult;\n        }\n        return ret;\n\
    \    }\n};\n#line 2 \"utility/num_semiring.cpp\"\n\ntemplate <class T> struct\
    \ NumSemiRing {\n    T val;\n    constexpr NumSemiRing() = default;\n    constexpr\
    \ NumSemiRing(const T& val) : val(val) {}\n    static constexpr NumSemiRing zero()\
    \ { return T(0); }\n    static constexpr NumSemiRing one() { return T(1); }\n\
    \    constexpr NumSemiRing operator+(const NumSemiRing& other) const { return\
    \ val + other.val; }\n    constexpr NumSemiRing operator*(const NumSemiRing& other)\
    \ const { return val * other.val; }\n};\n#line 7 \"test/semiring_matrix.test.cpp\"\
    \n#include <iostream>\n#line 9 \"test/semiring_matrix.test.cpp\"\n\nusing Fp =\
    \ Modint998244353;\nusing Num = NumSemiRing<Fp>;\nusing Matrix = SemiRingMatrix<Num>;\n\
    \nint main() {\n    usize N, M, K;\n    std::cin >> N >> M >> K;\n    std::vector<std::vector<Num>>\
    \ A(N, std::vector<Num>(M));\n    std::vector<std::vector<Num>> B(M, std::vector<Num>(K));\n\
    \    for (auto& v: A) {\n        for (auto& x: v) {\n            u32 t;\n    \
    \        std::cin >> t;\n            x.val = Fp(t);\n        }\n    }\n    for\
    \ (auto& v: B) {\n        for (auto& x: v) {\n            u32 t;\n           \
    \ std::cin >> t;\n            x.val = Fp(t);\n        }\n    }\n    const auto\
    \ C = Matrix(A) * Matrix(B);\n    for (const auto i: rep(0, N)) {\n        for\
    \ (const auto j: rep(0, K)) {\n            std::cout << C(i, j).val << \" \\n\"\
    [j + 1 == K];\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n#include\
    \ \"../math/static_modint.cpp\"\n#include \"../math/semiring_matrix.cpp\"\n#include\
    \ \"../utility/int_alias.cpp\"\n#include \"../utility/rep.cpp\"\n#include \"../utility/num_semiring.cpp\"\
    \n#include <iostream>\n#include <vector>\n\nusing Fp = Modint998244353;\nusing\
    \ Num = NumSemiRing<Fp>;\nusing Matrix = SemiRingMatrix<Num>;\n\nint main() {\n\
    \    usize N, M, K;\n    std::cin >> N >> M >> K;\n    std::vector<std::vector<Num>>\
    \ A(N, std::vector<Num>(M));\n    std::vector<std::vector<Num>> B(M, std::vector<Num>(K));\n\
    \    for (auto& v: A) {\n        for (auto& x: v) {\n            u32 t;\n    \
    \        std::cin >> t;\n            x.val = Fp(t);\n        }\n    }\n    for\
    \ (auto& v: B) {\n        for (auto& x: v) {\n            u32 t;\n           \
    \ std::cin >> t;\n            x.val = Fp(t);\n        }\n    }\n    const auto\
    \ C = Matrix(A) * Matrix(B);\n    for (const auto i: rep(0, N)) {\n        for\
    \ (const auto j: rep(0, K)) {\n            std::cout << C(i, j).val << \" \\n\"\
    [j + 1 == K];\n        }\n    }\n}"
  dependsOn:
  - math/static_modint.cpp
  - math/totient.cpp
  - utility/int_alias.cpp
  - math/rem_euclid.cpp
  - math/semiring_matrix.cpp
  - utility/rep.cpp
  - utility/num_semiring.cpp
  isVerificationFile: true
  path: test/semiring_matrix.test.cpp
  requiredBy: []
  timestamp: '2021-09-04 17:30:23+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/semiring_matrix.test.cpp
layout: document
redirect_from:
- /verify/test/semiring_matrix.test.cpp
- /verify/test/semiring_matrix.test.cpp.html
title: test/semiring_matrix.test.cpp
---
