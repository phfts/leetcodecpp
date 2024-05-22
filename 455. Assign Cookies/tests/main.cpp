#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace std;

// But, you should give each child at most one cookie.
// Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i],
// 1 <= g.length <= 3 * 10^4
// 0 <= s.length <= 3 * 10^4

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(s.begin(), s.end(), [](int a, int b){ return a > b; });
    sort(g.begin(), g.end(), [](int a, int b){ return a > b; });

    int si = 0;
    int gi = 0;
    int fedChildren = 0;
    while (si < s.size() && gi < g.size())
    {
        if (g[gi] > s[si])
        {
            gi++;
        }
        else
        {
            // std::cout << "Feeding child " << gi << " with greedy " << g[gi] << " with cookie " << si << " of size " << s[si] << std::endl;
            fedChildren++;
            gi++;
            si++;
        }
    }
    
    return fedChildren;
}


TEST(Example, NoChildFed)
{
    vector<int> s = {};
    vector<int> g = {10, 20};
    EXPECT_EQ(0, findContentChildren(g, s));

    vector<int> s2 = {1};
    vector<int> g2 = {10, 20};
    EXPECT_EQ(0, findContentChildren(g2, s2));

    
    vector<int> s3 = {9};
    vector<int> g3 = {10, 20};
    EXPECT_EQ(0, findContentChildren(g3, s3));
}

TEST(Example, OneChildIsFed)
{
    vector<int> s = {10};
    vector<int> g = {10, 20};
    EXPECT_EQ(1, findContentChildren(g, s));

    vector<int> s2 = {20};
    vector<int> g2 = {10, 20};
    EXPECT_EQ(1, findContentChildren(g2, s2));
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
