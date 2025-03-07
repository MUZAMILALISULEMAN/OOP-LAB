#include <iostream>
using namespace std;
class Vehicle{
    protected:
    string brand;
    int speed;
    public:
    Vehicle():brand(""),speed(-1){}
    Vehicle(string brand,int speed):brand(brand),speed(speed){}
    void display(){
        cout<<"BRAND: "<<brand<<endl;
        cout<<"SPEED: "<<speed<<endl;
    }
    };
    
    class Car: protected Vehicle{
    protected:
    int seats;
    public:
    Car():Vehicle(),seats(-1){}
    Car(string brand,int speed,int seats):Vehicle(brand,speed),seats(seats){}
    void display(){
        Vehicle::display();
        cout<<"SEATS: "<<seats<<endl;
    
    }
};

class ElectricCar: protected Car{
    protected:
    int batteryLife;
    public:
    ElectricCar():Car(),batteryLife(-1){}
    ElectricCar(string brand,int speed,int seats,int batteryLife):Car(brand,speed,seats),batteryLife(batteryLife){}
    void display(){
        Car::display();
        cout<<"BATTERY LIFE: "<<batteryLife<<endl;
    
    }
};

    
int main() {
    
    ElectricCar e1("TOYOTA",120,4,120);
    e1.display();



    return 0;
}