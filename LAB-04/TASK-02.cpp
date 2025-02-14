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
		Car(string m,string b,double p,bool a){
			brand = b;
			model = m;
			price = p;
			availabilityStatus =a;
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
		double applyDiscount(int days){
			if(days > 5){
				price-=(0.05 * price);
				return (0.05 * price);
				
			}else if(days > 10){
				price -= (0.10 * price);
				return (0.10 * price);
			}
		}
		void rentCar(string name, int DAYS){
			if(checkAvailability() == true){
				
				cout<<"CAR IS RENTED TO THE "<<name<<endl;
				cout<<"DISCOUNT IS "<<applyDiscount(DAYS);
				price-=applyDiscount(DAYS);
				
			}else{
				
			cout<<"CAR IS NOT AVAILABLE"<<endl;	}
		}

	

};
int main(){
	
	Car c("BUGATIC","CHIRON",1000,1);
	c.rentCar("MUZAMIL",10);
	c.setAvailability(false);
	c.rentCar("MUZAMIL",5);
	c.applyDiscount(10);
	
	
	
	return 0;
}