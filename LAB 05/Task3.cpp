#include<iostream>

using namespace std; 

class Employee{
    string Name;
    string Designation;
    public:
    Employee(string name, string designation) {
        Name = name;
        Designation = designation;
    }
    void display() {
        cout << "Employee: " << Name << " | Designation: " << Designation << endl;
    }
};

class Project{
    string Title;
    int Deadline;
    Employee **employees;
    int empcount = 0;
    public:
    Project(string title, int deadline){
        Title = title;
        Deadline = deadline;
        employees = new Employee*[10];
        for(int i=0;i<10;i++){
            employees[i] = nullptr;
        } 
    }
    void addEmployee(Employee *e){
        employees[empcount] = e;
        empcount ++;
    }
    void display() {
        cout << "Project: " << Title << " | Deadline: " << Deadline << endl;
        cout << "Assigned Employees:\n";
        for (int i=0;i<empcount;i++) {
            employees[i]->display();
        }
    }
};

int main() {
    Employee e1("Alice", "Software Engineer");
    Employee e2("Bob", "Project Manager");
    Employee e3("Charlie", "Developer");
    Project p1("AI Development", 30);
    p1.addEmployee(&e1);
    p1.addEmployee(&e2);
    p1.addEmployee(&e3);
    cout << "\nProject Details:\n";
    p1.display();
}