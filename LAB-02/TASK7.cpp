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

void multiply(int **matrix1,int **matrix2,int cols,int cols2,int rows , int rows2){
	if(cols!=rows2){
		cout<<endl<<"MATRIX MULITPLICATION NOT POSSIBLE, ORDER MISTMATCHED"<<endl;
		return;
	}
	cout<<endl;
int result =0;
for(int k=0;k<rows;k++){
	for(int i=0;i<cols2;i++){
		for(int j=0;j<cols;j++){
			
			result+=matrix1[k][j]*matrix2[j][i];

			
		}
		cout<<" | " <<result;
		result = 0;
	}
	cout<<" |"<<endl;
	}
}
	
int main()
{
    int **matrix1, **matrix2;
    int rows, cols, rows2, cols2;

    getDimensions(&rows, &cols, 1);
    matrix1 = alloc(rows, cols);
    inputMatrix(matrix1, rows, cols);

    getDimensions(&rows2, &cols2, 2);
    matrix2 = alloc(rows2, cols2);
    inputMatrix(matrix2, rows2, cols2);
	
	
	multiply(matrix1,matrix2,cols,cols2,rows,rows2);

    dealloc(matrix1, rows);
    dealloc(matrix2, rows2);

    return 0;
}