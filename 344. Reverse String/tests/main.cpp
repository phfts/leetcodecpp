#include <gtest/gtest.h>
#include <vector>

using namespace std;

// TODO: inplace
void reverseString(vector<char>& s) {
    for (int i=0;i<s.size()/2;i++)
    {
        swap(s[i], s[s.size()- 1 - i]);
    }
}

TEST(Example, SingleCharExample)
{
    vector<char> input = {'a'};
    reverseString(input);
    vector<char> expected = {'a'};
    EXPECT_EQ(expected, input);
}


TEST(Example, TwoCharExample)
{
    vector<char> input = {'a', 'b'};
    reverseString(input);
    vector<char> expected = {'b', 'a'};
    EXPECT_EQ(expected, input);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}