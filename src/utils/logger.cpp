#include "logger.h"
#include <iostream>

void Logger::info(const std::string& content)
{
    std::lock_guard<std::mutex> guard(mutex_);
    std::cout << "[INFO]" << content << std::endl;
}

void Logger::warning(const std::string& content)
{
    if (LOG_LEVEL == INFO) {
        return;
    }
    std::lock_guard<std::mutex> guard(mutex_);
    std::cout << "[WARNING]" << content << std::endl;
}

void Logger::error(const std::string& content)
{
    if (LOG_LEVEL == INFO || LOG_LEVEL == WARNING) {
        return;
    }
    std::lock_guard<std::mutex> guard(mutex_);
    std::cout << "[ERROR]" << content << std::endl;
}
