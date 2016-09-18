/*
    Program: BoxOffice.cpp
    Author: Son Huynh
    Lab Section: ITCS1212-L04
    Date: 9/2/2013
    Purpose: This program calculates the gross profit, net profit, and how much the distributor make
            for a particular movie based on the amount of adult and child tickets sold. Then, it makes
            a report for the user, with adult tickets, child tickets, gross profit, net profit, distributor making.
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    const double PERCENTAGE_KEPT = 0.2;                 //Declaring Constant variable PERCENTAGE_KEPT to 0.2
    const double ADULT_PRICE = 6.0;                     //Declaring Constant variable ADULT_PRICE to 6.0
    const double CHILD_PRICE = 3.0;                     //Declaring Constant variable CHILD_PRICE to 3.0

    string movieName;                                   //Declaring String variable movieName
    double netProfit;                                   //Declaring double variable netProfit, grossProfit, distributor
    double grossProfit;
    double distributor;
    int adultTickets;                                   //Declaring int variables adultTickets and childTickets
    int childTickets;

    cout << "Enter the name of the movie: ";                    //Prompts the user to enter the name of the movie
    getline(cin, movieName);

    cout << "Enter the number of adult tickets sold: ";         //Prompts the user to enter the number of adult tickets sold
    cin >> adultTickets;

    cout << "Enter the number of child tickets sold: ";         //Prompts the user to enter the number of child tickets sold
    cin >> childTickets;

    grossProfit = (adultTickets * ADULT_PRICE) + (childTickets * CHILD_PRICE);          //Calculating the grossProfit
    netProfit = PERCENTAGE_KEPT * grossProfit;                                          //Calculting the netProfit

    distributor = grossProfit - netProfit;                                              //Calculating distributor

    cout << "\nRevenue Report\n"                                                        //Outputting the report, which includes name, adultTickets sold,
         << "==============\n"                                                          //childTickets sold, grossProfit, netProfit, and distributor.
         << "Movie Name:                    "
         << "\"" << movieName << "\"" << endl
         << "Adult Tickets Sold:            "
         << setw(8) << adultTickets << endl
         << "Child Tickets Sold:            "
         << setw(8) << childTickets << endl
         << fixed << showpoint << setprecision(2)
         << "Gross Box Office Profit:      $"
         << setw(8) << grossProfit << endl
         << "Net Box Office Profit:        $"
         << setw(8) << netProfit << endl
         << "Amount Paid to Distributor:   $"
         << setw(8) << distributor << endl;

    return 0;

}
