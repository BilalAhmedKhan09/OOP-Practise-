#include<iostream>

using namespace std;

class Car{
    float Price;
    string Model;
    string Brand;
    bool Availability;

    public:
    Car(){
        Price = 0.0;
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

    bool Rent(){
        if(Availability == true){
            Availability = false;
            cout<<"Car rented"<<endl;
            return 1;
        }
        else{
            cout<<"Car is not available"<<endl;
            return 0;
        }
    }

    float applyDiscount(float days){
        Price = (Price-(Price*(days/100)));
        return Price;
    }

    float applyDiscount(int days){
        if(days > 5){
            return Price * 0.95;
        }
        else if(days > 10){
            return Price * 0.90;
        }
        return Price;
    }
    
    void getdetails(){
        cout<<"Brand: "<<Brand<<"\t";
        cout<<"Model: "<<Model<<"\t";
        cout<<"Availability: "<<Availability<<endl;
    }

    void changedetails(string model, string brand, bool availability){
        Model = model;
        Brand = brand;
        Availability = availability;
    }
};

int main(){
    Car car(10.5, "City", "Honda", false);
    if(car.Rent()){
        int num;
        cout<<"Enter the number of days the car is going to be rented for"<<endl;
        cin>>num;
        cout<<"Price: "<<car.applyDiscount(num)<<endl;
    }
}