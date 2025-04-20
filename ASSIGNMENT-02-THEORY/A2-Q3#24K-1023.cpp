#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
protected:
    string vehicleID;
    int vehicleSpeed;
    int vehicleCapacity;
    int energyEfficiency;
    static int totalDeliveries;

public:
    Vehicle(string id) : vehicleID(id) {}

    virtual void calculateRoute() = 0;
    virtual double estimateTime(double distance) = 0;

    virtual void command(string packageID)
    {
        totalDeliveries++;
        cout << "BASIC DELIVERY COMMAND FOR PACKAGE: " << packageID << endl;
    }

    virtual void command(string packageID, string urgency)
    {
        totalDeliveries++;
        cout << "URGENT DELIVERY COMMAND FOR PACKAGE: " << packageID << endl;
    }

    static int getTotalDeliveries() { return totalDeliveries; }

    friend bool operator==(const Vehicle &a, const Vehicle &b);
    friend Vehicle *resolveConflict(Vehicle *a, Vehicle *b);
};

int Vehicle::totalDeliveries = 0;

bool operator==(const Vehicle &a, const Vehicle &b)
{
    return (a.vehicleSpeed == b.vehicleSpeed) &&
           (a.vehicleCapacity == b.vehicleCapacity) &&
           (a.energyEfficiency == b.energyEfficiency);
}

Vehicle *resolveConflict(Vehicle *a, Vehicle *b)
{
    int aScore = a->vehicleSpeed * a->energyEfficiency + a->vehicleCapacity;
    int bScore = b->vehicleSpeed * b->energyEfficiency + b->vehicleCapacity;
    return aScore >= bScore ? a : b;
}

class RamzanDrone : public Vehicle
{
public:
    RamzanDrone(string id) : Vehicle(id)
    {
        vehicleSpeed = 100;
        vehicleCapacity = 10;
        energyEfficiency = 80;
    }

    void calculateRoute() override
    {
        cout << "CALCULATING AERIAL ROUTE FOR HIGH-SPEED DELIVERY" << endl;
    }

    double estimateTime(double distance) override
    {
        return distance / vehicleSpeed;
    }

    void command(string packageID, string urgency) override
    {
        if (urgency == "urgent")
        {
            cout << "DRONE ACTIVATING TURBO MODE FOR IFTAR MEAL: " << packageID << endl;
            vehicleSpeed *= 2;
        }
        Vehicle::command(packageID, urgency);
    }
};

class RamzanTimeShip : public Vehicle
{
public:
    RamzanTimeShip(string id) : Vehicle(id)
    {
        vehicleSpeed = 80;
        vehicleCapacity = 50;
        energyEfficiency = 70;
    }

    void calculateRoute() override
    {
        cout << "VERIFYING HISTORICAL CONSISTENCY FOR TIME TRAVEL" << endl;
    }

    double estimateTime(double distance) override
    {
        return distance / vehicleSpeed;
    }

    void command(string packageID, string urgency) override
    {
        if (urgency == "urgent")
        {
            cout << "TIMESHIP VALIDATING HISTORICAL RECORDS FOR: " << packageID << endl;
        }
        Vehicle::command(packageID, urgency);
    }
};

class RamzanHyperPod : public Vehicle
{
public:
    RamzanHyperPod(string id) : Vehicle(id)
    {
        vehicleSpeed = 120;
        vehicleCapacity = 1000;
        energyEfficiency = 90;
    }

    void calculateRoute() override
    {
        cout << "NAVIGATING UNDERGROUND HYPERLOOP NETWORK" << endl;
    }

    double estimateTime(double distance) override
    {
        return distance / vehicleSpeed;
    }
};

int main()
{
    cout << "NAME: MUZAMIL ALI" << endl;
    cout << "ROLL NO: 24K-1023" << endl;
    RamzanDrone drone("DRONE");
    RamzanTimeShip timeship("TIMESHIP");
    RamzanHyperPod pod("POD");

    drone.command("IFTAR_MEAL1", "urgent");
    drone.command("IFTAR_MEAL2", "urgent");

    timeship.command("HISTORICAL_ITEM", "urgent");

    pod.calculateRoute();
    cout << "ESTIMATED DELIVERY TIME: " << pod.estimateTime(360) << " HOURS" << endl;

    Vehicle *result = resolveConflict(&drone, &pod);
    cout << "CONFLICT RESOLUTION WINNER: " << result->getTotalDeliveries() << endl;

    cout << "TOTAL DELIVERIES: " << Vehicle::getTotalDeliveries() << endl;

    return 0;
}
