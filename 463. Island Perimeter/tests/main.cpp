#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;


int islandPerimeter(vector<vector<int>> &grid)
{
    int perimeter = 0;
    int rows = grid.size();
    for (int i = 0; i < rows; i++)
    {
        int columns = grid[0].size();
        for (int j = 0; j < columns; j++)
        {
            if (grid[i][j] != 1)
                continue;

            bool shouldCountLeft = (j == 0 || grid[i][j - 1] == 0);
            bool shouldCountTop = (i == 0 || grid[i - 1][j] == 0);
            bool shouldCountRight = (j == columns - 1 || grid[i][j + 1] == 0);
            bool shouldCountBottom = (i == rows - 1 || grid[i+1][j] == 0);

            if (shouldCountLeft) perimeter++;
            if (shouldCountTop) perimeter++;
            if (shouldCountRight) perimeter++;
            if (shouldCountBottom) perimeter++;
        }
    }
    return perimeter;
}

TEST(Example, Example1)
{
    vector<vector<int>> input = {{1}};
    EXPECT_EQ(4, islandPerimeter(input));
}

TEST(Example, Example2)
{
    vector<vector<int>> input = {{1,0}, {0,0}};
    EXPECT_EQ(4, islandPerimeter(input));
}

TEST(Example, Example3)
{
    vector<vector<int>> input = {{1,0}, {1,0}};
    EXPECT_EQ(6, islandPerimeter(input));
}

TEST(Example, Example4)
{
    vector<vector<int>> input = {{1,0}, {0,1}};
    EXPECT_EQ(8, islandPerimeter(input));
}

TEST(Example, Example5)
{
    vector<vector<int>> input = {{0,1,0}, {1,1,1}, {0,1,0}};
    EXPECT_EQ(12, islandPerimeter(input));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}