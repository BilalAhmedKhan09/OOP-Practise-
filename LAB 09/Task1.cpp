#include<iostream>

using namespace std;

class Patient {
    protected:
    int ID;
    string Name;
    public:
    Patient(int id, string name): ID(id), Name(name) {}
    virtual void DisplayTreatment() = 0;
    virtual void CalcualteCost() = 0;
};

class inPatient : protected Patient {
    public:
    inPatient(int id, string name) : Patient(id, name) {}
    void DisplayTreatment() override{
        cout << "InPatient Treatment" << endl;
    }
    void CalcualteCost() override{
        cout<<"Free"<<endl;
    }
};  

class OutPatient : protected Patient {
    public:
    OutPatient(int id, string name) : Patient(id, name) {}
    void DisplayTreatment() override{
        cout << "OutPatient Treatment" << endl;
    }
    void CalcualteCost() override{
        cout<<"1000"<<endl;
    }
};

int main(){
    inPatient p1(100, "Smith");
    OutPatient p2(101, "John");

    p1.DisplayTreatment();
    p1.CalcualteCost();

    p2.DisplayTreatment();
    p2.CalcualteCost();
}