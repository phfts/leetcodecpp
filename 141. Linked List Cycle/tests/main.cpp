#include <gtest/gtest.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool hasCycle(ListNode *head)
{
    ListNode *curr = head;
    ListNode *fast = head;

    while (fast != nullptr && curr != nullptr)
    {
        if (fast->next == nullptr || fast->next->next == nullptr)
            return false;

        fast = fast->next->next;

        if (curr->next == nullptr)
            return false;

        curr = curr->next;

        if (fast == curr)
            return true;
    }

    return false;
}

TEST(Example, OneElementLinkedList)
{
    ListNode *node;

    node = new ListNode(1);
    EXPECT_EQ(false, hasCycle(node));

    node = new ListNode(1);
    node->next = node;
    EXPECT_EQ(true, hasCycle(node));
    delete node;
}

TEST(Example, OneTwoElementsLinkedList)
{
    ListNode *node;

    node = new ListNode(1, new ListNode(2));
    EXPECT_EQ(false, hasCycle(node));

    node->next->next = node->next;
    EXPECT_EQ(true, hasCycle(node));

    node = new ListNode(1, new ListNode(2));
    node->next->next = node;
    EXPECT_EQ(true, hasCycle(node));
    delete node;
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}