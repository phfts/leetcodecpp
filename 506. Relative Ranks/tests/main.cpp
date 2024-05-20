#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> getBiggest(vector<int> score)
{
    sort(score.begin(), score.end(), [](int x, int y) {return x > y;});
    return score;
}

map<int, string> mapPositions(vector<int> biggestScores)
{
    map<int, string> positions;

    int i = 0;
    for (auto &x : biggestScores)
    {
        switch (i)
        {
            case 0:
                positions[x] = "Gold Medal";
                break;
            case 1:
                positions[x] = "Silver Medal";
                break;
            case 2:
                positions[x] = "Bronze Medal";
                break;
            default:
                positions[x] = to_string(i+1);
                break;
        }
        i++;
    }
    return positions;
}

vector<string> findRelativeRanks(vector<int> &score)
{
    vector<int> biggestScores = getBiggest(score);
    map<int, string> positions = mapPositions(biggestScores);
    vector<string> ret;

    for (auto &value : score)
    {
        ret.push_back(positions[value]);
    }
    return ret;
}

TEST(GetBiggest, OneElementInput)
{
    vector<int> input = {3};
    EXPECT_EQ((vector<int>{3}), getBiggest(input));
}

TEST(GetBiggest, TwoElementsInput)
{
    vector<int> input = {2, 3};
    EXPECT_EQ((vector<int>{3, 2}), getBiggest(input));
}

TEST(GetBiggest, TwoElementsInput2)
{
    vector<int> input = {3, 2};
    EXPECT_EQ((vector<int>{3, 2}), getBiggest(input));
}

TEST(GetBiggest, TreeElementsInput)
{
    vector<int> input = {1, 3, 2};
    EXPECT_EQ((vector<int>{3, 2, 1}), getBiggest(input));
}

TEST(GetBiggest, FourElementsInput)
{
    vector<int> input = {1, 3, 2, 5};
    EXPECT_EQ((vector<int>{5, 3, 2, 1}), getBiggest(input));
}

TEST(GetBiggest, FindRelative)
{
    vector<int> input = {1, 3, 2, 5};
    EXPECT_EQ((vector<string>{"4", "Silver Medal", "Bronze Medal", "Gold Medal"}), findRelativeRanks(input));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}