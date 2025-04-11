#include <iostream>
using namespace std;

class product {
protected:
    int productId;
    string name;
    double price;
    int stock;

public:
    product(int p, string s, double pr, int st)
        : productId(p), name(s), price(pr), stock(st) {}

    virtual double applyDiscount() {
        return price * 0.8;
    }

    virtual double calculateTotalPrice(int quantity) {
        return price * quantity;
    }

    virtual void displayProductInfo() {
        cout << ".................\n";
        cout << "PRODUCT ID: " << productId << endl;
        cout << "PRODUCT NAME: " << name << endl;
        cout << "PRICE: " << price << endl;
        cout << "STOCK: " << stock << endl;
        cout << ".................\n";
    }

    product operator+(product& p) {
        return product(productId, name, price + p.price, stock);
    }

    friend ostream& operator<<(ostream& os, const product& p) {
        os << "PRODUCT ID: " << p.productId << endl
           << "PRODUCT NAME: " << p.name << endl
           << "PRICE: " << p.price << endl
           << "STOCK: " << p.stock << endl;
        return os;
    }
};

class electronics : public product {
    int warranty;
    string brand;

public:
    electronics(int p, string s, double pr, int st, int w, string b)
        : product(p, s, pr, st), warranty(w), brand(b) {}

    void displayProductInfo() override {
        product::displayProductInfo();
        cout << "WARRANTY (MONTHS): " << warranty << endl;
        cout << "BRAND: " << brand << endl;
        cout << ".................\n";
    }
};

class clothes : public product {
    string color;
    string size;
    string fabricMaterial;

public:
    clothes(int p, string s, double pr, int st, string c, string sz, string fm)
        : product(p, s, pr, st), color(c), size(sz), fabricMaterial(fm) {}

    double applyDiscount() override {
        if (fabricMaterial == "Thick")
            return price * 0.7;
        return price * 0.8;
    }

    void displayProductInfo() override {
        product::displayProductInfo();
        cout << "COLOR: " << color << endl;
        cout << "SIZE: " << size << endl;
        cout << "FABRIC: " << fabricMaterial << endl;
        cout << ".................\n";
    }
};

class foodItem : public product {
    string expiryDate;
    int calories;

public:
    foodItem(int p, string s, double pr, int st, string ed, int cal)
        : product(p, s, pr, st), expiryDate(ed), calories(cal) {}

    double calculateTotalPrice(int quantity) override {
        if (quantity > 10)
            return price * quantity * 0.8;
        return price * quantity;
    }

    void displayProductInfo() override {
        product::displayProductInfo();
        cout << "EXPIRY DATE: " << expiryDate << endl;
        cout << "CALORIES: " << calories << endl;
        cout << ".................\n";
    }
};

class book : public product {
    string author;
    string genre;

public:
    book(int p, string s, double pr, int st, string a, string g)
        : product(p, s, pr, st), author(a), genre(g) {}

    void displayProductInfo() override {
        product::displayProductInfo();
        cout << "AUTHOR: " << author << endl;
        cout << "GENRE: " << genre << endl;
        cout << ".................\n";
    }
};

int main() {
    cout << "\n=== E-COMMERCE PRODUCT SHOWCASE ===\n\n";

    electronics e1(101, "iphone", 25000, 15, 12, "apple");
    e1.displayProductInfo();

    clothes c1(102, "Pants", 4500, 30, "Blue", "Medium", "Cotton");
    c1.displayProductInfo();
    cout << "ORIGINAL PRICE: " << c1.calculateTotalPrice(1) << endl;
    cout << "DISCOUNTED PRICE: " << c1.applyDiscount() << endl << ".................\n";

    foodItem f1(103, "FIZZ UP", 100, 50, "2026-04-01", 100);
    f1.displayProductInfo();
    cout << "TOTAL PRICE (5 ITEMS): " << f1.calculateTotalPrice(5) << endl;
    cout << "TOTAL PRICE (12 ITEMS - BULK): " << f1.calculateTotalPrice(12) << endl << ".................\n";

    book b1(104, "OOP 03", 1200, 20, "Havard", "Math");
    b1.displayProductInfo();

    product combined = c1 + b1;
    cout << "\nCOMBINED PRICE OF KURTA + BOOK:\n" << combined << endl;

    return 0;
}

