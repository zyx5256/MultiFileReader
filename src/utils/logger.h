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
    static void info(const std::string& content);
    static void warning(const std::string& content);
    static void error(const std::string& content);

private:
    static std::mutex mutex_;
};


#endif //MULTITHREADPROJ_LOGGER_H
