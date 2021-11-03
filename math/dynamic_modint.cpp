#pragma once
#include <cassert>
#include <ostream>
#include <type_traits>
#include "../math/barret_reduction.cpp"
#include "../math/mod_inv.cpp"
#include "../math/rem_euclid.cpp"
#include "../utility/int_alias.cpp"

template <usize ID> class DynamicModint {
    using Self = DynamicModint;

    static inline auto bt = BarretReduction(1);
    u32 v;

  public:
    static u32 mod() noexcept { return bt.mod; }
    static void set_mod(const u32 mod) noexcept {
        assert((u32)1 <= mod and mod <= ((u32)1 << 31));
        bt = BarretReduction(mod);
    }

    template <class T, std::enable_if_t<std::is_integral_v<T>>* = nullptr> static T normalize(const T& x) noexcept {
        return rem_euclid<std::common_type_t<T, i64>>(x, mod());
    }

    DynamicModint() noexcept : v(0) {}
    template <class T> DynamicModint(const T& x) noexcept : v(normalize(x)) {}
    template <class T> static Self raw(const T& x) noexcept {
        Self ret;
        ret.v = x;
        return ret;
    }

    u32 val() const noexcept { return v; }
    Self neg() const noexcept { return raw(v == 0 ? 0 : mod() - v); }
    Self inv() const noexcept { return raw(mod_inv(v, mod())); }
    Self pow(u64 exp) const noexcept {
        Self ret(1), mult(*this);
        for (; exp > 0; exp >>= 1) {
            if (exp & 1) ret *= mult;
            mult *= mult;
        }
        return ret;
    }

    Self operator-() const noexcept { return neg(); }
    Self operator~() const noexcept { return inv(); }

    Self operator+(const Self& rhs) const noexcept { return Self(*this) += rhs; }
    Self& operator+=(const Self& rhs) noexcept {
        if ((v += rhs.v) >= mod()) v -= mod();
        return *this;
    }

    Self operator-(const Self& rhs) const noexcept { return Self(*this) -= rhs; }
    Self& operator-=(const Self& rhs) noexcept {
        if (v < rhs.v) v += mod();
        v -= rhs.v;
        return *this;
    }

    Self operator*(const Self& rhs) const noexcept { return Self(*this) *= rhs; }
    Self& operator*=(const Self& rhs) noexcept {
        v = bt.product(v, rhs.v);
        return *this;
    }

    Self operator/(const Self& rhs) const noexcept { return Self(*this) /= rhs; }
    Self& operator/=(const Self& rhs) noexcept { return *this *= rhs.inv(); }

    bool operator==(const Self& rhs) const noexcept { return v == rhs.v; }
    bool operator!=(const Self& rhs) const noexcept { return v != rhs.v; }
    friend std::ostream& operator<<(std::ostream& stream, const Self& rhs) { return stream << rhs.v; }
};

using Modint = DynamicModint<__COUNTER__>;
