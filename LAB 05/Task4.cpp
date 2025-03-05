#include<iostream>

using namespace std; 

class AlarmSystem{
    string SecurityLevel;
    public:
    AlarmSystem(string level){
        SecurityLevel = level;
    }
    string getlevel(){
        return SecurityLevel;
    }
};

class SmartHome{
    string Homename;
    AlarmSystem *alarm;
    public:
    SmartHome(string name, AlarmSystem *a){
        Homename = name;
        alarm = new AlarmSystem(*a);
    }
    void Display(){
        cout << "Home Name: " << Homename << endl;
        cout<<"Security level "<<alarm->getlevel()<<endl;
    }

    ~SmartHome(){
        delete alarm;
    }
};


int main() {
    AlarmSystem a("HIGH");
    SmartHome myHome("MyHouse", &a);
    myHome.Display();
}