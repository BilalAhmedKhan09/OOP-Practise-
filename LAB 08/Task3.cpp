#include<iostream>

using namespace std;

class TwoDVector{
private:
    double xCoord, yCoord;

public:
    TwoDVector(double x = 0, double y = 0) : xCoord(x), yCoord(y) {}

    TwoDVector operator+(const TwoDVector &vec){
        return TwoDVector(xCoord + vec.xCoord, yCoord + vec.yCoord);
    }

    TwoDVector operator-(const TwoDVector &vec){
        return TwoDVector(xCoord - vec.xCoord, yCoord - vec.yCoord);
    }

    TwoDVector operator*(double factor){
        return TwoDVector(xCoord * factor, yCoord * factor);
    }

    friend double ComputeDotProduct(const TwoDVector &vec1, const TwoDVector &vec2);

    friend void operator<<(ostream &stream, const TwoDVector &vec){
        stream << "(" << vec.xCoord << ", " << vec.yCoord << ")" << endl;
    }
};

double ComputeDotProduct(const TwoDVector &vec1, const TwoDVector &vec2){
    return vec1.xCoord * vec2.xCoord + vec1.yCoord * vec2.yCoord;
}

int main(){
    TwoDVector vec1(3, 4), vec2(1, 2);
    TwoDVector resultScaled = vec1 * 2;
    cout << "Scaled Vector: ";
    cout << resultScaled;

    double dot = ComputeDotProduct(vec1, vec2);
    cout << "Dot Product Result: " << dot << endl;

    TwoDVector resultAdd = vec1 + vec2;
    cout << "Vector Addition: ";
    cout << resultAdd;

    TwoDVector resultSub = vec1 - vec2;
    cout << "Vector Subtraction: ";
    cout << resultSub;
}
