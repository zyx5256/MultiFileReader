#include <mutex>
#include "MsgGenerator.h"

class MsgGeneratorImpl : public MsgGenerator {
public:
    explicit MsgGeneratorImpl(const std::string& fileSource);
    ~MsgGeneratorImpl() override = default;
    void genMsg(std::queue<std::string>& container, int numOfWorkers) const override;
    void stopGen() override;

private:
    std::string fileSource_;
    volatile bool isGen_;
    std::mutex lock_;
};

MsgGeneratorImpl::MsgGeneratorImpl(const std::string& fileSource) {
    fileSource_ = fileSource;
}

void MsgGeneratorImpl::genMsg(std::queue<std::string> &container, int numOfWorkers) const {

}

void MsgGeneratorImpl::stopGen() {

}

std::unique_ptr<MsgGenerator> createMsgGenerator(const std::string& fileSource)
{
    return std::make_unique<MsgGeneratorImpl>(fileSource);
}