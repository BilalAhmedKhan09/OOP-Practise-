#include <iostream>
#include<exception> 

using namespace std;

class DatabaseException : public exception {
    public:
    const char* what() const noexcept override {
        return "Database error occurred";
    }
};

class ConnectionFailedException : public DatabaseException {};

class QuerytimeoutException : public DatabaseException {};
 
template <typename T>
class DatabaseConnector {
    public:
    void connect(const string& dbName) {
        if (dbName == "invalid_db") {
            throw ConnectionFailedException();
        } else if (dbName == "slow_db") {
            throw DatabaseException();
        } else {
            cout << "Connected to " << dbName << " successfully."<<endl;
        }
    }
};

int main() {
    DatabaseConnector<int> db;
    try {
        cout << "Attempting to connect to invalid_db..."<<endl;
        db.connect("invalid_db");
    }
    catch (const ConnectionFailedException& e) {
        cout << "Caught ConnectionFailedException - what(): " << e.what() << endl;
    }
    try {
        cout << "\nAttempting to connect to slow_db...\n";
        db.connect("slow_db");
    }
    catch (const DatabaseException& e) {
        cout << "Caught a general DatabaseException - what(): " << e.what() << endl;
    }
}
