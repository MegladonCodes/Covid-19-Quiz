#ifndef QUESTION_H
#define QUESTION_H
#include <iostream>

using namespace std;

class Question
{
 private:
        int Question_id;
        string Question_Text;
        string Answer_1;
        string Answer_2;
        string Answer_3;
        string Answer_4;
        string True_1;
        string False_2;

        int Correct_Answer;
        int Question_Score;


    public:

        //MCQ Constructor
        Question(int qID,string q,string answer1,string answer2,string answer3,string answer4,int ca,int qs);

        //TrueFalse Constructor
        Question(int qID, string q,string answer1,string answer2,int ca,int qs);

        //Empty Constructor
        Question(){};

        void setValues (int qID,string, string, string, string, string, int, int);
        void setTFValues (int qID,string, string, string, int, int);
        void readQuestions(string fileName);
        void askMCQQuestion ();
        void askTFQuestion( );
        void askQuestion();
        int getTotal();

};

#endif // QUESTION_H
