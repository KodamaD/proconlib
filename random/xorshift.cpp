#pragma once
#include <chrono>
#include <random>
#include "../utility/int_alias.cpp"

u64 xorshift() {
    static u64 state = std::chrono::system_clock::now().time_since_epoch().count();
    state ^= state << 7;
    state ^= state >> 9;
    return state;
}
