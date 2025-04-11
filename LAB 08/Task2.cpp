#include<iostream>

using namespace std;

class BankAccount{
private:
    int accNumber;
    double currentBalance;

public:
    BankAccount(int number, double bal) : accNumber(number), currentBalance(bal) {}

    friend class BankManager;
    friend void MoveFunds(BankAccount &sender, BankAccount &receiver, double amt);
};

class BankManager{
public:
    void addFunds(BankAccount &account, double amt){
        account.currentBalance += amt;
    }

    void deductFunds(BankAccount &account, double amt){
        if (amt <= account.currentBalance)
            account.currentBalance -= amt;
        else
            cout << "Not enough balance" << endl;
    }

    void showDetails(BankAccount &account){
        cout << "Account Number: " << account.accNumber << endl;
        cout << "Current Balance: " << account.currentBalance << endl;
    }
};

void MoveFunds(BankAccount &sender, BankAccount &receiver, double amt){
    if (amt <= sender.currentBalance)
    {
        sender.currentBalance -= amt;
        receiver.currentBalance += amt;
    }
    else
        cout << "Not enough balance" << endl;
}

int main()
{
    BankAccount account1(101, 5000.0), account2(102, 3000.0);
    BankManager manager;

    manager.addFunds(account1, 1000.0);
    cout << "After Adding Funds:" << endl;
    manager.showDetails(account1);

    cout << "Balances Before Transfer:" << endl;
    manager.showDetails(account1);
    manager.showDetails(account2);

    manager.deductFunds(account2, 500.0);
    cout << "After Deducting Funds:" << endl;
    manager.showDetails(account2);

    MoveFunds(account1, account2, 2000.0);
    cout << "Balances After Transfer:" << endl;
    manager.showDetails(account1);
    manager.showDetails(account2);
}


