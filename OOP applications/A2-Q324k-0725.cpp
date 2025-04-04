#include<iostream>

using namespace std;

class Vehicle{
    protected:
    int ID;
    static int TotalActiveDeliveries;
    public:
    Vehicle(int id): ID(id) {}
    int Calc_Optimal_Route(float totalweight, int Totalitems, bool islate){
        if(islate == true){
            return 1;
        }
        else if(totalweight > 5 || Totalitems > 5){
            return 2;
        }
        else if(totalweight < 5){
            return 3;
        }
        else {
            return 4;
        }
    }
    static void AddDelivery(){
        TotalActiveDeliveries ++;
    }
    int getID(){
        return ID;
    }
    virtual void Calc_Delivery_Time(int VehicleID, int distance){
        if(VehicleID/100==1){
            cout<<"Delivery to be made by Ramzan Time Ship"<<endl;
        }
        if(VehicleID/100==2){
            cout<<"Delivery to be made by Ramzan Hyperpod"<<endl;
        }
        if(VehicleID/100==3){
            cout<<"Delivery to be made by Ramzan Drone"<<endl;
        }
    }
    virtual void MovementStrategy(){}
    virtual void Command(string order, int packageid) {
        cout<<"Package: "<<packageid<<" will be delivered shortly"<<endl;
        AddDelivery();
    }
    virtual void Command(string order, int packageid, int urgenctLevel){
        Command(order,packageid);
    }
    friend bool ResolveConflict(Vehicle& v1, Vehicle& v2, int distance);
};

int Vehicle::TotalActiveDeliveries = 0;
class RamzanHyperpod;

class RamzanDrone: public Vehicle{
    int efficiency_percent = 80; 
    int capacity_kg = 4;
    int Speed_km = 50;
    bool Highspeed = false;
    public:
    RamzanDrone(int id): Vehicle(id) {}
    void MovementStrategy()override{
        cout<<"Picking the best aerial route"<<endl;
    }
    void Calc_Delivery_Time(int VehicleID, int distance)override {
        cout << "Will take " << (distance / Speed_km) * 60 << " minutes" << endl;
        MovementStrategy();
        Vehicle::Calc_Delivery_Time(VehicleID,distance);
    }
    void Command(string order, int packageid, int urgenctLevel)override {
        cout<<"Activating high speed mode"<<endl;
        Highspeed = true;
        AddDelivery();
    }
    void Command(string order, int packageid) override {
        Vehicle::Command(order, packageid);
    }
    friend bool ResolveConflict(RamzanDrone& v1, RamzanHyperpod& v2, int distance);
};

class RamzanTimeShip : public Vehicle{
    int efficiency_percent = 40;
    public:
    RamzanTimeShip(int id): Vehicle(id) {}
    void MovementStrategy()override{
        cout<<"Making sure there is historical consistency"<<endl;
    }
    void Calc_Delivery_Time(int VehicleID,int distance)override {
        Vehicle::Calc_Delivery_Time(VehicleID,0);
        MovementStrategy();
        cout<<"Instantaneous Delivery"<<endl;   
    }
    void Command(string order, int packageid, int urgenctLevel)override {
        cout<<"Time sensitive package...Confrimation required ( write 'yes' to proceed)"<<endl;
        string txt;
        cin>>txt;
        if(txt == "yes"){
            cout<<"Proceeding with utmost caution"<<endl;
        } 
        else{
            cout<<"Delivery aborted"<<endl;
        }
        AddDelivery();
    }
    void Command(string order, int packageid) override {
        Vehicle::Command(order, packageid);
    }
};

class RamzanHyperpod: public Vehicle{
    int Speed_km = 120;
    bool Highspeed = false;
    int capacity_kg = 10;
    int efficiency_percent = 70;
    public:
    RamzanHyperpod(int id): Vehicle(id) {}
    void MovementStrategy()override {
        cout<<"Navigating through the most efficient route"<<endl;
    }
    void Calc_Delivery_Time(int VehicleID, int distance)override {
        cout << "Will take " << (distance / Speed_km) * 60 << " minutes" << endl;
        MovementStrategy();
        Vehicle::Calc_Delivery_Time(VehicleID,distance);
    }
    friend bool ResolveConflict(RamzanDrone& v1, RamzanHyperpod& v2, int distance);
    void Command(string order, int packageid) override {
        Vehicle::Command(order, packageid);
    }
};

bool ResolveConflict(RamzanDrone& v1, RamzanHyperpod& v2, int distance){
    if(distance < 30){
        if(v1.efficiency_percent > v2.efficiency_percent){
            v1.Calc_Delivery_Time(v1.ID, distance);
        }
        else{
            v2.Calc_Delivery_Time(v2.ID, distance);
        }
    }
    else{
        if(v1.Speed_km > v2.Speed_km){
            v1.Calc_Delivery_Time(v1.ID, distance);
        }
        else{
            v2.Calc_Delivery_Time(v2.ID,distance);
        }
    }
}

int main() {
    RamzanDrone drone(301);
    RamzanTimeShip timeShip(101);
    RamzanHyperpod hyperpod(201);

    cout << "Testing Movement Strategy:" << endl;
    drone.MovementStrategy();
    timeShip.MovementStrategy();  
    hyperpod.MovementStrategy();  
    cout << endl;

    cout << "Testing Command Function:" << endl;
    drone.Command("Deliver", 1234);  
    timeShip.Command("Deliver", 5678, 2);  
    hyperpod.Command("Deliver", 91011);  
    cout << endl;

    cout << "Testing Delivery Time Calculation:" << endl;
    drone.Calc_Delivery_Time(drone.getID(), 100);  
    timeShip.Calc_Delivery_Time(timeShip.getID(), 0);  
    hyperpod.Calc_Delivery_Time(hyperpod.getID(), 200);  
    cout << endl;

    cout << "Testing AI Conflict Resolution:" << endl;
    ResolveConflict(drone, hyperpod, 50); 
    ResolveConflict(drone, hyperpod, 150); 
}
