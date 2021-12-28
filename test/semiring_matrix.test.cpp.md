---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/factorize_iter.cpp
    title: math/factorize_iter.cpp
  - icon: ':heavy_check_mark:'
    path: math/rem_euclid.cpp
    title: math/rem_euclid.cpp
  - icon: ':heavy_check_mark:'
    path: math/semiring_matrix.cpp
    title: math/semiring_matrix.cpp
  - icon: ':heavy_check_mark:'
    path: math/static_modint.cpp
    title: math/static_modint.cpp
  - icon: ':heavy_check_mark:'
    path: math/totient.cpp
    title: math/totient.cpp
  - icon: ':heavy_check_mark:'
    path: traits/num_semiring.cpp
    title: traits/num_semiring.cpp
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
    PROBLEM: https://judge.yosupo.jp/problem/matrix_product
    links:
    - https://judge.yosupo.jp/problem/matrix_product
  bundledCode: "#line 1 \"test/semiring_matrix.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\
    \n#include <iostream>\n#include <vector>\n#line 2 \"math/semiring_matrix.cpp\"\
    \n#include <array>\n#include <cassert>\n#include <initializer_list>\n#line 2 \"\
    utility/int_alias.cpp\"\n#include <cstdint>\n\nusing i32 = std::int32_t;\nusing\
    \ u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n#line 2 \"utility/rep.cpp\"\
    \n#include <algorithm>\n\nclass Range {\n    struct Iter {\n        int itr;\n\
    \        constexpr Iter(const int pos) noexcept : itr(pos) {}\n        constexpr\
    \ void operator++() noexcept { ++itr; }\n        constexpr bool operator!=(const\
    \ Iter& other) const noexcept { return itr != other.itr; }\n        constexpr\
    \ int operator*() const noexcept { return itr; }\n    };\n    const Iter first,\
    \ last;\n\n  public:\n    explicit constexpr Range(const int first, const int\
    \ last) noexcept : first(first), last(std::max(first, last)) {}\n    constexpr\
    \ Iter begin() const noexcept { return first; }\n    constexpr Iter end() const\
    \ noexcept { return last; }\n};\n\nconstexpr Range rep(const int l, const int\
    \ r) noexcept { return Range(l, r); }\nconstexpr Range rep(const int n) noexcept\
    \ { return Range(0, n); }\n#line 8 \"math/semiring_matrix.cpp\"\n\ntemplate <class\
    \ S> class SemiRingMatrix {\n    using T = typename S::Type;\n    using Self =\
    \ SemiRingMatrix;\n    std::vector<std::vector<T>> data;\n\n  public:\n    SemiRingMatrix()\
    \ = default;\n    explicit SemiRingMatrix(const int h, const int w, const T& val\
    \ = S::zero()) : data(h, std::vector<T>(w, val)) {}\n\n    SemiRingMatrix(const\
    \ std::vector<std::vector<T>>& vec) : data(vec) {\n        for (const auto& v\
    \ : data) assert(v.size() == width());\n    }\n    SemiRingMatrix(const std::initializer_list<std::initializer_list<T>>&\
    \ list) {\n        data.reserve(list.size());\n        for (const auto& v : list)\
    \ data.emplace_back(v.begin(), v.end());\n        for (const auto& v : data) assert(v.size()\
    \ == width());\n    }\n\n    int height() const { return data.size(); }\n    int\
    \ width() const { return data.empty() ? 0 : data[0].size(); }\n\n    T& operator()(const\
    \ int i, const int j) {\n        assert(i < height());\n        assert(j < width());\n\
    \        return data[i][j];\n    }\n    const T& operator()(const int i, const\
    \ int j) const {\n        assert(i < height());\n        assert(j < width());\n\
    \        return data[i][j];\n    }\n\n    Self operator+(const Self& other) const\
    \ { return Self(*this) += other; }\n    Self& operator+=(const Self& other) {\n\
    \        assert(height() == other.height());\n        assert(width() == other.width());\n\
    \        for (const int i : rep(0, height())) {\n            for (const int j\
    \ : rep(0, width())) {\n                data[i][j] = S::sum(data[i][j], other.data[i][j]);\n\
    \            }\n        }\n        return *this;\n    }\n\n    Self operator*(const\
    \ Self& other) const {\n        assert(width() == other.height());\n        Self\
    \ ret(height(), other.width(), S::zero());\n        for (const int i : rep(0,\
    \ height())) {\n            for (const int k : rep(0, width())) {\n          \
    \      for (const int j : rep(0, other.width())) {\n                    ret.data[i][j]\
    \ = S::sum(ret.data[i][j], S::product(data[i][k], other.data[k][j]));\n      \
    \          }\n            }\n        }\n        return ret;\n    }\n\n    Self\
    \ operator*(const T& other) const { return Self(*this) *= other; }\n    Self&\
    \ operator*=(const T& other) {\n        for (const int i : rep(0, height())) {\n\
    \            for (const int j : rep(0, width())) {\n                data[i][j]\
    \ = S::product(data[i][j], other);\n            }\n        }\n    }\n\n    Self\
    \ pow(u64 exp) const {\n        assert(height() == width());\n        Self ret(height(),\
    \ width(), S::zero()), mult(*this);\n        for (const int i : rep(0, height()))\
    \ {\n            ret.data[i][i] = S::one();\n        }\n        for (; exp > 0;\
    \ exp >>= 1) {\n            if (exp & 1) ret = ret * mult;\n            mult =\
    \ mult * mult;\n        }\n        return ret;\n    }\n};\n#line 2 \"math/static_modint.cpp\"\
    \n#include <ostream>\n#include <type_traits>\n#line 3 \"math/rem_euclid.cpp\"\n\
    \ntemplate <class T> constexpr T rem_euclid(T value, const T& mod) {\n    assert(mod\
    \ > 0);\n    return (value %= mod) >= 0 ? value : value + mod;\n}\n#line 3 \"\
    math/factorize_iter.cpp\"\n#include <utility>\n#include <variant>\n\ntemplate\
    \ <class T> class Factorizer {\n    struct Iter {\n        T s, t;\n        explicit\
    \ constexpr Iter(const T& s, const T& t) noexcept : s(s), t(t) {}\n        constexpr\
    \ bool operator!=(std::monostate) const noexcept { return s != 1; }\n        constexpr\
    \ void operator++() noexcept { t += 1; }\n        constexpr std::pair<T, int>\
    \ operator*() noexcept {\n            while (s % t != 0) {\n                if\
    \ (t * t > s) {\n                    const T u = s;\n                    s = 1;\n\
    \                    return {u, 1};\n                }\n                t += 1;\n\
    \            }\n            int e = 0;\n            while (s % t == 0) {\n   \
    \             e += 1;\n                s /= t;\n            }\n            return\
    \ {t, e};\n        }\n    };\n    T x;\n\n  public:\n    explicit constexpr Factorizer(const\
    \ T& x) noexcept : x(x) { assert(x > 0); }\n    constexpr Iter begin() const noexcept\
    \ { return Iter(x, 2); }\n    constexpr std::monostate end() noexcept { return\
    \ {}; }\n};\n\ntemplate <class T> constexpr Factorizer<T> factorize_iter(const\
    \ T& x) noexcept { return Factorizer<T>(x); }\n#line 3 \"math/totient.cpp\"\n\n\
    template <class T> constexpr T totient(T x) {\n    T ret = x;\n    for (const\
    \ auto& p : factorize_iter(x)) {\n        ret /= p.first;\n        ret *= p.first\
    \ - 1;\n    }\n    return ret;\n}\n#line 7 \"math/static_modint.cpp\"\n\ntemplate\
    \ <u32 MOD, std::enable_if_t<((u32)1 <= MOD and MOD <= ((u32)1 << 31))>* = nullptr>\
    \ class StaticModint {\n    using Self = StaticModint;\n\n    static inline constexpr\
    \ u32 PHI = totient(MOD);\n    u32 v;\n\n  public:\n    static constexpr u32 mod()\
    \ noexcept { return MOD; }\n\n    template <class T, std::enable_if_t<std::is_integral_v<T>>*\
    \ = nullptr>\n    static constexpr T normalize(const T& x) noexcept {\n      \
    \  return rem_euclid<std::common_type_t<T, i64>>(x, MOD);\n    }\n\n    constexpr\
    \ StaticModint() noexcept : v(0) {}\n    template <class T> constexpr StaticModint(const\
    \ T& x) noexcept : v(normalize(x)) {}\n    template <class T> static constexpr\
    \ Self raw(const T& x) noexcept {\n        Self ret;\n        ret.v = x;\n   \
    \     return ret;\n    }\n\n    constexpr u32 val() const noexcept { return v;\
    \ }\n    constexpr Self neg() const noexcept { return raw(v == 0 ? 0 : MOD - v);\
    \ }\n    constexpr Self inv() const noexcept { return pow(PHI - 1); }\n    constexpr\
    \ Self pow(u64 exp) const noexcept {\n        Self ret(1), mult(*this);\n    \
    \    for (; exp > 0; exp >>= 1) {\n            if (exp & 1) ret *= mult;\n   \
    \         mult *= mult;\n        }\n        return ret;\n    }\n\n    constexpr\
    \ Self operator-() const noexcept { return neg(); }\n    constexpr Self operator~()\
    \ const noexcept { return inv(); }\n\n    constexpr Self operator+(const Self&\
    \ rhs) const noexcept { return Self(*this) += rhs; }\n    constexpr Self& operator+=(const\
    \ Self& rhs) noexcept {\n        if ((v += rhs.v) >= MOD) v -= MOD;\n        return\
    \ *this;\n    }\n\n    constexpr Self operator-(const Self& rhs) const noexcept\
    \ { return Self(*this) -= rhs; }\n    constexpr Self& operator-=(const Self& rhs)\
    \ noexcept {\n        if (v < rhs.v) v += MOD;\n        v -= rhs.v;\n        return\
    \ *this;\n    }\n\n    constexpr Self operator*(const Self& rhs) const noexcept\
    \ { return Self(*this) *= rhs; }\n    constexpr Self& operator*=(const Self& rhs)\
    \ noexcept {\n        v = (u64)v * rhs.v % MOD;\n        return *this;\n    }\n\
    \n    constexpr Self operator/(const Self& rhs) const noexcept { return Self(*this)\
    \ /= rhs; }\n    constexpr Self& operator/=(const Self& rhs) noexcept { return\
    \ *this *= rhs.inv(); }\n\n    constexpr bool operator==(const Self& rhs) const\
    \ noexcept { return v == rhs.v; }\n    constexpr bool operator!=(const Self& rhs)\
    \ const noexcept { return v != rhs.v; }\n    friend std::ostream& operator<<(std::ostream&\
    \ stream, const Self& rhs) { return stream << rhs.v; }\n};\n\nusing Modint1000000007\
    \ = StaticModint<1000000007>;\nusing Modint998244353 = StaticModint<998244353>;\n\
    #line 2 \"traits/num_semiring.cpp\"\n\ntemplate <class T> struct NumSemiRing {\n\
    \    using Type = T;\n    static constexpr T zero() { return T(0); }\n    static\
    \ constexpr T one() { return T(1); }\n    static constexpr T sum(const T& x, const\
    \ T& y) { return x + y; }\n    static constexpr T product(const T& x, const T&\
    \ y) { return x * y; }\n};\n#line 9 \"test/semiring_matrix.test.cpp\"\n\nusing\
    \ Fp = Modint998244353;\nusing Matrix = SemiRingMatrix<NumSemiRing<Fp>>;\n\nint\
    \ main() {\n    int N, M, K;\n    std::cin >> N >> M >> K;\n    std::vector<std::vector<Fp>>\
    \ A(N, std::vector<Fp>(M));\n    std::vector<std::vector<Fp>> B(M, std::vector<Fp>(K));\n\
    \    for (auto& v : A) {\n        for (auto& x : v) {\n            u32 t;\n  \
    \          std::cin >> t;\n            x = Fp(t);\n        }\n    }\n    for (auto&\
    \ v : B) {\n        for (auto& x : v) {\n            u32 t;\n            std::cin\
    \ >> t;\n            x = Fp(t);\n        }\n    }\n    const auto C = Matrix(A)\
    \ * Matrix(B);\n    for (const auto i : rep(0, N)) {\n        for (const auto\
    \ j : rep(0, K)) {\n            std::cout << C(i, j) << \" \\n\"[j + 1 == K];\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n#include\
    \ <iostream>\n#include <vector>\n#include \"../math/semiring_matrix.cpp\"\n#include\
    \ \"../math/static_modint.cpp\"\n#include \"../traits/num_semiring.cpp\"\n#include\
    \ \"../utility/int_alias.cpp\"\n#include \"../utility/rep.cpp\"\n\nusing Fp =\
    \ Modint998244353;\nusing Matrix = SemiRingMatrix<NumSemiRing<Fp>>;\n\nint main()\
    \ {\n    int N, M, K;\n    std::cin >> N >> M >> K;\n    std::vector<std::vector<Fp>>\
    \ A(N, std::vector<Fp>(M));\n    std::vector<std::vector<Fp>> B(M, std::vector<Fp>(K));\n\
    \    for (auto& v : A) {\n        for (auto& x : v) {\n            u32 t;\n  \
    \          std::cin >> t;\n            x = Fp(t);\n        }\n    }\n    for (auto&\
    \ v : B) {\n        for (auto& x : v) {\n            u32 t;\n            std::cin\
    \ >> t;\n            x = Fp(t);\n        }\n    }\n    const auto C = Matrix(A)\
    \ * Matrix(B);\n    for (const auto i : rep(0, N)) {\n        for (const auto\
    \ j : rep(0, K)) {\n            std::cout << C(i, j) << \" \\n\"[j + 1 == K];\n\
    \        }\n    }\n}"
  dependsOn:
  - math/semiring_matrix.cpp
  - utility/int_alias.cpp
  - utility/rep.cpp
  - math/static_modint.cpp
  - math/rem_euclid.cpp
  - math/totient.cpp
  - math/factorize_iter.cpp
  - traits/num_semiring.cpp
  isVerificationFile: true
  path: test/semiring_matrix.test.cpp
  requiredBy: []
  timestamp: '2021-12-28 22:38:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/semiring_matrix.test.cpp
layout: document
redirect_from:
- /verify/test/semiring_matrix.test.cpp
- /verify/test/semiring_matrix.test.cpp.html
title: test/semiring_matrix.test.cpp
---
