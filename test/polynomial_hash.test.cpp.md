---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: container/polynomial_hash.cpp
    title: container/polynomial_hash.cpp
  - icon: ':x:'
    path: random/rand_int.cpp
    title: random/rand_int.cpp
  - icon: ':question:'
    path: random/xorshift.cpp
    title: random/xorshift.cpp
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B
  bundledCode: "#line 1 \"test/polynomial_hash.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B\"\
    \n#line 2 \"container/polynomial_hash.cpp\"\n#include <cassert>\n#include <string>\n\
    #include <type_traits>\n#include <vector>\n#line 2 \"random/rand_int.cpp\"\n#include\
    \ <random>\n#line 2 \"random/xorshift.cpp\"\n#include <chrono>\n#line 2 \"utility/int_alias.cpp\"\
    \n#include <cstdint>\n\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\n\
    using i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing i128 = __int128_t;\n\
    using u128 = __uint128_t;\n#line 5 \"random/xorshift.cpp\"\n\nu64 xorshift() {\n\
    \    static u64 state = std::chrono::system_clock::now().time_since_epoch().count();\n\
    \    state ^= state << 7;\n    state ^= state >> 9;\n    return state;\n}\n#line\
    \ 4 \"random/rand_int.cpp\"\n\ntemplate <class T> T rand_int(const T& min, const\
    \ T& max) {\n    static std::default_random_engine gen(xorshift());\n    return\
    \ std::uniform_int_distribution<T>(min, max)(gen);\n}\n#line 2 \"utility/rep.cpp\"\
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
    \ { return Range(0, n); }\n#line 9 \"container/polynomial_hash.cpp\"\n\nstruct\
    \ PolynomialHashOperations {\n    static inline constexpr u64 MOD = ((u64)1 <<\
    \ 61) - 1;\n    static constexpr u64 sum(u64 a, const u64 b) { return (a += b)\
    \ >= MOD ? a - MOD : a; }\n    static constexpr u64 difference(u64 a, const u64\
    \ b) { return (a += MOD - b) >= MOD ? a - MOD : a; }\n    static constexpr u64\
    \ product(const u64 a, const u64 b) {\n        u128 ret = (u128)a * b;\n     \
    \   ret = (ret >> 61) + (ret & MOD);\n        return ret >= MOD ? ret - MOD :\
    \ ret;\n    }\n};\n\ntemplate <int ID> struct PolynomialHashBase {\n    static\
    \ inline const u64 BASE = rand_int<u64>(0, MOD - 1);\n    static u64 base_pow(const\
    \ int n) {\n        static std::vector<u64> vec;\n        if (vec.empty()) vec\
    \ = {1};\n        while ((int)vec.size() <= n) vec.push_back(PolynomialHashOperations::product(vec.back(),\
    \ BASE));\n        return vec[n];\n    }\n};\n\ntemplate <class T, int ID = -1,\
    \ std::enable_if_t<std::is_integral_v<T>>* = nullptr> class PolynomialHash {\n\
    \    using Oper = PolynomialHashOperations;\n    using Base = PolynomialHashBase<ID>;\n\
    \n    std::vector<u64> hash;\n    std::vector<T> data;\n\n  public:\n    PolynomialHash()\
    \ : PolynomialHash(std::vector<T>()) {}\n    explicit PolynomialHash(const std::vector<T>&\
    \ vec) : data(vec) {\n        const int size = data.size();\n        hash = std::vector<u64>(size\
    \ + 1);\n        for (const int i : rep(size)) {\n            assert(0 <= data[i]\
    \ and (u64) data[i] < Base::MOD);\n            hash[i + 1] = Oper::sum(Oper::product(Base::BASE,\
    \ hash[i]), (u64)data[i]);\n        }\n    }\n\n    int size() const { return\
    \ data.size(); }\n    const std::vector<T>& get() const { return data; }\n\n \
    \   u64 fold() const { return hash.back(); }\n    u64 fold(const int l, const\
    \ int r) const {\n        assert(0 <= l and l <= r and r <= size());\n       \
    \ return Oper::difference(hash[r], Oper::product(hash[l], Base::base_pow[r - l]));\n\
    \    }\n\n    void concat(const PolynomialHash& other) {\n        hash.reserve(hash.size()\
    \ + other.size());\n        u64 val = hash.back();\n        for (const int i :\
    \ rep(other.size())) {\n            val = Oper::product(val, Base::BASE);\n  \
    \          hash.push_back(Oper::sum(val, other.hash[i + 1]));\n        }\n   \
    \     data.reserve(data.size() + other.size());\n        std::copy(other.data.cbegin(),\
    \ other.data.cend(), std::back_inserter(data));\n    }\n};\n#line 3 \"test/polynomial_hash.test.cpp\"\
    \n#include <iostream>\n#line 5 \"test/polynomial_hash.test.cpp\"\n\nint main()\
    \ {\n    std::string T, P;\n    std::cin >> T >> P;\n    if (T.size() < P.size())\
    \ {\n        return 0;\n    }\n    PolynomialHash rh(std::vector<char>(T.begin(),\
    \ T.end()));\n    const auto match = PolynomialHash(std::vector<char>(P.begin(),\
    \ P.end())).fold();\n    for (const int i : rep(0, T.size() - P.size() + 1)) {\n\
    \        if (rh.fold(i, i + P.size()) == match) {\n            std::cout << i\
    \ << '\\n';\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B\"\
    \n#include \"../container/polynomial_hash.cpp\"\n#include <iostream>\n#include\
    \ \"../utility/rep.cpp\"\n\nint main() {\n    std::string T, P;\n    std::cin\
    \ >> T >> P;\n    if (T.size() < P.size()) {\n        return 0;\n    }\n    PolynomialHash\
    \ rh(std::vector<char>(T.begin(), T.end()));\n    const auto match = PolynomialHash(std::vector<char>(P.begin(),\
    \ P.end())).fold();\n    for (const int i : rep(0, T.size() - P.size() + 1)) {\n\
    \        if (rh.fold(i, i + P.size()) == match) {\n            std::cout << i\
    \ << '\\n';\n        }\n    }\n    return 0;\n}"
  dependsOn:
  - container/polynomial_hash.cpp
  - random/rand_int.cpp
  - random/xorshift.cpp
  - utility/int_alias.cpp
  - utility/rep.cpp
  isVerificationFile: true
  path: test/polynomial_hash.test.cpp
  requiredBy: []
  timestamp: '2021-12-28 22:38:25+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/polynomial_hash.test.cpp
layout: document
redirect_from:
- /verify/test/polynomial_hash.test.cpp
- /verify/test/polynomial_hash.test.cpp.html
title: test/polynomial_hash.test.cpp
---
