
#include <iostream>
#include <vector>

using namespace std;

// circular (0) or squared sandwiches (1)
//studants are in a queue
int countStudents(vector<int>& students, vector<int>& sandwiches) {
    int studentsWantingRounded = 0;
    int studentsWantingSquared = 0;

    for (int i=0; i<students.size(); i++)
    {
        if (students[i] == 0)
        {
            studentsWantingRounded++;
        }
        else
        {
            studentsWantingSquared++;
        }
    }

    for (int i=0;i<sandwiches.size();i++)
    {
        if (sandwiches[i] == 1)
        {
            if (studentsWantingSquared == 0)
            {
                return sandwiches.size() - i;
            }
            else
            {
                studentsWantingSquared--;
            }
        }
        else
        {
            if (studentsWantingRounded == 0)
            {
                return sandwiches.size() - i;
            }
            else
            {
                studentsWantingRounded--;
            }
        }
    }

    return 0;
}
