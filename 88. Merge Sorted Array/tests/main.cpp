#include <gtest/gtest.h>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if (n == 0)
        return;

    int i1 = m-1;
    int i2 = n-1;
    int lastPos = m+n-1;
    vector<int> ans(m+n);
    while (i1 >= 0 || i2 >= 0)
    {
        if (i1 < 0)
        {
            nums1[lastPos--] = nums2[i2--];
        }
        else if (i2 < 0)
        {
            nums1[lastPos--] = nums1[i1--];
        }
        else if (nums1[i1] < nums2[i2])
        {
            nums1[lastPos--] = nums2[i2--];
        }
        else
        {
            nums1[lastPos--] =  nums1[i1--];
        }
    }
}

TEST(Example, Example1)
{
    vector<int> nums1 = {};
    vector<int> nums2 = {};
    vector<int> expected = {};
    merge(nums1, 0, nums2, 0);
    EXPECT_EQ(expected, nums1);
}

TEST(Example, Example2)
{
    vector<int> nums1 = {1};
    vector<int> nums2 = {};
    vector<int> expected = {1};
    merge(nums1, 2, nums2, 0);
    EXPECT_EQ(expected, nums1);
}

TEST(Example, Example3)
{
    vector<int> nums1 = {1,4, 0};
    vector<int> nums2 = {2};
    vector<int> expected = {1,2,4};
    merge(nums1, 2, nums2, 1);
    EXPECT_EQ(expected, nums1);
}


int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}