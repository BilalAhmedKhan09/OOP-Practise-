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
    char getLicenseType(){
        return LicenseType;
    }
};


class Vehicle{
    string Model;
    float Price;
    char LicenseRequired;
    public:

    Vehicle(string model, float price, char requirement){
        Model = model;
        Price = price;
        LicenseRequired = requirement;
    }

    char GetRequirement(){
        return LicenseRequired;
    }

    void display(){
        cout<<"Model: "<<Model<<"\t";
        cout<<"Price (per day) "<<Price<<"\t";
        cout<<"License requirement: "<<LicenseRequired<<endl;
    }

};



void Rent(Vehicle *vehicles[3], User &user) {
    int choice;
    cout << "PICK THE CAR OF YOUR CHOOSING (1, 2, or 3)" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Car " << i + 1 << ": ";
        vehicles[i]->display();
    }
    cin >> choice;
    if (choice < 1 || choice > 3) {
        cout << "Invalid choice!" << endl;
        return;
    }
    char requiredLicense = vehicles[choice - 1]->GetRequirement();
    char userLicense = user.getLicenseType();
    if (requiredLicense == 'L' || userLicense == 'F' || requiredLicense == userLicense) {
        cout << "Car has been rented successfully!" << endl;
    } 
    else {
        cout << "Sorry, you are ineligible to rent this vehicle." << endl;
    }
}


int main(){
    int age, id, contact;
    char license;
    cout<<"Enter your age, id, contact in order..."<<endl;
    cin>>age>>id>>contact;
    cout<<"Enter your license type"<<endl;
    cin>>license;
    User user(contact,age,id,license);
    Vehicle **vehicles;
    vehicles = new Vehicle*[3];
    vehicles[0] = new Vehicle("Toyota",10, 'L');
    vehicles[1] = new Vehicle("Honda",10, 'F');
    vehicles[2] = new Vehicle("Kia",10, 'M');
    Rent(vehicles, user);
    user.UpdateDetails(000,19,0725,'L');
    Rent(vehicles, user);
    for (int i = 0; i < 3; i++) {
        delete vehicles[i];
    }
    delete[] vehicles;
}