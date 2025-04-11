#include <iostream>
#include <cmath>

using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& complexOther) const {
        return Complex(real + complexOther.real, imag + complexOther.imag);
    }

    Complex operator*(const Complex& complexOther) const {
        return Complex(real * complexOther.real - imag * complexOther.imag, real * complexOther.imag + imag * complexOther.real);
    }

    Complex operator-(const Complex& complexOther) const {
        return Complex(real - complexOther.real, imag - complexOther.imag);
    }

    friend ostream& operator<<(ostream& cout, const Complex& c);
    
    friend double magnitude(const Complex& c);
};

double magnitude(const Complex& c){
        return sqrt(c.real * c.real + c.imag * c.imag);
}
ostream& operator<<(ostream& cout, const Complex& c) {
    cout << "(" << c.real << " + " << c.imag << "i)";
    return cout;
}

int main() {

    Complex c1(3, 4);
    Complex c2(1, 2);

    Complex sum = c1 + c2;
    cout << "SUM: " << sum << endl;

    Complex diff = c1 - c2;
    cout << "DIFFERENCE: " << diff << endl;

    Complex product = c1 * c2;
    cout << "PRODUCT: " << product << endl;

    cout << "MAGNITUDE OF " << c1 << ": " << magnitude(c1) << endl;
    cout << "MAGNITUDE OF " << c2 << ": " << magnitude(c2) << endl;
    return 0;
}