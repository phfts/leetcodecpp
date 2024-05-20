#include <gtest/gtest.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(nullptr) {};
    ListNode(int val, ListNode* next) : val(val), next(next) {};
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == nullptr && list2 == nullptr)
        return nullptr;

    if (list1 == nullptr) 
        return list2;
    
    if (list2 == nullptr)
        return list1;

    if (list1->val < list2->val)
    {
        auto next = mergeTwoLists(list1->next, list2);
        auto ret = new ListNode(list1->val, next);
        return ret;
    }
    else 
    {
        auto next = mergeTwoLists(list1, list2->next);
        auto ret = new ListNode(list2->val, next);
        return ret;
    }
}

TEST(mergeTwoLists, EmptyLists)
{
    EXPECT_EQ(nullptr, mergeTwoLists(nullptr, nullptr));
}


TEST(mergeTwoLists, OneElementWithEmptyList)
{
    ListNode* l1 = new ListNode(10);
    EXPECT_EQ(10, mergeTwoLists(l1, nullptr)->val);
    EXPECT_EQ(nullptr, mergeTwoLists(l1, nullptr)->next);
}

TEST(mergeTwoLists, OneElementInBothLists)
{
    ListNode* l1 = new ListNode(10);
    ListNode* l2 = new ListNode(17);
    ListNode* result = mergeTwoLists(l1, l2);
    EXPECT_EQ(10, result->val);
    EXPECT_EQ(17, result->next->val);
    EXPECT_EQ(nullptr, result->next->next);
}


TEST(mergeTwoLists, OneElementVsTwoElements)
{
    ListNode* l1 = new ListNode(10);
    ListNode* l2 = new ListNode(7, new ListNode(19));
    ListNode* result = mergeTwoLists(l1, l2);
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