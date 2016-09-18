/*
    Program: distance.cpp
    Author: Son Huynh
    Lab Section: 04
    Date: 11/9/2013
    Purpose: This program will generate a random coordinate, in which the x and y value is between 1 and 200
            Then it will generate 20 other points and determine which point is the closest and furthest from
            original point. Then it will calculate the distance from the original point to both points.
    Algorithm:
        1)  Generate a random number between 1 and 200 for originalX
        2)  Generate a random number between 1 and 200 for originalY
        3)  Generate 20 random number between 1 and 200 for an array of X's
        4)  Generate 20 random number between 1 and 200 for an array of Y's
        5)  Calculating the distance using for formula provided below
            d2 = (x2 - x1)^2 + (y2 - y1)^2
            and storing all those distances in an array
        6)  To find the min, set min = distance[0], and compare it to the first distance,
            if distance[0] < min, then set distance[0] to min, and keep going through the distance array
        7)  To find the max, set max = distance[0], and compare it to the first distance,
            if distance[0] > max, then set distance[0] to max, and keep going through the distance array
        8)  Output the original point(x,y)
        9)  Output the min (Closest Distance) with its coordinate
        10) Output the max (Furthest Distance)  with its coordinate
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <iomanip>

//Prototypes
double calcMax(int originalX, int originalY, int pointX[], int pointY[], int& furthestX, int& furthestY);        //Prototype for calcMax
double calcMin(int originalX, int originalY, int pointX[], int pointY[], int& closestX, int& closestY);          //Prototype for calcMin

using namespace std;

int main()
{
    int pointX[20], pointY[20];                     //Declaring int variables
    int originalX, originalY;
    double distance[20];
    double minimumDistance, maximumDistance;
    int closestX, closestY, furthestX, furthestY;
    double min;
    double max;

    srand(time(0));                                 //srand() seeds a random number generator. We are seeding it with the current system time - time(0)

    originalX = rand() % 200 + 1;                   //originalX will be assigned a random value between 1 and 200
    originalY = rand() % 200 + 1;                   //originalY will be assigned a random value between 1 and 200

    for (int x = 0; x < 20; x ++)
    {
        pointX[x] = rand() % 200 + 1;               //pointX will be assigned a random value between 1 and 200
    }

    for (int x = 0; x < 20; x ++)
    {
        pointY[x] = rand() % 200 + 1;               //pointY will be assigned a random value between 1 and 200
    }

    for (int x = 0; x < 20; x++)
    {
        distance[x] = sqrt(pow((pointX[x] - originalX),2) + pow((pointY[x] - originalY),2));            //Assigning distance array
    }

    cout << setw (15) << "X Coordinates" << setw(15) << "Y Coordinates" << setw(15) << "Distance";      //Output headings
    cout << endl;
    cout << setw (15) << "-------------" << setw(15) << "-------------" << setw(15) << "--------";
    cout << endl;

    for (int x = 0; x < 20; x ++)
    {
        cout << setw (15) << pointX[x] << setw(15) << pointY[x] << setw(15) << distance[x];
        cout << endl;
    }

    cout << endl << endl;

    max = calcMax(originalX, originalY, pointX, pointY, furthestX, furthestY);                          //Calling calcMax function
    min = calcMin(originalX, originalY, pointX, pointY, closestX, closestY);                            //Calling calcMin function

    cout << "The original point is: X = "<<originalX<<", Y = "<<originalY;                              //Output the original point
    cout << endl;
    cout << "\nThe closest point is : X = "<<closestX<<", Y = "<<closestY;                              //Output the closest point
    cout << "\nThe closest distance is: "<<min;                                                         //Output the closest distance
    cout << endl;
    cout << "\nThe furthest point is: X = "<<furthestX<<", Y = "<<furthestY;                            //Output the furthest point
    cout << "\nThe furthest distance is: "<<max;                                                        //Output the furthest distance
    cout << endl;
}


/*
    Function: calcMin
    Purpose: To find the closest distance of the original point and a random point
    Parameters: originalX is the original X value, originalY is the original Y value,
                pointX array with all the randomly generated X values,
                and pointY array with all the randomly generated Y values
    Return: min, or the closest distance
*/
double calcMin(int originalX, int originalY, int pointX[], int pointY[], int& closestX, int& closestY)
{
    double distance[20];                                                                               //Declaring double variable
    double min = distance[0];

    for (int x = 0; x < 20; x++)
    {
        distance[x] = sqrt(pow((pointX[x] - originalX),2) + pow((pointY[x] - originalY),2));           //Calculating distance

        if (distance[x] < min)
        {
            min = distance[x];                                                                         //Finding the smallest distance and assigning it to min
            closestX = pointX[x];                                                                      //Finding the closest X value
            closestY = pointY[x];                                                                      //Finding the closest Y value
        }
    }

    return min;
}


/*
    Function: calcMax
    Purpose: To find the furthest distance of the original point and a random point
    Parameters: originalX is the original X value, originalY is the original Y value,
                pointX array with all the randomly generated X values,
                and pointY array with all the randomly generated Y values
    Return: max, or the furthest distance
*/
double calcMax(int originalX, int originalY, int pointX[], int pointY[], int& furthestX, int& furthestY)
{
    double distance[20];                                                                                //Declaring double variable
    double max = distance[0];

    for (int x = 0; x < 20; x++)
    {
        distance[x] = sqrt(pow((pointX[x] - originalX),2) + pow((pointY[x] - originalY),2));            //Calculating distance

        if (distance[x] > max)
        {
            max = distance[x];                                                                          //Finding the largest distance and assigning it to the max
            furthestX = pointX[x];                                                                      //Finding the furthest X value
            furthestY = pointY[x];                                                                      //Finding the furthest Y value
        }
    }

    return max;
}
