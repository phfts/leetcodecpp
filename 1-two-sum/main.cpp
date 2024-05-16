#include <gtest/gtest.h>
#include "src/two_sum.cpp"

TEST(TwoSum, BruteForceSolution)
{
    vector<int> expected = {0,1};
    EXPECT_EQ(expected, getTwoSum(vector<int> {1,2,3}, 3));
}

TEST(TwoSum, OptimizedSolutionSimpleCase)
{
    vector<int> expected = {8,9};
    EXPECT_EQ(expected, getTwoSumOptimized(vector<int> {1,2,3,4,5,6,7,8,9,10}, 19));
}

TEST(TwoSum, OptimizedSolutionRepetition)
{
    vector<int> expected = {0,2};
    EXPECT_EQ(expected, getTwoSumOptimized(vector<int> {3,1,3}, 6));
}

TEST(TwoSum, OptimizedSolutionUniqueSolution)
{
    vector<int> expected = {1,2};
    EXPECT_EQ(expected, getTwoSumOptimized(vector<int> {3,1,5}, 6));
}



int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}