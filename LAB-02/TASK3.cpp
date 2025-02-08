#include<iostream>
using namespace std;
typedef struct{
	float hoursWorked;
	string name;
	float hourlyRate;
}Employee;

Employee getInput(){
	cout<<endl;
	Employee employee;
	cout<<"ENTER THE EMPLOYEE NAME: ";
	cin>>employee.name;
	cout<<"ENTER THE HOUR WORKED FOR EMPLOYEE: ";
	cin>>employee.hoursWorked;
	cout<<"ENTER THE HOURLY RATE FOR EMPLOYEE: ";
	cin>>employee.hourlyRate;
	cout<<endl;
	return employee;
}



int main() {

	int n;
	cout<<"HOW MANY EMPLOYEE RECORDS: ";
	cin>>n;
	cout<<endl;
	Employee *employees = new Employee[n];
	for(int i=0; i<n; i++) {
		cout<<"ENTER THE DETAILS FOR EMPLOYEE "<<i+1<<endl;
		employees[i] = getInput();
	}
	
	for(int i=0;i<n;i++){
		cout<<"SALARY FOR EMPLOYEE "<<i+1<<": ";
		cout<<employees[i].hoursWorked*employees[i].hourlyRate<<endl;
	}

	





delete [] employees;



return 0;
}