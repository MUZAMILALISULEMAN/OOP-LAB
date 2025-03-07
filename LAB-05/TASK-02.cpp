#include <iostream>
using namespace std;
class Student
{

private:
    const int id;
    string name;
    
    public:
    float *marks;
    int count;
    Student() : id(-1)
    {
        marks = new float[20];
        count = 0;
    }

    Student(int id, string name) : id(id), name(name)
    {
        marks = new float[20];
        count = 0;
    }

    Student(const Student &other) : id(other.id)
    {
        name = other.name;
        count = other.count;
        marks = new float[count];
        for (int i = 0; i < count; i++)
        {
            marks[i] = (other.marks)[i];
        }
    }

    void display()
    {
        cout << "NAME: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "MARKS: ";
        for (int i = 0; i < count; i++)
        {
            cout << marks[i] << " ";
        }
        cout << endl;
    }
 ~Student(){
     delete[] marks;
    }
}
;
int main()
{

    Student A(3, "MUZAMIL");
    A.marks[0] = 50;
    A.count++;
    A.marks[1] = 40;
    A.count++; 
    Student B = A;
    B.display();

    return 0;
}