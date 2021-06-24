#include "Question.h"
#include "player.h"
#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <string>
#include <random>
#include <stdlib.h>
#include <Windows.h>
#include <mmsystem.h>
#include <unistd.h>

using namespace std;

vector<player> playerVector;

Question level_1Arr [8];
Question level_2Arr [8];
Question level_3Arr [8];

static void populateVector(vector<Question> &questionVector,string fileName);

void loadLeaderboard(vector<player> &playerVector, string fileName);
void DisplayLeaderboard(vector<player> &playerVector);
void startQuiz();
void endQuiz();

void populateArr(Question *questionArr,string fileName);

struct scoreGreater
{
    bool operator()(player& p1,player& p2){

        return p1.getHighScore() > p2.getHighScore();
    }
};

bool emptyFile(ifstream &file)
{
    return file.peek() == ifstream::traits_type::eof();
}


int main()
{

    startQuiz();

    return 0;
}

void populateArr(Question *questionArr,string fileName)
{
    string qID,q,T1,F2,answer,score;
    string answer1,answer2,answer3,answer4;
    int answerNum;
    int q_ID;
    int q_score;
    int i = 0;

    try
    {

        ifstream file;
        file.open(fileName);

        if(file.is_open())
        {

                while(file.good() && i < 8)
                {
                        getline(file,qID,',');
                        q_ID = stoi(qID);
                        if(q_ID == 2)
                        {
                            getline(file,q,',');
                            getline(file,T1,',');
                            getline(file,F2,',');
                            getline(file,answer,',');
                            answerNum = stoi(answer);
                            getline(file,score,'\n');
                            q_score = stoi(score);

                            //cout<<q_ID<<" "<<q<<" "<<T1<<" "<<F2<<" "<<answerNum<<" "<<q_score<<endl;//Debugging Code

                            Question newQuestion(q_ID,q,T1,F2,answerNum,q_score);
                            questionArr[i] = newQuestion;
                            i++;

                        }
                        else if(q_ID == 1)
                        {
                            getline(file,q,',');
                            getline(file,answer1,',');
                            getline(file,answer2,',');
                            getline(file,answer3,',');
                            getline(file,answer4,',');
                            getline(file,answer,',');
                            answerNum = stoi(answer);
                            getline(file,score,'\n');
                            q_score = stoi(score);

                            //cout<<q_ID<<" "<<q<<" "<<answer1<<" "<<answer2<<" "<<" "<<answer3<<" "<<answer4<<" "<<answerNum<<" "<<q_score<<endl;//Debugging code

                            Question newQuestion(q_ID,q,answer1,answer2,answer3,answer4,answerNum,q_score);;
                            questionArr[i] = newQuestion;
                            i++;
                        }
                    }
        }
        else
        {
            cout<<"File not open";
        }

        //Shuffle Array each time the application runs
        srand(time(0));
        //random_shuffle array
        random_shuffle(questionArr,questionArr+8);
    }
    catch(const exception &e)
    {
        cout<<"ERROR - Could not load vectors";
    }

}

static void populateVector(vector<Question>& questionVector,string fileName)
{
    string qID,q,T1,F2,answer,score;
    string answer1,answer2,answer3,answer4;
    int answerNum;
    int q_ID;
    int q_score;
    int i = 0;

    try
    {

        ifstream file;
        file.open(fileName);


        if(file.is_open())
        {

                while(file.good() && i < 8)
                {
                        getline(file,qID,',');
                        q_ID = stoi(qID);
                        if(q_ID == 2)
                        {
                            getline(file,q,',');
                            getline(file,T1,',');
                            getline(file,F2,',');
                            getline(file,answer,',');
                            answerNum = stoi(answer);
                            getline(file,score,'\n');
                            q_score = stoi(score);

                            //cout<<q_ID<<" "<<q<<" "<<T1<<" "<<F2<<" "<<answerNum<<" "<<q_score<<endl;//Debugging Code

                            Question newQuestion(q_ID,q,T1,F2,answerNum,q_score);
                            questionVector.push_back(newQuestion);
                            i++;

                        }
                        else if(q_ID == 1)
                        {
                            getline(file,q,',');
                            getline(file,answer1,',');
                            getline(file,answer2,',');
                            getline(file,answer3,',');
                            getline(file,answer4,',');
                            getline(file,answer,',');
                            answerNum = stoi(answer);
                            getline(file,score,'\n');
                            q_score = stoi(score);

                            //cout<<q_ID<<" "<<q<<" "<<answer1<<" "<<answer2<<" "<<" "<<answer3<<" "<<answer4<<" "<<answerNum<<" "<<q_score<<endl;//Debugging code

                            Question newQuestion(q_ID,q,answer1,answer2,answer3,answer4,answerNum,q_score);
                            questionVector.push_back(newQuestion);
                            i++;
                        }
                    }
        }
        else
        {
            cout<<"File not open";
        }

        //Shuffle Vector each time the application runs
        srand(time(0));
        random_shuffle(questionVector.begin(),questionVector.end());
    }
    catch(const exception &e)
    {
        cout<<"ERROR - Could not load vectors";
    }
}

void startQuiz()
{
    cout<<"********************************"<<endl;
    cout<<"* WELCOME TO THE COVID-19 QUIZ *"<<endl;
    cout<<"*      TEST YOU KNOWLEDGE!     *"<<endl;
    cout<<"*        COMP315 2021          *"<<endl;
    cout<<"********************************"<<endl;

    populateArr(level_1Arr,"level1.txt");
    populateArr(level_2Arr,"level2.txt");
    populateArr(level_3Arr,"level3.txt");

    //Question runQuiz;

    cout<<"Press 1. to view the Leaderboard."<<endl;
    cout<<"Press 2. to start the quiz."<<endl;
    cout<<"Press 0. to exit quiz."<<endl;
    int choice;
    cout<<"Enter: ";
    cin>>choice;
    cout<<endl;

    if(choice == 1)
    {
        loadLeaderboard(playerVector,"players.txt");

        DisplayLeaderboard(playerVector);

    }
    else if( choice == 2)
    {

        cout<<"Are you ready to begin? YES/NO: ";

        string response;
        cin>>response;
        transform(response.begin(),response.end(),response.begin(),::toupper);
        cout<<endl;

        if(response == "YES")
        {
            //Get User Details
            string name;

            cout<<"What is your first name? :";

            cin>>name;

            player p(name);

            cout<<endl;

            cout<<"Welcome "<< name <<endl;

            cout<<"The Quiz begins NOW: "<<endl;
            sleep(1);

            //Ask Questions
            cout<<"LEVEL 1 - Easy"<<endl;
            cout<<"**************"<<endl;
            for( int i = 0; i < 8; i++)
            {
                level_1Arr[i].askQuestion();
            }
            cout<<"LEVEL 2 - Challenging"<<endl;
            cout<<"*********************"<<endl;
            for( int i = 0; i < 8; i++)
            {
                level_2Arr[i].askQuestion();
            }

            cout<<"LEVEL 3 - Difficult"<<endl;
            cout<<"*******************"<<endl;
            for( int i = 0; i < 8; i++)
            {
                level_3Arr[i].askQuestion();
            }

            endQuiz();

            Question workQ;
            p.setHighscore(workQ.getTotal());
            p.writePlayerToFile("players.txt",p);
        }

    }
    else
    {
        cout<<"Goodbye! Play again soon..."<<endl;
        exit(1);
    }
}

void endQuiz()
{
    Question q;
    int tot = q.getTotal();

    if(tot == 240)
    {
        cout<<"**********************************************************"<<endl;
        cout<<"* Excellent Work! You obtained full marks: "<<tot<<"/240 *"<<endl;
        cout<<"*     You are: PROFFICIENT in your COVID-19 Knowledge!   *"<<endl;
        cout<<"*            Consider becoming a Doctor..                *"<<endl;
        cout<<"**********************************************************"<<endl;
        PlaySound(TEXT("Win-fanfare-sound.wav"), NULL, SND_SYNC);
    }
    else if(tot >=100 && tot<240)
    {
        cout<<"************************************************************"<<endl;
        cout<<"*     Well Done! you are almost there! :"<<tot<<"/240      *"<<endl;
        cout<<"*  You are: WELL EDUCATED in your COVID-19 Knowledge!      *"<<endl;
        cout<<"* Consider brushing up on your information at: www.WHO.int *"<<endl;
        cout<<"************************************************************"<<endl;
        PlaySound(TEXT("Street-crowd-clapping-and-cheering-sound-effect.wav"), NULL, SND_SYNC);
    }
    else
    {
        cout<<"***************************************************************"<<endl;
        cout<<"* Eish!...This is a good time to hit the books :"<<tot<<"/240 *"<<endl;
        cout<<"*          You are: NOT GOOD in your COVID-19 Knowledge!      *"<<endl;
        cout<<"* Consider brushing up on your information at: www.WHO.int    *"<<endl;
        cout<<"*                if you're still alive!                       *"<<endl;
        cout<<"***************************************************************"<<endl;
        PlaySound(TEXT("Failure-trumpet-melody.wav"), NULL, SND_SYNC);
    }
}


void loadLeaderboard(vector<player> &playerVector, string fileName)
{
    try
    {
        string name,scoreTxt;
        string line;
        int score;

        ifstream fileScore(fileName);

        if(fileScore.is_open())
        {
            if(emptyFile(fileScore))
            {
                cout<<endl;
                cout<<"No scores yet...Get Playing!"<<endl;
                cout<<endl;
                startQuiz();
            }
            else
            {

                while(fileScore.good())
                {
                    getline(fileScore,name,',');
                    getline(fileScore,scoreTxt);
                    score = stoi(scoreTxt);

                    if(fileScore.eof()){break;}

                    //cout<<name<<" "<<score<<endl;DEBUG CODE

                    player newPlayer(name,score);
                    playerVector.push_back(newPlayer);

                }
            }
        }

        fileScore.close();
    }
    catch(const exception &e)
    {
        cout<<"Error - Could not load leaderboard";
        exit(1);
    }

    //Sort players in decending order
    sort(playerVector.begin(), playerVector.end(),scoreGreater());

}


void DisplayLeaderboard(vector<player> &playerVector)
{

        cout<<"********************************"<<endl;
        cout<<"*      PLAYERS LEADERBOARD     *"<<endl;
        cout<<"********************************"<<endl;
        for(size_t i = 0, max = playerVector.size();i != max; ++i)
        {
          cout<<i+1<<". "<<playerVector[i].getPlayerName() <<" "<<" SCORE: "<<playerVector[i].getHighScore()<<endl;
        }
        cout<<"********************************"<<endl;
        cout<<endl;

        startQuiz();

}


