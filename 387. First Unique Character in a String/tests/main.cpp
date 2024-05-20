#include <gtest/gtest.h>
#include <map>

using namespace std;

    int firstUniqChar(string s) {
        map<char, int> occurrences;
        for (auto &c : s)
        {
            if (occurrences.find(c) == occurrences.end())
            {
                occurrences[c] = 0;
            }
            occurrences[c]++;
        }

        int i = 0;
        for (auto &c : s)
        {
            if (occurrences[c] == 1)
                return i;
            i++;
        }
        return -1;
    }

TEST(Example, Example1)
{
    EXPECT_EQ(0, firstUniqChar("a"));
    EXPECT_EQ(0, firstUniqChar("abc"));
    EXPECT_EQ(1, firstUniqChar("aba"));
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}