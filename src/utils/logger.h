#ifndef MULTITHREADPROJ_LOGGER_H
#define MULTITHREADPROJ_LOGGER_H


#include <mutex>

enum Level {
    INFO,
    WARNING,
    ERROR,
};

extern Level LOG_LEVEL;

class Logger {
public:
    Logger() = delete;
    static void print(const std::stringstream& content);

private:
    static std::mutex mutex_;
};


#endif //MULTITHREADPROJ_LOGGER_H
