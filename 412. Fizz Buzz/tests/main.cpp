#include <gtest/gtest.h>
#include <vector>

using namespace std;

vector<string> fizzBuzz(int n)
{
    vector<string> ans(n);
    for (int i = 1; i <= n; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            ans[i - 1] = "FizzBuzz";
        }
        else if (i % 3 == 0)
        {
            ans[i - 1] = "Fizz";
        }
        else if (i % 5 == 0)
        {
            ans[i - 1] = "Buzz";
        }
        else
        {
            ans[i - 1] = to_string(i);
        }
    }
    return ans;
}

TEST(Example, Example1)
{
    vector<string> expected = {"1", "2", "Fizz"};
    EXPECT_EQ(expected, fizzBuzz(3));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}