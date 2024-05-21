#include <gtest/gtest.h>
#include <vector>

using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int i = 0;
    int removed = 0;
    while (i<nums.size()-1)
    {
        if (nums[i] == nums[i+1])
        {
            nums.erase(nums.begin() + i);
        }
        else
        {
            i++;
        }
    }
    return nums.size();
}

TEST(Example, Example1)
{
    vector<int> input = {1, 1, 2, 2, 3};
    EXPECT_EQ(3, removeDuplicates(input));
}

TEST(Example, Example2)
{
    vector<int> input = {1};
    EXPECT_EQ(1, removeDuplicates(input));
}

TEST(Example, Example3)
{
    vector<int> input = {1, 1};
    EXPECT_EQ(1, removeDuplicates(input));
}

TEST(Example, Example4)
{
    vector<int> input = {1, 2};
    EXPECT_EQ(2, removeDuplicates(input));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}