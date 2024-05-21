#include <gtest/gtest.h>
#include <vector>

using namespace std;

int removeElement(vector<int> &nums, int val)
{
    int i = 0;
    int removed = 0;
    while (i < nums.size())
    {
        if (nums[i] == val)
        {
            removed++;
            nums.erase(nums.begin() + i);
            nums.push_back(-1);
        }
        else
        {
            i++;
        }
    }
    return nums.size() - removed;
}

TEST(Example, Example1)
{
    vector<int> input = {1, 2, 1, 2, 3, 3};
    EXPECT_EQ(4, removeElement(input, 2));
}

TEST(Example, Example2)
{
    vector<int> input = {2, 2, 2, 2, 3, 3};
    EXPECT_EQ(2, removeElement(input, 2));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}