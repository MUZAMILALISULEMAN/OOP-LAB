#include <iostream>
#include <stdexcept>

using namespace std;

class InvalidTemperatureException : public exception
{
};

template <typename T>
double ConvertToFahrenheit(T celsius)
{
    if (celsius < -273.15)
        throw InvalidTemperatureException();
    return (celsius * 9.0 / 5.0) + 32.0;
}

int main()
{
    try
    {
        cout << "TRYING TO CONVERT -500C TO FAHRENHEIT..." << endl;
        double f = ConvertToFahrenheit(-500); 
        cout << "CONVERSION RESULT: " << f << "F" << endl;
    }
    catch (const InvalidTemperatureException &e)
    {
        cout << "ERROR: INVALID TEMPERATURE DETECTED" << endl;
        cout << "DETAILS: " << e.what() << endl;
        cout << "NOTE: TEMPERATURE CANNOT BE BELOW ABSOLUTE ZERO (-273.15C)" << endl;
    }

    return 0;
}