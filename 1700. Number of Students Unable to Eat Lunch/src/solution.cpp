
#include <iostream>
#include <vector>

using namespace std;

bool hasStudentWishingSandwich(vector<int>& students, int sandwich)
{
    for (auto &student : students)
    {
        if (student == sandwich)
        {
            return true;
        }
    }
    return false;
}

void rotate(vector<int> &elements)
{
    if (elements.empty())
    {
        return;
    }

    int firstElement = elements[0];
    elements.erase(elements.begin());
    elements.push_back(firstElement);
}

// circular (0) or squared sandwiches (1)
//studants are in a queue
int countStudents(vector<int>& students, vector<int>& sandwiches) {
    if (students.size() != sandwiches.size())
    {
        throw runtime_error("Students and sandwiches vectors must have equal sizes");
    }

    if (students.size() == 0) 
    {
        return 0;
    }

    if (students[0] == sandwiches[0])
    {
        students.erase(students.begin());
        sandwiches.erase(sandwiches.begin());
        return countStudents(students, sandwiches);
    }
    else
    {
        int sandwich = sandwiches[0];
        if (hasStudentWishingSandwich(students, sandwich)) //n
        {
            rotate(students); // n
            return countStudents(students, sandwiches); //n
        }
        else
        {
            return students.size();
        }
    }

    return -1;
}
