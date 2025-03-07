#include<iostream>

using namespace std;

class Vehicle{
    protected:
    string Brand;
    int Speed;
    public:
    Vehicle(string b,int s):Brand(b),Speed(s){}
    virtual void Display(){
        cout<<"Brand: "<<Brand<<endl;
        cout<<"Speed: "<<Speed<<endl;
    }
};


class Car : protected Vehicle{
    protected:
    int Seats;
    public:
    Car(string b,int s,int seat):Vehicle(b,s),Seats(seat){}
    void Display() override{
        Vehicle::Display();
        cout<<"Seats: "<<Seats<<endl;
    }   
};

class ElectricCar: protected Car{
    protected:
    int BatteryLife;
    public:
    ElectricCar(string b,int s,int seat,int battery):Car(b,s,seat),BatteryLife(battery){}
    void Display() override{
        Car::Display();
        cout<<"Battery life: "<<BatteryLife<<endl;
    }
};

int main(){
    ElectricCar car("BYD", 180, 7, 100);
    car.Display();
}