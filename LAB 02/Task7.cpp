#include<iostream>

using namespace std;

int** createMatrix(int numRows, int numCols) {
    int** matrix = new int*[numRows]; 
    for (int i = 0; i < numRows; i++) {
        matrix[i] = new int[numCols]; 
    }
    return matrix;
}

void fillMatrix(int **matrix, int numRows, int numCols) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cout << "matrix[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int **matrix, int numRows, int numCols) {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void multiplyMatrices(int **matrix1, int **matrix2, int rows1, int cols1, int rows2, int cols2) {
    cout << "Multiplication of the matrices:" << endl;
    int result = 0;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result += matrix1[i][k] * matrix2[k][j];
            }  
            cout << result << " ";
            result = 0;
        }
        cout << endl;
    }
}

void deleteMatrix(int **matrix, int numRows) {
    for (int i = 0; i < numRows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int rows1, cols1;
    int rows2, cols2;
    cout << "Enter the number of rows for matrix 1: ";
    cin >> rows1;
    cout << "Enter the number of columns for matrix 1: ";
    cin >> cols1;
    cout << "Enter the number of rows for matrix 2: ";
    cin >> rows2;
    cout << "Enter the number of columns for matrix 2: ";
    cin >> cols2;
    if (cols1 == rows2) {
        int **matrix1 = createMatrix(rows1, cols1);
        int **matrix2 = createMatrix(rows2, cols2);

        cout << "Enter values for matrix 1:" << endl;
        fillMatrix(matrix1, rows1, cols1);

        cout << "Enter values for matrix 2:" << endl;
        fillMatrix(matrix2, rows2, cols2);

        cout << "Matrix 1:" << endl;
        printMatrix(matrix1, rows1, cols1);

        cout << "Matrix 2:" << endl;
        printMatrix(matrix2, rows2, cols2);

        multiplyMatrices(matrix1, matrix2, rows1, cols1, rows2, cols2);

        deleteMatrix(matrix1, rows1);
        deleteMatrix(matrix2, rows2);
    } 
    else {
        cout << "Matrices cannot be multiplied. Number of columns in matrix 1 must equal number of rows in matrix 2." << endl;
    }
}