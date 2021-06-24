#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

class player
{
    public:
        player(string p_Name);

        player(string p_Name,int p_highscore);

        void writePlayerToFile(string fileName, player &p);

        inline string getPlayerName();
        inline int getPlayerID();
        int getHighScore();
        void setHighscore(int p_hs);


    protected:

    private:

        int playerID;
        string playerName;
        int highScore;

};

#endif // PLAYER_H
