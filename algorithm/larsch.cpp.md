---
data:
  _extendedDependsOn: []
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
  bundledCode: "#line 2 \"algorithm/larsch.cpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <functional>\n#include <memory>\n#include <vector>\n\nclass LARSCH {\n\
    \    using Select = std::function<bool(int, int, int)>;\n    struct ReduceRow;\n\
    \    struct ReduceCol;\n\n    struct ReduceRow {\n        int n, m, x, k;\n  \
    \      Select f;\n        std::unique_ptr<ReduceCol> rec;\n\n        explicit\
    \ ReduceRow(const int n_, const Select& f_) : n(n_), m(0), x(0), k(0), f(f_),\
    \ rec() {\n            const int h = n / 2;\n            if (h != 0) rec = std::make_unique<ReduceCol>(h,\
    \ [&](int i, int j, int k) { return f(2 * i + 1, j, k); });\n        }\n\n   \
    \     void add_column() {\n            if ((x & 1) and f(x, k, m)) k = m;\n  \
    \          if (rec) rec->add_column();\n            m += 1;\n        }\n\n   \
    \     int get_argmin() {\n            if (x & 1) {\n                x += 1;\n\
    \                return k;\n            } else {\n                int ret = k;\n\
    \                if (x + 1 == n)\n                    k = m - 1;\n           \
    \     else\n                    k = rec->get_argmin();\n                for (int\
    \ j = ret + 1; j <= k; j += 1)\n                    if (f(x, ret, j)) ret = j;\n\
    \                x += 1;\n                return ret;\n            }\n       \
    \ }\n    };\n\n    struct ReduceCol {\n        int n, m, x, y;\n        std::vector<int>\
    \ c;\n        Select f;\n        ReduceRow rec;\n\n        explicit ReduceCol(const\
    \ int n_, const Select& f_)\n            : n(n_), m(0), x(0), y(0), c(), f(f_),\
    \ rec(n_, [&](int i, int j, int k) { return f(i, c[j], c[k]); }) {}\n\n      \
    \  void add_column() {\n            while (true) {\n                const int\
    \ i = c.size();\n                if (i <= x or !f(i - 1, c[i - 1], m)) break;\n\
    \                c.pop_back();\n            }\n            if (c.size() != n)\
    \ c.push_back(m);\n            m += 1;\n        }\n\n        int get_argmin()\
    \ {\n            x += 1;\n            while (y < std::min(x, (int)c.size())) {\n\
    \                rec.add_column();\n                y += 1;\n            }\n \
    \           return c[rec.get_argmin()];\n        }\n    };\n\n    int row, col;\n\
    \    ReduceRow machine;\n\n  public:\n    explicit LARSCH(const int n, const Select&\
    \ f) : row(n), col(0), machine(n, f) {}\n\n    void add_column() {\n        assert(row\
    \ != 0);\n        col += 1;\n        machine.add_column();\n    }\n\n    int get_argmin()\
    \ {\n        assert(row != 0 and col != 0);\n        row -= 1;\n        return\
    \ machine.get_argmin();\n    }\n};\n\ntemplate <class T, class Comp = std::less<T>>\
    \ class CompLARSCH {\n    std::function<T(int, int)> func;\n    Comp comp;\n \
    \   LARSCH machine;\n\n  public:\n    explicit CompLARSCH(const int n, const std::function<T(int,\
    \ int)>& f, const Comp& c = Comp())\n        : func(f), comp(c), machine(n, [&](int\
    \ i, int j, int k) { return comp(func(i, k), func(i, j)); }) {}\n\n    void add_column()\
    \ { machine.add_column(); }\n\n    int get_argmin() { return machine.get_argmin();\
    \ }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <functional>\n\
    #include <memory>\n#include <vector>\n\nclass LARSCH {\n    using Select = std::function<bool(int,\
    \ int, int)>;\n    struct ReduceRow;\n    struct ReduceCol;\n\n    struct ReduceRow\
    \ {\n        int n, m, x, k;\n        Select f;\n        std::unique_ptr<ReduceCol>\
    \ rec;\n\n        explicit ReduceRow(const int n_, const Select& f_) : n(n_),\
    \ m(0), x(0), k(0), f(f_), rec() {\n            const int h = n / 2;\n       \
    \     if (h != 0) rec = std::make_unique<ReduceCol>(h, [&](int i, int j, int k)\
    \ { return f(2 * i + 1, j, k); });\n        }\n\n        void add_column() {\n\
    \            if ((x & 1) and f(x, k, m)) k = m;\n            if (rec) rec->add_column();\n\
    \            m += 1;\n        }\n\n        int get_argmin() {\n            if\
    \ (x & 1) {\n                x += 1;\n                return k;\n            }\
    \ else {\n                int ret = k;\n                if (x + 1 == n)\n    \
    \                k = m - 1;\n                else\n                    k = rec->get_argmin();\n\
    \                for (int j = ret + 1; j <= k; j += 1)\n                    if\
    \ (f(x, ret, j)) ret = j;\n                x += 1;\n                return ret;\n\
    \            }\n        }\n    };\n\n    struct ReduceCol {\n        int n, m,\
    \ x, y;\n        std::vector<int> c;\n        Select f;\n        ReduceRow rec;\n\
    \n        explicit ReduceCol(const int n_, const Select& f_)\n            : n(n_),\
    \ m(0), x(0), y(0), c(), f(f_), rec(n_, [&](int i, int j, int k) { return f(i,\
    \ c[j], c[k]); }) {}\n\n        void add_column() {\n            while (true)\
    \ {\n                const int i = c.size();\n                if (i <= x or !f(i\
    \ - 1, c[i - 1], m)) break;\n                c.pop_back();\n            }\n  \
    \          if (c.size() != n) c.push_back(m);\n            m += 1;\n        }\n\
    \n        int get_argmin() {\n            x += 1;\n            while (y < std::min(x,\
    \ (int)c.size())) {\n                rec.add_column();\n                y += 1;\n\
    \            }\n            return c[rec.get_argmin()];\n        }\n    };\n\n\
    \    int row, col;\n    ReduceRow machine;\n\n  public:\n    explicit LARSCH(const\
    \ int n, const Select& f) : row(n), col(0), machine(n, f) {}\n\n    void add_column()\
    \ {\n        assert(row != 0);\n        col += 1;\n        machine.add_column();\n\
    \    }\n\n    int get_argmin() {\n        assert(row != 0 and col != 0);\n   \
    \     row -= 1;\n        return machine.get_argmin();\n    }\n};\n\ntemplate <class\
    \ T, class Comp = std::less<T>> class CompLARSCH {\n    std::function<T(int, int)>\
    \ func;\n    Comp comp;\n    LARSCH machine;\n\n  public:\n    explicit CompLARSCH(const\
    \ int n, const std::function<T(int, int)>& f, const Comp& c = Comp())\n      \
    \  : func(f), comp(c), machine(n, [&](int i, int j, int k) { return comp(func(i,\
    \ k), func(i, j)); }) {}\n\n    void add_column() { machine.add_column(); }\n\n\
    \    int get_argmin() { return machine.get_argmin(); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/larsch.cpp
  requiredBy: []
  timestamp: '2021-12-17 09:20:39+09:00'
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
