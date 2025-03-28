#include<iostream>
#include<string>
using namespace std;

class Person {
protected:
    string fullName;
    int personAge;
    string contactNo;
    string homeAddress;
public:
    Person(string name, int age, string contact, string address)
        : fullName(name), personAge(age), contactNo(contact), homeAddress(address) {}
    
    virtual void displayInfo() {
        cout << "Name: " << fullName << endl;
        cout << "Age: " << personAge << endl;
        cout << "Contact Number: " << contactNo << endl;
        cout << "Address: " << homeAddress << endl;
    }

    virtual void updateDetails(string name, int age, string contact, string address) {
        fullName = name;
        personAge = age;
        contactNo = contact;
        homeAddress = address;
    }
};

class Patient : public Person {
    string patientID;
    string assignedDoctor;
    string healthRecord;
public:
    Patient(string name, int age, string contact, string address, string id, string doctor, string history)
        : Person(name, age, contact, address), patientID(id), assignedDoctor(doctor), healthRecord(history) {}
    
    void displayInfo() override {
        Person::displayInfo();
        cout << "Patient ID: " << patientID << endl;
        cout << "Assigned Doctor: " << assignedDoctor << endl;
        cout << "Medical History: " << healthRecord << endl;
    }

    void updateDetails(string name, int age, string contact, string address, string id, string doctor, string history) {
        Person::updateDetails(name, age, contact, address);
        patientID = id;
        assignedDoctor = doctor;
        healthRecord = history;
    }
};

class Doctor : public Person {
    string fieldOfExpertise;
    float appointmentFee;
    string patientRoster[5];
public:
    Doctor(string name, int age, string contact, string address, string specialty, float fee)
        : Person(name, age, contact, address), fieldOfExpertise(specialty), appointmentFee(fee) {
        for(int i = 0; i < 5; i++) {
            patientRoster[i] = "";
        }
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "Specialization: " << fieldOfExpertise << endl;
        cout << "Consultation Fee: " << appointmentFee << endl;
        cout << "Patient Roster: " << endl;
        for(int i = 0; i < 5; i++) {
            cout << patientRoster[i] << endl;
        }
    }

    void addPatient(string patientName) {
        for(int i = 0; i < 5; i++) {
            if(patientRoster[i] == "") {
                patientRoster[i] = patientName;
                break;
            }
        }
    }

    void removePatient(string patientName) {
        for(int i = 0; i < 5; i++) {
            if(patientRoster[i] == patientName) {
                patientRoster[i] = "";
                break;
            }
        }
    }
};

class Nurse : public Person {
    string wardAssigned;
    string shiftHours;
public:
    Nurse(string name, int age, string contact, string address, string ward, string shift)
        : Person(name, age, contact, address), wardAssigned(ward), shiftHours(shift) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Assigned Ward: " << wardAssigned << endl;
        cout << "Shift Timing: " << shiftHours << endl;
    }
};

class Administrator : public Person {
    string adminDepartment;
    float monthlySalary;
public:
    Administrator(string name, int age, string contact, string address, string department, float salary)
        : Person(name, age, contact, address), adminDepartment(department), monthlySalary(salary) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << adminDepartment << endl;
        cout << "Salary: " << monthlySalary << endl;
    }

    void updateDetails(string name, int age, string contact, string address, string department, float salary) {
        Person::updateDetails(name, age, contact, address);
        adminDepartment = department;
        monthlySalary = salary;
    }
};

int main() {
    Patient patient("Bilal Khan", 35, "03001654567", "House 123, Islamabad", "P001", "Dr. Ahmed", "No history");
    Doctor doctor("Dr. Ahmed", 27, "03004321", "Street 45, Lahore", "Cardiology", 5000);
    Nurse nurse("Hannah", 30, "0356543210", "House 78, Karachi", "ICU", "Night");
    Administrator admin("John Smith", 45, "03232345458", "Office 12, Lahore", "Finance", 15000);
    cout << "--- Hospital Management System ---\n";
    cout << "\nPatient Details:\n";
    patient.displayInfo();
    cout << "\nDoctor Details:\n";
    doctor.displayInfo();
    cout << "\nNurse Details:\n";
    nurse.displayInfo();
    cout << "\nAdministrator Details:\n";
    admin.displayInfo();
    cout << "\nUpdating Patient Details...\n";
    patient.updateDetails("Bilal Khan", 25, "0300123567", "House 123, Islamabad", "P001", "Dr. Ahmed", "Diabetes");
    patient.displayInfo();
    cout << "\nUpdating Administrator Details...\n";
    admin.updateDetails("John Smith", 45, "03002345678", "Office 12, Peshawar", "HR", 20000);
    admin.displayInfo();
    cout << "\nAdding Patient to Doctor's List...\n";
    doctor.addPatient("Bilal Khan");
    doctor.displayInfo();
    cout << "\nRemoving Patient from Doctor's List...\n";
    doctor.removePatient("Bilal Khan");
    doctor.displayInfo();
}
