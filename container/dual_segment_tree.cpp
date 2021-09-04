#pragma once
#include <cassert>
#include <vector>
#include "../bit/bit_rzeros.cpp"
#include "../bit/ceil_log2.cpp"
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"
#include "../utility/revrep.cpp"

template <class Effector> class DualSegmentTree {
    using E = Effector;
    usize internal_size, logn;
    std::vector<E> lazy;

    void apply(const usize k, const E& e) { lazy[k] = lazy[k] * e; }
    void flush(const usize k) {
        apply(2 * k, lazy[k]);
        apply(2 * k + 1, lazy[k]);
        lazy[k] = E::one();
    }
    void push(const usize k) {
        for (const usize d : revrep(bit_rzeros(k) + 1, logn + 1)) {
            flush(k >> d);
        }
    }

  public:
    explicit DualSegmentTree(const usize size = 0, const E& value = E::one())
        : DualSegmentTree(std::vector<E>(size, value)) {}
    explicit DualSegmentTree(const std::vector<E>& vec) : internal_size(vec.size()) {
        logn = ceil_log2(internal_size);
        lazy = std::vector<E>(2 * internal_size, E::one());
        for (const usize i : rep(0, internal_size)) lazy[i] = vec[i];
    }

    usize size() const { return internal_size; }

    void operate(usize l, usize r, const E& e) {
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
    void assign(usize i, const E& e) {
        assert(i < internal_size);
        i += internal_size;
        for (const usize d : revrep(1, logn + 1)) flush(i >> d);
        lazy[i] = e;
    }

    E get(usize i) const {
        assert(i < internal_size);
        i += internal_size;
        E ret = E::one();
        while (i > 0) {
            ret = ret * lazy[i];
            i >>= 1;
        }
        return ret;
    }
};