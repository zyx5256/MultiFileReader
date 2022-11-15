#include "MsgGenerator.h"
#include "../../src/fileHandler/TsvFileHandler.h"
#include <algorithm>
#include <mutex>

class MsgGeneratorImpl : public MsgGenerator {
public:
    explicit MsgGeneratorImpl(const std::vector<std::string>& fileSources);

    ~MsgGeneratorImpl() override = default;

    void genMsg(std::queue<std::string>& container) const override;

    void stopGen() override;

private:
    void genMsgTask(std::queue<std::string>& container, const std::string& fileSource) const;

private:
    std::vector<std::string> fileSources_;
    std::mutex mutex_;
};

MsgGeneratorImpl::MsgGeneratorImpl(const std::vector<std::string>& fileSources)
{
    fileSources_ = fileSources;
}

void MsgGeneratorImpl::genMsg(std::queue<std::string>& container) const
{
//    std::vector<std::thread> threads;
}

void MsgGeneratorImpl::stopGen()
{

}

void MsgGeneratorImpl::genMsgTask(std::queue<std::string>& container, const std::string& fileSource) const
{

}

std::unique_ptr<MsgGenerator> createMsgGenerator(const std::vector<std::string>& fileSources)
{
    return std::make_unique<MsgGeneratorImpl>(fileSources);
}