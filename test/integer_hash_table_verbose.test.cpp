#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
#include <cassert>
#include <vector>
#include <utility>
#include <memory>
#include "../container/integer_hash_table.cpp"

struct Object {
    static inline int CON = 0;
    static inline int DES = 0;
    Object() { CON += 1; }
    ~Object() { DES += 1; }
};

void test() {
    {
        IntegerHashTable<int, int> map;

        assert(map.insert(0, 3).second);
        assert(map.insert(1, 2).second);
        assert(!map.insert(0, 2).second);

        assert(map[0] == 3);
        assert(map[1] == 2);

        map[0] = 10;
        assert(map[0] == 10);

        for (int i = 2; i < 100; ++i) {
            map.insert(i, 2 * i);
        }
        assert(map.find(10));
        assert(map.erase(10));
        assert(!map.find(10));
        assert(map.size() == 99);

        const auto enumerate = [&](const IntegerHashTable<int, int>& m) {
            std::vector<std::pair<int, int>> ret;
            ret.reserve(m.size());
            for (const auto& [a, b] : m) {
                ret.emplace_back(a, b);
            }
            assert(ret.size() == m.size());
            std::sort(ret.begin(), ret.end());
            return ret;
        };

        const auto copy1 = map;
        assert(copy1.size() == 99);
        assert(copy1.find(0));
        assert(!copy1.find(10));
        assert(enumerate(map) == enumerate(copy1));

        IntegerHashTable<int, int> copy2(map);
        assert(copy2.size() == 99);
        assert(enumerate(map) == enumerate(copy2));

        auto move1 = std::move(map);
        assert(map.size() == 0);
        assert(map.empty());
        assert(enumerate(move1) == enumerate(copy1));

        IntegerHashTable<int, int> move2(std::move(move1));
        assert(move1.size() == 0);
        assert(move1.empty());
        assert(enumerate(move2) == enumerate(copy1));

        for (auto& [a, b] : move2) {
            b = -1;
        }
        assert(move2[0] == -1);
        assert(move2[1] == -1);
        assert(move2[2] == -1);
    }
    {
        {
            IntegerHashTable<int, std::unique_ptr<Object>> map;
            assert(map.insert(0, std::make_unique<Object>()).second);
            assert(!map.insert(0, std::make_unique<Object>()).second);
            assert(Object::CON == 2);
            assert(Object::DES == 1);

            map.clear();
            assert(Object::CON == 2);
            assert(Object::DES == 2);
        }

        IntegerHashTable<int, std::unique_ptr<Object>> map;
        for (int i = 0; i < 100; ++i) {
            map.insert(2 * i, std::make_unique<Object>());
        }
        assert(Object::CON == 102);
        assert(Object::DES == 2);

        auto next = std::move(map);
        assert(Object::CON == 102);
        assert(Object::DES == 2);
        assert(next.size() == 100);
        for (const auto& [a, b] : next) {
            assert(a % 2 == 0);
        }

        {
            const IntegerHashTable<int, std::unique_ptr<Object>> inside(std::move(next));
            assert(inside.size() == 100);
            assert(Object::CON == 102);
            assert(Object::DES == 2);
        }
        assert(Object::CON == 102);
        assert(Object::DES == 102);
    }
}

#include <iostream>

int main() {
    test();
    std::cout << "Hello World\n";
}