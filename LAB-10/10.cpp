#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream recordFile("record.txt", ios::in);

    if (!recordFile) {
        cerr << "ERROR: FAILED TO OPEN RECORD FILE" << endl;
        return 1;
    }

    
    string firstLine;
    getline(recordFile, firstLine);
    cout << "CURRENT FILE POSITION: " << recordFile.tellg() << " bytes" << endl;
    cout << "FIRST LINE CONTENT: " << firstLine << endl;

    
    recordFile.seekg(ios::beg);
    recordFile.seekg(22, ios::beg);

    
    string thirdRecord;
    getline(recordFile, thirdRecord);
    cout << "THIRD RECORD CONTENT: " << thirdRecord << endl;

    recordFile.close();
    return 0;
}