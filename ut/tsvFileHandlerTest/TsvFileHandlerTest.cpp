#include "../../src/TsvFileHandler.h"
#include "gtest/gtest.h"


#ifdef __APPLE__
    const std::string TEST_DATA_FILE_PATH = "../ut/testData/test.tsv";
#else
    const std::string TEST_DATA_FILE_PATH = "..\\ut\\testData\\test.tsv";
#endif

// test read line
TEST(TsvFileHandler_Test, readline_1)
{
    auto tsvFileHandler = CreateTsvFileHandler(TEST_DATA_FILE_PATH);
    std::string line = tsvFileHandler->ReadLine();
    ASSERT_STREQ(static_cast<char *>(&line[0]), "id,sentence");
}

// test read last line
TEST(TsvFileHandler_Test, readline_2)
{
    auto tsvFileHandler = CreateTsvFileHandler(TEST_DATA_FILE_PATH);
    std::string line;
    for (int i = 0; i < 4; ++i) {
        line = tsvFileHandler->ReadLine();
    }
    ASSERT_STREQ(static_cast<char *>(&line[0]), "2,Why don't people simply 'Google' instead;");
}

// test exception
TEST(TsvFileHandler_Test, readline_3)
{
    auto tsvFileHandler = CreateTsvFileHandler(TEST_DATA_FILE_PATH);
    try {
        for (int i = 0; i < 40; ++i) {
            tsvFileHandler->ReadLine();
        }
    }
    catch( const std::out_of_range& err ) {
        // check exception
        ASSERT_STREQ(err.what(), "no more lines to read");
    }
}

// test read all lines
TEST(TsvFileHandler_Test, readline_4)
{
    auto tsvFileHandler = CreateTsvFileHandler(TEST_DATA_FILE_PATH);
    std::vector<std::string> lines = tsvFileHandler->ReadLines();
    std::vector<std::string> target = {"id,sentence",
                                       "0,Would the idea of Trump and Putin.",
                                       "1,What are the top ten Consumer-to-Consumer,",
                                       "2,Why don't people simply 'Google' instead;"};
    for (int i = 0; i < 4; ++i) {
        ASSERT_STREQ(static_cast<char *>(&lines[i][0]), static_cast<char *>(&target[i][0]));
    }
}

int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}