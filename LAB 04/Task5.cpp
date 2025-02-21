#include<iostream>

using namespace std;

class Car{
    float Price;
    string Model;
    string Brand;
    bool Availability;
const int ID;
    public:
    Car(): ID(000){
        Price = 0.0;
        Model = "Generic";
        Brand = "Unknown";
        Availability = true;
       
    }
    Car(float price, string model, string brand, bool availability, int id) : ID(id){
        Price = price;
        Model = model;
        Brand = brand;
        Availability = availability;
    }

    Car(Car &r) :ID(r.ID){
        Price = r.Price;
        Model = r.Model;
        Brand = r.Brand;
        Availability = r.Availability;
    }

    ~Car(){}
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
        if(days > 10){
            return Price * 0.90;
        }
        else if(days > 5){
            return Price * 0.95;
        }
        return Price;
    }
   
    void getdetails(){
        cout<<"Brand: "<<Brand<<"\t";
        cout<<"Model: "<<Model<<"\t";
        cout<<"Availability: "<<Availability<<endl;
        cout<<"Car ID: "<<ID<<endl;
    }

    void changedetails(string model, string brand, bool availability){
        Model = model;
        Brand = brand;
        Availability = availability;
    }

    float revenue(int days){
        return Price * days;
    }
};

int main(){
    Car car(10.5, "City", "Honda", true, 256);
    Car car2(car);
    car.getdetails();
    if(car.Rent()){
        int num;
        cout<<"Enter the number of days the car is going to be rented for"<<endl;
        cin>>num;
        cout<<"Price: "<<car.applyDiscount(num)<<endl;
    }
    cout<<endl;
    car2.getdetails();
    cout<<endl;
    car.changedetails("R8", "Audi", true);
    car.getdetails();
    car.revenue(10);
}