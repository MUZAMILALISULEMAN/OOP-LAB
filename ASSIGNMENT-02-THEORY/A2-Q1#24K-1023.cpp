#include <iostream>
using namespace std;

class Passenger {
protected:
    int ID;
    string name;
    bool isActive;
    double balance;
    double feeToPay;
    string stop;
public:
    static int totalPassengers;

    Passenger(int id, string n, string s, double fee)
        : ID(id), name(n), stop(s), isActive(false), balance(0.0), feeToPay(fee) {
        totalPassengers++;
    }

    Passenger() : ID(-1), balance(0.0), isActive(false), feeToPay(0.0) {}

    virtual void display() {
        cout << "ID: " << ID << endl;
        cout << "NAME: " << name << endl;
        cout << "STOP: " << stop << endl;
    }

    virtual void payFee(double amount) {
        balance += amount;
        if (balance >= feeToPay) {
            isActive = true;
            cout << "PAYMENT SUCCESSFUL => CARD ACTIVATED." << endl;
        } else {
            cout << "PARTIAL PAYMENT RECEIVED. PAY REMAINING: "
                 << (feeToPay - balance) << " TO ACTIVATE CARD." << endl;
        }
    }

    void tapCard() const {
        cout << (isActive ? "ATTENDANCE RECORDED FOR " + name
                          : "CARD INACTIVE. PLEASE PAY THE FEE.") << endl;
    }

    int getID() const { return ID; }
    string getName() const { return name; }
    bool getIsActive() const { return isActive; }
    double getBalance() const { return balance; }
    double getFeeToPay() const { return feeToPay; }
    string getStop() const { return stop; }

    void setName(string n) { name = n; }
    void setStop(string s) { stop = s; }
    void setFeeToPay(double fee) { feeToPay = fee; }
};

int Passenger::totalPassengers = 0;

class Student : public Passenger {
    string department;
public:
    Student(int id, string n, string s, double fee, string department)
        : Passenger(id, n, s, fee), department(department) {}

    void display() override {
        Passenger::display();
        cout << "DEPARTMENT: " << department << endl;
    }
};

class Teacher : public Passenger {
public:
    int monthsPaid;
    string designation;

    Teacher(int id, string n, string s, double fee, string designation)
        : monthsPaid(0), Passenger(id, n, s, fee), designation(designation) {}

    void display() override {
        Passenger::display();
        cout << "DESIGNATION: " << designation << endl;
    }

    void payFee(double amount) override {
        balance += amount;
        monthsPaid++;

        cout << "MONTHLY PAYMENT RECEIVED: " << amount << endl;
        cout << "TOTAL MONTHS PAID: " << monthsPaid << endl;

        if (balance >= feeToPay) {
            isActive = true;
            cout << "FULL FEE PAID => CARD ACTIVATED." << endl;
        } else {
            cout << "REMAINING FEE: " << (feeToPay - balance) << endl;
        }
    }
};

class Staff : public Passenger {
private:
    string role;
    string shiftTiming;
    string assignedRoute;
public:
    Staff(int id, string n, string s, double fee, string r, string shift, string route)
        : Passenger(id, n, s, fee), role(r), shiftTiming(shift), assignedRoute(route) {}

    void display() override {
        Passenger::display();
        cout << "ROLE: " << role << endl;
        cout << "TIMINGS: " << shiftTiming << endl;
        cout << "ASSIGNED ROUTE: " << assignedRoute << endl;
    }
};

class BusRoute {
private:
    string stops[10];
    int totalStops;

public:
    string routeName;
    BusRoute() : totalStops(0) {}

    void addRoute(string name) {
        routeName = name;
        cout << "ROUTE ADDED SUCCESSFULLY." << endl;
    }

    void addStop(string stop) {
        if (totalStops < 10) {
            stops[totalStops++] = stop;
            cout << "STOP " << stop << " ADDED TO ROUTE." << endl;
        } else {
            cout << "MAXIMUM NUMBER OF STOPS REACHED." << endl;
        }
    }

    bool isValidStop(string stop) const {
        for (int i = 0; i < totalStops; i++) {
            if (stops[i] == stop) return true;
        }
        return false;
    }

    bool operator==(const BusRoute& other) const {
        if (routeName != other.routeName || totalStops != other.totalStops)
            return false;
        
        for (int i = 0; i < totalStops; i++) {
            if (stops[i] != other.stops[i]) return false;
        }
        return true;
    }
};

class TransportSystem {
private:
    string name;
    Passenger* students[100]; 
    Staff* StaffMembers[100];
    Teacher* Teachers[100];
    BusRoute routes[10];
    int studentCount;
    int teacherCount;
    int staffCount;
    int routeCount;

public:
    TransportSystem() : studentCount(0), routeCount(0), teacherCount(0), staffCount(0) {}

    void Register(Teacher *t) {
        if (teacherCount < 100) {
            Teachers[teacherCount++] = t;
            cout << "TEACHER REGISTERED SUCCESSFULLY." << endl;
        } else {
            cout << "TEACHER REGISTRATION LIMIT REACHED." << endl;
        }
    }
    void Register(Student *s) {
        if (studentCount < 100) {
            students[studentCount++] = s;
            cout << "STUDENT REGISTERED SUCCESSFULLY." << endl;
        } else {
            cout << "STUDENT REGISTRATION LIMIT REACHED." << endl;
        }
    }
    void Register(Staff *sf) {
        if (staffCount < 100) {
            StaffMembers[staffCount++] = sf;
            cout << "STAFF REGISTERED SUCCESSFULLY." << endl;
        } else {
            cout << "STAFF REGISTRATION LIMIT REACHED." << endl;
        }
    }

    void tapCard(int id) const {
        for (int i = 0; i < studentCount; i++) {
            if (students[i]->getID() == id) {
                students[i]->tapCard();
                return;
            }
        }
        for (int i = 0; i < teacherCount; i++) {
            if (Teachers[i]->getID() == id) {
                Teachers[i]->tapCard();
                return;
            }
        }
        for (int i = 0; i < staffCount; i++) { 
            if (StaffMembers[i]->getID() == id) {
                StaffMembers[i]->tapCard();
                return;
            }
        }

        cout << "PASSENGER NOT FOUND." << endl;
    }
};

int main() {
    cout << "NAME: MUZAMIL ALI" << endl;
    cout << "ROLL NO: 24K-1023" << endl;

    TransportSystem system;

    Student* student1 = new Student(1, "MUSTUFA", "QUIDABAD", 5000, "Computer Science");
    system.Register(student1);
    
    Teacher* teacher1 = new Teacher(2, "MUZAMIL", "GULSHAN-E-HADEED", 5000, "Professor");
    system.Register(teacher1);

    BusRoute route1, route2;
    route1.addRoute("ROUTE 1");
    route1.addStop("QUIDABAD");

    route2.addRoute("ROUTE 1");
    route2.addStop("QUIDABAD");

    if (route1 == route2) cout << "ROUTES ARE SAME." << endl;

    system.tapCard(1);
    system.tapCard(2);

    return 0;
}
