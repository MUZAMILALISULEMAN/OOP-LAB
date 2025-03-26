#include<iostream>
using namespace std;
class Ticket{

protected:
int ticketID;
string passengerName;
double price;
string date;
string destination;
public:
Ticket():price(0.0){}
void reserve(int ticketID ,string passengerName,string date,string destination,double price){
this->price = price;
this->ticketID = ticketID;
this->passengerName = passengerName;
this->date = date;
this->destination = destination;
}



};
int main(){




    return 0;
}