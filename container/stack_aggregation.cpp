#pragma once
#include <vector>
#include <cassert>

template <class Monoid> class StackAggregation {
    using M = Monoid;

    struct Node {
        M value, fold;
        explicit Node(const M value, const M fold) : value(value), fold(fold) {}
    };

    std::vector<Node> st;

  public:
    StackAggregation() = default;

    bool empty() const { return st.empty(); }
    M top() const {
        assert(!empty());
        return st.back().value;
    }
    M fold() const { return st.empty() ? M::zero() : st.back().fold; }

    void push(const M& x) { st.emplace_back(x, fold() + x); }
    void pop() {
        assert(!empty());
        st.pop_back();
    }
};
