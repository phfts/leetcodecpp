#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct MyDLLNode {
    string val;
    MyDLLNode* next;
    MyDLLNode* prev;

    MyDLLNode(string val) : val(val), next(nullptr), prev(nullptr) {}
};

class BrowserHistory
{
private:
    MyDLLNode *head;
    MyDLLNode *tail;
    int pos;

public:
    BrowserHistory(string homepage)
    {
        pos = 0;
        head = new MyDLLNode(homepage);
        tail = head;
    }

    void visit(string url)
    {
        if (tail->next) {
            MyDLLNode *x = tail->next;
            x->prev = nullptr;
        }
        MyDLLNode* node = new MyDLLNode(url); // TODO: manage memory 
        tail->next = node;
        node->prev = tail;
        tail = node;
    }

    string back(int steps)
    {
        while (steps-- > 0 && tail->prev)
            tail = tail->prev;

        return tail->val;
    }

    string forward(int steps)
    {
        while (steps-- > 0 && tail->next)
            tail = tail->next;

        return tail->val;
    }
};

TEST(Example, Example1)
{
    BrowserHistory *obj = new BrowserHistory("www.google.com");
    EXPECT_EQ("www.google.com", obj->back(1));
    EXPECT_EQ("www.google.com", obj->back(1));
}

TEST(Example, Example2)
{
    BrowserHistory *obj = new BrowserHistory("www.google.com");
    obj->visit("www.facebook.com");
    EXPECT_EQ("www.google.com", obj->back(1));
    EXPECT_EQ("www.google.com", obj->back(1));
    EXPECT_EQ("www.facebook.com", obj->forward(1));
}

TEST(Example, Example3)
{
    BrowserHistory *obj = new BrowserHistory("website1");
    EXPECT_EQ("website1", obj->back(1));

    obj->visit("website2");
    obj->visit("website3");
    obj->visit("website4");
    EXPECT_EQ("website2", obj->back(2));

    obj->visit("website5");
    EXPECT_EQ("website5", obj->forward(2));
}

TEST(Example, Example4)
{
    BrowserHistory *obj = new BrowserHistory("website1");
    EXPECT_EQ("website1", obj->back(1));

    obj->visit("website2");
    obj->visit("website3");
    obj->visit("website4");
    obj->visit("website5");
    obj->visit("website6");
    EXPECT_EQ("website4", obj->back(2));
    EXPECT_EQ("website5", obj->forward(1));
}

TEST(Example, Example5)
{
    BrowserHistory *obj = new BrowserHistory("w1");  // [w1], []
    EXPECT_EQ("w1", obj->back(1)); //  [w1], []

    obj->visit("w2"); //  [w1, w2], []
    obj->visit("w3");  //  [w1, w2, w3], []
    EXPECT_EQ("w1", obj->back(10)); //  [w1], [w2, w3]

    obj->visit("w4"); //  [w1, w4], []
    obj->visit("w5");  //  [w1, w4, w5], []
    EXPECT_EQ("w1", obj->back(10));  //  [w1], [w4, w5]
    EXPECT_EQ("w5", obj->forward(10));
}

TEST(Example, Example6) {
    BrowserHistory *obj = new BrowserHistory("momn.com"); // [mon] []
    obj->visit("bx.com"); // [mon bx] []
    obj->visit("bjyfmln.com"); // [mon bx bjyfmln] []
    EXPECT_EQ("momn.com", obj->back(3)); // [mon bx] [bjyfmln] -> [mon] [bx bjyfmln]
    obj->visit("ijtrqk.com"); // [mon ijtrqk] []
    obj->visit("dft.com"); // [mon ijtrqk dft] []
    EXPECT_EQ("momn.com", obj->back(10)); // [mon] [ijtrqk dft]
    EXPECT_EQ("dft.com", obj->forward(10)); // [mon] [ijtrqk dft]
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}