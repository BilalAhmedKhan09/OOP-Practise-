#include "Course.h"

class LectureCourse : public Course{
public:
    LectureCourse(string Coursecode, int credits): Course(Coursecode, credits) {}
    void calculateGrade()override;
    void display()override;

};