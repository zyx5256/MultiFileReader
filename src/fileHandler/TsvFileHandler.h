#ifndef MULTI_THREAD_PROJ_TSV_FILE_HANDLER_H
#define MULTI_THREAD_PROJ_TSV_FILE_HANDLER_H


#include <string>
#include <vector>
#include <memory>

class TsvFileHandler {
public:
    virtual ~TsvFileHandler() = default;
    virtual std::vector<std::string> ReadLines() = 0;
    virtual std::string ReadLine() = 0;
    virtual bool WriteLine(const std::string& line) = 0;
    virtual bool WriteLines(const std::vector<std::string>& lines) = 0;
};

std::unique_ptr<TsvFileHandler> CreateTsvFileHandler(const std::string& line);

#endif //MULTI_THREAD_PROJ_TSV_FILE_HANDLER_H
