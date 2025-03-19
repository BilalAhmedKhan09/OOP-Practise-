#include <iostream>
using namespace std;

class Stop;
class Bus;

class Passenger {
    protected:
    string name;
    bool feePaid;
    bool isActive;
    Stop* assignedStop; 
    Bus* assignedBus;

public:
    Passenger(string n) {
        name = n;
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

class Faculty: public Passenger{
    int FacultyID;
    public:
    Faculty(string n, int id): Passenger(n), FacultyID(id){}
    void payFee(){
        cout<<"Monthly payment. ";
        Passenger::payFee();
    }
};

class Student: public Passenger{
    int StudentID;
    public:
    Student(string n, int id): Passenger(n), StudentID(id){}
    void payFee(){
        cout<<"Semester transport fee. ";
        Passenger::payFee();
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
    Student* students[15];  
    Faculty* faculties[5];  
    int studentCount;
    int facultyCount;
public:
    Bus(string name) {
        busName = name;
        stopCount = 0;
        attendance = 0;
        studentCount = 0;
        facultyCount = 0;
        for(int i=0;i<5;i++){
            stops[i] = nullptr;
        }
    }
    bool operator==(const Bus& bus) const {
        if (bus.stopCount != stopCount) {
            return false;
        }
        for (int i = 0; i < stopCount; i++) {
            if (bus.stops[i]->getStopName() != stops[i]->getStopName()) {
                return false;
            }
        }
        return true;
    }
    void CheckDuplication(Bus *bus) {
        if(*this == *bus) {
            cout<<"Similar bus already exists"<<endl;
            delete this;
        }
    }
    void addStudent(Student* student) {
        if (studentCount < 15) {
            students[studentCount] = student;
            student->assignBus(this);
            cout << student->getName() << " assigned to Bus: " << busName << endl;
            studentCount++;
        } else {
            cout << "Bus is full, cannot assign more students."<<endl;
        }
    }

    void addFaculty(Faculty* faculty) {
        if (facultyCount < 5) {
            faculties[facultyCount] = faculty;
            faculty->assignBus(this);
            cout << faculty->getName() << " assigned to Bus: " << busName << endl;
            facultyCount++;
        } else {
            cout << "Bus is full, cannot assign more faculty members."<<endl;
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

void Passenger::tapCard(){
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
    Faculty faculty1("Bob", 202);
    bus1.addStudent(&student1);
    bus1.addFaculty(&faculty1);
    bus1.addStop(&stop1);
    bus1.addStop(&stop2);
    student1.payFee();
    student1.tapCard();
    faculty1.tapCard();
    bus1.displayAttendance();

    Bus bus2("Bus 2");
    bus2.addStop(&stop1);
    bus2.addStop(&stop2);
    bus2.CheckDuplication(&bus1);
}