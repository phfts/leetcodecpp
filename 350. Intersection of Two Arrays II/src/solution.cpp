#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ocurrences;
        for (auto &x : nums2)
        {
            if (ocurrences.count(x) == 0)
            {
                ocurrences[x] = 0;
            }
            ocurrences[x]++;
        }
        vector<int> ret;
        for (auto &x : nums1)
        {
            if (ocurrences.count(x) > 0 && ocurrences[x] > 0)
            {
                ocurrences[x]--;
                ret.push_back(x);
            }
        }
        return ret;
    }
};