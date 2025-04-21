#include<iostream>
using namespace std;
class patient{

protected:
string name;
int id;
public:
virtual void displayTreatment() = 0;
virtual void calculateCost() = 0;
};

class inPatient: public patient{
private:
public:
void displayTreatment(){
    cout<<"Patient Name: " << name << endl;
    cout << "Patient ID: " << id << endl;
    cout << "In Patient Treatment" << endl;
}
void calculateCost(){
    cout << "In Patient Calculation" << endl;
}
};
class outPatient: public patient{
private:
public:
void displayTreatment(){
    cout << "Out Patient Treatment" << endl;
    cout<<"Patient Name: " << name << endl;
    cout << "Patient ID: " << id << endl;
}
void calculateCost(){
    cout << "Out Patient Calculation" << endl;
}
};

int main(){
patient *p;
inPatient ip;
outPatient op;
p = &ip;
p->displayTreatment();
p->calculateCost();
p=&op;
p->displayTreatment();
p->calculateCost();
    return 0;
}