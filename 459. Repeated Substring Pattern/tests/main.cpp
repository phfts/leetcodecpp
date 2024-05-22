#include <gtest/gtest.h>
#include <string>
#include <sstream>

using namespace std;

string buildRepeated(string s, int times)
{
    stringstream ss;
    int j = 0;
    while (j++ < times) ss << s;
    return ss.str();
}

bool repeatedSubstringPattern(string s)
{
    int n = s.length();
    if (n < 2)
        return false;

    for (int i = 1; i < n; i++)
    {
        if (n % i != 0)
            continue;

        int times = n / i;

        if (buildRepeated(s.substr(0, i), times) == s)
            return true;
    }
    return false;
}

TEST(Example, Example1)
{
    EXPECT_EQ(false, repeatedSubstringPattern("a"));
    EXPECT_EQ(false, repeatedSubstringPattern("ax"));
    EXPECT_EQ(true, repeatedSubstringPattern("aaa"));
    EXPECT_EQ(false, repeatedSubstringPattern("aba"));
    EXPECT_EQ(true, repeatedSubstringPattern("abab"));
    EXPECT_EQ(false, repeatedSubstringPattern("abcab"));
    EXPECT_EQ(true, repeatedSubstringPattern("abcabc"));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}