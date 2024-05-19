#include <gtest/gtest.h>
#include <string>

using namespace std;

bool checkIfPangram(string sentence)
{
    map<int, bool> presentChars;
    int lastChar = 'z' - 'a';
    for (int i = 0; i<= lastChar; i++)
    {
        presentChars[i] = false;
    }

    for (char &c : sentence)
    {
        presentChars[c - 'a'] = true;
    }

    for (auto &[k, v] : presentChars)
    {
        if (!v)
        {
            return false;
        }
    }
    return true;
}

TEST(Example, Example1)
{
    EXPECT_EQ(false,  checkIfPangram("ddd"));
    EXPECT_EQ(true,  checkIfPangram("qwertyuiopasdfghjklzxcvbnm"));
    EXPECT_EQ(false,  checkIfPangram("qwertyuiopasdfghjklzxcvbm"));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}