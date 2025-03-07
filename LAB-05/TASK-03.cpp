#include <iostream>
using namespace std;
class Project;
class Employee{
private:
string name;
string designation;
Project *assignedProject[10];
int projectCount;
public:
Employee(string name,string designation):name(name),designation(designation){projectCount=0;}
Employee(){
    name = "";
    designation= "";
    projectCount=0;
}
void displayAll();
void displayDetails(){
    cout<<"NAME: "<<name<<endl;
    cout<<"DESIGNATION: "<<designation<<endl;
}
int getProjectCount()const{return projectCount;}
void assignProject(Project *p);
};
class Project{
    private:
    int countEmployee;
    Employee *employees[10];
    public:
    string title;
    string deadline;
    Project():title(""),deadline(""){countEmployee=0;}
    Project(string title,string deadline):title(title),deadline(deadline){countEmployee=0;}
    void addEmployee(Employee *e){
        if(countEmployee>10 || e->getProjectCount() > 10) return;
        employees[countEmployee++] = e; 
        e->assignProject(this);

    }
    void displayDetails(){
        cout<<"TITLE: "<<title<<endl;
        cout<<"DEADLINE: "<<deadline<<endl;
    }
    void DisplayAll(){
        displayDetails();
        for (int i = 0; i < countEmployee; i++)
        {
            employees[i]->displayDetails();
        }
    }
    

};

void Employee::assignProject(Project *p){
    if (projectCount >  10) return;
    assignedProject[projectCount++] = p;
    
}
void Employee::displayAll(){
    cout<<"NAME: "<<name<<endl;
    cout<<"DESIGNATION: "<<designation<<endl;
    for (int i = 0; i < projectCount; i++)
    {
        assignedProject[i]->displayDetails();
    }
    
}

int main() {
    
    Employee e1("Alice", "Software Engineer");
    Employee e2("Bob", "Project Manager");


    Project p1("AI Development", "2025-06-01");
    Project p2("Cyber Security", "2025-07-15");

    p1.addEmployee(&e1);
    p2.addEmployee(&e1);
    p1.addEmployee(&e2);
    p2.addEmployee(&e2);
    
    p1.DisplayAll();
    e1.displayAll();
    p2.DisplayAll();
    e2.displayAll();

    return 0;
}
