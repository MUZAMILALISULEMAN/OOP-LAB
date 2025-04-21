#include <iostream>
#include <string>
using namespace std;

class Course {
protected:
    string courseCode;
    int credits;

public:
    Course(string code, int credit) : courseCode(code), credits(credit) {}
    virtual ~Course() {}

    virtual void calculateGrade() = 0;
    virtual void displayInfo() = 0;
};

class LectureCourse : public Course {
public:
    LectureCourse(string code, int credit) : Course(code, credit) {}

    void calculateGrade()  {
        cout << "CALCULATING GRADE FOR LECTURE COURSE: " << courseCode << endl;
    }

    void displayInfo()  {
        cout << "LECTURE COURSE INFO:" << endl;
        cout << "COURSE CODE: " << courseCode << endl << "CREDITS: " << credits << endl;
    }
};

class LabCourse : public Course {
public:
    LabCourse(string code, int credit) : Course(code, credit) {}

    void calculateGrade()  {
        cout << "CALCULATING GRADE FOR LAB COURSE: " << courseCode << endl;
    }

    void displayInfo()  {
        cout << "LAB COURSE INFO:" << endl;
        cout << "COURSE CODE: " << courseCode << endl << "CREDITS: " << credits << endl;
    }
};

int main() {
    
    LectureCourse l("CS101", 3);
    LabCourse la("CS101L", 1);
    Course* lecture = &l;

    lecture->displayInfo();
    lecture->calculateGrade();

    lecture = &la;

    lecture->displayInfo();
    lecture->calculateGrade();


    return 0;
}
