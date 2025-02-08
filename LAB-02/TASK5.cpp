#include<iostream>
using namespace std;
int main(){
int size,sum=0;
cout<<"ENTER THE SIZE OF THE ARRAY: ";
cin>>size;
int *array = new int[size];
for(int i=0;i<size;i++){
	cout<<"ENTER THE ELEMENT "<<i+1<<": ";
	cin>>*(array+i);
	sum+=*(array+i);
}
	cout<<endl<<"ARRAY ELEMENTS: ";
for(int i=0;i<size;i++){
	cout<<*(array+i)<<" ";
}
cout<<endl<<endl<<"SUM OF ARRAY ELEMENT: "<<sum;






return 0;
}
