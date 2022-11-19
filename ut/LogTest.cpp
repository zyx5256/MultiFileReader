#include "../src/utils//Log.h"
#include "gtest/gtest.h"

Level LOG_LEVEL;

// test info level
TEST(Log_test, info)
{
    LOG_LEVEL = Level::INFO;
    LOG::INFO("test info");
    LOG::WARNING("test warning");
    LOG::ERROR("test error");
}

// test warning level
TEST(Log_test, warning)
{
    LOG_LEVEL = Level::WARNING;
    LOG::INFO("test info");
    LOG::WARNING("test warning");
    LOG::ERROR("test error");
}

// test error level
TEST(Log_test, error)
{
    LOG_LEVEL = Level::ERROR;
    LOG::INFO("test info");
    LOG::WARNING("test warning");
    LOG::ERROR("test error");
}

int main()
{
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}