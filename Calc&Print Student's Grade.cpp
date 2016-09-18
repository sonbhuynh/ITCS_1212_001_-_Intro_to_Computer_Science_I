/*
    Program: Program3
    Author: Son Huynh
    Lab Section: ITCS1212-L04
    Date: 10/13/2013
    Purpose: This program calculates and prints a student's letter grade
            and a message based on the average of the four test grades
    Algorithm:
        1) Input 4 test grades (double)
        2) Calculates the average (double)
        3) Determines the letter grade (char)
        4) Outputs results to the screen
*/

#include <iostream>
#include <iomanip>

//Function Prototypes
double calcAverage(double firstTest, double secondTest, double thirdTest, double fourthTest);               //Prototype for calcAverage
char calcLetterGrade(double testAverage);                                                                   //Prototype for calcLetterAverage
void outputResult(double testAverage, char letterGrade);                                                    //Prototype for outputResult

using namespace std;

int main()
{
    double firstTest, secondTest, thirdTest, fourthTest;                        //Declaring double variables
    double testAverage;
    char letterGrade;                                                           //Declaring char variable

    cout << setprecision(2) << fixed << showpoint;

    cout << "Enter the 1st test grade: ";           //Input firstTest
    cin >> firstTest;

    cout << "Enter the 2nd test grade: ";           //Input secondTest
    cin >> secondTest;

    cout << "Enter the 3rd test grade: ";           //Input thirdTest
    cin >> thirdTest;

    cout << "Enter the 4th test grade: ";           //Input fourthTest
    cin >> fourthTest;

    testAverage = calcAverage(firstTest, secondTest, thirdTest, fourthTest);    //Calliing calcAverage

    letterGrade = calcLetterGrade(testAverage);                                 //Calling calcLetterGrade

    outputResult(testAverage, letterGrade);                                     //Calling outputResult
}


/*
    Function Name: calcAverage
    Purpose: calculates the average of the 4 test grades
    Parameter: firstTest represents the valube of the first test grade, and so on
    Return: returns the test average of the 4 test grades
*/
double calcAverage(double firstTest, double secondTest, double thirdTest, double fourthTest)
{
    double testAverage;                             //Declaring double variable

    testAverage = (firstTest + secondTest + thirdTest + fourthTest) / 4.0;       //Calculates test average

    return testAverage;                             //Returns testAverage
}

/*
    Function Name: calcLetterGrade
    Purpose: calculates the letter grade based on the test average
    Parameter: testAverage represents the test average of 4 tests
    Return: returns the letter grade based on the test average
*/
char calcLetterGrade(double testAverage)
{
    char letterGrade;                               //Declaring char variable


    if(testAverage >= 90)
    {
        letterGrade = 'A';                                  //If testAverage is 90 or above, it's an A
    }
    else
    {
        if(testAverage >= 80)                               //If testAverage is 80 or above, it's an B
        {
             letterGrade = 'B';
        }
        else
        {
             if(testAverage >= 70)                          //If testAverage is 70 or above, it's an C
             {
                letterGrade = 'C';
             }
             else
             {
                if(testAverage >= 60)                       //If testAverage is 60 or above, it's an D
                {
                letterGrade = 'D';
                }
                else
                {
                    letterGrade = 'F';                      //If testAverage is lower than 60, it's an F
                }
            }
        }
    }


    return letterGrade;                             //Returns letterGrade
}

/*
    Function Name: outputResult
    Purpose: outputs test grade, letter grade, and whether or not
                a student can take the next course
    Parameter: testAverage represents the test average of 4 tests, letterGrade represents the letter grade the student received
    Output: results if they can pass
*/
void outputResult(double testAverage, char letterGrade)
{
    if (letterGrade == 'A' || letterGrade == 'B' || letterGrade == 'C')
        cout << "\n\nYour average is: "<<testAverage<<" which is a "<<letterGrade<<". You can take the next course. ";
    else
        cout << "\n\nYour average is: "<<testAverage<<" which is a "<<letterGrade<<". You cannot take the next course. ";
}
