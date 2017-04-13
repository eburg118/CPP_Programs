/***************************************************/
/* Author: Eric Burgos                             */
/* Creation Date: August 28, 2014                  */
/* Due Date: August 31, 2014                       */ 
/* Course: CSC135 050                              */
/* Professor Name: Dr. Zhang                       */ 
/* Assignment: #1                                  */
/* Filename: pay_EricBurgos.cpp                    */
/* Purpose: This program calculates the user's pay */
/* 	    given number of hours and hourly rate  */

#include <iostream>
using namespace std;
int main()
{
double hours, rate, pay;
// Get the number of hours worked.
 cout << "How many hours did you work? ";
 cin >> hours;

 // Get the hourly pay rate.
 cout << "How much do you get paid an hour? ";
 cin >> rate;

 // Calculate the pay.
 pay = hours * rate;

 // Display the pay.

 cout << "You have earned $" << pay << endl;
 return 0;

}
