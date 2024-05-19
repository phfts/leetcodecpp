#include <gtest/gtest.h>
#include "../src/solution.cpp"

//You are given a string s. The score of a string is defined as the sum of 
// the absolute difference between the ASCII values of adjacent characters.



TEST(Example, Scores)
{
    EXPECT_EQ(0, score("aa"));
    EXPECT_EQ(1, score("ab"));
    EXPECT_EQ(1, score("ba"));
    EXPECT_EQ(2, score("bab"));
    EXPECT_EQ(0, score("bbb"));
    EXPECT_EQ(2, score("abc"));
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}