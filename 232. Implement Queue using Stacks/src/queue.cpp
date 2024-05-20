#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> stack1;
    stack<int> stack2;

    void move(stack<int> &s1, stack<int> &s2)
    {
        while (!s1.empty())
        {
            auto x = s1.top();
            s1.pop();
            s2.push(x);
        }
    }

    int getFirst(bool remove)
    {
        move(stack1, stack2);
        auto ret = stack2.top();
        if (remove) stack2.pop();
        move(stack2, stack1);
        return ret;
    }

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stack1.push(x);
    }
    
    int pop() {
        if (stack1.empty())
            throw runtime_error("Cannot pop empty queue");
        
        return getFirst(true);
    }
    
    int peek() {
        if (stack1.empty())
            throw runtime_error("Cannot peek empty queue");

        return getFirst(false);
    }
    
    bool empty() {
        return stack1.size() == 0;
    }
};