#include <gtest/gtest.h>
#include <string>
#include <sstream>

using namespace std;

string addBinary(string a, string b)
{
    int pos1 = a.size() -1;
    int pos2 = b.size() -1;

    string ret = "";

    int carry = 0;
    while (pos1 >= 0 || pos2 >= 0 || carry > 0)
    {
        int v1 = pos1 >= 0 ? a[pos1--] - '0' : 0;
        int v2 = pos2 >= 0 ? b[pos2--] - '0' : 0;
        int sum = v1 + v2 + carry;
        carry = sum / 2;
        sum = sum % 2;
        ret = to_string(sum) + ret;
    }
    return ret;
}

TEST(Example, Example1)
{
    EXPECT_EQ("100", addBinary("11", "1"));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}