#include "Question.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <fstream>
using namespace std;

    int Guess;
    int Total;
    int questionCount = 1;

   Question:: Question(int qID,string q,string answer1,string answer2,string answer3,string answer4,int ca,int qs)
   {
            Question_id = qID;
            Question_Text = q;
            Answer_1 = answer1;
            Answer_2 = answer2;
            Answer_3 = answer3;
            Answer_4 = answer4;

            Correct_Answer = ca;
            Question_Score = qs;
   }

   //TrueFalse Constructor
   Question::Question(int qID, string q,string answer1,string answer2,int ca,int qs)
   {
            Question_id = qID;
            Question_Text = q;
            True_1 = answer1;
            False_2 = answer2;

            Correct_Answer = ca;
            Question_Score = qs;
    }


//Overloaded SetValue Function for True/False Questions
void Question::setTFValues (int qID,string q,string T1,string F2,int ca,int pa)
{
    Question_id = qID;
    Question_Text = q;
    True_1 = T1;
    False_2 = F2;
    Correct_Answer = ca;
    Question_Score = pa;
}

void Question::setValues (int qID,string q,string a1,string a2,string a3,string a4,int ca,int pa)
{
    Question_id = qID;
    Question_Text = q;
    Answer_1 = a1;
    Answer_2 = a2;
    Answer_3 = a3;
    Answer_4 = a4;
    Correct_Answer = ca;
    Question_Score = pa;
}

//Overloaded askQuestion for True/False Questions
void Question::askTFQuestion()
{
    cout <<"Q"<< questionCount++ <<") "<< Question_Text <<": "<<endl;
    cout << "1. " << True_1;
    cout << " 2. " << False_2;
    cout<<endl;
    cout << "What is your answer ?: ";
    cin >> Guess;

    if(Guess < 1 || Guess > 2)
    {
        cin.clear();
        cin.ignore(INT_MAX,'\n');
        cout<<"Please enter a relevent choice! 1 or 2."<<endl;
        cout<<endl;
        questionCount--;
        askQuestion();
    }
    else
    {

        if (Guess == Correct_Answer)
        {
            cout << "Great! You are correct."<<endl;
            Total = Total + Question_Score;

            cout << "Score: " << Question_Score << " Out of " << Question_Score << "!";
            cout<<endl;
        }
        else
        {
            cout << "Oh No! You are Wrong."<<endl;
            cout << "Score: 0 " << "Out of " << Question_Score << "!"<<endl;
            cout << "The correct answer is " << Correct_Answer << "."<<endl;
        }

        cout<<endl;
    }

}
void Question::askMCQQuestion()
{

    cout << "Q" << questionCount++ << ") " << Question_Text <<": "<<endl;
    cout << "1. " << Answer_1<<endl;
    cout << "2. " << Answer_2<<endl;
    cout << "3. " << Answer_3<<endl;
    cout << "4. " << Answer_4<<endl;

    cout << "What is your answer ? :";
    cin >> Guess;

    if(Guess < 1 || Guess > 4)
    {
        cin.clear();
        cin.ignore(INT_MAX,'\n');
        cout<<"Please enter a relevent choice! 1 -> 4."<<endl;
        questionCount--;
        askQuestion();
    }
    else
    {

        if (Guess == Correct_Answer)
        {
            cout << "Great! You are correct."<<endl;
            Total = Total + Question_Score;

            cout << "Score: " << Question_Score << " Out of " << Question_Score << "!";
            cout<<endl;
        }
        else
        {
            cout << "Oh No! You are Wrong."<<endl;
            cout << "Score: 0 " << "Out of " << Question_Score << "!"<<endl;
            cout << "The correct answer is " << Correct_Answer << "."<<endl;

        }
        cout<<endl;
    }

}
void Question::askQuestion()
{
    cout<<"Question: "<<questionCount<<" out of 24"<<endl;
    cout<<endl;

    if(Question_id == 2)
    {
        askTFQuestion();
    }
    else
    {
        askMCQQuestion();
    }
}
int Question::getTotal()
{
    return Total;
}

