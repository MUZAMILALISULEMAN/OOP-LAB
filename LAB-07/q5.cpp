#include <iostream>
using namespace std;

class Warrior;
class Mage;
class Archer;
class Rogue;

class Character
{
protected:
    int characterID;
    string name;
    int level;
    float healthPoints;
    float hitDamage;
    float defense;

public:
    Character() {}

    Character(int characterID, string name, int level, float healthPoints, float hitDamage, float defense)
        : characterID(characterID), name(name), level(level), healthPoints(healthPoints), hitDamage(hitDamage), defense(defense) {}

    virtual void defend(double damage)
    {
        double damageAbsorbed = defense - damage;
        if (damageAbsorbed < 0)
        {
            if (healthPoints - damageAbsorbed <= 0)
            {
                healthPoints = 0;
            }
            else
            {
                healthPoints -= damageAbsorbed;
            }
            defense = 0;
        }
        else
        {
            defense = damageAbsorbed;
        }
    }

    virtual void attack(Character &enemy)
    {
        enemy.defend(hitDamage);
    }

    void displayStats()
    {
        cout << "CHARACTER ID: " << characterID << endl;
        cout << "CHARACTER NAME: " << name << endl;
        cout << "LEVEL: " << level << endl;
        cout << "HEALTH POINTS: " << healthPoints << endl;
        cout << "HIT DAMAGE: " << hitDamage << endl;
        cout << "DEFENSE: " << defense << endl;
    }
};

class Warrior : public Character
{
private:
    float armorStrength;
    float meleeDamage;

public:
    Warrior() {}

    Warrior(int characterID, string name, int level, float healthPoints, float hitDamage, float defense, float armorStrength, float meleeDamage)
        : Character(characterID, name, level, healthPoints, hitDamage, defense), armorStrength(armorStrength), meleeDamage(meleeDamage) {}

    void attack(Character &enemy)
    {
        enemy.defend(meleeDamage);
    }
};

class Mage : public Character
{
private:
    float manaPoints;
    float spellPower;
    float magicalBarrier;

public:
    Mage() {}

    Mage(int characterID, string name, int level, float healthPoints, float hitDamage, float defense, float manaPoints, float spellPower, float magicalBarrier)
        : Character(characterID, name, level, healthPoints, hitDamage, defense), manaPoints(manaPoints), spellPower(spellPower), magicalBarrier(magicalBarrier) {}

    void defend(double damage)
    {
        float DAMAGE = magicalBarrier - damage;
        if (DAMAGE < 0)
        {
            magicalBarrier = 0;
            DAMAGE = defense + DAMAGE;
            if (DAMAGE < 0)
            {
                defense = 0;
                if (healthPoints + DAMAGE < 0)
                {
                    healthPoints = 0;
                }
                else
                {
                    healthPoints += DAMAGE;
                }
                return;
            }
            defense = DAMAGE;
            return;
        }
        magicalBarrier = DAMAGE;
    }
};

class Rogue : public Character
{
private:
    float stealthLevel;
    float agility;

public:
    Rogue() {}

    Rogue(int characterID, string name, int level, float healthPoints, float hitDamage, float defense, float stealthLevel, float agility)
        : Character(characterID, name, level, healthPoints, hitDamage, defense), stealthLevel(stealthLevel), agility(agility) {}

    void displayStats()
    {
        Character::displayStats();
        cout << "STEALTH LEVEL: " << stealthLevel << endl;
        cout << "AGILITY: " << agility << endl;
    }
};

class Archer : public Character
{
private:
    int arrowCount;
    float rangedAccuracy;

public:
    Archer() {}

    Archer(int characterID, string name, int level, float healthPoints, float hitDamage, float defense, int arrowCount, float rangedAccuracy)
        : Character(characterID, name, level, healthPoints, hitDamage, defense), arrowCount(arrowCount), rangedAccuracy(rangedAccuracy) {}

    void attack(Character &enemy)
    {
        if (arrowCount > 0)
        {
            if (rangedAccuracy > (rand() % 100) / 100.0)
            {
                cout << "SHOT MISSED!" << endl;
            }
            else
            {
                enemy.defend(hitDamage);
            }
            arrowCount--;
        }
    }
};

class VideoGameCharacterManagementSystem
{
private:
    Character *characters[4];

public:
    VideoGameCharacterManagementSystem()
    {
        characters[0] = new Mage(1, "WANDA", 10, 200, 50, 30, 100, 80, 150);
        characters[1] = new Warrior(2, "THOR", 12, 300, 70, 50, 100, 90);
        characters[2] = new Rogue(3, "BLACK WIDOW", 8, 150, 40, 25, 90, 85);
        characters[3] = new Archer(4, "HAWK EYE", 11, 180, 60, 40, 20, 0.85);
    }

    void displayInitialStats()
    {
        cout << "\nINITIAL STATS\n";
        for (int i = 0; i < 4; i++)
        {
            characters[i]->displayStats();
        }
    }

    void startBattle()
    {
        cout << "\nBATTLE BEGINS!\n";

        cout << "\nWARRIOR ATTACKS MAGE!\n";
        characters[1]->attack(*characters[0]);
        characters[0]->displayStats();

        cout << "\nMAGE ATTACKS ROGUE!\n";
        characters[0]->attack(*characters[2]);
        characters[2]->displayStats();

        cout << "\nROGUE ATTACKS ARCHER!\n";
        characters[2]->attack(*characters[3]);
        characters[3]->displayStats();

        cout << "\nARCHER ATTACKS WARRIOR!\n";
        characters[3]->attack(*characters[1]);
        characters[1]->displayStats();

        cout << "\nBATTLE OVER\n";
    }

    ~VideoGameCharacterManagementSystem()
    {
        for (int i = 0; i < 4; i++)
        {
            delete characters[i];
        }
    }
};

int main()
{
    VideoGameCharacterManagementSystem game;
    game.displayInitialStats();
    game.startBattle();
    return 0;
}
