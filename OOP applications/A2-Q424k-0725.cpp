#include<iostream>

using namespace std;

int GenerateHash(string password){
    int hash_value = 5381;
    for(int i=0;password[i]!='\0';i++){
        hash_value = (hash_value * 33) + password[i];
    }
    return hash_value;
}

class User{
    protected:
    string Name;
    int ID;
    string Email;
    int HashedPassword;
    string ListofPermissions[2];
    public:
    User(string n, int id, string e, string password, string permission1, string permission2): Name(n), ID(id), Email(e) {
        HashedPassword = GenerateHash(password);
        ListofPermissions[0] = permission1;
        ListofPermissions[1] = permission2;
    }
    void AuthenticateUser(string password){
        if(HashedPassword == GenerateHash(password)){
            cout<<"User authenticated..."<<endl;
        } else {
            cout<<"Authentication failed."<<endl;
        }
    }
    virtual void Display(){
        cout<<"Name: "<<Name<<endl;
        cout<<"ID: "<<ID<<endl;
        cout<<"Email: "<<Email<<endl;
        cout<<"List of granted permissions: "<<endl;
        for(int i=0;i<2;i++){
            if(ListofPermissions[i] != "N/A"){
                cout<<ListofPermissions[i]<<endl;
            }
        }
    }
    void AccessLab(){
        for(int i=0;i<2;i++){
            if(ListofPermissions[i] == "Full lab access"){
                cout<<"Lab access granted"<<endl;
            }
            else{
                cout<<"Access denied"<<endl;
            }
        }
    }
};

class Student: public User{
    protected:
    int Assignments[3];
    int Assignmentcount;
    public:
    Student(string n, int id, string e, string password, string permission1, string permission2):User(n, id, e, password, permission1, permission2) {
        Assignmentcount = 0;
        for(int i=0;i<3;i++){
            Assignments[i] = 0;
        }
    }
    void AddAssignment(){
        if(Assignmentcount < 3){
            for(int i=0;i<3;i++){
                if(Assignments[i] == 1){
                Assignments[i] = 0;
                Assignmentcount++;
                }
            }
            cout<<"Task assigned"<<endl;
        }
        else{
            cout<<"Please do not burden the student"<<endl;
        }
    }
    void SubmitAssignment(int Assignmentno){
        Assignments[Assignmentno - 1] = 1;
        cout<<"Assignment submitted"<<endl;
        Assignmentcount--;
    }
    void Display()override{
        User::Display();
        cout<<"Providing Student assignment details: "<<endl;
        for(int i=0;i<3;i++){
            if(Assignments[i] == 1){
                cout<<"Assignment "<<i<<" has been completed";
            }
            else{
                cout<<"\tAssignment "<<i<<" has not been completed"<<endl;
            }
        }
    }
    int Getstudentid(){
        return ID;
    }
    string GetstudentName(){
        return Name;
    }
};

class TA : public Student {
    Student *AssignedStudents[10];
    string ListofProjects[2];
    int ProjectCount;
    int StudentCount;
    public:
    TA(string n, int id, string e, string password, string permission1, string permission2):   
    Student(n, id, e, password, permission1, permission2) {
        ProjectCount = 0;
        StudentCount = 0;
        for(int i=0;i<10;i++){
            if(i<2){
                ListofProjects[i] = "N/A";
            }
            AssignedStudents[i] = nullptr;
        }
    }
    void viewproject(){
        for(int i=0;i<ProjectCount;i++){
            cout<<"Project: "<<ListofProjects[i]<<endl;
        }
    }
    void AddProject(string project_description){
        if(ProjectCount < 2){
            if(ListofProjects[0] == "N/A"){
                ListofProjects[0] = project_description;
            }
            else{
                ListofProjects[1] = project_description;
            }
            cout<<"Project assigned"<<endl;
            ProjectCount++;
        }
        else{
            cout<<"Cannot work on more projects"<<endl;
        }
    }
    void AssignStudents(Student *s){
        for(int j=0; j<2;j++){
            if(ListofPermissions[j] == "Management of Students"){
                if(StudentCount < 10){
                    for(int i=0;i<10;i++){
                        if(AssignedStudents[i] == nullptr){
                            AssignedStudents[i] = s;
                        }
                    }
                    StudentCount++;
                }
                else{
                    cout<<"Maximum number of students already assigned"<<endl;
                }
            }
        }
    }
    void Display() override {
        User::Display();
        cout<<"Displaying project details: "<<endl;
        viewproject();
        cout<<"Providing details of assigned students"<<endl;
        for(int i=0;i<10;i++){
            if(AssignedStudents[i] != nullptr){
                cout<<"Name: "<<AssignedStudents[i]->GetstudentName()<<"\tID: "<<AssignedStudents[i]->Getstudentid()<<endl;
            }
        }
    }
    string Get_TA_Name(){
        return Name;
    }
};

class Professor : public User{
    public:
    Professor(string n, int id, string e, string password, string permission1, string permission2): User(n, id, e, password, permission1, permission2) {}
    void AssignProject(TA *t, string project_description){
        t->AddProject(project_description);
    }
    void Display()override{
        cout<<"Displaying professor details: "<<endl;
        User::Display();
    }
};

int main() {
    User user1("John Doe", 1001, "john@example.com", "password123", "Full lab access", "N/A");

    Student student1("Jane Smith", 1002, "jane@example.com", "studentpass", "Submit assignment", "N/A");
    student1.AddAssignment();
    student1.SubmitAssignment(1);
    
    TA ta1("Mark Brown", 1003, "mark@example.com", "tapassword", "View projects", "Management of Students");
    ta1.AssignStudents(&student1);
    
    Professor professor1("Dr. Alice White", 1004, "alice@example.com", "profpassword", "Assign projects", "Full lab access");
    professor1.AssignProject(&ta1, "Project 1: AI Research");

    user1.Display();
    user1.AuthenticateUser("password123");
    user1.AccessLab();

    student1.Display();
    student1.AuthenticateUser("studentpass");
    student1.AccessLab();

    ta1.Display();
    ta1.AuthenticateUser("tapassword");
    ta1.AccessLab();

    professor1.Display();
    professor1.AuthenticateUser("profpassword");
    professor1.AccessLab();
}