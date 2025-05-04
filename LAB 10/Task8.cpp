#include<iostream>
#include<fstream>


using namespace std;

int main() {
    fstream file("config.txt", ios::out);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }
    file << "AAAAABBBBBCCCCC";
    file.close();
    file.open("config.txt", ios::in | ios::out);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }
    file.seekp(5);
    file << "XXXXX";
    file.close();
    string line;
    file.open("config.txt");
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}
