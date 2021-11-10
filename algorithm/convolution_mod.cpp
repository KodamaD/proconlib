#pragma once
#include <algorithm>
#include <vector>
#include "../bit/ceil_log2.cpp"
#include "../math/modulo_transform.cpp"
#include "../math/static_modint.cpp"
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"

template <class T> std::vector<T> convolution_naive(const std::vector<T>& a, const std::vector<T>& b) {
    const usize n = a.size(), m = b.size();
    std::vector<T> c(n + m - 1);
    if (n < m) {
        for (const usize j : rep(0, m))
            for (const usize i : rep(0, n)) c[i + j] += a[i] * b[j];
    } else {
        for (const usize i : rep(0, n))
            for (const usize j : rep(0, m)) c[i + j] += a[i] * b[j];
    }
    return c;
}

template <class M> std::vector<M> convolution_ntt(std::vector<M> a, std::vector<M> b) {
    static constexpr ModuloTransform<M> transform;
    const usize n = a.size(), m = b.size();
    const usize k = 1 << ceil_log2(n + m - 1);
    a.resize(k), b.resize(k);
    transform.butterfly(a);
    transform.butterfly(b);
    for (const usize i : rep(0, k)) a[i] *= b[i];
    transform.butterfly_inv(a);
    a.resize(n + m - 1);
    const M c = M(k).inv();
    for (const usize i : rep(0, n + m - 1)) a[i] *= c;
    return a;
}

template <class M> std::vector<M> convolution_mod(std::vector<M>&& a, std::vector<M>&& b) {
    const usize n = a.size(), m = b.size();
    if (n == 0 || m == 0) return {};
    if (std::min(n, m) <= 60) return convolution_naive(a, b);
    return convolution_ntt(std::move(a), std::move(b));
}

template <class M> std::vector<M> convolution_mod(const std::vector<M>& a, const std::vector<M>& b) {
    const usize n = a.size(), m = b.size();
    if (n == 0 || m == 0) return {};
    if (std::min(n, m) <= 60) return convolution_naive(a, b);
    return convolution_ntt(a, b);
}

template <class T, u32 MOD, std::enable_if_t<std::is_integral_v<T>>* = nullptr>
std::vector<T> convolution_mod(const std::vector<T>& a, const std::vector<T>& b) {
    const usize n = a.size(), m = b.size();
    if (n == 0 || m == 0) return {};
    using M = StaticModint<MOD>;
    std::vector<M> a2(n), b2(m);
    for (const usize i : rep(0, n)) a2[i] = a[i];
    for (const usize i : rep(0, m)) b2[i] = b[i];
    std::vector<M> c2 = convolution_mod(std::move(a2), std::move(b2));
    std::vector<T> c(n + m - 1);
    for (const usize i : rep(0, n + m - 1)) c[i] = c2[i].val();
    return c;
}