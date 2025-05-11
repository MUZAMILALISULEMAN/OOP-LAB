#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    ifstream file("vehicles.txt");
    if (!file)
    {
        cerr << "FILE ERROR!!\n";
        exit(1);
    }
    string data;
    while (getline(file, data))
    {
        if (data.empty())
        {
            continue;
        }
        int l =  data.length();
        for (int i = 0; i <l; i++)
        {
            if(data[i] == ',' || data[i]=='.'){
                data[i] = ' ';
            }
        }
        
        
        
        istringstream s(data);
        string type;
        string model;
        string name;
        int year;
        s >> type >> model >> name >> year;
        
        cout << "VEHICLE RECORD - TYPE: " << type 
             << " | NAME: " << name 
             << " | MODEL: " << model 
             << " | YEAR: " << year << endl;
    }
    return 0;
}