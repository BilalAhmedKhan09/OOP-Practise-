#include<iostream>

using namespace std;

class Vehicle{
private:
    string modelName;
    double cost;

public:
    Vehicle(string name, double c) : modelName(name), cost(c) {}

    friend class StockManager;
    friend void CompareCosts(Vehicle &v1, Vehicle &v2);
};

class StockManager{
public:
    void modifyCost(Vehicle &veh, double newCost){
        veh.cost = newCost;
    }

    void showInfo(Vehicle &veh){
        cout << "Model Name: " << veh.modelName << endl;
        cout << "Cost: " << veh.cost << "$" << endl;
    }
};

void CompareCosts(Vehicle &v1, Vehicle &v2){
    if (v1.cost > v2.cost){
        cout << v1.modelName << " costs more than " << v2.modelName << endl;
    }
    else if (v1.cost < v2.cost){
        cout << v2.modelName << " costs more than " << v1.modelName << endl;
    }
    else{
        cout << v1.modelName << " and " << v2.modelName << " are priced equally." << endl;
    }
}

int main(){
    Vehicle vehicle1("Toyota Corolla", 20000);
    Vehicle vehicle2("Honda Civic", 22000);
    StockManager sm;

    cout << "Initial price comparison:" << endl;
    CompareCosts(vehicle1, vehicle2);

    cout << "\nVehicle information before update:" << endl;
    sm.showInfo(vehicle1);
    sm.showInfo(vehicle2);

    cout << "\nModifying price of Toyota Corolla to 23000$..." << endl;
    sm.modifyCost(vehicle1, 23000);

    cout << "\nUpdated vehicle details:" << endl;
    sm.showInfo(vehicle1);
}
