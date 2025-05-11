#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ifstream in("vehicles.txt");
    if (!in) {
        cerr << "ERROR: FILE NOT OPENED" << endl;
        return 1;
    }

    string data;
    while (getline(in, data)) {
        if (data.empty()) {
            continue;
        }
        istringstream ss(data);
        string type, substring;

        getline(ss, type, ',');
        getline(ss, substring);

        size_t colon = substring.find(":");
        size_t comma = substring.find(",");
        string str = substring.substr(colon + 1, comma - colon - 1);
        
        if (type == "AutonomousCar") {
            cout << "AUTO CAR VERSION:" << str << endl;
        }
        else if (type == "ElectricVehicle") {  
            cout << "ELECTRIC CAR BATTERY:" << str << endl;
        }
    }
    in.close();
    return 0;
}