#ifndef MULTITHREADPROJ_MSGGENERATOR_H
#define MULTITHREADPROJ_MSGGENERATOR_H


#include <string>
#include <queue>
#include <memory>
#include <vector>

class MsgGenerator {
public:
    virtual ~MsgGenerator() = default;

    virtual void genMsg(std::queue<std::string>& container) const = 0;

    virtual void stopGen() = 0;
};

std::unique_ptr<MsgGenerator> createMsgGenerator(const std::vector<std::string>& fileSources);


#endif //MULTITHREADPROJ_MSGGENERATOR_H
