#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main() {
    fstream file("large_log.txt", ios::out);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }
    file << "This is the first part of the log.\n";
    file << "This is the second part of the log.\n";
    file << "This is the second part of the log.\n";
    file.close();
    file.open("large_log.txt", ios::in);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }
    string line;
    char buffer[10];
    file.read(buffer, 10);
    getline(file, line);
    cout << "Current position in file: " << file.tellg() << endl;

    getline(file, line);
    file.read(buffer, 10);
    cout << "Current position in file: " << file.tellg() << endl;
    file.close();
}
