#include <iostream>
#include <fstream>
#include "src/TsvFileHandler.h"



int main() {
    std::fstream file;
    file.open("/Users/zyx/GitHub/MultiThreading/ut/testData/test.tsv");
    if (file.is_open()) {
        std::cout << "file successfully opened." << std::endl;
        std::string line;
        getline(file, line);
        std::cout << line << std::endl;
    } else {
        std::cout << "open file failed." << std::endl;
    }
    return 0;
}
