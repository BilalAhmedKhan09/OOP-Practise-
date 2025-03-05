#include <iostream>
using namespace std;

class Doctor {
private:
    string docName, docSpecialization, docExperience;
public:
    Doctor(string n, string s, string e) {
        docName = n;
        docSpecialization = s;
        docExperience = e;
    }
    void showDoctorInfo() const {
        cout << "Doctor's Name: " << docName << endl;
        cout << "Specialization: " << docSpecialization << endl;
        cout << "Experience: " << docExperience << endl;
        cout << "-----------------------------" << endl;
    }
};

class Hospital {
private:
    string hospitalName;
    Doctor* doctorList;
    int totalDoctors;
public:
    Hospital(string hName) {
        hospitalName = hName;
        totalDoctors = 0;
        doctorList = new Doctor[20];
    }
    ~Hospital() {
        delete[] doctorList;
    }
    void registerDoctor(const Doctor& d) {
        doctorList[totalDoctors++] = d;
    }
    void showHospitalInfo() const {
        cout << "Hospital Name: " << hospitalName << endl;
        cout << "Registered Doctors:\n";
        cout << "-----------------------------" << endl;
        for (int i = 0; i < totalDoctors; i++) {
            doctorList[i].showDoctorInfo();
        }
    }
};

int main() {
    Doctor d1("Meghan", "Cardiologist", "3.5 years"), d2("Martin", "Pediatrician", "2 years");
    Hospital h1("AKUH");
    h1.registerDoctor(d1);
    h1.registerDoctor(d2);
    h1.showHospitalInfo();
}
