#include <gtest/gtest.h>

TEST(Google, BorderCase1)
{
    EXPECT_EQ(1, 2);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}