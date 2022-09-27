#pragma once

#include <iostream>
#include <utility>

template <class T>
void print(T&& x) {
    std::cout << x;
}

template <class T, class... Args>
void print(T&& x, Args&&... args) {
    std::cout << x << ' ';
    print(std::forward<Args>(args)...);
}

void println() {
    std::cout << '\n';
}

template <class... Args>
void println(Args&&... args) {
    print(std::forward<Args>(args)...);
    std::cout << '\n';
}

template <class C>
void print_seq(C&& c, const char* sep = " ", const char* end = "\n") {
    bool f = false;
    for (auto&& x : c) {
        if (f) {
            std::cout << sep;
        } else {
            f = true;
        }
        std::cout << x;
    }
    std::cout << end;
}