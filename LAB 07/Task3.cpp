#include<iostream> 

using namespace std;

class Ticket{
protected:
    int ticketID;
    string passengerName;
    float ticketPrice;
    string date;
    string destination;
public:
    Ticket(int id, string name, float price, string date, string destination)
        : ticketID(id), passengerName(name), ticketPrice(price), date(date), destination(destination) {}

    virtual void reserveTicket(){
        cout << "Ticket Reserved" << endl;
    }
    
    virtual void cancelTicket(){
        cout << "Ticket Cancelled" << endl;
    }
    
    virtual void display(){
        cout << "Ticket ID: " << ticketID << endl;
        cout << "Passenger Name: " << passengerName << endl;
        cout << "Ticket Price: " << ticketPrice << endl;
        cout << "Destination: " << destination << endl;
        cout << "Date: " << date << endl;
    }
};

class FlightTicket : public Ticket{
    string airlineName;
    int flightNumber;
    string seatClass;
public:
    FlightTicket(int id, string name, float price, string dest, string date, string airline, int flight, string seat)
        : Ticket(id, name, price, date, dest), airlineName(airline), flightNumber(flight), seatClass(seat) {}

    void display() override{
        Ticket::display();
        cout << "Airline Name: " << airlineName << endl;
        cout << "Flight Number: " << flightNumber << endl;
        cout << "Seat Class: " << seatClass << endl;
    }
};

class TrainTicket: public Ticket{
    int trainNumber;
    string coachType;
    string departureTime;
    int seatNumber;
public:
    TrainTicket(int id, string name, float price, string dest, string date, int train, string coach, string time)
        : Ticket(id, name, price, date, dest), trainNumber(train), coachType(coach), departureTime(time), seatNumber(0) {}
    
    void reserveTicket() override{
        seatNumber = rand() % 100 + 1;
        cout << "Seat Number Assigned: " << seatNumber << endl;
    }
    
    void display() override{
        Ticket::display();
        cout << "Train Number: " << trainNumber << endl;
        cout << "Coach Type: " << coachType << endl;
        cout << "Departure Time: " << departureTime << endl;
        cout << "Seat Number: " << seatNumber << endl;
    }
};

class BusTicket: public Ticket{
    string busCompany;
    int seatNumber;
public:
    BusTicket(int id, string name, float price, string dest, string date, string company)
        : Ticket(id, name, price, date, dest), busCompany(company), seatNumber(0) {}
    
    void cancelTicket() override{
        cout << "Ticket Cancelled and money refunded" << endl;
    }
    
    void display() override{
        Ticket::display();
        cout << "Bus Company: " << busCompany << endl;
        cout << "Seat Number: " << seatNumber << endl;
    }
};

class ConcertTicket: public Ticket{
    string artistName;
    string venue;
    string seatType;
public:
    ConcertTicket(int id, string name, float price, string dest, string date, string artist, string place, string seat)
        : Ticket(id, name, price, date, dest), artistName(artist), venue(place), seatType(seat) {}
    
    void display() override{
        Ticket::display();
        cout << "Artist Name: " << artistName << endl;
        cout << "Venue: " << venue << endl;
        cout << "Seat Type: " << seatType << endl;
    }
};

int main(){
    FlightTicket f1(1, "John Doe", 5000, "New York", "12/12/2025", "Delta", 123, "Business");
    TrainTicket t1(2, "Jane Doe", 1000, "Chicago", "12/12/2025", 456, "First Class", "12:00 PM");
    BusTicket b1(3, "Alice", 500, "Los Angeles", "12/12/2025", "Greyhound");
    ConcertTicket c1(4, "Bob", 2000, "Las Vegas", "12/12/2025", "Ariana Grande", "MGM Grand", "VIP");
    f1.display();
    cout << endl;
    t1.display();
    cout << endl;
    b1.display();
    cout << endl;
    c1.display();
    cout << endl;
    f1.reserveTicket();
    t1.reserveTicket();
    b1.cancelTicket();
    c1.cancelTicket();
}