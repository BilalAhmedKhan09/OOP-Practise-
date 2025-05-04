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
            size_t colonPos = extraData.find(':');
            if (colonPos == string::npos) {
                cout << "Error: ':' not found in ExtraData"<<endl;
                continue;
            }
            if(extraData == "ElectricVehicle"){
                int batterycapacity = stoi(extraData.substr(colonPos+1));
                cout << "Battery Capacity: " << batterycapacity << endl;
            }    
            if(extraData == "AutonomousCar"){
                float version = stof(extraData.substr(colonPos+1));
                cout << "Software Version: " << version << endl;
            }    
            if(extraData == "HybridTruck"){
                size_t pipe = extraData.find('|');
                int cargo = stoi(extraData.substr(colonPos+1, pipe-1));
                cout << "Cargo Value: " << cargo << endl;
                size_t colon2 = extraData.find(':', pipe+1);
                int batterycapacity = stoi(extraData.substr(colon2+1));
            }  
        file.close();
    }
}