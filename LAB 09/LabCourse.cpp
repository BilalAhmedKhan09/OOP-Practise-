#include "LabCourse.h"

void LabCourse::calculateGrade(){
    int marks;
    cout << "Enter marks for Lab Course " << Coursecode << ": ";
    cin >> marks;
    cout<< "your grade is: ";
    if (marks >= 90)
        cout << "A+" << endl;
    else if (marks >= 80)
        cout << "A" << endl;
    else if (marks >= 70)
        cout << "B" << endl;
    else if (marks >= 60)
        cout << "C" << endl;
    else
        cout << "D" << endl;
}

void LabCourse::display(){
    cout << "Course Code: " << Coursecode << endl;
    cout << "Credits: " << credits << endl;
    cout << "Course Type: Lab" << endl;
}