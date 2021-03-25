#pragma once
#include "../utility/int_alias.cpp"
#include "rem_euclid.cpp"
#include "mod_inv.cpp"
#include <type_traits>
#include <ostream>
#include <cassert>

namespace dynamic_modint_internal {

struct Barret {
    u32 mod;
    u64 near_inv;
    explicit Barret(const u32 mod) noexcept: mod(mod), near_inv((u64) (-1) / mod + 1) { }
    u32 product(const u32 a, const u32 b) const noexcept {
        const u64 z = (u64) a * b;
        const u64 x = ((u128) z * near_inv) >> 64;
        const u32 v = z - x * mod;
        return v < mod ? v : v + mod;
    }
};

}

template <usize ID>
class DynamicModint {
    using Mint = DynamicModint;
    using Barret = dynamic_modint_internal::Barret;
    static inline Barret bt = Barret(1);
    u32 v;
public:
    static u32 mod() noexcept { return bt.mod; }
    static void set_mod(const u32 mod) noexcept {
        assert((u32) 1 <= mod and mod <= ((u32) 1 << 31));
        bt = Barret(mod);
    }

    template <class T, std::enable_if_t<std::is_signed_v<T> and std::is_integral_v<T>>* = nullptr>
    static T normalize(const T x) noexcept { return rem_euclid<i64>(x, mod()); }
    template <class T, std::enable_if_t<std::is_unsigned_v<T> and std::is_integral_v<T>>* = nullptr>
    static T normalize(const T x) noexcept { return x % mod(); }

    DynamicModint() noexcept: v(0) { }
    template <class T>
    explicit DynamicModint(const T x) noexcept: v(normalize(x)) { }
    template <class T>
    static Mint raw(const T x) noexcept {
        Mint ret;
        ret.v = x;
        return ret;
    }

    u32 get() const noexcept { return v; }
    Mint neg() const noexcept { return raw(v == 0 ? 0 : mod() - v); }
    Mint operator - () const noexcept { return neg(); }
    Mint inv() const noexcept { return raw(mod_inv(v, mod())); }
    Mint operator ~ () const noexcept { return inv(); }
    Mint pow(u64 exp) const noexcept {
        Mint ret(1), mult(*this);
        for (; exp > 0; exp >>= 1) {
            if (exp & 1) ret *= mult;
            mult *= mult;
        }
        return ret;
    }

    Mint operator + (const Mint& rhs) const noexcept { return Mint(*this) += rhs; }
    Mint& operator += (const Mint& rhs) noexcept {
        if ((v += rhs.v) >= mod()) v -= mod();
        return *this;
    }
    Mint operator - (const Mint& rhs) const noexcept { return Mint(*this) -= rhs; }
    Mint& operator -= (const Mint& rhs) noexcept {
        if (v < rhs.v) v += mod();
        v -= rhs.v;
        return *this;
    }
    Mint operator * (const Mint& rhs) const noexcept { return Mint(*this) *= rhs; }
    Mint& operator *= (const Mint& rhs) noexcept {
        v = bt.product(v, rhs.v);
        return *this;
    }
    Mint operator / (const Mint& rhs) const noexcept { return Mint(*this) /= rhs; }
    Mint& operator /= (const Mint& rhs) noexcept { 
        return *this *= rhs.inv();
    }
    bool operator == (const Mint& rhs) const noexcept { return v == rhs.v; }
    bool operator != (const Mint& rhs) const noexcept { return v != rhs.v; }
    friend std::ostream& operator << (std::ostream& stream, const Mint& rhs) { 
        return stream << rhs.v;
    }
};
