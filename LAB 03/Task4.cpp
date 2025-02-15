#include<iostream>

using namespace std;

class Car{
    string brand;
    int fuelcapacity;
    int model;
    int currentfuellevel = 0;
    public:
    Car(string name, int make, int capacity){
        model = make;
        fuelcapacity = capacity;
        brand = name;
    }

    void setfuellevel(int num){
        if(num > fuelcapacity){
            cout<<"This value exceeds the fuel capacity"<<endl;
            return;
        }
        if(currentfuellevel == 0 && num < 0){
            cout<<"No more fuel"<<endl;
            return;
        }
        if(currentfuellevel == fuelcapacity && num > 0){
            cout<<"Fuel tank already full"<<endl;
            return;
        }
        currentfuellevel +=num;
        if(currentfuellevel < 5){
            cout<<"Fuel level low... please refuel"<<endl;
        }
    }

    int getfuelstatus(){
        return currentfuellevel;
    }
};

void displayMenu() {
    cout << "\nCar Fuel Management System" << endl;
    cout << "1. Set Fuel Level" << endl;
    cout << "2. Check Fuel Status" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Car toyota("Toyota", 2016, 20);

    int choice, fuelAmount;
    
    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the amount of fuel to add: ";
                cin >> fuelAmount;
                toyota.setfuellevel(fuelAmount);
                break;
            case 2:
                cout << "Current fuel level: " << toyota.getfuelstatus() << " liters" << endl;
                break;
            case 3:
                cout << "Exiting system. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}
