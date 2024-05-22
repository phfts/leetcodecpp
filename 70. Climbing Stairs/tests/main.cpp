#include <gtest/gtest.h>
#include <vector>

using namespace std;

int climbStairs(int n) {
        vector<int> values = {1, 2,3};
        int pos = n-1;

        while (pos >= values.size())
        {
            int size = values.size();
            int x = values[size-1] + values[size-2];
            values.push_back(x);
        }

        return values[pos];
    }

TEST(Example, Example1)
{
    EXPECT_EQ(5, climbStairs(4));
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}