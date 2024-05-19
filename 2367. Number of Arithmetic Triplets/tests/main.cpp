#include <gtest/gtest.h>
#include <vector>
#include <map>

using namespace std;

int arithmeticTriplets(vector<int> &nums, int diff)
{
    map<int, vector<int>> valuesByPositions;
    for (int i=0;i<nums.size();i++)
    {
        int value = nums[i];
        valuesByPositions[value].push_back(i);
    }
    
    
    int results = 0;
    for (auto x : nums)
    {
        bool nextIsPresent = valuesByPositions.find(x+diff) != valuesByPositions.end();
        bool nextNextIsAlsoPresent = valuesByPositions.find(x+2*diff) != valuesByPositions.end();
        if (nextIsPresent && nextNextIsAlsoPresent) 
        {
            results++;
        }
    }
    return results;
}

TEST(Example, Example1)
{
    vector<int> input = {0, 1, 4, 6, 7, 10};
    EXPECT_EQ(2, arithmeticTriplets(input, 3));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}