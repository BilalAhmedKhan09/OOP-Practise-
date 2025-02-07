#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cout << "For matrix[a][b][c]" << endl;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter c: ";
    cin >> c;
    int ***matrix = new int**[a];
    for (int i = 0; i < a; i++) {
        matrix[i] = new int*[b];
        for (int j = 0; j < b; j++) {
            matrix[i][j] = new int[c];
        }
    }
    cout << "Enter Elements:" << endl;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            for (int k = 0; k < c; k++) {
                cout << "Enter matrix[" << i + 1 << "][" << j + 1 << "][" << k + 1 << "]: ";
                cin >> matrix[i][j][k];
            }
        }
    }
    cout << "3D Matrix Elements:" << endl;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            for (int k = 0; k < c; k++) {
                cout << matrix[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            delete[] matrix[i][j];
        }
        delete[] matrix[i];
    }
    delete[] matrix;
}
