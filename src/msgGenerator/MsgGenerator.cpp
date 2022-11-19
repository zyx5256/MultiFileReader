#include "MsgGenerator.h"
#include "../../src/fileHandler/TsvFileHandler.h"
#include "../../src/utils/Log.h"
#include <algorithm>
#include <mutex>
#include <thread>
#include <sstream>

class MsgGeneratorImpl : public MsgGenerator {
public:
    explicit MsgGeneratorImpl(const std::vector<std::string>& fileSources);

    ~MsgGeneratorImpl() override = default;

    void genMsg(std::queue<std::string>& container) override;

private:
    void genMsgTask(std::queue<std::string>& container, const std::string& fileSource);

private:
    std::vector<std::string> fileSources_;
    std::mutex mutex_;
};

MsgGeneratorImpl::MsgGeneratorImpl(const std::vector<std::string>& fileSources)
{
    fileSources_ = fileSources;
}

void MsgGeneratorImpl::genMsg(std::queue<std::string>& container)
{
    std::vector<std::thread> threads;
    for (const std::string& fileSource : fileSources_) {
        std::thread td([&](){genMsgTask(container, fileSource);});
        threads.emplace_back(std::move(td));
    }

    for (std::thread& td : threads) {
        td.join();
    }
}

void MsgGeneratorImpl::genMsgTask(std::queue<std::string>& container, const std::string& fileSource)
{
    std::stringstream ss;
    ss << "Thread " << std::this_thread::get_id() << " start running";

    LOG::INFO(ss.str());
    auto tsvFileHandlerPtr = createTsvFileHandler(fileSource);
    std::unique_lock<std::mutex> guard(mutex_, std::defer_lock);
    while (tsvFileHandlerPtr->hasNext()) {
        std::string line = tsvFileHandlerPtr->readLine();
        guard.lock();
        container.push(line);
        guard.unlock();
    }

    std::stringstream ss1;
    ss1 << "Thread " << std::this_thread::get_id() << " start running";
    LOG::INFO(ss1.str());
}

std::unique_ptr<MsgGenerator> createMsgGenerator(const std::vector<std::string>& fileSources)
{
    return std::make_unique<MsgGeneratorImpl>(fileSources);
}