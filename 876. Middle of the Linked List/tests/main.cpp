#include <gtest/gtest.h>
#include "../src/solution.cpp"

TEST(Size, TestSize)
{
    ListNode head = ListNode(1);
    EXPECT_EQ(1, middleNode(&head)->val);

    auto next = ListNode(2);
    head.next = &next;
    EXPECT_EQ(2, middleNode(&head)->val);

    auto third = ListNode(3);
    next.next = &third;
    EXPECT_EQ(2, middleNode(&head)->val);

    auto forth = ListNode(4);
    third.next = &forth;
    EXPECT_EQ(3, middleNode(&head)->val);

    auto fifth = ListNode(5);
    forth.next = &fifth;
    EXPECT_EQ(3, middleNode(&head)->val);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}