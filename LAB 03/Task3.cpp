#include<iostream>

using namespace std;

class Library{
    int TotalBooks = 0;
    string Booklist[10];
    string BorrowedBooks[10];
    string AvailableBooks[10];

    public:
    void setBooklist(string bookname){
        TotalBooks += 1;
        Booklist[TotalBooks-1] = bookname;
        AvailableBooks[TotalBooks-1] = bookname;
    }
    
    void BorrowBooks(string bookname){
        for (int i = 0; i < TotalBooks; i++) {
            if (AvailableBooks[i] == bookname) {
                for (int j = i; j < TotalBooks - 1; j++) {
                    AvailableBooks[j] = AvailableBooks[j + 1];
                }
                AvailableBooks[TotalBooks - 1] = "";
                for (int k = 9; k > 0; k--) {
                    BorrowedBooks[k] = BorrowedBooks[k - 1];
                }
                BorrowedBooks[0] = bookname;
                cout << "Successfully borrowed: " << bookname << endl;
                return;
            }
        }
        cout << "Book not available for borrowing.\n";
    }

    void ReturnBooks(string bookname) {
        for (int i = 0; i < 10; i++) {
            if (BorrowedBooks[i] == bookname) {
                for (int j = i; j < 9; j++) {
                    BorrowedBooks[j] = BorrowedBooks[j + 1];
                }
                BorrowedBooks[9] = "";
                for (int k = 9; k > 0; k--) {
                    AvailableBooks[k] = AvailableBooks[k - 1];
                }
                AvailableBooks[0] = bookname;
                cout << "Successfully returned: " << bookname << endl;
                return;
            }
        }
        cout << "This book was not borrowed.\n";
    }

    string* GetAvailableBooks(){
        return AvailableBooks;
    }

    string* GetBorrowedBooks(){
        return BorrowedBooks;
    }

    string* GetBooklist(){
        return Booklist;
    }

};

int main() {
    Library lib;
    int choice;
    string bookname;
    do {
        cout << "\nLibrary Menu:\n";
        cout << "1. Add a Book\n";
        cout << "2. Borrow a Book\n";
        cout << "3. Return a Book\n";
        cout << "4. View Available Books\n";
        cout << "5. View Borrowed Books\n";
        cout << "6. View Full Book List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 
        switch (choice) {
            case 1:
                cout << "Enter book name to add: ";
                getline(cin, bookname);
                lib.setBooklist(bookname);
                cout << "Book added successfully!\n";
                break;
            case 2:
                cout << "Enter book name to borrow: ";
                getline(cin, bookname);
                lib.BorrowBooks(bookname);
                cout << "Book borrowed (if available)!\n";
                break;
            case 3:
                cout << "Enter book name to return: ";
                getline(cin, bookname);
                lib.ReturnBooks(bookname);
                cout << "Book returned (if it was borrowed)!\n";
                break;
            case 4: {
                string* available = lib.GetAvailableBooks();
                cout << "Available Books:\n";
                for (int i = 0; i < 10; i++) {
                    if (!available[i].empty()) cout << "- " << available[i] << endl;
                }
                break;
            }
            case 5: {
                string* borrowed = lib.GetBorrowedBooks();
                cout << "Borrowed Books:\n";
                for (int i = 0; i < 10; i++) {
                    if (!borrowed[i].empty()) cout << "- " << borrowed[i] << endl;
                }
                break;
            }
            case 6: {
                string* booklist = lib.GetBooklist();
                cout << "Complete Book List:\n";
                for (int i = 0; i < 10; i++) {
                    if (!booklist[i].empty()) cout << "- " << booklist[i] << endl;
                }
                break;
            }
            case 0:
                cout << "Exiting the Library System. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);
}
