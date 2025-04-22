#include "LectureCourse.h"

void LectureCourse::calculateGrade(){
    int marks;
    cout << "Enter marks for Lecture Course " << Coursecode << ": ";
    cin >> marks;
    cout<< "your grade is: ";
    if (marks >= 90)
        cout << "A" << endl;
    else if (marks >= 80)
        cout << "B" << endl;
    else if (marks >= 70)
        cout << "C" << endl;
    else if (marks >= 60)
        cout << "D" << endl;
    else
        cout << "F" << endl;
}
void LectureCourse::display(){
    cout << "Course Code: " << Coursecode << endl;
    cout << "Credits: " << credits << endl;
    cout << "Course Type: Lecture" << endl;
}