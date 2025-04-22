#include "LectureCourse.h"

void LectureCourse::calculateGrade(){
    int marks;
    cout << "Enter marks for Lecture Course " << Coursecode << ": ";
    cin >> marks;
    cout<< "your grade is: ";
    if (marks >= 90)
        cout << "Grade: A" << endl;
    else if (marks >= 80)
        cout << "Grade: B" << endl;
    else if (marks >= 70)
        cout << "Grade: C" << endl;
    else if (marks >= 60)
        cout << "Grade: D" << endl;
    else
        cout << "Grade: F" << endl;
}
void LectureCourse::display(){
    cout << "Course Code: " << Coursecode << endl;
    cout << "Credits: " << credits << endl;
    cout << "Course Type: Lecture" << endl;
}