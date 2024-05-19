#include <gtest/gtest.h>

#include <vector>

using namespace std;

vector<int> getConcatenation(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(2*n);
    for (int i=0;i<nums.size(); i++)
    {
        ans[i] = nums[i];
        ans[i + n] = nums[i];
    }
}

TEST(Example, Example1)
{
    vector<int> expected = {1,2,1,2};
    vector<int> original = {1,2};
    EXPECT_EQ(expected, getConcatenation(original));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}