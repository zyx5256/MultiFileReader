#ifndef MULTITHREADPROJ_TSV_FILE_HANDLER_H
#define MULTITHREADPROJ_TSV_FILE_HANDLER_H


#include <string>
#include <vector>
#include <memory>

class TsvFileHandler {
public:
    virtual ~TsvFileHandler() = default;
    virtual std::vector<std::string> readLines() = 0;
    virtual std::string readLine() = 0;
    virtual bool writeLine(const std::string& line) = 0;
    virtual bool writeLines(const std::vector<std::string>& lines) = 0;
};

std::unique_ptr<TsvFileHandler> createTsvFileHandler(const std::string& line);

#endif //MULTITHREADPROJ_TSV_FILE_HANDLER_H
