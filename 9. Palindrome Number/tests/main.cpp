#include <gtest/gtest.h>
#include <string>

using namespace std;

bool isPalindrome(int x)
{
    if (x < 0)
        return false;
        
    string s = to_string(x);

    for (int i = 0; i < s.length() / 2; i++)
    {
        if (s[i] != s[s.length() - 1 - i])
            return false;
    }
    return true;
}

TEST(Example, Example1)
{
    EXPECT_EQ(false, isPalindrome(-1));
    EXPECT_EQ(true, isPalindrome(0));
    EXPECT_EQ(true, isPalindrome(1));
    EXPECT_EQ(false, isPalindrome(10));
    EXPECT_EQ(true, isPalindrome(11));
    EXPECT_EQ(false, isPalindrome(112));
    EXPECT_EQ(true, isPalindrome(121));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}