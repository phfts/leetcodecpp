#include <gtest/gtest.h>
#include <vector>
#include <map>

using namespace std;

int singleNumber(vector<int> &nums)
{
    map<int, int> valueOccurences;
    for (auto x : nums)
    {
        if (valueOccurences.find(x) == valueOccurences.end())
        {
            valueOccurences[x] = 1;
        }
        else
        {
            valueOccurences[x]++;
        }
    }

    for (auto &[k, v] : valueOccurences)
    {
        if (v == 1)
        {
            return k;
        }
    }
    return -1;
}

TEST(Example, Example1)
{
    auto input = vector<int> {10,2,2};
    EXPECT_EQ(10, singleNumber(input));
}


TEST(Example, Example2)
{
    auto input = vector<int> {10,2,2,10,3};
    EXPECT_EQ(3, singleNumber(input));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}