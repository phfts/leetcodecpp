#include <gtest/gtest.h>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int carry = 1;
    int i = digits.size() - 1;
    while (carry > 0 && i >= 0)
    {
        int digit = digits[i] + carry;
        carry = digit / 10;
        digits[i--] = digit % 10;
    }
    if (carry > 0)
    {
        digits.insert(digits.begin(), carry);
        carry = 0;
    }
    return digits;
}

TEST(Example, Example1)
{
    vector<int> input = {1};
    vector<int> output = {2};
    EXPECT_EQ(output, plusOne(input));
}


TEST(Example, Example2)
{
    vector<int> input = {9};
    vector<int> output = {1,0};
    EXPECT_EQ(output, plusOne(input));
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}