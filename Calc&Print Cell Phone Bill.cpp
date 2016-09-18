/*
    Program: Program1
    Author: Son Huynh
    Lab Section: ITCS1212-L04
    Date: 10/13/2013
    Purpose: This program calculates and prints the bill for a cell phone company
    Algorithm:
        1) Output the menu and let the user to choose Regular or Premium (int)
        2) If they choose Regular, let them input the minutes used (int)
        3) If they used 200 or less, bill is 20
            else, take the extra minutes, multiply by .15, and add to 20 (double)
        4) Output the Regular bill (double)
        5) If they choose Premium, let them choose when they made the calls (int)
        6) Let them input the minutes used (int)
        7) If they used 100 or less, bill is 35
            else, take the extra minutes, multiply by .10, and add to 35 (double)
        8) If they used 300 or less, bill is 35
            else, take the extra minutes, multiply by .05, and add to 35 (double)
        9) Output the Premium bill (double)
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int plan, regularMinutes, overMinutes;                      //Declaring int variables
    int callTime, premiumMinutes;
    double regularBill, premiumBill1, premiumBill2;             //Declaring double variables

    cout << "The plans available: ";                            //Outputs the menu for user the choose
    cout << "\n1. Regular ";
    cout << "\n2. Premium ";

    cout << "\nEnter the plan in which you are under: ";        //Input the plan the user is under
    cin >> plan;

    switch (plan)
    {
    case 1:
        cout << "\nEnter the minutes used: ";                   //Input the minutes used under Regular plan
        cin >> regularMinutes;

        if (regularMinutes <= 200)                              //If regularMinutes is less than or equal to 200
            regularBill = 20;                                   //regularBill is 20
        else                                                    //If regularMinutes is over 200
        {
            overMinutes = regularMinutes - 200;                 //Calculates the minutes used over the 200 allowed
            regularBill = 20 + overMinutes * .15;               //Calculates regularBill
        }

        cout << "\nThe total bill is $"<<regularBill;           //Output regularBill for Regular plan
        break;

    case 2:
        cout << "\nChoose when the calls were made: ";          //Output the menu for user to choose
        cout << "\n1. 6:00 AM to 6:00 PM ";
        cout << "\n2. 6:00 PM to before 6:00 AM";

        cout << "\nEnter the time the calls were made: ";       //Input the time in which the calls were made
        cin >> callTime;

        switch (callTime)
        {
        case 1:
            cout << "\nEnter the minutes used: ";               //Input minutes used under Premium plan
            cin >> premiumMinutes;

            if (premiumMinutes <= 100)                          //If premiumMinutes is less than or equal to 100
                premiumBill1 = 35;                              //premiumBill1 is 35
            else                                                //If premiumMinutes is over 100
            {
                overMinutes = premiumMinutes - 100;             //Calculates the minutes used over the 100 allowed
                premiumBill1 = 35 + overMinutes * .10;          //Calculates the premiumBill1
            }

            cout << "\nThe total bill is $"<<premiumBill1;      //Output premiumBill1 for Premium plan
            break;
        case 2:
            cout << "\nEnter the minutes used: ";               //Input minutes used under Premium plan
            cin >> premiumMinutes;

            if (premiumMinutes <= 300)                          //If premiumMinutes is less than or equal to 300
                premiumBill2 = 35;                              //premiumBill2 is 35
            else                                                //If premiumMinutes is over 300
            {
                overMinutes = premiumMinutes - 300;             //Calculates the minutes used over the 300 allowed
                premiumBill2 = 35 + overMinutes * .05;          //Calculates the premiumBill2
            }

            cout << "\nThe total bill is $"<<premiumBill2;      //Output premiumBill2 for Premium plan
            break;
        }
    }
}
