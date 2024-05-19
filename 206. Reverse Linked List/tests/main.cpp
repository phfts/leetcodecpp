#include <gtest/gtest.h>
#include <vector>
#include "../lib/list_node.cpp"

using namespace std;

ListNode *reverseList(ListNode *head)
{
    if (head == nullptr)
    {
        return head;
    }

    vector<ListNode*> nodes;
    while (head != nullptr)
    {
        nodes.push_back(head);
        head = head->next;
    }

    ListNode *tail = nodes[nodes.size() - 1];
    for (int i=0;i<nodes.size()-1; i++)
    {
        nodes[nodes.size() - 1 - i]->next = nodes[nodes.size() - 2 - i];
    }
    nodes[0]->next = nullptr;
    return tail;
}

TEST(Example, OneElementLinkedList)
{
    auto input = ListNode(1);
    auto reversed = reverseList(&input);
    EXPECT_EQ(1, reversed->val);
}

TEST(Example, EmptyExample)
{
    auto reversed = reverseList(nullptr);
    EXPECT_EQ(nullptr, reversed);
}

TEST(Example, TwoElementLinkedList)
{
    auto input = ListNode(1);
    ListNode second = ListNode(2);
    input.next = &second;
    auto reversed = reverseList(&input); 
    EXPECT_EQ(2, reversed->val);
    EXPECT_EQ(1, reversed->next->val);
    EXPECT_EQ(nullptr, reversed->next->next);
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}