#include<iostream>
using namespace std;
int main() {
int AQI[4][7];
for(int i=0;i<4;i++){
	cout<<endl<<"CITY "<<i+1<<": "<<endl;
	for(int j=0;j<7;j++){
		cout<<"DAY "<<j+1<<": ";
		cin>>AQI[i][j];
	}
}
cout<<"CRITICAL POLLUTIONS DAYS: "<<endl;
	for(int i=0; i<4; i++) {
		cout<<endl<<"CITY "<<i+1<<": "<<endl;
		for(int j=0; j<7; j++) {
			if(AQI[i][j] > 150){
				cout<<"DAY "<<j+1<<" : "<<AQI[i][j]<<endl;
			}
					}
	}
	return 0;
}
