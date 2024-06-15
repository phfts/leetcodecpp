#include <gtest/gtest.h>
#include <vector>

using namespace std;

class CustomStack {
private:
    int maxSize;
    vector<int> arr;
public:
    CustomStack(int maxSize) : maxSize(maxSize) {
    }
    
    void push(int x) {
        arr.push_back(x);
        while (arr.size() > maxSize) {
            arr.pop_back();
        }
    }
    
    int pop() {
        if (arr.empty()) return -1;
        int ans = arr.back();
        arr.pop_back();
        return ans;
    }
    
    void increment(int k, int val) {
        k = k < arr.size() ? k : arr.size();
        for (int i=0; i<k; i++)
            arr[i] += val;
    }
};

TEST(Example, Example1)
{
    CustomStack* obj = new CustomStack(10);
    obj->push(3);
    EXPECT_EQ(3, obj->pop());
    obj->increment(4,7);
    EXPECT_EQ(-1, obj->pop());

    obj->push(4);
    obj->push(5);
    obj->push(6);
    EXPECT_EQ(6, obj->pop());
    EXPECT_EQ(5, obj->pop());
    EXPECT_EQ(4, obj->pop());
    EXPECT_EQ(-1, obj->pop());
}

TEST(Example, Example2)
{
    CustomStack* obj = new CustomStack(10);

    obj->push(4);
    obj->push(5);
    obj->push(6);
    obj->increment(2,7);

    EXPECT_EQ(6, obj->pop());
    EXPECT_EQ(12, obj->pop());
    EXPECT_EQ(11, obj->pop());
    EXPECT_EQ(-1, obj->pop());
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}