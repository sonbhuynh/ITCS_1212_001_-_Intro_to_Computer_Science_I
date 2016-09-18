/*
    Program: mortgage.cpp
    Author: Son Huynh
    Lab Section: 04
    Date: 11/9/2013
    Purpose: This program will allow the user to enter the principal amount that they're borrowing,
            the interest rate, and the length in years. Then, it will print a mortgage loan payoff table.
    Algorithm:
        1)  Input principal (the amount borrowed)
        2)  Input interest (the interest rate annually)
        3)  Input lengthYears (the number of years of the loan)
        4)  Calculate the monthlyPayment using the formula provided below
            monthlyPayment = principal * (decimalInterest / (1 - (1 + decimalInterest)^(-lengthMonths)))
        5)  Compute the monthlyInterest by multiplying principal by the decimalInterest
        6)  Compute the monthlyPrincipal by taking monthlyPayment and subtract monthlyInterest
        7)  Compute the newBalance by taking the principal and subtract monthlyPrincipal
        8)  Make the newBalance become the principal
        9)  Loop step 5 through 8 until principal is 0
        10) Prompt the user if they want to repeat back to step 1, so nested loop
        11) If they press Y, clear the screen and go back to step 1. If they press N, exit the loop.
*/

#include <iostream>
#include <math.h>
#include <iomanip>
#include <cstdlib>

//Prototypes
void inputData(double& principal, double& interest, double& lengthYears);           //Prototype for inputData
double calcMonthlyPayment(double principal, double interest, double lengthYears);   //Prototype for calcMonthlyPayment

using namespace std;

int main()
{
    double principal, interest, lengthYears;                                        //Declaring double variables
    double monthlyPayment, monthlyInterest, monthlyPrincipal;
    double newBalance;
    char repeat;                                                                    //Declaring char variable
    int paymentNum = 0;                                                             //Declaring int variable

    cout << fixed << setprecision(2) << showpoint;                                  //Setting output to 2 decimal places

    do
    {
        paymentNum = 0;
        inputData(principal, interest, lengthYears);                                //Calling function inputData

        cout << endl;
        cout << setw(10) << "Payment #" << setw(15) << "Interest" << setw(15) << "Principal" << setw(15) << "Balance";                          //Output headings
        cout << endl;
        cout << setw(10) << "---------" << setw(15) << "--------" << setw(15) << "---------" << setw(15) << "-------";
        cout << endl;

        monthlyPayment = calcMonthlyPayment(principal, interest, lengthYears);      //Calling function calcMonthlyPayment

        do
        {
            monthlyInterest = principal * (interest / (12 * 100));                  //Calculating monthlyInterest
            monthlyPrincipal = monthlyPayment - monthlyInterest;                    //Calculating monthlyPrincipal
            newBalance = principal - monthlyPrincipal;                              //Calculating newBalance

            principal = newBalance;                                                 //Assigning the newBalance to become the new principal

            cout << setw(10) << paymentNum + 1 << setw(15) << monthlyInterest << setw(15) << monthlyPrincipal << setw(15) << newBalance;        //Output the data for the table
            cout << endl;

            paymentNum ++;                                                          //Increasing paymentNum by 1
        }
        while (principal >= 0);                                                     //Continues the loop while principal is not negative

        cout << "\n\nTo restart this session, press Y, otherwise, press any key: "; //Prompts the user if they want to restart the calculaton
        cin >> repeat;

        if (repeat == 'Y' || repeat == 'y')                                         //If they choose Y or y, clear the screen
            system("CLS");
    }
    while (repeat == 'Y' || repeat == 'y');                                         //Repeats if the user chooses Y or y

}


/*
    Function: inputData
    Purpose: To allow the user to input the principal, the interest, and the year of the loan
    Parameters: principal represents the amount borrowed, interest represents the interest rate,
                and lengthYears represents the number of years of the loan
    Return: referencing the parameters, not really returning
*/
void inputData(double& principal, double& interest, double& lengthYears)
{
    do
    {
        cout << "Enter the principal: $";                         //Input principal
        cin >> principal;
    }
    while (!(principal > 0));

    do
    {
        cout << "Enter the interest rate: ";                      //Input interest rate
        cin >> interest;
    }
    while (!(interest >= 0 && interest <= 100));

    do
    {
        cout << "Enter the length (in years): ";                  //Input length in years
        cin >> lengthYears;
    }
    while (!(lengthYears > 0));
}


/*
    Function: calcMonthlyPayment
    Purpose: To calculate the monthly payment for the mortgage
    Parameters: principal represents the amount borrowed, interest represents the interest rate,
                and lengthYears represents the number of years of the loan
    Return: the monthly payment
*/
double calcMonthlyPayment(double principal, double interest, double lengthYears)
{
    double decimalInterest, lengthMonths, monthlyPayment;       //Declaring double variables

    decimalInterest = interest / (12 * 100);                    //Calculating monthly iinterest in decimal form
    lengthMonths = lengthYears * 12;                            //Calculating number of months in which the loan is amortized

    monthlyPayment = principal * (decimalInterest / (1 - pow((1 + decimalInterest), lengthMonths * -1)));           //Calculating monthlyPayment

    return monthlyPayment;
}
