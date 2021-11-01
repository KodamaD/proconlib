#pragma once
#include <optional>
#include <type_traits>
#include <utility>
#include <vector>
#include "../math/inv_gcd.cpp"
#include "../math/rem_euclid.cpp"
#include "../utility/rep.cpp"

template <class T, class Result = T>
std::optional<std::pair<Result, Result>> congruence_equations(const std::vector<T>& m, const std::vector<T>& r) {
    using U = std::make_signed_t<Result>;
    assert(m.size() == r.size());
    const usize n = m.size();
    U r0 = 0, m0 = 1;
    for (const usize i : rep(0, n)) {
        assert(m[i] > 0);
        U r1 = rem_euclid(r[i], m[i]), m1 = m[i];
        if (m0 < m1) {
            std::swap(r0, r1);
            std::swap(m0, m1);
        }
        if (m0 % m1 == 0) {
            if (r0 % m1 != r1) return std::nullopt;
            continue;
        }
        const auto [g, inv_m] = inv_gcd(m0, m1);
        if ((r1 - r0) % g != 0) return std::nullopt;
        const U u1 = m1 / g;
        const U x = (r1 - r0) / g % u1 * inv_m % u1;
        r0 += x * m0;
        m0 *= u1;
        if (r0 < 0) r0 += m0;
    }
    return std::pair<Result, Result>(r0, m0);
}
