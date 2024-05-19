#include <gtest/gtest.h>
#include <string>
#include <sstream>

using namespace std;

string mergeAlternately(string word1, string word2) {
    stringstream ss;

    int pos1 = 0;
    int pos2 = 0;

    while (pos1 < word1.length() || pos2 < word2.length())
    {
        if (pos1 < word1.length())
        {
            ss << word1[pos1];
        }
        if (pos2 < word2.length())
        {
            ss << word2[pos2];
        }
        pos1++;
        pos2++;
    }

    return ss.str();
}

TEST(Example, Example1)
{
    EXPECT_EQ("", mergeAlternately("", ""));
    EXPECT_EQ("a", mergeAlternately("a", ""));
    EXPECT_EQ("b", mergeAlternately("", "b"));
    EXPECT_EQ("ab", mergeAlternately("a", "b"));
    EXPECT_EQ("abccc", mergeAlternately("accc", "b"));
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}