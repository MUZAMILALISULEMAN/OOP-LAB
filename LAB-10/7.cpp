#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
using namespace std;

void WriteToFile() {
    ofstream myFile;
    myFile.open("sensor_log.txt", ios::out);
    
    if (!myFile) {
        cerr << "ERROR: FAILED TO OPEN FILE" << endl;
        return;
    }
    
    myFile << "Sensor 1: 25.5 Cargo" << endl;
    cout << "FILE POSITION AFTER SENSOR 1 WRITE: " << myFile.tellp() << " bytes" << endl;

    myFile << endl;
    myFile << "Sensor 2: 98.1 %RH" << endl;
    cout << "FILE POSITION AFTER SENSOR 2 WRITE: " << myFile.tellp() << " bytes" << endl;

    myFile.close();
    cout << "SENSOR DATA SUCCESSFULLY WRITTEN TO FILE" << endl;
}

int main() {
    WriteToFile();
    return 0;
}