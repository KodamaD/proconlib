#pragma once
#include <array>
#include <cassert>
#include <initializer_list>
#include <vector>
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"

template <class S> class SemiRingMatrix {
    using T = typename S::Type;
    using Self = SemiRingMatrix;
    std::vector<std::vector<T>> data;

  public:
    SemiRingMatrix() = default;
    explicit SemiRingMatrix(const int h, const int w, const T& val = S::zero()) : data(h, std::vector<T>(w, val)) {}

    SemiRingMatrix(const std::vector<std::vector<T>>& vec) : data(vec) {
        for (const auto& v : data) assert(v.size() == width());
    }
    SemiRingMatrix(const std::initializer_list<std::initializer_list<T>>& list) {
        data.reserve(list.size());
        for (const auto& v : list) data.emplace_back(v.begin(), v.end());
        for (const auto& v : data) assert(v.size() == width());
    }

    int height() const { return data.size(); }
    int width() const { return data.empty() ? 0 : data[0].size(); }

    T& operator()(const int i, const int j) {
        assert(i < height());
        assert(j < width());
        return data[i][j];
    }
    const T& operator()(const int i, const int j) const {
        assert(i < height());
        assert(j < width());
        return data[i][j];
    }

    Self operator+(const Self& other) const { return Self(*this) += other; }
    Self& operator+=(const Self& other) {
        assert(height() == other.height());
        assert(width() == other.width());
        for (const int i : rep(0, height())) {
            for (const int j : rep(0, width())) {
                data[i][j] = S::sum(data[i][j], other.data[i][j]);
            }
        }
        return *this;
    }

    Self operator*(const Self& other) const {
        assert(width() == other.height());
        Self ret(height(), other.width(), S::zero());
        for (const int i : rep(0, height())) {
            for (const int k : rep(0, width())) {
                for (const int j : rep(0, other.width())) {
                    ret.data[i][j] = S::sum(ret.data[i][j], S::product(data[i][k], other.data[k][j]));
                }
            }
        }
        return ret;
    }

    Self operator*(const T& other) const { return Self(*this) *= other; }
    Self& operator*=(const T& other) {
        for (const int i : rep(0, height())) {
            for (const int j : rep(0, width())) {
                data[i][j] = S::product(data[i][j], other);
            }
        }
    }

    Self pow(u64 exp) const {
        assert(height() == width());
        Self ret(height(), width(), S::zero()), mult(*this);
        for (const int i : rep(0, height())) {
            ret.data[i][i] = S::one();
        }
        for (; exp > 0; exp >>= 1) {
            if (exp & 1) ret = ret * mult;
            mult = mult * mult;
        }
        return ret;
    }
};
