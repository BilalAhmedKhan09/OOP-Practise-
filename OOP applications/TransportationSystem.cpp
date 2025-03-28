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
    Bus* assignedBus;

public:
    Student(string n, int id) {
        name = n;
        studentID = id;
        feePaid = false;
        isActive = false;
        assignedStop = nullptr;
        assignedBus = nullptr;
    }

    void payFee() {
        feePaid = true;
        setactive();
    }

    void assignStop(Stop* stop) {
        assignedStop = stop;
    }

    void assignBus(Bus *bus){
        assignedBus = bus;
    }

    bool isCardActive() {
        return isActive;
    }

    void tapCard();

    string getName() {
        return name;
    }
    void setactive(){
        if(feePaid == false){
            isActive = false; 
            cout<<"Card de-activated"<<endl;
            return;
        }
        isActive = true;
        cout << name << " has paid the fee. Transportation card activated."<<endl;
    }
};

class Stop {
    string stopName;

public:
    Stop(string name) {
        stopName = name;
    }

    string getStopName() {
        return stopName;
    }
};

class Bus {
    string busName;
    Stop* stops[5];  
    int stopCount;
    int attendance; 
    Student* students[10];  
    int studentCount;
public:
    Bus(string name) {
        busName = name;
        stopCount = 0;
        attendance = 0;
        studentCount = 0;
        for(int i=0;i<5;i++){
            students[i] = nullptr;
        }
        for(int i=0;i<5;i++){
            stops[i] = nullptr;
        }
    }

    void addStudent(Student* student) {
        if (studentCount < 10) {
            students[studentCount] = student;
            student->assignBus(this);
            cout << student->getName() << " assigned to Bus: " << busName << endl;
            studentCount++;
        } else {
            cout << "Bus is full, cannot assign more students."<<endl;
        }
    }

    void addStop(Stop* stop) {
        if (stopCount < 5) {
            stops[stopCount++] = stop;
            cout << "Stop " << stop->getStopName() << " added to bus route: " << busName << endl;
        } else {
            cout << "Bus cannot take more stops."<<endl;
        }
    }

    void increaseAttendace();

    void displayAttendance()const {
        cout << "Total attendance recorded: " << attendance << endl;
    }

    void displayRoute() {
        cout << "Bus " << busName << " stops at:"<<endl;
        for (int i = 0; i < stopCount; i++) {
            cout << "- " << stops[i]->getStopName() << endl;
        }
    }
};

void Bus::increaseAttendace(){
    attendance++;
}

void Student::tapCard(){
    if (isActive) {
        cout << name << " tapped the card. Attendance marked."<<endl;
        assignedBus->increaseAttendace(); 
        return; 
    }
    cout << name << " cannot board the bus. Card is inactive."<<endl;
}


int main() {
    Bus bus1("Bus 1");
    Stop stop1("Stop A");
    Stop stop2("Stop B");
    Student student1("Alice", 101);
    Student student2("Bob", 102);
    bus1.addStudent(&student1);
    bus1.addStudent(&student1);
    bus1.addStop(&stop1);
    bus1.addStop(&stop2);
    student1.assignBus(&bus1);
    student2.assignBus(&bus1);
    student1.payFee();
    student1.tapCard();
    student2.tapCard();
    bus1.displayAttendance();
}
