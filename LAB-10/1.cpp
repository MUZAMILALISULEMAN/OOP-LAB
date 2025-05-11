#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ifstream file;
    file.open("vehicles.txt",ios::in);
    if(!file) {
        cerr<<"FILE NOT OPEN!!";
        exit(1);
    }
    string data;
    while(getline(file,data)) {
        if(data.empty()) {
            continue;
        }
        cout<<data<<endl;
    }
    file.close();
    return 0;
}