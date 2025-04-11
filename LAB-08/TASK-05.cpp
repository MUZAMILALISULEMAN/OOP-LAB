#include <iostream>

using namespace std;

class Matrix2x2;

class MatrixHelper {
public:
    void updateElement(Matrix2x2& matrix, int row, int col, int value);
};

class Matrix2x2 {
private:
    int elements[2][2];

public:
    Matrix2x2(int a = 0, int b = 0, int c = 0, int d = 0) {
        elements[0][0] = a;
        elements[0][1] = b;
        elements[1][0] = c;
        elements[1][1] = d;
    }

    Matrix2x2 operator+(const Matrix2x2& other) const {
        return Matrix2x2(
            elements[0][0] + other.elements[0][0],
            elements[0][1] + other.elements[0][1],
            elements[1][0] + other.elements[1][0],
            elements[1][1] + other.elements[1][1]
        );
    }

    Matrix2x2 operator-(const Matrix2x2& other) const {
        return Matrix2x2(
            elements[0][0] - other.elements[0][0],
            elements[0][1] - other.elements[0][1],
            elements[1][0] - other.elements[1][0],
            elements[1][1] - other.elements[1][1]
        );
    }

    Matrix2x2 operator*(const Matrix2x2& other) const {
        return Matrix2x2(
            elements[0][0] * other.elements[0][0] + elements[0][1] * other.elements[1][0],
            elements[0][0] * other.elements[0][1] + elements[0][1] * other.elements[1][1],
            elements[1][0] * other.elements[0][0] + elements[1][1] * other.elements[1][0],
            elements[1][0] * other.elements[0][1] + elements[1][1] * other.elements[1][1]
        );
    }

    friend int determinant(const Matrix2x2& matrix);

    friend ostream& operator<<(ostream& cout, const Matrix2x2& matrix);

    friend class MatrixHelper;
};

int determinant(const Matrix2x2& matrix) {
    return matrix.elements[0][0] * matrix.elements[1][1] - matrix.elements[0][1] * matrix.elements[1][0];
}

ostream& operator<<(ostream& cout, const Matrix2x2& matrix) {
    cout << matrix.elements[0][0] << " " << matrix.elements[0][1] << endl;
    cout << matrix.elements[1][0] << " " << matrix.elements[1][1];
    return cout;
}

void MatrixHelper::updateElement(Matrix2x2& matrix, int row, int col, int value) {
    if (row >= 0 && row < 2 && col >= 0 && col < 2) {
        matrix.elements[row][col] = value;
    } else {
        cout << "INVALID ROW OR COLUMN INDEX!" << endl;
    }
}

int main() {
    Matrix2x2 mat1(1, 2, 3, 4);
    Matrix2x2 mat2(5, 6, 7, 5);

    cout << "MATRIX 1:" << endl << mat1 << endl;
    cout << "MATRIX 2:" << endl << mat2 << endl;

    Matrix2x2 sum = mat1 + mat2;
    cout << "SUM OF MATRICES:" << endl << sum << endl;

    Matrix2x2 diff = mat1 - mat2;
    cout << "DIFFERENCE OF MATRICES:" << endl << diff << endl;

    Matrix2x2 product = mat1 * mat2;
    cout << "PRODUCT OF MATRICES:" << endl << product << endl;

    cout << "DETERMINANT OF MATRIX 1: " << determinant(mat1) << endl;

    MatrixHelper helper;
    helper.updateElement(mat1, 0, 1, 10);
    cout << "MATRIX 1 AFTER UPDATING ELEMENT (0, 1) TO 10:" << endl << mat1 << endl;

    return 0;
}