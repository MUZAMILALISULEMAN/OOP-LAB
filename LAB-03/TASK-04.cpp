#include<iostream>
using namespace std;

class CAR {
	private:
		string brand;
		string model;
		float fuelCapacity;  //fuel is in Liters
		float currentFuelLevel; 
		float fuelEfficiency;// is in kilometers/liters
		float minFuel;
	public:
		
		
		CAR(){
			currentFuelLevel = 0;
			fuelCapacity = 0;
			fuelEfficiency = -1;
			minFuel = 0;
			
		}
		CAR(string Model, string Brand, float fuelCAPACITY,float currentFuelLEVEL,float fuelEFFICIENCY,float MinFuel){
			model = Model;
			brand = Brand;
			fuelCapacity = fuelCAPACITY;
			currentFuelLevel =currentFuelLEVEL;
			 fuelEfficiency = fuelEFFICIENCY;
			 minFuel = MinFuel;
			 
		}
		

		void drive(float distance) { // distance is in kilometers
			float fuelUsed = distance/fuelEfficiency;
			if(currentFuelLevel - fuelUsed > 0) {

				currentFuelLevel -= fuelUsed;
				notify();
			}

		}
		void refuel(float liters) {
			if(currentFuelLevel+liters <= fuelCapacity && liters > 0) {

				currentFuelLevel+=liters;
				
			} else {
				currentFuelLevel = fuelCapacity;
			}
			cout<<endl<<"CAR IS FUELD WITH "<<liters<<" LITERS"<<endl;
			fuelStatus();
		}

		void notify() 

		{
			if(currentFuelLevel < minFuel ){
				cout<<endl<<"YOU ARE RUNNING OUT OF FUEL";
				fuelStatus();
			}
			
			
			
		}
		
		void fuelStatus(){
			cout<<endl<<currentFuelLevel<<" LITERS LEFTOVER IN THE CAR";
		}



};



int main() {

	CAR car("BUGGATI","CHIRON",1000,60,40,100);
	car.drive(800);
	car.refuel(40);
	car.fuelStatus();
	car.notify();
	



	return 0;
}
