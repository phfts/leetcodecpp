#include <gtest/gtest.h>
#include "../src/solution.cpp"

bool solve(ListNode *head)
{
    auto x = Solution();
    return x.isPalindrome(head);
}

TEST(Example, SingleElement)
{
    ListNode *root = new ListNode(1);
    EXPECT_EQ(true, solve(root));
}

TEST(Example, TwoElementsPalindrome)
{
    ListNode *root = new ListNode(1, new ListNode(1));
    EXPECT_EQ(true, solve(root));
}

TEST(Example, TreeElementFalsePalindrome)
{
    ListNode *root = new ListNode(1, new ListNode(2, new ListNode(2)));
    EXPECT_EQ(false, solve(root));
}

TEST(Example, TreeElementTruePalindrome)
{
    ListNode *root = new ListNode(1, new ListNode(2, new ListNode(1)));
    EXPECT_EQ(true, solve(root));
}

TEST(Example, FourElementTruePalindrome)
{
    ListNode *root = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));
    EXPECT_EQ(true, solve(root));
}

TEST(Example, FourElementFalsePalindrome)
{
    ListNode *root = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(11))));
    EXPECT_EQ(false, solve(root));
}

TEST(Example, FourElementFalsePalindrome2)
{
    ListNode *root = new ListNode(5, new ListNode(5, new ListNode(7, new ListNode(5))));
    EXPECT_EQ(false, solve(root));
}

TEST(Example, FiveElementTruePalindrome)
{
    ListNode *root = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(2, new ListNode(1)))));
    EXPECT_EQ(true, solve(root));
}

TEST(Example, FiveElementFalsePalindrome)
{
    ListNode *root = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(1, new ListNode(1)))));
    EXPECT_EQ(false, solve(root));
}

TEST(Example, Example1)
{
    ListNode *root = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(11))));
    EXPECT_EQ(false, solve(root));
}

TEST(Example, Example2)
{
    ListNode *root = new ListNode(1, new ListNode(2, new ListNode(1)));
    EXPECT_EQ(true, solve(root));
}

TEST(Example, Example3)
{
    ListNode *root = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));
    EXPECT_EQ(true, solve(root));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}