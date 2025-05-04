#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ifstream file("vehicles.txt");

    if (!file) {
        cout << "File not found" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        if((!line.empty()) && (!line[0] == '#')){
            cout << "Line: " << line << endl;
            stringstream ss(line);
            string type, id, name, year, extraData, certification;
            getline(ss, type, ',');
            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, year, ',');
            getline(ss, extraData, ',');
            getline(ss, certification, ',');
            int result;
            if(!(result == stoi(year))){
                cout<<"Could not convert stoi"<<endl;
            }
            cout << "Type: " << type << endl;
            cout << "ID: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Year: " << result << endl;
            cout << "ExtraData: " << extraData << endl;
            cout << "Certification: " << certification << endl;
            cout <<""<< endl;
        }
    }
    file.close();
}