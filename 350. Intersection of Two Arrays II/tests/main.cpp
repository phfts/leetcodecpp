#include <gtest/gtest.h>
#include "../src/solution.cpp"

TEST(Example, Example1)
{
    auto s = Solution();
    vector<int> input1 = {1};
    vector<int> input2 = {1};
    vector<int> expected = {1};
    EXPECT_EQ(expected, s.intersect(input1, input2));
}


TEST(Example, Example2)
{
    auto s = Solution();
    vector<int> input1 = {2};
    vector<int> input2 = {1};
    vector<int> expected = {};
    EXPECT_EQ(expected, s.intersect(input1, input2));
}


TEST(Example, Example3)
{
    auto s = Solution();
    vector<int> input1 = {1,1,1,2};
    vector<int> input2 = {1,1,1,1};
    vector<int> expected = {1,1,1};
    EXPECT_EQ(expected, s.intersect(input1, input2));
}


int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}