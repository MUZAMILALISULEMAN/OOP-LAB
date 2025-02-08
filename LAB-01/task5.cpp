#include <iostream>
using namespace std;
int event1_count = 0;
int event2_count = 0;
void barChart(int participants_count,int event){
	cout<<"EVENT "<<event<<": ";
	for(int i=0;i<participants_count;i++){
		cout<<"*";
	}
	cout<<endl;
}



int main(){
string event1_participant[5];
string event2_participant[5];
int choice;
while(!(event1_count >= 5 && event2_count >= 5)){
int isContinue=1;
cout<<"REGISTER FOR EVENT (1/2) OR EVENT POPULARITY BAR CHART (3): ";
cin>>choice;

switch(choice){
	case 1:
		while(event1_count <=5 && isContinue == 1){
			cout<<"ENTER NAME FOR MEMBER " << event1_count+1<< ": ";
			cin>>event1_participant[event1_count];
			event1_count++;
			cout<<"DO YOU WANT TO CONTINUE (1/0): ";
			cin>>isContinue;
			
			
		}
		isContinue = 1;
			break;
	case 2:
		while(event2_count <=5 && isContinue == 1){
			cout<<"ENTER NAME FOR MEMBER " << event2_count+1<< ": "; 
			cin>>event2_participant[event2_count];
			event2_count++;
			cout<<"DO YOU WANT TO CONTINUE (1/0): ";
			cin>>isContinue;
			
		}
			isContinue = 1;
		break;
	case 3:
		barChart(event1_count,1);
		barChart(event2_count,2);
		
}
}
}
	 
