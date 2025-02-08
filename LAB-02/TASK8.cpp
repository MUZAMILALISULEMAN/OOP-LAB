#include<iostream>
using namespace std;
int main(){
int size;
cout<<"ENTER THE SIZE FOR ARRAY: ";
cin>>size;
int *array = new int[size];
for(int i=0;i<size;i++){
	cout<<"ENTER THE ELEMENT "<<i+1<<": ";
	cin>>array[i];
}
	cout<<endl<<"ARRAY ELEMENTS: ";
for(int i=0;i<size;i++){
	cout<<array[i]<<" ";
}


return 0;
}
