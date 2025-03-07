#include <iostream>
using namespace std;
class AlarmSystem
{

private:
    string securityLevel;

public:
    AlarmSystem() { securityLevel = ""; }
    AlarmSystem(string level) : securityLevel(level) {}
    string getSecurityLevel() const { return securityLevel; };
    void setSecurityLevel(string level) { securityLevel = level; }
    void display() const
    {
        cout << "SECURITY LEVEL: " << securityLevel << endl;
    }
};
class SmartHome
{

private:
    string name;
    AlarmSystem alarm;

public:
    SmartHome(string name, string securityLevel) : name(name)
    {
        alarm.setSecurityLevel(securityLevel);
    }
    SmartHome() : name("") {}

    void display() const
    {
        cout << "SMART HOME NAME: " << name << endl;
        alarm.display();
    }

    void setName(string name)
    {
        this->name = name;
    }
    void setSecurityLevel(string sLevel)
    {
        alarm.setSecurityLevel(sLevel);
    }
    string getSecurityLevel() const
    {
        return alarm.getSecurityLevel();
    }
    string getName() const
    {
        return name;
    }
};
int main()
{
    SmartHome Home("DIGITAL HOME", "MEDIUM");
    Home.display();
    return 0;
}