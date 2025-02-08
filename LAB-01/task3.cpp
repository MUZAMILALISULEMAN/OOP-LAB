#include <iostream>
int event1_count = 0;
int event2_count = 0;
int total_donations = 0;
using namespace std;
int main(){
string event1_participant[5];
string event2_participant[5];
int choice=1;
while(choice > 0 && choice < 4){
int isContinue=1;
cout<<"REGISTER FOR EVENT (1/2) OR TOTAL DONATIONS (3) ";
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
		break;
	case 2:
		while(event2_count <=5 && isContinue == 1){
			cout<<"ENTER NAME FOR MEMBER" << event2_count+1<< ": ";
			cin>>event2_participant[event2_count];
			event2_count++;
			cout<<"DO YOU WANT TO CONTINUE (1/0): ";
			cin>>isContinue;
		}
		break;
	case 3:
	total_donations = (event1_count + event2_count) * 10;
	cout<<"TOTAL DONATIONS FOR BOTH EVENTS:  "<<total_donations<<endl;
	break;
	
}
}
}
	 
