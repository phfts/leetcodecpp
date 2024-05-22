#include <gtest/gtest.h>
#include <string>

using namespace std;

bool isSubsequence(string s, string t)
{
    if (s.size() > t.size())
        return false;

    if (t.size() == 0) // s will be zero as well
        return true;

    int i = 0;
    int j = 0;
    int found = 0;
    while (j < t.size() && i < s.size())
    {
        int k = j;
        while (k < t.size() && s[i] != t[k])
        {
            k++;
        }
        
        if (k == t.size())
            return false;

        i++;
        j = k + 1;
        found++;
    }
    return found >= s.size();
}

// 0 <= s.length <= 100
// 0 <= t.length <= 10^4
TEST(Example, Example1)
{
    EXPECT_EQ(true, isSubsequence("", ""));
    EXPECT_EQ(true, isSubsequence("", "a"));
    EXPECT_EQ(true, isSubsequence("a", "a"));
    EXPECT_EQ(true, isSubsequence("a", "aa"));
    EXPECT_EQ(true, isSubsequence("a", "na"));
    EXPECT_EQ(true, isSubsequence("a", "ax"));
    EXPECT_EQ(false, isSubsequence("b", "a"));
}

TEST(Example, Example2)
{
    // EXPECT_EQ(true, isSubsequence("axb", "axb"));
    // EXPECT_EQ(true, isSubsequence("axb", "ax1b"));
    // EXPECT_EQ(true, isSubsequence("axb", "3a2x1b"));
    EXPECT_EQ(false, isSubsequence("acb", "ahbgdc"));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}