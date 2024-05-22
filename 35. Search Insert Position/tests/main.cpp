#include <gtest/gtest.h>
#include <vector>

using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int n = nums.size();
    if (n == 0)
        return 0;

    if (n == 1)
    {
        if (target > nums[n - 1])
            return 1;
        return 0;
    }

    int leftPos = 0;
    int rightPos = n-1;
    while (leftPos < rightPos)
    {
        if (target <= nums[leftPos])
            return leftPos;

        if (target > nums[rightPos])
            return rightPos + 1;

        if (target == nums[rightPos])
            return rightPos;

        if (rightPos == leftPos + 1)
        {
            return rightPos;
        }
        
        int midPos = (leftPos + rightPos)/2;
        if (target == nums[midPos]) 
        {
            return midPos;
        }
        else if (target > nums[midPos])
        {
            leftPos = midPos;
        }
        else
        {
            rightPos = midPos;
        }
    }

}

TEST(Example, Example1)
{
    vector<int> nums = {1}; 
    EXPECT_EQ(0, searchInsert(nums, 1));
    EXPECT_EQ(1, searchInsert(nums, 2));
}

TEST(Example, ExampleWith2DifferentElements)
{
    vector<int> nums = {1, 4}; 
    EXPECT_EQ(0, searchInsert(nums, 0));
    EXPECT_EQ(0, searchInsert(nums, 1));
    EXPECT_EQ(1, searchInsert(nums, 2));
    EXPECT_EQ(1, searchInsert(nums, 4));
    EXPECT_EQ(2, searchInsert(nums, 5));
}


TEST(Example, ExampleWith3DifferentElements)
{
    vector<int> nums = {1, 2, 4}; 
    EXPECT_EQ(0, searchInsert(nums, 0));
    EXPECT_EQ(0, searchInsert(nums, 1));
    EXPECT_EQ(1, searchInsert(nums, 2));
    EXPECT_EQ(2, searchInsert(nums, 3));
    EXPECT_EQ(2, searchInsert(nums, 4));
    EXPECT_EQ(3, searchInsert(nums, 5));
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}