#include <iostream>
using namespace std;
class level{
private:
int levelNo;
int difficulty;
string description;
public:
level():levelNo(-1),difficulty(-1),description(""){}
level(int levelNo,int difficulty,string description):levelNo(levelNo),difficulty(difficulty),description(description){}
void display()const{

    cout<<"LEVEL NO: "<<levelNo<<endl;
    cout<<"DIFFICULTY: "<<difficulty<<endl;
    cout<<"DESCRIPTION: "<<description<<endl<<endl;

}
};
class game{
    string title;
    string genre;
    level levels[10];
    int levelCount;
    public:
    game(string title,string genre):title(title),genre(genre),levelCount(0){}
    game():levelCount(0),title(""),genre(""){}
    void display()const{
        cout<<"GENRE: "<<genre<<endl;
        cout<<"TITLE: "<<title<<endl;
        for (int i = 0; i < levelCount; i++)
        {
            levels[i].display();
        }
    }
    void addLevel(level LEVEL){
        if(levelCount>10) return;
        levels[levelCount++] = LEVEL;
    }


};
int main() {
    game GAME("UPSIDE DOWN","ACTION");
    GAME.addLevel(level(1,4,"EASY TO HANDLE"));
    GAME.addLevel(level(2,10,"TOUGH TO HANDLE"));
    GAME.display();
    return 0;
}