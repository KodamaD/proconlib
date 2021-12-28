#pragma once
#include <vector>

template <class Cont> decltype(auto) collect(const Cont& c) {
    std::vector<decltype(*std::declval<Cont>().begin())> ret;
    for (const auto& x : c) ret.push_back(x);
    return ret;
}

template <class Cont> decltype(auto) collect(Cont&& c) {
    std::vector<decltype(*std::declval<Cont>().begin())> ret;
    for (auto&& x : c) ret.push_back(std::move(x));
    return ret;
}