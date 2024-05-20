#include <gtest/gtest.h>
#include <vector>
#include <unordered_set>

using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    unordered_set<int> ocurrences;
    for (auto &c : nums)
    {
        if (ocurrences.count(c) > 0)
        {
            return true;
        }
        ocurrences.insert(c);
    }
    return false;
}

TEST(Example, Example1)
{
    vector<int> a = {1};
    EXPECT_EQ(false, containsDuplicate(a));

    vector<int> b = {1, 2};
    EXPECT_EQ(false, containsDuplicate(b));

    vector<int> c = {1,1};
    EXPECT_EQ(true, containsDuplicate(c));

    vector<int> d = {1,3,1};
    EXPECT_EQ(true, containsDuplicate(d));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}