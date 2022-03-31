---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/auto_memoize.cpp
    title: utility/auto_memoize.cpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_10_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_10_A
  bundledCode: "#line 1 \"test/auto_memoize.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_10_A\"\
    \n#line 2 \"utility/int_alias.cpp\"\n#include <cstdint>\n\nusing i32 = std::int32_t;\n\
    using u32 = std::uint32_t;\nusing i64 = std::int64_t;\nusing u64 = std::uint64_t;\n\
    using i128 = __int128_t;\nusing u128 = __uint128_t;\n#line 2 \"utility/auto_memoize.cpp\"\
    \n#include <map>\n#include <tuple>\n#include <type_traits>\n#include <utility>\n\
    \ntemplate <class F> class AutoMemoization {\n    template <class> struct GetSig;\n\
    \    template <class T, class R, class S, class... Args> struct GetSig<R (T::*)(S,\
    \ Args...) const> {\n        using Ret = R;\n        using Tuple = std::tuple<Args...>;\n\
    \    };\n\n    using Sig = GetSig<decltype(&F::template operator()<AutoMemoization<F>&>)>;\n\
    \    using R = typename Sig::Ret;\n    using Tuple = typename Sig::Tuple;\n\n\
    \    F func;\n    mutable std::map<Tuple, R> data;\n\n    template <std::size_t...\
    \ I> R apply(const Tuple& args_tuple, std::index_sequence<I...>) const {\n   \
    \     return func(*this, std::get<I>(args_tuple)...);\n    }\n\n  public:\n  \
    \  explicit AutoMemoization(F&& f) : func(std::forward<F>(f)) {}\n\n    template\
    \ <class... Args> R operator()(Args&&... args) const {\n        Tuple tup(std::forward<Args>(args)...);\n\
    \        const auto itr = data.find(tup);\n        if (itr != data.end()) return\
    \ itr->second;\n        R ret = apply(tup, std::make_index_sequence<std::tuple_size_v<Tuple>>());\n\
    \        data.emplace(std::move(tup), ret);\n        return ret;\n    }\n};\n\n\
    template <class F> decltype(auto) auto_memoize(F&& f) { return AutoMemoization<F>(std::forward<F>(f));\
    \ }\n#line 4 \"test/auto_memoize.test.cpp\"\n#include <iostream>\n\nint main()\
    \ {\n    u64 x;\n    std::cin >> x;\n    std::cout << auto_memoize([](auto&& fib,\
    \ const u64 x) -> u64 {\n        if (x <= 1) return 1;\n        return fib(x -\
    \ 1) + fib(x - 2);\n    })(x) << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_10_A\"\
    \n#include \"../utility/int_alias.cpp\"\n#include \"../utility/auto_memoize.cpp\"\
    \n#include <iostream>\n\nint main() {\n    u64 x;\n    std::cin >> x;\n    std::cout\
    \ << auto_memoize([](auto&& fib, const u64 x) -> u64 {\n        if (x <= 1) return\
    \ 1;\n        return fib(x - 1) + fib(x - 2);\n    })(x) << '\\n';\n    return\
    \ 0;\n}\n"
  dependsOn:
  - utility/int_alias.cpp
  - utility/auto_memoize.cpp
  isVerificationFile: true
  path: test/auto_memoize.test.cpp
  requiredBy: []
  timestamp: '2021-12-17 09:20:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/auto_memoize.test.cpp
layout: document
redirect_from:
- /verify/test/auto_memoize.test.cpp
- /verify/test/auto_memoize.test.cpp.html
title: test/auto_memoize.test.cpp
---