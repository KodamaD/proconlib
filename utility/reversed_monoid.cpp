#pragma once

template <class Monoid> struct ReversedMonoid {
    using M = Monoid;
    using Self = ReversedMonoid;
    M raw;
    constexpr ReversedMonoid(const M& m): raw(m) {}
    static constexpr Self zero() { return Self(M::zero()); }
    constexpr Self operator+(const Self& other) const { return other.raw + raw; }
};
