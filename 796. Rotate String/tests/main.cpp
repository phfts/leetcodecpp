#include <gtest/gtest.h>
#include <string>

using namespace std;

bool rotateString(string s, string goal)
{
    if (s.length() != goal.length())
        return false;

    int n = s.length();
    vector<char> v1(n);
    vector<char> v2(n);

    for (int i = 0; i < n; i++)
    {
        v1[i] = s[i];
        v2[i] = goal[i];
    }

    for (int offset = 0; offset < n; offset++)
    {
        bool stillCandidate = true;
        for (int j = 0; j < n; j++)
        {
            int pos = (j + offset) % n;
            if (v1[pos] != v2[j])
            {
                stillCandidate = false;
                break;
            }
        }
        if (stillCandidate) return true;
    }
    return false;
}

TEST(Example, Example1)
{
    EXPECT_EQ(true, rotateString("a", "a"));
    EXPECT_EQ(false, rotateString("a", "b"));
    EXPECT_EQ(true, rotateString("ab", "ba"));
    EXPECT_EQ(true, rotateString("abc", "cab"));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}