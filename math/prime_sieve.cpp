#pragma once
#include <cassert>
#include <numeric>
#include <utility>
#include <vector>
#include "../utility/auto_realloc.cpp"
#include "../utility/rep.cpp"

struct PrimeSieve {
    static inline const auto min_prime = auto_realloc([](const int n) {
        std::vector<int> ret(n);
        std::iota(ret.begin(), ret.end(), (int)0);
        std::vector<int> list;
        for (const int i : rep(2, n)) {
            if (ret[i] == i) list.push_back(i);
            for (const int p : list) {
                if (p * i >= n || p > ret[i]) break;
                ret[p * i] = p;
            }
        }
        return ret;
    });
    static bool is_prime(const int n) {
        if (n <= 1) return false;
        return min_prime[n] == n;
    }
    template <class T> static std::vector<std::pair<T, int>> factorize(T x) {
        assert(x > 0);
        std::vector<std::pair<T, int>> ret;
        while (x != 1) {
            const int p = min_prime[x];
            ret.emplace_back((T)p, 0);
            while (min_prime[x] == p) {
                ret.back().second++;
                x /= p;
            }
        }
        return ret;
    }
};
