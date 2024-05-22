#include <gtest/gtest.h>
#include <string>
#include <sstream>

using namespace std;

string sanitize(string s)
{
    stringstream ss;
    for (char &c : s)
    {
        bool isLowerCaseAlphaNumericChar = (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
        if (isLowerCaseAlphaNumericChar)
        {
            ss << (char)(c);
            continue;
        }

        bool isUpperCaseChar = c >= 'A' && c <= 'Z';
        if (isUpperCaseChar)
        {
            ss << (char)(c - 'A' + 'a');
        }
    }
    return ss.str();
}

bool isPalindrome(string s)
{
    s = sanitize(s);
    for (int i = 0; i < s.length() / 2; i++)
    {
        if (s[i] != s[s.length() - 1 - i])
            return false;
    }
    return true;
}

TEST(Example, Example1)
{
    EXPECT_EQ(true, isPalindrome(""));
    EXPECT_EQ(true, isPalindrome("a"));
    EXPECT_EQ(true, isPalindrome("aa"));
    EXPECT_EQ(false, isPalindrome("ab"));
}

TEST(Example, ExampleWithNonEnglishChars)
{
    EXPECT_EQ(true, isPalindrome("/.;"));
    EXPECT_EQ(true, isPalindrome("a "));
    EXPECT_EQ(true, isPalindrome(" A    a "));
    EXPECT_EQ(false, isPalindrome("a b"));
    EXPECT_EQ(false, isPalindrome("0P"));
    EXPECT_EQ(true, isPalindrome(".P"));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}