#include <gtest/gtest.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(nullptr){};
    ListNode(int val, ListNode *next) : val(val), next(next){};
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *head = nullptr;
    ListNode *dummy = nullptr;
    while (list1 != nullptr || list2 != nullptr)
    {
        if (list1 == nullptr)
        {
            if (head == nullptr)
            {
                return list2;
            }
            else
            {
                dummy->next = list2;
                return head;
            }
        }

        if (list2 == nullptr)
        {
            if (head == nullptr)
            {
                return list1;
            }
            else
            {
                dummy->next = list1;
                return head;
            }
        }

        if (list1->val < list2->val)
        {
            if (head == nullptr)
            {
                head = new ListNode(list1->val);
                dummy = head;
            }
            else
            {
                ListNode *newNode = new ListNode(list1->val);
                dummy->next = newNode;
                dummy = dummy->next;
            }
            list1 = list1->next;
        }
        else
        {
            if (head == nullptr)
            {
                head = new ListNode(list2->val);
                dummy = head;
            }
            else
            {
                ListNode *newNode = new ListNode(list2->val);
                dummy->next = newNode;
                dummy = dummy->next;
            }
            list2 = list2->next;
        }
    }
    return head;
}

TEST(mergeTwoLists, EmptyLists)
{
    EXPECT_EQ(nullptr, mergeTwoLists(nullptr, nullptr));
}

TEST(mergeTwoLists, OneElementWithEmptyList)
{
    ListNode *l1 = new ListNode(10);
    EXPECT_EQ(10, mergeTwoLists(l1, nullptr)->val);
    EXPECT_EQ(nullptr, mergeTwoLists(l1, nullptr)->next);
}

TEST(mergeTwoLists, OneElementInBothLists)
{
    ListNode *l1 = new ListNode(10);
    ListNode *l2 = new ListNode(17);
    ListNode *result = mergeTwoLists(l1, l2);
    EXPECT_EQ(10, result->val);
    EXPECT_EQ(17, result->next->val);
    EXPECT_EQ(nullptr, result->next->next);
}

TEST(mergeTwoLists, OneElementVsTwoElements)
{
    ListNode *l1 = new ListNode(10);
    ListNode *l2 = new ListNode(7, new ListNode(19));
    ListNode *result = mergeTwoLists(l1, l2);
    EXPECT_EQ(7, result->val);
    EXPECT_EQ(10, result->next->val);
    EXPECT_EQ(19, result->next->next->val);
    EXPECT_EQ(nullptr, result->next->next->next);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}