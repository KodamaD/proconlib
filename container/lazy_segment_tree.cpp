#pragma once
#include <cassert>
#include <vector>
#include "../bit/bit_rzeros.cpp"
#include "../bit/ceil_log2.cpp"
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"
#include "../utility/revrep.cpp"

template <class Monoid, class Effector> class LazySegmentTree {
    using M = Monoid;
    using E = Effector;
    usize internal_size, logn, seg_size;
    std::vector<M> data;
    std::vector<E> lazy;

    void fetch(const usize k) { data[k] = data[2 * k] + data[2 * k + 1]; }
    void apply(const usize k, const E& e) {
        data[k] = data[k] * e;
        if (k < seg_size) lazy[k] = lazy[k] * e;
    }
    void flush(const usize k) {
        apply(2 * k, lazy[k]);
        apply(2 * k + 1, lazy[k]);
        lazy[k] = E::one();
    }

    void push(const usize k) {
        for (const usize d : revrep(bit_rzeros(k) + 1, logn + 1)) flush(k >> d);
    }
    void pull(usize k) {
        for (k >>= bit_rzeros(k); k > 1;) fetch(k >>= 1);
    }

  public:
    explicit LazySegmentTree(const usize size = 0, const M& value = M::zero())
        : LazySegmentTree(std::vector<M>(size, value)) {}
    explicit LazySegmentTree(const std::vector<M>& vec) : internal_size(vec.size()) {
        logn = ceil_log2(internal_size);
        seg_size = 1 << logn;
        data = std::vector<M>(2 * seg_size, M::zero());
        lazy = std::vector<E>(seg_size, E::one());
        for (const usize i : rep(0, internal_size)) data[seg_size + i] = vec[i];
        for (const usize i : revrep(1, seg_size)) fetch(i);
    }

    usize size() const { return internal_size; }

    void assign(usize i, const M& value) {
        assert(i < internal_size);
        i += seg_size;
        for (const usize d : revrep(1, logn + 1)) flush(i >> d);
        data[i] = value;
        for (const usize d : rep(1, logn + 1)) fetch(i >> d);
    }
    void operate(usize l, usize r, const E& e) {
        assert(l <= r and r <= internal_size);
        l += seg_size;
        r += seg_size;
        push(l);
        push(r);
        for (usize l0 = l, r0 = r; l0 < r0; l0 >>= 1, r0 >>= 1) {
            if (l0 & 1) apply(l0++, e);
            if (r0 & 1) apply(--r0, e);
        }
        pull(l);
        pull(r);
    }

    M fold() const { return data[1]; }
    M fold(usize l, usize r) {
        assert(l <= r and r <= internal_size);
        l += seg_size;
        r += seg_size;
        push(l);
        push(r);
        M ret_l = M::zero(), ret_r = M::zero();
        while (l < r) {
            if (l & 1) ret_l = ret_l + data[l++];
            if (r & 1) ret_r = data[--r] + ret_r;
            l >>= 1;
            r >>= 1;
        }
        return ret_l + ret_r;
    }

    template <class F> usize max_right(usize l, const F& f) {
        assert(l <= internal_size);
        assert(f(M::zero()));
        if (l == internal_size) return internal_size;
        l += seg_size;
        for (const usize d : revrep(1, logn + 1)) flush(l >> d);
        M sum = M::zero();
        do {
            while (!(l & 1)) l >>= 1;
            if (!f(sum + data[l])) {
                while (l < seg_size) {
                    flush(l);
                    l = 2 * l;
                    if (f(sum + data[l])) sum = sum + data[l++];
                }
                return l - seg_size;
            }
            sum = sum + data[l++];
        } while ((l & -l) != l);
        return internal_size;
    }

    template <class F> usize min_left(usize r, const F& f) {
        assert(r <= internal_size);
        assert(f(M::zero()));
        if (r == 0) return 0;
        r += seg_size;
        for (const usize d : revrep(1, logn + 1)) flush((r - 1) >> d);
        M sum = M::zero();
        do {
            r -= 1;
            while (r > 1 and (r & 1)) r >>= 1;
            if (!f(data[r] + sum)) {
                while (r < seg_size) {
                    flush(r);
                    r = 2 * r + 1;
                    if (f(data[r] + sum)) sum = data[r--] + sum;
                }
                return r + 1 - seg_size;
            }
            sum = data[r] + sum;
        } while ((r & -r) != r);
        return 0;
    }
};
