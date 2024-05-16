#include <gtest/gtest.h>
#include "solution.cpp"


TEST(AddTwoNumbers, OneDigit)
{
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    auto result = addTwoNumbers(l1, l2);
    EXPECT_EQ(3, result->val);
}

TEST(AddTwoNumbers, OneDigitWithCarry)
{
    ListNode l1 = ListNode(8);
    ListNode l2 = ListNode(2);
    auto result = addTwoNumbers(&l1, &l2);
    EXPECT_EQ(0, result->val);
    EXPECT_EQ(1, result->next->val);
}

TEST(AddTwoNumbers, TwoDigits)
{
    ListNode l1 = ListNode(3, new ListNode(1));
    ListNode l2 = ListNode(2, new ListNode(2));
    auto result = addTwoNumbers(&l1, &l2);
    EXPECT_EQ(5, result->val);
    EXPECT_EQ(3, result->next->val);
}

TEST(AddTwoNumbers, TwoDigitsWithCarry)
{
    ListNode l1 = ListNode(3, new ListNode(1));
    ListNode l2 = ListNode(9, new ListNode(9));
    auto result = addTwoNumbers(&l1, &l2);
    EXPECT_EQ(2, result->val);
    EXPECT_EQ(1, result->next->val);
    EXPECT_EQ(1, result->next->val);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}