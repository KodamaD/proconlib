#pragma once
#include <cassert>
#include <vector>
#include "../bit/bit_rzeros.cpp"
#include "../bit/ceil_log2.cpp"
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"
#include "../utility/revrep.cpp"

template <class M> class DualSegmentTree {
    using T = typename M::Type;
    usize internal_size, logn;
    std::vector<T> lazy;

    void apply(const usize k, const T& e) { lazy[k] = M::operation(lazy[k], e); }
    void flush(const usize k) {
        apply(2 * k, lazy[k]);
        apply(2 * k + 1, lazy[k]);
        lazy[k] = M::identity();
    }
    void push(const usize k) {
        for (const usize d : revrep(bit_rzeros(k) + 1, logn + 1)) {
            flush(k >> d);
        }
    }

  public:
    explicit DualSegmentTree(const usize size = 0, const T& value = M::identity())
        : DualSegmentTree(std::vector<T>(size, value)) {}
    explicit DualSegmentTree(const std::vector<T>& vec) : internal_size(vec.size()) {
        logn = ceil_log2(internal_size);
        lazy = std::vector<T>(2 * internal_size, M::identity());
        for (const usize i : rep(0, internal_size)) lazy[i] = vec[i];
    }

    usize size() const { return internal_size; }

    void operate(usize l, usize r, const T& e) {
        assert(l <= r and r <= internal_size);
        l += internal_size;
        r += internal_size;
        push(l);
        push(r);
        while (l < r) {
            if (l & 1) apply(l++, e);
            if (r & 1) apply(--r, e);
            l >>= 1;
            r >>= 1;
        }
    }
    void assign(usize i, const T& e) {
        assert(i < internal_size);
        i += internal_size;
        for (const usize d : revrep(1, logn + 1)) flush(i >> d);
        lazy[i] = e;
    }

    T get(usize i) const {
        assert(i < internal_size);
        i += internal_size;
        T ret = M::identity();
        while (i > 0) {
            ret = M::operation(ret, lazy[i]);
            i >>= 1;
        }
        return ret;
    }
};