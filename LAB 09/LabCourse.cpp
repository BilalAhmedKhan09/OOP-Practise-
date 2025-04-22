#include "LabCourse.h"

void LabCourse::calculateGrade(){
    int marks;
    cout << "Enter marks for Lab Course " << Coursecode << ": ";
    cin >> marks;
    cout<< "your grade is: ";
    if (marks >= 90)
        cout << "Grade: A+" << endl;
    else if (marks >= 80)
        cout << "Grade: A" << endl;
    else if (marks >= 70)
        cout << "Grade: B" << endl;
    else if (marks >= 60)
        cout << "Grade: C" << endl;
    else
        cout << "Grade: D" << endl;
}

void LabCourse::display(){
    cout << "Course Code: " << Coursecode << endl;
    cout << "Credits: " << credits << endl;
    cout << "Course Type: Lab" << endl;
}