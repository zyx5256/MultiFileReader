#include "../../src/TsvFileHandler.h"
#include "gtest/gtest.h"

const std::string TEST_DATA_FILE_PATH = "C:\\Users\\ZYX\\CLionProjects\\MultiThreadProj\\ut\\testData\\test.tsv";

// test readline
TEST(TsvFileHandler_Test, readline_1)
{
    auto tsvFileHandler = CreateTsvFileHandler(TEST_DATA_FILE_PATH);
    std::string line = tsvFileHandler->ReadLine();
    ASSERT_EQ(line, "id,question1,question2");
}

int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}