#include <gtest/gtest.h>
#include "../src/solution.cpp"

TEST(Example, Example1)
{
    auto ma = MovingAverage(3);
    EXPECT_EQ(2, ma.next(2));
    EXPECT_EQ(3, ma.next(4));
    EXPECT_EQ(4, ma.next(6));
}

TEST(Example, Example2)
{
    auto ma = MovingAverage(1);
    EXPECT_EQ(4, ma.next(4));
    EXPECT_EQ(0, ma.next(0));
}


int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}