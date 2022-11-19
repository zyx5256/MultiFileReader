#include "../src/fileHandler/TsvFileHandler.h"
#include "gtest/gtest.h"

const std::string TEST_DATA_FILE_PATH = "../ut/data/test.tsv";

// test read line
TEST(TsvFileHandler_Test, readline_1)
{
    auto tsvFileHandler = createTsvFileHandler(TEST_DATA_FILE_PATH);
    std::string line = tsvFileHandler->readLine();
    EXPECT_STREQ(static_cast<char *>(&line[0]), "id,sentence");
}

// test read last line
TEST(TsvFileHandler_Test, readline_2)
{
    auto tsvFileHandler = createTsvFileHandler(TEST_DATA_FILE_PATH);
    std::string line;
    for (int i = 0; i < 4; ++i) {
        line = tsvFileHandler->readLine();
    }
    EXPECT_STREQ(static_cast<char *>(&line[0]), "2,Why don't people simply 'Google' instead;");
}

// test exception
TEST(TsvFileHandler_Test, readline_3)
{
    auto tsvFileHandler = createTsvFileHandler(TEST_DATA_FILE_PATH);
    try {
        for (int i = 0; i < 40; ++i) {
            tsvFileHandler->readLine();
        }
    }
    catch( const std::out_of_range& err ) {
        // check exception
        EXPECT_STREQ(err.what(), "no more lines to read");
    }
}

// test read all lines
TEST(TsvFileHandler_Test, readline_4)
{
    auto tsvFileHandler = createTsvFileHandler(TEST_DATA_FILE_PATH);
    std::vector<std::string> lines = tsvFileHandler->readLines();
    std::vector<std::string> target = {"id,sentence",
                                       "0,Would the idea of Trump and Putin.",
                                       "1,What are the top ten Consumer-to-Consumer,",
                                       "2,Why don't people simply 'Google' instead;"};
    for (int i = 0; i < 4; ++i) {
        EXPECT_STREQ(static_cast<char *>(&lines[i][0]), static_cast<char *>(&target[i][0]));
    }
}

int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}