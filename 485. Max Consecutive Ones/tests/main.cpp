#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int ret = 0;
    if (nums.size() == 1)
        return nums[0] == 1 ? 1 : 0;

    int i = 0;
    while (i < nums.size())
    {
        if (nums[i] == 0)
        {
            i++;
            continue;
        }

        int count = 1;
        bool found = false;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] == 1)
            {
                count++;
            }
            else
            {
                found = true;
                i = j;
                break;
            }
        }
        if (!found)
            return max({ret, count});

        ret = max({ret, count});
    }
    return ret;
}

TEST(Example, Example1)
{
    vector<int> input = {1};
    EXPECT_EQ(1, findMaxConsecutiveOnes(input));
}

TEST(Example, Example2)
{
    vector<int> input = {0};
    EXPECT_EQ(0, findMaxConsecutiveOnes(input));
}

TEST(Example, Example3)
{
    vector<int> input = {1, 0, 1};
    EXPECT_EQ(1, findMaxConsecutiveOnes(input));
}

TEST(Example, Example5)
{
    vector<int> input = {1, 1, 0, 1, 1, 1};
    EXPECT_EQ(3, findMaxConsecutiveOnes(input));
}

TEST(Example, Example4)
{
    vector<int> input = {1, 1, 1, 0, 1, 1};
    EXPECT_EQ(3, findMaxConsecutiveOnes(input));
}

TEST(Example, ExampleBig)
{
    int n = pow(10,5);
    vector<int> input(n);

    for (int i = 0; i < n; i++) input[i] = 1;
    EXPECT_EQ(n, findMaxConsecutiveOnes(input));


    for (int i = 0; i < n; i++) input[i] = 0;
    EXPECT_EQ(0, findMaxConsecutiveOnes(input));    


    for (int i = 0; i < n; i++) input[i] = i % 2;
    EXPECT_EQ(1, findMaxConsecutiveOnes(input));     
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}