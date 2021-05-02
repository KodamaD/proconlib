#pragma once
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"
#include <vector>
#include <array>
#include <initializer_list>
#include <cassert>

template <class SemiRing>
class SemiRingMatrix {
    using Self = SemiRingMatrix;
    std::vector<std::vector<SemiRing>> data;

public:
    SemiRingMatrix() = default;
    explicit SemiRingMatrix(const usize h, const usize w, const SemiRing& val = SemiRing::zero()): data(h, std::vector<SemiRing>(w, val)) { }

    SemiRingMatrix(const std::vector<std::vector<SemiRing>>& vec): data(vec) { }
    SemiRingMatrix(const std::initializer_list<std::initializer_list<SemiRing>>& list) {
        data.reserve(list.size());
        for (const auto& v: list) {
            data.emplace_back(v.begin(), v.end());
        }
    }
    template <usize H, usize W>
    SemiRingMatrix(const std::array<std::array<SemiRing, W>, H>& arr) {
        data.reserve(H);
        for (const auto &v: arr) {
            data.emplace_back(v.begin(), v.end());
        }
    }

    usize height() const { return data.size(); }
    usize width() const { return data.empty() ? 0 : data[0].size(); }

    SemiRing& operator () (const usize i, const usize j) {
        assert(i < height());
        assert(j < width());
        return data[i][j];
    }
    const SemiRing& operator () (const usize i, const usize j) const {
        assert(i < height());
        assert(j < width());
        return data[i][j];
    }

    Self operator + (const Self& other) const { return Self(*this) += other; }
    Self& operator += (const Self& other) {
        assert(height() == other.height());
        assert(width() == other.width());
        for (const usize i: rep(0, height())) {
            for (const usize j: rep(0, width())) {
                data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return *this;
    }

    Self operator * (const Self& other) const {
        assert(width() == other.height());
        Self ret(height(), other.width(), SemiRing::zero());
        for (const usize i: rep(0, height())) {
            for (const usize k: rep(0, width())) {
                for (const usize j: rep(0, other.width())) {
                    ret.data[i][j] = ret.data[i][j] + data[i][k] * other.data[k][j];
                }
            }
        }
        return ret;
    }

    Self operator * (const SemiRing& other) const { return Self(*this) *= other; }
    Self& operator *= (const SemiRing& other) {
        for (const usize i: rep(0, height())) {
            for (const usize j: rep(0, width())) {
                data[i][j] = data[i][j] * other;
            }
        }
    }

    Self pow(u64 exp) const {
        assert(height() == width());
        Self ret(height(), width(), SemiRing::zero()), mult(*this);
        for (const usize i: rep(0, height())) {
            ret.data[i][i] = SemiRing::one();
        }
        for (; exp > 0; exp >>= 1) {
            if (exp & 1) ret = ret * mult;
            mult = mult * mult;
        }
        return ret;
    }
};
