#include <iostream>
using namespace std;
class Doctor{

public:
string name;
string specialization;
string experience;
Doctor(string name,string specialization,string experience):experience(experience),specialization(specialization),name(name){}
Doctor():name(""),specialization(""),experience(""){}

};

class Hospital{

private:
Doctor *doctors[50];
int count;
string name;
public:
Hospital():name(""),count(0){}
Hospital(string name):name(name),count(0){}
void display(){
    cout<<"HOSPITAL NAME: "<<name<<endl;
    cout<<"DOCTORS ===>"<<endl;
    for (int i = 0; i < count; i++)
    {
        cout<<"DOCTOR: "<<doctors[i]->name<<endl;
    }
}
void assignDoctor(Doctor *doctor){
    doctors[count++] = doctor;
}
};
int main() {
    Doctor *Doctor1 = new Doctor("MUZAMIL","DERMATOLOGIST","MBBS");
    Doctor *Doctor2 = new Doctor("ALI","DERMATOLOGIST","MBBS");
    Hospital hospital;
    hospital.assignDoctor(Doctor1);
    hospital.assignDoctor(Doctor2);
    hospital.display();
    delete Doctor1;
    delete Doctor2;

    return 0;
}