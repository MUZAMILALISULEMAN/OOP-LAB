#include <iostream>
using namespace std;

class Vehicle {
private:
    string model;
    double rent;
    string licenseTypeRequired;

public:
    bool isAvailable;

    Vehicle() : isAvailable(true) {}
    Vehicle(string model, double rent, string licenseTypeRequired)
        : model(model), rent(rent), licenseTypeRequired(licenseTypeRequired), isAvailable(true) {}

    double getRent() { return rent; }
    string getModel() { return model; }
    string getLicenseTypeRequired() { return licenseTypeRequired; }

    void displayVehicle() {
        cout << "VEHICLE MODEL: " << model << endl;
        cout << "VEHICLE RENT PER DAY: " << rent << endl;
    }
};

class User {
private:
    int age;
    string licenseType;
    string contact;
    int userID;

public:
    User() {}
    User(int age, int userID, string contact, string licenseType)
        : age(age), userID(userID), contact(contact), licenseType(licenseType) {}

    bool rentVehicle(Vehicle *V) {
        return licenseType == V->getLicenseTypeRequired();
    }

    void setAge(int newAge) { age = newAge; }
    void setUserID(int newUserID) { userID = newUserID; }
    void setContact(string newContact) { contact = newContact; }
    void setLicenseType(string newLicenseType) { licenseType = newLicenseType; }
    int getID() { return userID; }
};

class RentalSystem {
private:
    User users[100];
    Vehicle **vehicleAvailable;
    int totalVehicle;
    int userCount;

public:
    RentalSystem() : totalVehicle(0), vehicleAvailable(nullptr), userCount(0) {}

    void ALLOCATE_VEHICLE(string model, double rent, string licenseTypeRequired) {
        Vehicle **newArray = new Vehicle *[totalVehicle + 1];
        for (int i = 0; i < totalVehicle; i++) {
            newArray[i] = vehicleAvailable[i];
        }
        newArray[totalVehicle] = new Vehicle(model, rent, licenseTypeRequired);

        if (vehicleAvailable) {
            delete[] vehicleAvailable;
        }
        vehicleAvailable = newArray;
        totalVehicle++;
    }

    void DEALLOCATE_ARRAY() {
        if (vehicleAvailable) {
            for (int i = 0; i < totalVehicle; i++) {
                delete vehicleAvailable[i];
            }
            delete[] vehicleAvailable;
            vehicleAvailable = nullptr;
        }
    }

    void rentVehicle(int userID, string vehicleModel, int Days) {
        for (int i = 0; i < totalVehicle; i++) {
            if (vehicleAvailable[i]->getModel() == vehicleModel && vehicleAvailable[i]->isAvailable) {
                for (int j = 0; j < userCount; j++) {
                    if (users[j].getID() == userID) {
                        if (users[j].rentVehicle(vehicleAvailable[i])) {
                            cout << "YOU HAVE SUCCESSFULLY RENTED THE " << vehicleModel << endl;
                            cout << "RENTED FOR DAYS: " << Days << endl;
                            cout << "TOTAL RENT: " << vehicleAvailable[i]->getRent() * Days << endl;
                            vehicleAvailable[i]->isAvailable = false;
                        } else {
                            cout << "SORRY, LICENSE TYPE FOR " << vehicleModel << " DOES NOT MATCH." << endl;
                        }
                        return;
                    }
                }
                cout << "SORRY, USER NOT FOUND." << endl;
                return;
            }
        }
        cout << "SORRY, VEHICLE NOT AVAILABLE." << endl;
    }

    void displayAvailableVehicles() {
        int k = 1;
        for (int i = 0; i < totalVehicle; i++) {
            if (vehicleAvailable[i]->isAvailable) {
                cout << k++ << ". ";
                vehicleAvailable[i]->displayVehicle();
            }
        }
    }

    void registerUser(int age, int userID, string contact, string licenseType) {
        users[userCount++] = User(age, userID, contact, licenseType);
    }

    void setAge(int userID, int newAge) {
        for (int i = 0; i < userCount; i++) {
            if (users[i].getID() == userID) {
                users[i].setAge(newAge);
                return;
            }
        }
        cout << "USER NOT FOUND." << endl;
    }

    void setContact(int userID, string newContact) {
        for (int i = 0; i < userCount; i++) {
            if (users[i].getID() == userID) {
                users[i].setContact(newContact);
                return;
            }
        }
        cout << "USER NOT FOUND." << endl;
    }

    void setLicenseType(int userID, string newLicenseType) {
        for (int i = 0; i < userCount; i++) {
            if (users[i].getID() == userID) {
                users[i].setLicenseType(newLicenseType);
                return;
            }
        }
        cout << "USER NOT FOUND." << endl;
    }

    ~RentalSystem() {
        DEALLOCATE_ARRAY();
    }
};

int main() {

    cout<<"NAME: MUZAMIL ALI"<<endl;
    cout<<"ROLL NO: 24K-1023"<<endl;

    RentalSystem GARAGESLOT;

    GARAGESLOT.registerUser(25, 0, "123-456-7890", "INTERMEDIATE");
    GARAGESLOT.registerUser(30, 1, "987-654-3210", "FULL");

    GARAGESLOT.ALLOCATE_VEHICLE("COROLLA", 1500, "LEARNER");
    GARAGESLOT.ALLOCATE_VEHICLE("CIVIC", 1800, "FULL");
    GARAGESLOT.ALLOCATE_VEHICLE("BUGGATI CHIRON", 2500, "INTERMEDIATE");
    GARAGESLOT.rentVehicle(1,"CIVIC",5);
    cout << "AVAILABLE VEHICLES:" << endl;
    GARAGESLOT.displayAvailableVehicles();

    // modifying the vehicle
    GARAGESLOT.setAge(0, 26);
    GARAGESLOT.setContact(0, "321-654-0987");
    GARAGESLOT.setLicenseType(0, "FULL");
    

    return 0;
}
