#include <gtest/gtest.h>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};

// n>=0 and n <= 300
// ascending order
ListNode *deleteDuplicates(ListNode *head)
{
    if (head == nullptr) 
        return nullptr;

    if (head->next == nullptr)
        return head;

    ListNode* curr = head;
    while (curr != nullptr)
    {
        ListNode* next = curr->next;
        while (true)
        {
            if (next == nullptr)
                break;

            if (curr->val != next->val)
                break;

            next = next->next;
        }
        curr->next = next;
        curr = next;
    }

    return head;
}

TEST(Example, ExampleEmpty)
{
    EXPECT_EQ(nullptr, deleteDuplicates(nullptr));
}

TEST(Example, ExampleSingleElement)
{
    ListNode *root = new ListNode(1);
    EXPECT_EQ(1, deleteDuplicates(root)->val);
}

TEST(Example, ExampleTwoElements)
{
    ListNode *input1 = new ListNode(1, new ListNode(2));
    EXPECT_EQ(1, deleteDuplicates(input1)->val);
    EXPECT_EQ(2, deleteDuplicates(input1)->next->val);

    ListNode *input2 = new ListNode(1, new ListNode(1));
    EXPECT_EQ(1, deleteDuplicates(input2)->val);
    EXPECT_EQ(nullptr, deleteDuplicates(input2)->next);
}

TEST(Example, ExampleThreeElements)
{
    ListNode *input1 = new ListNode(1, new ListNode(2, new ListNode(3)));
    EXPECT_EQ(1, deleteDuplicates(input1)->val);
    EXPECT_EQ(2, deleteDuplicates(input1)->next->val);
    EXPECT_EQ(3, deleteDuplicates(input1)->next->next->val);

    ListNode *input2 = new ListNode(1, new ListNode(1, new ListNode(1)));
    EXPECT_EQ(1, deleteDuplicates(input2)->val);
    EXPECT_EQ(nullptr, deleteDuplicates(input2)->next);
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}