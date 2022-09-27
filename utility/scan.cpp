#pragma once
#include <array>
#include <cassert>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

template <class T>
T scan() {
    T x;
    std::cin >> x;
    return x;
}

template <class T>
std::vector<T> scan_vec(int n = -1) {
    if (n == -1)
        std::cin >> n;
    assert(n >= 0);
    std::vector<T> v(n);
    for (auto& x : v)
        std::cin >> x;
    return v;
}

template <class T, int N>
std::array<T, N> scan_array() {
    std::array<T, N> a;
    for (auto& x : a)
        std::cin >> x;
    return a;
}

std::vector<char> scan_chars() {
    std::string s;
    std::cin >> s;
    return std::vector<char>(std::cbegin(s), std::cend(s));
}
