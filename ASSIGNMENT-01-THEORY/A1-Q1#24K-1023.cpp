#include <iostream>
using namespace std;

class Learner;

class Skill {
public:
    int skillID;
    string skillName;
    string description;

    void showSkillDetails() const {
        cout << "SKILL ID: " << skillID << endl;
        cout << "SKILL NAME: " << skillName << endl;
        cout << "SKILL DESCRIPTION: " << description << endl;
    }

    void updateSkillDescription(string newDescription) {
        description = newDescription;
    }
};

class Sports {
private:
    int sportID;
    Skill requiredSkill[20];
    int skillCount;

public:
    string name;
    string description;

    Sports() : skillCount(0) {}

    void display() const {
        cout << "SPORT ID: " << sportID << endl;
        cout << "NAME: " << name << endl;
        cout << "DESCRIPTION: " << description << endl;
        cout << "REQUIRED SKILLS: ";
        for (int i = 0; i < skillCount; i++) {
            requiredSkill[i].showSkillDetails();
        }
        cout << endl;
    }
};

class Mentor {
private:
    int mentorID;
    int maxLearners;
    int assignedLearnersCount;
    Learner* assignedLearners[100];
    int countExpertise;

public:
    string name;
    Sports sportExpertise[20];

    Mentor() : mentorID(0), maxLearners(0), assignedLearnersCount(0), countExpertise(0) {}

    Mentor(int ID, int maxlearners, string name) : mentorID(ID), maxLearners(maxlearners), name(name), assignedLearnersCount(0), countExpertise(0) {}

    int getStudentsAssigned() const {
        return assignedLearnersCount;
    }

    int getMaxLearners() const {
        return maxLearners;
    }

    void assignLearner(Learner* s) {
        if (assignedLearnersCount < maxLearners) {
            assignedLearners[assignedLearnersCount++] = s;
        } else {
            cout << "MENTOR " << name << " HAS REACHED THE MAX CAPACITY." << endl;
        }
    }

    int getCountExpertise() const {
        return countExpertise;
    }

    void removeLearner(Learner* s);

    void viewLearners();

    void provideGuidance();
        
};

class Learner {
private:
    int id;
    Sports sportOfInterest[20];
    int age;
    int sportOfInterestCount;

public:
    int getID() const {
        return id;
    }

    void display() const {
        cout << "ID: " << id << endl;
        cout << "NAME: " << name << endl;
        cout << "AGE: " << age << endl;
        for (int i = 0; i < sportOfInterestCount; i++) {
            sportOfInterest[i].display();
        }
    }

    Mentor* mentorAssigned;
    string name;

    Learner() : id(0), age(0), sportOfInterestCount(0), mentorAssigned(nullptr) {}

    Learner(int id, int age, string name) : id(id), age(age), name(name), sportOfInterestCount(0), mentorAssigned(nullptr) {}

    void registerForMentor(Mentor& m) {
        if (m.getStudentsAssigned() < m.getMaxLearners()) {
            mentorAssigned = &m;
            m.assignLearner(this);
        } else {
            cout << "MENTOR " << m.name << " HAS NO AVAILABLE SLOTS." << endl;
        }
    }

    void viewMentorDetails() const {
        if (mentorAssigned) {
            cout << "MENTOR NAME: " << mentorAssigned->name << endl;
            for (int i = 0; i < mentorAssigned->getCountExpertise(); i++) {
                mentorAssigned->sportExpertise[i].display();
            }
        } else {
            cout << "NO MENTOR IS ASSIGNED." << endl;
        }
    }

    void updateSportsInterest(Sports s) {
        if (sportOfInterestCount < 20) {
            sportOfInterest[sportOfInterestCount++] = s;
        } else {
            cout << "CAN'T ADD MORE SPORT INTEREST" << endl;
        }
    }
};

void Mentor::removeLearner(Learner* s) {
    for (int i = 0; i < assignedLearnersCount; i++) {
        if (assignedLearners[i] == s) {
            for (int j = i; j < assignedLearnersCount - 1; j++) {
                assignedLearners[j] = assignedLearners[j + 1];
            }
            assignedLearnersCount--;
            cout << "LEARNER REMOVED FROM THE MENTORSHIP." << endl;
            return;
        }
    }
    cout << "LEARNER IS NOT FOUND UNDER THIS MENTOR." << endl;
}

void Mentor::viewLearners() {
    if (assignedLearnersCount == 0) {
        cout << "NO LEARNERS ARE ASSIGNED." << endl;
        return;
    }
    cout << "MENTOR " << name << " HAS THE FOLLOWING LEARNERS:" << endl;
    for (int i = 0; i < assignedLearnersCount; i++) {
        assignedLearners[i]->display();
    }
}

void Mentor::provideGuidance() {
        cout << "MENTOR " << name << " IS PROVIDING GUIDANCE TO ASSIGNED LEARNERS." << endl;
        for (int i = 0; i < assignedLearnersCount; i++) {
            cout << "GUIDING LEARNER: " << assignedLearners[i]->name << endl;
        }
    }


int main() {
    
    Mentor mentor(1, 2, "ALI");
    Learner l1(12, 18, "MUZAMIL");
    Learner l2(13, 18, "MUZZY");
    Learner l3(14, 19, "AHMED");

    
    l1.registerForMentor(mentor);
    l2.registerForMentor(mentor);
    l3.registerForMentor(mentor); 

    mentor.viewLearners();

    mentor.removeLearner(&l1);

    mentor.viewLearners();

    return 0;
}
