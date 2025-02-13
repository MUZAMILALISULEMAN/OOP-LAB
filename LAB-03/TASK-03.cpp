#include<iostream>
using namespace std;
class Library {
	private:
		string bookList[100];
		string borrowedBooks[100];
		string students[100];
		int availableBooks[100];
		int books;
		int borrowedBooksCount;
	public:
		Library(){
			books = 0;
			borrowedBooksCount = 0;
		}
		void addBook(string bookName) {
			if(books< 100){
			bookList[books] = bookName;
			availableBooks[books] = 1;
			books++;
			cout<<"BOOK ADDED!"<<endl;
			}else{
				cout<<endl<<"UNNABLE TO ADD!"<<endl;
			}
		}
		void lendBook(string bookName,string studentName) {
			for(int i=0; i<books; i++) {
				if(bookList[i] == bookName && availableBooks[i] == 1 && borrowedBooksCount < 100) {
					cout<<"BOOK ISSUED TO "<<studentName<<endl;
					availableBooks[i] = 0;
					students[borrowedBooksCount] = studentName;
					borrowedBooks[borrowedBooksCount] = bookName;
					borrowedBooksCount++;
					break;
				}
			}
		}
		void returnBook(string bookName,string studentName) {
			int found = 0;
			for(int i=0; i<borrowedBooksCount; i++) {
				if(borrowedBooks[i] == bookName) {
				
					found = 1;
					
					for(int j=i;j<borrowedBooksCount-1;j++){

						borrowedBooks[j] = borrowedBooks[j+1];
						students[j] = students[j+1];
						
					}
					borrowedBooksCount--;
					break;
					
				}
			}
			if(found == 0) {
				return;
			}
			for(int i=0; i<books; i++) {
				if(bookList[i] == bookName) {
					availableBooks[i] = 1;
					break;
				}
			}

			cout<<"BOOK RETURNED BY "<<studentName<<endl;

		}
		void AvailableBooks(){
			int k = 0;
			cout<<"AVAILABLE BOOKS:";
			for(int i=0;i<books;i++){
	
				if(availableBooks[i] == 1){
					cout<<endl<<++k<<". "<<bookList[i];
					
				}
				
				
			}
			if(k == 0){
				cout<<" NO BOOK AVAILABLE";
			}
			cout<<endl;
		}		

};
int main() {
	
	Library FAST;
	FAST.addBook("STRANGER THINGS");
	FAST.AvailableBooks();
	FAST.addBook("HARRY POTTER");
	FAST.AvailableBooks();
	FAST.lendBook("HARRY POTTER","ALI");
	FAST.AvailableBooks();
	FAST.returnBook("HARRY POTTER","ALI");
	FAST.AvailableBooks();

	return 0;
}
