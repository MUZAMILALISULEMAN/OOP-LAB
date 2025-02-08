#include<iostream>
using namespace std;

int main(){
int AQI[4][7];
for(int i=0;i<4;i++){
	cout<<endl<<"CITY "<<i+1<<": "<<endl;
	for(int j=0;j<7;j++){
		cout<<"DAY "<<j+1<<": ";
		cin>>AQI[i][j];
	}
}
int stars;
for(int i=0;i<4;i++){
	cout<<endl<<endl<<"CITY "<<i+1<<": "<<endl;
	for(int j=0;j<7;j++){
		cout<<endl<<"DAY "<<j+1<<": ";
		stars = AQI[i][j]/50;
		for(int k=0;k<stars;k++){
			cout<<"*";
		}
	}
}





return 0;
}
