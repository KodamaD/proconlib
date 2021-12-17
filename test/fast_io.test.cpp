#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"
#include "../utility/int_alias.cpp"
#include "../utility/fast_io.cpp"

fast_io::Scanner input;
fast_io::Printer output;

int main() {
    int n;
    input.scan(n);
    while (n--) {
        u64 a, b;
        input.scan(a, b);
        output.println(a + b);
    }
}