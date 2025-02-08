#include <iostream>
using namespace std;

int **alloc(int rows, int cols)
{
    int **p = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        *(p + i) = new int[cols];
    }
    return p;
}

void getDimensions(int *rows, int *cols, int matNo)
{
    cout << endl
         << "INPUT THE DIMENSIONS FOR MATRIX " << matNo << endl;
    cout << "ENTER THE ROWS: ";
    cin >> *rows;
    cout << "ENTER THE COLUMNS: ";
    cin >> *cols;
    cout << endl;
}

void dealloc(int **matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void sum(int **matrix1, int **matrix2, int rows, int cols, int rows2, int cols2)
{
    if (rows != rows2 || cols != cols2)
    {
        cout << endl
             << "ORDER OF MATRICES ARE NOT EQUAL!!!" << endl;
        return;
    }

    cout << endl
         << "SUM OF THE MATRICES" << endl
         << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << " | " << matrix1[i][j] + matrix2[i][j];
        }
        cout << " |" << endl;
    }
}

void sub(int **matrix1, int **matrix2, int rows, int cols, int rows2, int cols2)
{
    if (rows != rows2 || cols != cols2)
    {
        cout << endl
             << "ORDER OF MATRICES ARE NOT EQUAL!!!" << endl;
        return;
    }
    int k;
    cout << endl
         << "DIFFERENCE OF THE MATRICES" << endl
         << endl;
    cout << "WHICH MATRIX HAS TO BE SUBTRACTED FROM THE OTHER (1/2): ";
    cin >> k;
    cout << endl
         << endl;
    if (k == 2)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << " | " << matrix1[i][j] - matrix2[i][j];
            }
            cout << " |" << endl;
        }
    }
    else
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << " | " << matrix2[i][j] - matrix1[i][j];
            }
            cout << " |" << endl;
        }
    }
}

void inputMatrix(int **matrix, int rows, int cols)
{
    int k = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "ENTER ELEMENT " << k++ << ": ";
            cin >> matrix[i][j];
        }
    }
}

void display(int **matrix, int rows, int cols)
{
    cout << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << " | " << matrix[i][j];
        }
        cout << " |" << endl;
    }
    cout << endl;
}

int main()
{
    int **matrix1, **matrix2;
    int rows, cols, rows2, cols2;

    getDimensions(&rows, &cols, 1);
    matrix1 = alloc(rows, cols);
    inputMatrix(matrix1, rows, cols);
    display(matrix1, rows, cols);

    getDimensions(&rows2, &cols2, 2);
    matrix2 = alloc(rows2, cols2);
    inputMatrix(matrix2, rows2, cols2);
    display(matrix2, rows2, cols2);

    int choice;
    do
    {
        << "1. ADD MATRICES" << endl << "2. SUBTRACT MATRICES" << endl << "3. EXIT" << endl<< "ENTER YOUR CHOICE: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            sum(matrix1, matrix2, rows, cols, rows2, cols2);
            break;
        case 2:
            sub(matrix1, matrix2, rows, cols, rows2, cols2);
            break;
        case 3:
            cout << "EXITING PROGRAM..." << endl;
            break;
        default:
            cout << "INVALID CHOICE. PLEASE TRY AGAIN." << endl;
        }
    } while (choice != 3);

    dealloc(matrix1, rows);
    dealloc(matrix2, rows2);

    return 0;
}
