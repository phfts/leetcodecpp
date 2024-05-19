#include <gtest/gtest.h>

#include <vector>

using namespace std;


// ans[i] = nums[nums[i]]
vector<int> buildArray(vector<int> &nums)
{
    vector<int> ans(nums.size());
    for (int i = 0; i < nums.size(); i++)
    {
        ans[i] = nums[nums[i]];
    }
    return ans;
}

TEST(Example, Example1)
{
    vector<int> expected = vector<int>{0, 1, 2, 4, 5, 3};
    vector<int> nums = vector<int>{0, 2, 1, 5, 3, 4};
    EXPECT_EQ(expected, buildArray(nums));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}