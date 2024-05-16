#include <iostream>

// You are given two non-empty linked lists representing two non-negative integers. The digits are
// stored in reverse order, and each of their nodes contains a single digit. Add the two numbers
// and return the sum as a linked list.

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
};

ListNode* addTwoNumbers(ListNode *l1, ListNode *l2, int carry)
{
    if (carry == 0 && l1 == nullptr && l2 == nullptr)
    {
        return nullptr;
    }
    
    if (l1 == nullptr) 
    {
        auto x = new ListNode(0);
        return addTwoNumbers(x, l2, carry);
    }

    if (l2 == nullptr) 
    {
        auto x = new ListNode(0);
        return addTwoNumbers(l1, x, carry);
    }

    int sum = carry + l1->val + l2->val;
    int digit = sum % 10;
    carry = sum / 10;
    ListNode* result = new ListNode(digit);

    ListNode* next = addTwoNumbers(l1->next, l2->next, carry);
    result->next = next;
    return result;
}

ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
{
    return addTwoNumbers(l1, l2, 0);
}