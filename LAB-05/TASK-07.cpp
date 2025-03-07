#include <iostream>
using namespace std;
class Product
{
    const int id;
    string name;
    int quantity;

public:
    Product() : id(-1), name(""), quantity(0) {}
    Product(int id,string name, int qty) : id(id), name(name) ,quantity(qty) {}
    int getID() const
    {
        return id;
    }
    string getName() const
    {
        return name;
    }
    void display() const
    {
        cout << "ID: " << id << endl;
        cout << "NAME: " << name << endl;
        cout << "QUANTITY: " << quantity << endl<<endl;
    }
};

class Inventory
{

private:
    Product *products[100];
    int productCount;

public:
    Inventory() : productCount(0) {}
    void addProduct(string name, int id, int quantity)
    {
        if (productCount < 100)
        {
            products[productCount++] = new Product(id,name, quantity);
    
        }
        else
        {
            cout << "INSUFFICIENT SPACE!!!" << endl;
        }
    }

    void search(int ID){
        for (int i = 0; i < productCount; i++)
        {
            if (products[i]->getID() == ID){
                cout<<"PRODUCT FOUND!"<<endl;
                products[i]->display();
                return;
            }
            
        }
        cout<<"NOT FOUND!"<<endl;
    }
    void sort(){

        for(int i=0;i<productCount;i++){
            string pname = products[i]->getName();
            for (int j = 0; j < productCount; j++)
            {
                if(products[j]->getName() > pname){
                    Product *temp = products[i];
                    products[i] = products[j];
                    products[j] = temp; 
                }
            }
        }
        
    }
    void displayAll(){
        for (int i = 0; i < productCount; i++)
        {
            products[i]->display();
        }
    }


    ~Inventory()
    {
        for (int i = 0; i < productCount; i++){
            delete products[i];}
    }
};
int main()
{
    Inventory inv;
    inv.addProduct("Shampoo",1,100);
    inv.addProduct("Bicycle",2,5);
    inv.sort();
    inv.displayAll();
    inv.search(2);

    return 0;
}
