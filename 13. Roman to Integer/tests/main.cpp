#include <gtest/gtest.h>
#include <map>
#include <string>

using namespace std;

int romanToInt(string s)
{
    if (s.length() == 0)
        return 0;

    map<char, int> romanNumerals;
    romanNumerals['I'] = 1;
    romanNumerals['V'] = 5;
    romanNumerals['X'] = 10;
    romanNumerals['L'] = 50;
    romanNumerals['C'] = 100;
    romanNumerals['D'] = 500;
    romanNumerals['M'] = 1000;

    if (s.size() == 1)
        return romanNumerals[s[0]];

    if (s.size() > 2 && s[0] == s[1] && s[1] == s[2])
        return 3*romanNumerals[s[0]] + romanToInt(s.substr(3, s.length()-3));

    if (s.size() > 1 && s[0] == s[1])
        return 2*romanNumerals[s[0]] + romanToInt(s.substr(2, s.length()-2));
        
    if (s.size() > 1 && s[0] != s[1])
    {
        if (romanNumerals[s[0]] < romanNumerals[s[1]])
        {
            return (romanNumerals[s[1]] - romanNumerals[s[0]])  + romanToInt(s.substr(2, s.length()-2));
        }
        else
        {
            return romanNumerals[s[0]] + romanToInt(s.substr(1, s.length()-1));
        }
    }
    return -1;
}

TEST(Example, Example1)
{
    EXPECT_EQ(1, romanToInt("I"));
    EXPECT_EQ(2, romanToInt("II"));
    EXPECT_EQ(3, romanToInt("III"));
    EXPECT_EQ(4, romanToInt("IV"));
    EXPECT_EQ(5, romanToInt("V"));
    EXPECT_EQ(6, romanToInt("VI"));
    EXPECT_EQ(7, romanToInt("VII"));
    EXPECT_EQ(8, romanToInt("VIII"));
    EXPECT_EQ(9, romanToInt("IX"));
    EXPECT_EQ(10, romanToInt("X"));
    EXPECT_EQ(11, romanToInt("XI"));
    EXPECT_EQ(12, romanToInt("XII"));
    EXPECT_EQ(13, romanToInt("XIII"));
    EXPECT_EQ(14, romanToInt("XIV"));
    EXPECT_EQ(15, romanToInt("XV"));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}