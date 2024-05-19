#include <map>


using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
};

ListNode *middleNode(ListNode* head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    ListNode* dummy = head;
    int size = 0;
    while(dummy != nullptr)
    {
        dummy = dummy->next;
        size++;
    }

    int pos = 0;
    ListNode* ans = head;
    while (pos < size/2)
    {
        ans = ans->next;
        pos++;
    }

    return ans;
}