#pragma once
#include <ostream>
#include <type_traits>
#include "../math/rem_euclid.cpp"
#include "../math/totient.cpp"
#include "../utility/int_alias.cpp"

template <u32 MOD, std::enable_if_t<((u32)1 <= MOD and MOD <= ((u32)1 << 31))>* = nullptr> class StaticModint {
    using Self = StaticModint;

    static inline constexpr u32 PHI = totient(MOD);
    u32 v;

  public:
    static constexpr u32 mod() noexcept { return MOD; }

    template <class T, std::enable_if_t<std::is_integral_v<T>>* = nullptr>
    static constexpr T normalize(const T& x) noexcept {
        return rem_euclid<std::common_type_t<T, i64>>(x, MOD);
    }

    constexpr StaticModint() noexcept : v(0) {}
    template <class T> constexpr StaticModint(const T& x) noexcept : v(normalize(x)) {}
    template <class T> static constexpr Self raw(const T& x) noexcept {
        Self ret;
        ret.v = x;
        return ret;
    }

    constexpr u32 get() const noexcept { return v; }
    constexpr Self neg() const noexcept { return raw(v == 0 ? 0 : MOD - v); }
    constexpr Self inv() const noexcept { return pow(PHI - 1); }
    constexpr Self pow(u64 exp) const noexcept {
        Self ret(1), mult(*this);
        for (; exp > 0; exp >>= 1) {
            if (exp & 1) ret *= mult;
            mult *= mult;
        }
        return ret;
    }

    constexpr Self operator-() const noexcept { return neg(); }
    constexpr Self operator~() const noexcept { return inv(); }

    constexpr Self operator+(const Self& rhs) const noexcept { return Self(*this) += rhs; }
    constexpr Self& operator+=(const Self& rhs) noexcept {
        if ((v += rhs.v) >= MOD) v -= MOD;
        return *this;
    }

    constexpr Self operator-(const Self& rhs) const noexcept { return Self(*this) -= rhs; }
    constexpr Self& operator-=(const Self& rhs) noexcept {
        if (v < rhs.v) v += MOD;
        v -= rhs.v;
        return *this;
    }

    constexpr Self operator*(const Self& rhs) const noexcept { return Self(*this) *= rhs; }
    constexpr Self& operator*=(const Self& rhs) noexcept {
        v = (u64)v * rhs.v % MOD;
        return *this;
    }

    constexpr Self operator/(const Self& rhs) const noexcept { return Self(*this) /= rhs; }
    constexpr Self& operator/=(const Self& rhs) noexcept { return *this *= rhs.inv(); }

    constexpr bool operator==(const Self& rhs) const noexcept { return v == rhs.v; }
    constexpr bool operator!=(const Self& rhs) const noexcept { return v != rhs.v; }
    friend std::ostream& operator<<(std::ostream& stream, const Self& rhs) { return stream << rhs.v; }
};

using Modint1000000007 = StaticModint<1000000007>;
using Modint998244353 = StaticModint<998244353>;
