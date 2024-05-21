#include <gtest/gtest.h>
#include <string>
#include <unordered_map>

using namespace std;

int longestPalindrome(string s)
{
    int n = s.length();
    if (n <= 1) 
        return n;

    unordered_map<char, int> ocurrences; 
    for (char &c: s)
    {
        if (ocurrences.count(c) == 0)
        {
            ocurrences[c] = 0;
        }
        ocurrences[c]++;
    }

    int oddsCount = 0;
    int evenCount = 0;
    for (auto &[k, v] : ocurrences)
    {
        if (v % 2 == 1)
        {
            oddsCount++;
        }
        else
        {
            evenCount++;
        }
    }
    if (oddsCount == 0) 
        return s.length();
    
    return s.length() -oddsCount + 1;
}

TEST(Example, Example1)
{
    EXPECT_EQ(1, longestPalindrome("a"));
    EXPECT_EQ(2, longestPalindrome("aa"));
    EXPECT_EQ(1, longestPalindrome("ac"));
    EXPECT_EQ(7, longestPalindrome("abccccdd"));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}