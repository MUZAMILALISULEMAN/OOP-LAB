#include <iostream>
using namespace std;
class Car
{

	string brand;
	string model;
	double price;
	bool availabilityStatus;
	double totalRevenue;

public:
	Car()
	{
		totalRevenue = 0.0;
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
		totalRevenue = 0;
	}
	Car(const Car &carGiven)
	{

		this->brand = carGiven.brand;
		this->model = carGiven.model;
		this->price = carGiven.price;
		this->availabilityStatus = carGiven.availabilityStatus;
	}
	~Car()
	{
		cout << "CAR IS REMOVED FROM THE MEMORY" << endl;
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
	};
	void totalRevenueCalc(int DAYS)
	{

		applyDiscount(DAYS);
		this->totalRevenue = DAYS * price;
	}
	void displayRevenue()
	{
		cout << "TOTAL REVENUE: " << totalRevenue << endl;
	}
};

int main()
{

	Car Civic("CIVIC", "HONDA", 15000, true);
	Civic.totalRevenueCalc(13);
	Civic.displayRevenue();

	return 0;
}