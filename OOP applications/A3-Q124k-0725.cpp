#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class User {
protected:
    int ID;
    string Name;
    bool payment;
    bool booked;
public:
    User(int id, string name) : ID(id), Name(name), payment(false), booked(false) {}
    virtual bool isStudent() = 0;
    void makePayment() { payment = true; }
    bool hasPaid() const { return payment; }
    void setBooked() { booked = true; }
    bool isBooked() const { return booked; }
    int getID() const { return ID; }
    string getName() const { return Name; }
};

class Student : public User {
public:
    Student(int id, string name) : User(id, name) {}
    bool isStudent() override { return true; }
};

class Faculty : public User {
public:
    Faculty(int id, string name) : User(id, name) {}
    bool isStudent() override { return false; }
};

class Route {
    string start, end;
    int distance;
public:
    Route(string s, string e, int d) : start(s), end(e), distance(d) {}
    string getStart() const { return start; }
    string getEnd() const { return end; }
    int getDistance() const { return distance; }
};

class Vehicle {
protected:
    string type;
    int totalSeats;
    int facultySeats;
    int studentSeats;
    bool hasAC;
    Route* route;
public:
    Vehicle(string t, int total, int fSeats, int sSeats, bool ac)
        : type(t), totalSeats(total), facultySeats(fSeats), studentSeats(sSeats), hasAC(ac), route(nullptr) {}

    void assignRoute(Route* r) { route = r; }

    bool isAlreadyBooked(User* user) {
        ifstream file("bookings.txt");
        string line;
        string idStr = "ID: " + to_string(user->getID());
        while (getline(file, line)) {
            if (line.find(idStr) != string::npos) {
                return true;
            }
        }
        return false;
    }

    void saveBookingToFile(User* user) {
        if (isAlreadyBooked(user)) {
            cout << "Booking already exists for user ID " << user->getID() << "." << endl;
            return;
        }

        ofstream file("bookings.txt", ios::app);
        if (file.is_open()) {
            file << "ID: " << user->getID()
                 << " | Name: " << user->getName()
                 << " | Type: " << (user->isStudent() ? "Student" : "Faculty")
                 << " | Vehicle: " << type
                 << " | AC: " << (hasAC ? "Yes" : "No")
                 << " | Route: " << (route ? (route->getStart() + " to " + route->getEnd()) : "None")
                 << endl;
            file.close();
        }
    }

    void calculateFare(User* user) {
        int fare = user->isStudent() ? 2000 : 3000;
        if (hasAC) fare += 2000;
        cout << "Fare for " << user->getName() << ": Rs. " << fare << endl;
    }

    virtual void bookSeat(User* user) {
        if (!user->hasPaid()) {
            cout << "Payment not made." << endl;
            return;
        }

        if (isAlreadyBooked(user)) {
            cout << "User already has a booking" << endl;
            return;
        }

        if (user->isStudent() && studentSeats > 0) {
            studentSeats--;
        } else if (!user->isStudent() && facultySeats > 0) {
            facultySeats--;
        } else {
            cout << "No seat available for this user type" << endl;
            return;
        }

        user->setBooked();
        calculateFare(user);
        saveBookingToFile(user);
    }

    string getType() const { return type; }
    bool getAC() const { return hasAC; }
};

class Bus : public Vehicle {
public:
    Bus(bool ac) : Vehicle("Bus", 52, 10, 42, ac) {}
};

class Coaster : public Vehicle {
public:
    Coaster(bool ac) : Vehicle("Coaster", 32, 10, 22, ac) {}
};

class Driver {
    string name;
    int licenseNo;
    Vehicle* vehicle;
public:
    Driver(string n, int lic, Vehicle* v) : name(n), licenseNo(lic), vehicle(v) {}

    void showDriver() {
        cout << "Driver: " << name << ", License: " << licenseNo << ", Vehicle Type: " << vehicle->getType() << endl;
    }

    bool isDriverAlreadySaved() {
        ifstream file("drivers.txt");
        string line;
        string key = name + "," + to_string(licenseNo);
        while (getline(file, line)) {
            if (line.find(key) != string::npos) {
                return true;
            }
        }
        return false;
    }

    void saveToFile() {
        if (isDriverAlreadySaved()) {
            cout << "Driver already exists in file." << endl;
            return;
        }

        ofstream file("drivers.txt", ios::app);
        if (file.is_open()) {
            file << name << "," << licenseNo << "," << vehicle->getType() << endl;
            file.close();
        }
    }
};

class Transporter {
protected:
    string name;
    Vehicle* vehicles[10];
    int count;
public:
    Transporter(string n) : name(n), count(0) {}
    void addVehicle(Vehicle* v) {
        if (count < 10) {
            vehicles[count++] = v;
            cout << "Added vehicle to " << name << endl;
        } else {
            cout << "Cannot add more vehicles to " << name << endl;
        }
    }
    void showVehicles() {
        cout << name << " vehicles:" << endl;
        for (int i = 0; i < count; i++) {
            cout << "- " << vehicles[i]->getType() << endl;
        }
    }
};

class NadeemTransporter : public Transporter {
public:
    NadeemTransporter() : Transporter("Nadeem Transporter") {}
};

class ZulfiqarTransporter : public Transporter {
public:
    ZulfiqarTransporter() : Transporter("Zulfiqar Transporter") {}
};

// ---------------------- Main Function ---------------------- //
int main() {
    Student s1(101, "Ali Khan");
    s1.makePayment();

    Route r1("Gulshan", "FAST-NUCES", 15);
    Bus bus1(true);
    bus1.assignRoute(&r1);

    Driver d1("Ahmed Raza", 12345, &bus1);
    d1.showDriver();
    d1.saveToFile();

    bus1.bookSeat(&s1);

    NadeemTransporter nadeem;
    nadeem.addVehicle(&bus1);
    nadeem.showVehicles();
}
