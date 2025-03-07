#include <iostream>
using namespace std;
class Employee{
protected:
string name;
float salary;
public:
Employee():salary(0),name(""){}
Employee(string name,float salary):name(name),salary(salary){}
void display(){
    cout<<"NAME: "<<name<<endl;
    cout<<"SALARY: "<<salary<<endl;
}
};

class Manager: protected Employee{
protected:
float bonus;
public:
Manager():Employee(),bonus(0){}
Manager(string name,float salary,float bonus):Employee(name,salary),bonus(bonus){}
void display(){
    Employee::display();
    cout<<"BONUS: "<<bonus;

}


};
int main() {
    Manager M1("MUZAMIL",1000.00,120);
    M1.display();
    
    return 0;
}