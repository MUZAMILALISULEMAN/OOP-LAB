#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
    fstream myFile;
    
    
    myFile.open("config.txt", ios::in | ios::out);
    
    if (!myFile) {
        cerr << "ERROR: FAILED TO OPEN CONFIG FILE" << endl;
        return 1;
    }
    
    
    myFile.seekp(5);
    myFile <<"XXXXXX";
    
    cout << "DATA SUCCESSFULLY WRITTEN TO CONFIG FILE" << endl;
    
    myFile.close();
    return 0;
}