#include<iostream>
using namespace std;
typedef struct{
	string year;
	string author;
	string title;
}Book;

Book getInput(){
	cout<<endl;
	Book book;
	cout<<"ENTER THE BOOK TITLE: ";
	cin>>book.title;
	cout<<"ENTER THE AUTHOR FOR BOOK: ";
	cin>>book.author;
	cout<<"ENTER THE YEAR FOR BOOK: ";
	cin>>book.year;
	cout<<endl;
	return book;
}
void display(Book book){

	cout<<endl<<"BOOK TITLE: "<<book.title<<endl;
	cout<<"BOOK AUTHOR: "<<book.author<<endl;
	cout<<"BOOK PUBLISHED YEAR: "<<book.year<<endl;
	
	
}


int main() {

	int n;
	cout<<"HOW MANY BOOKS: ";
	cin>>n;
	cout<<endl;
	Book *books = new Book[n];
	for(int i=0; i<n; i++) {
		cout<<"ENTER THE DETAILS FOR BOOK "<<i+1<<endl;
		books[i] = getInput();
	}
	string Year;
	cout<<"ENTER THE YEAR TO FIND THE BOOKS OF SPECIFIC YEAR: ";
	cin>>Year;
	
	for(int i=0; i<n; i++) {
		if(books[i].year.compare(Year) > 0){
			display(books[i]);
		}
	}

	





delete [] books;



return 0;
}