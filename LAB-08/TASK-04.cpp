#include <iostream>
#include <string>

using namespace std;

class Car;

class InventoryManager {
public:
    void updatePrice(Car& car, double newPrice);
    void displayCarDetails(const Car& car) const;
};

class Car {
private:
    string model;
    double price;

public:
    Car(string model, double price) : model(model), price(price) {}

    friend class InventoryManager;
    friend void comparePrice(const Car& car1, const Car& car2);
};

void InventoryManager::updatePrice(Car& car, double newPrice) {
    car.price = newPrice;
    cout << "UPDATED PRICE OF " << car.model << " TO $" << newPrice << endl;
}

void InventoryManager::displayCarDetails(const Car& car) const {
    cout << "MODEL: " << car.model << ", PRICE: $" << car.price << endl;
}

void comparePrice(const Car& car1, const Car& car2) {
    if (car1.price > car2.price) {
        cout << car1.model << " IS MORE EXPENSIVE THAN " << car2.model << endl;
    } else if (car1.price < car2.price) {
        cout << car2.model << " IS MORE EXPENSIVE THAN " << car1.model << endl;
    } else {
        cout << car1.model << " AND " << car2.model << " ARE PRICED EQUALLY" << endl;
    }
    
}

int main() {
    Car car1("CORROLA", 20000);
    Car car2("CIVIC", 22000);

    InventoryManager manager;

    cout << "INITIAL CAR DETAILS:" << endl;
    manager.displayCarDetails(car1);
    manager.displayCarDetails(car2);

    manager.updatePrice(car1, 21000);

    cout <<endl<< "AFTER UPDATING PRICE:" << endl;
    manager.displayCarDetails(car1);
    cout <<endl<< "COMPARING PRICES:" << endl;
    comparePrice(car1, car2);

    return 0;
}