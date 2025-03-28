#include <iostream>

using namespace std;

class Character {
protected:
    int CharacterID;
    string Name;
    int Level;
    int HealthPoints;
    string WeaponType;

public:
    Character(int id, string name, int level, int health, string weapon) {
        CharacterID = id;
        Name = name;
        Level = level;
        HealthPoints = health;
        WeaponType = weapon;
    }

    virtual void Attack() {
        cout << "An attack was performed" << endl;
    }

    virtual void Defend() {
        cout << "Attack Parried" << endl;
    }

    virtual void DisplayStats() {
        cout << "Character ID: " << CharacterID << endl;
        cout << "Name: " << Name << endl;
        cout << "Level: " << Level << endl;
        cout << "Health Points: " << HealthPoints << endl;
        cout << "Weapon Type: " << WeaponType << endl;
    }
};

class Warrior : public Character {
    int ArmorStrength;
    int MeleeDamage;

public:
    Warrior(int id, string n, int l, int hp, string wt, int armor, int damage)
        : Character(id, n, l, hp, wt) {
        ArmorStrength = armor;
        MeleeDamage = damage;
    }

    void Attack() override {
        cout << "A melee attack was performed with " << WeaponType << " dealing " << MeleeDamage << " damage" << endl;
    }

    void DisplayStats() override {
        Character::DisplayStats();
        cout << "Armor Strength: " << ArmorStrength << endl;
        cout << "Melee Damage: " << MeleeDamage << endl;
    }
};

class Mage : public Character {
    int SpellPower;
    int ManaPoints;

public:
    Mage(int id, string n, int l, int hp, string wt, int sp, int mp)
        : Character(id, n, l, hp, wt) {
        SpellPower = sp;
        ManaPoints = mp;
    }

    void Defend() override {
        cout << "Defended with magical barriers" << endl;
    }

    void DisplayStats() override {
        Character::DisplayStats();
        cout << "Spell Power: " << SpellPower << endl;
        cout << "Mana Points: " << ManaPoints << endl;
    }
};

class Archer : public Character {
    int ArrowCount;
    string RangedAccuracy;

public:
    Archer(int id, string n, int l, int hp, string wt, int ac, string ra)
        : Character(id, n, l, hp, wt) {
        ArrowCount = ac;
        RangedAccuracy = ra;
    }

    void Attack() override {
        cout << "Used an Arrow for Long range attack" << endl;
    }

    void DisplayStats() override {
        Character::DisplayStats();
        cout << "Arrow Count: " << ArrowCount << endl;
        cout << "Ranged Accuracy: " << RangedAccuracy << endl;
    }
};

class Rogue : public Character {
    int StealthLevel;
    int Agility;

public:
    Rogue(int id, string n, int l, int hp, string wt, int sl, int ag)
        : Character(id, n, l, hp, wt) {
        StealthLevel = sl;
        Agility = ag;
    }

    void DisplayStats() override {
        Character::DisplayStats();
        cout << "Stealth Level: " << StealthLevel << endl;
        cout << "Agility: " << Agility << endl;
    }
};

int main() {
    Warrior w(1, "Warrior", 10, 100, "Sword", 50, 20);
    Mage m(2, "Mage", 10, 100, "Staff", 30, 50);
    Archer a(3, "Archer", 10, 100, "Bow", 30, "High");
    Rogue r(4, "Rogue", 10, 100, "Dagger", 40, 40);
    w.DisplayStats();
    cout<<endl;
    m.DisplayStats();
    cout<<endl;
    a.DisplayStats();
    cout<<endl;
    r.DisplayStats();
    cout<<endl;
    w.Attack();
    cout<<endl;
    m.Defend();
    cout<<endl;
    a.Attack();
}
