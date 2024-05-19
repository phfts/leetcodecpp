#include <string>
#include <cstring>

using namespace std;

int abs(int value) {
    if (value < 0) 
    {
        return -value;
    }
    return value;
}

int score(const string& s)
{
    int sum = 0;
    for (int i=0; i<s.length() -1; i++)
    {
        sum += abs(s[i+1] - s[i]);
    }
    return sum;
}