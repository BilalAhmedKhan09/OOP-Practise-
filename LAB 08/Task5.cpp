#include<iostream>

using namespace std;

class SquareMatrix{
private:
    double m11, m12, m21, m22;

public: 
    SquareMatrix(double val11 = 0, double val12 = 0, double val21 = 0, double val22 = 0)
        : m11(val11), m12(val12), m21(val21), m22(val22) {}

    SquareMatrix operator+(const SquareMatrix &other){
        return SquareMatrix(m11 + other.m11, m12 + other.m12, m21 + other.m21, m22 + other.m22);
    }

    SquareMatrix operator-(const SquareMatrix &other){
        return SquareMatrix(m11 - other.m11, m12 - other.m12, m21 - other.m21, m22 - other.m22);
    }

    SquareMatrix operator*(const SquareMatrix &other){
        return SquareMatrix(
            m11 * other.m11 + m12 * other.m21,
            m11 * other.m12 + m12 * other.m22,
            m21 * other.m11 + m22 * other.m21,
            m21 * other.m12 + m22 * other.m22);
    }

    friend void operator<<(ostream &out, const SquareMatrix &mat){
        cout << "[" << mat.m11 << " " << mat.m12 << "]" << endl;
        cout << "[" << mat.m21 << " " << mat.m22 << "]" << endl;
    }

    friend double GetDeterminant(const SquareMatrix &mat){
        return mat.m11 * mat.m22 - mat.m12 * mat.m21;
    }

    friend class MatrixEditor;
};

class MatrixEditor{
public:
    void modifyElement(SquareMatrix &mat, int row, int col, double newVal){
        if (row == 1 && col == 1){
            mat.m11 = newVal;}
        else if (row == 1 && col == 2){
            mat.m12 = newVal;}
        else if (row == 2 && col == 1){
            mat.m21 = newVal;}
        else if (row == 2 && col == 2){
            mat.m22 = newVal;}
        else{
            cout << "Invalid matrix indices!" << endl;}
    }
};

int main(){
    SquareMatrix mat1(1, 2, 3, 4), mat2(5, 6, 7, 8);
    MatrixEditor editor;

    cout << "Matrix One:" << endl;
    cout << mat1;
    cout << "Matrix Two:" << endl;
    cout << mat2;

    SquareMatrix resultMul = mat1 * mat2;
    cout << "\nProduct of matrices:" << endl;
    cout << resultMul;

    SquareMatrix resultAdd = mat1 + mat2;
    cout << "Sum of matrices:" << endl;
    cout << resultAdd;

    SquareMatrix resultSub = mat1 - mat2;
    cout << "Difference of matrices:" << endl;
    cout << resultSub;

    double detVal = GetDeterminant(mat1);
    cout << "Determinant of Matrix One: " << detVal << endl;

    editor.modifyElement(mat1, 1, 1, 10);
    cout << "\nMatrix One after modifying [1][1] to 10:" << endl;
    cout << mat1;

}
