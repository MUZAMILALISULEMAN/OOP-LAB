#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MenuItem {
protected:
    string dishName;
    double price;

public:
    MenuItem(string name, double cost) : dishName(name), price(cost) {}
    virtual ~MenuItem() {}
    virtual void showDetails()  = 0;
    virtual void prepare()  = 0;
};


class Appetizer : public MenuItem {
public:
    Appetizer(string name, double cost) : MenuItem(name, cost) {}

    void showDetails()  {
        cout << "APPETIZER: " << dishName << ", PRICE: $" << price << endl;
    }

    void prepare()  {
        cout << "PREPARING APPETIZER: " << dishName << " WITH SPECIAL GARNISHING." << endl;
    }
};

class MainCourse : public MenuItem {
public:
    MainCourse(string name, double cost) : MenuItem(name, cost) {}

    void showDetails()  {
        cout << "MAIN COURSE: " << dishName << ", PRICE: $" << price << endl;
    }

    void prepare()   {
        cout << "PREPARING MAIN COURSE: " << dishName << " WITH PROPER SEASONING AND COOKING." << endl;
    }
};

int main() {

    Appetizer app("Bruschetta", 8.99);
    MainCourse main("Grilled Salmon", 22.50);

    MenuItem * item = &app;
    item->showDetails();
    item->prepare();
    item = &main;
    item->showDetails();
    item->prepare();

    return 0;
}
