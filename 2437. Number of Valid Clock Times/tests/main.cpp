#include <gtest/gtest.h>
#include <string>

using namespace std;

bool hasQuestionChar(string s)
{
    int i = 0;
    while (i < 5 && s[i] != '?')
    {
        i++;
    }
    if (i >= s.length())
        return false;
    return true;
}

int countTime(string time)
{
    if (!hasQuestionChar(time))
        return 1;

    int ret = 1;

    if (time[4] == '?')
        ret = 10 * ret;
    if (time[3] == '?')
        ret = 6 * ret;

    if (time.substr(0, 2) == "??")
        return 24 * ret;

    if (time[0] == '?')
    {
        if (time[1] >= '4')
            return 2 * ret;
        else
            return 3 * ret;
    }
    else if (time[1] == '?')
    {
        if (time[0] == '2')
            return 4 * ret;
        else
            return 10 * ret;
    }

    return ret;
}

TEST(countTime, Example)
{
    EXPECT_EQ(1, countTime("14:33"));
    EXPECT_EQ(1, countTime("14:33"));
    EXPECT_EQ(2, countTime("?4:33"));
    EXPECT_EQ(2, countTime("?9:33"));
    EXPECT_EQ(30, countTime("?3:5?"));
    EXPECT_EQ(60, countTime("11:??"));
    EXPECT_EQ(24, countTime("??:12"));
    EXPECT_EQ(24 * 60, countTime("??:??"));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}