#pragma once
#include <cassert>
#include <vector>
#include "../bit/ceil_log2.cpp"
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"
#include "../utility/revrep.cpp"

template <class Monoid> class SegmentTree {
    using M = Monoid;
    usize internal_size, seg_size;
    std::vector<M> data;

    void fetch(const usize k) { data[k] = data[2 * k] + data[2 * k + 1]; }

  public:
    explicit SegmentTree(const usize size = 0, const M& value = M::zero()) : SegmentTree(std::vector<M>(size, value)) {}
    explicit SegmentTree(const std::vector<M>& vec) : internal_size(vec.size()) {
        seg_size = 1 << ceil_log2(internal_size);
        data = std::vector<M>(2 * seg_size, M::zero());
        for (const usize i : rep(0, internal_size)) data[seg_size + i] = vec[i];
        for (const usize i : revrep(1, seg_size)) fetch(i);
    }

    usize size() const { return internal_size; }

    void assign(usize i, const M& value) {
        assert(i < internal_size);
        i += seg_size;
        data[i] = value;
        while (i > 1) {
            i >>= 1;
            fetch(i);
        }
    }

    M fold() const { return data[1]; }
    M fold(usize l, usize r) const {
        assert(l <= r and r <= internal_size);
        l += seg_size;
        r += seg_size;
        M ret_l = M::zero(), ret_r = M::zero();
        while (l < r) {
            if (l & 1) ret_l = ret_l + data[l++];
            if (r & 1) ret_r = data[--r] + ret_r;
            l >>= 1;
            r >>= 1;
        }
        return ret_l + ret_r;
    }

    template <class F> usize max_right(usize l, const F& f) const {
        assert(l <= internal_size);
        assert(f(M::zero()));
        if (l == internal_size) return internal_size;
        l += seg_size;
        M sum = M::zero();
        do {
            while (!(l & 1)) l >>= 1;
            if (!f(sum + data[l])) {
                while (l < seg_size) {
                    l = 2 * l;
                    if (f(sum + data[l])) sum = sum + data[l++];
                }
                return l - seg_size;
            }
            sum = sum + data[l++];
        } while ((l & -l) != l);
        return internal_size;
    }

    template <class F> usize min_left(usize r, const F& f) const {
        assert(r <= internal_size);
        assert(f(M::zero()));
        if (r == 0) return 0;
        r += seg_size;
        M sum = M::zero();
        do {
            r -= 1;
            while (r > 1 and (r & 1)) r >>= 1;
            if (!f(data[r] + sum)) {
                while (r < seg_size) {
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
