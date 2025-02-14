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
		void display(){
		
			cout<<"BRAND:"<<brand<<endl;
			cout<<"MODEL: "<<model<<endl;
			cout<<"PRICE: "<<price<<endl;
			cout<<"AVAILABLE: "<<availabilityStatus<<endl;
		}

	

};
int main(){
	
	Car c;
	c.rentCar("MUZAMIL");
	c.setAvailability(false);
	c.rentCar("MUZAMIL");
	c.display();
	
	
	return 0;
}