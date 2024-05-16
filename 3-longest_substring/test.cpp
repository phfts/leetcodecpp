#include <gtest/gtest.h>
#include "solution.cpp"

TEST(Solution, BruteForceSolution)
{
    EXPECT_EQ(0, lengthOfLongestSubstring(""));
}

TEST(Solution, BruteForceSolutionOneChar)
{
    EXPECT_EQ(1, lengthOfLongestSubstring("a"));
}

TEST(Solution, BruteForceSolutionTwoDistinctChars)
{
    EXPECT_EQ(2, lengthOfLongestSubstring("ab"));
}

TEST(Solution, BruteForceSolutionTwoEqualChars)
{
    EXPECT_EQ(1, lengthOfLongestSubstring("aa"));
}

TEST(Solution, BruteForcThreeChars)
{
    EXPECT_EQ(1, lengthOfLongestSubstring("aaa"));
    EXPECT_EQ(2, lengthOfLongestSubstring("aba"));
    EXPECT_EQ(2, lengthOfLongestSubstring("baa"));
    EXPECT_EQ(3, lengthOfLongestSubstring("bac"));
    EXPECT_EQ(3, lengthOfLongestSubstring("dvdf"));
    EXPECT_EQ(3, lengthOfLongestSubstring("pwwkew"));
    EXPECT_EQ(3, lengthOfLongestSubstring("abcabcbb"));
    EXPECT_EQ(2, lengthOfLongestSubstring("abba"));
    EXPECT_EQ(5, lengthOfLongestSubstring("tmmzuxt"));
    EXPECT_EQ(3, lengthOfLongestSubstring("aabaab!bb"));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
