#include <iostream>
using namespace std;

class Device {
protected:
    int deviceID;
    bool status;
public:
    Device(): deviceID(0), status(false) {}
    Device(int deviceID, bool status): deviceID(deviceID), status(status) {}

    void displayDetails() {
        cout << "DEVICE ID: " << deviceID << endl;
        cout << "STATUS: ";
        if (status == true) {
            cout << "ON" << endl;
        } 
        else {
            cout << "OFF" << endl;
        }
    }
};

class SmartPhone : protected Device {
protected:
    float screenSize;
public:
    SmartPhone(): Device(), screenSize(0.0) {}
    SmartPhone(int deviceID, bool status, float screenSize): Device(deviceID, status), screenSize(screenSize) {}

    void displayDetails() {
        Device::displayDetails();
        cout << "SCREEN SIZE: " << screenSize << " INCHES" << endl;
    }
};

class SmartWatch : protected SmartPhone {
protected:
    bool heartRateMonitor;
public:
    SmartWatch(): SmartPhone(), heartRateMonitor(false) {}
    SmartWatch(int deviceID, bool status, float screenSize, bool heartRateMonitor)
        : SmartPhone(deviceID, status, screenSize), heartRateMonitor(heartRateMonitor) {}

    void displayDetails() {
        SmartPhone::displayDetails();
        cout << "HEART RATE MONITOR: ";
        if (heartRateMonitor == true) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
};

class SmartWearable : protected SmartWatch {
protected:
    int stepCounter;
public:
    SmartWearable(): SmartWatch(), stepCounter(0) {}
    SmartWearable(int deviceID, bool status, float screenSize, bool heartRateMonitor, int stepCounter)
        : SmartWatch(deviceID, status, screenSize, heartRateMonitor), stepCounter(stepCounter) {}

    void displayDetails() {
        SmartWatch::displayDetails();
        cout << "STEP COUNTER: " << stepCounter << " STEPS" << endl;
    }
};

int main() {
    SmartWearable s1(100, true, 6.5, false, 1200);

    s1.displayDetails();

    return 0;
}
