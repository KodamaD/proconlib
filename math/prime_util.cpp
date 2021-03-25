#pragma once
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"
#include "../utility/auto_realloc.cpp"
#include <vector>
#include <utility>
#include <numeric>
#include <cassert>

struct PrimeUtil {
    static inline auto min_prime = AutoRealloc([](const usize n) {
        std::vector<usize> ret(n);
        std::iota(ret.begin(), ret.end(), (usize) 0);
        std::vector<usize> list;
        for (const usize i: rep(2, n)) {
            if (ret[i] == i) list.push_back(i);
            for (const usize p: list) {
                if (p * i >= n || p > ret[i]) break;
                ret[p * i] = p;
            }
        }
        return ret;
    });
    static bool is_prime(const usize n) {
        if (n <= 1) return false;
        return min_prime[n] == n;
    }
    template <class T>
    static std::vector<std::pair<T, usize>> factorize(T x) {
        assert(x > 0);
        std::vector<std::pair<T, usize>> ret;
        while (x != 1) {
            const auto p = min_prime[x];
            ret.emplace_back((T) p, 0);
            while (min_prime[x] == p) {
                ret.back().second++;
                x /= p;
            }
        }
        return ret;
    }
};
