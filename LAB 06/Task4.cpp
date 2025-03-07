#include<iostream>

using namespace std;

class Account {
protected:
    int accNum; float accBalance;
public:
    Account(int num, float bal) : accNum(num), accBalance(bal) {}
    void display() const {
        cout << "Account No: " << accNum << endl;
        cout << "Balance: " << accBalance << endl;
    }
};

class SavingAccount : private Account {
private:
    float interest;
public:
    SavingAccount(int num, float bal, float rate) : Account(num, bal), interest(rate) {}
    void display() const {
        Account::display();
        cout << "Interest Rate: " << interest << endl;
    }
};

class CheckingAccount : private Account {
private:
    float overdraft;
public:
    CheckingAccount(int num, float bal, float limit) : Account(num, bal), overdraft(limit) {}
    void display() const {
        Account::display();
        cout << "Overdraft Limit: " << overdraft << endl;
    }
};

int main() {
    SavingAccount s(1, 4000.0, 3.5);
    CheckingAccount c(2, 1000.0, 1000.0);
    cout << "Saving Account\n"; s.display();
    cout << "-------------------" << endl;
    cout << "Checking Account\n"; c.display();
}
