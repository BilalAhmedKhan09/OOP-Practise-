#include<iostream>

using namespace std;

class Employee{
    protected:
    string Name;
    float Salary;
    public:
    Employee(string name, float salary){
        Name = name;
        Salary = salary;
    }
    virtual void Display(){
        cout<<"Name: "<<Name<<endl;
        cout<<"Salary: "<<Salary<<endl;
    }
};


class Manager : protected Employee{
    float Bonus;
    public:
    Manager(string name, float bonus, float salary):Employee(name, salary){
        Bonus = bonus;
    }
    void Display() override{
        cout<<"Name: "<<Name<<endl;
        cout<<"Salary: "<<Salary<<endl;
        cout<<"Bonus: "<<Bonus<<endl;
    }
};

int main(){
    Manager m("Josh",5000,500);
    m.Display();
}