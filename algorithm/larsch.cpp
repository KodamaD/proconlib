#pragma once
#include <algorithm>
#include <cassert>
#include <functional>
#include <memory>
#include <vector>

class LARSCH {
    using Select = std::function<bool(int, int, int)>;
    struct ReduceRow;
    struct ReduceCol;

    struct ReduceRow {
        int n, m, x, k;
        Select f;
        std::unique_ptr<ReduceCol> rec;

        explicit ReduceRow(const int n_, const Select& f_) : n(n_), m(0), x(0), k(0), f(f_), rec() {
            const int h = n / 2;
            if (h != 0) rec = std::make_unique<ReduceCol>(h, [&](int i, int j, int k) { return f(2 * i + 1, j, k); });
        }

        void add_column() {
            if ((x & 1) and f(x, k, m)) k = m;
            if (rec) rec->add_column();
            m += 1;
        }

        int get_argmin() {
            if (x & 1) {
                x += 1;
                return k;
            } else {
                int ret = k;
                if (x + 1 == n)
                    k = m - 1;
                else
                    k = rec->get_argmin();
                for (int j = ret + 1; j <= k; j += 1)
                    if (f(x, ret, j)) ret = j;
                x += 1;
                return ret;
            }
        }
    };

    struct ReduceCol {
        int n, m, x, y;
        std::vector<int> c;
        Select f;
        ReduceRow rec;

        explicit ReduceCol(const int n_, const Select& f_)
            : n(n_), m(0), x(0), y(0), c(), f(f_), rec(n_, [&](int i, int j, int k) { return f(i, c[j], c[k]); }) {}

        void add_column() {
            while (true) {
                const int i = c.size();
                if (i <= x or !f(i - 1, c[i - 1], m)) break;
                c.pop_back();
            }
            if ((int)c.size() != n) c.push_back(m);
            m += 1;
        }

        int get_argmin() {
            x += 1;
            while (y < std::min(x, (int)c.size())) {
                rec.add_column();
                y += 1;
            }
            return c[rec.get_argmin()];
        }
    };

    int row, col;
    ReduceRow machine;

  public:
    explicit LARSCH(const int n, const Select& f) : row(n), col(0), machine(n, f) {}

    void add_column() {
        assert(row != 0);
        col += 1;
        machine.add_column();
    }

    int get_argmin() {
        assert(row != 0 and col != 0);
        row -= 1;
        return machine.get_argmin();
    }
};

template <class T, class Comp = std::less<T>> class CompLARSCH {
    std::function<T(int, int)> func;
    Comp comp;
    LARSCH machine;

  public:
    explicit CompLARSCH(const int n, const std::function<T(int, int)>& f, const Comp& c = Comp())
        : func(f), comp(c), machine(n, [&](int i, int j, int k) { return comp(func(i, k), func(i, j)); }) {}

    void add_column() { machine.add_column(); }

    int get_argmin() { return machine.get_argmin(); }
};