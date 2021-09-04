#pragma once
#include <type_traits>
#include <utility>
#include "../math/rem_euclid.cpp"

template <class T> constexpr std::pair<T, T> inv_gcd(const T& a, const T& b) {
    using U = std::make_signed_t<T>;
    U t = rem_euclid(a, b);
    if (t == 0) return {b, 0};
    U s = b, m0 = 0, m1 = 1;
    while (t != 0) {
        const U u = s / t;
        s -= t * u;
        m0 -= m1 * u;
        U tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    if (m0 < 0) m0 += b / s;
    return {(T)s, (T)m0};
}
