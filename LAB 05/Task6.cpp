#include<iostream>
using namespace std;

class Level {
    string levelName, levelDifficulty;
public:
    Level() {}
    Level(string n, string d) {
        levelName = n;
        levelDifficulty = d;
    }
    void showLevelInfo() const {
        cout << "Level Name: " << levelName << endl;
        cout << "Level Difficulty: " << levelDifficulty << endl;
    }
};

class VideoGame {
    string gameTitle, gameGenre;
    Level gameLevels[10];
    int totalLevels = 0;
public:
    VideoGame(string t, string g) {
        gameTitle = t;
        gameGenre = g;
    }
    void insertLevel(string n, string d) {
        gameLevels[totalLevels++] = Level(n, d);
    }
    void showGameInfo() {
        cout << "Game Title: " << gameTitle << endl;
        cout << "Genre: " << gameGenre << endl;
        cout << "Game Levels:\n";
        for (int i = 0; i < totalLevels; i++) {
            gameLevels[i].showLevelInfo();
        }
    }
};

int main() {
    VideoGame g("RDR2", "Adventure");
    g.insertLevel("Chapter 1", "Easy");
    g.insertLevel("Chapter 2", "Medium");
    g.insertLevel("Chapter 3", "Hard");
    g.showGameInfo();
}
