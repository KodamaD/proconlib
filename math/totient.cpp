#pragma once

template <class T> constexpr T totient(T x) {
    T ret = x;
    for (T i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            ret /= i;
            ret *= i - 1;
            while (x % i == 0) x /= i;
        }
    }
    if (x > 1) {
        ret /= x;
        ret *= x - 1;
    }
    return ret;
}