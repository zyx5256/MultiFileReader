#include "logger.h"
#include <sstream>
#include <unordered_map>

namespace {
std::unordered_map<Level, std::string> LOG_NAME_MAP {
    {INFO, "[INFO]"},
    {WARNING, "[WARNING]"},
    {ERROR, "[ERROR]"},
};
}

void Logger::print(const std::stringstream& content)
{
    printf("%s%s\n", &LOG_NAME_MAP[LOG_LEVEL][0], &content.str()[0]);
}


