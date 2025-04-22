#include <iostream>

using namespace std;

class Shipment{
protected:
    string trackingID;
    double shipmentWeight;

public:
    Shipment(string trackingID, double shipmentWeight) : trackingID(trackingID), shipmentWeight(shipmentWeight) {}
    virtual void estimateDeliveryTime() = 0;
    virtual void displayDetails() = 0;
};

class AirFreight : public Shipment{
public:
    AirFreight(string trackingID, double shipmentWeight) : Shipment(trackingID, shipmentWeight) {}
    void estimateDeliveryTime(){
        cout << "Estimated delivery time for Air Freight: 2-3 days" << endl;
    }
    void displayDetails(){
        cout << "Air Freight Shipment Details:" << endl;
        cout << "Tracking ID: " << trackingID << endl;
        cout << "Weight: " << shipmentWeight << " kg" << endl;
    }
};

class GroundShipment : public Shipment{
public:
    GroundShipment(string trackingID, double shipmentWeight) : Shipment(trackingID, shipmentWeight) {}
    void estimateDeliveryTime(){
        cout << "Estimated delivery time for Ground Shipment: 5-7 days" << endl;
    }
    void displayDetails(){
        cout << "Ground Shipment Details:" << endl;
        cout << "Tracking ID: " << trackingID << endl;
        cout << "Weight: " << shipmentWeight << " kg" << endl;
    }
};

int main(){
    AirFreight airShipment("A5", 25.5);
    GroundShipment groundShipment("B6", 20.0);

    airShipment.estimateDeliveryTime();
    airShipment.displayDetails();

    groundShipment.estimateDeliveryTime();
    groundShipment.displayDetails();
}
