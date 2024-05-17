#include <string>
#include <map>
#include <vector>

using namespace std;

class Logger
{
private:
    int flushTime;
    map<string, int> messagesPerTime;

public:
    Logger() : flushTime(10) {}

    bool shouldPrintMessage(int timestamp, string message)
    {
        if (messagesPerTime.find(message) != messagesPerTime.end())
        {
            int lastTimestamp = messagesPerTime[message];
            if (timestamp - lastTimestamp < 10)
            {
                return false;
            }
            else
            {
                messagesPerTime[message] = timestamp;
                return true;
            }
        }
        messagesPerTime[message] = timestamp;
        return true;
    }
};