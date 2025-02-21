#include <iostream>
using namespace std;

class Stop;
class Bus;

class Student {
    string name;
    bool feePaid;
    int studentID;
    bool isActive;
    Stop* assignedStop; 

public:
    Student(string n, int id) {
        name = n;
        studentID = id;
        feePaid = false;
        isActive = false;
        assignedStop = nullptr;
    }

    void payFee() {
        feePaid = true;
        isActive = true;
        cout << name << " has paid the fee. Transportation card activated."<<endl;
    }

    void assignStop(Stop* stop) {
        assignedStop = stop;
    }

    bool isCardActive() {
        return isActive;
    }

    void tapCard();

    string getName() {
        return name;
    }
};

class Stop {
    string stopName;
    Student* students[10];  
    int studentCount;

public:
    Stop(string name) {
        stopName = name;
        studentCount = 0;
    }

    void addStudent(Student* student) {
        if (studentCount < 10) {
            students[studentCount++] = student;
            student->assignStop(this);
            cout << student->getName() << " assigned to stop: " << stopName << endl;
        } else {
            cout << "Stop is full, cannot assign more students."<<endl;
        }
    }

    string getStopName() {
        return stopName;
    }
};

class Bus {
    string busName;
    Stop* stops[5];  
    int stopCount;
    static int attendance; 

public:
    Bus(string name) {
        busName = name;
        stopCount = 0;
    }

    void addStop(Stop* stop) {
        if (stopCount < 5) {
            stops[stopCount++] = stop;
            cout << "Stop " << stop->getStopName() << " added to bus route: " << busName << endl;
        } else {
            cout << "Bus cannot take more stops."<<endl;
        }
    }

    static void increaseAttendance();

    static void displayAttendance() {
        cout << "Total attendance recorded: " << attendance << endl;
    }

    void displayRoute() {
        cout << "Bus " << busName << " stops at:"<<endl;
        for (int i = 0; i < stopCount; i++) {
            cout << "- " << stops[i]->getStopName() << endl;
        }
    }
};

int Bus::attendance = 0;

void Bus::increaseAttendance() {
    attendance++;
}

void Student::tapCard(){
    if (isActive) {
        cout << name << " tapped the card. Attendance marked."<<endl;
        Bus::increaseAttendance();  
        cout << name << " cannot board the bus. Card is inactive."<<endl;
    }
}


int main() {
    Stop stop1("Stop A");
    Stop stop2("Stop B");
    Student student1("Alice", 101);
    Student student2("Bob", 102);
    stop1.addStudent(&student1);
    stop2.addStudent(&student2);
    Bus bus1("Bus 1");
    bus1.addStop(&stop1);
    bus1.addStop(&stop2);
    student1.payFee();
    student2.payFee();
    student1.tapCard();
    student2.tapCard();
    Bus::displayAttendance();
    bus1.displayRoute();
}
