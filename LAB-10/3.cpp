#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    ifstream in("vehicles.txt");
    if (!in)
    {
        return 1;
    }
    string data;
    while (getline(in, data))
    {
        if (data.empty())
        {
            continue;
        }
        int l = data.length();
        for (int i = 0; i < l; i++)
        {
            if (data[i] == ',' || data[i] == '.')
            {
                data[i] = ' ';
            }
        }

        istringstream s(data);
        string type,
            name,
            id,
            year;
        s>> type >> name >> id >> year;
        int Year = stoi(year);
        if (stoi(year))
        {
            cout << Year << endl;
        }
        else
        {
            cout << "ERROR HERE...";
        }
    }
    in.close();
    return 0;
}