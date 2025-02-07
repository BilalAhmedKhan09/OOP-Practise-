#include <iostream>

using namespace std;

struct Item {
    int itemID;
    string itemName;
    int stock;
    float cost;
};

void getInput(Item *i1, int count) {
    for (int i = 0; i < count; i++) {
        cout << "For item " << i + 1 << endl;
        cout << "Enter item name: ";
        cin.ignore();
        getline(cin, i1[i].itemName);
        cout << "Enter item ID: ";
        cin >> i1[i].itemID;
        cout << "Enter stock quantity: ";
        cin >> i1[i].stock;
        cout << "Enter cost: ";
        cin >> i1[i].cost;
    }
}

void showDetails(Item *i1, int count) {
    for (int i = 0; i < count; i++) {
        cout << "For Item " << i + 1 << endl;
        cout << "Name: " << i1[i].itemName << endl;
        cout << "Item ID: " << i1[i].itemID << endl;
        cout << "Cost: " << i1[i].cost << endl;
        cout << "Stock: " << i1[i].stock << endl;
        cout << "Total value: " << i1[i].stock * i1[i].cost << endl;
    }
}

int main() {
    int count;
    cout << "Enter the number of items you want to input: ";
    cin >> count;
    
    Item* items = new Item[count];
    getInput(items, count);
    showDetails(items, count);
    
    delete[] items;
}
