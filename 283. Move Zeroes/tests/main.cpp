#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace std;

void moveZeroes(vector<int> &nums)
{
    int i = 0;
    while (i < nums.size())
    {
        if (nums[i] != 0) 
        {
            i++;
            continue;
        }

        bool found = false;
        for (int j=i+1; j<nums.size(); j++)
        {
            if (nums[j] != 0)
            {
                swap(nums[i], nums[j]);
                i++;
                found = true;
                break;
            }
        }
        if (!found)
            break;
    }
}

TEST(Example, Example1)
{
    vector<int> input {0,1,0,3,4};
    moveZeroes(input);
    EXPECT_EQ((vector<int> {1,3,4,0,0}), input);
}

TEST(Example, Example2)
{
    vector<int> input {0,0,1,0,3,4};
    moveZeroes(input);
    EXPECT_EQ((vector<int> {1,3,4,0,0,0}), input);
}


TEST(Example, Example3)
{
    vector<int> input {0,0,0,1,0,3,4};
    moveZeroes(input);
    EXPECT_EQ((vector<int> {1,3,4,0,0,0,0}), input);
}

TEST(Example, Example4)
{
    vector<int> input {0};
    moveZeroes(input);
    EXPECT_EQ((vector<int> {0}), input);
}

TEST(Example, Example5)
{
    vector<int> input {10};
    moveZeroes(input);
    EXPECT_EQ((vector<int> {10}), input);
}

TEST(Example, Example6)
{
    vector<int> input {0,10};
    moveZeroes(input);
    EXPECT_EQ((vector<int> {10,0}), input);
}

TEST(Example, Example7)
{
    vector<int> input {10,0};
    moveZeroes(input);
    EXPECT_EQ((vector<int> {10,0}), input);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}