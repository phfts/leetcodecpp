#include <gtest/gtest.h>
#include "../src/solution2.cpp"

TEST(Example, EmptyCase)
{
    vector<int> students {};
    vector<int> sandwiches {};
    EXPECT_EQ(0, countStudents(students, sandwiches));
}

TEST(Example, SimpleWorkingExampleWithOneElement)
{
    vector<int> students {1};
    vector<int> sandwiches {1};
    EXPECT_EQ(0, countStudents(students, sandwiches));
}

TEST(Example, SimpleNotWorkingExampleWithOneElement)
{
    vector<int> students {1};
    vector<int> sandwiches {0};
    EXPECT_EQ(1, countStudents(students, sandwiches));
}

TEST(Example, TwoElementsWorking)
{
    vector<int> students {0,1};
    vector<int> sandwiches {1,0};
    EXPECT_EQ(0, countStudents(students, sandwiches));
}

TEST(Example, TwoElementsNotWorking)
{
    vector<int> students {0,1};
    vector<int> sandwiches {0,0};
    EXPECT_EQ(1, countStudents(students, sandwiches));
}


TEST(Example, TwoElementsNotWorkingAtAll)
{
    vector<int> students {1,1};
    vector<int> sandwiches {0,0};
    EXPECT_EQ(2, countStudents(students, sandwiches));
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}