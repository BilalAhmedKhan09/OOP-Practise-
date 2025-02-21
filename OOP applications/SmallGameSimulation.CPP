#include<iostream>
#include <tuple>

using namespace std;

class Ball{
    private:
    int X;
    int Y;

    public:
    Ball(){
        X = 0;
        Y = 0;
    }

    int getX(){
        return X;
    }
    
    int getY(){
        return Y;
    }

    tuple<int,int>getPosition(){
        return make_tuple(X,Y);
    }

    void Move(int dx, int dy){
        X += dx;
        Y += dy;
    }

};

class ROBOT{
    private:
    string Name;
    int Hits;

    public:
    ROBOT(){
        Hits = 0;
    }
    ROBOT(string name){
        Name = name;
        Hits = 0;
    }
    void Hitball(int &ballX, int &ballY, const string &direction){
        if(direction == "up"){
            ballY++;
        }
        else if(direction == "down"){
            ballY--;
        }
        else if(direction == "right"){
            ballX++;
        }
        else if(direction == "left"){
            ballX--;
        }
        Hits++;
    }

    int getHits(){
        return Hits;
    }
};

class Team{
    private:
    string Name;
    ROBOT Robot;
    
    public:
    Team(){}
    Team(string name, ROBOT &r){
        Name = name;
        Robot = r;
    }
    string GetName(){
        return Name;
    }

    void playRobot(int &x, int &y, const string &dir){
        Robot.Hitball(x, y, dir);
    }

    int robotdetails(){
        return Robot.getHits();
    }

    string getname(){
        return Name;
    }
};

class Goal{
    private:
    int X;
    int Y;

    public:
    Goal(){
        X = 3;
        Y = 3;
    }

    int isGoalReached(int ballX, int ballY){
        if(ballX == X && ballY == Y){
            return 1;
        }
        else{
            return 0;
        }
    }
};

class Game{
    private:
    Goal goal;
    Team team1;
    Team team2;
    Ball ball;
    
    public:
    Game(Team &t1, Team &t2){
        team1 = t1;
        team2 = t2;
    }

    void Play(Team &team){
        int ballX = ball.getX();
        int ballY = ball.getY();  
        while (!goal.isGoalReached(ballX, ballY)){
            string str;
            cout << "Enter movement: ";
            cin >> str;
            team.playRobot(ballX, ballY, str);  
            ball.Move(ballX - ball.getX(), ballY - ball.getY());
        }
        ball.Move(-3,-3);
        cout<<"Goal scored..."; 
    }

    void DeclareWinner(){
        if(team1.robotdetails() > team2.robotdetails()){
            cout<<team2.getname()<<" is the winner with "<<team2.robotdetails()<<" hits"<<endl;
        }
        else if(team1.robotdetails() == team2.robotdetails()){
            cout<<"There is a tie with "<<team2.robotdetails()<<" hits"<<endl;
        }
        else{
            cout<<team1.getname()<<" is the winner with "<<team1.robotdetails()<<" hits"<<endl;
        }
    }

    void startGame(){
        cout<<"Team 1 may begin"<<endl;
        Play(team1);
        cout<<"Team 2 may begin"<<endl;
        Play(team2);
        cout<<endl;
        DeclareWinner();
    }
};

int main(){
    ROBOT r1("RobotA");
    ROBOT r2("RobotB");
    Team team1("Team Alpha", r1);
    Team team2("Team Beta", r2);
    Game game(team1, team2);
    game.startGame();
}