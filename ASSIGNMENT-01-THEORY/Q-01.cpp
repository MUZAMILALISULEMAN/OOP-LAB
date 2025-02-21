#include <iostream>
using namespace std;
class Learner;
class Skill
{
public:
    int skillID;
    string skillName;
    string description;
    void showSkillDetails() const
    {
        cout << "SKILL ID: " << skillID << endl;
        cout << "SKILL NAME: " << skillName << endl;
        cout << "SKILL DESCRIPTION: " << description << endl;
    }
    void updateSkillDescription(string newDescription)
    {
        description = newDescription;
    }
};
class Sports
{
private:
    int sportID;
    Skill requiredSkill[20];
    int skillCount;

public:
    string name;
    string description;
    Sports()
    {
        skillCount = 0;
    }

    void display() const
    {

        cout << "SPORT ID: " << sportID << endl;
        cout << "NAME: " << name << endl;
        cout << "DESCRIPTION: " << description << endl;
        cout << "REQUIRED SKILLS: ";
        for (int i = 0; i < skillCount; i++)
        {
            requiredSkill[i].showSkillDetails();
        }
        cout << endl;
    }
};
class Mentor
{
private:
    int mentorID;
    int maxLearners;
    int assignedLearnersCount;
    Learner *assignedLearners[100];
    int countExpertise;

public:
    string name;
    Sports sportExpertise[20];

    Mentor()
    {

        assignedLearnersCount = 0;
        countExpertise = 0;
    }

    Mentor(int ID, int maxlearners, string name)
    {

        this->mentorID = ID;
        this->name = name;
        this->maxLearners = maxlearners;
        assignedLearnersCount = 0;
        countExpertise = 0;
    }

    int getStudentsAssigned()const
    {
        return assignedLearnersCount;
    }
    int getMaxLearners() const
    {
        return maxLearners;
    }
    void assignLearner(Learner *s)
    {

        assignedLearners[assignedLearnersCount++] = s;
    }
    int getCountExpertise() const

    {
        return countExpertise;
    }

    void removeLearner(Learner s);
    void viewLearners();

    void provideGuidance() {
        cout << "MENTOR " << name << " IS PROVIDING GUIDANCE TO ASSIGNED LEARNERS." << endl;
        for (int i = 0; i < assignedLearnersCount; i++) {
            cout << "GUIDING LEARNER: " << assignedLearners[i]->name << endl;
        }
    }
    

};

class Learner
{
private:
    int id;
    Sports sportOfInterest[20];
    int age;
    int sportOfInterestCount;

public:
    int getID() const
    {
        return id;
    }
    void display() const{

        cout<<"ID: "<<id<<endl;
        cout<<"NAME: "<<name<<endl;
        cout<<"AGE: "<<age<<endl;
        for (int i = 0; i < sportOfInterestCount; i++)
        {
            sportOfInterest[i].display();
        }
        


    }
    Mentor mentorAssigned;
    string name;
    Learner() { sportOfInterestCount = 0; };
    Learner(int id, int age, string name)
    {
        this->id = id;
        this->age = age;
        this->name = name;
        sportOfInterestCount = 0;
    }
    void registerForMentor( Mentor &m)
    {
        int assignedLearnersCount = m.getStudentsAssigned();
        int total = m.getMaxLearners();
        if (assignedLearnersCount < total)
        {
            // copying the data
            mentorAssigned.name = m.name;
            int CountExpertise = m.getCountExpertise();
            for (int i = 0; i < CountExpertise; i++)
            {
                mentorAssigned.sportExpertise[i] = m.sportExpertise[i];
            }
            m.assignLearner(this);
        }
    }
    void viewMentorDetails()const
    {
        int assignedLearnersCount = mentorAssigned.getCountExpertise();
        cout << "MENTOR NAME: " << mentorAssigned.name << endl;

        for (int i = 0; i < assignedLearnersCount; i++)
        {
            mentorAssigned.sportExpertise[i].display();
        }
    }

    void updateSportsInterest(Sports s)
    {

        if (sportOfInterestCount < 20)
        {

            sportOfInterest[sportOfInterestCount++] = s;
        }
    }
};

void Mentor::removeLearner(Learner s)
{
    for (int i = 0; i < assignedLearnersCount; i++)
    {
        if (assignedLearners[i]->getID() == s.getID())
        {
            for (int j = i; j < assignedLearnersCount - 1; j++)
            {
                assignedLearners[j] = assignedLearners[j + 1];
            }
            assignedLearners[assignedLearnersCount - 1] = nullptr;
            assignedLearnersCount--;
            break;
        }
    }
}

void Mentor::viewLearners(){
    for(int i=0;i<assignedLearnersCount;i++){
        assignedLearners[i]->display();
    }
}

int main()
{
    Mentor mentor(1, 20, "ALI");
    Learner l1(12, 18, "MUZAMIL");
    Learner l2(13, 18, "MUZZY");
    
    return 0;
}