#include <iostream>

using namespace std;

class Product {
    int productID, quantity;
    string productName;
    public:
        Product() {}
        Product(int id, string name, int qty) {
            productID = id;
            productName = name;
            quantity = qty;
        }
        int getID() const {
            return productID;
        }
        string getName() const {
            return productName;
        }
        void showProductInfo() const {
            cout << "Product ID: " << productID << endl;
            cout << "Product Name: " << productName << endl;
            cout << "Quantity: " << quantity << endl;
            cout << "-----------------------------" << endl;
        }
};

class Inventory {
    Product productList[50];
    int totalProducts = 0;
    public:
        void addProduct(int id, string name, int qty) {
            productList[totalProducts++] = Product(id, name, qty);
        }
        void sortProducts() {
            for (int i = 0; i < totalProducts - 1; i++) {
                for (int j = 0; j < totalProducts - i - 1; j++) {
                    if (productList[j].getName() > productList[j + 1].getName()) {
                        swap(productList[j], productList[j + 1]);
                    }
                }
            }
        }
        void searchByID(int id) {
            for (int i = 0; i < totalProducts; i++) {
                if (productList[i].getID() == id) {
                    cout << "Product Found:\n";
                    productList[i].showProductInfo();
                    return;
                }
            }
            cout << "Product not found.\n";
        }
        void showInventory() {
            cout << "Inventory:\n";
            cout << "-----------------------------" << endl;
            for (int i = 0; i < totalProducts; i++) {
                productList[i].showProductInfo();
            }
        }
};

int main() {
    Inventory warehouse;
    warehouse.addProduct(101, "Table", 10);
    warehouse.addProduct(102, "Laptop", 5);
    warehouse.addProduct(103, "Apple", 20);
    warehouse.sortProducts();
    warehouse.showInventory();
    cout << "\nSearching for Product ID 102:\n";
    warehouse.searchByID(102);

}
