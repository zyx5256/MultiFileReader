#include <iostream>
#include <fstream>
#include "TsvFileHandler.h"

class TsvFileHandlerImpl : public TsvFileHandler {
public:
    explicit TsvFileHandlerImpl(const std::string& line);

    ~TsvFileHandlerImpl() override;

    std::vector<std::string> readLines() override;

    std::string readLine() override;

    bool writeLine(const std::string& line) override;

    bool writeLines(const std::vector<std::string>& lines) override;

private:
    std::string filePath_;
    std::fstream file_;
};

TsvFileHandlerImpl::~TsvFileHandlerImpl()
{
    if (file_.is_open()) {
        file_.close();
    }
}

TsvFileHandlerImpl::TsvFileHandlerImpl(const std::string& line)
{
    filePath_ = line;
}

std::vector<std::string> TsvFileHandlerImpl::readLines()
{
    std::vector<std::string> lines;
    std::string line;
    std::fstream file;
    file.open(filePath_);
    while (getline(file, line)) {
        line.erase(line.find_last_not_of(" \n\r\t") + 1);
        lines.emplace_back(line);
    }
    file.close();
    return lines;
}

std::string TsvFileHandlerImpl::readLine()
{
    if (!file_.is_open()) {
        file_.open(filePath_);
    }

    std::string line;
    if (!getline(file_, line)) {
        file_.close();
        throw std::out_of_range("no more lines to read");
    }
    return line.erase(line.find_last_not_of(" \n\r\t") + 1);
}

bool TsvFileHandlerImpl::writeLine(const std::string& line)
{
    std::cout << "Not Implemented yet." << std::endl;
    return false;
}

bool TsvFileHandlerImpl::writeLines(const std::vector<std::string>& lines)
{
    std::cout << "Not Implemented yet." << std::endl;
    return false;
}

std::unique_ptr<TsvFileHandler> createTsvFileHandler(const std::string& line)
{
    return std::make_unique<TsvFileHandlerImpl>(line);
}
