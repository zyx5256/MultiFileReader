#include <iostream>
#include <thread>
#include <vector>
#include "src/utils/Log.h"

Level LOG_LEVEL = Level::WARNING;

int main() {
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i) {
        std::thread td([&](){ LOG::INFO("good");LOG::WARNING("oh my god");});
        threads.emplace_back(std::move(td));
    }

    for (std::thread& td : threads) {
        td.join();
    }
    return 0;
}
