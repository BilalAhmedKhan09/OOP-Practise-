#include<iostream>

using namespace std;

class Skill{
    private:
    int ID;
    string Name;
    string Description;
    public:
    Skill(){}
    Skill(int id,string name, string description){
        ID = id;
        Name = name;
        Description = description;
    }

    void showSkillDetails(){
        cout<<"Skill ID: "<<ID<<endl;
        cout<<"Skill Name: "<<Name<<endl;
        cout<<"Description: "<<Description<<endl;
    }

    void UpdateSkillDescription(string description){
        Description = description;
    }
    
    int getID(){
        return ID;
    }
};

class Sport{
    private:
    int ID;
    string Name;
    string Description;
    Skill RequiredSkills[5];
    public:
    Sport(){}
    Sport(int id, string name, string description){
        ID = id;
        Name = name;
        Description = description;
    }

    void AddSkill(Skill s){
        for(int i=4; i>0; i--){
            RequiredSkills[i] = RequiredSkills[i-1];
        }
        RequiredSkills[0] = s;
    }

    void RemoveSkill(Skill s){
        for(int i=0;i<5;i++){
            if(s.getID() == RequiredSkills[i].getID()){
                for(int j=i;j<4;j++){
                    RequiredSkills[j] = RequiredSkills[j+1];
                }
                RequiredSkills[4] = Skill();
            }
        }
    }
    
    int getID(){
        return ID;
    }
};

class Mentor; // Forward declaration

class Student{
    private:
    int ID;
    string Name;
    int Age;
    Mentor* MentorAssigned;
    Sport SportsInterests[5];
    public:
    Student(){}
    Student(int id, string name, int age){
        ID = id;
        Name = name;
        Age = age;
        MentorAssigned = nullptr;
    }

    void RegisterForMentor(Mentor *m);
    void ViewMentorDetails();
    void UpdateSportsInterests(Sport s);

    int getID(){
        return ID;
    }
};

class Mentor{
    private:
    int ID;
    string Name;
    int MaxLearners;
    Student* AssignedLearners[5];
    Sport SportsExpertise[5];
    public:
    Mentor(){}
    Mentor(int id, string name, int maxLearners, Sport sportsexpertise[5]){
        ID = id;
        Name = name;
        MaxLearners = maxLearners;
        for(int i=0;i<MaxLearners;i++){
            AssignedLearners[i] = nullptr;
        }
        for (int i = 0; i < 5; i++) {
            SportsExpertise[i] = sportsexpertise[i];
        }
    }

    void AssignLearner(Student &s);
    void RemoveLearner(Student &s);
    Student** ViewLearners(){ return AssignedLearners; }
    void ProvideGuidance(string guidance){ cout<<"Guidance Provided"<<endl; }
    int getAssignedLearners();
    int getmaxlearners(){ return MaxLearners; }
    void getdetails();
};

void Student::RegisterForMentor(Mentor *m){
    if(m->getAssignedLearners() == m->getmaxlearners()){
        cout<<"Sorry, the mentor does not have a slot free"<<endl;
        return;
    }
    MentorAssigned = m;
    m->AssignLearner(*this);
}

void Student::ViewMentorDetails(){
    if(MentorAssigned != nullptr){
        MentorAssigned->getdetails();
    } else {
        cout << "No mentor assigned" << endl;
    }
}

void Student::UpdateSportsInterests(Sport s){
    for(int i=4; i>0; i--){
        SportsInterests[i] = SportsInterests[i-1];
    }
    SportsInterests[0] = s;
}

void Mentor::AssignLearner(Student &s){
    for(int i=0; i<MaxLearners; i++){
        if(AssignedLearners[i] == nullptr){
            AssignedLearners[i] = &s;
            return;
        }
    }
}

void Mentor::RemoveLearner(Student &s){
    for(int i=0; i<MaxLearners; i++){
        if(AssignedLearners[i] != nullptr && AssignedLearners[i]->getID() == s.getID()){
            for(int j=i; j<MaxLearners-1; j++){
                AssignedLearners[j] = AssignedLearners[j+1];
            }
            AssignedLearners[MaxLearners-1] = nullptr;
            return;
        }
    }
}

int Mentor::getAssignedLearners(){
    int count = 0;
    for(int i=0; i<MaxLearners; i++){
        if(AssignedLearners[i] != nullptr) count++;
    }
    return count;
}

void Mentor::getdetails(){
    cout<<"Mentor ID: "<<ID<<endl;
    cout<<"Mentor Name: "<<Name<<endl;
    cout<<"Sport Expertise (Sport ID):"<<endl;
    for(int i=0; i<5; i++){
        cout<<SportsExpertise[i].getID()<<" ";
    }
    cout<<endl;
}

int main(){
    Skill skill(123, "Control", "Ball control");
    skill.showSkillDetails();
    skill.UpdateSkillDescription("Advanced ball control");
    skill.showSkillDetails();

    Sport sport(456, "Football", "Game of Footwork");
    sport.AddSkill(skill);
    sport.RemoveSkill(skill);
    cout << "Sport ID: " << sport.getID() << endl;

    Student student(1, "Bilal", 19);
    cout << "Student ID: " << student.getID() << endl;
    student.UpdateSportsInterests(sport);
    
    Sport arr[5];
    arr[0] = sport;
    Mentor mentor(789, "James", 5, arr);
    mentor.getdetails();
    student.RegisterForMentor(&mentor);
    student.ViewMentorDetails();
    mentor.ProvideGuidance("Keep practicing your dribbling skills");
    cout << "Assigned Learners: " << mentor.getAssignedLearners() << endl;
    mentor.ViewLearners();
    mentor.RemoveLearner(student);
    cout << "Assigned Learners after removal: " << mentor.getAssignedLearners() << endl;
    
}
