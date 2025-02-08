#include<iostream>
#include <cctype>//this library has tolower(char ch) function
using namespace std;
typedef struct{
	int productID;
	string name;
	int quantity;
	float price;
}product;

product getInput(){
	cout<<endl;
	product dummy;
	cout<<"ENTER THE PRODUCT ID: ";
	cin>>dummy.productID;
	cout<<"ENTER THE PRODUCT NAME: ";
	cin>>dummy.name;
	cout<<"ENTER THE PRODUCT QUANTITY: ";
	cin>>dummy.quantity;
	cout<<"ENTER THE PRODUCT PRICE: ";
	cin>>dummy.price;
	cout<<endl;
	return dummy;
}



int main() {

	int n;
	cout<<"HOW MANY PRODUCTS: ";
	cin>>n;
	cout<<endl;
	product *products = new product[n];
	float totalValue = 0;
	for(int i=0; i<n; i++) {

		cout<<"ENTER THE DETAILS FOR PRODUCT "<<i+1<<endl;
		products[i] = getInput();
		totalValue+=products[i].quantity*products[i].price;

	}

	cout<<"TOTAL VALUE OF THE INVENTORY: "<<totalValue;

	





delete [] products;



return 0;
}