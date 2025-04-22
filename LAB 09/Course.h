#pragma once 
#include <iostream>
#include <string>
using namespace std;

class Course{
protected:
    string Coursecode;
    int credits;
    Course(string code, int credits) : Coursecode(code), credits(credits) {}
    virtual void calculateGrade() = 0; 
    virtual void display() = 0; 
};