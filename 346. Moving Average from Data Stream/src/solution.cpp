#include <queue>

using namespace std;

class ListNode
{
public:
    int val = 0;
    ListNode* next = nullptr;
    ListNode(int val) : val(val) {}
};

class MovingAverage
{
private:
    ListNode* head;
    ListNode* tail;
    int size;
    double sum;
    int currentSize;

public:
    MovingAverage(int size) : size(size), sum(0), head(nullptr), tail(nullptr), currentSize(0)
    {
    }

    double next(int val)
    {
        if (currentSize == 0)
        {
            sum += val;
            auto newHead = new ListNode(val);
            head = newHead;
            tail = head;
            currentSize = 1;
            return sum / currentSize;
        }
        else if (currentSize < size)
        {
            addNode(val);
            return sum / ++currentSize;
        }

        sum -= head->val;
        auto oldHead = head;
        head = head->next;
        delete oldHead;
        
        addNode(val);
        return sum / currentSize;
    }

    void addNode(int val)
    {
        sum += val;
        auto newNode = new ListNode(val);
        tail->next = newNode;
        tail = tail->next; 
    }
};
