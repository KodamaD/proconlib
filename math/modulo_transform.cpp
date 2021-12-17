#pragma once
#include <array>
#include <vector>
#include "../utility/countr_zero.cpp"
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"
#include "../utility/revrep.cpp"
#include "primitive_root.cpp"

template <class M> struct ModuloTransform {
    static constexpr u32 ROOT = primitive_root(M::mod());
    static constexpr int RANK = countr_zero(M::mod() - 1);

    std::array<M, RANK + 1> root, iroot;
    std::array<M, (RANK >= 2 ? RANK - 2 + 1 : 0)> rate2, irate2;
    std::array<M, (RANK >= 3 ? RANK - 3 + 1 : 0)> rate3, irate3;

    constexpr ModuloTransform() : root(), iroot(), rate2(), irate2(), rate3(), irate3() {
        root[RANK] = M(ROOT).pow((M::mod() - 1) >> RANK);
        iroot[RANK] = root[RANK].inv();
        for (const int i : revrep(0, RANK)) {
            root[i] = root[i + 1] * root[i + 1];
            iroot[i] = iroot[i + 1] * iroot[i + 1];
        }
        M prod = 1, iprod = 1;
        for (const int i : rep(2, RANK + 1)) {
            rate2[i - 2] = root[i] * prod;
            irate2[i - 2] = iroot[i] * iprod;
            prod *= iroot[i];
            iprod *= root[i];
        }
        prod = 1, iprod = 1;
        for (const int i : rep(3, RANK + 1)) {
            rate3[i - 3] = root[i] * prod;
            irate3[i - 3] = iroot[i] * iprod;
            prod *= iroot[i];
            iprod *= root[i];
        }
    }

    void butterfly(std::vector<M>& a) const {
        const int n = a.size();
        const int h = countr_zero(n);
        for (int len = 0; len < h;) {
            if (len + 1 == h) {
                M rot = 1;
                for (const int s : rep(0, 1 << len)) {
                    const int t = s << 1;
                    const M l = a[t], r = a[t + 1] * rot;
                    a[t] = l + r;
                    a[t + 1] = l - r;
                    if (((s + 1) >> len) == 0) rot *= rate2[countr_zero(~s)];
                }
                len += 1;
            } else {
                const int p = 1 << (h - len - 2);
                M rot = 1;
                for (const int s : rep(0, 1 << len)) {
                    const int t = s << (h - len);
                    const M rot2 = rot * rot;
                    const M rot3 = rot2 * rot;
                    for (const int i : rep(0, p)) {
                        const M a0 = a[i + t];
                        const M a1 = a[i + t + p] * rot;
                        const M a2 = a[i + t + p * 2] * rot2;
                        const M a3 = a[i + t + p * 3] * rot3;
                        const M ax = (a1 - a3) * root[2];
                        a[i + t] = a0 + a1 + a2 + a3;
                        a[i + t + p] = a0 - a1 + a2 - a3;
                        a[i + t + p * 2] = a0 - a2 + ax;
                        a[i + t + p * 3] = a0 - a2 - ax;
                    }
                    if (((s + 1) >> len) == 0) rot *= rate3[countr_zero(~s)];
                }
                len += 2;
            }
        }
    }

    void butterfly_inv(std::vector<M>& a) const {
        const int n = a.size();
        const int h = countr_zero(n);
        for (int len = h; len > 0;) {
            if (len == 1) {
                const int p = n >> 1;
                for (const int i : rep(0, p)) {
                    const M l = a[i], r = a[i + p];
                    a[i] = l + r;
                    a[i + p] = l - r;
                }
                len -= 1;
            } else {
                const int p = 1 << (h - len);
                M rot = 1;
                for (const int s : rep(0, 1 << (len - 2))) {
                    const int t = s << (h - len + 2);
                    const M rot2 = rot * rot;
                    const M rot3 = rot2 * rot;
                    for (const int i : rep(0, p)) {
                        const M a0 = a[i + t];
                        const M a1 = a[i + t + p];
                        const M a2 = a[i + t + p * 2];
                        const M a3 = a[i + t + p * 3];
                        const M ax = (a2 - a3) * iroot[2];
                        a[i + t] = a0 + a1 + a2 + a3;
                        a[i + t + p] = (a0 - a1 + ax) * rot;
                        a[i + t + p * 2] = (a0 + a1 - a2 - a3) * rot2;
                        a[i + t + p * 3] = (a0 - a1 - ax) * rot3;
                    }
                    if (((s + 1) >> (len - 2)) == 0) rot *= irate3[countr_zero(~s)];
                }
                len -= 2;
            }
        }
    }
};
