#pragma once
#include "../utility/int_alias.cpp"
#include <random>
#include <chrono>

u64 xorshift() {
    static u64 state = std::chrono::system_clock::now().time_since_epoch().count();
    state ^= state << 7;
    state ^= state >> 9;
    return state;
}
