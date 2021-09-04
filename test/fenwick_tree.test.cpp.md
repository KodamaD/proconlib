---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: bit/ceil_log2.cpp
    title: bit/ceil_log2.cpp
  - icon: ':heavy_check_mark:'
    path: container/fenwick_tree.cpp
    title: container/fenwick_tree.cpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/fenwick_tree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\
    \n#line 2 \"utility/int_alias.cpp\"\n#include <cstddef>\n#include <cstdint>\n\n\
    using i32 = std::int32_t;\nusing u32 = std::uint32_t;\nusing i64 = std::int64_t;\n\
    using u64 = std::uint64_t;\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n\
    using isize = std::ptrdiff_t;\nusing usize = std::size_t;\n#line 2 \"utility/rep.cpp\"\
    \n#include <algorithm>\n#line 4 \"utility/rep.cpp\"\n\nclass rep {\n    struct\
    \ Iter {\n        usize itr;\n        constexpr Iter(const usize pos) noexcept\
    \ : itr(pos) {}\n        constexpr void operator++() noexcept { ++itr; }\n   \
    \     constexpr bool operator!=(const Iter& other) const noexcept { return itr\
    \ != other.itr; }\n        constexpr usize operator*() const noexcept { return\
    \ itr; }\n    };\n    const Iter first, last;\n\n  public:\n    explicit constexpr\
    \ rep(const usize first, const usize last) noexcept : first(first), last(std::max(first,\
    \ last)) {}\n    constexpr Iter begin() const noexcept { return first; }\n   \
    \ constexpr Iter end() const noexcept { return last; }\n};\n#line 3 \"bit/ceil_log2.cpp\"\
    \n\nconstexpr u64 ceil_log2(const u64 x) {\n    u64 e = 0;\n    while (((u64)1\
    \ << e) < x) ++e;\n    return e;\n}\n#line 4 \"container/fenwick_tree.cpp\"\n\
    #include <vector>\n#include <cassert>\n\ntemplate <class T>\nclass FenwickTree\
    \ {\n    usize logn;\n    std::vector<T> data;\n    \npublic:\n    explicit FenwickTree(const\
    \ usize size = 0) {\n        logn = ceil_log2(size + 1) - 1;\n        data = std::vector<T>(size\
    \ + 1, T(0));\n    }\n\n    usize size() const { return data.size() - 1; }\n\n\
    \    void add(usize i, const T& x) { \n        assert(i < size());\n        i\
    \ += 1;\n        while (i < data.size()) {\n            data[i] += x;\n      \
    \      i += i & -i;\n        }\n    }\n    void subtract(usize i, const T& x)\
    \ { \n        assert(i < size());\n        i += 1;\n        while (i < data.size())\
    \ {\n            data[i] -= x;\n            i += i & -i;\n        }\n    }\n\n\
    \    T fold() const { return fold(0, size()); }\n    T fold(usize l, usize r)\
    \ const {\n        assert(l <= r and r <= size());\n        T ret(0);\n      \
    \  while (l < r) {\n            ret += data[r];\n            r -= r & -r;\n  \
    \      }\n        while (r < l) {\n            ret -= data[l];\n            l\
    \ -= l & -l;\n        }\n        return ret;\n    }\n\n    template <class F>\n\
    \    usize max_right(const F &f) const {\n        assert(f(T(0)));\n        usize\
    \ i = 0;\n        T sum(0);\n        for (usize k = (1 << logn); k > 0; k >>=\
    \ 1) {\n            if (i + k <= size() && f(sum + data[i + k])) {\n         \
    \       i += k;\n                sum += data[i];\n            }\n        }\n \
    \       return i;\n    }\n};\n#line 5 \"test/fenwick_tree.test.cpp\"\n#include\
    \ <iostream>\n\nint main() {\n    usize N, Q;\n    std::cin >> N >> Q;\n    FenwickTree<u64>\
    \ fen(N);\n    for (const usize i: rep(0, N)) {\n        u64 x;\n        std::cin\
    \ >> x;\n        fen.add(i, x);\n    }\n    while (Q--) {\n        usize t;\n\
    \        std::cin >> t;\n        if (t == 0) {\n            usize p;\n       \
    \     u64 x;\n            std::cin >> p >> x;\n            fen.add(p, x);\n  \
    \      }\n        else {\n            usize l, r;\n            std::cin >> l >>\
    \ r;\n            std::cout << fen.fold(l, r) << '\\n';\n        }\n    }\n  \
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include \"../utility/int_alias.cpp\"\n#include \"../utility/rep.cpp\"\n#include\
    \ \"../container/fenwick_tree.cpp\"\n#include <iostream>\n\nint main() {\n   \
    \ usize N, Q;\n    std::cin >> N >> Q;\n    FenwickTree<u64> fen(N);\n    for\
    \ (const usize i: rep(0, N)) {\n        u64 x;\n        std::cin >> x;\n     \
    \   fen.add(i, x);\n    }\n    while (Q--) {\n        usize t;\n        std::cin\
    \ >> t;\n        if (t == 0) {\n            usize p;\n            u64 x;\n   \
    \         std::cin >> p >> x;\n            fen.add(p, x);\n        }\n       \
    \ else {\n            usize l, r;\n            std::cin >> l >> r;\n         \
    \   std::cout << fen.fold(l, r) << '\\n';\n        }\n    }\n    return 0;\n}"
  dependsOn:
  - utility/int_alias.cpp
  - utility/rep.cpp
  - container/fenwick_tree.cpp
  - bit/ceil_log2.cpp
  isVerificationFile: true
  path: test/fenwick_tree.test.cpp
  requiredBy: []
  timestamp: '2021-09-04 17:30:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/fenwick_tree.test.cpp
layout: document
redirect_from:
- /verify/test/fenwick_tree.test.cpp
- /verify/test/fenwick_tree.test.cpp.html
title: test/fenwick_tree.test.cpp
---
