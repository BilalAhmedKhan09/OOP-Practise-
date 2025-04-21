#include<iostream>

using namespace std;

class MenuItem {
    protected:
    string Dishname;
    double Cost;
    public:
    MenuItem(string name, double cost): Dishname(name), Cost(cost) {}
    virtual void ShowDetails() = 0;
    virtual void Prepare() = 0;
};

class Appetizers : public MenuItem {
    public:
    Appetizers(string name, double cost): MenuItem(name, cost) {}
    void ShowDetails() override {
        cout<<"Details for appetizer: "<<Dishname<<endl;
        cout<<"Price: "<<Cost<<endl;
    }
    void Prepare() override {
        cout<<"Preparing appetizer : "<<Dishname<<endl;
    }
};

class MainCourse : public MenuItem {
    public:
    MainCourse(string name, double cost): MenuItem(name, cost) {}
    void ShowDetails() override {
        cout<<"Details for Main course: "<<Dishname<<endl;
        cout<<"Price: "<<Cost<<endl;
    }
    void Prepare() override {
        cout<<"Preparing Main course : "<<Dishname<<endl;
    }
};

int main(){
    Appetizers A("Bread Sticks", 3.5);
    MainCourse M("Steak", 10.0);

    A.ShowDetails();
    A.Prepare();

    M.ShowDetails();
    M.Prepare();
}