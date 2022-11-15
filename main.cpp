#include <iostream>
#include <thread>
#include <vector>


class A {
public:
    int func(int t) {
        std::vector<std::thread> threads;
        for (int i = 0; i < 1000; ++i) {
            std::thread td([&]() { func2(t); });
            threads.emplace_back(std::move(td));
        }

        for (std::thread& td : threads) {
            td.join();
        }
        return t;
    }

    int func3(int t) {
        std::thread td([&]() { func2(t); });
    }

private:
    void func2(int& t) {
        t++;
    }
};

int main() {
    int t = 0;
    A a;
    std::cout << a.func(t) << std::endl;

    return 0;
}
