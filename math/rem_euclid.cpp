#pragma once

template <class T>
constexpr T rem_euclid(T value, const T& mod) {
    return (value %= mod) >= 0 ? value : value + mod;
}
