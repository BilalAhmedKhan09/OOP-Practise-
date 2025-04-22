#include <iostream>

using namespace std;

class WeatherSensor{
public:
    virtual void collectData() = 0;
    virtual void displayReport() = 0;
};

class Thermometer : public WeatherSensor{
public:
    void collectData(){
        cout << "Collecting temperature data..." << endl;
    }
    void displayReport(){
        cout << "Temperature report has been generated." << endl;
    }
};

class Barometer : public WeatherSensor{
public:
    void collectData()
    {
        cout << "Collecting pressure data..." << endl;
    }
    void displayReport()
    {
        cout << "Pressure report has been generated." << endl;
    }
};

int main(){
    Thermometer sensor1;  
    Barometer sensor2;

    sensor1.collectData();
    sensor1.displayReport();

    sensor2.collectData();
    sensor2.displayReport();
}
