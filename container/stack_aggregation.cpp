#pragma once
#include <cassert>
#include <vector>

template <class M> class StackAggregation {
    using T = typename M::Type;

    struct Node {
        T value, fold;
        explicit Node(const T value, const T fold) : value(value), fold(fold) {}
    };

    std::vector<Node> st;

  public:
    StackAggregation() = default;

    bool empty() const { return st.empty(); }
    T top() const {
        assert(!empty());
        return st.back().value;
    }
    T fold() const { return st.empty() ? M::identity() : st.back().fold; }

    void push(const T& x) { st.emplace_back(x, M::operation(fold(), x)); }
    void pop() {
        assert(!empty());
        st.pop_back();
    }
};
