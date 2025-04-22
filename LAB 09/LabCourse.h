#include "Course.h"

class LabCourse : public Course{
public:
    LabCourse(string code, int credits): Course(code, credits){}
    void calculateGrade() override;
    void display()override;
};