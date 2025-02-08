#include<iostream>
float month_average(int AQI[4][4][7],int cityIndex) {

	float avg=0;

	for(int i=0; i<4; i++) {
		for(int j=0; j<7; j++) {
			avg+=AQI[cityIndex][i][j];
		}
	}

	return avg/28.0;

}

float improvement_calc(int AQI[4][4][7],int cityIndex) {
	float improvement =0;
	float weeks_avg[2] = {0};
	int weeks_index[2] = {0,3};
	for(int i=0; i<2; i++) {
		for(int j=0; j<7; j++) {
			improvement+=AQI[cityIndex][weeks_index[i]][j];
		}

		weeks_avg[i] = improvement/7.0;
		improvement = 0;
	}
	improvement = weeks_avg[0] - weeks_avg[1];
	if(improvement > 0){
	return improvement;
	}
	return 0;
}




using namespace std;
int main() {

	int AQI[4][4][7];
	for(int i=0;i<4;i++){
		cout<<"CITY "<<i+1<<" :"<<endl;
		for(int j=0;j<4;j++){
			for(int k=0;k<7;k++){
				cout<<"DAY "<<7*j+(k+1)<<" : ";
				cin>>AQI[i][j][k];
			}
		}
	}
//	for average of month
	
	for(int i=0; i<4; i++) {
		cout<<"AVERAGE AQI FOR CITY "<<i+1<<": "<<month_average(AQI,i)<<endl<<endl;
	}

//improved city
	
	float improved_cities[4]  = {0};
	for(int i=0;i<4;i++){
		improved_cities[i] = improvement_calc(AQI,i); 
	
	}
	int max_improved_city = 1;
	float temp = improved_cities[0];
	for(int i=0;i<4;i++){
		if(temp < improved_cities[i]){
			temp = improved_cities[i];
			max_improved_city = i+1;
		}
	}
	
	cout<<"MAX IMPROVED CITY:  "<<max_improved_city<<endl;




	return 0;
}