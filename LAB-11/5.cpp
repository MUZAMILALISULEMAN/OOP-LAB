#include <iostream>
#include <stdexcept>

using namespace std;

class NegativeStockException : public exception {};
class OverCapacityException : public exception {};

template <typename T>
class InventoryItem
{
private:
    T currentStock;
    T maximumCapacity;

public:
    InventoryItem(T max) : currentStock(0), maximumCapacity(max) {}

    void updateStock(T quantity)
    {
        if (quantity < 0)
        {
            throw NegativeStockException();
        }
        if (quantity > maximumCapacity)
        {
            throw OverCapacityException();
        }
        currentStock = quantity;
    }

    T checkStock() const
    {
        return currentStock;
    }
};

int main()
{
    InventoryItem<int> item(100);

    try
    {
        cout << "ATTEMPTING TO SET STOCK TO -10..." << endl;
        item.updateStock(-10);
    }
    catch (const NegativeStockException &e)
    {
        cout << "ERROR: NEGATIVE STOCK DETECTED - " << e.what() << endl;
    }

    try
    {
        cout << "ATTEMPTING TO SET STOCK TO 123 (MAX 100)..." << endl;
        item.updateStock(123);
    }
    catch (const OverCapacityException &e)
    {
        cout << "ERROR: EXCEEDED MAXIMUM CAPACITY - " << e.what() << endl;
    }

    return 0;
}