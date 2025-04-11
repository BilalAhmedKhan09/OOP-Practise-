#include <iostream>
#include <cmath>

using namespace std;

class ComplexNumber{
private:
    double realPart;
    double imaginaryPart;

public:
    ComplexNumber(double realVal = 0, double imagVal = 0) : realPart(realVal), imaginaryPart(imagVal) {}

    ComplexNumber operator+(const ComplexNumber &other) {
        return ComplexNumber(realPart + other.realPart, imaginaryPart + other.imaginaryPart);
    }

    ComplexNumber operator-(const ComplexNumber &other){
        return ComplexNumber(realPart - other.realPart, imaginaryPart - other.imaginaryPart);
    }

    ComplexNumber operator*(const ComplexNumber &other){
        return ComplexNumber(realPart * other.realPart - imaginaryPart * other.imaginaryPart,
                             realPart * other.imaginaryPart + imaginaryPart * other.realPart);
    }

    ComplexNumber operator/(const ComplexNumber &other){
        double denom = other.realPart * other.realPart + other.imaginaryPart * other.imaginaryPart;
        return ComplexNumber((realPart * other.realPart + imaginaryPart * other.imaginaryPart) / denom,
                             (imaginaryPart * other.realPart - realPart * other.imaginaryPart) / denom);
    }

    friend void operator<<(ostream &output, const ComplexNumber &obj){
        output << obj.realPart << " + " << obj.imaginaryPart << "i" << endl;
    }

    friend double CalculateMagnitude(ComplexNumber &obj){
        return sqrt(obj.realPart * obj.realPart + obj.imaginaryPart * obj.imaginaryPart);
    }
};

int main(){
    ComplexNumber num1(3, 4), num2(1, 2);

    double mag = CalculateMagnitude(num1);
    cout << "Magnitude of first number: " << mag << endl;

    ComplexNumber prodResult = num1 * num2;
    cout << "Product: ";
    cout << prodResult;

    ComplexNumber sumResult = num1 + num2;
    cout << "Sum: ";
    cout << sumResult;

    ComplexNumber divResult = num1 / num2;
    cout << "Quotient: ";
    cout << divResult;

    ComplexNumber diffResult = num1 - num2;
    cout << "Difference: ";
    cout << diffResult;
}

