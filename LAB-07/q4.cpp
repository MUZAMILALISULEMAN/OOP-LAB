#include <iostream>
using namespace std;

class Doctor; // Forward declaration

class Person
{
protected:
    string name;
    int age;
    string contactNumber;
    string address;

public:
    Person(string name, int age, string contactNumber, string address)
        : name(name), age(age), contactNumber(contactNumber), address(address) {}

    void updateInfo(string name, int age, string contactNo, string address)
    {
        this->name = name;
        this->age = age;
        this->contactNumber = contactNo;
        this->address = address;
    }

    virtual void displayInfo()
    {
        cout << "NAME: " << name << endl;
        cout << "AGE: " << age << endl;
        cout << "CONTACT NUMBER: " << contactNumber << endl;
        cout << "ADDRESS: " << address << endl;
    }
};

class Patient : public Person
{
private:
    int patientID;
    string medicalHistory;
    Doctor *doctorAssigned;

public:
    Patient(string name, int age, string contactNumber, string address, int patientID, string medicalHistory, Doctor *doctorAssigned)
        : Person(name, age, contactNumber, address), patientID(patientID), medicalHistory(medicalHistory), doctorAssigned(doctorAssigned) {}

    void updateInfo(string name, int age, string contactNo, string address, int patientID, string medicalHistory)
    {
        Person::updateInfo(name, age, contactNo, address);
        this->patientID = patientID;
        this->medicalHistory = medicalHistory;
    }

    void displayInfo();
};

class Doctor : public Person
{
private:
    string specialization;
    double consultationFee;
    Patient *patientList[10];
    int patientCount;

public:
    Doctor(string name, int age, string contactNumber, string address, string specialization, double consultationFee)
        : Person(name, age, contactNumber, address), specialization(specialization), consultationFee(consultationFee), patientCount(0) {}

    void addPatient(Patient *p)
    {
        if (patientCount < 10)
        {
            patientList[patientCount++] = p;
        }
        else
        {
            cout << "PATIENT LIST IS FULL!" << endl;
        }
    }

    void updateInfo(string name, int age, string contactNo, string address, string specialization, double consultationFee)
    {
        Person::updateInfo(name, age, contactNo, address);
        this->specialization = specialization;
        this->consultationFee = consultationFee;
    }

    void displayInfo()
    {
        Person::displayInfo();
        cout << "SPECIALIZATION: " << specialization << endl;
        cout << "CONSULTATION FEE: " << consultationFee << endl;
    }
};

void Patient::displayInfo()
{
    Person::displayInfo();
    cout << "PATIENT ID: " << patientID << endl;
    cout << "MEDICAL HISTORY: " << medicalHistory << endl;
    if (doctorAssigned)
    {
        cout << "\n--- ASSIGNED DOCTOR DETAILS ---\n";
        doctorAssigned->displayInfo();
    }
}

class Nurse : public Person
{
private:
    string assignedWard;
    string shiftTimings;

public:
    Nurse(string name, int age, string contactNumber, string address, string assignedWard, string shiftTimings)
        : Person(name, age, contactNumber, address), assignedWard(assignedWard), shiftTimings(shiftTimings) {}

    void updateInfo(string name, int age, string contactNo, string address, string assignedWard, string shiftTimings)
    {
        Person::updateInfo(name, age, contactNo, address);
        this->assignedWard = assignedWard;
        this->shiftTimings = shiftTimings;
    }

    void displayInfo()
    {
        Person::displayInfo();
        cout << "ASSIGNED WARD: " << assignedWard << endl;
        cout << "SHIFT TIMING: " << shiftTimings << endl;
    }
};

class Administrator : public Person
{
private:
    string department;
    double salary;

public:
    Administrator(string name, int age, string contactNumber, string address, string department, double salary)
        : Person(name, age, contactNumber, address), department(department), salary(salary) {}

    void displayInfo()
    {
        Person::displayInfo();
        cout << "DEPARTMENT: " << department << endl;
        cout << "SALARY: " << salary << endl;
    }

    void updateInfo(Patient &p, string name, int age, string contactNumber, string address, int patientID, string medicalHistory)
    {
        p.updateInfo(name, age, contactNumber, address, patientID, medicalHistory);
    }

    void updateInfo(Doctor &d, string name, int age, string contactNumber, string address, string specialization, double consultationFee)
    {
        d.updateInfo(name, age, contactNumber, address, specialization, consultationFee);
    }

    void updateInfo(Nurse &n, string name, int age, string contactNumber, string address, string assignedWard, string shiftTimings)
    {
        n.updateInfo(name, age, contactNumber, address, assignedWard, shiftTimings);
    }
};

#include <iostream>
using namespace std;

int main()
{
   
    Doctor doc("DR. SMITH", 45, "123456789", "NYC", "CARDIOLOGY", 100.0);

    Patient pat1("JOHN DOE", 30, "987654321", "LA", 101, "DIABETES", &doc);
    Patient pat2("JANE DOE", 40, "456789123", "TEXAS", 102, "HYPERTENSION", &doc);
    
    doc.addPatient(&pat1);
    doc.addPatient(&pat2);

   
    Nurse nurse("ALICE BROWN", 28, "654987321", "BOSTON", "ICU", "NIGHT");
    Administrator admin("MARK WILSON", 50, "789321654", "CHICAGO", "MANAGEMENT", 75000.0);

 
    Person *people[4] = {&doc, &pat1, &nurse, &admin};
    for (int i = 0; i < 4; i++)
    {
        people[i]->displayInfo();
    }

   
    admin.updateInfo(doc, "DR. ROBERT SMITH", 50, "123456789", "SAN FRANCISCO", "NEUROLOGY", 150.0);

    doc.displayInfo();

    return 0;
}

