#include <iostream>
#include <string>
using namespace std;

class Wallet {
    string Ownername;
    float Totalbalance = 0;
    string transactionHistory[5] = {"0", "0", "0", "0", "0"};

public:
    void setmoney(float num) {
        if (num < 0 && Totalbalance + num < 0) {  
            cout << "Error: Insufficient balance for withdrawal!" << endl;
            return;
        }

        Totalbalance += num;

        // Shift transactions downward
        for (int i = 4; i > 0; i--) {
            transactionHistory[i] = transactionHistory[i - 1];
        }
        transactionHistory[0] = to_string(num);
    }

    void gettransactionHistory() {
        cout << "\nTransaction History (Last 5 Transactions):" << endl;
        for (int i = 0; i < 5; i++) {
            if (transactionHistory[i] != "0") {
                cout << transactionHistory[i] << endl;
            }
        }
    }

    void getbalance() {
        cout << "Current Balance: " << Totalbalance << endl;
    }
};

int main() {
    Wallet wallet;
    int choice;
    float num;

    do {
        cout << "\n1. Deposit/Withdraw Money\n2. Check Balance\n3. View Transaction History\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount (negative for withdrawal): ";
                cin >> num;
                wallet.setmoney(num);
                break;
            case 2:
                wallet.getbalance();
                break;
            case 3:
                wallet.gettransactionHistory();
                break;
            case 0:
                cout << "Exiting the program. Thank you!" << endl;
                break;
            default:
                cout << "Invalid input! Please enter a valid choice." << endl;
        }
    } while (choice != 0);

    return 0;
}
