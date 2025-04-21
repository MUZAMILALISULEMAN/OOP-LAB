#include <iostream>
#include <string>
using namespace std;

class Shipment {
protected:
    string trackingNumber;
    double weight;

public:
    Shipment(string tNumber, double w) : trackingNumber(tNumber), weight(w) {}
    virtual double estimateDeliveryTime() = 0;
    virtual void showDetails() = 0;
    virtual ~Shipment() {}
};

class AirFreight : public Shipment {
public:
    AirFreight(string tNumber, double w) : Shipment(tNumber, w) {}

    double estimateDeliveryTime()  {
        return weight * 0.5;
    }

    void showDetails()  {
        cout << "AIR FREIGHT DETAILS" << endl;
        cout << "TRACKING NUMBER: " << trackingNumber << endl;
        cout << "WEIGHT: " << weight << endl;
        cout << "ESTIMATED DELIVERY TIME: " << estimateDeliveryTime() << " HOURS" << endl;
    }
};

class GroundShipment : public Shipment {
public:
    GroundShipment(string tNumber, double w) : Shipment(tNumber, w) {}

    double estimateDeliveryTime()  {
        return weight * 1.5;
    }

    void showDetails() {
        cout << "GROUND SHIPMENT DETAILS" << endl;
        cout << "TRACKING NUMBER: " << trackingNumber << endl;
        cout << "WEIGHT: " << weight << endl;
        cout << "ESTIMATED DELIVERY TIME: " << estimateDeliveryTime() << " HOURS" << endl;
    }
};

int main() {
    Shipment* air = new AirFreight("AF123", 10.5);
    Shipment* ground = new GroundShipment("GS456", 20.0);

    air->showDetails();
    cout<<endl;
    ground->showDetails();

    delete air;
    delete ground;

    return 0;
}