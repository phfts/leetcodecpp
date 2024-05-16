
#include <vector>
#include <map>

using namespace std;

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

vector<int> getTwoSum(vector<int> arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == target)
            {
                return (vector<int>{i, j});
            }
        }
    }
    return (vector<int>{});
}

vector<int> getTwoSumOptimized(vector<int> arr, int target)
{
    map<int, int> indexPerValue;
    for (int i = 0; i < arr.size(); i++)
    {
        int value = arr[i];
        int complement = target - value;
        if (indexPerValue.find(complement) == indexPerValue.end())
        {
            indexPerValue[value] = i;
        }
        else
        {
            return (vector<int>{indexPerValue[complement], i});
        }
    }
    return (vector<int>{-1, -1});
}