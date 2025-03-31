#include<iostream>

using namespace std;

class HauntedHouse;

class Visitor {
    string Name;
    int Bravery;
public:
    Visitor(string n, int b) : Name(n), Bravery(b) {}
    friend void visit(Visitor visitors[], int visitorCount, HauntedHouse& house);
    string getName(){
        return Name;
    }
    int getBravery(){
        return Bravery;
    }
};

class Ghost {
protected:
    string WorkerName;
    int ScareLevel;
public:
    Ghost(string name, int sl) : WorkerName(name), ScareLevel(sl) {}

    virtual void Haunt(Visitor &p) {

        if (p.getBravery() > ScareLevel) {
            cout << p.getName() << " taunts the ghost." << endl;
        }
        else if (p.getBravery() < ScareLevel) {
            cout << p.getName() << " runs away screaming." << endl;
        }
        else {
            cout << p.getName() << "'s voice becomes shaky." << endl;
        }
    }

    friend ostream& operator<<(ostream &out, const Ghost &g) {
        out << "Ghost played by: " << g.WorkerName << ", Scare Level: " << g.ScareLevel << endl;
        return out;
    }    

    Ghost operator+(const Ghost &other) {
        int newScareLevel = this->ScareLevel + other.ScareLevel;
        string newWorkerName = this->WorkerName + " & " + other.WorkerName;
        return Ghost(newWorkerName, newScareLevel);
    }
};

class Poltergeist : public Ghost {
public:
    Poltergeist(string name, int sl) : Ghost(name, sl) {}
    void Haunt(Visitor &p) override {
        cout << "Poltergeist moves objects violently." << endl;
        Ghost::Haunt(p);
    }
};

class Banshee : virtual public Ghost {
public:
    Banshee(string name, int sl) : Ghost(name, sl) {}
    void Haunt(Visitor &p) override {
        cout << "Banshee screams loudly." << endl;
        Ghost::Haunt(p);
    }
};

class ShadowGhost : virtual public Ghost {
public:
    ShadowGhost(string name, int sl) : Ghost(name, sl) {}
    void Haunt(Visitor &p) override {
        cout << "Ghost whispers creepily." << endl;
        Ghost::Haunt(p);
    }
};

class HybridGhost : public Banshee, public ShadowGhost {
public:
HybridGhost(string name, int sl) : Ghost(name, sl), Banshee(name, sl), ShadowGhost(name, sl) {}
    void Haunt(Visitor &p) override {
        Banshee::Haunt(p);
        ShadowGhost::Haunt(p);
    }
};

class HauntedHouse {
private:
    string HouseName;
    Ghost* Ghosts[3];
    int GhostCount;
public:
    HauntedHouse(string name) : HouseName(name), GhostCount(0) {}

    void addGhost(Ghost* ghost) {
        if (GhostCount < 3) {
            Ghosts[GhostCount++] = ghost;
        } else {
            cout << "Max number of ghosts reached!" << endl;
        }
    }

    friend void visit(Visitor visitors[], int visitorCount, HauntedHouse& house);
};

void visit(Visitor visitors[], int visitorCount, HauntedHouse& house) {
    cout << "Visitors are entering the Haunted House: " << house.HouseName << endl;
    for (int i = 0; i < visitorCount; i++) {
        for (int j = 0; j < house.GhostCount; j++) {
            house.Ghosts[j]->Haunt(visitors[i]);
        }
    }
}

int main() {
    Visitor visitors[] = { Visitor("Tom", 3), Visitor("Sarah", 6), Visitor("James", 9) };
    int visitorCount = 3;

    Poltergeist poltergeist1("John", 5);
    Banshee banshee1("Alice", 2);
    ShadowGhost shadowGhost1("David", 6);
    HybridGhost hybridGhost1("Lucas", 8);

    Ghost UpgradedGhost = poltergeist1+banshee1;

    HauntedHouse house1("Spooky Manor");
    house1.addGhost(&poltergeist1);
    house1.addGhost(&banshee1);

    HauntedHouse house2("Dark Hollow");
    house2.addGhost(&shadowGhost1);
    house2.addGhost(&hybridGhost1);

    cout << "Ghost Information:" << endl;
    cout << poltergeist1;
    cout << banshee1;
    cout << shadowGhost1;
    cout << hybridGhost1;
    cout << UpgradedGhost;

    cout << "\nVisiting Spooky Manor:" << endl;
    visit(visitors, visitorCount, house1);

    cout << "\nVisiting Dark Hollow:" << endl;
    visit(visitors, visitorCount, house2);
}