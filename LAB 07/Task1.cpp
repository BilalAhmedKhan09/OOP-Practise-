#include<iostream>

using namespace std;

class Appliance{
protected:
    int idCode;
    string title;
    string state;
public:
    Appliance(int code, string name, string condition){
        idCode = code;
        title = name;
        state = condition;
    }

    virtual void Activate(){
        state = "ON";
    }
    virtual void Deactivate(){
        state = "OFF";
    }
    virtual string retrieveState(){
        return state;
    }
    virtual void showDetails(){
        cout << "ID: " << idCode << endl;
        cout << "Name: " << title << endl;
        cout << "State: " << state << endl;
    }
};

class Lamp: public Appliance{
    int luminance;
    string hueMode;
public:
    Lamp(int code, string name, string condition, int bright, string hue): Appliance(code, name, condition) {
        luminance = bright;
        hueMode = hue;
    }
    void showDetails() override {
        Appliance::showDetails();
        cout << "Luminance: " << luminance << endl;
        cout << "Hue Mode: " << hueMode << endl;
    }
};

class ClimateControl: public Appliance{
    int temp;
    string setting;
    int targetTemp;
public:
    ClimateControl(int code, string name, string condition, int temperature, string mode, int desiredTemp): Appliance(code, name, condition) {
        temp = temperature;
        setting = mode;
        targetTemp = desiredTemp;
    }
    string retrieveState() override{
        return to_string(temp);
    }
    void showDetails() override{
        Appliance::showDetails();
        cout << "Current Temperature: " << temp << endl;
        cout << "Setting: " << setting << endl;
        cout << "Target Temperature: " << targetTemp << endl;
    }
};

class Surveillance: public Appliance{
    string clarity;
    bool isRecording;
    string nightMode;
public:
    Surveillance(int code, string name, string condition, string resolution, bool record, string nightVision): Appliance(code, name, condition) {
        clarity = resolution;
        isRecording = record;
        nightMode = nightVision;
    }
    void Activate() override {
        isRecording = true;
    }
    void showDetails() override {
        Appliance::showDetails();
        cout << "Resolution: " << clarity << endl;
        cout << "Recording: " << (isRecording ? "ON" : "OFF") << endl;
        cout << "Night Mode: " << nightMode << endl;
    }
};

class EnergyOutlet: public Appliance{
    int wattUsage;
    string timeControl;
public:
    EnergyOutlet(int code, string name, string condition, int usage, string timer): Appliance(code, name, condition) {
        wattUsage = usage;
        timeControl = timer;
    }
    void Deactivate() override {
        cout << "Logging energy consumption" << endl;
        Appliance::Deactivate();
    }
    void showDetails() override {
        Appliance::showDetails();
        cout << "Power Consumption: " << wattUsage << endl;
        cout << "Timer: " << timeControl << endl;
    }
};

int main(){
    Lamp loungeLamp(1, "Lounge Lamp", "OFF", 80, "Cool White");
    ClimateControl houseThermostat(2, "House Thermostat", "ON", 21, "Heating", 23);
    Surveillance entryCamera(3, "Entryway Camera", "OFF", "4K", false, "Enabled");
    EnergyOutlet kitchenSocket(4, "Kitchen Socket", "ON", 200, "3 hours");
    
    cout << "Lounge Lamp Info:" << endl;
    loungeLamp.showDetails();
    cout << endl;
    
    cout << "House Thermostat Info:" << endl;
    houseThermostat.showDetails();
    cout << endl;
    
    cout << "Entryway Camera Info:" << endl;
    entryCamera.showDetails();
    cout << endl;
    
    cout << "Kitchen Socket Info:" << endl;
    kitchenSocket.showDetails();
    cout << endl;
    
    cout << "Activating Lounge Lamp..." << endl;
    loungeLamp.Activate();
    loungeLamp.showDetails();
    cout << endl;
    
    cout << "Deactivating Kitchen Socket..." << endl;
    kitchenSocket.Deactivate();
    kitchenSocket.showDetails();
    cout << endl;
}
