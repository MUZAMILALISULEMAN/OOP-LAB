#include <iostream>
int event1_count = 0;
int event2_count = 0;
using namespace std;
int main(){
string event1_participant[5];
string event2_participant[5];
int choice = 1;
while(choice > 0 && choice < 4){
int isContinue=1;
cout<<"REGISTER FOR EVENT (1/2) OR CHECK ATTENDANCE (3) ";
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
		string name;
		int found = 0;
		cout<<"ENTER THE NAME FOR MEMBER: ";
		cin>>name;
		for(int i=0; i<5; i++){
		if(event1_participant[i] == name){
			cout<<name<<" IS REGISTERED IN EVENT 1\n";
			found = 1;
			break;
		} else if (event2_participant[i] == name){
			cout<<name<<" IS REGISTERED IN EVENT 2\n";
			found = 1;
			break;
		}	
		
	}
	if(found == 0){
	cout<<"NOT FOUND!\n";
	}
	break;
	
}
}
}
	 
