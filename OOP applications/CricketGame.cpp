#include<iostream>

using namespace std;

class Player{
    int ballscores[12];
    int Totalscore = 0;
    public:
    string Name;
    Player(string name){
        Name = name;
    }
    int Ballnum = 0;
    void SetBallscore(int score){
        ballscores[Ballnum] = score;
        Totalscore += score;
    }

    int Gettotal(){
        return Totalscore;
    }

    void displayplayerscores(){
        for(int i=0;i<Ballnum;i++){
            cout<<ballscores[i]<<"  ";
        }
    }
}; 

class Game{
    public:
    void Playgame(Player &player){
        if(player.Ballnum == 12){
            cout<<"Game has ended..."<<endl;
            return;
        }
        int score;
        cout<<"Enter score for ball "<<player.Ballnum+1<<endl;
        cin>>score;
        if(this->validatescore(score, player) == 1){
            player.SetBallscore(score);
            player.Ballnum++;
            return;
        };
        player.SetBallscore(0);
        player.Ballnum++;
    }

    int validatescore(int score, Player &player){
        if(score>6 || score<0){
            cout<<"Invalid score"<<endl;
            return 0;
        }
        return 1;
    }

    void findwinner(Player &player1, Player &player2){
        if(player1.Gettotal() > player2.Gettotal()){
            cout<<player1.Name<<" is the winner"<<endl;
            return;
        }
        else{
            cout<<player2.Name<< " is the winner"<<endl;
        }
    }   

    void displayscores(Player &player1, Player &player2){
        player1.displayplayerscores();
        player2.displayplayerscores();
    }
};

int main(){
    Game game;
    Player player1("John");
    Player player2("Paul");
    for(int i=0;i<24;i++){
        if(i%2 == 0){
            game.Playgame(player1);
        }
        else{
            game.Playgame(player2);
        }
    }
    game.findwinner(player1, player2);
    game.displayscores(player1,player2);
}