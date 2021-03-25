#pragma once
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"
#include "../utility/auto_realloc.cpp"
#include <vector>
#include <cassert>

template <class M>
struct ModintUtil {
    static inline auto fact = AutoRealloc([](const usize n) {
        std::vector<M> ret(n);
        ret[0] = M(1);
        for (const usize i: rep(1, n)) {
            ret[i] = ret[i - 1] * M(i);
        }
        return ret;
    });
    static inline auto inv = AutoRealloc([](const usize n) {
        std::vector<M> ret(n);
        if (n == 1) return ret;
        ret[1] = M(1);
        for (const usize i: rep(2, n)) {
            ret[i] = -M(M::mod() / i) * ret[M::mod() % i];
        }
        return ret;
    });
    static inline auto inv_fact = AutoRealloc([](const usize n) {
        std::vector<M> ret(n);
        ret[0] = M(1);
        for (const usize i: rep(1, n)) {
            ret[i] = ret[i - 1] * inv[i];
        }
        return ret;
    });
    static M binom(const usize n, const usize k) {
        assert(k <= n);
        return fact[n] * inv_fact[n - k] * inv_fact[k];
    }
    static M factpow(const usize n, const usize k) {
        assert(k <= n);
        return fact[n] * inv_fact[n - k];
    }
    static M homo(const usize n, const usize k) {
        if (n == 0 && k == 0) return M(1);
        return binom(n + k - 1, n);
    }
};
