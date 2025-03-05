#include<iostream>

using namespace std;

class Apartment{
    int ID;
    string Address;
    string *Name;
    
    public:
    Apartment(int id, string address, string name){
        ID = id;
        Address = address;
        Name = new string(name);
    }
    Apartment(Apartment &a){
        ID = a.ID;
        Address = a.Address;
        Name = new string(*a.Name); 
    }
    void display(){
        cout << "Apartment ID: " << ID << endl;
        cout << "Address: " << Address << endl;
        cout << "Owner: " << *Name << endl;
    }

    // Destructor
    ~Apartment() {
        delete Name;
    }
};

int main() {
    Apartment a1(101, "123 Main Street", "John");
    cout << "Original Apartment:\n";
    a1.display();
    Apartment a2 = a1;
    cout << "\nCopied Apartment:\n";
    a2.display();
}