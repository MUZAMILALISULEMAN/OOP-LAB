#include<iostream>
#include<exception>
using namespace std;
class DimensionMismatchError:public exception{
private:
string message;
public:
DimensionMismatchError(string message):message(message){}
const char* what() noexcept{
return message.c_str();
}
};
template<class TYPE>
class Matrix{
TYPE **matrix;
int rows;
int cols;
public:
Matrix(int rows,int cols):rows(rows),cols(cols){

    matrix = new TYPE*[this->rows];
    for (size_t i = 0; i < this->rows; i++)
    {
        matrix[i] = new TYPE[this->cols];
    }

}
~Matrix(){

for (size_t i = 0; i < this->rows; i++)
{
delete[] matrix[i];    
}
delete[] matrix;
}

void getMatrix(){

for (int i = 0; i < rows; i++)
{
    for (int j = 0; j < cols; j++)
    {
        cout<<"ENTER THE ROW "+to_string(i+1)+" COLUMN "+to_string(j+1)+" : ";
        cin>>matrix[i][j];
        cout<<endl;
    }
    
}
}
Matrix<TYPE> operator+(const Matrix<TYPE> &B){


if(B.cols != cols || B.rows!=rows){
    throw DimensionMismatchError("MATRIX ORDER MISMATCHED!!!");
}
Matrix<TYPE> k(rows,cols);
for (int i = 0; i < rows; i++)
{
    for (int j = 0; j < cols; j++)
    {
        k.matrix[i][j] = matrix[i][j]+B.matrix[i][j];
    }
    
}
return k;
}
void display(){


    for (int i = 0; i < rows; i++) {         
        for (int j = 0; j < cols; j++) {     
            cout << matrix[i][j] << " "; 
        }
        cout << endl; 
}

}

};
int main() {
    
    try{
    Matrix<int>A(3,3);
    Matrix<int>B(2,2);
    cout<<"MATRIX 1: \n\n";
    A.getMatrix();
    cout<<"MATRIX 2: \n\n";
    B.getMatrix();
    Matrix<int>K = A+B;
    K.display();
	}catch(DimensionMismatchError &e){
		cout<<"ERROR: "<<e.what()<<endl;
	}




}