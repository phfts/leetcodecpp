#include <gtest/gtest.h>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

struct Position
{
    int x;
    int y;
    Position(int x, int y) : x(x), y(y) {}

    string toKey()
    {
        return to_string(x) + ":" + to_string(y);
    }

    bool isValid(int m, int n)
    {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }
};

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    auto startPosition = Position(sr, sc);
    vector<Position> positionsToVisit = {startPosition};

    map<string, bool> visited;
    visited[startPosition.toKey()] = false;

    int originalColor = image[sr][sc];
    int m = image.size();
    int n = image[0].size();
    int i = 0;

    while (i < positionsToVisit.size())
    {
        auto currentPosition = positionsToVisit[i];
        if (visited.find(currentPosition.toKey()) != visited.end() && visited[currentPosition.toKey()])
        {
            i++;
            continue;
        }

        visited[currentPosition.toKey()] = true;

        auto left = Position(currentPosition.x - 1, currentPosition.y);
        auto top = Position(currentPosition.x, currentPosition.y - 1);
        auto right = Position(currentPosition.x + 1, currentPosition.y);
        auto down = Position(currentPosition.x, currentPosition.y + 1);

        if (left.isValid(m, n) && image[left.x][left.y] == originalColor && visited.find(left.toKey()) == visited.end() && !visited[left.toKey()])
        {
            positionsToVisit.push_back(left);
            visited[left.toKey()] = false;
        }

        if (top.isValid(m, n) && image[top.x][top.y] == originalColor && visited.find(top.toKey()) == visited.end() && !visited[top.toKey()])
        {
            positionsToVisit.push_back(top);
            visited[top.toKey()] = false;
        }

        if (right.isValid(m, n) && image[right.x][right.y] == originalColor && visited.find(right.toKey()) == visited.end() && !visited[right.toKey()])
        {
            positionsToVisit.push_back(right);
            visited[right.toKey()] = false;
        }

        if (down.isValid(m, n) && image[down.x][down.y] == originalColor && visited.find(down.toKey()) == visited.end() && !visited[down.toKey()])
        {
            positionsToVisit.push_back(down);
            visited[down.toKey()] = false;
        }

        i++;
    }
    for (auto &position : positionsToVisit)
    {
        image[position.x][position.y] = color;
    }
    return image;
}

TEST(Example, Example1)
{
    vector<vector<int>> input = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    vector<vector<int>> expected = {{2, 2, 2}, {2, 2, 0}, {2, 0, 1}};
    EXPECT_EQ(expected, floodFill(input, 1, 1, 2));
}

TEST(Example, Example2)
{
    vector<vector<int>> input = {{0, 0, 0}, {0, 0, 0}};
    vector<vector<int>> expected = {{1, 1, 1}, {1, 1, 1}};
    EXPECT_EQ(expected, floodFill(input, 1, 0, 1));
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}