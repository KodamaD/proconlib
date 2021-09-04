#pragma once
#include "../container/stack_aggregation.cpp"
#include "../utility/reversed_monoid.cpp"

template <class Monoid> class QueueAggregation {
    using M = Monoid;

    StackAggregation<ReversedMonoid<M>> front_st;
    StackAggregation<M> back_st;

  public:
    QueueAggregation() = default;

    bool empty() const { return front_st.empty(); }
    M fold() const { return front_st.fold().raw + back_st.fold(); }

    void push(const M& x) {
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
