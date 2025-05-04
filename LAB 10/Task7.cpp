#include<iostream>
#include<fstream>

using namespace std;

int main() {
    ofstream file("sensor_log.txt");
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }
    file << "Mama said life is like a box of chocolates.\n";
    file << "You never know what you're gonna get.\n";
    file << "The eternal faminine leads us aloft.\n";
    cout << "Current position in file: " << file.tellp() << endl;
    file << "Not all those who wander are lost.\n";
    streampos position = file.tellp();
    cout << "Current position in file: " << position << endl;
    file.close();
}
