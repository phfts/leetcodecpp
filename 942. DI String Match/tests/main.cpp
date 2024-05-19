#include <gtest/gtest.h>
#include <vector>
#include <string>

using namespace std;

vector<int> diStringMatch(string s)
{
    vector<int> ans = {0};
    int lastPos = 0;
    int lastNeg = 0;
    for (auto &c : s) 
    {
        if (c == 'D')
        {
            ans.push_back(--lastNeg);
        }
        else if (c == 'I')
        {
            ans.push_back(++lastPos);
        }
    }

    for (int i=0; i<ans.size(); i++)
    {
        ans[i] = ans[i] - lastNeg;
    }

    return ans;
}

TEST(Example, Example1)
{
    EXPECT_EQ((vector<int> {0,1,2,3}), diStringMatch("III"));
    EXPECT_EQ((vector<int> {2,1,0,3}), diStringMatch("DDI"));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}