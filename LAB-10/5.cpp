#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ifstream inputFile("vehicles.txt");

    if (!inputFile) {
        cerr << "ERROR: COULD NOT OPEN FILE" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        if (line.empty() || line[0] == '#') {
            continue;
        }

        istringstream lineStream(line);
        string vehicleType, vehicleData;

        getline(lineStream, vehicleType, ',');
        getline(lineStream, vehicleData);

        if (vehicleType == "AutonomousCar") {
            string version = vehicleData.substr(
                vehicleData.find(":") + 1, 
                vehicleData.find(",") - vehicleData.find(":") - 1
            );
            cout << "AUTO CAR VERSION:" << version << endl;
        }
        else if (vehicleType == "Electric vehicle") {
            string battery = vehicleData.substr(
                vehicleData.find(":") + 1,
                vehicleData.find(",") - vehicleData.find(":") - 1
            );
            cout << "ELECTRIC CAR BATTERY:" << battery << endl;
        }
        else if (vehicleType == "HybridTruck") {
            size_t cargoStart = vehicleData.find(":");
            size_t pipePos = vehicleData.find("|");
            string cargoStr = vehicleData.substr(
                cargoStart + 1, 
                pipePos - cargoStart - 1
            );
        
            size_t batteryStart = vehicleData.find(":", pipePos);
            size_t dataEnd = vehicleData.find(",", batteryStart);
            string batteryStr = vehicleData.substr(
                batteryStart + 1, 
                dataEnd - (batteryStart + 1)
            );
        
            int cargoCapacity = stoi(cargoStr);
            int batteryCapacity = stoi(batteryStr);
            
            cout << "CARGO:" << cargoCapacity << "|";
            cout << " BATTERY:" << batteryCapacity << endl;
        }
        else {
            cout << "ERROR: UNKNOWN VEHICLE TYPE" << endl;
        }
    }

    inputFile.close();
    return 0;
}