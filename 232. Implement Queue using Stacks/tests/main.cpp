#include <gtest/gtest.h>
#include "../src/queue.cpp"

using namespace std;

TEST(MyQueue, Empty)
{
    auto queue = new MyQueue();
    EXPECT_EQ(queue->empty(), true);
}

TEST(MyQueue, AfterAddingShouldNotBeEmpty)
{
    auto queue = new MyQueue();
    queue->push(1);
    EXPECT_EQ(1, queue->peek());
    EXPECT_EQ(queue->empty(), false);

    queue->push(2);
    EXPECT_EQ(1, queue->peek());
    EXPECT_EQ(queue->empty(), false);
}

TEST(MyQueue, AfterRemovinAllShouldBeEmpty)
{
    auto queue = new MyQueue();
    queue->push(1);
    EXPECT_EQ(1, queue->peek());
    EXPECT_EQ(queue->empty(), false);

    queue->pop();
    EXPECT_EQ(queue->empty(), true);

    queue->push(2);
    queue->push(3);
    EXPECT_EQ(2, queue->peek());
    EXPECT_EQ(queue->empty(), false);
    EXPECT_EQ(2, queue->pop());
    EXPECT_EQ(queue->empty(), false);
    EXPECT_EQ(3, queue->pop());
    EXPECT_EQ(queue->empty(), true);
}

TEST(MyQueue, Example)
{
    auto queue = new MyQueue();
    queue->push(1);
    queue->push(2);
    EXPECT_EQ(1, queue->peek());
    EXPECT_EQ(1, queue->pop());
    EXPECT_EQ(false, queue->empty());
}

// TEST(MyQueue, AfterAddingShouldNotBeEmpty)
// {
//     auto queue = new MyQueue();
//     queue->push(1);
//     EXPECT_EQ(queue->empty(), false);
// }

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}