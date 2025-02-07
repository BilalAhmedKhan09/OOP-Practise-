#include <iostream>

using namespace std;

struct Pupil {
    string fullName;
    int idNumber;
    float scores[3];
};

void calculateAverage(Pupil p) {
    float total = 0;
    for (int i = 0; i < 3; i++) {
        total += p.scores[i];
    }
    cout << "Average marks: " << total / 3.0 << endl;
}

void getInput(Pupil *p, int count) {
    for (int i = 0; i < count; i++) {
        cout << "For pupil " << i + 1 << endl;
        cout << "Enter full name: ";
        cin.ignore();
        getline(cin, p[i].fullName);
        cout << "Enter ID number: ";
        cin >> p[i].idNumber;
        for (int j = 0; j < 3; j++) {
            cout << "Enter score for subject " << j + 1 << ": ";
            cin >> p[i].scores[j];
        }
    }
}

void showDetails(Pupil *p, int count) {
    for (int i = 0; i < count; i++) {
        cout << "Pupil " << i + 1 << endl;
        cout << "Full Name: " << p[i].fullName << endl;
        cout << "ID Number: " << p[i].idNumber << endl;
        for (int j = 0; j < 3; j++) {
            cout << "Score of subject " << j + 1 << ": " << p[i].scores[j] << endl;
        }
        calculateAverage(p[i]);
    }
}

int main() {
    int count;
    cout << "Enter the number of pupils: ";
    cin >> count;
    Pupil *pupils = new Pupil[count];
    getInput(pupils, count);
    showDetails(pupils, count);
    delete[] pupils;
}
