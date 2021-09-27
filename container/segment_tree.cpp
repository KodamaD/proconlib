#pragma once
#include <cassert>
#include <vector>
#include "../bit/ceil_log2.cpp"
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"
#include "../utility/revrep.cpp"

template <class M> class SegmentTree {
    using T = typename M::Type;
    usize internal_size, seg_size;
    std::vector<T> data;

    void fetch(const usize k) { data[k] = M::operation(data[2 * k], data[2 * k + 1]); }

  public:
    explicit SegmentTree(const usize size = 0, const T& value = M::identity())
        : SegmentTree(std::vector<T>(size, value)) {}
    explicit SegmentTree(const std::vector<T>& vec) : internal_size(vec.size()) {
        seg_size = 1 << ceil_log2(internal_size);
        data = std::vector<T>(2 * seg_size, M::identity());
        for (const usize i : rep(0, internal_size)) data[seg_size + i] = vec[i];
        for (const usize i : revrep(1, seg_size)) fetch(i);
    }

    usize size() const { return internal_size; }

    void assign(usize i, const T& value) {
        assert(i < internal_size);
        i += seg_size;
        data[i] = value;
        while (i > 1) {
            i >>= 1;
            fetch(i);
        }
    }

    T fold() const { return data[1]; }
    T fold(usize l, usize r) const {
        assert(l <= r and r <= internal_size);
        l += seg_size;
        r += seg_size;
        T ret_l = M::identity(), ret_r = M::identity();
        while (l < r) {
            if (l & 1) ret_l = M::operation(ret_l, data[l++]);
            if (r & 1) ret_r = M::operation(data[--r], ret_r);
            l >>= 1;
            r >>= 1;
        }
        return M::operation(ret_l, ret_r);
    }

    template <class F> usize max_right(usize l, const F& f) const {
        assert(l <= internal_size);
        assert(f(M::identity()));
        if (l == internal_size) return internal_size;
        l += seg_size;
        T sum = M::identity();
        do {
            while (!(l & 1)) l >>= 1;
            if (!f(M::operation(sum, data[l]))) {
                while (l < seg_size) {
                    l = 2 * l;
                    if (f(M::operation(sum, data[l]))) sum = M::operation(sum, data[l++]);
                }
                return l - seg_size;
            }
            sum = M::operation(sum, data[l++]);
        } while ((l & -l) != l);
        return internal_size;
    }

    template <class F> usize min_left(usize r, const F& f) const {
        assert(r <= internal_size);
        assert(f(M::identity()));
        if (r == 0) return 0;
        r += seg_size;
        T sum = M::identity();
        do {
            r -= 1;
            while (r > 1 and (r & 1)) r >>= 1;
            if (!f(M::operation(data[r], sum))) {
                while (r < seg_size) {
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
