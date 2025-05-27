#include <iostream>
#include <exception>

using namespace std;

class NegativeStockException : public exception {};

class OverCapacityException : public exception {};

template <typename T>
class InventoryItem {
    T stock;
    T maxStock;
    public:
    InventoryItem(T max) : stock(0), maxStock(max) {}
    void setStock(T value) {
        if (value < 0)
            throw NegativeStockException();
        else if (value > maxStock)
            throw OverCapacityException();
        stock = value;
    }
    void showStock() {
        cout << "Current stock: " << stock << endl;
    }
};

int main() {
    InventoryItem<int> item(100);
    try {
        cout << "Attempting to set stock to -5..."<<endl;
        item.setStock(-5);
    } catch (const NegativeStockException& e) {
        cout << "Caught NegativeStockException - what(): " << e.what() << endl;
    }
    try {
        cout << "\nAttempting to set stock to 120 (max 100)..."<<endl;
        item.setStock(120);
    } catch (const OverCapacityException& e) {
        cout << "Caught OverCapacityException - what(): " << e.what() <<endl;
    }
}
