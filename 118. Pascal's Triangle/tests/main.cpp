#include <gtest/gtest.h>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows)
{
    if (numRows == 1)
    {
        return {{1}};
    }

    vector<vector<int>> ret = {{1},{1, 1}};
    if (numRows == 2)
    {
        return ret;
    }

    int row = 2;
    while (row++ < numRows)
    {
        vector<int> currentRow(row);
        for (int i = 0; i<row; i++)
        {
            if (i == 0 || i == row - 1)
            {
                currentRow[i] = 1;
            }
            else
            {
                auto lastRow = ret[ret.size()-1];
                currentRow[i] = lastRow[i] + lastRow[i-1];
            }
        }
        ret.push_back(currentRow);
    }
    return ret;
}

TEST(Example, Example1)
{
    vector<vector<int>> expected = {{1}};
    EXPECT_EQ(expected, generate(1));
}

TEST(Example, Example2)
{
    vector<vector<int>> expected = {{1}, {1,1}};
    EXPECT_EQ(expected, generate(2));
}

TEST(Example, Example3)
{
    vector<vector<int>> expected = {{1}, {1,1}, {1,2,1}, {1,3,3,1}, {1,4,6,4,1}};
    EXPECT_EQ(expected, generate(5));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}