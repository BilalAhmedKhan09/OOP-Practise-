#include<iostream>

using namespace std;

class Car{
    float Price = 0.0;
    string Model;
    string Brand;
    bool Availability;

    public:
    Car(){
        Model = "Generic";
        Brand = "Unknown";
        Availability = true;
    }
    Car(float price, string model, string brand, bool availability){
        Price = price;
        Model = model;
        Brand = brand;
        Availability = availability;
    }

    void Rent(){
        if(Availability == true){
            Availability = false;
            cout<<"Car rented"<<endl;
        }
        else{
            cout<<"Car is not available"<<endl;
        }
    }

    float applyDiscount(float days){
        Price = (Price-(Price*(days/100)));
        return Price;
    }
};

int main(){
    Car car(10.5, "City", "Honda", true);
}