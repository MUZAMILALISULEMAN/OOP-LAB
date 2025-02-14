#include<iostream>
using namespace std;
class Car{
	
	string brand;
	string model;
	double price;
	bool availabilityStatus;
	
	public:
		Car(){
			
			brand = "Unknown";
			model = "Generic";
			price = 0.0;
			availabilityStatus =true;
			
		}
		
		void setBrand(string b){
			brand = b;
		}
		void setModel(string m){
			model = m;
		}
		void setPrice(double p){
			price  = p;
		}
		void setAvailability (bool a){
			availabilityStatus = a;
		}	
		bool checkAvailability(){
			
		return availabilityStatus;
		
			
		}
		void rentCar(string name){
			if(checkAvailability() == true){
				
				cout<<"CAR IS RENTED TO THE "<<name<<endl;
				
			}else{
				
			cout<<"CAR IS NOT AVAILABLE"<<endl;			}
		}
		
		Car(const Car &c){
			
	brand = c.brand;
	 model = c.model;
	 price = c.price;
 availabilityStatus = c.availabilityStatus;
			
		}
		~Car(){
			
			
			cout<<"OBJECT DELETED!";
		}

	

};
int main(){
	
Car c("BUGATIC","CHIRON",1000,1);
	c.rentCar("MUZAMIL",10);
	c.setAvailability(false);
	c.rentCar("MUZAMIL",15);


	
	
	
	
	
	return 0;
}