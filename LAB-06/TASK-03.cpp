#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(): name(""), age(0) {}
    Person(string name, int age): name(name), age(age) {}
    void displayDetails() {
        cout << "NAME: " << name << endl;
        cout << "AGE: " << age << endl;
    }
};

class Teacher : protected Person {
protected:
    string subject;
public:
    Teacher(): Person(), subject("") {}
    Teacher(string name, int age, string subject): Person(name, age), subject(subject) {}
    void displayDetails() {
        Person::displayDetails();
        cout << "SUBJECT: " << subject << endl;
    }
};

class Researcher : protected Teacher {
protected:
    string researchArea;
public:
    Researcher(): Teacher(), researchArea("") {}
    Researcher(string name, int age, string subject, string researchArea)
        : Teacher(name, age, subject), researchArea(researchArea) {}
    void displayDetails() {
        Teacher::displayDetails();
        cout << "RESEARCH AREA: " << researchArea << endl;
    }
};

class Professor : protected Researcher {
protected:
    int publications;
public:
    Professor(): Researcher(), publications(0) {}
    Professor(string name, int age, string subject, string researchArea, int publications)
        : Researcher(name, age, subject, researchArea), publications(publications) {}
    void displayDetails() {
        Researcher::displayDetails();
        cout << "PUBLICATIONS: " << publications << endl;
    }
};

int main() {
    Professor p1("MUZAMIL", 20, "AI ANALYST", "AI", 11);
    p1.displayDetails();

    return 0;
}
