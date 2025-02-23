#include <iostream>
using namespace std;

class Student {
private:
    const int studentID;
    string name;
    bool isActive;
    double balance;
    string stop;

public:
    static int totalStudents;

    Student(int id, string n, string s) : studentID(id), name(n), stop(s), isActive(false), balance(0.0) {
        totalStudents++;
    }
    Student() : studentID(-1) ,balance(0.0),isActive(false){}

    void payFee(double amount) {
        balance += amount;
        isActive = true;
        cout << "PAYMENT SUCCESSFUL=> CARD ACTIVATED." << endl;
    }

    void tapCard() const {
        cout << (isActive ? "ATTENDANCE RECORDED FOR " + name : "CARD INACTIVE. PLEASE PAY THE SEMESTER FEE.") << endl;
    }

    int getID() const { 
        return studentID; 
    }
    string getName() const { 
        return name; 
    }
    bool getIsActive() const { 
        return isActive; 
    }
    double getBalance() const { 
        return balance; 
    }
    string getStop() const { 
        return stop; 
    }

    void setName(string n) { 
        name = n; 
    }
    void setStop(string s) { 
        stop = s;
     }
};

int Student::totalStudents = 0;

class BusRoute {
private:
    string stops[10];
    int totalStops;

public:
    string routeName;
    BusRoute() : totalStops(0) {}

    void addRoute(string name) {
        routeName = name;
        totalStops = 0;
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
};

class TransportSystem {
private:
    Student students[100];
    BusRoute routes[10];
    int studentCount;
    int routeCount;

public:
    TransportSystem() : studentCount(0), routeCount(0) {}

    void registerStudent(int id, string name, string stop) {
        if (studentCount < 100) {
            new (&students[studentCount]) Student(id, name, stop);
            studentCount++;
            cout << "STUDENT REGISTERED SUCCESSFULLY." << endl;
        } else {
            cout << "STUDENT REGISTRATION LIMIT REACHED." << endl;
        }
    }

    void addRoute(string name) {
        if (routeCount < 10) {
            routes[routeCount].addRoute(name);
            routeCount++;
        } else {
            cout << "MAXIMUM NUMBER OF ROUTES REACHED." << endl;
        }
    }

    void addStopToRoute(string routeName, string stop) {
        for (int i = 0; i < routeCount; i++) {
            if (routes[i].routeName == routeName) {
                routes[i].addStop(stop);
                return;
            }
        }
        cout << "ROUTE NOT FOUND." << endl;
    }

    void processPayment(int id, double amount) {
        for (int i = 0; i < studentCount; i++) {
            if (students[i].getID() == id) {
                students[i].payFee(amount);
                return;
            }
        }
        cout << "STUDENT NOT FOUND." << endl;
    }

    void tapCard(int id) const {
        for (int i = 0; i < studentCount; i++) {
            if (students[i].getID() == id) {
                students[i].tapCard();
                return;
            }
        }
        cout << "STUDENT NOT FOUND." << endl;
    }
    static int getTotalStudents(){
        return Student::totalStudents;
    }
    ~TransportSystem(){
        cout<<"SYSTEM IS TERMINATED";

    }
};

int main() {
    cout<<"NAME: MUZAMIL ALI"<<endl;
    cout<<"ROLL NO: 24K-1023"<<endl;
    TransportSystem system;

    system.registerStudent(1, "MUSTUFA", "QUIDABAD");
    system.registerStudent(2, "MUZAMIL", "GULSHAN-E-HADEED");

    system.addRoute("ROUTE 1");
    system.addStopToRoute("ROUTE 1", "QUIDABAD");
    system.addRoute("ROUTE 2");
    system.addStopToRoute("ROUTE 2", "GULSHAN-E-HADEED");
    system.addStopToRoute("ROUTE 2", "GULSHAN-E-JOHAR");

    system.processPayment(1, 5000);
    system.tapCard(1);
    system.tapCard(2);

    cout << "TOTAL STUDENTS REGISTERED: " << TransportSystem::getTotalStudents() << endl;
    return 0;
}
