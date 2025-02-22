#include <iostream>
using namespace std;
#include <string>
#include <tuple>
string lowercase(string k)
{
    string Lowercase = "";
    int l = k.length();
    for (int i = 0; i < l; i++)
    {
        Lowercase += tolower(k[i]);
    }
    return Lowercase;
}
class Robot
{
    string name;
    int hits;

public:
    Robot(string name) : name(name) { hits = 0; }
    Robot() : name("") { hits = 0; }
    int getHits()
    {
        return hits;
    }
    string getName()
    {
        return name;
    }
    void setName(string NAME)
    {
        name = NAME;
    }

    void hitBall(int &BallX, int &BallY, string &Direction)
    {
        string d = lowercase(Direction);
        if (d == "up")
        {
            BallY++;
            hits++;
        }
        else if (d == "down")
        {
            BallY--;
            hits++;
        }
        else if (d == "right")
        {
            BallX++;
            hits++;
        }
        else if (d == "left")
        {
            BallX--;
            hits++;
        }
        else
        {
            cout << "INVALID DIRECTION";
        }
        return;
    }
};
class Ball
{

    int y;
    int x;

public:
    Ball() : x(0), y(0) {}
    int &refgetX()
    {
        return x;
    }
    int &refgetY()
    {
        return y;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }

    void move(int dx, int dy)
    {
        x = dx;
        y = dy;
    }
    tuple<int, int> getPosition()
    {
        return make_tuple(x, y);
    }
    void setBallX(int X)
    {
        x = X;
    }
    void setBallY(int Y)
    {
        y = Y;
    }
};
class Goal
{
    
    public:
    int x, y;
    Goal() : x(3), y(3) {}
    bool isGoalReached(int BallX, int BallY)
    {
        if (x == BallX && y == BallY)
        {
            return true;
        }
        return false;
    }

};
class Team
{
public:
    string teamName;
    Robot *getPlayer()
    {
        return player;
    }
    void setPlayer(Robot *p)
    {
        player = p;
    }

private:
    Robot *player;
};
class Game
{

    Team *teamOne;
    Team *teamTwo;
    Goal goal;
    Ball ball;

public:
    void setTeam(Team *t,int teamNO){
        if(teamNO == 1){
            teamOne = t;
        }else if(teamNO == 2){
            teamTwo = t;
        }
    }
    void play(Team *team)
    {

        ball.setBallX(0);
        ball.setBallY(0);
        do
        {

            cout << "ENTER THE DIRECTION: ";
            string direction;
            cin >> direction;
            team->getPlayer()->hitBall(ball.refgetX(), ball.refgetY(), direction);

        } while (!goal.isGoalReached(ball.getX(), ball.getY()));
    }
    void declareWinner()
    {

        if (teamOne->getPlayer()->getHits() < teamTwo->getPlayer()->getHits())
        {
            cout << teamOne->teamName << "IS THE WINNER";
        }
        else if (teamOne->getPlayer()->getHits() > teamTwo->getPlayer()->getHits())
        {
            cout << teamTwo->teamName << "IS THE WINNER";
        }
        else
        {
            cout << " IT IS THE TIE";
        }
    }
    void StartGame()
    {

        cout << "TEAM ONE NAME: ";
        cin >> teamOne->teamName;
        cout << "TEAM TWO NAME: ";
        cin >> teamTwo->teamName;
        cout << "GAME STARTED"<<endl;
        cout << "TEAM "<< teamOne->teamName + " TURN: " << endl;
        play(teamOne);
        cout << "TEAM "<< teamTwo->teamName + " TURN: " << endl;
        play(teamTwo);
        declareWinner();
    }
};

int main()
{
    Team teamOne;
    Team teamTwo;

    Robot robotOne("Player1");
    Robot robotTwo("Player2");

    teamOne.setPlayer(&robotOne);
    teamOne.setPlayer(&robotTwo);

    Game game;

    game.setTeam(&teamOne,1);
    game.setTeam(&teamTwo,2);

    game.StartGame();

    return 0;
}