#include<iostream>

using namespace std;

class Student{
    int ID;
    string Name;
    int *Examscores;
    
    public:
    Student(int id, string name, int examscores[5]){
        ID = id;
        Name = name;
        Examscores = new int[5];
        for(int i=0;i<5;i++){
            Examscores[i] = examscores[i];
        }
    }
    Student(Student &s){
        ID = s.ID;
        Name = s.Name;
        Examscores = new int [5];
        for(int i=0;i<5;i++){
            Examscores[i] = s.Examscores[i];
        }
    }
    void display() {
        cout << "Student ID: " << ID << endl;
        cout << "Name: " << Name << endl;
        cout << "Exam Scores: ";
        for (int i=0;i<5;i++) {
            cout << Examscores[i] << " ";
        }
        cout << endl;
    }
    ~Student() {
        delete[] Examscores; 
    }
};

int main() {
    int scores1[] = {85, 90, 78, 92, 88};
    int numScores = 5;
    Student student1(101, "Alice", scores1);
    cout << "Original Student:\n";
    student1.display();
    Student student2 = student1;
    cout << "\nCopied Student for Verification:\n";
    student2.display();
}

