#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;

class Item {
    public:
    int ID;
    char Name[20];
};

void write(Item &item) {
    ofstream file("inventory.dat", ios::binary);
    if (!file){
        return;
    }
    file.write((char*)(&item), sizeof(item));
    file.close();
}

void read(Item &item){
    ifstream file("inventory.dat", ios::binary);
    if (!file){
        return;
    }
    file.read((char*)(&item), sizeof(item));
    file.close();
}

int main(){
    Item item;
    item.ID = 123;
    strncpy(item.Name, "Product", sizeof(item.Name) - 1);
    item.Name[sizeof(item.Name) - 1] = '\0';
    write(item);
    Item item2;
    read(item2);
    cout<<item2.Name<<endl;
    cout<<item2.ID<<endl;
}