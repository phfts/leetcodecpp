#include <gtest/gtest.h>
#include <vector>
#include <string>

using namespace std;

string destCity(vector<vector<string>> &paths)
{
    if (paths.size() == 0)
    {
        throw runtime_error("Invalid path input. Should not be empty!");
    }

    map<string, bool> citiesOutgoingPath;
    for (auto x : paths)
    {
        string origin = x[0];
        citiesOutgoingPath[origin] = true;
    }

    for (auto x : paths)
    {
        string origin = x[0];
        string destination = x[1];

        if (citiesOutgoingPath.find(origin) == citiesOutgoingPath.end())
        {
            return origin;
        }

        if (citiesOutgoingPath.find(destination) == citiesOutgoingPath.end())
        {
            return destination;
        }
    }
    return "NOT_FOUND";
}

TEST(Example, Example1)
{
    vector<vector<string>> paths1 = {{"A", "B"}};
    EXPECT_EQ("B", destCity(paths1));

    vector<vector<string>> paths2 = {{"A", "B"}, {"B", "C"}};
    EXPECT_EQ("C", destCity(paths2));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}