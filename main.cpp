#include <iostream>
#include <thread>
#include <vector>



int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i) {
        std::thread td([&](){ printf("hello_my_boy\n");});
        threads.emplace_back(std::move(td));
    }

    for (std::thread& td : threads) {
        td.join();
    }
    return 0;
}
