#include <gtest/gtest.h>
#include <vector>
#include <map>

using namespace std;

int majorityElement(vector<int>& nums) {
    int candidate = nums[0];
    int votes = 0;
    for (auto &x : nums)
    {
        if (x == candidate)
        {
            votes++;
        }
        else
        {
            if (--votes == 0)
            {
                candidate = x;
                votes = 1;
            }
        }
    }
    return candidate;
}

TEST(Example, Example1)
{
    vector<int> input = {3,1,2,1,3,3};
    EXPECT_EQ(3, majorityElement(input));
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}