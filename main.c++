#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int numCourses, creditHours[20];
    char grades[20];
    string courseName[20];

    double previousCGPA = 0.0;
    int totalCreditHoursBefore = 0;
    double totalGradePointsBefore = 0.0;

    cout << "Welcome to CGPA Calculator" << endl;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    // If the user has a previous CGPA, collect the necessary data
    char hasPreviousCGPA;
    cout << "Do you have a previous CGPA? (Y/N): ";
    cin >> hasPreviousCGPA;

    if (hasPreviousCGPA == 'Y' || hasPreviousCGPA == 'y')
    {
        cout << "Enter previous CGPA: ";
        cin >> previousCGPA;
        cout << "Enter total credit hours before this semester: ";
        cin >> totalCreditHoursBefore;
        cout << "Enter total grade points before this semester: ";
        cin >> totalGradePointsBefore;
    }

    for (int i = 0; i < numCourses; i++)
    {
        cout << endl
             << "Enter course name: ";
        cin >> courseName[i];
        cout << "Enter credit hours: ";
        cin >> creditHours[i];
        cout << "Enter Grade(A/B/C/D/E/F): ";
        cin >> grades[i];
    }

    double totalGradePoints = totalGradePointsBefore;
    int totalCredits = totalCreditHoursBefore;

    for (int i = 0; i < numCourses; i++)
    {
        int gradePoints = 0;
        if (grades[i] == 'A')
        {
            gradePoints = 4;
        }
        else if (grades[i] == 'B')
        {
            gradePoints = 3;
        }
        else if (grades[i] == 'C')
        {
            gradePoints = 2;
        }
        else if (grades[i] == 'D')
        {
            gradePoints = 1;
        }
        else if (grades[i] == 'E')
        {
            gradePoints = 0;
        }

        totalGradePoints += gradePoints * creditHours[i];
        totalCredits += creditHours[i];

        // Print course details for verification
        cout << "Course Name: " << courseName[i] << endl;
        cout << "Credit Hours: " << creditHours[i] << endl;
        cout << "Grade: " << grades[i] << endl;
        cout << "Grade Points: " << gradePoints << endl;
        cout << endl;
    }

    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "Total Credits: " << totalCredits << endl;

    double semesterGPA = totalGradePoints / totalCredits;
    double GPA = ceil(semesterGPA * 100) / 100;
    cout << "Semester GPA: " << semesterGPA << endl;

    // Calculate and display CGPA
    double CGPA = (totalGradePoints + previousCGPA * totalCreditHoursBefore) / (totalCredits + totalCreditHoursBefore);
    cout << "CGPA: " << CGPA << endl;

    return 0;
}
