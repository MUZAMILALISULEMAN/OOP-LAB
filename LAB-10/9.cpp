#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream logFile("log.txt", ios::in);

    if (!logFile) {
        cerr << "ERROR: FAILED TO OPEN FILE" << endl;
        return 1;
    }


    char readBuffer[11];
    logFile.read(readBuffer, 10);
    readBuffer[10] = '\0';
    cout << "FIRST 10 CHARACTERS: " << readBuffer << endl;
    cout << "FILE POSITION AFTER READ: " << logFile.tellg() << " bytes" << endl;

    
    string lineContent;
    getline(logFile, lineContent);
    cout << "NEXT LINE CONTENT: " << lineContent << endl;
    cout << "FILE POSITION AFTER GETLINE: " << logFile.tellg() << " bytes" << endl;

    
    getline(logFile, lineContent);
    cout << "FOLLOWING LINE CONTENT: " << lineContent << endl;
    cout << "FINAL FILE POSITION: " << logFile.tellg() << " bytes" << endl;

    logFile.close();
    return 0;
}