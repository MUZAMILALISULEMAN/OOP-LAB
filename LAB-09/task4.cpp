#include <iostream>
using namespace std;

class WeatherSensor {
public:
    virtual void readData() = 0;
    virtual void displayReport() = 0;
    virtual ~WeatherSensor() {}
};

class Thermometer : public WeatherSensor {
private:
    float temperature;
public:
    Thermometer() : temperature(0.0) {}
    void readData()  {
        temperature = 25.5;
    }
    void displayReport()  {
        cout << "THERMOMETER REPORT:" << endl;
        cout << "TEMPERATURE: " << temperature << " C" << endl;
    }
};

class Barometer : public WeatherSensor {
private:
    float pressure;
public:
    Barometer() : pressure(0.0) {}
    void readData() override {
        pressure = 1013.25;
    }
    void displayReport()  {
        cout << "BAROMETER REPORT:" << endl;
        cout << "PRESSURE: " << pressure << " hPa" << endl;
    }
};

int main() {
    Thermometer thermometer;
    Barometer barometer;

    WeatherSensor* sensors[2] = { &thermometer, &barometer };

    for (int i = 0; i < 2; i++) {
        sensors[i]->readData();
        sensors[i]->displayReport();
    }

    return 0;
}
