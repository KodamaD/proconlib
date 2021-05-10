#pragma once
#include <vector>
#include <utility>
#include <array>
#include <algorithm>
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"
#include "../utility/revrep.cpp"
#include "../bit/ceil_log2.cpp"
#include "../bit/bit_rzeros.cpp"
#include "../bit/bit_reverse.cpp"
#include "../math/primitive_root.cpp"

template <class M, bool INV = false>
void modulo_transform(std::vector<M>& f) {
    static constexpr u32 MOD = M::mod();
    static constexpr u32 ROOT = primitive_root(MOD);
    static constexpr usize LEVEL = bit_rzeros(MOD - 1);
    static constexpr auto COEFF = [] {
        std::array<M, LEVEL> ret{};
        ret[LEVEL - 1] = M(ROOT).pow((MOD - 1) >> LEVEL);
        if (INV) ret[LEVEL - 1] = ret[LEVEL - 1].inv();
        for (const usize i: revrep(1, LEVEL)) {
            ret[i - 1] = ret[i] * ret[i];
        }
        return ret;
    }();
    const usize size = f.size();
    const usize logn = bit_rzeros(size);
    for (const usize i: rep(0, size)) {
        const usize j = bit_reverse(i) >> (64 - logn);
        if (i < j) std::swap(f[i], f[j]);
    }
    for (const usize s: rep(0, logn)) {
        const usize mh = (usize) 1 << s;
        const usize m = mh << 1;
        for (usize i = 0; i < size; i += m) {
            M coeff = M(1);
            for (const usize j: rep(i, i + mh)) {
                const M a = f[j];
                const M b = f[j + mh] * coeff;
                f[j] = a + b;
                f[j + mh] = a - b;
                coeff *= COEFF[s];
            }
        }
    }
}

template <class M>
std::vector<M> convolution(const std::vector<M>& a, const std::vector<M>& b) {
    const usize min = std::min(a.size(), b.size());
    if (min == 0) return { };
    if (min <= 60) {
        std::vector<M> ret(a.size() + b.size() - 1, M(0));
        for (const usize i: rep(0, a.size()))
            for (const usize j: rep(0, b.size()))
                ret[i + j] += a[i] * b[j];
        return ret;
    }
    const usize size = (usize) 1 << ceil_log2(a.size() + b.size() - 1);
    std::vector<M> f(size, M(0)), g(size, M(0));
    std::copy(a.cbegin(), a.cend(), f.begin());
    std::copy(b.cbegin(), b.cend(), g.begin());
    modulo_transform(f);
    modulo_transform(g);
    for (const usize i: rep(0, size)) f[i] *= g[i];
    modulo_transform<M, true>(f);
    f.resize(a.size() + b.size() - 1);
    const M inv = M(size).inv();
    for (auto& x: f) x *= inv;
    return f;
}