#pragma once
#include <cassert>
#include <functional>
#include <memory>
#include <vector>
#include "../utility/int_alias.cpp"

class LARSCH {
    using Select = std::function<bool(usize, usize, usize)>;
    struct ReduceRow;
    struct ReduceCol;

    struct ReduceRow {
        usize n, m, x, k;
        Select f;
        std::unique_ptr<ReduceCol> rec;

        explicit ReduceRow(const usize n_, const Select& f_) : n(n_), m(0), x(0), k(0), f(f_), rec() {
            const usize h = n / 2;
            if (h != 0)
                rec = std::make_unique<ReduceCol>(h, [&](usize i, usize j, usize k) { return f(2 * i + 1, j, k); });
        }

        void add_column() {
            if ((x & 1) and f(x, k, m)) k = m;
            if (rec) rec->add_column();
            m += 1;
        }

        usize get_argmin() {
            if (x & 1) {
                x += 1;
                return k;
            } else {
                usize ret = k;
                if (x + 1 == n)
                    k = m - 1;
                else
                    k = rec->get_argmin();
                for (usize j = ret + 1; j <= k; j += 1)
                    if (f(x, ret, j)) ret = j;
                x += 1;
                return ret;
            }
        }
    };

    struct ReduceCol {
        usize n, m, x, y;
        std::vector<usize> c;
        Select f;
        ReduceRow rec;

        explicit ReduceCol(const usize n_, const Select& f_)
            : n(n_), m(0), x(0), y(0), c(), f(f_), rec(n_, [&](usize i, usize j, usize k) { return f(i, c[j], c[k]); }) {}

        void add_column() {
            while (true) {
                const usize i = c.size();
                if (i <= x or !f(i - 1, c[i - 1], m)) break;
                c.pop_back();
            }
            if (c.size() != n) c.push_back(m);
            m += 1;
        }

        usize get_argmin() {
            x += 1;
            while (y < std::min(x, c.size())) {
                rec.add_column();
                y += 1;
            }
            return c[rec.get_argmin()];
        }
    };

    usize row, col;
    ReduceRow machine;

  public:
    explicit LARSCH(const usize n, const Select& f) : row(n), col(0), machine(n, f) {}

    void add_column() {
        assert(row != 0);
        col += 1;
        machine.add_column();
    }

    usize get_argmin() {
        assert(row != 0 and col != 0);
        row -= 1;
        return machine.get_argmin();
    }
};

template <class T, class Comp = std::less<T>> class CompLARSCH {
    std::function<T(usize, usize)> func;
    Comp comp;
    LARSCH machine;

  public:
    explicit CompLARSCH(const usize n, const std::function<T(usize, usize)>& f, const Comp& c = Comp())
        : func(f), comp(c), machine(n, [&](usize i, usize j, usize k) { return comp(func(i, k), func(i, j)); }) {}

    void add_column() { machine.add_column(); }

    usize get_argmin() { return machine.get_argmin(); }
};