#include "./list_node.cpp"

#include <iostream>
#include <vector>

using namespace std;

int listSize(ListNode *head)
{
    int size = 0;
    ListNode *dummy = head;
    while (dummy != nullptr)
    {
        size++;
        dummy = dummy->next;
    }
    return size;
}

class Solution
{
public:
    bool isPalindrome(ListNode *head);
};

bool Solution::isPalindrome(ListNode *head)
{
    int size = listSize(head);

    if (size < 2)
        return true;

    if (size == 2)
        return head->val == head->next->val;

    int pos = 0;
    ListNode *dummy = head;
    ListNode *fast = nullptr;
    ListNode *prev = nullptr;
    ListNode *slow = nullptr;
    while (dummy != nullptr)
    {
        slow = prev;
        prev = fast;
        fast = dummy;

        if (prev != nullptr && (pos >= size/2 + 2))
        {
            prev->next = slow;
        }
        dummy = dummy->next;
        pos++;
    }

    fast->next = prev;
    ListNode* tail = fast;

    while (true)
    {
        if (tail->val != head->val)
            return false;

        if (size % 2 == 0 && head->next == tail)
            return true;
        
        if (size % 2 == 1 && head == tail)
            return true;

        tail = tail->next;
        head = head->next;
    }
}
