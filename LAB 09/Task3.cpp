#include<iostream>
#include "LabCourse.h"
#include "lectureCourse.h"

int main(){
    LectureCourse Course1 ("CS1", 3);
    LabCourse Course2 ("CS2", 4);

    Course1.calculateGrade();
    Course1.display();

    Course2.calculateGrade();
    Course2.display();
}