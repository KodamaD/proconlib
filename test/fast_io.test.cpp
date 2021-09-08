#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"
#include "../utility/int_alias.cpp"
#include "../utility/fast_io.cpp"

fast_io::Scanner input;
fast_io::Printer output;

int main() {
    usize N;
    input.scan(N);
    while (N--) {
        u64 a, b;
        input.scan(a, b);
        output.println(a + b);
    }
}