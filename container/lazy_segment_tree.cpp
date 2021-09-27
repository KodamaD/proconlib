#pragma once
#include <cassert>
#include <vector>
#include "../bit/bit_rzeros.cpp"
#include "../bit/ceil_log2.cpp"
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"
#include "../utility/revrep.cpp"

template <class A> class LazySegmentTree {
    using M = typename A::Monoid;
    using E = typename A::Effector;
    using T = typename M::Type;
    using U = typename E::Type;
    usize internal_size, logn, seg_size;
    std::vector<T> data;
    std::vector<U> lazy;

    void fetch(const usize k) { data[k] = M::operation(data[2 * k], data[2 * k + 1]); }
    void apply(const usize k, const U& e) {
        data[k] = A::operation(data[k], e);
        if (k < seg_size) lazy[k] = E::operation(lazy[k], e);
    }
    void flush(const usize k) {
        apply(2 * k, lazy[k]);
        apply(2 * k + 1, lazy[k]);
        lazy[k] = E::identity();
    }

    void push(const usize k) {
        for (const usize d : revrep(bit_rzeros(k) + 1, logn + 1)) flush(k >> d);
    }
    void pull(usize k) {
        for (k >>= bit_rzeros(k); k > 1;) fetch(k >>= 1);
    }

  public:
    explicit LazySegmentTree(const usize size = 0, const T& value = M::identity())
        : LazySegmentTree(std::vector<T>(size, value)) {}
    explicit LazySegmentTree(const std::vector<T>& vec) : internal_size(vec.size()) {
        logn = ceil_log2(internal_size);
        seg_size = 1 << logn;
        data = std::vector<T>(2 * seg_size, M::identity());
        lazy = std::vector<U>(seg_size, E::identity());
        for (const usize i : rep(0, internal_size)) data[seg_size + i] = vec[i];
        for (const usize i : revrep(1, seg_size)) fetch(i);
    }

    usize size() const { return internal_size; }

    void assign(usize i, const T& value) {
        assert(i < internal_size);
        i += seg_size;
        for (const usize d : revrep(1, logn + 1)) flush(i >> d);
        data[i] = value;
        for (const usize d : rep(1, logn + 1)) fetch(i >> d);
    }
    void operate(usize l, usize r, const U& e) {
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

    T fold() const { return data[1]; }
    T fold(usize l, usize r) {
        assert(l <= r and r <= internal_size);
        l += seg_size;
        r += seg_size;
        push(l);
        push(r);
        T ret_l = M::identity(), ret_r = M::identity();
        while (l < r) {
            if (l & 1) ret_l = M::operation(ret_l, data[l++]);
            if (r & 1) ret_r = M::operation(data[--r], ret_r);
            l >>= 1;
            r >>= 1;
        }
        return M::operation(ret_l, ret_r);
    }

    template <class F> usize max_right(usize l, const F& f) {
        assert(l <= internal_size);
        assert(f(M::identity()));
        if (l == internal_size) return internal_size;
        l += seg_size;
        for (const usize d : revrep(1, logn + 1)) flush(l >> d);
        T sum = M::identity();
        do {
            while (!(l & 1)) l >>= 1;
            if (!f(M::operation(sum, data[l]))) {
                while (l < seg_size) {
                    flush(l);
                    l = 2 * l;
                    if (f(M::operation(sum, data[l]))) sum = M::operation(sum, data[l++]);
                }
                return l - seg_size;
            }
            sum = M::operation(sum, data[l++]);
        } while ((l & -l) != l);
        return internal_size;
    }

    template <class F> usize min_left(usize r, const F& f) {
        assert(r <= internal_size);
        assert(f(M::identity()));
        if (r == 0) return 0;
        r += seg_size;
        for (const usize d : revrep(1, logn + 1)) flush((r - 1) >> d);
        T sum = M::identity();
        do {
            r -= 1;
            while (r > 1 and (r & 1)) r >>= 1;
            if (!f(M::operation(data[r], sum))) {
                while (r < seg_size) {
                    flush(r);
                    r = 2 * r + 1;
                    if (f(M::operation(data[r], sum))) sum = M::operation(data[r--], sum);
                }
                return r + 1 - seg_size;
            }
            sum = M::operation(data[r], sum);
        } while ((r & -r) != r);
        return 0;
    }
};
