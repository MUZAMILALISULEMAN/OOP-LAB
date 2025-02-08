#include<iostream>
using namespace std;
void getDimensions(int *pages,int *rows, int *cols)
{
    cout << endl
         << "INPUT THE DIMENSIONS FOR ARRAY " << endl;
    cout << "ENTER THE PAGES: ";
	cin >> *pages;
	cout << "ENTER THE ROWS: ";
    cin >> *rows;
    cout << "ENTER THE COLUMNS: ";
    cin >> *cols;
    cout << endl;

}
int ***alloc(int pages,int rows, int cols)
{
    int ***p = new int **[pages];
    for (int i = 0; i < pages; i++)
    {
        p[i] = new int*[rows];
    	for(int j=0;j<rows;j++){
    		p[i][j] = new int[cols];
	}    
    
	}
    
    return p;
}
int ***dealloc(int ***p,int pages,int rows)
{
    for (int i = 0; i < pages; i++)
    {
    	for(int j=0;j<rows;j++){
    		delete [] p[i][j];
	}
	delete [] p[i];    
	}
	delete [] p;
    
    return p;
}
void inputArray(int ***arr,int pages,int rows,int cols){
	cout<<endl;
	for(int i=0;i<pages;i++){
		for(int j=0;j<rows;j++){
			for(int k=0;k<cols;k++){
				cout<<"ENTER THE ELEMENT FOR PAGE " <<i+1<<" ROW "<<j+1<<" COLUMN "<<k+1<<" : ";
				cin>>arr[i][j][k];
			}
		}
	cout<<endl;
	}
}
void displayArray(int ***arr,int pages,int rows,int cols){
	cout<<endl;
	for(int i=0;i<pages;i++){
		for(int j=0;j<rows;j++){
			for(int k=0;k<cols;k++){
				cout<<" | "<<arr[i][j][k];
			}
			
		cout << " |" << endl;
		}
	cout<<endl<<endl;
	}
}

int main(){

int pages,rows,cols;
getDimensions(&pages,&rows,&cols);
int ***array = alloc(pages,rows,cols);
inputArray(array,pages,rows,cols);
displayArray(array,pages,rows,cols);
dealloc(array,pages,rows);


return 0;
}
