#pragma once
#include "../traits/reversed_monoid.cpp"
#include "stack_aggregation.cpp"

template <class M> class QueueAggregation {
    using T = typename M::Type;
    using R = ReversedMonoid<M>;

    StackAggregation<R> front_st;
    StackAggregation<M> back_st;

  public:
    QueueAggregation() = default;

    bool empty() const { return front_st.empty(); }
    T fold() const { return M::operation(front_st.fold(), back_st.fold()); }

    void push(const T& x) {
        if (empty())
            front_st.push(x);
        else
            back_st.push(x);
    }
    void pop() {
        assert(!empty());
        front_st.pop();
        if (front_st.empty()) {
            while (!back_st.empty()) {
                front_st.push(back_st.top());
                back_st.pop();
            }
        }
    }
};
