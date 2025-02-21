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
		void rentCar(){
			if(checkAvailability() == true){
				
				cout<<"CAR IS RENTED"<<endl;
				availabilityStatus = false;
			}else{
				
			cout<<"CAR IS NOT AVAILABLE"<<endl;
			
			}
		}
		void display(){
		
			cout<<"BRAND:"<<brand<<endl;
			cout<<"MODEL: "<<model<<endl;
			cout<<"PRICE: "<<price<<endl;
			cout<<"AVAILABLE: "<<availabilityStatus<<endl;
		}

	

};
int main(){
	
	Car BMW;
	BMW.setBrand("BMW");
	BMW.setModel("56K-LK");
	BMW.setPrice(56000);
	BMW.rentCar();
	cout<<endl<<BMW.checkAvailability();
	
	
	return 0;
}