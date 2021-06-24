#include "player.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

    player::player(string p_Name)
    {
        //playerID = p_ID;
        playerName = p_Name;
    }

    player::player(string p_Name,int p_highscore)
    {
        //playerID = p_ID;
        playerName = p_Name;
        highScore = p_highscore;
    };

    void player::setHighscore(int phs)
    {
        highScore = phs;
    }

    inline int player::getPlayerID()
    {
        return playerID;
    }

    inline string player::getPlayerName()
    {
        return playerName;
    }

    int player::getHighScore()
    {
        return highScore;
    }

   void player::writePlayerToFile(string fileName,player &p)
    {
        try
        {
            ofstream Myfile(fileName, ios::app);

            Myfile << p.getPlayerName() <<','<< p.getHighScore()<<'\n';

            Myfile.close();
        }
        catch(exception e)
        {
            cout<<"Unable to open file"<<endl;
            exit(3);
        }
    }
