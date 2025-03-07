#include<iostream>
using namespace std;

class Device {
protected:
    int deviceid;
    bool status;
public:
    Device(int id, bool s) : deviceid(id), status(s) {}
    virtual void display() {
        cout << "Device ID: " << deviceid << endl;
        if (status) {
            cout << "Device is on" << endl;
        } else {
            cout << "Device is off" << endl;
        }
    }
};

class Smartphone : protected Device {
protected:
    float screensize;
public:
    Smartphone(int id, bool s, float screen) : Device(id, s), screensize(screen) {}
    void display() override {
        Device::display();
        cout << "Screen size: " << screensize << " inches" << endl;
    }
};

class SmartWatch : protected Device {
protected:
    bool heartratemonitor;
public:
    SmartWatch(int id, bool s, bool rate) : Device(id, s), heartratemonitor(rate) {}
};

class SmartWearable : protected Smartphone, protected SmartWatch {
    int stepcounter;
public:
    SmartWearable(int id, bool s, float screen, bool rate, int count)
        : Smartphone(id, s, screen), SmartWatch(id, s, rate), stepcounter(count) {}
    void display() override {
        Smartphone::display();
        if (heartratemonitor) {
            cout << "Heart rate monitor is on" << endl;
        } else {
            cout << "Heart rate monitor is off" << endl;
        }
        cout << "Steps taken: " << stepcounter << endl;
    }
};

int main() {
    SmartWearable smart(124, true, 3.5, true, 1050);
    smart.display();
}
