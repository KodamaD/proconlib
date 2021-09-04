#pragma once
#include <algorithm>
#include <numeric>
#include <variant>
#include <vector>
#include "../utility/int_alias.cpp"

class permutations {
    struct Iter {
        bool f;
        std::vector<usize> v;
        explicit Iter(const usize n, const usize k) noexcept : f(true), v(n) { std::iota(v.begin(), v.end(), k); }
        bool operator!=(std::monostate) const noexcept { return f; }
        void operator++() noexcept { f = std::next_permutation(v.begin(), v.end()); }
        const std::vector<usize>& operator*() noexcept { return v; }
    };
    Iter iter;

  public:
    explicit permutations(const usize n, const usize k = 0) noexcept : iter(n, k) {}
    Iter begin() const noexcept { return iter; }
    std::monostate end() noexcept { return {}; }
};
