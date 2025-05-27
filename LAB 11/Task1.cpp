#include <iostream>
#include <exception>
using namespace std;

class SizeMismatchError : public exception {
    string info;
public:
    SizeMismatchError(const string &msg) : info(msg) {}
    const char* what() const noexcept override {
        return info.c_str();
    }
};

template<typename T>
class Matrix2D {
    T **data;
    int numRows;
    int numCols;
    public:
    Matrix2D(int r, int c) : numRows(r), numCols(c) {
        data = new T*[numRows];
        for (int i = 0; i < numRows; ++i){
            data[i] = new T[numCols];
        }
    }
    ~Matrix2D() {
        for (int i = 0; i < numRows; ++i)
            delete[] data[i];
        delete[] data;
    }
    void inputValues() {
        cout << "Input matrix elements (" << numRows << "x" << numCols << "):" << endl;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                cin >> data[i][j];
            }
        }
    }
    void print() const {
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << "\n";
        }
    }
    friend Matrix2D<T> operator+(Matrix2D &a, Matrix2D &b) {
        if (a.numRows != b.numRows || a.numCols != b.numCols) {
            throw SizeMismatchError("Error: Cannot add matrices of different dimensions.");
        }
        Matrix2D<T> temp(a.numRows, a.numCols);
        for (int i = 0; i < a.numRows; i++) {
            for (int j = 0; j < a.numCols; j++) {
                temp.data[i][j] = a.data[i][j] + b.data[i][j];
            }
        }
        return temp;
    }
};

int main() {
    Matrix2D<int> A(2, 2), B(2, 2);
    A.inputValues();
    B.inputValues();
    cout << "\nMatrix A:"<<endl;
    A.print();
    cout << "Matrix B:"<<endl;
    B.print();
    try {
        Matrix2D<int> C = A + B;
        cout << "Sum of A and B:"<<endl;
        C.print();
    } 
    catch (SizeMismatchError &err) {
        cout << err.what() << endl;
    }
}
