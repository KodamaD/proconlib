#pragma once
#include <array>
#include <cassert>
#include <initializer_list>
#include <vector>
#include "../utility/int_alias.cpp"
#include "../utility/rep.cpp"

template <class S> class SemiRingMatrix {
    using T = typename S::Type;
    using A = typename S::Sum;
    using M = typename S::Product;
    using Self = SemiRingMatrix;
    std::vector<std::vector<T>> data;

  public:
    SemiRingMatrix() = default;
    explicit SemiRingMatrix(const int h, const int w, const T& val = A::zero()) : data(h, std::vector<T>(w, val)) {}

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
        assert(0 <= i and i < height());
        assert(0 <= j and j < width());
        return data[i][j];
    }
    const T& operator()(const int i, const int j) const {
        assert(0 <= i and i < height());
        assert(0 <= j and j < width());
        return data[i][j];
    }

    Self operator+(const Self& other) const { return Self(*this) += other; }
    Self& operator+=(const Self& other) {
        assert(height() == other.height());
        assert(width() == other.width());
        for (const int i : rep(height()))
            for (const int j : rep(width())) data[i][j] = A::operation(data[i][j], other.data[i][j]);
        return *this;
    }

    Self operator*(const Self& other) const {
        assert(width() == other.height());
        Self ret(height(), other.width(), A::identity());
        for (const int i : rep(height()))
            for (const int k : rep(width()))
                for (const int j : rep(other.width()))
                    ret.data[i][j] = A::operation(ret.data[i][j], M::operation(data[i][k], other.data[k][j]));
        return ret;
    }

    Self operator*(const T& other) const { return Self(*this) *= other; }
    Self& operator*=(const T& other) {
        for (const int i : rep(height()))
            for (const int j : rep(width())) data[i][j] = M::operation(data[i][j], other);
    }

    Self pow(u64 exp) const {
        assert(height() == width());
        Self ret(height(), width(), A::identity()), mult(*this);
        for (const int i : rep(height())) ret.data[i][i] = M::identity();
        for (; exp > 0; exp >>= 1) {
            if (exp & 1) ret = ret * mult;
            mult = mult * mult;
        }
        return ret;
    }
};
