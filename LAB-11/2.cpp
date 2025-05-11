#include <iostream>
#include <stdexcept>

using namespace std;

class QueueOverflowException : public exception
{
};

class QueueUnderflowException : public exception
{
};

template <typename T>
class Queue
{
private:
    int front, rear, size, capacity;
    T* data;

public:
    Queue(int cap) : front(0), rear(0), size(0), capacity(cap)
    {
        data = new T[capacity];
    }

    ~Queue() {
        delete[] data;
    }

    void enqueue(const T &value)
    {
        if (isFull())
            throw QueueOverflowException();

        data[rear] = value;
        rear = (rear + 1) % capacity;
        size++;
    }

    T dequeue()
    {
        if (isEmpty())
            throw QueueUnderflowException();

        T val = data[front];
        front = (front + 1) % capacity;
        size--;
        return val;
    }

    bool isEmpty() const { return size == 0; }
    bool isFull() const { return size == capacity; }
};

int main()
{
    Queue<int> q(2);

    try
    {
        cout << "ATTEMPTING TO ENQUEUE INTO A FULL QUEUE..." << endl;
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30); 
    }
    catch (const QueueOverflowException &e)
    {
        cout << "CAUGHT QueueOverflowException: THE QUEUE IS FULL!" << endl;
    }

    try
    {
        cout << "DEQUEUEING FROM THE QUEUE..." << endl;
        Queue<int> emptyQueue(2);
        emptyQueue.dequeue(); 
    }
    catch (const QueueUnderflowException &e)
    {
        cout << "CAUGHT QueueUnderflowException: THE QUEUE IS EMPTY!" << endl;
    }

    return 0;
}
