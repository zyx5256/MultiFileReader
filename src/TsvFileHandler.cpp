//
// Created by ZYX on 11/12/2022.
//

#include "TsvFileHandler.h"

class TsvFileHandlerImpl : public TsvFileHandler {
public:
    TsvFileHandlerImpl(const std::string& line);
    ~TsvFileHandlerImpl() override = 0;
    std::vector<std::string> ReadLines() override;
    std::string ReadLine() override;
    bool WriteLine(const std::string& line) override;
    bool WriteLines(const std::vector<std::string>& lines) override;

private:
    std::string filePath_;
};

TsvFileHandlerImpl::TsvFileHandlerImpl(const std::string &line) {
    filePath_ = line;
}

std::unique_ptr<TsvFileHandler> CreateTsvFileHandler(const std::string& line)
{
    return std::make_unique<TsvFileHandlerImpl>(line);
}
