#include <gtest/gtest.h>
#include <vector>

using namespace std;

vector<int> sortedSquares(vector<int> &nums)
{
    vector<int> negative;
    vector<int> positive;

    for (auto x : nums)
    {
        if (x < 0)
        {
            negative.emplace(negative.begin(), x * x);
        }
        else
        {
            positive.push_back(x * x);
        }
    }

    vector<int> ret;
    int pos1 = 0;
    int pos2 = 0;

    while (true)
    {
        if (pos1 < negative.size() && pos2 < positive.size())
        {
            if (negative[pos1] < positive[pos2])
            {
                ret.push_back(negative[pos1++]);
            }
            else
            {
                ret.push_back(positive[pos2++]);
            }
        }
        else if (pos1 < negative.size())
        {
            ret.push_back(negative[pos1++]);
        }
        else if (pos2 < positive.size())
        {
            ret.push_back(positive[pos2++]);
        }
        else
        {
            break;
        }
    }
    return ret;
}

TEST(Example, Example1)
{
    vector<int> input = {-1, 0, 4};
    vector<int> expected = {0, 1, 16};
    EXPECT_EQ(expected, sortedSquares(input));
}

TEST(Example, Example2)
{
    vector<int> input = {-4, -1, 0, 3, 10};
    vector<int> expected = {0, 1, 9, 16, 100};
    EXPECT_EQ(expected, sortedSquares(input));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}