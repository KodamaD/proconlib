#pragma once
#include "../utility/int_alias.cpp"
#include "../bit/ceil_log2.cpp"
#include <vector>
#include <cassert>

template <class T>
class FenwickTree {
    usize logn;
    std::vector<T> data;
public:
    explicit FenwickTree(const usize size = 0) {
        logn = ceil_log2(size + 1) - 1;
        data = std::vector<T>(size + 1, T{});
    }

    usize size() const { return data.size() - 1; }

    void add(usize i, const T& x) { 
        assert(i < size());
        i += 1;
        while (i < data.size()) {
            data[i] += x;
            i += i & -i;
        }
    }
    void subtract(usize i, const T& x) { 
        assert(i < size());
        i += 1;
        while (i < data.size()) {
            data[i] -= x;
            i += i & -i;
        }
    }

    T fold(usize l, usize r) const {
        assert(l <= r and r <= size());
        T ret{};
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

    template <class F>
    usize max_right(const F &f) const {
        assert(f(T{}));
        usize i = 0;
        T sum{};
        for (usize k = (1 << logn); k > 0; k >>= 1) {
            if (i + k <= size() && f(sum + data[i + k])) {
                i += k;
                sum += data[i];
            }
        }
        return i;
    }
};
