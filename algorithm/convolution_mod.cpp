#pragma once
#include <algorithm>
#include <vector>
#include "../internal/modulo_transform.cpp"
#include "../math/static_modint.cpp"
#include "../utility/ceil_log2.cpp"
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"

namespace proconlib {

template <class T> std::vector<T> convolution_naive(const std::vector<T>& a, const std::vector<T>& b) {
    const int n = a.size(), m = b.size();
    std::vector<T> c(n + m - 1);
    if (n < m) {
        for (const int j : rep(m))
            for (const int i : rep(n)) c[i + j] += a[i] * b[j];
    } else {
        for (const int i : rep(n))
            for (const int j : rep(m)) c[i + j] += a[i] * b[j];
    }
    return c;
}

template <class M> std::vector<M> convolution_ntt(std::vector<M> a, std::vector<M> b) {
    constexpr ModuloTransform<M> transform;
    const int n = a.size(), m = b.size();
    const int k = 1 << ceil_log2(n + m - 1);
    a.resize(k), b.resize(k);
    transform.butterfly(a);
    transform.butterfly(b);
    for (const int i : rep(k)) a[i] *= b[i];
    transform.butterfly_inv(a);
    a.resize(n + m - 1);
    const M c = M(k).inv();
    for (const int i : rep(n + m - 1)) a[i] *= c;
    return a;
}

}  // namespace proconlib

template <class M> std::vector<M> convolution_mod(std::vector<M>&& a, std::vector<M>&& b) {
    const int n = a.size(), m = b.size();
    if (n == 0 || m == 0) return {};
    if (std::min(n, m) <= 60) return proconlib::convolution_naive(a, b);
    return proconlib::convolution_ntt(std::move(a), std::move(b));
}

template <class M> std::vector<M> convolution_mod(const std::vector<M>& a, const std::vector<M>& b) {
    const int n = a.size(), m = b.size();
    if (n == 0 || m == 0) return {};
    if (std::min(n, m) <= 60) return proconlib::convolution_naive(a, b);
    return proconlib::convolution_ntt(a, b);
}

template <class T, u32 MOD, std::enable_if_t<std::is_integral_v<T>>* = nullptr>
std::vector<T> convolution_mod(const std::vector<T>& a, const std::vector<T>& b) {
    const int n = a.size(), m = b.size();
    if (n == 0 || m == 0) return {};
    using M = StaticModint<MOD>;
    std::vector<M> a2(n), b2(m);
    for (const int i : rep(n)) a2[i] = a[i];
    for (const int i : rep(m)) b2[i] = b[i];
    std::vector<M> c2 = convolution_mod(std::move(a2), std::move(b2));
    std::vector<T> c(n + m - 1);
    for (const int i : rep(n + m - 1)) c[i] = c2[i].val();
    return c;
}