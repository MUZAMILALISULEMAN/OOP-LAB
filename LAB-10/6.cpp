#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

class InventoryItem {
public:
    static int itemId;
    char itemName[20];
    
    InventoryItem(string name) {
        this->itemId++;
        strncpy(itemName, name.c_str(), 19);
        itemName[19] = '\0';  
    }
};

int InventoryItem::itemId = 0;

void writeToFile(InventoryItem &item) {
    ofstream file;
    file.open("in.dat", ios::binary);
    if(!file) {
        cerr << "ERROR: FILE OPEN FAILED" << endl;
    }
    file.write(reinterpret_cast<char*>(&item.itemId), sizeof(item.itemId));
    file.write(item.itemName, 20);
    file.close();
}

void readFromFile() {
    ifstream file;
    file.open("inventory.dat", ios::binary);
    if(!file) {
        cerr << "ERROR: FILE OPEN FAILED" << endl;
        return;
    }
    int id;
    char name[20];
    file.read(reinterpret_cast<char*>(&id), sizeof(id));
    file.read(name, 20);

    cout << "READ ITEM ID: " << id << endl;
    cout << "READ ITEM NAME: " << name << endl;
    file.close();
}

int main() {
    InventoryItem item("TOOLS");
    writeToFile(item);

    readFromFile();
    cout << "CURRENT ITEM ID: " << item.itemId << endl;
    cout << "CURRENT ITEM NAME: " << item.itemName << endl;

    return 0;
}