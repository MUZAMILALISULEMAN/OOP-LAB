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
};
int main()
{

	Car c1("BMW", "KL-03", 19000, true);
	Car c2 = c1;

	return 0;
}