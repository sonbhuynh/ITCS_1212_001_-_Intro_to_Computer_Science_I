/*
    Program: dicegame.cpp
    Author: Son Huynh
    Lab Section: 04
    Date: 11/23/2013
    Purpose: This pogram will simulate an ancient dice game for 2 players
    Algorithm:
        1) Ask for player 1 and player 2 names
        2) Generate a random number, if it's even, player 1 goes first, otherwise, player 2 goes first
        3) Generate 6 random numbers between 1 and 6 and store them into dice[] array
        4) Output the dice[] array onto the screen
        5) Let the user choose their dice combination to cash in or socre
        6) Update their score according to their input
        7) Output the score of player 1
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>

//Function Prototypes
void generateDice(int dice[]);                          //Prototype for function generateDice
void outputDice(int dice[]);                            //Prototype for function outputDice

using namespace std;


int main()
{
    srand(time(0));

    int firstTurn;                                      //Declaration
    string playerOne, playerTwo;
    int playerOnePoints = 0, playerTwoPoints = 0;
    int dice[6];
    int scoringDice;
    int countEach1, countEach5;
    char again;

    firstTurn = rand() % 2;                             //Randomizing first turn

    do
    {
        cout << "Enter the name for player 1: ";            //Input playerOne's name
        cin >> playerOne;

        cout << endl;

        cout << "Enter the name for player 2: ";            //Input playerTwo's name
        cin >> playerTwo;

        if (firstTurn == 0)
            cout << "\n"<<playerOne<<" will go first.";     //Outputs if player one is going first
        else
            cout << "\n"<<playerTwo<<" will go first.";     //Outputs if player two will go first

        generateDice(dice);                                 //Calling generateDice

        cout << endl << endl;

        outputDice(dice);                                   //Calling outputDice


        cout << endl << endl;
        cout << setw(20) << "Dice Combination" << setw(10) << "Score";       //Output header
        cout << endl;
        cout << setw(20) << "1. Each 1" << setw(10) << "100";                //Output scoring combination
        cout << endl;
        cout << setw(20) << "2. Each 5" << setw(10) << "50";
        cout << endl;
        cout << setw(20) << "3. Three 1s" << setw(10) << "1000";
        cout << endl;
        cout << setw(20) << "4. Three 2s" << setw(10) << "200";
        cout << endl;
        cout << setw(20) << "5. Three 3s" << setw(10) << "300";
        cout << endl;
        cout << setw(20) << "6. Three 4s" << setw(10) << "400";
        cout << endl;
        cout << setw(20) << "7. Three 5s" << setw(10) << "500";
        cout << endl;
        cout << setw(20) << "8. Three 6s" << setw(10) << "600";
        cout << endl;


        cout << "\nChoose which dice combination you want to score: ";        //Input the dice combination to score
        cin >> scoringDice;

        switch (scoringDice)
        {
            case 1:
                cout << "\nHow many 1's: ";                                   //Input how many 1's
                cin >> countEach1;

                playerOnePoints = playerOnePoints + countEach1 * 100;         //Calculating playerOnePoints

                break;

            case 2:
                cout << "\nHow many 5's: ";                                   //Input how many 5's
                cin >> countEach5;

                playerOnePoints = playerOnePoints + countEach5 * 50;         //Calculating playerOnePoints

                break;

            case 3:
                playerOnePoints += 1000;                                    //Increases score by 1000
                break;

            case 4:
                playerOnePoints += 200;                                    //Increases score by 200
                break;

            case 5:
                playerOnePoints += 300;                                    //Increases score by 300
                break;

            case 6:
                playerOnePoints += 400;                                    //Increases score by 400
                break;

            case 7:
                playerOnePoints += 500;                                    //Increases score by 500
                break;

            case 8:
                playerOnePoints += 600;                                    //Increases score by 600
                break;

            default:
                cout << "Please input a number between 1-8. ";              //Output error message
                break;
        }

        cout << "\n\nPlayer "<<playerOne<<" score is "<<playerOnePoints;    //Output playerOne score

        if (playerOnePoints > playerTwoPoints)
        {
            cout << "\nCongratulations! " <<playerOne<< " is the winner.";         //Output the playerOne and the score
            cout << "\nYour points were: "<< playerOnePoints;
        }
        if (playerOnePoints < playerTwoPoints)
        {
            cout << "\nCongratulations! " <<playerTwo<< " is the winner.";         //Output the playerTwo and the score
            cout << "\nYour points were: "<< playerTwoPoints;
        }

        cout << "\n\nPress Y to go again, N to quit: ";
        cin >> again;

        if (again == 'Y' || again == 'y')
            system("CLS");
    }
    while (again == 'Y' || again == 'y');

}

/*
    Function: generateDice
    Purpose: generate 6 random die and store them into dice array
    Parameters: dice[] represents the array that the dice are being generated into
    Return: Alias parameter, not really returning
*/
void generateDice(int dice[])
{
    for (int x = 0; x < 6; x++)
    {
        dice[x] = rand() % 6 + 1;                           //Generating the dice
    }
}

/*
    Function: outputDice
    Purpose: output the randomly generated dice
    Parameters: dice[] represents the array that the dice are stored in
    Return: Alias parameter, not really returning
*/
void outputDice(int dice[])
{
    for (int x = 0; x < 6; x++)
    {
        cout << "Dice #"<<x+1<<": " <<dice[x];             //Output the dice rolled
        cout << endl;
    }
}
