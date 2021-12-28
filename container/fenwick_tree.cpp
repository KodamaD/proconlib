#pragma once
#include <cassert>
#include <vector>
#include "../utility/ceil_log2.cpp"

template <class G> class FenwickTree {
    using T = typename G::Type;

    int logn;
    std::vector<T> data;

  public:
    explicit FenwickTree(const int size = 0) {
        logn = ceil_log2(size + 1) - 1;
        data = std::vector<T>(size + 1, G::identity());
    }

    int size() const { return data.size() - 1; }

    void add(int i, const T& x) {
        assert(0 <= i and i < size());
        i += 1;
        while (i <= size()) {
            data[i] = G::operation(data[i], x);
            i += i & -i;
        }
    }

    T fold() const { return fold(0, size()); }
    T fold(int l, int r) const {
        assert(0 <= l and l <= r and r <= size());
        T ret = G::identity();
        while (l < r) {
            ret = G::operation(ret, data[r]);
            r -= r & -r;
        }
        while (r < l) {
            ret = G::operation(ret, G::inverse(data[l]));
            l -= l & -l;
        }
        return ret;
    }

    template <class F> int max_right(const F& f) const {
        assert(f(G::identity()));
        int i = 0;
        T sum = G::identity();
        for (int k = (1 << logn); k > 0; k >>= 1) {
            if (i + k <= size() && f(G::operation(sum, data[i + k]))) {
                sum = G::operation(sum, data[i += k]);
            }
        }
        return i;
    }
};
