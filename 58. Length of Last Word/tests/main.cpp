#include <gtest/gtest.h>
#include <string>

using namespace std;

int lengthOfLastWord(string s)
{
    int n = s.length();
    if (n == 0)
        return 0;

    int lastCharPos = n-1;
    while (lastCharPos > 0 && s[lastCharPos] == ' ') lastCharPos--; // Test with all spaces

    int count = 0;
    int lastLength = 0;
    for (int i = 0; i <= lastCharPos; i++)
    {
        count = (s[i] == ' ' ? 0 : count + 1);
    }
    return count;
}

TEST(lengthOfLastWord, NoWords)
{
    EXPECT_EQ(0, lengthOfLastWord(""));
    EXPECT_EQ(0, lengthOfLastWord(" "));
    EXPECT_EQ(0, lengthOfLastWord("   "));
}

TEST(lengthOfLastWord, WithOneLetterWords)
{
    EXPECT_EQ(1, lengthOfLastWord("a"));
    EXPECT_EQ(1, lengthOfLastWord(" a"));
    EXPECT_EQ(1, lengthOfLastWord("a "));
    EXPECT_EQ(1, lengthOfLastWord(" a "));
}

TEST(lengthOfLastWord, TwoWords)
{
    EXPECT_EQ(2, lengthOfLastWord("a aa"));
    EXPECT_EQ(1, lengthOfLastWord(" aa a"));
}

TEST(lengthOfLastWord, MultipleWords)
{
    EXPECT_EQ(4, lengthOfLastWord("   fly me   to   the moon  "));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}