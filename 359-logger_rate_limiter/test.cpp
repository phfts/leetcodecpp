#include <gtest/gtest.h>
#include "solution.cpp"

TEST(Logger, OneMessage)
{
    auto logger = Logger();
    EXPECT_EQ(true, logger.shouldPrintMessage(1, "foo"));
    EXPECT_EQ(false, logger.shouldPrintMessage(1, "foo"));
    EXPECT_EQ(true, logger.shouldPrintMessage(1, "bar"));
    EXPECT_EQ(false, logger.shouldPrintMessage(10, "foo"));
    EXPECT_EQ(true, logger.shouldPrintMessage(11, "foo"));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}