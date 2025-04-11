#include <iostream>

using namespace std;

class Vector2D {
private:
    double x;
    double y;

public:
    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}

    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    Vector2D operator*(double scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }

    friend double dotProduct(const Vector2D& v1, const Vector2D& v2);
    friend ostream& operator<<(ostream& os, const Vector2D& v);
};

ostream& operator<<(ostream& os, const Vector2D& v) {
    os << "(" << v.y << ", " << v.x << ")";
    return os;
}

double dotProduct(const Vector2D& v1, const Vector2D& v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

int main() {
    Vector2D v1(3, 4);
    Vector2D v2(1, 2);

    Vector2D sum = v1 + v2;
    cout << "SUM: " << sum << endl;

    Vector2D diff = v1 - v2;
    cout << "DIFFERENCE: " << diff << endl;

    Vector2D scaled = v1 * 2;
    cout << "V1 BY SCALE OF 2: " << scaled << endl;

    double dot = dotProduct(v1, v2);
    cout << "DOT PRODUCT OF V1 AND V2: " << dot << endl;

    return 0;
}