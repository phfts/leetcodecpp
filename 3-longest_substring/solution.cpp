#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;


int lengthOfLongestSubstring(string s)
{
    unordered_set<char> values;

    // "a"
    int maxSize = 0;
    int leftPos = 0;

    for (int pos = 0; pos < s.length(); pos++)
    {
        char c = s[pos];
        if (values.find(c) == values.end())
        {
            int candidateSize = pos - leftPos + 1;
            maxSize = maxSize > candidateSize ? maxSize : candidateSize;
            values.insert(c);
        }
        else
        {
            // aabaabxbb
            // values = {a,b,c,b}
            for (auto &c : values)
            {
                std::cout << c;
            }
            std::cout << std::endl;

            for (int j = leftPos; j < pos; j++)
            {
                char leftChar = s[j];
                if (leftChar != c)
                {
                    values.erase(s[j]);
                    leftPos++;
                }
                else
                {
                    leftPos++;
                    break;
                }
            }
        }
    }
    return maxSize;
}
