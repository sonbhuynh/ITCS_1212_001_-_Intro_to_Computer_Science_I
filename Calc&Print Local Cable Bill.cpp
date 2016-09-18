/*
    Program: Program2
    Author: Son Huynh
    Lab Section: ITCS1212-L04
    Date: 10/13/2013
    Purpose: This program calculates a customer's bil for a local cable company.
    Algorithm:
        1) Input whether a customer is residential or business (char)
        2) Input the account number (int)
        3) If the customer is residential, input premium channels (int)
        4) Calculate the residential cost and return it (double)
        5) Output residential bill and account number to the screen
        6) If the customer is business, input basic connections and premium channels (int)
        7) Calculate the business cost and return it (double)
        8) Output business bill and account number to the screen
*/

#include <iostream>
#include <iomanip>

//Function Prototypes
double calcResidential(int premiumChannels);                        //Prototype for calResidential function
double calcBusiness(int basicConnections, int premiumChannels);     //Prototype for calcBusiness function

using namespace std;

int main()
{
    int accountNumber, premiumChannels, basicConnections;                   //Declaring int variables
    char customerCode;                                                      //Declaring char variable
    double residentialBill, businessBill;                                   //Declaring double variables

    cout << setprecision(2) << fixed << showpoint;

    cout << "For residential customer, press R. ";
    cout << "\nFor business customer, press B. ";
    cout << "\nEnter customer code: ";                                      //Input customer code
    cin >> customerCode;

    cout << "\nPlease enter the account number: ";                          //Input account number
    cin >> accountNumber;

    if (customerCode == 'R' || customerCode == 'r')
    {
        cout << "\nEnter the number of subscribed premium channels: ";      //Input premium channels
        cin >> premiumChannels;

        residentialBill = calcResidential(premiumChannels);                 //Calling calcResidential function

        cout << "\n\nThe Account Number is "<<accountNumber;                //Output accountNumber
        cout << "\nThe Residental Bill is $"<<residentialBill;              //Outputs residentalBill
    }

    if (customerCode == 'B' || customerCode == 'b')
    {
        cout << "Enter the number of basic connections: ";                  //Input basic connections
        cin >> basicConnections;

        cout << "\nEnter the number of subscribed premium channels: ";      //Input premium channels
        cin >> premiumChannels;

        businessBill = calcBusiness(basicConnections, premiumChannels);     //Calling calcBusines function

        cout << "\n\nThe Account Number is "<<accountNumber;                //Output accountNumber
        cout << "\nThe Business Bill is $"<<businessBill;                   //Outputs businessBill
    }
}

/*
    Function Name: calcResidential
    Purpose: calculates the residential bill for residential customers
    Parameter: premiumChannels represents the number of premium channels a user is subscribed to
    Return: returns the residential bill
*/
double calcResidential(int premiumChannels)
{
    double residentialBill;                                                 //Declaring double variable

    residentialBill = 4.5 + 20.5 + 7.5 * premiumChannels;                   //Calculates residentialBill

    return residentialBill;                                                 //Returns residentialBill
}


/*
    Function Name: calcBusiness
    Purpose: calculates the business bill for business customers
    Parameter: basicConnections represents the number of basic service connections,and
                premiumChannels represents the number of premium channels a user is subscribed to
    Return: returns the business bill
*/
double calcBusiness(int basicConnections, int premiumChannels)
{
    double businessBill;                                                    //Declaring double variable

    if (basicConnections <= 10)                                             //If the user inputs 10 or less basicConnections
        businessBill = 15.00 + 75.00 + 50.00 * premiumChannels;             //Calculates businessBil
    else
        businessBill = 15.00 + 75.00 + 5.00 * (basicConnections - 10) + 50.00 * premiumChannels;             //Calculates businessBil

    return businessBill;                                                    //Returns businessBill
}
