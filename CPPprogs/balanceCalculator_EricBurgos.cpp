/**********************************************************************************/
/* Author: Eric burgos                                                            */
/* Creating Date: Septemper 18, 2014                                              */
/* Due Date: October 2, 2014                                                      */
/* Course: CSC135 050                                                             */
/* Professor Name: Dr. Zhang                                                      */
/* Assignment: Project 1                                                          */
/* Filename: balanceCalculator_EricBurgos.cpp                                     */
/* Purpose: Asks user for principal amount, interest rate and the number of times */ 
/* the interest rate is compounded and displays: Interest rate, times compounded, */
/* the principal amount, amount in interest and the amount in savings.            */
/**********************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main()
{
  
  // Declaring variables 
  
  double principal;
  double interestRate;
  int compounded;
  double interestAmount;
  double savingsAmount;
  
  // Welcomes the user
  
  cout << "Welcome to Saving Account Balance Calculator" << endl;
  cout << "--------------------------------------------" << endl;
  
  // Ask user for input
  
  cout << "Please enter the initial balance(without the $ symbol): ";
  cin >> principal;
  
  cout << "Please enter the interest rate(in decimal form): ";
  cin >> interestRate;
  
  cout << "Please enter the number of times the interest is compounded in a year: ";
  cin >> compounded;
  
  cout << endl << endl;
  
  // Calculations
  
  interestAmount = interestRate * principal; // Calculation for interest amount
  savingsAmount = principal * pow(1 + interestRate / compounded, compounded); // Calculation for saving amount
  interestRate = 100 * interestRate; // changing the interest rate into a percentage
  
  
  // REPORT header
  
  cout << "REPORT" << endl;
  cout << "---------------------------------------------" << endl;
  
  // Output after calculations
  cout << setprecision(2) << fixed;
  cout << left << setw(20) << "Interest Rate:" << interestRate << "%" <<  endl;;
  cout << setw(20) << "Times Compounded:" << compounded << endl;;
  cout << setw(20) << "Principal:" << "$" << principal << endl;
  cout << setw(20) << "Interest:" << "$" << interestAmount << endl;
  cout << setw(20) << "Amount in Savings:" << "$" << savingsAmount << endl; 
  
  return 0;
  
}
