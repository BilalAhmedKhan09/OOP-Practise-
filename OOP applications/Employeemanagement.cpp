#include<iostream>

using namespace std;

class Employee{
    string Name;
    int EmployeeID;
    static int nextEmployeeID;
    float Salary;
    const float Max_salary;
    public:
    Employee(string n, float s):Salary(s),Name(n),
        Max_salary(1000),EmployeeID(generateEmployeeID()){}

    static int generateEmployeeID(){
        return nextEmployeeID ++;
    }  
    void display() {
        cout << "Employee ID: " << EmployeeID << "\n";
        cout << "Name: " << Name << "\n";
        cout << "Salary: $" << Salary << "\n";
        cout << "Max Salary Limit: $" << Max_salary << "\n";
    }
};
int Employee::nextEmployeeID = 1;

int main(){
    Employee emp1("Alice", 800);
    Employee emp2("Bob", 950);
    emp1.display();
    cout << "-----------------\n";
    emp2.display();
}