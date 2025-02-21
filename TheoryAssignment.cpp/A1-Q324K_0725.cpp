#include<iostream>

using namespace std;

class User{
    int Contact;
    int Age;
    int ID;
    char LicenseType;
    public:

    User(int c, int a, int i, char l){
        Contact = c;
        Age = a;
        ID = i;
        LicenseType = l;
    }

    void UpdateDetails(int contact, int age, int id, char licenseType){
        Contact = contact;
        Age = age;
        ID = id;
        LicenseType = licenseType;
    }
};


class Vehicle{
    string Model;
    float Price;
    char LicenseRequired;
    public:

    Vehicle(string model, flaot price, char requirement){
        Model = model;
        Price = price;
        LicenseRequired = requirement;
    }

    char GetRequirement(char license){
        return LicenseRequired;
    }

};

int main(){
    int age, id, contact;
    char license;
    cout<<"Enter your age, id, contact in order..."<<endl;
    cin>>age>>id>>contact;
    cout<<"Enter your license type"<<endl;
    cin>>license;
    User user(contact,age,id,license);
    Vehicle *vehicles;
    vehicles = new Vehicle(3);
    vehicles[i]()
}