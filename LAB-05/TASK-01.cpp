#include <iostream>
using namespace std;
class Apartment{

const int id;
string address;
string *name;

public:
Apartment():id(-1){
    name = new string("");
    address = "";

}
Apartment(int id,string address,string ownerName):id(id),address(address){
    name = new string(ownerName);
}
void display(){

    cout<<"NAME: "<<*name<<endl;
    cout<<"ID: "<<id<<endl;
    cout<<"ADDRESS: "<<address<<endl;
}
Apartment(const Apartment&other):id(other.id){
    address = other.address;
    name = new string(*other.name);
}
~Apartment(){
    delete name;
}

};
int main() {
    Apartment A(120,"LAHORE","MUZAMIL");
    Apartment B(A);
    A.display();
    B.display();
    return 0;
}