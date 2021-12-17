#pragma once
#include <cassert>
#include <vector>
#include "../utility/ceil_log2.cpp"

template <class T> class FenwickTree {
    int logn;
    std::vector<T> data;

  public:
    explicit FenwickTree(const int size = 0) {
        logn = ceil_log2(size + 1) - 1;
        data = std::vector<T>(size + 1, T(0));
    }

    int size() const { return data.size() - 1; }

    void add(int i, const T& x) {
        assert(i < size());
        i += 1;
        while (i < data.size()) {
            data[i] += x;
            i += i & -i;
        }
    }
    void subtract(int i, const T& x) {
        assert(i < size());
        i += 1;
        while (i < data.size()) {
            data[i] -= x;
            i += i & -i;
        }
    }

    T fold() const { return fold(0, size()); }
    T fold(int l, int r) const {
        assert(l <= r and r <= size());
        T ret(0);
        while (l < r) {
            ret += data[r];
            r -= r & -r;
        }
        while (r < l) {
            ret -= data[l];
            l -= l & -l;
        }
        return ret;
    }

    template <class F> int max_right(const F& f) const {
        assert(f(T(0)));
        int i = 0;
        T sum(0);
        for (int k = (1 << logn); k > 0; k >>= 1) {
            if (i + k <= size() && f(sum + data[i + k])) {
                i += k;
                sum += data[i];
            }
        }
        return i;
    }
};
