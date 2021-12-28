#pragma once
#include <vector>

namespace proconlib {

template <class T> class SimpleQueue {
    std::vector<T> payload;
    int pos;

  public:
    SimpleQueue() : payload(), pos(0) {}
    explicit SimpleQueue(const int n) : SimpleQueue() { reserve(n); }

    int size() const { return (int)payload.size() - pos; }
    bool empty() const { return size() == 0; }
    T& front() { return payload[pos]; }

    void push(const T& t) { payload.push_back(t); }
    void push(T&& t) { payload.push_back(std::move(t)); }
    void pop() { pos++; }

    void reserve(int n) { payload.reserve(n); }
    void clear() {
        payload.clear();
        pos = 0;
    }
};

}  // namespace proconlib
