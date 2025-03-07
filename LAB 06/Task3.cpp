#include<iostream>

using namespace std;

class Person {
protected:
    string fullName;
    int years;
public:
    Person(string n, int a) : fullName(n), years(a) {}
    void display() const {
        cout << "Name: " << fullName << endl;
        cout << "Age: " << years << endl;
    }
};

class Teacher : protected Person {
protected:
    string field;
public:
    Teacher(string n, int a, string s) :
    Person(n, a), field(s) {}
    void display() const {
        Person::display();
        cout << "Subject: " << field << endl;
    }
};

class Researcher : protected Teacher {
protected:
    string studyArea;
public:
    Researcher(string n, int a, string s, string research) :
    Teacher(n, a, s), studyArea(research) {}
    void display() const {
        Teacher::display();
        cout << "Research Area: " << studyArea << endl;
    }
};

class Professor : protected Researcher {
private:
    int papers;
public:
    Professor(string n, int a, string s, string research, int p) :
    Researcher(n, a, s, research), papers(p) {}
    void display() const {
        Researcher::display();
        cout << "Publications: " << papers << endl;
    }
};

int main() {
    Professor prof("Dr. Will Smith", 50, "Computer Science", "Artificial Intelligence", 80);
    prof.display();
}
