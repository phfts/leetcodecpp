#include <gtest/gtest.h>
#include <string>
#include <vector>

using namespace std;

// 0 <= nums.length <= 20
// case 1: empty nums returns no interval
// case 2: nums with length 1 returns the number
// case 3: nums with length 2 (e.g: [a,b]) returns ["a->b"] if b == a + 1
//         otherwise it will return [a,b]
// case 4: nums with length 3 will get last ans. If it is one number smaller it will change the interval

class Interval
{
public:
    int start;
    int finish;

    Interval(int start, int finish) : start(start), finish(finish) {}

    std::string toString()
    {
        if (start == finish)
        {
            return to_string(start);
        }
        return to_string(start) + "->" + to_string(finish);
    }
};

vector<Interval> summaryRangesHelper(vector<int>& nums) {
    vector<Interval> intervals;
    for (int i=0; i<nums.size(); i++)
    {
        int num = nums[i];
        if (intervals.empty() || intervals[intervals.size() - 1].finish < num - 1)
        {
            auto interval = Interval(num, num);
            intervals.push_back(interval);
        }
        else
        {
            intervals[intervals.size() - 1].finish = num;
        }
    }
    return intervals;
}

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ans;
    for (auto &interval : summaryRangesHelper(nums))
    {
        std::cout << "Added " << interval.toString() << " interval." << std::endl;
        ans.push_back(interval.toString());
    }
    return ans;
}

TEST(Example, Example1)
{
    vector<int> input = {};
    vector<string> expected = {};
    EXPECT_EQ(expected, summaryRanges(input));
}


TEST(Example, ExampleWithOneElement)
{
    vector<int> input = {1};
    vector<string> expected = {"1"};
    EXPECT_EQ(expected, summaryRanges(input));
}

TEST(Example, ExampleWithTwoElements)
{
    vector<int> input1 = {1, 3};
    vector<string> expected1 = {"1", "3"};
    EXPECT_EQ(expected1, summaryRanges(input1));

    vector<int> input2 = {1, 2};
    vector<string> expected2 = {"1->2"};
    EXPECT_EQ(expected2, summaryRanges(input2));    
}

TEST(Example, ExampleWithTreeElements)
{
    vector<int> input1 = {1, 2, 3};
    vector<string> expected1 = {"1->3"};
    EXPECT_EQ(expected1, summaryRanges(input1));

    vector<int> input2 = {1, 2, 4};
    vector<string> expected2 = {"1->2", "4"};
    EXPECT_EQ(expected2, summaryRanges(input2));    
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}