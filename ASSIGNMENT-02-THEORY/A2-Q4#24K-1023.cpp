#include <iostream>
#include <string>
using namespace std;

int hashPassword(const string &password) {
    unsigned long hash = 5381;
    for (int i = 0; i < password.length(); i++)
        hash = ((hash * 33) + password[i]);
    return hash;
}

class User {
protected:
    string userName;
    string listOfPermission[10];
    int hashedPassword;
    string userEmail;
public:
    User() {}
    User(string name, string email, string LOF[], string password) : userName(name), userEmail(email) {
        for (int i = 0; i < 10; i++)
            listOfPermission[i] = LOF[i];
        hashedPassword = hashPassword(password);
    }
    bool authenticate(string pass) {
        return hashPassword(pass) == hashedPassword;
    }

    virtual void display() {
        cout << "NAME: " << userName << endl;
        cout << "EMAIL: " << userEmail << endl;
    }

    bool access(int lab) {
        if (listOfPermission[lab] == "Full_Lab_access") {
            cout << userName << " HAS BEEN GRANTED LAB ACCESS\n" << endl;
            return true;
        }
        else {
            cout << userName << " HAS BEEN GRANTED LAB ACCESS\n" << endl;
        }
        return false;
    }

    virtual void performAction(string action) = 0;
};

class Student : public User {
protected:
    int* assignment;
    static int totalAssignment;
public:
    Student() {}
    Student(string name, string email, string LOF[], string password) : User(name, email, LOF, password) {
        assignment = nullptr;
    }

    void addAssignment() {
        int* temp;
        if (assignment) {
            temp = new int[totalAssignment];
            for (int i = 0; i < totalAssignment; i++)
                temp[i] = assignment[i];
            delete[] assignment;
        }
        assignment = new int[++totalAssignment];
        for (int i = 0; i < totalAssignment - 1; i++)
            assignment[i] = temp[i];
        delete[] temp;
        assignment[totalAssignment - 1] = 0;
    }

    void submitAssignment(int assignmentNumber) {
        assignment[assignmentNumber - 1] = 1;
    }

    void display() {
        User::display();
        for (int i = 0; i < totalAssignment; i++)
            cout << "ASSIGNMENT " << i + 1 << ": " << assignment[i] << endl;
    }

    void performAction(string action) {
        if (action == "submit_assignment")
            cout << userName << " SUBMITTED AN ASSIGNMENT" << endl;
        else
            cout << "ACTION NOT PERMITTED FOR STUDENT" << endl;
    }
};

int Student::totalAssignment = 1;

class TA : public Student {
    Student assignedStudent[10];
    int currentStudent;
    string project[2];
    bool taAssigned;
    int projectNumber;
public:
    TA() {}
    TA(string name, string email, string LOF[], string password) : Student(name, email, LOF, password), projectNumber(0), currentStudent(0), taAssigned(false) {}

    void viewProject() {
        for (int i = 0; i < projectNumber; i++)
            cout << i + 1 << " PROJECT: " << project[i] << endl;
    }

    void addProject(string newProject) {
        if (projectNumber != 2) {
            project[projectNumber++] = newProject;
            cout << "PROJECT ASSIGNED" << endl;
        }
        else
            cout << "NEW PROJECT LIMIT EXCEEDED!" << endl;
    }

    void display() {
        Student::display();
        viewProject();
    }

    void assignedAsTA(bool aat) { taAssigned = aat; }
    
    void assignStudent(Student& s) {
        if (taAssigned) {
            if (currentStudent != 10)
                assignedStudent[currentStudent++] = s;
            else
                cout << "MORE THAN 10 CAN'T BE ASSIGNED" << endl;
        }
        else
            cout << "STUDENT IS NOT TA SO HE CAN'T MANAGE STUDENTS" << endl;
    }

    void performAction(string action) {
        if (action == "view_projects")
            cout << userName << " IS VIEWING PROJECTS" << endl;
        else if (action == "manage_students")
            cout << userName << " IS MANAGING STUDENTS" << endl;
        else
            Student::performAction(action);
    }
};

class Professor : public User {
    TA ta[4];
public:
    Professor(string name, string email, string LOF[], string password) : User(name, email, LOF, password) {}

    void assignedProject(int n, string project) {
        ta[n - 1].addProject(project);
    }

    void display() {
        User::display();
        for (int i = 0; i < 4; i++) {
            cout << "TA " << i + 1 << ":" << endl;
            ta[i].viewProject();
        }
    }

    void performAction(string action) {
        if (action == "assign_projects")
            cout << userName << " IS ASSIGNING PROJECTS" << endl;
        else if (action == "full_lab_access")
            cout << userName << " HAS FULL LAB ACCESS" << endl;
        else
            cout << "ACTION NOT PERMITTED FOR PROFESSOR" << endl;
    }
};

void authenticateAndPerformAction(User* user, string action) {
    user->performAction(action);
}

int main() {
    cout << "NAME: MUZAMIL ALI" << endl;
    cout << "ROLL NO: 24K-1023" << endl;
    string lf[10] = { "Full_Lab_access", "Full_Lab_access", "NOT_ACCESS", "Full_Lab_access", "NOT_ACCESS", "NOT_ACCESS", "Full_Lab_access", "NOT_ACCESS", "Full_Lab_access", "NOT_ACCESS" };
    Student s[3] = {
        {"RAHUL", "rahulpirwani704@gmail.com", lf, "&we"},
        {"ROHAN", "rohannlkumar@gmail.com", lf, "&e2234"},
        {"MANAV", "manav@gmail.com", lf, "&we"}
    };

    s[2].addAssignment();
    s[2].addAssignment();
    s[2].submitAssignment(1);
    s[2].display();

    TA t("KARAN", "karanshukari@gmail.com", lf, "iwe*2!");
    t.addProject("COMPUTER ENGINEERING");
    t.addProject("CYASD");
    t.access(3);
    t.addProject("HOW");

    t.assignStudent(s[1]);

    authenticateAndPerformAction(&t, "xyz");
    t.assignStudent(s[2]);

    Professor p("ALI", "Alikhan777@gmail.com", lf, "were");
    p.assignedProject(1, "XYZ");
    p.assignedProject(2, "XYZ");
    p.assignedProject(2, "DASUF");
    p.assignedProject(3, "XYZ");

    p.display();
}
