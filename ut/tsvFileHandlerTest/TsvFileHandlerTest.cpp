#include "../../src/TsvFileHandler.h"
#include "gtest/gtest.h"

const std::string TEST_DATA_FILE_PATH = "/Users/zyx/GitHub/MultiThreading/ut/testData/test.tsv";

// test readline
TEST(TsvFileHandler_Test, readline_1)
{
    auto tsvFileHandler = CreateTsvFileHandler(TEST_DATA_FILE_PATH);
//    tsvFileHandler->ReadLine();
    std::string line = tsvFileHandler->ReadLine();
    ASSERT_STREQ(reinterpret_cast<const char*>(&line), "id\tquestion1\tquestion2");
}

int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}