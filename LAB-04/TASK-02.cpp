#include <iostream>
using namespace std;
class Car
{

	string brand;
	string model;
	double price;
	bool availabilityStatus;

public:
	Car()
	{

		brand = "Unknown";
		model = "Generic";
		price = 0.0;
		availabilityStatus = true;
	}
	Car(string m, string b, double p, bool a)
	{
		brand = b;
		model = m;
		price = p;
		availabilityStatus = a;
	}

	void setBrand(string b)
	{
		brand = b;
	}
	void setModel(string m)
	{
		model = m;
	}
	void setPrice(double p)
	{
		price = p;
	}
	void setAvailability(bool a)
	{
		availabilityStatus = a;
	}
	bool checkAvailability()
	{

		return availabilityStatus;
	}
	void applyDiscount(int days)
	{

		if (days > 10)
		{
			price -= (0.10 * price);
		}
		else if (days > 5)
		{
			price -= (0.05 * price);
		}
	}
	void rentCar(int DAYS)
	{
		if (checkAvailability() == true)
		{

			cout << "CAR IS RENTED" << endl;
			availabilityStatus = false;
			applyDiscount(DAYS);
		}
		else
		{

			cout << "CAR IS NOT AVAILABLE" << endl;
		}
	}
};
int main()
{

	Car Civic("CIVIC", "HONDA", 15000, true);
	Civic.rentCar(12);
	cout << endl
		 << Civic.checkAvailability();

	return 0;
}