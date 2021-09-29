---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/larsch.test.cpp
    title: test/larsch.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algorithm/larsch.cpp\"\n#include <cassert>\n#include <functional>\n\
    #include <memory>\n#include <vector>\n#line 2 \"utility/int_alias.cpp\"\n#include\
    \ <cstddef>\n#include <cstdint>\n\nusing i32 = std::int32_t;\nusing u32 = std::uint32_t;\n\
    using i64 = std::int64_t;\nusing u64 = std::uint64_t;\nusing isize = std::ptrdiff_t;\n\
    using usize = std::size_t;\n#line 7 \"algorithm/larsch.cpp\"\n\nclass LARSCH {\n\
    \    using Select = std::function<bool(usize, usize, usize)>;\n    struct ReduceRow;\n\
    \    struct ReduceCol;\n\n    struct ReduceRow {\n        usize n, m, x, k;\n\
    \        Select f;\n        std::unique_ptr<ReduceCol> rec;\n\n        explicit\
    \ ReduceRow(const usize n_, const Select& f_) : n(n_), m(0), x(0), k(0), f(f_),\
    \ rec() {\n            const usize h = n / 2;\n            if (h != 0)\n     \
    \           rec = std::make_unique<ReduceCol>(h, [&](usize i, usize j, usize k)\
    \ { return f(2 * i + 1, j, k); });\n        }\n\n        void add_column() {\n\
    \            if ((x & 1) and f(x, k, m)) k = m;\n            if (rec) rec->add_column();\n\
    \            m += 1;\n        }\n\n        usize get_argmin() {\n            if\
    \ (x & 1) {\n                x += 1;\n                return k;\n            }\
    \ else {\n                usize ret = k;\n                if (x + 1 == n)\n  \
    \                  k = m - 1;\n                else\n                    k = rec->get_argmin();\n\
    \                for (usize j = ret + 1; j <= k; j += 1)\n                   \
    \ if (f(x, ret, j)) ret = j;\n                x += 1;\n                return\
    \ ret;\n            }\n        }\n    };\n\n    struct ReduceCol {\n        usize\
    \ n, m, x, y;\n        std::vector<usize> c;\n        Select f;\n        ReduceRow\
    \ rec;\n\n        explicit ReduceCol(const usize n_, const Select& f_)\n     \
    \       : n(n_), m(0), x(0), y(0), c(), f(f_), rec(n_, [&](usize i, usize j, usize\
    \ k) {\n                  return f(i, c[j], c[k]);\n              }) {}\n\n  \
    \      void add_column() {\n            while (true) {\n                const\
    \ usize i = c.size();\n                if (i <= x or !f(i - 1, c[i - 1], m)) break;\n\
    \                c.pop_back();\n            }\n            if (c.size() != n)\
    \ c.push_back(m);\n            m += 1;\n        }\n\n        usize get_argmin()\
    \ {\n            x += 1;\n            while (y < std::min(x, c.size())) {\n  \
    \              rec.add_column();\n                y += 1;\n            }\n   \
    \         return c[rec.get_argmin()];\n        }\n    };\n\n    usize row, col;\n\
    \    ReduceRow machine;\n\n  public:\n    explicit LARSCH(const usize n, const\
    \ Select& f) : row(n), col(0), machine(n, f) {}\n\n    void add_column() {\n \
    \       assert(row != 0);\n        col += 1;\n        machine.add_column();\n\
    \    }\n\n    usize get_argmin() {\n        assert(row != 0 and col != 0);\n \
    \       row -= 1;\n        return machine.get_argmin();\n    }\n};\n\ntemplate\
    \ <class T, class Comp = std::less<T>> class CompLARSCH {\n    std::function<T(usize,\
    \ usize)> func;\n    Comp comp;\n    LARSCH machine;\n\n  public:\n    explicit\
    \ CompLARSCH(const usize n, const std::function<T(usize, usize)>& f, const Comp&\
    \ c = Comp())\n        : func(f), comp(c), machine(n, [&](usize i, usize j, usize\
    \ k) { return comp(func(i, k), func(i, j)); }) {}\n\n    void add_column() { machine.add_column();\
    \ }\n\n    usize get_argmin() { return machine.get_argmin(); }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <functional>\n#include <memory>\n\
    #include <vector>\n#include \"../utility/int_alias.cpp\"\n\nclass LARSCH {\n \
    \   using Select = std::function<bool(usize, usize, usize)>;\n    struct ReduceRow;\n\
    \    struct ReduceCol;\n\n    struct ReduceRow {\n        usize n, m, x, k;\n\
    \        Select f;\n        std::unique_ptr<ReduceCol> rec;\n\n        explicit\
    \ ReduceRow(const usize n_, const Select& f_) : n(n_), m(0), x(0), k(0), f(f_),\
    \ rec() {\n            const usize h = n / 2;\n            if (h != 0)\n     \
    \           rec = std::make_unique<ReduceCol>(h, [&](usize i, usize j, usize k)\
    \ { return f(2 * i + 1, j, k); });\n        }\n\n        void add_column() {\n\
    \            if ((x & 1) and f(x, k, m)) k = m;\n            if (rec) rec->add_column();\n\
    \            m += 1;\n        }\n\n        usize get_argmin() {\n            if\
    \ (x & 1) {\n                x += 1;\n                return k;\n            }\
    \ else {\n                usize ret = k;\n                if (x + 1 == n)\n  \
    \                  k = m - 1;\n                else\n                    k = rec->get_argmin();\n\
    \                for (usize j = ret + 1; j <= k; j += 1)\n                   \
    \ if (f(x, ret, j)) ret = j;\n                x += 1;\n                return\
    \ ret;\n            }\n        }\n    };\n\n    struct ReduceCol {\n        usize\
    \ n, m, x, y;\n        std::vector<usize> c;\n        Select f;\n        ReduceRow\
    \ rec;\n\n        explicit ReduceCol(const usize n_, const Select& f_)\n     \
    \       : n(n_), m(0), x(0), y(0), c(), f(f_), rec(n_, [&](usize i, usize j, usize\
    \ k) {\n                  return f(i, c[j], c[k]);\n              }) {}\n\n  \
    \      void add_column() {\n            while (true) {\n                const\
    \ usize i = c.size();\n                if (i <= x or !f(i - 1, c[i - 1], m)) break;\n\
    \                c.pop_back();\n            }\n            if (c.size() != n)\
    \ c.push_back(m);\n            m += 1;\n        }\n\n        usize get_argmin()\
    \ {\n            x += 1;\n            while (y < std::min(x, c.size())) {\n  \
    \              rec.add_column();\n                y += 1;\n            }\n   \
    \         return c[rec.get_argmin()];\n        }\n    };\n\n    usize row, col;\n\
    \    ReduceRow machine;\n\n  public:\n    explicit LARSCH(const usize n, const\
    \ Select& f) : row(n), col(0), machine(n, f) {}\n\n    void add_column() {\n \
    \       assert(row != 0);\n        col += 1;\n        machine.add_column();\n\
    \    }\n\n    usize get_argmin() {\n        assert(row != 0 and col != 0);\n \
    \       row -= 1;\n        return machine.get_argmin();\n    }\n};\n\ntemplate\
    \ <class T, class Comp = std::less<T>> class CompLARSCH {\n    std::function<T(usize,\
    \ usize)> func;\n    Comp comp;\n    LARSCH machine;\n\n  public:\n    explicit\
    \ CompLARSCH(const usize n, const std::function<T(usize, usize)>& f, const Comp&\
    \ c = Comp())\n        : func(f), comp(c), machine(n, [&](usize i, usize j, usize\
    \ k) { return comp(func(i, k), func(i, j)); }) {}\n\n    void add_column() { machine.add_column();\
    \ }\n\n    usize get_argmin() { return machine.get_argmin(); }\n};"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: algorithm/larsch.cpp
  requiredBy: []
  timestamp: '2021-09-29 21:09:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/larsch.test.cpp
documentation_of: algorithm/larsch.cpp
layout: document
redirect_from:
- /library/algorithm/larsch.cpp
- /library/algorithm/larsch.cpp.html
title: algorithm/larsch.cpp
---
