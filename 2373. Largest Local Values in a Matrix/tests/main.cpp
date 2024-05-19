#include <gtest/gtest.h>
#include <vector>

using namespace std;

int max(vector<int> &values)
{
    if (values.size() == 0)
    {
        throw runtime_error("Error evaluating empty vector for max values");
    }

    int ret = values[0];
    for (auto x : values)
    {
        ret = ret > x ? ret : x;
    }
    return ret;
}

vector<vector<int>> largestLocal(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<vector<int>> newGrid(n - 2);
    for (int i = 0; i < n - 2; i++)
    {
        vector<int> row(n - 2);
        newGrid[i] = row;
    }

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = 0; j < n - 2; j++)
        {
            vector<int> subMatrix = {
                grid[i+2][j],   grid[i+2][j+1], grid[i+2][j+2], 
                grid[i+1][j],   grid[i+1][j+1], grid[i+1][j+2], 
                grid[i][j],     grid[i][j+1],   grid[i][j+2], 
            };
            newGrid[i][j] = max(subMatrix);
        }
    }

    return newGrid;
}

TEST(Example, Example1)
{
    vector<vector<int>> grid = {{9, 9, 8, 1}, {5, 6, 2, 6}, {8, 2, 6, 4}, {6, 2, 2, 2}};
    vector<vector<int>> expected = {{9, 9}, {8, 6}};
    EXPECT_EQ(expected, largestLocal(grid));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}