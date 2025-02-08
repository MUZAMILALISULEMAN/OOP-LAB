#include<iostream>
using namespace std;
float weekly_avg(int AQI[4][4][7],int cityIndex,int weekIndex) {
	float avg = 0;
	for(int i=0; i<7; i++) {
		avg+=AQI[cityIndex][weekIndex][i];
	}
	return avg/7.0;

}
void minmax(int AQI[4][4][7],int minmaxValues[2]) {
	int max = AQI[0][0][0];
	int min = max;
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			for(int k=0; k<7; k++) {
				if(max < AQI[i][j][k]) {
					max = AQI[i][j][k];
				}
				if(min > AQI[i][j][k]) {
					min = AQI[i][j][k];
				}
			}
		}
	}

	minmaxValues[0] = min;
	minmaxValues[1] = max;


}
int main() {

	int AQI[4][4][7] = {
    { // City 1
        {85, 367, 361, 409, 251, 147, 70},     // Week 1
        {384, 413, 354, 40, 372, 339, 158},    // Week 2
        {496, 7, 352, 239, 307, 19, 500},      // Week 3
        {61, 237, 116, 206, 43, 69, 150}       // Week 4
    },
    { // City 2
        {309, 248, 377, 268, 347, 377, 389},   // Week 1
        {61, 364, 473, 11, 10, 103, 31},       // Week 2
        {175, 46, 426, 162, 63, 359, 186},     // Week 3
        {461, 155, 79, 8, 193, 391, 92}        // Week 4
    },
    { // City 3
        {30, 64, 385, 363, 462, 347, 165},     // Week 1
        {195, 437, 486, 345, 339, 42, 428},    // Week 2
        {433, 76, 311, 382, 441, 366, 241},    // Week 3
        {209, 435, 313, 477, 27, 177, 443}     // Week 4
    },
    { // City 4
        {144, 493, 253, 239, 175, 197, 283},   // Week 1
        {299, 435, 473, 400, 86, 310, 410},    // Week 2
        {171, 99, 377, 55, 149, 468, 274},     // Week 3
        {292, 422, 32, 157, 119, 413, 483}     // Week 4
    }
};

//	for(int i=0; i<4; i++) {
//		cout<<endl<<"CITY "<<i+1<<":"<<endl;
//		for(int j=0; j<4; j++) {
//			for(int  k=0; k<7; k++) {
//				cout<<"DAY "<<7*j+(k+1)<<": ";
//				cin>>AQI[i][j][k];
//
//			}
//		}
//
//	}

	cout<<endl<<"\t====WEEKLY AVERAGE===="<<endl;
	for(int i=0; i<4; i++) {
		cout<<endl<<"CITY "<<i+1<<":"<<endl;
		for(int j=0; j<4; j++) {
			cout<<"WEEK "<<j+1<<": "<<weekly_avg(AQI,i,j)<<endl;
		}
	}
	cout<<endl<<"\t====CRTIICAL POLLUTION DAYS====="<<endl;
	for(int i=0; i<4; i++) {
		cout<<endl<<"CITY "<<i+1<<":"<<endl<<endl;
		for(int j=0; j<4; j++) {
			for(int k=0; k<7; k++) {
				if(AQI[i][j][k] > 150) {
					cout<<"DAY "<<7*j+(k+1)<<": "<< AQI[i][j][k]<<endl;
				}
			}
		}
	}
	int minmaxValues[2] = {0};
	minmax(AQI,minmaxValues);
	cout<<"MINIMUM FOR MONTH: "<<minmaxValues[0]<<endl;
	cout<<"MAXIMUM FOR MONTH: "<<minmaxValues[1]<<endl;


	return 0;
}
