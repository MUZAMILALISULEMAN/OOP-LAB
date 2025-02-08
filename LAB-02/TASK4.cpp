#include<iostream>
#include <cctype>//this library has tolower(char ch) function
using namespace std;

string toLowercase(string s){
	string str = s;
		for(int l=0;l<str.length();l++){ // string for lowercase string 1
			str[l] = tolower(str[l]);
		}
		return str;
}




int main() {

	int n;
	cout<<"HOW MANY STRINGS TO BE STORED: ";
	cin>>n;
	cout<<endl;
	string *strings = new string[n];

	for(int i=0; i<n; i++) {

		cout<<"ENTER THE STRING "<<i+1<<" : ";
		cin>>strings[i];

	}

	cout<<endl<<"UNSORTED STRINGS: ";
	for(int i=0; i<n; i++) {
		cout<<strings[i]<<" ";

	}

	string temp;


	for(int i=0;i<n;i++){
	for(int j=0; j<n; j++) {
		if(toLowercase(strings[i]).compare(toLowercase(strings[j])) < 0) { //lowercase string1 and string2 for fair comparison
			temp = strings[i];
			strings[i] = strings[j];
			strings[j] = temp;
		}
	}

	}

cout<<endl<<"SORTED STRINGS: ";
for(int i=0; i<n; i++) {
	cout<<strings[i]<<" ";

}

delete [] strings;



return 0;
}