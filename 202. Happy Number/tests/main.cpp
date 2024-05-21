#include <gtest/gtest.h>
#include <cmath>
#include <unordered_map>

using namespace std;

int reduce(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += pow(n % 10, 2);
        n = n / 10;
    }
    return sum;    
}

bool isHappy(int n) {
    unordered_map<int, bool> foundValues;
    int sum = reduce(n);
    while (sum != 1)
    {
        if (foundValues.count(sum) > 0)
            return false;
        
        foundValues[sum] = true;
        sum = reduce(sum);
    }
    return true;
}


TEST(Example, Example1)
{
    EXPECT_EQ(true, isHappy(1));
    EXPECT_EQ(false, isHappy(2)); // 4 16 37 58 89 
    EXPECT_EQ(true, isHappy(19)); // 4 16 37 58 89 
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}