#include <gtest/gtest.h>
#include <vector>
#include <cmath>

using namespace std;


int maxProfit(vector<int> &prices)
{
    int buy = prices[0];
    int maxProfit = 0;
    for (auto &price : prices)
    {
        buy = buy < price ? buy : price;
        
        int diff = price - buy;
        maxProfit = diff > maxProfit ? diff : maxProfit;
    }
    return maxProfit;
}

TEST(Example, Example1)
{
    vector<int> input = {1};
    EXPECT_EQ(0, maxProfit(input));
}

TEST(Example, Example2)
{
    vector<int> input = {100, 99};
    EXPECT_EQ(0, maxProfit(input));
}

TEST(Example, Example3)
{
    vector<int> input = {10, 1};
    EXPECT_EQ(0, maxProfit(input));
}

TEST(Example, Example4)
{
    vector<int> input = {1,2,3,5};
    EXPECT_EQ(4, maxProfit(input));
}


TEST(Example, Example5)
{
    vector<int> input = {3,2,1,5};
    EXPECT_EQ(4, maxProfit(input));
}

TEST(Example, Example6)
{
    vector<int> input = {2,1,2,0,1};
    EXPECT_EQ(1, maxProfit(input));
}

TEST(Example, ExampleBig1)
{
    int N = pow(10, 5);
    vector<int> input(N);
    
    for (int i = 0; i < N; i++) input[i] = 0;
    EXPECT_EQ(0, maxProfit(input));

    for (int i = 0; i < N; i++) input[i] = i;
    EXPECT_EQ(N-1, maxProfit(input));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}