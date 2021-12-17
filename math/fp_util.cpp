#pragma once
#include <cassert>
#include <vector>

template <class M> struct FpUtil {
    static M fact(const int n) {
        static std::vector<M> vec;
        assert(n >= 0);
        if (vec.empty()) vec = {M(1)};
        while ((int)vec.size() <= n) vec.push_back(vec.back() * M(n));
        return vec[n];
    }
    static M inv(const int n) {
        static std::vector<M> vec;
        assert(n > 0);
        if (vec.empty()) vec = {M(0), M(1)};
        while ((int)vec.size() <= n) vec.push_back(-M(M::mod() / n) * vec[M::mod() % n]);
        return vec[n];
    }
    static M inv_fact(const int n) {
        static std::vector<M> vec;
        assert(n >= 0);
        if (vec.empty()) vec = {M(1)};
        while ((int)vec.size() <= n) vec.push_back(vec.back() * inv(n));
        return vec[n];
    }
    static M binom(const int n, const int k) {
        assert(0 <= k and k <= n);
        return fact(n) * inv_fact(n - k) * inv_fact(k);
    }
    static M factpow(const int n, const int k) {
        assert(0 <= k and k <= n);
        return fact(n) * inv_fact(n - k);
    }
    static M homo(const int n, const int k) {
        assert((n == 0 and k == 0) or (n > 0 and k >= 0));
        if (n == 0 and k == 0) return M(1);
        return binom(n + k - 1, k);
    }
};
