#include<iostream>
#include<string>
using namespace std;

class Item {
protected:
    int code;
    string label;
    float cost;
    int stock;
public:
    Item(int id, string name, float price, int quantity) {
        code = id;
        label = name;
        cost = price;
        stock = quantity;
    }
    virtual void applyReduction() {
        cost -= (cost * 0.1);
    }
    virtual void computeTotalCost(int quantity) {
        cout << "Total Cost: " << cost * quantity << endl;
    }
    virtual void present() {
        cout << "Code: " << code << endl;
        cout << "Label: " << label << endl;
        cout << "Cost: " << cost << endl;
        cout << "Stock: " << stock << endl;
    }
    Item operator+(Item &p) {
        return Item(0, "Bulk Order", cost + p.cost, 0);
    }
    friend void operator<<(ostream& output, Item &p) {
        output << "Label: " << p.label << endl;
        output << "Cost: " << p.cost << endl;
    }
};

class Gadget: public Item{
    string warranty;
    string manufacturer;
public:
    Gadget(int id, string name, float price, int quantity, string period, string brand): Item(id, name, price, quantity) {
        warranty = period;
        manufacturer = brand;
    }
    void present() override {
        Item::present();
        cout << "Warranty: " << warranty << endl;
        cout << "Manufacturer: " << manufacturer << endl;
    }
};

class Apparel: public Item {
    string fit;
    string fabric;
    string shade;
public:
    Apparel(int id, string name, float price, int quantity, string size, string material, string color): Item(id, name, price, quantity){
        fit = size;
        fabric = material;
        shade = color;
    }
    void applyReduction() override {
        cost -= (cost * 0.2);
    }
    void present() override {
        Item::present();
        cout << "Fit: " << fit << endl;
        cout << "Fabric: " << fabric << endl;
        cout << "Shade: " << shade << endl;
    }
};

class Edible: public Item{
    string expiry;
    int energy;
public:
    Edible(int id, string name, float price, int quantity, string date, int calories): Item(id, name, price, quantity) {
        expiry = date;
        energy = calories;
    }
    void computeTotalCost(int quantity) override {
        cost -= (cost * 0.5);
        cout << "Total Cost: " << cost * quantity << endl;
    }
    void present() override {
        Item::present();
        cout << "Expiry: " << expiry << endl;
        cout << "Energy: " << energy << endl;
    }
};

class Novel: public Item {
    string writer;
    string category;
public:
    Novel(int id, string name, float price, int quantity, string author, string genre): Item(id, name, price, quantity) {
        writer = author;
        category = genre;
    }
    void present() override {
        Item::present();
        cout << "Writer: " << writer << endl;
        cout << "Category: " << category << endl;
    }
};

int main(){
    Gadget tech1(1, "Smartphone", 70000, 15, "2 years", "Samsung");
    Apparel wear1(2, "Jacket", 2500, 30, "L", "Leather", "Black");
    Edible snack1(3, "Chocolates", 150, 200, "05/11/2023", 250);
    Novel book1(4, "The Hobbit", 1200, 8, "J.R.R. Tolkien", "Fantasy");
    tech1.present();
    cout << endl;
    wear1.present();
    cout << endl;
    snack1.present();
    cout << endl;
    book1.present();
    cout << endl;
    tech1.applyReduction();
    wear1.applyReduction();
    snack1.computeTotalCost(10);
    Item order = tech1 + wear1;
    cout << order;
    cout << endl;
    cout << "Displaying using friend function: " << endl;
    cout << tech1;
    cout << wear1;
    cout << snack1;
    cout << book1;
}