#include <iostream>
#include<exception>
using namespace std;

class InvalidTemperatureException : public exception{
    string message;
    public:
    InvalidTemperatureException(const string &msg) : message(msg) {}
};

template<class T>
class convertToFahrenheit{
    T celsius;
    public:
    convertToFahrenheit(T c){
        if(c < -273.15){
            throw InvalidTemperatureException("Invalid temperature: below absolute zero");
        }
    }
    T convert(){
        return (celsius * 9 / 5) + 32;
    }
};

int main(){
    try{
        convertToFahrenheit<double> temp(-300);
        cout << "Temperature(F) : " << temp.convert() <<endl;
    }
    catch (const InvalidTemperatureException &e){
        cout <<"Caught InvalidTemperatureException : "<< e.what() <<endl;
    }
}