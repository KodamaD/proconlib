#pragma once
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"
#include "../random/rand_int.cpp"
#include "../utility/auto_realloc.cpp"
#include <vector>
#include <string>
#include <type_traits>
#include <cassert>

template <usize ID>
struct PolynomialHashHelper {
    static inline constexpr u64 MOD = ((u64) 1 << 61) - 1;
    static inline const u64 BASE = rand_int<u64>(0, MOD - 1);

    static constexpr u64 add(u64 a, const u64 b) { return (a += b) >= MOD ? a - MOD : a; }
    static constexpr u64 sub(u64 a, const u64 b) { return (a += MOD - b) >= MOD ? a - MOD : a; }
    static constexpr u64 mul(const u64 a, const u64 b) {
        u128 ret = (u128) a * b;
        ret = (ret >> 61) + (ret & MOD);
        return ret >= MOD ? ret - MOD : ret;
    }

    static inline const auto BASE_POW = AutoRealloc([](const usize n) {
        std::vector<u64> ret(n);
        ret[0] = 1;
        for (const usize i: rep(1, n)) {
            ret[i] = mul(ret[i - 1], BASE);
        }
        return ret;
    });
};

template <class T, usize ID = 0, std::enable_if_t<std::is_integral_v<T>>* = nullptr>
class PolynomialHash {
    using Helper = PolynomialHashHelper<ID>;

    std::vector<u64> hash;
    std::vector<T> data;

public:
    PolynomialHash(): PolynomialHash(std::vector<T>()) { }
    explicit PolynomialHash(const std::vector<T>& vec): data(vec) {
        const usize size = data.size();
        hash = std::vector<u64>(size + 1);
        for (const usize i: rep(0, size)) {
            assert(0 <= data[i]);
            assert((u64) data[i] < Helper::MOD);
            hash[i + 1] = Helper::add(Helper::mul(Helper::BASE, hash[i]), (u64) data[i]);
        }
    }

    usize size() const { return data.size(); }
    const std::vector<T>& get() const { return data; }

    u64 fold() const { return hash.back(); }
    u64 fold(const usize l, const usize r) const {
        assert(l <= r and r <= size());
        return Helper::sub(hash[r], Helper::mul(hash[l], Helper::BASE_POW[r - l]));
    }

    void concat(const PolynomialHash& other) {
        hash.reserve(hash.size() + other.size());
        u64 val = hash.back();
        for (const usize i: rep(0, other.size())) {
            val = Helper::mul(val, Helper::BASE);
            hash.push_back(Helper::add(val, other.hash[i + 1]));
        }
        data.reserve(data.size() + other.size());
        std::copy(other.data.cbegin(), other.data.cend(), std::back_inserter(data));
    }
};
