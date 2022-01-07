#pragma once
#include <algorithm>
#include <numeric>
#include <variant>
#include <vector>

class PermutationScanner {
    struct Iter {
        bool f;
        std::vector<int> v;
        explicit Iter(const int n, const int k) noexcept : f(true), v(n) { std::iota(v.begin(), v.end(), k); }
        bool operator!=(std::monostate) const noexcept { return f; }
        void operator++() noexcept { f = std::next_permutation(v.begin(), v.end()); }
        const std::vector<int>& operator*() noexcept { return v; }
    };
    Iter iter;

  public:
    explicit PermutationScanner(const int n, const int k = 0) noexcept : iter(n, k) {}
    Iter begin() const noexcept { return iter; }
    std::monostate end() const noexcept { return {}; }
};

PermutationScanner permutations(const int n, const int k = 0) noexcept { return PermutationScanner(n, k); }
