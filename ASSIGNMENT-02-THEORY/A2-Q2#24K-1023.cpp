#include <iostream>
using namespace std;

class Visitor;
class HauntedHouse;

class Ghost
{
protected:
    string name;
    int scareLevel;

public:
    Ghost() : name(""), scareLevel(0) {}
    Ghost(string name, int scareLevel) : name(name), scareLevel(scareLevel) {}
    virtual ~Ghost() {} 

    string getName() const { return name; }
    int getScareLevel() const { return scareLevel; }
    virtual void haunt() { cout << name << " IS HAUNTING !!!" << endl; }
    
    friend void visit(Visitor *visitor, int totalVisitors, HauntedHouse &house);
};

class Poltergeist : virtual public Ghost
{
public:
    Poltergeist(string name, int scareLevel) : Ghost(name, scareLevel) {}
    void haunt() override { cout << name << " IS MOVING OBJECTS !!!" << endl; }
};

class Banshee : public Ghost
{
public:
    Banshee(string name, int scareLevel) : Ghost(name, scareLevel) {}
    void haunt() override { cout << name << " IS SCREAMING !!! " << endl; }
};

class ShadowGhost :  virtual public Ghost
{
public:
    ShadowGhost(string name, int scareLevel) : Ghost(name, scareLevel) {}
    void haunt() override { cout << name << " IS WHISPERING CREEPILY... " << endl; }
};

class ShadowPoltergeist : public ShadowGhost, public Poltergeist
{
public:
    ShadowPoltergeist(string name, int scareLevel) : Ghost(name, scareLevel), ShadowGhost(name, scareLevel), Poltergeist(name, scareLevel) {}
    void haunt() override
    {
        ShadowGhost::haunt();
        Poltergeist::haunt();
    }
};

class HauntedHouse
{
private:
    string name;
    Poltergeist *pGhost;
    Banshee *bGhost;
    ShadowGhost *sGhost;
    ShadowPoltergeist *spGhost;

public:
    HauntedHouse(string name, Poltergeist *p, Banshee *b, ShadowGhost *s, ShadowPoltergeist *sp) : name(name), pGhost(p), bGhost(b), sGhost(s), spGhost(sp) {}
    ~HauntedHouse()
    {
        delete pGhost;
        delete bGhost;
        delete sGhost;
        delete spGhost;
    }
    
    friend void visit(Visitor *visitor, int totalVisitors, HauntedHouse &house);
};

class Visitor
{
    friend void visit(Visitor *visitor, int totalVisitors, HauntedHouse &house);
private:
    string name;
    int braveryPoints;

public:
    Visitor(string name, int braveryPts) : name(name), braveryPoints(braveryPts) {}

    string getName() { return name; }

    bool isCowardly() const { return braveryPoints >= 1 && braveryPoints <= 4; }
    bool isAverage() const { return braveryPoints >= 5 && braveryPoints <= 7; }
    bool isFearless() const { return braveryPoints >= 8 && braveryPoints <= 10; }

    void react(Ghost &ghost)
    {
        if (isFearless() && ghost.getScareLevel() <= 4)
        {
            cout << getName() << " TAUNTS " << ghost.getName() << " FEARLESSLY!" << endl;
        }
        else if (isCowardly() && ghost.getScareLevel() >= 8)
        {
            cout << getName() << " SCREAMS AND RUNS AWAY FROM " << ghost.getName() << "!" << endl;
        }
        else if (isAverage() && (ghost.getScareLevel() >= 5 && ghost.getScareLevel() <= 7))
        {
            cout << getName() << " GETS A SHAKY VOICE NEAR " << ghost.getName() << "." << endl;
        }
        else
        {
            cout << getName() << " DOESN'T KNOW HOW TO REACT TO " << ghost.getName() << "!" << endl;
        }
    }
};

void visit(Visitor *visitor, int totalVisitors, HauntedHouse &house)
{
    for (int i = 0; i < totalVisitors; i++)
    {
        cout << "\nVISITORS: " << visitor[i].getName() << " IS EXPLORING THE " << house.name << "..." << endl;

        house.pGhost->haunt();
        visitor[i].react(*house.pGhost);

        house.bGhost->haunt();
        visitor[i].react(*house.bGhost);

        house.sGhost->haunt();
        visitor[i].react(*house.sGhost);

        house.spGhost->haunt();
        visitor[i].react(*house.spGhost);
    }
}

int main()
{


    HauntedHouse house1("BHOOT BANGLA",
                         new Poltergeist("YURO", 3),
                         new Banshee("NOKU", 7),
                         new ShadowGhost("ROKU", 5),
                         new ShadowPoltergeist("HANSE", 9));

    HauntedHouse house2("GHOST MANSION",
                         new Poltergeist("MORGAN", 4),
                         new Banshee("TERRA", 10),
                         new ShadowGhost("DRAKE", 6),
                         new ShadowPoltergeist("CREEPER", 8));

    
    Visitor visitors[3] = {
        Visitor("MUZZY", 3),  
        Visitor("JANE", 6),   
        Visitor("LUCAS", 9)}; 



    visit(visitors, 3, house1);

    visit(visitors, 3, house2);

    return 0;
}