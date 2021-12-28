#pragma once
#include <cassert>
#include <string>
#include <type_traits>
#include <vector>
#include "../random/rand_int.cpp"
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"

struct PolynomialHashOperations {
    static inline constexpr u64 MOD = ((u64)1 << 61) - 1;
    static constexpr u64 sum(u64 a, const u64 b) { return (a += b) >= MOD ? a - MOD : a; }
    static constexpr u64 difference(u64 a, const u64 b) { return (a += MOD - b) >= MOD ? a - MOD : a; }
    static constexpr u64 product(const u64 a, const u64 b) {
        u128 ret = (u128)a * b;
        ret = (ret >> 61) + (ret & MOD);
        return ret >= MOD ? ret - MOD : ret;
    }
};

template <int ID> struct PolynomialHashBase {
    static inline const u64 BASE = rand_int<u64>(0, MOD - 1);
    static u64 base_pow(const int n) {
        static std::vector<u64> vec;
        if (vec.empty()) vec = {1};
        while ((int)vec.size() <= n) vec.push_back(PolynomialHashOperations::product(vec.back(), BASE));
        return vec[n];
    }
};

template <class T, int ID = -1, std::enable_if_t<std::is_integral_v<T>>* = nullptr> class PolynomialHash {
    using Oper = PolynomialHashOperations;
    using Base = PolynomialHashBase<ID>;

    std::vector<u64> hash;
    std::vector<T> data;

  public:
    PolynomialHash() : PolynomialHash(std::vector<T>()) {}
    explicit PolynomialHash(const std::vector<T>& vec) : data(vec) {
        const int size = data.size();
        hash = std::vector<u64>(size + 1);
        for (const int i : rep(size)) {
            assert(0 <= data[i] and (u64) data[i] < Base::MOD);
            hash[i + 1] = Oper::sum(Oper::product(Base::BASE, hash[i]), (u64)data[i]);
        }
    }

    int size() const { return data.size(); }
    const std::vector<T>& get() const { return data; }

    u64 fold() const { return hash.back(); }
    u64 fold(const int l, const int r) const {
        assert(0 <= l and l <= r and r <= size());
        return Oper::difference(hash[r], Oper::product(hash[l], Base::base_pow[r - l]));
    }

    void concat(const PolynomialHash& other) {
        hash.reserve(hash.size() + other.size());
        u64 val = hash.back();
        for (const int i : rep(other.size())) {
            val = Oper::product(val, Base::BASE);
            hash.push_back(Oper::sum(val, other.hash[i + 1]));
        }
        data.reserve(data.size() + other.size());
        std::copy(other.data.cbegin(), other.data.cend(), std::back_inserter(data));
    }
};
