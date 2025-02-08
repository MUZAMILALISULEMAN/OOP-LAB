#include<iostream>
using namespace std;
typedef struct{
	int rollNumber;
	string name;
	float marks[3];
}Student;

Student getInput(){
	cout<<endl;
	Student student;
	cout<<"ENTER THE STUDENT ROLL NUMBER: ";
	cin>>student.rollNumber;
	cout<<"ENTER THE STUDENT NAME: ";
	cin>>student.name;
	for(int i=0;i<3;i++){
	cout<<"ENTER THE STUDENT MARKS FOR SUBJECT "<<i+1<<": ";
	cin>>student.marks[i];	
	}
	cout<<endl;
	return student;
}



int main() {

	int n;
	cout<<"HOW MANY STUDENT RECORDS: ";
	cin>>n;
	cout<<endl;
	Student *students = new Student[n];
	for(int i=0; i<n; i++) {

		cout<<"ENTER THE DETAILS FOR STUDENT "<<i+1<<endl;
		students[i] = getInput();
		

	}
	float avg ;
	for(int i=0;i<n;i++){
		cout<<"AVERAGE FOR STUDENT "<<i+1<<": ";
		avg = 0;
		for(int j=0;j<3;j++){
			avg+=students[i].marks[j];
		}
		
		cout<<avg/3.0<<endl;
	}


delete [] students;



return 0;
}